#problem 1158 kompege


from functools import lru_cache

def go(a, b):
    mas = []
    if a == 0 or b == 0:
        return mas
    if a >= 3 and b >= 3:
        mas += [solve(a - 3, b - 3)]
    if a % 2 == 0:
        mas += [solve(a//2, a//2)]
    if b % 2 == 0:
        mas += [solve(b//2, b//2)]
    return mas

@lru_cache(None)
def solve(a, b):

    mas = go(a, b)
    if len(mas) == 0:
        return -0
    if all(val > 0 for val in mas):
        return -max(mas)
    else:
        return -max(val for val in mas if val <= 0) + 1

print('problem 19')
for k in range(90):
    if +1 in go(32, k):
        print(k)
print('problem 20')
for k in range(90):
    if solve(32, k) == +2:
        print(k)

print('problem 21')
for k in range(90):
    if solve(20, k) == -2:
        print(k)