for i in range(int(input())):
    num = input()
    half_len=len(num)//2
    try:
        if int(num) % (int(num[:half_len]) * int(num[half_len:])) == 0:
            print('Yes')
        else:
            print('No')
    except:
        print('No')
