#include <node.h>
#include <v8.h>
#include <uv.h>
#include <stdlib.h>
#include <string.h>

#include <bemasat/SAT.h>

#define RETURN_EXCEPTION(msg) return ThrowException(Exception::TypeError(String::New(msg)))

using namespace v8;

const char *get(Local<Value> value) {
  String::AsciiValue string(value);
  char *str = (char *) malloc(string.length() + 1);
  strcpy(str, *string);
  return str;
}

Handle<Value> consultaSat(const Arguments& args) {
  HandleScope scope;

  if ((args.Length() != 1) || (!args[0]->IsInt32())) {
    RETURN_EXCEPTION("Expected 1 argument, must be an integer!");
  }

  int numSession = args[0]->Int32Value();
  const char *response = ConsultarSAT(numSession);
  return scope.Close(String::New(response));
}

Handle<Value> bloquearSat(const Arguments& args) {
  HandleScope scope;

  if ((args.Length() != 2) || (!args[0]->IsInt32()) || (!args[1]->IsString())) {
    RETURN_EXCEPTION("Expected 2 arguments, first integer and second string!");
  }

  int numSession = args[0]->Int32Value();
  const char *code = get(args[1]->ToString());
  const char *response = BloquearSAT(numSession, code);
  return scope.Close(String::New(response));
}

Handle<Value> desbloquearSat(const Arguments& args) {
  HandleScope scope;

  if ((args.Length() != 2) || (!args[0]->IsInt32()) || (!args[1]->IsString())) {
    RETURN_EXCEPTION("Expected 2 arguments, first integer and second string!");
  }

  int numSession = args[0]->Int32Value();
  const char *code = get(args[1]->ToString());
  const char *response = DesbloquearSAT(numSession, code);
  return scope.Close(String::New(response));
}
