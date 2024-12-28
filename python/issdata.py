import time
import os
from skyfield.api import Topos, load

stations_url = 'http://celestrak.com/NORAD/elements/stations.txt'
satellites = load.tle_file(stations_url)
by_name = {sat.name: sat for sat in satellites}

satellite = by_name['ISS (ZARYA)']


with open('coordinates1.txt', 'w') as f:
    pass

while True:
    ts = load.timescale()
    t = ts.now()

    geocentric = satellite.at(t)
    subpoint = geocentric.subpoint()

    latitude_deg = subpoint.latitude.degrees
    longitude_deg = subpoint.longitude.degrees
    elevation_km = subpoint.elevation.km

    lat_direction = 'N' if latitude_deg >= 0 else 'S'
    lon_direction = 'E' if longitude_deg >= 0 else 'W'

    coordinates = f"{abs(latitude_deg)},{lat_direction},{abs(longitude_deg)},{lon_direction},{elevation_km}\n"

    with open('coordinates1.txt', 'a') as f:
        f.write(coordinates)

    # Ждем 10 секунд перед повторением
    time.sleep(10)