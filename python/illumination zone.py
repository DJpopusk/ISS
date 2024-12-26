import numpy as np
from astropy.time import Time
from astropy.coordinates import solar_system_ephemeris, get_sun, EarthLocation, AltAz
from astropy import units as u

def is_in_earth_shadow(lat, lon, alt):
    time = Time.now()

    location = EarthLocation(lat=lat*u.deg, lon=lon*u.deg, height=alt*u.km)

    with solar_system_ephemeris.set('builtin'):
        sun = get_sun(time).transform_to(AltAz(obstime=time, location=location))

    return sun.alt < 0

def process_line(line):
    parts = line.strip().split(',')
    if len(parts) != 5:
        return None

    lat = float(parts[0])
    lat_dir = parts[1]
    lon = float(parts[2])
    lon_dir = parts[3]
    alt = float(parts[4])

    if lat_dir == 'S':
        lat = -lat
    if lon_dir == 'W':
        lon = -lon

    return lat, lon, alt

with open('coordinates1.txt', 'r') as file:
    for line in file:
        coordinates = process_line(line)
        if coordinates:
            lat, lon, alt = coordinates
            in_shadow = is_in_earth_shadow(lat, lon, alt)
            print(f'ISS at lat={lat}, lon={lon}, alt={alt} is {"in shadow" if in_shadow else "in sunlight"}')