#pragma once
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class DataFile
{
public:
	DataFile();
	void abrir(char* direccion, int);
	void cerrar();
	void escribir(char*, int);
	char* leer(int, int);
private:
	char* direccion;
	ofstream* escribiendo;
};
