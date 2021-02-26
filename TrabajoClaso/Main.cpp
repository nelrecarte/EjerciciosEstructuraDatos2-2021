#include "Empleados.h"
#include <conio.h>
#include <iostream>
#include <chrono>

using sys_clock = std::chrono::system_clock;
using sys_time = std::chrono::time_point<sys_clock>;

int main ()
{
	int opcion = 0;


	do
	{
		std::cout << "\n1. Generar Archivo\n";
		std::cout << "\n2. Busqueda Secuencial\n";
		std::cout << "\n3. Busqueda Binaria\n";
		std::cout << "\n4. Salir\n";
		std::cin >> opcion;

		switch (opcion)
		{
		case 1: 
			Empleados::generarEmpleados();

			break;
		case 2:
			sys_time start_time = sys_clock::now();
			Empleados::busquedaSecuencial();
			sys_time end_time = sys_clock::now();
			std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
			std::cout << "Load time: " << static_cast<double>(duration.count()) << "us\n";
			break;
		case 3:
			sys_time start_time = sys_clock::now();
			Empleados::busquedaBinaria();
			sys_time end_time = sys_clock::now();
			std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
			std::cout << "Load time: " << static_cast<double>(duration.count()) << "us\n";
			break;

		}
	} while (opcion != 4); 

	_getch();
}
