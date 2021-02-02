#include "Empleados.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>

void Empleados::generarEmpleados()
{
	std::fstream archivoEmpleados("empleados.bin", std::ios::out | std::ios::binary | std::ios::app);

	if (!archivoEmpleados)
	{
		std::cout << "Error al abrir archivo\n";
		return;
	}

	int cantidadEmpleados = 10000;
	empleado nuevoEmpleado;

	std::cout << "Generando Empleados por favor Espere\n";

	for (int i = 0; i < cantidadEmpleados; i++)
	{
		nuevoEmpleado.codigo = (rand() % cantidadEmpleados);
	}

}

bool Empleados::existeEmpleado(int codigo)
{
	std::fstream archivoEmpleados("empleados.bin", std::ios::in, std::ios::binary);

	if (!archivoEmpleados)
	{
		std::cout << "Error al intentar abrir el archivo";
		//return false;
	}

	std::cout << "*** Consulta Codigo ****\n\n";
	//posicionarnos al inicio del archivo; 

	archivoEmpleados.seekg(0, std::ios::beg);

	empleado actual;
	archivoEmpleados.read(reinterpret_cast<char*>(&actual), sizeof(empleado));

	while (!archivoEmpleados.eof())
	{
		if (actual.codigo == codigo)
		{
			archivoEmpleados.close();
			return true;
		}

		archivoEmpleados.read(reinterpret_cast<char*>(&actual), sizeof(empleado));
	}

	archivoEmpleados.close();
	return false;
}

void Empleados::lista()
{
	std::cout << "Hola\n";
	std::vector<int> l(10);

	for (int i = 0; i < 10; i++)
	{
		l.push_back((rand() % 10) + 1);

	}

	for (int n : l)
	{
		std::cout << n << "\n";
	}

	std::cout << "\n";
	//l.sort();
	//l.unique();

	//for (int n : l)
	//{
	//	std::cout << n << "\n";
	//}

	std::cout << "\nSize: " << l.size(); 
}