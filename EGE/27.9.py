for path in ('27A (5).txt', '27B (5).txt'):
    with open(path) as f:
        n = f.readline()

        cur_pref = 1
        res = 0
        prefs = [0]*11
        cur_mod = 0
        for line in f:
            val = int(line)

            if val % 5 == 0:
                prefs[cur_mod] += cur_pref
                cur_pref = 1
                cur_mod = (cur_mod + 1)%11
                res += prefs[cur_mod]
            else:
                res += prefs[cur_mod]
                cur_pref += 1
        print(res, end=' ')
print()