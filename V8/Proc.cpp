
#include "common.hpp"
#include "exceptions.hpp"
#include <v8.h>

using namespace v8;

class Proc
{
  std::string js_code;
  Persistent<Context> context;
  Handle<Script> script;
  
public:
  Proc(std::string js_code);
  ~Proc();
  Rice::Object run();
};

Proc::Proc(std::string js_code) {
  this->js_code = js_code;
/*
  // Create a stack-allocated handle scope.
  HandleScope handle_scope;

  // Create a new context.
  this->context = Context::New();
  
  // Enter the created context for compiling and
  // running the hello world script. 
  Context::Scope context_scope(this->context);

  // Create a string containing the JavaScript source code.
  Handle<String> source = String::New("'Hello' + ', World!'");
  //Handle<String> source = String::New(js_code.c_str());

  // Compile the source code.
  this->script = Script::Compile(source);
  */  
}

Proc::~Proc() {
  // Dispose the persistent context.
  //this->context.Dispose();
}

Rice::Object Proc::run() {
  /*
  // Run the script to get the result.
  Handle<Value> result = this->script->Run();
  
  //String::AsciiValue ascii(result);
  
  //printf("%s !!!!!!!!!!!!!!", *ascii);
  
  return to_ruby(44);
  */
  
  // Create a stack-allocated handle scope.
  HandleScope handle_scope;

  // Create a new context.
  this->context = Context::New();
  
  // Enter the created context for compiling and
  // running the hello world script. 
  Context::Scope context_scope(this->context);

  // Create a string containing the JavaScript source code.
  Handle<String> source = String::New(this->js_code.c_str());

  // Compile the source code.
  this->script = Script::Compile(source);
  
  // Run the script to get the result.
  Handle<Value> result = this->script->Run();
  
  // Dispose the persistent context.
  this->context.Dispose();

  // Convert the result to an ASCII string and print it.
  if(result->IsString()) {
    String::AsciiValue ascii(result);
    return to_ruby(std::string(*ascii));
  }
  //throw new V8UnknownReturnValueException();
  //throw rb_eUnknownReturnValueException;
  //throw Rice::Exception(rb_eUnknownReturnValueException, "aaaa");
  throw Rice::Exception(rb_eStandardError, "Unkown return value");
}

void Init_V8_Proc()
{
  Rice::Data_Type<Proc> rb_cProc = rb_mV8.define_class<Proc>("Proc");
  //rb_cProc.add_handler<V8UnknownReturnValueException>(handle_v8_exception);
  rb_cProc.define_constructor(Rice::Constructor<Proc, std::string>());
  rb_cProc.define_method("run", &Proc::run);
  rb_eUnknownReturnValueException = rb_mV8.define_class<V8UnknownReturnValueException>("UnknownReturnValueException");
}

/*
Object V8_Proc_initialize(Object self, std::string js_code)
{
  self.iv_set("@js_code", to_ruby(js_code));
}

Object V8_Proc_run(Object self)
{
  return self.iv_get("@js_code");
}

*/

