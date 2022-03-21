f = open("27.txt", 'r')

n = int(f.readline())
mas = [0]*140

for line in f:
    val = int(line)

    mas[val%140] += 1

res = 0
for i in range(1, 70):
    res += mas[i]*mas[140 - i]

res += mas[0]*(mas[0]-1)//2 + mas[70]*(mas[70] - 1)//2