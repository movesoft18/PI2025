#from math import sqrt
import math

a = float(input('Введите коэффициент а:'))
b = float(input('Введите коэффициент b:'))
c = float(input('Введите коэффициент c:'))

if a != 0:
    d = b**2 - 4 * a * c
    if d > 0:
        x1 = (-b + math.sqrt(d)) / (2 * a)
        x2 = (-b - math.sqrt(d)) / (2 * a)
        result = f'Имеем 2 корня: {x1} {x2}'
    elif d == 0:
        x = -b/(2 * a)
        result = f'Имеем 1 корень: {x}'
    else:
        result = 'Корней нет'

print(result)