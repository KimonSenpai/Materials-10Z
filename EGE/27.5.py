# Даются тройки чисел. 
# Из каждой нужно выбрать 2 числа так, чтобы их 
# общая сумма делилась на 4 и была максимальной.
# Все числа целые неотрицательные

f = open("27.txt", 'r')

n = int(f.readline())
sums = [0] + [-1]*3

for line in f:
    vals = list(map(int, line.split()))
    new_sums = [-1]*4
    for k in range(4):
        if sums[k] == -1: continue

        for i,j in ((0, 1), (0, 2), (1, 2)):
            s = vals[i] + vals[j]
            new_sums[(k + s)%4] = max(new_sums[(k + s)%4], sums[k] + s)


    sums = new_sums

print(sums[0])