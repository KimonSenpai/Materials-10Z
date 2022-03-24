#  Даны тройки чисел. Разбить каждую тройку на три суммы так, чтобы в конце одна 
# была четной, чторая нечетной, а третья минимальной. Вывести минимальную.

f = open("27.txt", 'r')

n = int(f.readline())

s1 = s2 = s3 = 0
dif = 10000000001
for line in f:
    vals = list(sorted(map(int, line.split())))

    s1 += vals[0]
    s2 += vals[1]
    s3 += vals[2]

    for i, j in ((1, 0), (2, 0)):
        if (vals[i] - vals[j])%2 == 1:
            dif = min(dif, vals[i] - vals[j])


if s2%2 == s3%2:
    s1 += dif

print(s1)