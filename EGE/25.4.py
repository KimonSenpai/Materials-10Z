def S(n):
    divs = []
    div = 2
    while div*div <= n:
        if n%div == 0:
            divs += [div]
            if div != n//div:
                divs += [n//div]
        if len(divs) >= 5:
            break
        div += 1
    divs.sort(reverse=True)
    return sum(divs[:3]) if len(divs) >= 3 else 0

cnt = 0
val = 10_000_001
while cnt < 5:
    s = S(val)

    if s > 0 and int(s**0.5)**2 == s:
        print(s)
        cnt += 1
    val += 1
