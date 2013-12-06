
#include "data_loader.hpp"
#include <ruler-point-process/ruler_point_process.hpp>
#include <planner-core/shortest_path_next_planner.hpp>
#include <point-process-experiment-core/experiment_utils.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <fstream>


using namespace math_core;
using namespace point_process_experiment_core;
using namespace planner_core;
using namespace point_process_core;
using namespace rawseeds_experiments;
using namespace ruler_point_process;
namespace po = boost::program_options;


boost::shared_ptr<mcmc_point_process_t>
create_planner_process(  const nd_aabox_t& world_window ,
			 po::variables_map& po_vm)
{
  // Really, we only look at the wanted process and them use
  // some defaults here
  if( po_vm["point-process"].as<std::string>() == "ruler_point_process" ) {
    int dim = 2;
    ruler_point_process_model_t model;
    model.prior_ruler_start_mean = zero_point( dim );
    model.prior_ruler_direction_mean = zero_point( dim );
    model.alpha = 1;
    model.precision_distribution.shape = 500000;
    model.precision_distribution.rate = 1000;
    model.period_distribution.p = pow(2.15,40);
    model.period_distribution.q = 2.15*40;
    model.period_distribution.r = 40;
    model.period_distribution.s = 40;
    model.ruler_length_distribution.p = pow(10,40);
    model.ruler_length_distribution.q = 10 * 40;
    model.ruler_length_distribution.r = 40;
    model.ruler_length_distribution.s = 40;
    model.ruler_start_mean_distribution.dimension = dim;
    model.ruler_start_mean_distribution.means.push_back( 0.4 );
    model.ruler_start_mean_distribution.means.push_back( 0.4 );
    model.ruler_start_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * (0.4*0.4) );
    model.ruler_start_precision_distribution.shape = 5000;
    model.ruler_start_precision_distribution.rate = 100;
    model.ruler_direction_mean_distribution.dimension = dim;
    model.ruler_direction_mean_distribution.means.push_back( 10 );
    model.ruler_direction_mean_distribution.means.push_back( 10 );
    model.ruler_direction_mean_distribution.covariance = to_dense_mat( Eigen::MatrixXd::Identity(dim,dim) * 1 );
    model.ruler_direction_precision_distribution.shape = 5000;
    model.ruler_direction_precision_distribution.rate = 100;
    std::vector<nd_point_t> init_points;
    init_points.push_back( point( 0.0, 0.0 ) );
    init_points.push_back( point( 1.0, 1.0 ) );
    boost::shared_ptr<ruler_point_process_t> process = 
      boost::shared_ptr<ruler_point_process_t>
      ( new ruler_point_process_t( world_window,
				   model,
				   init_points ) );
    boost::shared_ptr<mcmc_point_process_t> planner_process
      = boost::shared_ptr<mcmc_point_process_t>( process );
    
    return planner_process;
  }
  
  throw std::runtime_error("unknown planner process!" );
}


boost::shared_ptr<grid_planner_t>
create_planner( boost::shared_ptr<mcmc_point_process_t>& planner_process,
		po::variables_map& po_vm )
{
  if( po_vm["planner"].as<std::string>() == "shortest_path_next_planner" ) {

    // create a planner for it
    grid_planner_parameters_t planner_params;
    planner_params.burnin_mcmc_iterations = 10;
    planner_params.update_model_mcmc_iterations = 10;
    planner_params.grid_cell_size = 10.0;
    entropy_estimator_parameters_t entropy_params;
    entropy_params.num_samples = 10;
    sampler_planner_parameters_t sampler_planner_params;
    sampler_planner_params.num_samples_of_observations = 10;
    sampler_planner_params.num_samples_of_point_sets = 200;
    double prob_thresh = 0.6;
    boost::shared_ptr<grid_planner_t> planner
      = boost::shared_ptr<grid_planner_t>
      (
       new shortest_path_next_planner ( planner_process,
					planner_params,
					entropy_params,
					sampler_planner_params,
					prob_thresh)
       );
    
    return planner;
    
  }

  if( po_vm["planner"].as<std::string>() == "debug::shortest_path_next_planner" ) {

    // create a planner for it
    grid_planner_parameters_t planner_params;
    planner_params.burnin_mcmc_iterations = 1;
    planner_params.update_model_mcmc_iterations = 1;
    planner_params.grid_cell_size = 10.0;
    entropy_estimator_parameters_t entropy_params;
    entropy_params.num_samples = 2;
    sampler_planner_parameters_t sampler_planner_params;
    sampler_planner_params.num_samples_of_observations = 1;
    sampler_planner_params.num_samples_of_point_sets = 2;
    double prob_thresh = 0.6;
    boost::shared_ptr<grid_planner_t> planner
      = boost::shared_ptr<grid_planner_t>
      (
       new shortest_path_next_planner ( planner_process,
					planner_params,
					entropy_params,
					sampler_planner_params,
					prob_thresh)
       );
    
    return planner;
    
  }


  if( po_vm["planner"].as<std::string>() == "debug::small_001" ) {

    // create a planner for it
    grid_planner_parameters_t planner_params;
    planner_params.burnin_mcmc_iterations = 1;
    planner_params.update_model_mcmc_iterations = 1;
    planner_params.grid_cell_size = 1.0;
    entropy_estimator_parameters_t entropy_params;
    entropy_params.num_samples = 2;
    sampler_planner_parameters_t sampler_planner_params;
    sampler_planner_params.num_samples_of_observations = 1;
    sampler_planner_params.num_samples_of_point_sets = 2;
    double prob_thresh = 0.6;
    boost::shared_ptr<grid_planner_t> planner
      = boost::shared_ptr<grid_planner_t>
      (
       new shortest_path_next_planner ( planner_process,
					planner_params,
					entropy_params,
					sampler_planner_params,
					prob_thresh)
       );
    
    return planner;
    
  }



  throw std::runtime_error( "unknown planner!" );
}


