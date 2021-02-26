//#include "stdafx.h"
#include "DataFile.h"

DataFile::DataFile()
{
	this->direccion = new char[13];
}

void DataFile::abrir(char* direccion, int size)
{
	this->direccion = direccion;

	this->escribiendo = new ofstream(this->direccion, ios::in | ios::out | ios::binary | ios::app);
	if (!escribiendo->is_open())
	{
		escribiendo->open(this->direccion);
	}
}

void DataFile::cerrar()
{
	this->escribiendo->close();
}

void DataFile::escribir(char* info, int size)
{
	this->escribiendo->seekp(0, ios::end);
	this->escribiendo->write(info, size);
}

char* DataFile::leer(int initialPosition, int size)
{
	char* regre = new char[size];
	ifstream in(this->direccion);
	in.seekg(initialPosition);
	in.read(regre, size);
	return regre;
}