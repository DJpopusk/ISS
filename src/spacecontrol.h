#ifndef SPACECONTROL_H
#define SPACECONTROL_H

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <filesystem>

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
private:
    double thrust;
    std::vector<std::pair<double, double>> thrustData;
    std::vector<std::pair<double, double>> coordinates;

public:
    Propulsion();
    Propulsion(double thrustValue);
    void calculateThrust(std::vector<std::pair<double, double>> coordinates); // исправлены параметры
    void recordData(const std::string &filename) const;
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