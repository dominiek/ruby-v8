
class V8UnknownReturnValueException : public Rice::Exception {
};

Rice::Object rb_eUnknownReturnValueException;

/*
void handle_v8_exception(V8UnknownReturnValueException const & ex) {
  throw Rice::Exception(rb_eStandardError, "Oooops");
}

void Init_V8_Exceptions(Rice::Module rb_mV8) {
  rb_mV8.add_handler<V8UnknownReturnValueException>(handle_v8_exception);
}
*/