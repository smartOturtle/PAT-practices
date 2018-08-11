from collections import namedtuple

Student = namedtuple('Student', 'name ID grade')
student_size = int(input())
students = [[], []]
for i in range(student_size):
    name, gender, ID, grade = input().split()
    students[0 if gender == 'M' else 1].append(Student(name, ID, int(grade)))
if students[1]:
    highest_female = max(students[1], key=lambda s: s.grade)
    print(highest_female.name, highest_female.ID)
else:
    print('Absent')
if students[0]:
    lowest_male = min(students[0], key=lambda s: s.grade)
    print(lowest_male.name, lowest_male.ID)
else:
    print('Absent')
if students[0] and students[1]:
    print(highest_female.grade - lowest_male.grade)
else:
    print('NA')
