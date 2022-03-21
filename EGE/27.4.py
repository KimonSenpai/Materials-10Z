f = open("27.txt", 'r')

n = int(f.readline())
minDif = s = 0

for line in f:
    a, b = map(int, line.split())
    if a > b: a, b = b, a

    s += b
    if (b-a)%8 != 0:
        minDif = min(minDif, b-a)

if s % 8 == 0:
    s -= minDif

print(s)