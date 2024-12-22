project('c-template', 'c',
  version: '0.1',
  license: 'MPL-2.0',
  default_options: ['warning_level=3'])

# define source files
src = files('src/main.c')

# define project metadata
url = 'https://github.com/mekb-turtle/c-template'
name = meson.project_name()
version = meson.project_version()

add_project_arguments(
  f'-DPROJECT_NAME="@name@"',
  f'-DPROJECT_VERSION="@version@"',
  f'-DPROJECT_URL="@url@"',
  language : 'c')

# add custom binary/text files to be compiled into the binary
#xxd = find_program('xxd')
#src += custom_target(input: 'src' / 'example.bin', command: [xxd, '-i', '-n', '@PLAINNAME@', '@INPUT@', '@OUTPUT@'], output: '@PLAINNAME@.c', install: false, build_by_default: true)

exe = executable('c-template', sources: src, install: true, dependencies: [

])

