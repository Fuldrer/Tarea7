

// CursoresTarea.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Campeon{
public:
	int ataque;
	int next = 1;
};

Campeon champ[10];
int disponible = 0;

void initcursor(){
	for (int a = 0; a < 9; a++){
		champ[a].next = a + 1;
	}
	champ[9].next = 1;
}

int crear(Campeon champi){
	int temp = disponible;
	disponible = champ[disponible].next;
	champ[temp] = champi;
	return temp;
}

Campeon buscar(int a, int lista){
	while (lista != -1 && champ[lista].ataque != a){
		lista = champ[lista].next;
	}
	if (lista == -1){
		cout << "No hay lista" << endl;
	}
}

Campeon buscaranterior(int a, int lista){
	int temp = -1;
	while (lista != -1 && champ[lista].ataque != a){
		temp = lista;
		lista = champ[lista].next;
	}
	if (lista != -1){
		return champ[temp];
	}
}

void eliminar(int pos, int lista){
	if (pos<0 || pos>9){
		cout << "posicion fuera del arreglo \n" << endl;
	}
	else{
		champ[pos].ataque = NULL;
		champ[pos].next = pos + disponible;
		disponible = pos;
	}
}

void agregar(Campeon campeon, int list){
	while (champ[list].next != -1){
		list= champ[list].next;
	}
	int temp = disponible;
	champ[list].next = temp;
	disponible = champ[disponible].next;
	champ[temp] = campeon;
}

void print(){
	for (int i = 0; i < 10; i++){
		cout << "Posicion: " << i << "  Ataque: " << champ[i].ataque << "  Siguiente: " << champ[i].next << endl;
	}
	cout << "Disponible: " << disponible << "\n" << endl;
}

int main()
{
	initcursor();
	Campeon Alistar, Evelynn, Malzahar, Kogmaw, Rammus, Akali;
	Alistar.ataque = 10; Evelynn.ataque = 5; Malzahar.ataque = 8; Kogmaw.ataque = 4, Rammus.ataque = 7; Akali.ataque = 3;
	int lista = crear(Alistar);
	int lista2 = crear(Evelynn);
	agregar(Malzahar, lista); 
	agregar(Kogmaw, lista2); 
	agregar(Rammus, lista); 
	agregar(Akali, lista2);
	print();
	eliminar(0, lista);
	print();
	return 0;
}

