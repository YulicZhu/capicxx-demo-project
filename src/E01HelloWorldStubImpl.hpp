#ifndef E01HELLOWORLDSTUBIMPL_H_
#define E01HELLOWORLDSTUBIMPL_H_

#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/examples/E01HelloWorldStubDefault.hpp>

class E01HelloWorldStubImpl: public v0_1::commonapi::examples::E01HelloWorldStubDefault {

public:
    E01HelloWorldStubImpl();
    virtual ~E01HelloWorldStubImpl();

    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _return);

};

#endif /* E01HELLOWORLDSTUBIMPL_H_ */
