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
void XY(short x, short y) // ������� ��� ������������� ������������ �������
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void Non_cursor(bool show, short size)
{
	CONSOLE_CURSOR_INFO cur_info;
	GetConsoleCursorInfo(hStdOut, &cur_info);
	cur_info.bVisible = show; // �������� ��������� �������
	cur_info.dwSize = size;   // �������� ������ �������
	SetConsoleCursorInfo(hStdOut, &cur_info);
}

int menu(int line)
{
	int Y = 12;
	XY(40, 12);

	string menu[]{ "1> ��������", "2> ���������� \"������� ��������� �������\"", "3> �� ������", "4> �����" };
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
	HDC hDC = GetDC(GetConsoleWindow()); HWND hwnd = GetConsoleWindow(); // �������� ���������� ���� �������
	HDC hdc = GetDC(hwnd);
	float a = 0.5;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	XY(40, 13); printf("__________________________________________________\n");

	XY(40, 14); printf("|������� ������, ����� ����� �� ����� ������ ����!|\n");
	XY(40, 15); printf("__________________________________________________\n");
	Sleep(1200);
	system("cls");

	while (true)
	{
		srand(time(NULL)); // ������ �������� ����� ������� ����� � �������
		HBRUSH brush1 = CreateSolidBrush(RGB(178, rand() % 200 + 55, 250)); // ����� 1
		HBRUSH brush2 = CreateSolidBrush(RGB(240, 255, rand() % 200 + 55)); // ����� 2

		int x, y;
		x = 300 * tan(a) + 300; // ���������� �������� ��� 1 ��������
		y = 200 * sin(a) + 300; // ���������� �������� ��� 1 ��������

		SelectObject(hDC, brush1); // ������� �����
		Ellipse(hDC, x, y, x + 5, y + 60); // ������ ����

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

		a += 0.5f; // ��� �����������
		Sleep(1); // �������� ������

		int o, p, u, u1;
		o = x2; // ����������� ���������� ��� ������ ��������
		p = y;
		u = x;
		u1 = y2;
		MoveCircle1(hdc, o, p);
		MoveCircle1(hdc, u, u1);

		if (GetAsyncKeyState(VK_SPACE)) // ������� ��� ���������� ������� �������
		{
			break;
		}
	}

}

void author()
{
	int Y = 12;
	string author[]{ "���ר��� ����������� ������", "�� ���������� \"����������������\"", "�����������:", "��������� ������� ����� �����", "������ ��-212, ������ ��������� ����������" };

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	for (int i = 0; i < 5; i++)
	{
		XY(40, Y++);
		cout << author[i];
	}
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	XY(0, 25);
	cout << "����� ����� � ����, ������� ����� �������..." << endl;
}


void directory_menu()
{
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	XY(40, 12); cout << "(1) ����� �� ������ �����." << endl;
	XY(40, 13); cout << "(2) �������� �����������." << endl;
	XY(40, 14); cout << "(3) �������������� ������." << endl;
	XY(40, 15); cout << "(4) ���������� ����� ������." << endl;
	XY(40, 16); cout << "(5) ����� �� ���������� ��������." << endl;
	XY(40, 17); cout << "(6) ���������� ������." << endl;
	XY(40, 18); cout << "��� �����: " << ">> ";

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
				cout << "������ �� ���! ������ ����������� ��������. ���������� ������� ����� ���� - 1" << endl;

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
				cout << "������ �� ���, ������ ������ ���������!" << endl;

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
				cout << "������ �� ���������!" << endl;

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
				cout << "������ �� ���������!" << "������ ����������� �����! ���������� ������� ����� ���� - 1" << endl;

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
				cout << "������ �� ���������!" << endl;

			system("pause");
			system("cls");
			directory_menu();
			break;

		default:

			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_INTENSITY);
			XY(40, 20); cout << "������� ����� ����� ����!" << endl;
			XY(40, 20); system("pause");
			system("cls");
			directory_menu();
			break;
		}

	}
}

int main()
{
	SetConsoleTitle(L"���, ��-212, ������ �.�.");
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Non_cursor(false, 100);

	int X = 40, Y = 12;
	char button;
	while (true)
	{
		if (Y > 18) // ��� ������� �������� ��������� �������� "������".�����, ����� ���������� �������� ������ �� ������� �� ������� ������
		{
			Y = 12;
		}
		else if (Y < 12)
		{
			Y = 18;
		}

		menu(Y);

		XY(X, Y);

		button = _getch(); //���������� ������� �������
		if (button == -32) //������� ��� ���������� ������� � �������� �� 2 ������� ��������� � 1 ������� 
		{
			button = _getch(); //��������� ���������� ������� �������
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

			cout << "���������� ������ ���������..." << endl;

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

				cout << "���������� ������ ���������..." << endl;
				Sleep(500);
				return(0);
			}
			}
		}
		}
	}
}