# problem 1886 kompege

val = 39345679
cnt = 0
res = []
while cnt < 10:
    val -= 1
    div = 2
    div_cnt = 0
    if not all(val%d == 0 for d in (2, 3, 5, 7)):
        continue
    while div*div <= val and div_cnt <= 88:
        if val % div == 0:
            div_cnt += 1
            if div != val//div:
                div_cnt += 1
        div += 1

    if 76 <= div_cnt <= 88:
        print(val, div_cnt)
        cnt += 1