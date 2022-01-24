# a*x**2 + b*x + c = 0
import math

a = int(input())
b = int(input())
c = int(input())

math.sqrt(a)

if a == 0:
    if b == 0:
        if c == 0:
            print("Every real!")
        else:
            print("No")
    else:
        x = -c / b
        print(x)
else:
    D = b**2 - 4*a*c
    if D < 0:
        print("No")
    elif D == 0:
        print(-b/2/a)
    else:
        x1 = (-b - D**0.5)/2/a
        x2 = (-b + D**0.5)/2/a
        print(x1, x2)
