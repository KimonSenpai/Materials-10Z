from functools import lru_cache

def go(a, b):
    res = []
    if a > 0:
        res += [solve(a - 1, b)]
    if b > 0:
        res += [solve(a, b - 1)]
    if a > 1:
        res += [solve(a - a//2, b)]
    if b > 1:
        res += [solve(a, b - b//2)]
    return res

    
@lru_cache(None)
def solve(a, b):
    if a+b <= 32:
        return -0

    res = go(a, b)

    if all(i > 0 for i in res):
        return -max(res)
    else:
        return -max(i for i in res if i <= 0) + 1

print('problem 19')
for s in range(23, 100):
    if solve(10, s) == -1:
        print(s)

print('problem 20')
for s in range(23, 100):
    if solve(10, s) == +2:
        print(s)

print('problem 21')
for s in range(23, 100):
    if solve(10, s) == -2:
        print(s)