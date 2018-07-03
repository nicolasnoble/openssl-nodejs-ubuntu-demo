#include <node.h>
#include <nan.h>
#include <v8.h>

#include <openssl/ssl.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  SSL_library_init();
  args.GetReturnValue().Set(Nan::New(SSLeay_version(SSLEAY_VERSION)).ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("do").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Method)->GetFunction());
}

NODE_MODULE(openssl_example, Init);