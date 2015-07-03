#include <node.h>
#include <v8.h>
#include <uv.h>
#include <bemasat/SAT.h>

using namespace v8;

Handle<Value> consultaSat(const Arguments& args) {
  HandleScope scope;
  const char * response;
  int numSession;
  if (args[0]->IsInt32()) {
    numSession = args[0]->Int32Value();
    response = ConsultarSAT(numSession);
  } else {
    ThrowException(Exception::TypeError(String::New("Argument must be an integer")));
    return Undefined();
  }
  return scope.Close(String::New(response));
}

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "consultaSat", consultaSat);
  return;
}

NODE_MODULE(addon, init)
