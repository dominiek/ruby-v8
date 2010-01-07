
require 'V8'

js_code = <<-JAVASCRIPT
  
  var hello = 'hello';
  var world = 'world';
  hello + ' ' + world + '!';

JAVASCRIPT

proc = V8::Proc.new(js_code)
result = proc.run
puts result
