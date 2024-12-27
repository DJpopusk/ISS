#ifndef SPACECONTROL_H
#define SPACECONTROL_H

#include <vector>
#include <string>
#include <iostream>
#include <exception>

using namespace std;

class AllError : public exception {
public:
    enum ErrorType {
        FILE_NOT_FOUND,
        INVALID_INPUT
    };

private:
    ErrorType type;
    string message;

public:
    AllError (ErrorType type, const string& new_message) : type(type), message(new_message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    ErrorType getType() const {
        return type;
    }

};

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

    bool isPositionSunny(double latitude, double longitude, double altitude);

public:
    PowerSystem(double output);
    void displayInfo() const override;

    void determineSunlightExposure(const string& filePath);
};

class Propulsion : public SpaceControl {
public:
    struct Position {
        double latitude;
        char latDirection;
        double longitude;
        char longDirection;
        double altitude;

        Position(double lat, char latDir, double lon, char longDir, double alt)
            : latitude(lat), latDirection(latDir), longitude(lon), longDirection(longDir), altitude(alt) {}
    };

    vector<Position> positions;
    double deltaTime;
    Propulsion(const vector<Position>& pos, double dT);
    double calculateSpeed() const;
    void displayInfo() const override;
};

class Laboratory : public SpaceControl {
private:
    string experiments;
    int personnelCount;
public:
    Laboratory(const string& exp, int count);
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
    vector<SpaceControl*> modules;
public:
    void addModule(SpaceControl* module);
    void displayInfo() const;
    ~MKS();
};

#endif // SPACECONTROL_H