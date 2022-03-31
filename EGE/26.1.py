
f = open("D:\\Downloads\\26 (2).txt")

n, m = (int(v) for v in f.readline().split())

mas = [int(line) for line in f]

mas.sort(reverse=True)

sv_count = obr = 0

while sum(mas) >= m:
    mm = m
    cnt = 0
    while mas[0] < mm:
        mm -= mas[0]
        cnt += 1
        mas.pop(0)

    for i in range(len(mas)):
        if i == len(mas) - 1 or mas[i+1] < mm:
            cnt += 1
            if mas[i] - mm > 0:
                obr += mas[i] - mm
                mas += [mas[i] - mm]
            mas.pop(i)
            break
    sv_count += cnt - 1
    mas.sort(reverse=True)

print(sv_count, obr)