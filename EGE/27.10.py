# 3231 kompege

for path in (r"D:\Downloads\27-A (6).txt", r"D:\Downloads\27-B (6).txt"):
    with open(path) as f:
        n = int(f.readline())

        a = [int(line) for line in f]

        l = r = s = 0

        for i in range(1, n//2 + 1):
            s += a[i]*i
            l += a[i]
        for i in range(0, n//2):
            s += i*a[-i%n]
            r += a[-i%n]

        min_s = s
        min_i = 0

        for i in range(1, n):
            s = s - l + r
            l = l - a[i] + a[(i + n//2)%n]
            r = r + a[i] - a[(i + n//2)%n]
            if s < min_s:
                min_s = s
                min_i = i
        print(min_i + 1)