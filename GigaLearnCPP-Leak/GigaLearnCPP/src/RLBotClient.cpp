#include "RLBotClient.h"

#include <iostream>

struct RLBotClient::Impl {
    std::string host;
    std::uint16_t port = 0;
    bool connected = false;
};

void RLBotClient::Connect(const std::string &host, std::uint16_t port) {
    if (!impl) {
        impl = std::make_unique<Impl>();
    }
    impl->host = host;
    impl->port = port;
    impl->connected = true;
    std::cout << "[RLBotClient] Connecting to " << host << ":" << port << std::endl;
}

void RLBotClient::SendObservation(const std::vector<float> &obs) {
    if (!impl || !impl->connected) {
        std::cerr << "[RLBotClient] Cannot send observation before connecting" << std::endl;
        return;
    }
    std::cout << "[RLBotClient] Sending observation with " << obs.size() << " floats" << std::endl;
}

void RLBotClient::SendAction(const std::vector<float> &action) {
    if (!impl || !impl->connected) {
        std::cerr << "[RLBotClient] Cannot send action before connecting" << std::endl;
        return;
    }
    std::cout << "[RLBotClient] Sending action with " << action.size() << " floats" << std::endl;
}

void RLBotClient::Close() {
    if (!impl || !impl->connected) {
        return;
    }
    std::cout << "[RLBotClient] Closing connection to " << impl->host << std::endl;
    impl->connected = false;
}
