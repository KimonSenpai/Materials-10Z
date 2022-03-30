from functools import lru_cache
def pos(x):
    return x is not None and x > 0
def neg(x):
    return x is not None and x <= 0

def go(a, b):
    return [solve(a + 1, b), solve(a, b + 1), solve(a*2, b), solve(a, b*2)]

@lru_cache(None)
def solve(a, b):
    if a + b >= 77:
        return 0

    res = go(a, b)

    if all(map(pos, res)):
        return -max(res)
    else:
        return -max(filter(neg, res)) + 1

for s in range(70, 0, -1):
    if +1 in go(7, s):
        print(s)
print("----------------------------------")
for s in range(70, 0, -1):
    if solve(7, s) == +2:
        print(s)
print("----------------------------------")
for s in range(70, 0, -1):
    if solve(7, s) == -2:
        print(s)