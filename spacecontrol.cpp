#include "spacecontrol.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>
#include <ctime>

using namespace std;

LifeSupport::LifeSupport(double o2, double co2) : oxygenLevel(o2), co2Level(co2) {}

void LifeSupport::displayInfo() const {
    cout << "Life Support: Oxygen level: " << oxygenLevel
              << ", CO2 level: " << co2Level << endl;
}

const double RADIUS_EARTH = 6371.0;

AllError Error;

PowerSystem::PowerSystem(double output) : energyOutput(output) {}

void PowerSystem::displayInfo() const {
    cout << "Current energy output: " << energyOutput << endl;
}

double calculateJulianDate() {
    time_t now = time(0);
    struct tm* utc_time = gmtime(&now); 
    int year = utc_time->tm_year + 1900;
    int month = utc_time->tm_mon + 1;
    int day = utc_time->tm_mday;

    if (month <= 2) {
        year -= 1;
        month += 12;
    }

    int A = year / 100;
    int B = 2 - A + (A / 4);

    double JD = floor(365.25 * (year + 4716)) + floor(30.6001 * (month + 1)) + day + B - 1524.5;
    JD += (utc_time->tm_hour + utc_time->tm_min / 60.0 + utc_time->tm_sec / 3600.0) / 24.0;
    return JD;
}

double sunDeclination(double JD) {
    double n = JD - 2451545.0;
    double L = 280.46 + 0.9856474 * n;
    L = fmod(L, 360.0);
    if (L < 0) L += 360.0;

    double g = 357.528 + 0.9856003 * n;
    g = fmod(g, 360.0);

    double lambda = L + 1.915 * sin(g * M_PI / 180) + 0.020 * sin(2 * g * M_PI / 180);
    return asin(sin(lambda * M_PI / 180) * sin(23.44 * M_PI / 180)) * 180 / M_PI;
}

double calculateHourAngle(double longitude, double JD) {
    double n = JD - 2451545.0;
    double LST = fmod(280.46061837 + 360.98564736629 * n + longitude, 360.0);
    return LST;
}
bool PowerSystem::isPositionSunny(double latitude, double longitude, double altitude) {
    double JD = calculateJulianDate();
    double declination = sunDeclination(JD);
    double hourAngle = calculateHourAngle(longitude, JD);

    // Calculate solar altitude
    double latRad = latitude * M_PI / 180;
    double decRad = declination * M_PI / 180;
    double hourAngleRad = (hourAngle - 180) * M_PI / 180;

    double altitudeAngle = asin(sin(latRad) * sin(decRad) + cos(latRad) * cos(decRad) * cos(hourAngleRad)) * 180 / M_PI;

    return altitudeAngle > 0;
}


void PowerSystem::determineSunlightExposure(const string& filePath) {
    ifstream inFile(filePath);
    if (!inFile) {
        // cerr << "Error: Unable to open file " << filePath << endl; ///////// вызов ф-ции из библиотеки о невозможности открыть файл
        throw (AllError(AllError::FILE_NOT_FOUND, "This file can't be open"));
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        double latitude, longitude, altitude;
        char latDir, longDir;
        char comma;

        ss >> latitude >> comma >> latDir >> comma >> longitude >> comma >> longDir >> comma >> altitude;

        latitude *= (latDir == 'S') ? -1 : 1;
        longitude *= (longDir == 'W') ? -1 : 1;

        if (isPositionSunny(latitude, longitude, altitude)) {
            energyOutput += 10.0;
            cout << "Position in sunlight: (" << latitude << ", " << longitude << ", " << altitude << ")\n";
        } else {
            cout << "Position not in sunlight: (" << latitude << ", " << longitude << ", " << altitude << ")\n";
        }
    }
    inFile.close();
}

Propulsion::Propulsion(const vector<Position>& pos, double dT)
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

    double a = pow(sin(dLat / 2), 2) +
               cos(lat1) * cos(lat2) * pow(sin(dLon / 2), 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double surfaceDistance = RADIUS_EARTH * c;
    double altitudeChange = end.altitude - start.altitude;
    double distance = sqrt(pow(surfaceDistance, 2) + pow(altitudeChange, 2));

    return distance / deltaTime;
}

void Propulsion::displayInfo() const {
    cout << "Propulsion System: Calculated Speed = " << calculateSpeed() << " km/s" << endl;
}

Laboratory::Laboratory(const string& exp, int count) : experiments(exp), personnelCount(count) {}

void Laboratory::displayInfo() const {
    cout << "Laboratory: Ongoing Experiments: " << experiments
              << ", Personnel Count: " << personnelCount << endl;
}

LivingQuarters::LivingQuarters(int cap, int occ) : capacity(cap), occupied(occ) {}

void LivingQuarters::displayInfo() const {
    cout << "Living Quarters: Capacity: " << capacity
              << ", Occupied: " << occupied << endl;
}

Manipulator::Manipulator(int level) : dexterityLevel(level) {}

void Manipulator::displayInfo() const {
    cout << "Manipulator: Dexterity Level: " << dexterityLevel << endl;
}

SecuritySystem::SecuritySystem(bool secured) : isSecured(secured) {}

void SecuritySystem::displayInfo() const {
    cout << "Security System: Secured: " << (isSecured ? "Yes" : "No") << endl;
}

void MKS::addModule(SpaceControl* module) {
    modules.push_back(module);
}

void MKS::displayInfo() const {
    cout << "MKS Modules Information:" << endl;
    for (const auto& module : modules) {
        module->displayInfo();
    }
}

MKS::~MKS() {
    for (auto module : modules) {
        delete module;
    }
}