#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h>
#include "For the datebase.h"
#define DOWN 80
#define ESC 27
#define ENTER 13
#define UP 72

using namespace std;
int base_menu;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void XY(short x, short y) // функция для регулирования расположения курсора
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void Non_cursor(bool show, short size)
{
	CONSOLE_CURSOR_INFO cur_info;
	GetConsoleCursorInfo(hStdOut, &cur_info);
	cur_info.bVisible = show; // изменяем видимость курсора
	cur_info.dwSize = size;   // изменяем размер курсора
	SetConsoleCursorInfo(hStdOut, &cur_info);
}

int menu(int line)
{
	int Y = 12;
	XY(40, 12);

	string menu[]{ "1> Заставка", "2> Справочник \"Планеты Солнечной системы\"", "3> Об авторе", "4> Выход" };
	for (int i = 0; i < 4; i++)
	{
		if ((i + 12) == line)
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		else {
			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		XY(40, Y++);
		cout << menu[i];
	}
	return 0;
}

void MoveCircle1(HDC hdc, int x, int y)
{
	int r = 10, r1 = 10;
	HBRUSH brush;
	brush = CreateSolidBrush(RGB(218, 112, 214));

	SelectObject(hdc, brush);
	Ellipse(hdc, x, y, x + r, y + r1);
}

void Animation()
{
	HDC hDC = GetDC(GetConsoleWindow()); HWND hwnd = GetConsoleWindow(); // получаем дескриптор окна консоли
	HDC hdc = GetDC(hwnd);
	float a = 0.5;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	XY(40, 13); printf("__________________________________________________\n");

	XY(40, 14); printf("|Нажмите ПРОБЕЛ, чтобы выйти из этого пункта меню!|\n");
	XY(40, 15); printf("__________________________________________________\n");
	Sleep(1200);
	system("cls");

	while (true)
	{
		srand(time(NULL)); // повтор анимации после каждого входа в консоль
		HBRUSH brush1 = CreateSolidBrush(RGB(178, rand() % 200 + 55, 250)); // кисть 1
		HBRUSH brush2 = CreateSolidBrush(RGB(240, 255, rand() % 200 + 55)); // кисть 2

		int x, y;
		x = 300 * tan(a) + 300; // траектория движения для 1 элемента
		y = 200 * sin(a) + 300; // траектория движения для 1 элемента

		SelectObject(hDC, brush1); // выбрали кисть
		Ellipse(hDC, x, y, x + 5, y + 60); // рисуем круг

		int x1, y1;
		x1 = 300 * tan(a) + 500;
		y1 = 200 * sin(a) + 300;
		SelectObject(hDC, brush2);
		Ellipse(hDC, x1, y1, x1 + 5, y1 + 60);

		int x2, y2;
		x2 = 300 * tan(a) + 700;
		y2 = 200 * sin(a) + 300;
		SelectObject(hDC, brush1);
		Ellipse(hDC, x2, y2, x2 + 5, y2 + 60);

		a += 0.5f; // шаг перемещения
		Sleep(1); // задержка экрана

		int o, p, u, u1;
		o = x2; // присваиваем траекторию для других объектов
		p = y;
		u = x;
		u1 = y2;
		MoveCircle1(hdc, o, p);
		MoveCircle1(hdc, u, u1);

		if (GetAsyncKeyState(VK_SPACE)) // Функция для считывания клавиши пробела
		{
			break;
		}
	}

}

void author()
{
	int Y = 12;
	string author[]{ "РАСЧЁТНО ГРАФИЧЕСКАЯ РАБОТА", "По дисциплине \"программирование\"", "Подготовила:", "Студентка первого курса ОМГТУ", "группы ПИ-212, Эммерт Екатерина Васильевна" };

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 0; i < 5; i++)
	{
		XY(40, Y++);
		cout << author[i];
	}
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	XY(0, 25);
	cout << "Чтобы выйти в меню, нажмите любую клавишу..." << endl;
}


