#include <node.h>
#include <v8.h>
#include <uv.h>

using namespace v8;

// -------------------------------------------------------------------
// Settings related functions
// -------------------------------------------------------------------
Handle<Value> consultarSat(const Arguments& args);
Handle<Value> bloquearSat(const Arguments& args);
Handle<Value> desbloquearSat(const Arguments& args);
Handle<Value> enviarDadosVenda(const Arguments& args);

void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "consultarSat", consultarSat);
  NODE_SET_METHOD(exports, "bloquearSat", bloquearSat);
  NODE_SET_METHOD(exports, "desbloquearSat", desbloquearSat);
  NODE_SET_METHOD(exports, "enviarDadosVenda", enviarDadosVenda);

  return;
}

NODE_MODULE(sat, init)
