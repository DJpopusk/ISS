import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

# Функция для преобразования широты и долготы в декартовы координаты
def lat_lon_to_cartesian(lat, lon, altitude):
    # Преобразуем углы в радианы
    lat_rad = np.radians(lat)
    lon_rad = np.radians(lon)

    # Радиус Земли + высота орбиты (если высота дана в километрах)
    R = 6371 + altitude

    x = R * np.cos(lat_rad) * np.cos(lon_rad)
    y = R * np.cos(lat_rad) * np.sin(lon_rad)
    z = R * np.sin(lat_rad)

    return x, y, z

# Чтение данных из файла
coordinates = []
with open('coordinates1.txt', 'r') as file:
    for line in file:
        parts = line.strip().split(',')
        lat = float(parts[0])
        if parts[1] == 'S':
            lat = -lat
        lon = float(parts[2])
        if parts[3] == 'W':
            lon = -lon
        altitude = float(parts[4])
        coordinates.append((lat, lon, altitude))

# Преобразование в декартовы координаты
x_coords = []
y_coords = []
z_coords = []

for lat, lon, alt in coordinates:
    x, y, z = lat_lon_to_cartesian(lat, lon, alt)
    x_coords.append(x)
    y_coords.append(y)
    z_coords.append(z)

# Построение графика
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.plot(x_coords, y_coords, z_coords, marker='o')

ax.set_xlabel('X (км)')
ax.set_ylabel('Y (км)')
ax.set_zlabel('Z (км)')

plt.title('Орбита спутника')
plt.show()