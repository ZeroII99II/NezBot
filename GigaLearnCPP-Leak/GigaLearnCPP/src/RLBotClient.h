#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

// Minimal stub that mirrors the GigaLearn-RLBot example interface. It can be
// replaced with the upstream implementation once you pull in the leak.
class RLBotClient {
public:
    RLBotClient() = default;
    ~RLBotClient() = default;

    void Connect(const std::string &host, std::uint16_t port);
    void SendObservation(const std::vector<float> &obs);
    void SendAction(const std::vector<float> &action);
    void Close();

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
