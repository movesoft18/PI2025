#from math import sqrt
import math

def quadratic_equation(a, b, c):
    if a != 0:
        d = b**2 - 4 * a * c
        if d > 0:
            x1 = (-b + math.sqrt(d)) / (2 * a)
            x2 = (-b - math.sqrt(d)) / (2 * a)
            return 2, [x1, x2]
        if d == 0:
            x = -b/(2 * a)
            return 1, [x]
        return 0, []
    else:
        if b != 0:
            x = -c/b
            return 1, [x]
        if c == 0:
            return 3, []
        return 0, []

a = float(input('Введите коэффициент а:'))
b = float(input('Введите коэффициент b:'))
c = float(input('Введите коэффициент c:'))

count, roots = quadratic_equation(a, b, c)
if count == 0:
    print('Нет корней')
elif count == 1:
    print('Один корень', roots[0])
elif count == 2:
    print('Два корня', roots[0], roots[1])
else:
    print('Бесконечное множество корней')