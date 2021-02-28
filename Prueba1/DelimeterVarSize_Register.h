#pragma once
#ifndef DELIMETERSIZE_REGISTER
#define DELIMETERSIZE_REGISTER
#include "DataFile.h"

struct knownVarSize_Register
{
	DataFile* file;
	int code;
	char* name;
	double salary;
	int sizeJob;
	char* job;

public:
	void print_register();			// Imprime en consola, los campos del registro actual
	char* toChar();					// Construye un buffer de datos con la estructura en bytes de campos del registro actual
	void fromChar(char*);			// Inserta en cada campo, los valores a partir del buffer de datos enviado por parametro
	void open_file(char*);			// Abre el archive con la estructura de registro
	void write_into_file();			// Escribe al final del archivo binario, la estructura de datos actual
	void read_from_file(int pos);	// Lee a partir de una posición(índice) un registro dentro del archivo binario
	void close_file();				// Cierra el archivo con la estructura de registro
	int get_size();					// Obtiene el tamaño total en bytes de la estructura de registro
};
#endif // !DELIMETERSIZE_REGISTER
