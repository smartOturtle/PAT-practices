from functools import *
from collections import defaultdict

student_size, query_size = [int(i) for i in input().split(' ')]
students = {}
for i in range(student_size):
    student_id, *scores = (int(value) for value in input().split(' '))
    students[student_id] = [sum(scores) / 3]
    students[student_id].extend(scores)


def build_rank(rank, score_group, course_id):
    global students
    for student_id in score_group[1]:
        students[student_id][course_id] = rank
    return rank + len(score_group[1])


for i in range(4):
    score_groups = defaultdict(list)
    for student_id, scores in students.items():
        score_groups[scores[i]].append(student_id)
    reduce(partial(build_rank, course_id=i), sorted(score_groups.items(), reverse=True), 1)
for i in range(query_size):
    student_id = int(input())
    if student_id in students:
        print(*min(zip(students[student_id], 'ACME'), key=lambda t: t[0]))
    else:
        print('N/A')
