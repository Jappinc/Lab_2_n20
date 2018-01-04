/*
Задача 20
Создать класс Payment. В классе должны быть представлены поля:
- фамилия,
- имя,
- отчество,
- оклад,
- год поступления на работу,
- процент надбавки,
- подоходный налог,
- количество отработанных дней в месяце,
- количество рабочих дней в месяце,
- начисленная и удержанная суммы.

Реализовать методы: 
- вычисления начисленной суммы,
- вычисления удержанной суммы,
- вычисление стажа.
*/

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>

using namespace std;

class Person
{
private:
	string name;//имя
	string surName;//фамилия
	string patronymic;//отчество
	float salary;// оклад
	int yearOfEmployment;//год поступления на работу
	float perallow;// процент надбавки
	float incomeTax;// подоходный налог - 13%
	float pension;//1% на пенсию
	int dayMonth;//дней в месяце
	int dayWorkMonth;//отработано дней в месяце
	float accrual;// начисленная сумма 
	float amountWithheld;//удержанная сумма

public:
	Person() { salary = 0; yearOfEmployment = 0; dayMonth = 0; dayWorkMonth = 0; };
    void Read(); // ввод владельца
	void Display();//вывод владельца
	float Accrual();// начисленная сумма 
	float AmountWithheld();//удержанная сумма
	int Experience();//стаж работы
};
	


void Person::Read()// ввод владельца
	{
		cout << "Введите имя" << endl;
		cin >> name;
		cout << "Введите фамилию " << endl;
		cin >> surName;
		cout << "Введите отчество " << endl;
		cin >> patronymic;
		do 
		{
			cout << "Год поступления на работу " << endl;
			cin >> yearOfEmployment;
		} while (yearOfEmployment <= 2000);

		do
		{
			cout << "Введите оклад " << endl;
			cin >> salary;
		} while (salary <= 0);

		do
		{
			cout << "Дней в месяце " << endl;
			cin >> dayMonth;
		} while (dayMonth <= 28 || dayMonth >= 31);

		do 
		{
			cout << "Отработано дней в мес€це " << endl;
			cin >> dayWorkMonth;
		} while (dayWorkMonth >= dayMonth);
	}

void Person::Display()
{
	cout << "Имя - " << name << endl;
	cout << "Фамилия - " << surName << endl;
	cout << "Отчество - " << patronymic << endl;
	cout << "Год поступления на работу - " << yearOfEmployment << " год" << endl;
	cout << "Оклад - " << salary << endl;
	cout << "Отчество - " << patronymic << endl;
	cout << "Отработано дней в мес€це - " << dayWorkMonth << endl;	
}

float Person::AmountWithheld()//удержанная сумма
{
	incomeTax = (salary / 100) * 13;
	pension = (salary / 100);
	return incomeTax + pension;
}

float Person::Accrual()// начисленная сумма = salary-amountWithheld
{
	return salary - AmountWithheld();
}

int Person::Experience()//стаж работы
{
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int year = aTime->tm_year + 1900;

	return year - yearOfEmployment;
}

	int main()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		Person ps;
		int number;

		for (; ;)
		{
			cout << "=========== Меню ===========" << endl;
			cout << "1 - Ввод нового пользовател€" << endl;
			cout << "2 - Информаци€ о пользователе" << endl;
			cout << "3 - Удержанна€ сумма " << endl;
			cout << "4 - Начисленна€ сумма  " << endl;
			cout << "5 - Стаж " << endl;
			cout << "0 - Выход " << endl;
			cout << "============================" << endl;
			cout << "Введите ваш вариант: " << endl;
			cin >> number;

			switch (number)
			{
			case 1: ps.Read(); break;
			case 2: ps.Display(); break;
			case 3: printf_s("Удержанная сумма = %.2f \n", ps.AmountWithheld()); break;
			case 4: printf_s("Начисленная сумма = %.2f \n",ps.Accrual()); break;
			case 5: printf_s("Стаж = %d лет \n",ps.Experience()); break;
			case 0: cout << "Выход..." << endl; exit(1); break;
	
			default: cout << "Некорретный ввод " << endl; break;
			}
			getchar();
		}
		return 0;
	}