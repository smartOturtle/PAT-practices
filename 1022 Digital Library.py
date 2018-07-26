from collections import defaultdict

book_size = int(input())
book_title_dict = defaultdict(list)
author_dict = defaultdict(list)
key_word_dict = defaultdict(list)
publisher_dict = defaultdict(list)
year_dict = defaultdict(list)
for i in range(book_size):
    book_id = input()
    book_title = input()
    book_title_dict[book_title].append(book_id)
    author = input()
    author_dict[author].append(book_id)
    key_words = input().split()
    for key_word in key_words:
        key_word_dict[key_word].append(book_id)
    publisher = input()
    publisher_dict[publisher].append(book_id)
    year = input()
    year_dict[year].append(book_id)
query_table = {'1': book_title_dict, '2': author_dict, '3': key_word_dict, '4': publisher_dict, '5': year_dict}
for kind_dict in query_table.values():
    for inside in kind_dict.values():
        inside.sort()
query_size = int(input())
for i in range(query_size):
    query = input()
    print(query)
    query_type, content = query.split(': ')
    if content in query_table[query_type]:
        for book_id in query_table[query_type][content]:
            print(book_id)
    else:
        print('Not Found')
