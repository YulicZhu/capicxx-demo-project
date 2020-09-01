cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

FIND_PACKAGE(CommonAPI 3.1.12 REQUIRED CONFIG NO_CMAKE_PACKAGE_REGISTRY)
FIND_PACKAGE(CommonAPI-DBus 3.1.12 REQUIRED CONFIG NO_CMAKE_PACKAGE_REGISTRY)
find_package (CommonAPI-SomeIP 3.1.12 REQUIRED)
find_package (vsomeip 2.7.0 REQUIRED)
find_package( Boost 1.54 COMPONENTS system thread log REQUIRED )

include(FindPkgConfig)
pkg_check_modules(DBus REQUIRED dbus-1>=1.4)

include_directories(
    src-gen
    ${COMMONAPI_INCLUDE_DIRS}
    ${COMMONAPI_DBUS_INCLUDE_DIRS}
    ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
    ${DBus_INCLUDE_DIRS}
    ${VSOMEIP_INCLUDE_DIRS}
)
link_directories(
    ${COMMONAPI_LIBDIR}
    ${COMMONAPI_DBUS_LIBDIR}
    ${COMMONAPI_SOMEIP_CMAKE_DIR}/build
    ${Boost_LIBRARY_DIR}
)

add_executable(E01HelloWorldClient_DBus
        src/E01HelloWorldClient.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldDBusProxy.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldDBusDeployment.cpp
)
target_link_libraries(E01HelloWorldClient_DBus CommonAPI CommonAPI-DBus dbus-1)
add_executable(E01HelloWorldService_DBus
        src/E01HelloWorldService.cpp
        src/E01HelloWorldStubImpl.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldDBusStubAdapter.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldStubDefault.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldDBusDeployment.cpp
)
target_link_libraries(E01HelloWorldService_DBus CommonAPI CommonAPI-DBus dbus-1)
add_executable(E01HelloWorldClient_SomeIP
        src/E01HelloWorldClient.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldSomeIPProxy.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(E01HelloWorldClient_SomeIP CommonAPI CommonAPI-SomeIP vsomeip)
add_executable(E01HelloWorldService_SomeIP
        src/E01HelloWorldService.cpp
        src/E01HelloWorldStubImpl.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldSomeIPStubAdapter.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldStubDefault.cpp
        src-gen/v0/commonapi/examples/E01HelloWorldSomeIPDeployment.cpp
)
target_link_libraries(E01HelloWorldService_SomeIP CommonAPI CommonAPI-SomeIP vsomeip)
install(TARGETS E01HelloWorldClient_SomeIP E01HelloWorldService_SomeIP E01HelloWorldClient_DBus E01HelloWorldService_DBus
        RUNTIME DESTINATION bin)
