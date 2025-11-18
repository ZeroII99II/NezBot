#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

int main() {
    const fs::path collisionMeshes = fs::path{"collision_meshes"};
    if (!fs::exists(collisionMeshes)) {
        std::cerr << "[ExampleMain] collision_meshes folder missing. Drop it next to the executable or update ExampleMain.cpp."
                  << std::endl;
        return 1;
    }

    std::cout << "[ExampleMain] Loading meshes from " << fs::absolute(collisionMeshes) << std::endl;
    // Insert arena + car setup logic from your training binary here.
    return 0;
}
