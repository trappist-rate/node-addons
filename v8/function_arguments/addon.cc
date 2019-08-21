// hello.cc
#include <node.h>

namespace demo {

    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::NewStringType;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Add(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        if (args.Length() < 2) {
             isolate->ThrowException(Exception::TypeError(
                 String::NewFromUtf8(isolate, "Wrong number of arguments",
                                     NewStringType::kNormal).ToLocalChecked()));
             return;
        }

        // check the argument types
        if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Wrong argument type", 
                NewStringType::kNormal).ToLocalChecked()));
            return;
        }

        double value = args[0].As<Number>()->Value() + args[1].As<Number>()->Value();
        Local<Number> num = Number::New(isolate, value);
        args.GetReturnValue().Set(num);
    }

    void Init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "add", Add);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Init)
} // namespace demo
