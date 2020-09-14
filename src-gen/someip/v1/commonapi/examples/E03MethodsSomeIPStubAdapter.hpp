/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.someip 3.1.12.v201706201046.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_EXAMPLES_E03_METHODS_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_EXAMPLES_E03_METHODS_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/examples/E03MethodsStub.hpp>
#include <v1/commonapi/examples/E03MethodsSomeIPDeployment.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace commonapi {
namespace examples {

template <typename _Stub = ::v1::commonapi::examples::E03MethodsStub, typename... _Stubs>
class E03MethodsSomeIPStubAdapterInternal
    : public virtual E03MethodsStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> E03MethodsSomeIPStubAdapterHelper;

    ~E03MethodsSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        E03MethodsSomeIPStubAdapterHelper::deinit();
    }

    void fireMyStatusEvent(const int32_t& myCurrentValue);

    void deactivateManagedInstances() {
    }

    static CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::examples::E03MethodsStub,
        CommonAPI::Version
    > getE03MethodsInterfaceVersionStubDispatcher;


    
    static CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::examples::E03MethodsStub,
        std::tuple< int32_t, std::string>,
        std::tuple< E03Methods::stdErrorTypeEnum, int32_t, std::string>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>, CommonAPI::SomeIP::StringDeployment>,
        std::tuple< ::v1::commonapi::examples::E03Methods_::stdErrorTypeEnumDeployment_t, CommonAPI::SomeIP::IntegerDeployment<int32_t>, CommonAPI::SomeIP::StringDeployment>
    > fooStubDispatcher;

    E03MethodsSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        E03MethodsSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< E03MethodsStub>(_stub))
    {

        
                E03MethodsSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7530) }, &fooStubDispatcher );

        // Provided events/fields
        {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(0x80f2));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x80f2), itsEventGroups, false);
        }
    }

private:
};

template <typename _Stub, typename... _Stubs>
CommonAPI::SomeIP::GetAttributeStubDispatcher<
    ::v1::commonapi::examples::E03MethodsStub,
    CommonAPI::Version
    > E03MethodsSomeIPStubAdapterInternal<_Stub, _Stubs...>::getE03MethodsInterfaceVersionStubDispatcher(&E03MethodsStub::getInterfaceVersion, false);

template <typename _Stub, typename... _Stubs>
CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
    ::v1::commonapi::examples::E03MethodsStub,
    std::tuple< int32_t, std::string>,
    std::tuple< E03Methods::stdErrorTypeEnum, int32_t, std::string>,
    std::tuple< CommonAPI::SomeIP::IntegerDeployment<int32_t>, CommonAPI::SomeIP::StringDeployment>,
    std::tuple< ::v1::commonapi::examples::E03Methods_::stdErrorTypeEnumDeployment_t, CommonAPI::SomeIP::IntegerDeployment<int32_t>, CommonAPI::SomeIP::StringDeployment>
> E03MethodsSomeIPStubAdapterInternal<_Stub, _Stubs...>::fooStubDispatcher(
    &E03MethodsStub::foo,
    false,
    std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr), &::v1::commonapi::examples::E03Methods_::foo_x2Deployment),
    std::make_tuple(static_cast< ::v1::commonapi::examples::E03Methods_::stdErrorTypeEnumDeployment_t * >(nullptr), static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr), &::v1::commonapi::examples::E03Methods_::foo_y2Deployment));

template <typename _Stub, typename... _Stubs>
void E03MethodsSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireMyStatusEvent(const int32_t& _myCurrentValue) {
    CommonAPI::Deployable< int32_t, CommonAPI::SomeIP::IntegerDeployment<int32_t>> deployed_myCurrentValue(_myCurrentValue, static_cast< CommonAPI::SomeIP::IntegerDeployment<int32_t>* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<CommonAPI::SomeIP::SerializableArguments<  CommonAPI::Deployable< int32_t, CommonAPI::SomeIP::IntegerDeployment<int32_t> > 
    >>
        ::sendEvent(
            *this,
            CommonAPI::SomeIP::event_id_t(0x80f2),
            false,
             deployed_myCurrentValue 
    );
}

template <typename _Stub = ::v1::commonapi::examples::E03MethodsStub, typename... _Stubs>
class E03MethodsSomeIPStubAdapter
    : public E03MethodsSomeIPStubAdapterInternal<_Stub, _Stubs...>,
      public std::enable_shared_from_this< E03MethodsSomeIPStubAdapter<_Stub, _Stubs...>> {
public:
    E03MethodsSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          E03MethodsSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace examples
} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_EXAMPLES_E03_Methods_SOMEIP_STUB_ADAPTER_HPP_
