#pragma once
#include <ctime>
#include <string>

struct fileEntry
{
	char name[30];
	char type;
	int size;
	int padre;
	int hijo;
	int nextSibling;
	int primerBloq;
	bool available;
};


//133271 bytes

//1. Name: Nombre del archivo / directorio creado
//2. Type : Tipo de objeto(Archivo o Directorio)
//3. Date : Fecha de creación del archivo / directorio
//4. Size : Tamaño total en bloques de datos, del archivo / directorio.
//5. 12 apuntadores unsigned int a bloques de datos indirectos
//6. 1 apuntador a bloque de índice de un nivel
//7. 1 apuntador a bloque de índice de dos niveles
//8. 1 apuntador a bloque de índice de tres niveles