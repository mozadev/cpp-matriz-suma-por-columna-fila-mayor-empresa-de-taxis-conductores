#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>
using namespace std;
using namespace System;

int IngresaPositivo()
{
	int Num;
	do
	{
		cout << "numero positivo:"; cin >> Num;
	} while (Num <= 1 || Num > 20);
	return Num;
}
void IngresaDatos(int N, float **Matriz)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		Matriz[i][0] = i + 1; // conductores
		for (int j = 1; j <= 6; j++) // genera pasjs para 6 dias
			Matriz[i][j] = 1 + rand() % 25;
	}
}
void ImprimirDatos(int N, float **Matriz)
{
	cout << endl << " DATOS DE LA MATRIZ" << endl << endl;
	cout << "Conduct. \t dia1 \t dia2 \t Dia3 \t dia4 \t dia5 \t dia6 " << endl;;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< 7; j++)
			cout << Matriz[i][j] << "\t";
		cout << endl;
	}
}

void PasajerosSemana(int N, float **Matriz)
{
	float Pasajeros = 0;
	cout << endl << " PASAJEROS POR CONDUCTOR EN LA SEMANA" << endl << endl;
	cout << "COND. \t PASAJEROS x SEMANA" << endl;
	for (int i = 0; i < N; i++)
	{
		int Suma = 0;
		for (int j = 1; j <= 6; j++)
			Suma = Suma + Matriz[i][j];
		cout << Matriz[i][0] << "\t" << Suma << endl;

	}
	for (int j = 1; j <= 6; j++)
	{
		float Suma2 = 0;
		for (int i = 0; i < N; i++)
			Suma2 = Suma2 + Matriz[i][j];
		cout << "promedio dia " << j << ":" << "\t" << Suma2 / N << endl;
	}

}



int main()
{
	int N = IngresaPositivo();
	float **Matriz;
	Matriz = new float *[N];
	for (int i = 0; i<N; i++)
		Matriz[i] = new float[8];
	IngresaDatos(N, Matriz);
	ImprimirDatos(N, Matriz);
	PasajerosSemana(N, Matriz);
	for (int i = 0; i<N; i++)
		delete[] Matriz[i];
	delete[] Matriz;
	_getch();

}
