# В текстовом файле записан набор пар натуральных чисел, не превышающих 10 000. 
# Необходимо выбрать из набора некоторые пары так, чтобы второе число в каждой 
# выбранной паре было нечётным, сумма бо́льших чисел во всех выбранных парах была 
# чётной, а сумма меньших — нечётной. Какую наибольшую сумму чисел во всех выбранных 
# парах можно при этом получить?

f = open("inf_26_04_21_27b.txt", 'r')
n = int(f.readline())

matr = [[0, -1], [-1, -1]]

for line in f:
    a, b = map(int, line.split())

    if b%2 == 0: continue
    new_matr = [[val for val in ln] for ln in matr]
    if a > b: 
        a, b = b, a
    s = a + b
    
    for i in range(2):
        for j in range(2):
            if matr[i][j] != -1:
                new_matr[(i + a)%2][(j + b)%2] = max(new_matr[(i + a)%2][(j + b)%2], 
                                                        matr[i][j] + s)
    matr = new_matr

print(matr[1][0])