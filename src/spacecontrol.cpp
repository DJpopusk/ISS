#include "spacecontrol.h"

LifeSupport::LifeSupport(double o2, double co2) : oxygenLevel(o2), co2Level(co2) {}

void LifeSupport::displayInfo() const {
    std::cout << "Life Support: Oxygen level: " << oxygenLevel
              << ", CO2 level: " << co2Level << std::endl;
}

PowerSystem::PowerSystem(double output) : energyOutput(output) {}

void PowerSystem::displayInfo() const {
    std::cout << "Power System: Energy Output: " << energyOutput << " kW" << std::endl;
}

Propulsion::Propulsion(double thrustValue) : thrust(thrustValue) {}

Propulsion::Propulsion() : thrust(0.0) {}

void Propulsion::applyThrust(double thrust, double duration) {
    thrustData.emplace_back(thrust, duration);
}

void Propulsion::recordData(const std::string &filename) const {
    std::filesystem::path filepath(filename);
    std::filesystem::create_directories(filepath.parent_path());

    std::ofstream file(filename, std::ios::out | std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const auto &data : thrustData) {
        file << data.first << " " << data.second << std::endl;
    }

    file.close();
}

void Propulsion::displayInfo() const {
    std::cout << "Propulsion: Thrust: " << thrust << " N" << std::endl;
    for (const auto &data : thrustData) {
        std::cout << "Thrust: " << data.first << ", Duration: " << data.second << std::endl;
    }
}

Laboratory::Laboratory(const std::string& exp, int count) : experiments(exp), personnelCount(count) {}

void Laboratory::displayInfo() const {
    std::cout << "Laboratory: Ongoing Experiments: " << experiments
              << ", Personnel Count: " << personnelCount << std::endl;
}

LivingQuarters::LivingQuarters(int cap, int occ) : capacity(cap), occupied(occ) {}

void LivingQuarters::displayInfo() const {
    std::cout << "Living Quarters: Capacity: " << capacity
              << ", Occupied: " << occupied << std::endl;
}

Manipulator::Manipulator(int level) : dexterityLevel(level) {}

void Manipulator::displayInfo() const {
    std::cout << "Manipulator: Dexterity Level: " << dexterityLevel << std::endl;
}

SecuritySystem::SecuritySystem(bool secured) : isSecured(secured) {}

void SecuritySystem::displayInfo() const {
    std::cout << "Security System: Secured: " << (isSecured ? "Yes" : "No") << std::endl;
}

void MKS::addModule(SpaceControl* module) {
    modules.push_back(module);
}

void MKS::displayInfo() const {
    std::cout << "MKS Modules Information:" << std::endl;
    for (const auto& module : modules) {
        module->displayInfo();
    }
}

MKS::~MKS() {
    for (auto module : modules) {
        delete module;
    }
}