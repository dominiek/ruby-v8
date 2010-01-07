
require 'rubygems'
require 'mkmf-rice'

# --with-v8-include=~/src/v8/include
v8_dirs = dir_config('v8')
if v8_dirs && v8_dirs.first
  v8_libdir = v8_dirs.first.gsub(/\/include/, '')
  $LDFLAGS = " #{$LDFLAGS} #{v8_libdir}/libv8.a "
end
have_header('v8.h')

create_makefile('V8')
