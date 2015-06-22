// Generated by the gRPC protobuf plugin.
// If you make any local change, they will be lost.
// source: greeter.proto
#ifndef GRPC_greeter_2eproto__INCLUDED
#define GRPC_greeter_2eproto__INCLUDED

#include "greeter.pb.h"

#include <grpc++/impl/internal_stub.h>
#include <grpc++/impl/rpc_method.h>
#include <grpc++/impl/service_type.h>
#include <grpc++/async_unary_call.h>
#include <grpc++/status.h>
#include <grpc++/stream.h>

namespace grpc {
class CompletionQueue;
class ChannelInterface;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace helloworld {

class Greeter GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status SayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::helloworld::HelloReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>> AsyncSayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>>(AsyncSayHelloRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::helloworld::HelloReply>* AsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface, public ::grpc::InternalStub {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status SayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::helloworld::HelloReply* response) GRPC_OVERRIDE;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>> AsyncSayHello(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>>(AsyncSayHelloRaw(context, request, cq));
    }

   private:
    ::grpc::ClientAsyncResponseReader< ::helloworld::HelloReply>* AsyncSayHelloRaw(::grpc::ClientContext* context, const ::helloworld::HelloRequest& request, ::grpc::CompletionQueue* cq) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_SayHello_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);

  class Service : public ::grpc::SynchronousService {
   public:
    Service() : service_(nullptr) {}
    virtual ~Service();
    virtual ::grpc::Status SayHello(::grpc::ServerContext* context, const ::helloworld::HelloRequest* request, ::helloworld::HelloReply* response);
    ::grpc::RpcService* service() GRPC_OVERRIDE GRPC_FINAL;
   private:
    ::grpc::RpcService* service_;
  };
  class AsyncService GRPC_FINAL : public ::grpc::AsynchronousService {
   public:
    explicit AsyncService();
    ~AsyncService() {};
    void RequestSayHello(::grpc::ServerContext* context, ::helloworld::HelloRequest* request, ::grpc::ServerAsyncResponseWriter< ::helloworld::HelloReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag);
  };
};

class SourceEndpoint GRPC_FINAL {
 public:
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientReaderInterface< ::helloworld::MediaPacket>> RequestPackets(::grpc::ClientContext* context, const ::helloworld::RequesArg& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::helloworld::MediaPacket>>(RequestPacketsRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::helloworld::MediaPacket>> AsyncRequestPackets(::grpc::ClientContext* context, const ::helloworld::RequesArg& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::helloworld::MediaPacket>>(AsyncRequestPacketsRaw(context, request, cq, tag));
    }
  private:
    virtual ::grpc::ClientReaderInterface< ::helloworld::MediaPacket>* RequestPacketsRaw(::grpc::ClientContext* context, const ::helloworld::RequesArg& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::helloworld::MediaPacket>* AsyncRequestPacketsRaw(::grpc::ClientContext* context, const ::helloworld::RequesArg& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
  };
  class Stub GRPC_FINAL : public StubInterface, public ::grpc::InternalStub {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReader< ::helloworld::MediaPacket>> RequestPackets(::grpc::ClientContext* context, const ::helloworld::RequesArg& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::helloworld::MediaPacket>>(RequestPacketsRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::helloworld::MediaPacket>> AsyncRequestPackets(::grpc::ClientContext* context, const ::helloworld::RequesArg& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::helloworld::MediaPacket>>(AsyncRequestPacketsRaw(context, request, cq, tag));
    }

   private:
    ::grpc::ClientReader< ::helloworld::MediaPacket>* RequestPacketsRaw(::grpc::ClientContext* context, const ::helloworld::RequesArg& request) GRPC_OVERRIDE;
    ::grpc::ClientAsyncReader< ::helloworld::MediaPacket>* AsyncRequestPacketsRaw(::grpc::ClientContext* context, const ::helloworld::RequesArg& request, ::grpc::CompletionQueue* cq, void* tag) GRPC_OVERRIDE;
    const ::grpc::RpcMethod rpcmethod_RequestPackets_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);

  class Service : public ::grpc::SynchronousService {
   public:
    Service() : service_(nullptr) {}
    virtual ~Service();
    virtual ::grpc::Status RequestPackets(::grpc::ServerContext* context, const ::helloworld::RequesArg* request, ::grpc::ServerWriter< ::helloworld::MediaPacket>* writer);
    ::grpc::RpcService* service() GRPC_OVERRIDE GRPC_FINAL;
   private:
    ::grpc::RpcService* service_;
  };
  class AsyncService GRPC_FINAL : public ::grpc::AsynchronousService {
   public:
    explicit AsyncService();
    ~AsyncService() {};
    void RequestRequestPackets(::grpc::ServerContext* context, ::helloworld::RequesArg* request, ::grpc::ServerAsyncWriter< ::helloworld::MediaPacket>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag);
  };
};

}  // namespace helloworld


#endif  // GRPC_greeter_2eproto__INCLUDED
