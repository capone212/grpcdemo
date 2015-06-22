#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>
#include <grpc++/channel_arguments.h>
#include <grpc++/channel_interface.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/credentials.h>
#include <grpc++/status.h>
#include "greeter.grpc.pb.h"

using grpc::ChannelArguments;
using grpc::ChannelInterface;
using grpc::ClientContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

class GreeterClient 
{
public:
    GreeterClient(std::shared_ptr<ChannelInterface> channel)
        : stub_(Greeter::NewStub(channel))
    {
    }

    std::string SayHello(const std::string& user) 
    {
        HelloRequest request;
        request.set_name(user);
        HelloReply reply;
        ClientContext context;

        Status status = stub_->SayHello(&context, request, &reply);
        if (status.IsOk()) 
        {
            return reply.message();
        }
        else 
        {
            return "Rpc failed";
        }
    }

private:
    std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv)
{
    GreeterClient greeter(
        grpc::CreateChannel("WIN-DK7NRRDJPS3:50051", grpc::InsecureCredentials(),
        ChannelArguments()));
    std::string user("world");
    std::string reply = greeter.SayHello(user);
    std::cout << "Greeter received: " << reply << std::endl;

    return 0;
}