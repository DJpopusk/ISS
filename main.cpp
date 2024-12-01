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

class Unmanned : public Laboratories {
    // Unmanned laboratories
};

class Manipulators : public Laboratories {
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
