num_size=int(input())
for i in range(num_size):
    a,b,c=map(int,input().split())
    print('Case #{}:'.format(i+1),'true' if a+b>c else 'false')
