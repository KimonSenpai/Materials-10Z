f = open("27.txt", 'r')

n = int(f.readline())
mas = [0]*140
res = 0
for line in f:
    val = int(line)

    res += mas[-val%140]

    mas[val%140] += 1

print(res)