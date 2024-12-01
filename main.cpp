#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <cmath>
#include <chrono>
 // Base libraries

class MKS {
    // Base class
};

class ControlledbyPeople : public MKS {
    // Blocks managing by people
};

class NeutralRooms : public ControlledbyPeople {
    // Neutral rooms
};

class LivingQuarters : public ControlledbyPeople {
    // Living quarters
};

class Laboratories : public ControlledbyPeople {
    // Laboratories
};

class Corridors : public NeutralRooms {
    // Corridors
};

class DockingChambers : public NeutralRooms {
    // Docking chambers
};

class Cafeterias : public LivingQuarters {
    // Cafeterias
};

class PersonalHygieneRooms : public LivingQuarters {
    // Personal hygiene rooms
};

class Gym : public LivingQuarters {
    // Gym
};

class Zerogravity : public Laboratories {
    // Zero gravity based exp laboratories
};

class Gravity : public Laboratories {
    // Gravity based exp laboratories
};

class Manipulators : public ControlledbyPeople {
    // Manipulators
};

class AutomatedSystems : public MKS {
    // Automated systems
};

class LifeSupport : public AutomatedSystems {
    // Life support systems
};

class Energy : public AutomatedSystems {
    // Energy systems
};

class SecuritySystems : public AutomatedSystems {
    // Security systems
};

class Ventilation : public LifeSupport {
    // Ventilation
};

class WaterFilters : public LifeSupport {
    // Water filters
};

class SolarPanels : public Energy {
    // Solar panels
};

class Accumulators : public Energy {
    // Accumulators
};

class FireSafetyDevices : public SecuritySystems {
    // Fire safety devices
};

class Decompression : public SecuritySystems {
    // Decompression
};
