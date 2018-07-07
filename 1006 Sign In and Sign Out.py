from collections import *

Record = namedtuple('Record', 'id check_in check_out')


def convert(s):
    sections = s.split(':')
    return (int(sections[0]) * 60 + int(sections[1])) * 60 + int(sections[2])


def input_record():
    row_data = input().split(' ')
    return Record(row_data[0], convert(row_data[1]), convert(row_data[2]))


length = int(input())
records = []
for i in range(length):
    records.append(input_record())
print(min(records, key=lambda r: r.check_in).id, max(records, key=lambda r: r.check_out).id)
