#include "RLBotClient.h"

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

int main() {
    constexpr std::uint16_t kPort = 23234;
    const std::string host = "127.0.0.1";

    RLBotClient client;
    client.Connect(host, kPort);

    std::vector<float> dummyObs(256, 0.0f);
    std::vector<float> dummyAction(8, 0.0f);

    std::cout << "[rlbotmain] Connected to RLBot shim at " << host << ":" << kPort << std::endl;
    for (int tick = 0; tick < 5; ++tick) {
        client.SendObservation(dummyObs);
        client.SendAction(dummyAction);
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    client.Close();
    std::cout << "[rlbotmain] Shutdown complete" << std::endl;
    return 0;
}
