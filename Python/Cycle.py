
x = 657
c = 0
while x > 0:
    c += 1
    x //= 10
print(c, '\n')

s = [1, 2, 4]
for k in s:
    print(k)
print()
for i in range(6):
    print(i)
print()
for i in range(1, 7):
    print(i)
print()
for i in range(2, 7, 2):
    print(i)

print('\n', -7%3, -7//3)
# -7 = -3*3 + 2
# (a + b)%b = a%b