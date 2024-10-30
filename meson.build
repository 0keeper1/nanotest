project(
    'nanotest',
    'c',
    version : '1.0.2',
    default_options : ['warning_level=3', 'c_std=c2x']
)

header = include_directories('include')

static_lib = static_library(
    meson.project_name() + '_static',
    ['src/main.c'],
    gnu_symbol_visibility : 'hidden',
    install : false,
    include_directories : header
)

shared_lib = shared_library(
    meson.project_name(),
    ['src/main.c'],
    gnu_symbol_visibility : 'hidden',
    install : true,
    include_directories : header
)

nanotest_dep = declare_dependency(
    link_with : static_lib,
    include_directories : header
)

install_headers('include/lib.h', subdir : meson.project_name())


