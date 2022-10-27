/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.someip 3.1.12.v201907221223.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v1/commonapi/HelloWorldSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createHelloWorldSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< HelloWorldSomeIPProxy>(_address, _connection);
}

void initializeHelloWorldSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.HelloWorld:v1_0:test",
        0x1234, 0x5678, 1, 0);
     CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
         HelloWorld::getInterface(),
         &createHelloWorldSomeIPProxy);
}

INITIALIZER(registerHelloWorldSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeHelloWorldSomeIPProxy);
}

HelloWorldSomeIPProxy::HelloWorldSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection )
    {
    }



        void HelloWorldSomeIPProxy::sayHello(const std::string &_name, CommonAPI::CallStatus &_internalCallStatus, std::string &_message, const CommonAPI::CallInfo *_info) {
            CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_name(_name, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
            CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_message(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
            CommonAPI::SomeIP::ProxyHelper<
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        std::string,
                        CommonAPI::SomeIP::StringDeployment
                    >
                >,
                CommonAPI::SomeIP::SerializableArguments<
                    CommonAPI::Deployable<
                        std::string,
                        CommonAPI::SomeIP::StringDeployment
                    >
                >
            >::callMethodWithReply(
            *this,
            CommonAPI::SomeIP::method_id_t(0x7918),
            false,
            false,
    (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
    deploy_name,
    _internalCallStatus,
    deploy_message);
    _message = deploy_message.getValue();
    }
    std::future<CommonAPI::CallStatus> HelloWorldSomeIPProxy::sayHelloAsync(const std::string &_name, SayHelloAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
        CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_name(_name, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
        CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_message(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
        return CommonAPI::SomeIP::ProxyHelper<
            CommonAPI::SomeIP::SerializableArguments<
                CommonAPI::Deployable<
                    std::string,
                    CommonAPI::SomeIP::StringDeployment
                >
            >,
            CommonAPI::SomeIP::SerializableArguments<
                CommonAPI::Deployable<
                    std::string,
                    CommonAPI::SomeIP::StringDeployment
                >
            >
        >::callMethodAsync(
            *this,
            CommonAPI::SomeIP::method_id_t(0x7918),
            false,
            false,
            (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
            deploy_name,
            [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment > _message) {
                if (_callback)
                    _callback(_internalCallStatus, _message.getValue());
            },
            std::make_tuple(deploy_message));
    }



    void HelloWorldSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
    }

} // namespace commonapi
} // namespace v1
