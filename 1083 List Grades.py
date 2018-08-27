size = int(input())
grade_buckets = [[] for i in range(101)]
for i in range(size):
    name, ID, grade = input().split()
    grade_buckets[int(grade)].append((name, ID))
has_output = False
low, up = map(int, input().split())
for i in range(up, low - 1, -1):
    if grade_buckets[i]:
        print(*grade_buckets[i][0])
        has_output = True
if not has_output:
    print('NONE')
