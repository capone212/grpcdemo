echo off

set INTERFACE_FILE=%1
set PROTOC="./../../../grpc/grpc/third_party/protobuf/vsprojects/Release/protoc.exe"
set grpc_cpp_plugin="C:/diskd/work/grpc/grpc/grpc/vsprojects/Release/grpc_cpp_plugin.exe"
set 
echo %PROTOC%
echo %INTERFACE_FILE%


echo %PROTOC% --grpc_out=. --plugin=protoc-gen-grpc=%grpc_cpp_plugin% %INTERFACE_FILE%
%PROTOC% --grpc_out=. --plugin=protoc-gen-grpc=%grpc_cpp_plugin% %INTERFACE_FILE%
%PROTOC% --cpp_out=. %INTERFACE_FILE%