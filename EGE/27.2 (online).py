f = open("27.txt", 'r')

n = int(f.readline())
n26 = n13 = n2 = n1 = 0
l = r = 0
for line in f:
    val = int(line)
    if val % 26 == 0:
        m = max(n1, n2, n13, n26)
        if val * m > l*r:
            l = m
            r = val
        n26 = max(n26, val)
    elif val % 13 == 0:
        m = max(n2, n26)
        if val * m > l*r:
            l = m
            r = val
        n13 = max(n13, val)
    elif val % 2 == 0:
        m = max(n13, n26)
        if val * m > l*r:
            l = m
            r = val
        n2 = max(n2, val)

    else:
        m = n26
        if val * m > l*r:
            l = m
            r = val
        n1 = max(n1, val)

print(l, r)