from decimal import *

input()
total_value = 0
legal_cnt = 0
for case in input().split():
    try:
        value = Decimal(case)
    except:
        value = 10000
    if value < -1000 or value > 1000 or value % Decimal('0.01'):
        print('ERROR: {} is not a legal number'.format(case))
    else:
        total_value += value
        legal_cnt += 1
if legal_cnt == 1:
    print('The average of 1 number is {:.2f}'.format(total_value))
elif legal_cnt > 1:
    print('The average of {} numbers is {:.2f}'.format(legal_cnt, total_value / legal_cnt))
else:
    print('The average of 0 numbers is Undefined')
