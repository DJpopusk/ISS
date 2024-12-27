from skyfield.api import Topos, load

# Загрузите TLE данные
stations_url = 'http://celestrak.com/NORAD/elements/stations.txt'
satellites = load.tle_file(stations_url)
by_name = {sat.name: sat for sat in satellites}

# Получите объект спутника МКС
satellite = by_name['ISS (ZARYA)']

# Вычислите местоположение на текущий момент
ts = load.timescale()
t = ts.now()

# Получите положение МКС в надирной системе координат
geocentric = satellite.at(t)
subpoint = geocentric.subpoint()
print('Широта:', subpoint.latitude.degrees)
print('Долгота:', subpoint.longitude.degrees)
print('Высота (км):', subpoint.elevation.km)