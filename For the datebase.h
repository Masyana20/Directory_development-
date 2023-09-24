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


void DataReading(features* (&d), int& n, string k); // ������ ������
void Print(features* d, int n); // ����� ������
void DataChange(features* (&d), int& n); // ��������� ������
void DataSearch(features* (&d), int& n); // ����� �� �����
void Copy(features* (&d_t), features* (&d_o), int n); //
void AddData(features* (&d), int& n, string k);// ���������� ������
void SaveData(features* d, int& n, string k); // ���������� ������