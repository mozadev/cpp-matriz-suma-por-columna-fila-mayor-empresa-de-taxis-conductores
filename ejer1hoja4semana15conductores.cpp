/*
ejercicio 1 hoja 4 bidimensionales
*/
#include<iostream>
#include<stdlib.h>
#include <time.h>

using namespace std;

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
		for(int j=1; j<= 6; j++) // genera pasjs para 6 dias
            Matriz[i][j] = 1 + rand() % 25;
	}
}
void ImprimirDatos(int N, float **Matriz)
{
	cout << endl << " DATOS DE LA MATRIZ" << endl<<endl;
	cout<<"Cond. \t Dia1 \t Dia2 \t Dia3 \t Dia4 \t Dia5 \t Dia6 "<<endl;;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< 7; j++)
			cout << Matriz[i][j] <<"\t";
		cout << endl;
	}
}

void PasajerosSemana(int N, float **Matriz)
{
	float Pasajeros = 0;
	cout << endl << " PASAJEROS POR CONDUCTOR EN LA SEMANA" << endl<< endl;
	cout<<"COND. \t PASAJEROS x SEMANA"<<endl;
	for (int i = 0; i < N; i++)
	{
		int Suma = 0;
		for(int j=1; j<= 6; j++)
			Suma = Suma + Matriz[i][j];
        cout<<Matriz[i][0]<<"\t"<<Suma<<endl;
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

}
