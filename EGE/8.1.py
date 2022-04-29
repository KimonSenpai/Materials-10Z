# problem 2517 kompege


from itertools import product


variants = list(''.join(v) for v in product('0123456789', repeat=6))


def check(s):
    if '34' in s:
        return False
    if '0' not in s:
        return False
    for i in range(5):
        if int(s[i])%2 == int(s[i + 1])%2:
            return False

    return True
# print(variants[:10])

count = 0
for s in variants:
    count += check(s)


print(count)


class MyInt:
    def __init__(self):
        self.__val = 0

    def __init__(self, val):
        self.__val = val

help(str)