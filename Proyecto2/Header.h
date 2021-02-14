#pragma once
#ifndef HEADER_H
#define HEADER_H
#include "metaData.h"
#include <string.h>
#include <fstream>


class header
{
public: 
	std::fstream archivoDisco;
	void crearDisco();
//	static std::string get_time();

	void initBitMap(char*, int);
	void initFileEntries(char*, int);
	void initDataBlocks();


	void cargarDisco();
	void cargarBitMap();
	void cargarFileEntries();

	void crearDirectorio(); 
	void elimDirectorio(); 
	void listar(); 
	void importFile();
	void exportFile();

	void actualizarBM(int);
};
#endif // !HEADER_H
