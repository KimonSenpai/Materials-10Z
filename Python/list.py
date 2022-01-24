l = [1, 2, 4, 5.6, "as", True]

print(*l, sep='--')

l += [2, 3, 7]

print(l)

ll = [2, 3]*5

print(ll)

matr = [[1, 2, 3] for i in range(3)]
print(matr)

matr[0][2] = 0
print(matr)