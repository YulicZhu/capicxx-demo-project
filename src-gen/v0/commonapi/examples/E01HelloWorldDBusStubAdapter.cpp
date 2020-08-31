/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.12.v201706201043.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v0/commonapi/examples/E01HelloWorld.hpp>
#include <v0/commonapi/examples/E01HelloWorldDBusStubAdapter.hpp>

namespace v0 {
namespace commonapi {
namespace examples {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createE01HelloWorldDBusStubAdapter(
                   const CommonAPI::DBus::DBusAddress &_address,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
                   const std::shared_ptr<CommonAPI::StubBase> &_stub) {
    return std::make_shared< E01HelloWorldDBusStubAdapter<::v0::commonapi::examples::E01HelloWorldStub>>(_address, _connection, std::dynamic_pointer_cast<::v0::commonapi::examples::E01HelloWorldStub>(_stub));
}

void initializeE01HelloWorldDBusStubAdapter() {
    CommonAPI::DBus::Factory::get()->registerStubAdapterCreateMethod(
        E01HelloWorld::getInterface(), &createE01HelloWorldDBusStubAdapter);
}

INITIALIZER(registerE01HelloWorldDBusStubAdapter) {
    CommonAPI::DBus::Factory::get()->registerInterface(initializeE01HelloWorldDBusStubAdapter);
}

} // namespace examples
} // namespace commonapi
} // namespace v0
