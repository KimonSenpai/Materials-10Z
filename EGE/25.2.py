# problem 2407 kompege

val = 1000893530
step = 1031849
val_cnt = 0
while val <= 2000000000:
    if val % 3 == 0 or val % 5 == 0:
        val += step
        continue

    div = 1
    cnt = 0

    while div*div <= val:
        if val % div == 0:
            if div % 2 == 1: cnt += 1
            if val//div != div:
                if val // div % 2 == 1: cnt += 1
        div += 1
    if cnt > 100: val_cnt += 1
    val += step

print(val_cnt)
    