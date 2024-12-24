#include <iostream>
#include "spacecontrol.h"
#include <filesystem>

int main() {
    Propulsion propulsionSystem;

    propulsionSystem.applyThrust(100.0, 2.5);
    propulsionSystem.applyThrust(150.0, 3.0);
    propulsionSystem.applyThrust(200.0, 1.8);

    propulsionSystem.displayInfo();

    std::string directory = "output";
    std::string filename = "thrust_data.txt";

    try {
        if (!std::filesystem::exists(directory)) {
            std::filesystem::create_directory(directory);
        }

        propulsionSystem.recordData(directory + "/" + filename);

        std::cout << "Data recorded successfully in " << directory + "/" + filename << std::endl;
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}