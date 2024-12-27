#include "sttracker.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include "DateTime.h"

SatelliteTracker::SatelliteTracker(const std::string& name, const std::string& line1, const std::string& line2)
    : tle(name, line1, line2), sgp4(tle) {}

void SatelliteTracker::updatePosition() {
    while (true) {
        DateTime now = DateTime::Now(true);

        Eci eci = sgp4.FindPosition(now);

        Geodetic geo = eci.ToGeodetic();

        double latitude = Rad2Deg(geo.latitude);
        double longitude = Rad2Deg(geo.longitude);
        double altitude = geo.altitude;

        std::cout << "Latitude: " << latitude << ", Longitude: " << longitude << ", Altitude: " << altitude << std::endl;

        // Задержка на 60 секунд
        std::this_thread::sleep_for(std::chrono::seconds(60));
    }
}