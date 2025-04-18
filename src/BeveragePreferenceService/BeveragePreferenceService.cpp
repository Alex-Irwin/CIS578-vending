// src/BeveragePreferenceService/BeveragePreferenceService.cpp
#include <iostream>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "../gen-cpp/BeveragePreferenceService.h"
#include "BeveragePreferenceHandler.h"
#include <fstream>
#include <sstream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace std;
using namespace vending_machine; // Use vending_machine namespace

int main(int argc, char **argv) {
  int port = 9092; // Choose a port for your service

  shared_ptr<vending_machine::BeveragePreferenceHandler> handler(new vending_machine::BeveragePreferenceHandler());
  shared_ptr<TProcessor> processor(new BeveragePreferenceServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  cout << "Starting the beverage preference server..." << endl;
  server.serve();
  cout << "done." << endl;
  return 0;
}
