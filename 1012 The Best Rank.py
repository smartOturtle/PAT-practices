student_size, query_size = [int(i) for i in input().split(' ')]
students = {}
for i in range(student_size):
    student = [int(value) for value in input().split(' ')]
    students[student[0]] = [sum(student[1:]) / 3]
    students[student[0]].extend(student[1:])
for i in range(4):
    previous_score = -1
    rank = 1
    same_score = 0
    for item in sorted(students.items(), key=lambda s: s[1][i], reverse=True):
        if item[1][i] != previous_score:
            rank += same_score
            same_score = 1
            previous_score = item[1][i]
        else:
            same_score += 1
        students[item[0]][i] = rank
for i in range(query_size):
    student_id = int(input())
    if student_id in students:
        print(*min(zip(students[student_id], 'ACME'), key=lambda t: t[0]))
    else:
        print('N/A')
