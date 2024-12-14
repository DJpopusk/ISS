#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

// Абстрактный базовый класс для всех объектов на мкс
class SpaceControl {
public:
    virtual ~SpaceControl() {}

    // Чисто виртуальная функция для отображения информации
    virtual void displayInfo() const = 0;
};

// Класс для управления жизнью
class LifeSupport : public SpaceControl {
private:
    double oxygenLevel;
    double co2Level;

public:
    LifeSupport(double o2, double co2) : oxygenLevel(o2), co2Level(co2) {}

    void displayInfo() const override {
        std::cout << "Life Support: Oxygen level: " << oxygenLevel
                  << ", CO2 level: " << co2Level << std::endl;
    }
};

// Класс для управления энергетическими системами
class PowerSystem : public SpaceControl {
private:
    double energyOutput;

public:
    PowerSystem(double output) : energyOutput(output) {}

    void displayInfo() const override {
        std::cout << "Power System: Energy Output: " << energyOutput << " kW" << std::endl;
    }
};

// Класс для управления движением
class Propulsion : public SpaceControl {
private:
    double thrust;

public:
    Propulsion(double thrustValue) : thrust(thrustValue) {}

    void displayInfo() const override {
        std::cout << "Propulsion: Thrust: " << thrust << " N" << std::endl;
    }
};

// Класс для лаборатории
class Laboratory : public SpaceControl {
private:
    std::string experiments;
    int personnelCount;

public:
    Laboratory(const std::string& exp, int count) : experiments(exp), personnelCount(count) {}

    void displayInfo() const override {
        std::cout << "Laboratory: Ongoing Experiments: " << experiments
                  << ", Personnel Count: " << personnelCount << std::endl;
    }
};

// Класс для жилых помещений
class LivingQuarters : public SpaceControl {
private:
    int capacity;
    int occupied;

public:
    LivingQuarters(int cap, int occ) : capacity(cap), occupied(occ) {}

    void displayInfo() const override {
        std::cout << "Living Quarters: Capacity: " << capacity
                  << ", Occupied: " << occupied << std::endl;
    }
};

// Класс для манипуляторов
class Manipulator : public SpaceControl {
private:
    int dexterityLevel;

public:
    Manipulator(int level) : dexterityLevel(level) {}

    void displayInfo() const override {
        std::cout << "Manipulator: Dexterity Level: " << dexterityLevel << std::endl;
    }
};

// Класс для систем безопасности
class SecuritySystem : public SpaceControl {
private:
    bool isSecured;

public:
    SecuritySystem(bool secured) : isSecured(secured) {}

    void displayInfo() const override {
        std::cout << "Security System: Secured: " << (isSecured ? "Yes" : "No") << std::endl;
    }
};

// Основной класс MKS, который агрегирует все системы
class MKS : public SpaceControl {
private:
    std::vector<SpaceControl*> modules; // Хранит указатели на модули

public:
    void addModule(SpaceControl* module) {
        modules.push_back(module);
    }

    void displayInfo() const override {
        std::cout << "MKS Modules Information:" << std::endl;
        for (const auto& module : modules) {
            module->displayInfo(); // Вывод информации о каждом модуле
        }
    }

    ~MKS() {
        for (auto module : modules) {
            delete module; // Освобождаем память
        }
    }
};

int main() {
    MKS mks;

    // Добавляем модули в MKS
    mks.addModule(new LifeSupport(21.0, 0.03)); // Уровень кислорода, уровень CO2
    mks.addModule(new PowerSystem(150.0));        // Энергия
    mks.addModule(new Propulsion(5000.0));        // Тяга
    mks.addModule(new Laboratory("Biology Experiment", 5)); // Лаборатория
    mks.addModule(new LivingQuarters(10, 3));     // Жилые помещения
    mks.addModule(new Manipulator(8));             // Манипулятор
    mks.addModule(new SecuritySystem(true));       // Система безопасности

    // Отображаем информацию
    mks.displayInfo();

    return 0;
}