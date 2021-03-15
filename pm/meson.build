pm_inc = include_directories('.')
pm_headers = files(['ParticleMesh.hpp','c_ParticleMesh.h'])
pm_sources = files(['ParticleMesh.cpp','c_ParticleMesh.cpp'])

pm_lib = static_library('PM',pm_headers+ pm_sources,
    include_directories: pm_inc)

pm = declare_dependency(
    include_directories: pm_inc,
    link_with: pm_lib)
