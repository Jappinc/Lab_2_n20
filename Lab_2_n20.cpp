/*
������ 20
������� ����� Payment. � ������ ������ ���� ������������ ����:
- �������,
- ���,
- ��������,
- �����,
- ��� ����������� �� ������,
- ������� ��������,
- ���������� �����,
- ���������� ������������ ���� � ������,
- ���������� ������� ���� � ������,
- ����������� � ���������� �����.

����������� ������: 
- ���������� ����������� �����,
- ���������� ���������� �����,
- ���������� �����.
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
	string name;//���
	string surName;//�������
	string patronymic;//��������
	float salary;// �����
	int yearOfEmployment;//��� ����������� �� ������
	float perallow;// ������� ��������
	float incomeTax;// ���������� ����� - 13%
	float pension;//1% �� ������
	int dayMonth;//���� � ������
	int dayWorkMonth;//���������� ���� � ������
	float accrual;// ����������� ����� 
	float amountWithheld;//���������� �����

public:
	Person() { salary = 0; yearOfEmployment = 0; dayMonth = 0; dayWorkMonth = 0; };
    void Read(); // ���� ���������
	void Display();//����� ���������
	float Accrual();// ����������� ����� 
	float AmountWithheld();//���������� �����
	int Experience();//���� ������
};
	


void Person::Read()// ���� ���������
	{
		cout << "������� ���" << endl;
		cin >> name;
		cout << "������� ������� " << endl;
		cin >> surName;
		cout << "������� �������� " << endl;
		cin >> patronymic;
		do 
		{
			cout << "��� ����������� �� ������ " << endl;
			cin >> yearOfEmployment;
		} while (yearOfEmployment <= 2000);

		do
		{
			cout << "������� ����� " << endl;
			cin >> salary;
		} while (salary <= 0);

		do
		{
			cout << "���� � ������ " << endl;
			cin >> dayMonth;
		} while (dayMonth <= 28 || dayMonth >= 31);

		do 
		{
			cout << "���������� ���� � ������ " << endl;
			cin >> dayWorkMonth;
		} while (dayWorkMonth >= dayMonth);
	}

void Person::Display()
{
	cout << "��� - " << name << endl;
	cout << "������� - " << surName << endl;
	cout << "�������� - " << patronymic << endl;
	cout << "��� ����������� �� ������ - " << yearOfEmployment << " ���" << endl;
	cout << "����� - " << salary << endl;
	cout << "�������� - " << patronymic << endl;
	cout << "���������� ���� � ������ - " << dayWorkMonth << endl;	
}

float Person::AmountWithheld()//���������� �����
{
	incomeTax = (salary / 100) * 13;
	pension = (salary / 100);
	return incomeTax + pension;
}

float Person::Accrual()// ����������� ����� = salary-amountWithheld
{
	return salary - AmountWithheld();
}

int Person::Experience()//���� ������
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
			cout << "=========== ���� ===========" << endl;
			cout << "1 - ���� ������ ������������" << endl;
			cout << "2 - ���������� � ������������" << endl;
			cout << "3 - ���������� ����� " << endl;
			cout << "4 - ����������� �����  " << endl;
			cout << "5 - ���� " << endl;
			cout << "0 - ����� " << endl;
			cout << "============================" << endl;
			cout << "������� ��� �������: " << endl;
			cin >> number;

			switch (number)
			{
			case 1: ps.Read(); break;
			case 2: ps.Display(); break;
			case 3: printf_s("���������� ����� = %.2f \n", ps.AmountWithheld()); break;
			case 4: printf_s("����������� ����� = %.2f \n",ps.Accrual()); break;
			case 5: printf_s("���� = %d ��� \n",ps.Experience()); break;
			case 0: cout << "�����..." << endl; exit(1); break;
	
			default: cout << "����������� ���� " << endl; break;
			}
			getchar();
		}
		return 0;
	}