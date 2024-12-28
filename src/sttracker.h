#ifndef STTRACKER_H
#define STTRACKER_H
#include <string>
#include "SGP4.h"
#include "sofa.h"
#include "Tle.h"

class SatelliteTracker {
private:
    libsgp4::Tle tle;
    libsgp4::SGP4 sgp4;

public:
    SatelliteTracker(const std::string& name, const std::string& line1, const std::string& line2);
    void updatePosition();
};

#endif //STTRACKER_H
