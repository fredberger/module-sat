#include <node.h>
#include <v8.h>
#include <uv.h>
#include <bemasat/SAT.h>

using namespace v8;

Handle<Value> consultaSat(const Arguments& args) {
  HandleScope scope;
  const char * response = ConsultarSAT(0);
  return scope.Close(String::New(response));
}

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "consultaSat", consultaSat);
  return;
}

NODE_MODULE(addon, init)
