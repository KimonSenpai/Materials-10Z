f = open("D:\\Downloads\\26 (6).txt")

V, n = (int(v) for v in f.readline().split())

mas_a = []
mas_b = []
for line in f:
    a, b = line.split()
    if b == 'A':
        mas_a += [int(a)]
    else:
        mas_b += [int(a)]
mas_a.sort()
mas_b.sort()
# mas.sort(key=lambda x: (x[1], x[0]))
move_count = b_count = 0
while len(mas_a) != 0:
    vv = V
    move_count += 1
    while len(mas_a) != 0 and mas_a[0] <= vv:
        vv -= mas_a[0]
        mas_a.pop(0)
    last = 0
    while len(mas_b) != 0 and mas_b[0] <= vv:
        vv -= mas_b[0]
        b_count += 1
        last = mas_b[0]
        mas_b.pop(0)

    if vv == 0: continue

    vv += last
    mas_b.insert(0, last)

    for i in range(len(mas_b)):
        if i == len(mas_b) - 1 or mas_b[i+1] > vv:
            mas_b.pop(i)
            break

print(move_count, b_count)