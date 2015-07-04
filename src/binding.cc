#include <node.h>
#include <v8.h>
#include <uv.h>

using namespace v8;

// -------------------------------------------------------------------
// Settings related functions
// -------------------------------------------------------------------
Handle<Value> consultaSat(const Arguments& args);
Handle<Value> bloquearSat(const Arguments& args);
Handle<Value> desbloquearSat(const Arguments& args);

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "consultaSat", consultaSat);
  NODE_SET_METHOD(exports, "bloquearSat", bloquearSat);
  NODE_SET_METHOD(exports, "desbloquearSat", desbloquearSat);
  
  return;
}

NODE_MODULE(addon, init)
