repeat_times = int(input())
shuffling_order = list(map(lambda i: int(i) - 1, input().split()))
card_deck = [i for i in range(54)]
temp = [i for i in range(54)]
for i in range(repeat_times):
    for previous, ought_to in enumerate(shuffling_order):
        temp[ought_to] = card_deck[previous]
    card_deck, temp = temp, card_deck
color = 'SHCDJ'
print(*(color[card // 13] + str(card % 13+1) for card in card_deck))
