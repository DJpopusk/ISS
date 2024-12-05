#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <curl/curl.h> // Библиотека для HTTP-запросов
#include <nlohmann/json.hpp> // Библиотека для работы с JSON

using json = nlohmann::json;

// --- Базовый класс для компонентов МКС ---
class Module {
protected:
    std::string name;

public:
    explicit Module(const std::string& name) : name(name) {}
    virtual ~Module() = default;

    virtual void displayInfo() const {
        std::cout << "Module: " << name << std::endl;
    }

    virtual void performOperation() const = 0;
};

// --- Энергия ---
class Energy : public Module {
public:
    explicit Energy(const std::string& name) : Module(name) {}

    void performOperation() const override {
        std::cout << name << ": Generating and managing energy.\n";
    }
};

// --- Солнечные панели ---
class SolarPanels : public Energy {
private:
    static constexpr int panelCount = 10; // Количество панелей
    double panelAngles[panelCount];       // Текущие углы панелей

public:
    SolarPanels() : Energy("Solar Panels") {
        for (int i = 0; i < panelCount; ++i) {
            panelAngles[i] = 0.0; // Изначально все панели на нуле градусов
        }
    }

    void performOperation() const override {
        std::cout << name << ": Optimizing angles for maximum sunlight absorption.\n";
    }

    void calculateOptimalAngles(double sunAzimuth, double sunAltitude) {
        // Рассчитываем угол поворота каждой панели
        for (int i = 0; i < panelCount; ++i) {
            panelAngles[i] = sunAzimuth; // Упрощенная модель
            std::cout << "Panel " << i + 1 << ": Adjusted to angle " << panelAngles[i] << " degrees.\n";
        }
    }

    static json fetchISSPosition() {
        // Используем curl для получения данных о позиции МКС
        CURL* curl;
        CURLcode res;
        std::string responseString;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "http://api.open-notify.org/iss-now.json");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
                             [](void* contents, size_t size, size_t nmemb, void* userp) -> size_t {
                                 ((std::string*)userp)->append((char*)contents, size * nmemb);
                                 return size * nmemb;
                             });
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if (res != CURLE_OK) {
                throw std::runtime_error("Failed to fetch ISS position.");
            }
        }

        return json::parse(responseString);
    }

    void updatePanelAngles() {
        try {
            json positionData = fetchISSPosition();
            double latitude = std::stod(positionData["iss_position"]["latitude"].get<std::string>());
            double longitude = std::stod(positionData["iss_position"]["longitude"].get<std::string>());

            std::cout << "Current ISS Position - Latitude: " << latitude
                      << ", Longitude: " << longitude << std::endl;

            // Для демонстрации рассчитаем угол солнца как фиксированное значение
            // В реальной системе используем астрофизические данные
            double sunAzimuth = 180.0;  // Азимут солнца
            double sunAltitude = 45.0; // Высота солнца над горизонтом

            calculateOptimalAngles(sunAzimuth, sunAltitude);

        } catch (const std::exception& e) {
            std::cerr << "Error updating solar panel angles: " << e.what() << std::endl;
        }
    }
};

// --- Основной класс для управления МКС ---
class ISS {
private:
    std::vector<Module*> modules;

public:
    ~ISS() {
        for (auto module : modules) {
            delete module;
        }
    }

    void addModule(Module* module) {
        modules.push_back(module);
    }

    void displayModules() const {
        std::cout << "Modules of the ISS:" << std::endl;
        for (const auto& module : modules) {
            module->displayInfo();
            module->performOperation();
        }
    }

    void updateSolarPanels() {
        for (const auto& module : modules) {
            SolarPanels* solarPanels = dynamic_cast<SolarPanels*>(module);
            if (solarPanels) {
                solarPanels->updatePanelAngles();
            }
        }
    }
};

int main() {
    ISS iss;

    // Добавляем солнечные панели
    SolarPanels* solarPanels = new SolarPanels();
    iss.addModule(solarPanels);

    // Отображаем информацию о модулях
    iss.displayModules();

    // Обновляем углы панелей
    std::cout << "\nUpdating solar panel angles based on ISS position...\n";
    iss.updateSolarPanels();

    return 0;
}