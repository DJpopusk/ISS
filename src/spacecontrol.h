#ifndef SPACECONTROL_H
#define SPACECONTROL_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>

// Forward declare classes if used before their definition
class SpaceControl {
public:
    virtual void displayInfo() const = 0;
    virtual ~SpaceControl() = default;
};

class LifeSupport : public SpaceControl {
private:
    double oxygenLevel, co2Level;
public:
    LifeSupport(double o2, double co2);
    void displayInfo() const override;
};

class PowerSystem : public SpaceControl {
private:
    double energyOutput;
public:
    PowerSystem(double output);
    void displayInfo() const override;
};

class Propulsion : public SpaceControl {
public:
    struct Position {
        double latitude;
        char latDirection; // 'N' or 'S'
        double longitude;
        char longDirection; // 'E' or 'W'
        double altitude;

        Position(double lat, char latDir, double lon, char longDir, double alt)
            : latitude(lat), latDirection(latDir), longitude(lon), longDirection(longDir), altitude(alt) {}
    };

    std::vector<Position> positions;
    double deltaTime;
    Propulsion(const std::vector<Position>& pos, double dT);
    double calculateSpeed() const;
    void displayInfo() const override;
};

class Laboratory : public SpaceControl {
private:
    std::string experiments;
    int personnelCount;
public:
    Laboratory(const std::string& exp, int count);
    void displayInfo() const override;
};

class LivingQuarters : public SpaceControl {
private:
    int capacity, occupied;
public:
    LivingQuarters(int cap, int occ);
    void displayInfo() const override;
};

class Manipulator : public SpaceControl {
private:
    int dexterityLevel;
public:
    Manipulator(int level);
    void displayInfo() const override;
};

class SecuritySystem : public SpaceControl {
private:
    bool isSecured;
public:
    SecuritySystem(bool secured);
    void displayInfo() const override;
};

class MKS {
private:
    std::vector<SpaceControl*> modules;
public:
    void addModule(SpaceControl* module);
    void displayInfo() const;
    ~MKS();
};

#endif // SPACECONTROL_H