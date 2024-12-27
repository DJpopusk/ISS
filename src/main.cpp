#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include "spacecontrol.h"
#include "sttracker.h"

std::tuple<double, char, double, char, double> parseCoordinates(const std::string& coordinateString) {
    double latitude, longitude, altitude;
    char latDir, longDir;
    std::istringstream iss(coordinateString);
    char comma;

    iss >> latitude >> comma >> latDir >> comma >> longitude >> comma >> longDir >> comma >> altitude;

    return std::make_tuple(latitude, latDir, longitude, longDir, altitude);
}

int main() {
    std::ifstream file("output/coordinates.txt");
    std::string line;
    std::vector<SpaceControl*> systems;

    PowerSystem ps(100.0);

    std::cout << "Initial energy status:" << std::endl;
    ps.displayInfo();

    ps.determineSunlightExposure("output/coordinates.txt");

    std::cout << "Energy status after processing coordinates:" << std::endl;
    ps.displayInfo();

    double o2Level = 0.21;
    double co2Level = 0.03;

    LifeSupport* lifeSupport = new LifeSupport(o2Level, co2Level);
    systems.push_back(lifeSupport);

    std::vector<Propulsion::Position> positions;
    while (std::getline(file, line)) {
        auto [latitude, latDir, longitude, longDir, altitude] = parseCoordinates(line);
        positions.emplace_back(latitude, latDir, longitude, longDir, altitude);
    }

    if (positions.size() >= 2) {
        systems.push_back(new Propulsion(positions, 60.0));
    } else {
        std::cerr << "Insufficient data to calculate speed." << std::endl;
    }

    for (const auto& system : systems) {
        system->displayInfo();
    }

    std::string name = "ISS (ZARYA)";
    std::string line1 = "1 25544U 98067A   24362.49453935  .00025652  00000+0  45083-3 0  9991";
    std::string line2 = "2 25544  51.6383  77.6130 0005797  11.6555 348.4567 15.50310083488534";
    SatelliteTracker tracker(name, line1, line2);
    tracker.updatePosition();

    // Очистка ресурсов
    for (auto system : systems) {
        delete system;
    }

    return 0;
}