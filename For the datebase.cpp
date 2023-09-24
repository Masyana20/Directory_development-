#include "For the datebase.h"
#include <iomanip>
#include <Windows.h >

using namespace std;

void DataReading(features* (&d), int& n, string k)
{
	// создаём поток для чтения

	ifstream read;
	read.open(k);

	if (!read.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}

	else
	{
		cout << "Данные считанны ! ";
		read >> n;
		//выделяем память для данных
		d = new features[n];
		for (int i = 0; i < n; i++)
		{
			read >> d[i].s.w;

			read >> d[i].s.name;

			read >> d[i].s.mass;

			read >> d[i].s.satellites;

			read >> d[i].m.density;

			read >> d[i].m.diametr;

			read >> d[i].m.distance;

			read >> d[i].m.period;

			read >> d[i].e.word;

			read >> d[i].e.group;
		}

		read.close();
	}
}

void Print(features* d, int n)
{
	printf("__________________________________________________________________________________________________________________________________________________________________________________________________________\n");
	printf(" № |   Название     |     Масса(кг)     |   Количество спутников  |       Плотность(г/см^3)      |    Диаметр(тыс.км)  |    Расстояние от Солнца(а.е.)  |     Период обращения      |        Группа     |\n");
	printf("--- ---------------  ------------------- ------------------------- ------------------------------ --------------------- -------------------------------- --------------------------- -------------------|\n");

	for (int i = 0; i < n; i++)
	{

		cout << "\n " << d[i].s.w;

		cout << setw(14) << d[i].s.name;

		cout << "\t" << setw(13) << d[i].s.mass;

		cout << setw(16) << d[i].s.satellites;

		cout << setw(29) << d[i].m.density;

		cout << setw(29) << d[i].m.diametr;

		cout << setw(26) << d[i].m.distance;

		cout << setw(32) << d[i].m.period;


		cout << setw(22) << d[i].e.word << " " << d[i].e.group;
		cout << endl;


	}
	printf("__________________________________________________________________________________________________________________________________________________________________________________________________________\n");
}

void DataChange(features* (&d), int& n)
{
	char p[10]{};
	string h;
	cout << "Введите название планеты, данные которой хотите исправить: ";
	cin >> p;

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		 if (_stricmp(d[i].s.name, p) == 0)
		{

			cout << "Введите массу планеты: ";
			cin >> d[i].s.mass;

			cout << "Введите количество спутников планеты: ";
			cin >> d[i].s.satellites;

			cout << endl;
			cout << setw(40) << "!Внимание дальше данные вводите с точкой \".\" !" << endl;

			cout << "Введите плотность планеты: ";
			cin >> d[i].m.density;

			cout << "\n\nХотите продолжить ввод ( тогда уж до конца :) )? Напишите \"Да\"."" Если нет, то напишите \"Стоп\": ";
			cin >> h;

			if ((h == "да") || (h == "Да"))
			{

				cout << "Введите расстояние планеты от солнца: ";
				cin >> d[i].m.distance;

				cout << "Введите диаметр планеты: ";
				cin >> d[i].m.diametr;

				cout << "Введите период планеты: ";
				cin >> d[i].m.period;

				cout << "Какая это планета Группа: карлик? гигант? или  Земной группы? ";
				cin >> d[i].e.word;
				cin >> d[i].e.group;

				system("cls");
				cout << endl;
				cout << "Данные изменены!" << endl;
				cout << setw(50) << "!Перед просмотром выберите пункт сохранения данных!" << endl;
			}

			else
				cout << " На этом всё!" << endl;
			    cout << endl;
			    cout << setw(50) << "!Перед просмотром выберите пункт сохранения данных!" << endl;
			break;
		}
	}
}
void DataSearch(features* (&d), int& n)
{
	char p[10]{};
	int o = 0;
	int l;
	cout << "Введите название планеты, данные которой хотите найти: ";
	cin >> p;

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(d[i].s.name, p) == 0)
		{
			o = d[i - 1].s.w;
			cout << "Результат для: " << setw(14) << d[i].s.name << endl;
			cout << endl;
			printf(" № |     Масса(кг)   |   Количество спутников   |     Плотность(г/см^3)      |  Диаметр(тыс.км)  |  Расстояние от Солнца(а.е.)  |     Период обращения      |        Группа     |\n");
			printf("--- ----------------- -------------------------- ---------------------------- ------------------- ------------------------------ --------------------------- -------------------|\n");
			cout << "\n " << d[i].s.w << setw(17) << d[i].s.mass << setw(18) << d[i].s.satellites;

			cout << setw(28) << d[i].m.density << setw(27) << d[i].m.diametr << setw(24) << d[i].m.distance << setw(29) << d[i].m.period;

			cout << setw(20) << d[i].e.word << " " << d[i].e.group << endl;
			cout << endl;
			cout << "_______________________________________________________________________________________________________________________________________________________________________________";

			cout << "\n\nХотите удалить данную планету? Напишите \"1\",\"Если нет, то напишите \"0\"  ";
			cin >> l;
			if (l == 1)
			{
				if (o >= 0 && o < n)
				{

					// временный массив для хранения
					features* change = new features[n];
					Copy(change, d, n);
					// выделяем новую память
					--n;
					d = new features[n];

					int q = 0;

					//запоминаем данные кроме того, который хотим удалить
					for (int w = 0; w <= n; w++)
					{
						if (w != o)
						{
							d[q] = change[w];
							++q;
						}
					}

					delete[]change;
					system("cls");
					Sleep(5);
					cout << "Данные удалены" << endl;
					cout << setw(20) << "!Перед просмотром выберите пункт сохранения данных!" << endl;
				}
			}
			else if (l == 0)
			{
				system("cls");
				Sleep(200);
				cout << "Тогда в меню ->!" << endl;
			}

		}
	}

}

