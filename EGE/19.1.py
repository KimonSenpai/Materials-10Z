# +1
# *2
# (7, S)
# 1 <= S <= 69
# win >= 77
from functools import lru_cache
def pos(x):
    return x > 0
def neg(x):
    return x <= 0

def go(a, b):
    return [solve(a + 1, b), solve(a, b + 1), solve(a*2, b), solve(a, b*2)]

@lru_cache(None)
def solve(a, b):
    if a + b >= 77:
        return 0

    res = go(a, b)

    if 0 in res:
        return +1

    if all(map(pos, res)) and max(res) == +1:
        return -1

    if any(map(neg, res)) and max(filter(neg, res)) == -1:
        return +2
    return None

#for s in range(70, 0, -1):
#    if +1 in go(7, s):
#        print(s)
for s in range(70, 0, -1):
    if solve(7, s) == +2:
        print(s)