#include <iostream>
#include <vector>
#include <utility>
#include "spacecontrol.h"

int main() {
    // Создаем объект Propulsion с начальным значением тяги
    Propulsion propulsionSystem(10.0);

    // Задаем несколько координат кучек объектов
    std::vector<std::pair<double, double>> coordinates = {
        {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}
    };

    // Рассчитываем тягу на основании координат
    propulsionSystem.calculateThrust(coordinates);

    // Выводим информацию о системе
    propulsionSystem.displayInfo();

    // Записываем данные в файл
    std::string filename = "output/thrust_data.txt";
    propulsionSystem.recordData(filename);
    std::cout << "Thrust data recorded in file: " << filename << std::endl;

    return 0;
}
