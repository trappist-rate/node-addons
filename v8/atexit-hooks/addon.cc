// addon.cc
#include <assert.h>
#include <stdlib.h>
#include <node.h>

namespace demo {

    using node::AtExit;
    using v8::HandleScope;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;

    static char cookie[] = "yum yum";
    static int at_exit_cb1_called = 0;
    static int at_exit_cb2_called = 0;

    static void at_exit_cb1(void* arg) {
       Isolate* isolate = static_cast<Isolate*>(arg);
       HandleScope scope(isolate);
       Local<Object> obj = Object::New(isolate);
       assert(!obj.IsEmpty()); // assert the VM is still alive
       assert(obj->IsObject());
       at_exit_cb1_called++;
    }

    static void at_exit_cb2(void* arg) {
       assert(arg == static_cast<void*>(cookie));
       at_exit_cb2_called++;
    }

    static void sanity_check(void*) {
       assert(at_exit_cb1_called == 1);
       assert(at_exit_cb2_called == 2);
    }

   void init(Local<Object> exports) {
       AtExit(at_exit_cb2, cookie);
       AtExit(at_exit_cb2, cookie);
       AtExit(at_exit_cb1, exports->GetIsolate());
       AtExit(sanity_check);
   }

   NODE_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace demo
