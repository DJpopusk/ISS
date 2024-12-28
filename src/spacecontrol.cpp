#include "spacecontrol.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <iostream>
#include <ctime>
#include "sofa.h"
#include "sofam.h"
using namespace std;

LifeSupport::LifeSupport(double o2, double co2) : oxygenLevel(o2), co2Level(co2) {}

void LifeSupport::displayInfo() const {
    std::cout << "Life Support: Oxygen level: " << oxygenLevel
              << ", CO2 level: " << co2Level << std::endl;
}



const double RADIUS_EARTH = 6371.0;

double toRadians(double degree) {
    return degree * M_PI / 180.0;
}
double toDegrees(double radians) {
    return radians * 180.0 / M_PI;
}

PowerSystem::PowerSystem(double output) : energyOutput(output) {}

void PowerSystem::displayInfo() const {
    std::cout << "Current energy output: " << energyOutput << std::endl;
}

double calculateJulianDateSofa() {
    time_t now = time(NULL);
    struct tm *ptm = gmtime(&now);

    int year = ptm->tm_year + 1900;
    int month = ptm->tm_mon + 1;
    int day = ptm->tm_mday;

    double djm0, djm;

    int status = iauCal2jd(year, month, day, &djm0, &djm);
    if (status) {
        throw (AllError(AllError::DOMAIN_ERROR, "Error: mistake in solving Julian date"));
    return -1;
    }

    double fraction = (ptm->tm_hour + ptm->tm_min / 60.0 + ptm->tm_sec / 3600.0) / 24.0;

    double jd = djm0 + djm + fraction;

    return jd;
}

double calculateSolarDeclination(double JD) {
    double D = JD - 2451545.0;
    double omega = 2.1429 - 0.0010394594 * D;
    return 0.37877 + 23.264 * sin(toRadians(57.297 * D / 365.242)) + 0.3812 * sin(toRadians(2 * 57.297 * D / 365.242)) + 0.17132 * sin(toRadians(3 * 57.297 * D / 365.242));
}

double calculateHourAngle(double JD, double longitude) {
    double D = JD - 2451545.0;
    double gmst = 280.46061837 + 360.98564736629 * D;
    double lmst = fmod(gmst + longitude, 360.0);
    return lmst;
}

bool PowerSystem::isPositionSunny(double latitude, double longitude, double altitude) {
    double jd = calculateJulianDateSofa();
    double declination = calculateSolarDeclination(jd);

    double hourAngle = calculateHourAngle(jd, longitude) + 30.0;
    double cosLatitude = cos(toRadians(latitude));
    double sinLatitude = sin(toRadians(latitude));
    double cosDeclination = cos(toRadians(declination));
    double sinDeclination = sin(toRadians(declination));

    double cosHourAngle = cos(toRadians(hourAngle));
    double sinAltitude = sinLatitude * sinDeclination + cosLatitude * cosDeclination * cosHourAngle;

    double altitudeAngle = toDegrees(asin(sinAltitude));

    return altitudeAngle > 0;
}

void PowerSystem::determineSunlightExposure(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        throw (AllError(AllError::FILE_NOT_FOUND, "This file can't be open"));
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
            energyOutput += 28.3;
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

    double lat1 = toRadians(start.latitude) * (start.latDirection == 'S' ? -1 : 1);
    double lon1 = toRadians(start.longitude) * (start.longDirection == 'W' ? -1 : 1);
    double lat2 = toRadians(end.latitude) * (end.latDirection == 'S' ? -1 : 1);
    double lon2 = toRadians(end.longitude) * (end.longDirection == 'W' ? -1 : 1);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = std::pow(std::sin(dLat / 2), 2) +
               std::cos(lat1) * std::cos(lat2) * std::pow(std::sin(dLon / 2), 2);

    double c = 2 * std::asin(std::sqrt(a));

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