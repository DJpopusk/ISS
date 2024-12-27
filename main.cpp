#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include "spacecontrol.h"

using namespace std;

tuple<double, char, double, char, double> parseCoordinates(const string& coordinateString) {
    double latitude, longitude, altitude;
    char latDir, longDir;
    istringstream iss(coordinateString);
    char comma;

    iss >> latitude >> comma >> latDir >> comma >> longitude >> comma >> longDir >> comma >> altitude;

    return make_tuple(latitude, latDir, longitude, longDir, altitude);
}

int main() {
    ifstream file("output/coordinates.txt");
    string line;
    vector<SpaceControl*> systems;

    SpaceControl* Error;

    PowerSystem ps(100.0);

    cout << "Initial energy status:" << endl;
    ps.displayInfo();

    ps.determineSunlightExposure("output/coordinates.txt");

    cout << "Energy status after processing coordinates:" << endl;
    ps.displayInfo();

    double o2Level = 0.21;
    double co2Level = 0.03;

    LifeSupport* lifeSupport = new LifeSupport(o2Level, co2Level);
    systems.push_back(lifeSupport);

    vector<Propulsion::Position> positions;
    while (getline(file, line)) {
        auto [latitude, latDir, longitude, longDir, altitude] = parseCoordinates(line);
        positions.emplace_back(latitude, latDir, longitude, longDir, altitude);
    }

    if (positions.size() >= 2) {
        systems.push_back(new Propulsion(positions, 60.0));
    } else {
        // cerr << "Insufficient data to calculate speed." << endl;
        throw (Error(AllError::INVALID_INPUT, "Insufficient data to calculate speed."));
    }

    for (const auto& system : systems) {
        system->displayInfo();
    }

    return 0;
}