#include <iostream>
#include "Header.h"
#include <vector>
#include "fileEntry.h"
#include "metaData.h"



int main()
{
	header func;
	int opcion;
	char comando[20];

	do
	{
		std::cout << "\n-Menu Principal-";
		std::cout << "\n1. Crear Disco";
		std::cout << "\n2. Cargar Disco";
		std::cout << "\n3. Salir\n";
		std::cout << "\nOpcion: ";
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
				std::cout << "\n\t-Comandos";
				std::cout << "\n\tmkdir";
				std::cout << "\n\tls";
				std::cout << "\n\trm";
				std::cout << "\n\tImport";
				std::cout << "\n\t cd ";
				std::cout << "\n\nOpcion: ";
				std::cin >> comando;
				opcion = header::Comand(comando);

				switch (opcion)
				{
				case 1:
					func.crearDirectorio();
					break;
				case 2:
					func.listar();
					break;
				case 3:
					func.eliminar();
					break;
				case 4:
					func.importFile();
					break;
				case 5:
					break;
				}
			} while (opcion != 5);
			break;
		case 3:
			break;
		}
	} while (opcion != 3);

}
