/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.12.v201706201043.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v1/commonapi/examples/E03MethodsDBusProxy.hpp>

namespace v1 {
namespace commonapi {
namespace examples {

std::shared_ptr<CommonAPI::DBus::DBusProxy> createE03MethodsDBusProxy(
    const CommonAPI::DBus::DBusAddress &_address,
    const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection) {
    return std::make_shared< E03MethodsDBusProxy>(_address, _connection);
}

void initializeE03MethodsDBusProxy() {
     CommonAPI::DBus::Factory::get()->registerProxyCreateMethod(
        E03Methods::getInterface(),
        &createE03MethodsDBusProxy);
}

INITIALIZER(registerE03MethodsDBusProxy) {
    CommonAPI::DBus::Factory::get()->registerInterface(initializeE03MethodsDBusProxy);
}

E03MethodsDBusProxy::E03MethodsDBusProxy(
    const CommonAPI::DBus::DBusAddress &_address,
    const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection)
    :   CommonAPI::DBus::DBusProxy(_address, _connection)
,        myStatus_(*this, "myStatus", "i", std::make_tuple(static_cast< CommonAPI::DBus::IntegerDeployment* >(nullptr)))
{
}


E03MethodsDBusProxy::MyStatusEvent& E03MethodsDBusProxy::getMyStatusEvent() {
    return myStatus_;
}

    void E03MethodsDBusProxy::foo(const int32_t &_x1, const std::string &_x2, CommonAPI::CallStatus &_internalCallStatus, E03Methods::stdErrorTypeEnum &_error, int32_t &_y1, std::string &_y2, const CommonAPI::CallInfo *_info) {
        CommonAPI::Deployable< E03Methods::stdErrorTypeEnum, CommonAPI::EmptyDeployment> deploy_error(static_cast< CommonAPI::EmptyDeployment * >(nullptr));
        CommonAPI::Deployable< int32_t, CommonAPI::DBus::IntegerDeployment> deploy_x1(_x1, static_cast< CommonAPI::DBus::IntegerDeployment* >(nullptr));
        CommonAPI::Deployable< std::string, CommonAPI::DBus::StringDeployment> deploy_x2(_x2, static_cast< CommonAPI::DBus::StringDeployment* >(nullptr));
        CommonAPI::Deployable< int32_t, CommonAPI::DBus::IntegerDeployment> deploy_y1(static_cast< CommonAPI::DBus::IntegerDeployment* >(nullptr));
        CommonAPI::Deployable< std::string, CommonAPI::DBus::StringDeployment> deploy_y2(static_cast< CommonAPI::DBus::StringDeployment* >(nullptr));
        CommonAPI::DBus::DBusProxyHelper<
            CommonAPI::DBus::DBusSerializableArguments<
            CommonAPI::Deployable< int32_t, CommonAPI::DBus::IntegerDeployment >,
            CommonAPI::Deployable< std::string, CommonAPI::DBus::StringDeployment >
            >,
            CommonAPI::DBus::DBusSerializableArguments<
            CommonAPI::Deployable< E03Methods::stdErrorTypeEnum, CommonAPI::EmptyDeployment>,
            CommonAPI::Deployable< int32_t,CommonAPI::DBus::IntegerDeployment>,
            CommonAPI::Deployable< std::string,CommonAPI::DBus::StringDeployment>
            >
            >::callMethodWithReply(
        *this,
        "foo",
        "is",
(_info ? _info : &CommonAPI::DBus::defaultCallInfo),
deploy_x1, deploy_x2,
_internalCallStatus,
deploy_error,
deploy_y1, deploy_y2);
_error = deploy_error.getValue();
_y1 = deploy_y1.getValue();
_y2 = deploy_y2.getValue();
}
    std::future<CommonAPI::CallStatus> E03MethodsDBusProxy::fooAsync(const int32_t &_x1, const std::string &_x2, FooAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
        CommonAPI::Deployable< E03Methods::stdErrorTypeEnum, CommonAPI::EmptyDeployment> deploy_error(static_cast< CommonAPI::EmptyDeployment * >(nullptr));
        CommonAPI::Deployable< int32_t, CommonAPI::DBus::IntegerDeployment> deploy_x1(_x1, static_cast< CommonAPI::DBus::IntegerDeployment* >(nullptr));
        CommonAPI::Deployable< std::string, CommonAPI::DBus::StringDeployment> deploy_x2(_x2, static_cast< CommonAPI::DBus::StringDeployment* >(nullptr));
        CommonAPI::Deployable< int32_t, CommonAPI::DBus::IntegerDeployment> deploy_y1(static_cast< CommonAPI::DBus::IntegerDeployment* >(nullptr));
        CommonAPI::Deployable< std::string, CommonAPI::DBus::StringDeployment> deploy_y2(static_cast< CommonAPI::DBus::StringDeployment* >(nullptr));
        return CommonAPI::DBus::DBusProxyHelper<
            CommonAPI::DBus::DBusSerializableArguments<
            CommonAPI::Deployable< int32_t, CommonAPI::DBus::IntegerDeployment >,
            CommonAPI::Deployable< std::string, CommonAPI::DBus::StringDeployment >
            >,
            CommonAPI::DBus::DBusSerializableArguments<
            CommonAPI::Deployable< E03Methods::stdErrorTypeEnum, CommonAPI::EmptyDeployment>,
            CommonAPI::Deployable< int32_t,CommonAPI::DBus::IntegerDeployment>,
            CommonAPI::Deployable< std::string,CommonAPI::DBus::StringDeployment>
            >
            >::callMethodAsync(
        *this,
        "foo",
        "is",
        (_info ? _info : &CommonAPI::DBus::defaultCallInfo),
        deploy_x1, deploy_x2,
        [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< E03Methods::stdErrorTypeEnum, CommonAPI::EmptyDeployment > _deploy_error, CommonAPI::Deployable< int32_t, CommonAPI::DBus::IntegerDeployment > _y1, CommonAPI::Deployable< std::string, CommonAPI::DBus::StringDeployment > _y2) {
            if (_callback)
                _callback(_internalCallStatus, _deploy_error.getValue(), _y1.getValue(), _y2.getValue());
        },
        std::make_tuple(deploy_error, deploy_y1, deploy_y2));
    }


void E03MethodsDBusProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
          ownVersionMajor = 1;
          ownVersionMinor = 2;
      }

      } // namespace examples
      } // namespace commonapi
      } // namespace v1