void Copy(features* (&d_t), features* (&d_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_t[i] = d_o[i];
	}
}

void AddData(features* (&d), int& n, string k)
{
	fstream r(k);
	r.seekg(0, ios_base::end);
	cout << "Последовательно согласно выведенной надписи вводите характеристики планеты." << endl;
	cout << endl;
	// временный массив данных
	features* f;
	f = new features[n];

	// сохраняем данные в временный массив
	Copy(f, d, n);

	// выделяем новую память
	n++;

	d = new features[n];

	// возвращаем данные
	Copy(d, f, --n);

	r << endl;

	cout << "Присвойте планете номер: ";
	cin >> d[n].s.w;
	cout << endl;
	r << d[n].s.w << endl;

	cout << "Введите имя: ";
	cin >> d[n].s.name;
	r << d[n].s.name << endl;

	cout << "Введите массу планеты: ";
	cin >> d[n].s.mass;
	r << d[n].s.mass << endl;

	cout << "Введите количество спутников планеты: ";
	cin >> d[n].s.satellites;
	r << d[n].s.satellites << endl;

	cout << setw(50) << "!Внимание дальше данные вводите с точкой \".\" !"<<endl;
	cout << endl;

	cout << "Введите плотность планеты: ";
	cin >> d[n].m.density;
	r << d[n].m.density << endl;

	cout << "Введите расстояние планеты от солнца: ";
	cin >> d[n].m.diametr;
	r << d[n].m.diametr << endl;

	cout << "Введите диаметр планеты: ";
	cin >> d[n].m.distance;
	r << d[n].m.diametr << endl;

	cout << "Введите период планеты: ";
	cin >> d[n].m.period;
	r << d[n].m.period << endl;

	cout << "Введите особенности планеты: Планета Карлик; Планета Гигант; Земной группы  ";
	cin >> d[n].e.word;
	r << d[n].e.word << endl;
	cin >> d[n].e.group;
	r << d[n].e.group;

	r.close();

	system("cls");
	cout << "Данные добавлены!" << endl;
	cout << endl;
	cout << setw(50) << "!Перед просмотром выберите пункт сохранения данных!" << endl;
	delete[] f;

}
void SaveData(features* d, int& n, string k)
{
	// создаётся поток для записи
	ofstream tt(k, ios::out);

	if (tt)
	{
		tt << n << endl;
		for (int i = 0; i < n; i++)
		{
			tt << d[i].s.w << endl;

			tt << d[i].s.name << endl;

			tt << d[i].s.mass << endl;

			tt << d[i].s.satellites << endl;

			tt << d[i].m.density << endl;

			tt << d[i].m.diametr << endl;

			tt << d[i].m.distance << endl;

			tt << d[i].m.period << endl;

			tt << d[i].e.word;

			tt << d[i].e.group;

			if (i < n - 1)
			{
				tt << d[i].e.group << endl;
			}
			else
				tt << d[i].e.group;
		}

		cout << "Данные сохранены!" << endl;
	}

	else
		cout << "Ошибка открытия файла!" << endl;

	tt.close();
}
