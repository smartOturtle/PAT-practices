pronunciations = {0: 'zero', 1: 'one', 2: 'two', 3: 'three', 4: 'four', 
                  5: 'five',6: 'six', 7: 'seven', 8: 'eight',9: 'nine'}
print(*(pronunciations[int(i)] for i in str(sum(int(i) for i in input()))))
