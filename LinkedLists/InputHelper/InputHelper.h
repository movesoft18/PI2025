#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

#include <iostream>
#include <string>
#include <conio.h>
using std::cout;
using std::endl;


template <typename T> // Объявляем шаблонную функцию с параметром T
bool ReadValue(const std::string& source, T& result) // это второй параметр функции
{
	size_t errSymbolPos;
	try // защищаемый блок
	{
		// а вот здесь нам нужно определить тип передаваемого параметра T и в зависимости от него
		// вызвать нужную нам функцию преобразования. Узнать тип параметра нам поможет функция typeid()
		if (typeid(T) == typeid(double)) // если это double
			result = stod(source, &errSymbolPos); // то преобразуем в double
		else if (typeid(T) == typeid(float)) // если float
			result = stof(source, &errSymbolPos); // то во float
		else if (typeid(T) == typeid(int)) // если int
			result = stoi(source, &errSymbolPos); // то в int
		else throw std::invalid_argument("Invalid type"); // иначе генерируем исключение std::invalid_argument (поскольку мы не поддерживаем 
														  // другие типы чисел, хотя перечень можно и расширить
		if (errSymbolPos < source.length()) // весь остальной код вам уже знаком
		{
			result = 0;
			return false;
		}
	}
	catch (std::invalid_argument e)
	{
		result = 0;
		return false;
	}
	return true;
}

template <typename T> // тоже используем шаблон, чтобы можно было считывать любые числа
// первый параметр - сообщение, выводимое пользователю в качестве приглашения ввода
// второй параметр, передаваемый по ссылке - возвращаемое число типа T
// результат функции - true, если введено корректное число и false, если пользователь отказался от ввода
bool InputValue(const std::string& inputMessage, T& resultValue)
{
	bool result = false; // результат преобразования строки в число
	do // цикл - долбаем пользователя, пока он не введет корректное число, или не нажмет Esc для отмены
	{
		std::string source; // исходная строка, читаемая с консоли
		std::cout << inputMessage; // выводим в консоль приглашение для ввода
		std::getline(std::cin, source); // считываем строку с консоли
		result = ReadValue<T>(source, resultValue); // вызываем уже ранее сделанную функцию преобразования строки в число, параметризуя
													// шаблон параметром T
		if (!result)	// если ошибка преобразования
		{	// выводим сообщение в консоль о неверном вводе и просим повторить
			std::cout << "Неверные данные, нажмите ENTER для повтора или Esc для отмены ввода\n";
			// если пользователь нажимает Esc, то возвращаем false и прерываем дальнейший ввод
			if (_getch() == 27) return false;
		}
	} while (!result); // повторяем ввод, пока пользователь не введет корректное число
	return true; // и возвращаем true
}
