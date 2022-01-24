
def Range(n):
    k = 0
    while k < n:
        yield k
        k += 1

print(Range(5))

for i in Range(5):
    print(i, end='\t')
print()

with open('Func.py', 'r') as f:
    for line in f:
        print(line)