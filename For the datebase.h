#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

struct line
{
	int w;
	char name[10];
	string mass;
	char satellites[5];
};

struct ch
{
	char word[10] = {};
	char group[10] = {};
};

struct numbers
{
	double distance,
		diametr,
		density,
		period;
};

struct features
{
	line s;
	ch e;
	numbers m;
};


void DataReading(features* (&d), int& n, string k); // чтение данных
void Print(features* d, int n); // вывод данных
void DataChange(features* (&d), int& n); // изменение данных
void DataSearch(features* (&d), int& n); // поиск по имени
void Copy(features* (&d_t), features* (&d_o), int n); //
void AddData(features* (&d), int& n, string k);// добавление данных
void SaveData(features* d, int& n, string k); // сохранение данных