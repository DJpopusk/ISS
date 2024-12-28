#include "sttracker.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include "DateTime.h"
#include "spacecontrol.h"

SatelliteTracker::SatelliteTracker(const std::string& name, const std::string& line1, const std::string& line2)
    : tle(name, line1, line2), sgp4(tle) {}

double Rad2Deg(double scalar) {
    return scalar/M_PI * 180.0;
}

void SatelliteTracker::updatePosition() {
    PowerSystem powerSystem(0.0);
    while (true) {
        libsgp4::DateTime now = libsgp4::DateTime::Now(true);
        libsgp4::Eci eci = sgp4.FindPosition(now);
        libsgp4::CoordGeodetic geo = eci.ToGeodetic();

        double latitude = Rad2Deg(geo.latitude);
        double longitude = Rad2Deg(geo.longitude);
        double altitude = geo.altitude;

        std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << ", Altitude: " << altitude << std::endl;

        bool sunny = powerSystem.isPositionSunny(latitude, longitude, altitude);
        double energyChange = sunny ? 10.0 : 0.0;
        powerSystem.energyOutput += energyChange;

        std::cout << "Energy added: " << energyChange << std::endl;
        std::cout << "Total energy: " << powerSystem.energyOutput << std::endl;
        // Sleep for 10 seconds
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}