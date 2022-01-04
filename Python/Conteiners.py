
l = [1, 2, 3]
ll = list()

t = (1, 2, 3)
tt = tuple()

l = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

#def pack(x):
#    return (x%2, x)
l.sort(key=lambda x: (x%2, x))
print(*l)

#if key(mas[i]) < key(mas[j])

s = set()
ss = {1, 2, 3}
print(2 in ss)

d = {'a': 2, 'ab': 3, 'c': 0}
dd = dict()
print(d['a'])
print('d' in d)
if 'k' not in d:
    d['k'] = 0

d['l'] += 1