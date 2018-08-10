from collections import namedtuple
from itertools import *

Station = namedtuple('Station', 'unit_price position')
tank_capacity, distance, unit_distance, station_size = map(int, input().split())
via_stations = []
for i in range(station_size):
    via_stations.append(Station(*map(float, input().split())))
via_stations.append(Station(0, distance))
via_stations.sort(key=lambda s: s.position)
cost = 0
gas_cnt = 0
current_pos = 0
for i, (unit_price, position) in enumerate(via_stations):
    can_reach_farthest = current_pos + gas_cnt * unit_distance
    if can_reach_farthest < position or can_reach_farthest >= distance:
        break
    gas_cnt -= (position - current_pos) / unit_distance
    current_pos = position
    station = via_stations[i]
    for s in takewhile(lambda s: tank_capacity * unit_distance + current_pos >= s.position,
                       islice(via_stations, i + 1, None)):
        if unit_price >= s.unit_price:
            station = s
            break
    previous_cnt = gas_cnt
    if unit_price > station.unit_price:
        if can_reach_farthest < station.position:
            gas_cnt = min(tank_capacity, (station.position - current_pos) / unit_distance)
    else:
        gas_cnt = tank_capacity
    cost += (gas_cnt - previous_cnt) * unit_price
if current_pos + gas_cnt * unit_distance < distance:
    print('The maximum travel distance = {:.2f}'.format(current_pos + gas_cnt * unit_distance))
else:
    print('{:.2f}'.format(cost))
