project(
    'unstdtest',
    'c',
    version : '1.1.2',
    license : 'MIT',
    default_options : ['warning_level=3', 'c_std=gnu23']
)

pkg_config = import('pkgconfig')

lib_args = ['-DBUILDING_MESON_LIBRARY']

headers = include_directories('include')

header_file = files('include/unstdtest.h')

libunstdtest_lib = static_library(
    'lib' + meson.project_name(),
    include_directories : headers,
    sources : [],
    c_args : lib_args,
    install : true
)

libunstdtest_dep = declare_dependency(
    include_directories : headers,
    link_with : libunstdtest_lib
)

install_headers(header_file)

pkg_config.generate(
    filebase : 'unstdtest',
    version : '1.1.2',
    name : 'unstdtest',
    description : ' unstdtest is a minimalistic testing framework for C focused on being lightweight and simple',
)
