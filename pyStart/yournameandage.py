name = input('Введите ваше имя:')
age = int(input('Введите ваш возраст:'))
if age <= 0: 
    text = 'Не ври, ты еще не родился!'
elif age > 100:
    text = 'Не ври, столько не живут!'
else:
    text = f'Тебя зовут {name} и тебе {age} лет'
print(text)