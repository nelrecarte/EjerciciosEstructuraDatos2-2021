#include <iostream>
#include "Header.h"
#include <vector>
#include "fileEntry.h"
#include "metaData.h"



int main()
{
	header func;
	int opcion;

	do
	{
		std::cout << "\n-Menu Principal-";
		std::cout << "\n1. Crear Disco";
		std::cout << "\n2. Cargar Disco";
		std::cout << "\n3. Salir\n";
		std::cin >> opcion;

		switch (opcion)
		{
		case 1:
			func.crearDisco();
			break;
		case 2:
			func.cargarDisco();

			do
			{
				std::cout << "\n-Disco-";
				std::cout << "\n1. Crear Dir";
				std::cout << "\n2. Listar";
				std::cout << "\n3. Salir\n";
				std::cin >> opcion;
				switch (opcion)
				{
				case 1:
					func.crearDirectorio();
					break;
				case 2:
					func.listar();
					break;
				case 3:
					break;
				}
			} while (opcion != 3);
			break;
		case 3:
			break;
		}
	} while (opcion != 3);

}

 