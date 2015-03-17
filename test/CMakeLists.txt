add_executable( object-search.rawseeds-experiments-test-ruler-mcmc
  test-ruler-mcmc.cpp
)
pods_use_pkg_config_packages( object-search.rawseeds-experiments-test-ruler-mcmc
  object-search.rawseeds-experiments
)
pods_install_executables( object-search.rawseeds-experiments-test-ruler-mcmc )


add_executable( object-search.rawseeds-experiments-test-ruler-intensity
  ruler-process-intensity.cpp
)
pods_use_pkg_config_packages( object-search.rawseeds-experiments-test-ruler-intensity
  object-search.rawseeds-experiments
)
pods_install_executables( object-search.rawseeds-experiments-test-ruler-intensity )
