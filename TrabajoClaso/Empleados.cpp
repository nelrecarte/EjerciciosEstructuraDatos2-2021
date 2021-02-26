#include "Empleados.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

empleado structEmpleado;
int cantidadEmpleados = 10000;

void Empleados::generarEmpleados()
{
	std::fstream archivoEmpleados("empleados.bin", std::ios::out | std::ios::binary | std::ios::app);

	if (!archivoEmpleados)
	{
		std::cout << "Error al abrir archivo\n";
		return;
	}

	//int cantidadEmpleados = 10000;

	std::cout << "Generando Empleados por favor Espere\n";

	char nombre[20];
	for (int i = 0; i < cantidadEmpleados; i++)
	{
		
		structEmpleado.codigo = i; 
		strcpy_s(structEmpleado.nombre,"empleado_" + i);
		structEmpleado.salario = (rand() % 100) + 2200;
		structEmpleado.estado = true;

		archivoEmpleados.write(reinterpret_cast<const char*>(&structEmpleado), sizeof(empleado));
	}

	archivoEmpleados.close();

}


void Empleados::busquedaSecuencial()
{
	std::fstream archivoEmpleados("empleados.bin", std::ios::in | std::ios::out | std::ios::binary);

	if (!archivoEmpleados)
	{
		std::cout << "Error al abrir archivo\n";
		return;
	}
	int codigo;
	std::cout << "\nIngrese codigo Empleado: ";
	std::cin >> codigo;

	archivoEmpleados.seekg(0, std::ios::beg);

	//long pos = 0;


	for (int i = 0; i < cantidadEmpleados; i++)
	{
		archivoEmpleados.read(reinterpret_cast<char*>(&structEmpleado), sizeof(empleado));
		
		if (codigo == structEmpleado.codigo)
		{
			std::cout << structEmpleado.nombre << " " << structEmpleado.codigo;
			break;
		}
	}

	archivoEmpleados.close();
}

void Empleados::busquedaBinaria()
{
	int codigoBuscar;

	std::cout << "\n Ingrese codigo a buscar: ";
	std::cin >> codigoBuscar;

	std::vector<empleado> vector;

	std::fstream archivoEmpleados("empleados.bin", std::ios::out | std::ios::binary | std::ios::app);

	if (!archivoEmpleados)
	{
		std::cout << "Error al abrir archivo\n";
		return;
	}

	archivoEmpleados.seekg(0, std::ios::beg);

	for (int i = 0; i < cantidadEmpleados; i++)
	{
		archivoEmpleados.read(reinterpret_cast<char*>(&structEmpleado), sizeof(empleado));
		vector.push_back(structEmpleado);
	}
	archivoEmpleados.close();


	if (std::binary_search(vector.begin(), vector.end(), codigoBuscar))
	{
		std::cout << "Empleado Encontrado";
	}
	else
	{
		std::cout << "Empleado no Encontrado";
	}
	

}



