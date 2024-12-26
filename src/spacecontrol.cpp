#include "spacecontrol.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>

const double RADIUS_EARTH = 6371.0;

LifeSupport::LifeSupport(double o2, double co2) : oxygenLevel(o2), co2Level(co2) {}

void LifeSupport::displayInfo() const {
    std::cout << "Life Support: Oxygen level: " << oxygenLevel
              << ", CO2 level: " << co2Level << std::endl;
}

PowerSystem::PowerSystem(double output) : energyOutput(output) {}

void PowerSystem::displayInfo() const {
    std::cout << "Current energy output: " << energyOutput << std::endl;
}

bool PowerSystem::isPositionSunny(double latitude, double longitude, double altitude) {
    return (altitude > 0);
}

void PowerSystem::determineSunlightExposure(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        double latitude, longitude, altitude;
        char latDir, longDir;
        char comma;

        ss >> latitude >> comma >> latDir >> comma >> longitude >> comma >> longDir >> comma >> altitude;

        latitude *= (latDir == 'S') ? -1 : 1;
        longitude *= (longDir == 'W') ? -1 : 1;

        if (isPositionSunny(latitude, longitude, altitude)) {
            energyOutput += 10.0;
            std::cout << "Position in sunlight: (" << latitude << ", " << longitude << ", " << altitude << ")\n";
        } else {
            std::cout << "Position not in sunlight: (" << latitude << ", " << longitude << ", " << altitude << ")\n";
        }
    }
    inFile.close();
}

Propulsion::Propulsion(const std::vector<Position>& pos, double dT)
    : positions(pos), deltaTime(dT) {}

double Propulsion::calculateSpeed() const {
    if (positions.size() < 2) return 0.0;

    const Position& start = positions.front();
    const Position& end = positions.back();

    auto toRadians = [](double degree) { return degree * M_PI / 180.0; };

    double lat1 = toRadians(start.latitude) * (start.latDirection == 'S' ? -1 : 1);
    double lon1 = toRadians(start.longitude) * (start.longDirection == 'W' ? -1 : 1);
    double lat2 = toRadians(end.latitude) * (end.latDirection == 'S' ? -1 : 1);
    double lon2 = toRadians(end.longitude) * (end.longDirection == 'W' ? -1 : 1);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = std::pow(std::sin(dLat / 2), 2) +
               std::cos(lat1) * std::cos(lat2) * std::pow(std::sin(dLon / 2), 2);

    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    double surfaceDistance = RADIUS_EARTH * c;
    double altitudeChange = end.altitude - start.altitude;
    double distance = std::sqrt(std::pow(surfaceDistance, 2) + std::pow(altitudeChange, 2));

    return distance / deltaTime;
}

void Propulsion::displayInfo() const {
    std::cout << "Propulsion System: Calculated Speed = " << calculateSpeed() << " km/s" << std::endl;
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