void directory_menu()
{
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	XY(40, 12); cout << "(1) Вывод из данных файла." << endl;
	XY(40, 13); cout << "(2) Просмотр справочника." << endl;
	XY(40, 14); cout << "(3) Редактирование данных." << endl;
	XY(40, 15); cout << "(4) Добавление новых данных." << endl;
	XY(40, 16); cout << "(5) Поиск по введенному названию." << endl;
	XY(40, 17); cout << "(6) Сохранение данных." << endl;
	XY(40, 18); cout << "Ваш выбор: " << ">> ";

	cin >> base_menu;
}

void realization_menu()
{
	directory_menu();
	int H = 0;
	string sourse = "list.txt";
	features* d = new features[H];

	while (base_menu != 0)
	{
		switch (base_menu)
		{
		case 1:
			system("cls");
			DataReading(d, H, sourse);
			system("pause");
			system("cls");
			directory_menu();
			break;

		case 2:
			system("cls");
			if (H != 0)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				Print(d, H);
			}
			else
				cout << "Данные не все! Нельзя осуществить просмотр. Попробуйте выбрать пункт меню - 1" << endl;

			system("pause");
			system("cls");
			directory_menu();
			break;

		case 3:
			system("cls");
			if (H != 0)
			{
				DataChange(d, H);
			}
			else
				cout << "Данные не все, нельзя внести изменения!" << endl;

			system("pause");
			system("cls");
			directory_menu();
			break;

		case 4:
			system("cls");
			if (H != 0)
			{
				AddData(d, H, sourse);
				H++;
			}
			else
				cout << "Данные не добавлены!" << endl;

			system("pause");
			system("cls");
			directory_menu();
			break;

		case 5:
			system("cls");

			if (H != 0)
			{
				SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				DataSearch(d, H);
				cout << endl;
			}

			else
				cout << "Данные не добавлены!" << "Нельзя осуществить поиск! Попробуйте выбрать пункт меню - 1" << endl;

			system("pause");
			system("cls");
			directory_menu();
			break;

		
		case 6:
			system("cls");
			if (H != 0)
			{
				SaveData(d, H, sourse);
			}
			else
				cout << "Данные не сохранены!" << endl;

			system("pause");
			system("cls");
			directory_menu();
			break;

		default:

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
			XY(40, 20); cout << "Неверно введён номер меню!" << endl;
			XY(40, 20); system("pause");
			system("cls");
			directory_menu();
			break;
		}

	}
}

int main()
{
	SetConsoleTitle(L"РГР, ПИ-212, Эммерт Е.В.");
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Non_cursor(false, 100);

	int X = 40, Y = 12;
	char button;
	while (true)
	{
		if (Y > 18) // Два условия проверки координат активной "кнопки".Нужно, чтобы координата активной кнопки не уходила за пределы выбора
		{
			Y = 12;
		}
		else if (Y < 12)
		{
			Y = 18;
		}

		menu(Y);

		XY(X, Y);

		button = _getch(); //Считывание нажатой клавиши
		if (button == -32) //Условие для считывания клавиши и перевода из 2 байтной кодировки в 1 байтную 
		{
			button = _getch(); //Повторное считывание нажатой клавиши
		}

		switch (button)
		{
		case UP:
		{
			Y--;
			break;
		}
		case DOWN:
		{
			Y++;
			break;
		}
		case ESC:
		{
			SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

			XY(0, 25);

			cout << "Завершение работы программы..." << endl;

			Sleep(500);

			return(0);
		}
		case ENTER:
		{

			switch (Y)
			{
			case 12:
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
				system("cls");

				Sleep(1);

				Animation();

				system("cls");

				break;
			}

			case 13:
			{
				system("cls");

				Sleep(1);

				realization_menu();

				_getch();

				system("cls");

				break;
			}

			case 14:
			{
				system("cls");

				Sleep(1);

				author();

				_getch();

				system("cls");

				break;
			}
			case 15:
			{
				XY(0, 25);

				SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

				cout << "Завершение работы программы..." << endl;
				Sleep(500);
				return(0);
			}
			}
		}
		}
	}
}