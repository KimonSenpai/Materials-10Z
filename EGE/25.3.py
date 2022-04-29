# 506 kompege


for val in range(25317, 51237 + 1):
    v = val

    div = 2
    cnt = 0
    mx = 0

    while div*div <= v:
        if v % div == 0:
            cnt += 1
            mx = div
            while v%div == 0: v //= div
        div += 1
    if v != 1:
        cnt += 1
        mx = v

    if cnt >= 6:
        print(val, mx)