int main( int argn, char** argv )
{

  // setup the program options
  nd_aabox_t undef_window;
  po::options_description po_desc( "RAWSEEDS Experiment Runner Options" );
  po_desc.add_options()
    ( "help", "usage and help message")
    ( "world", 
      po::value<std::string>()->default_value( "biccoca_2009_02_27a" ), 
      "Which RAWSEEDS world to load. Current supported values are ['biccoca_2009_02_27a', 'small_001']")
    ( "planner",
      po::value<std::string>()->default_value( "shortest_path_next_planner" ),
      "Which planner should we use. Current supported planners are ['shortest_path_next_planner']")
    ( "planner-parameters-json",
      po::value<std::string>()->default_value( "" ),
      "The parameters for the planner as a JSON string")
    ( "point-process",
      po::value<std::string>()->default_value( "ruler_point_process" ),
      "Which point process to use for modeling and exploration. Current supported point processes are: ['ruler_point_process', 'igmm', 'poisson' ]" )
    ( "point-process-parameters-json",
      po::value<std::string>()->default_value(""),
      "The point process parameters as a JSON string")
    ( "add-empty-regions",
      po::value<bool>()->default_value(true),
      "Compute and add emty regions within observed cells")
    ( "initial-window-fraction",
      po::value<double>()->default_value( 0.1 ),
      "The fraction of the world window initially 'seen' by hte planner")
    ( "goal-fraction-found",
      po::value<double>()->default_value( 1.0 ),
      "The fraction of the groundtruth point we need to find to finish the run (defaults to 1.0 or *all* points)");
      

  // parse the program options
  po::variables_map po_vm;
  po::store( po::parse_command_line( argn, argv, po_desc ), po_vm );
  po::notify( po_vm );
  
  // show usage if wanted
  if( po_vm.count( "help" )) {
    std::cout << po_desc << std::endl;
    return 1;
  }

  // get the wanted world points and window
  std::vector< nd_point_t > ground_truth = rawseeds_experiments::groundtruth_for_world( po_vm["world"].as<std::string>() );
  nd_aabox_t world_window = rawseeds_experiments::window_for_world( po_vm["world"].as<std::string>() );

  std::cout << "num points: " << ground_truth.size() << std::endl;
  
  // build up the point process model
  boost::shared_ptr< mcmc_point_process_t > planner_process = create_planner_process( world_window, po_vm );
  
  // build up the planner
  boost::shared_ptr<grid_planner_t> planner = create_planner( planner_process, po_vm );

  // get the initial window of known world
  double frac = po_vm["initial-window-fraction"].as<double>();
  nd_aabox_t initial_window = 
    aabox( world_window.start, 
	   world_window.start + ( world_window.end - world_window.start ) * frac );

  // seed the planner
  initial_window =
    setup_planner_with_initial_observations( planner,
					     po_vm["add-empty-regions"].as<bool>(),
					     initial_window,
					     ground_truth );

  // create the meta and trace files
  std::ofstream out_meta( "00-planner.meta" );
  std::ofstream out_trace( "00-planner.trace" );
  std::ofstream out_verbose_trace( "00-planner.verbose-trace" );

  out_meta << "add_empty_regions: " << po_vm["add-empty-regions"].as<bool>() << std::endl;
  
  // run the planner
  std::vector<marked_grid_cell_t> trace =
    simulate_run_until_all_points_found( planner,
					 po_vm["add-empty-regions"].as<bool>(),
					 initial_window,
					 po_vm["goal-fraction"].as<double>(),
					 ground_truth,
					 out_meta,
					 out_trace,
					 std::cout,
					 out_verbose_trace);

  return 0;
}
