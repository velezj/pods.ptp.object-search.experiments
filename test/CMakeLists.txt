add_executable( p2l-rawseeds-experiments-test-ruler-mcmc
  test-ruler-mcmc.cpp
)
pods_use_pkg_config_packages( p2l-rawseeds-experiments-test-ruler-mcmc
  p2l-rawseeds-experiments
)
pods_install_executables( p2l-rawseeds-experiments-test-ruler-mcmc )


add_executable( p2l-rawseeds-experiments-test-ruler-intensity
  ruler-process-intensity.cpp
)
pods_use_pkg_config_packages( p2l-rawseeds-experiments-test-ruler-intensity
  p2l-rawseeds-experiments
  gperftools-2.1
)
pods_install_executables( p2l-rawseeds-experiments-test-ruler-intensity )
