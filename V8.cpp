
#include "common.hpp"
#include "V8.hpp"

#include "V8/Proc.cpp"

extern "C"
void Init_V8()
{
  rb_mV8 = Rice::define_module("V8");
  //Init_V8_Exceptions(rb_mV8);
  Init_V8_Proc();
}
