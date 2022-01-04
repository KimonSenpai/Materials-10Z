
def f(a, b):
    return a + b

def g(a: float, b: float)->float:
    return a * b

def g(a: str, b: str):
    return a + b
print(g('a', 'b'))
print(g(2.0, 3.0))

h = lambda a, b: a + b

m = {}
def F(n):
    if n < 2:
        return n
    if n in m:
        return m[n]
    m[n] = F(n - 1) + F(n - 2)
    return m[n]


from functools import lru_cache

@lru_cache(None)
def FF(n):
    if n < 2:
        return n
    return F(n - 1) + F(n - 2)
    

def cache(f):
    m = {}
    def g(*args):
        nonlocal m
        if args in m:
            return m[args]
        m[args] = f(*args)
        return m[args]
    return g


@cache
def FFF(n):
    if n < 2:
        return n
    return F(n - 1) + F(n - 2)



print(FFF(20))