#include "node.h"
#include "nan.h"

#include <openssl/ssl.h>

NAN_METHOD(Do) {
  SSL_library_init();
}

NAN_MODULE_INIT(init) {
  Nan::HandleScope scope;
  Nan::SetMethod(target, "do", Do);
}
NODE_MODULE(openssl_example, init);
