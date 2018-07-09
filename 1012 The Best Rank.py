student_size, query_size = [int(i) for i in input().split(' ')]
students = {}
for i in range(student_size):
    student = [int(value) for value in input().split(' ')]
    students[student[0]] = student[1:]
    students[student[0]].append(sum(iter(student[1:])) / 3)
for i in range(4):
    previous_score = -1
    rank = 0
    same_score = 1
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
        rank, subject = min(zip(students[student_id], '1230'))
        print(rank, 'ACME'[int(subject)])
    else:
        print('N/A')
