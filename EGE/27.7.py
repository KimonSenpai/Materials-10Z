# Последовательность чисел. Нужно найти максимальную сумму подпоследовательности
# идущих подряд элементов, кратную 7. Числа последовательности натуральны.
# n ~ 10^8


f = open("27.txt", 'r')

n = int(f.readline())
pref = 0
max_sum = 0
prefs = [0] + [1**7]*6
for line in f:
    val = int(line)
    pref += val

    max_sum = max(max_sum, pref - prefs[pref%7])

    prefs[pref%7] = min(prefs[pref%7], pref)

print(max_sum)
