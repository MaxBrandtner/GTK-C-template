project('Template','c')
PROJECT_NAME = meson.project_name()
LOCAL_DIR = meson.current_source_dir()

gtkdep = dependency('gtk4')
#glibcdep = dependency('glibc')

#needed for math library
#add_project_link_arguments('-lm', language : 'c')


gnome = import('gnome')
resources = gnome.compile_resources('resources','Template.gresource.xml')

message('gresources complete')

#install_data('builder.ui', install_dir: pkgdatadir)


sourcefiles = files('main.c')

executable(PROJECT_NAME, sourcefiles, resources, dependencies: gtkdep, c_args:[ '-DLOCAL_DIR="@0@/"'.format(LOCAL_DIR)], export_dynamic: true)
