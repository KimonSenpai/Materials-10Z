f = open("27.txt", 'r')

n = int(f.readline())

maxVal = maxSum = 0
mas = [0]*5
for i in range(5):
    mas[i] = int(f.readline())

for i in range(5, n):
    val = int(f.readline())

    maxVal = max(maxVal, mas[i%5])

    maxSum = max(maxSum, maxVal + val)

    mas[i%5] = val


print(maxSum)