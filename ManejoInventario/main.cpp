#include <conio.h>
#include "Inventario.h"
#include <iostream>

int main()
{
    int opcion;

    do {
        std::cout << "1. Agregar productos"
            << "\n2. Consultar productos"
            << "\n3. Agregar compras"
            << "\n4. Agregar ventas"
            << "\n5. Salir\n";
        std::cout << "\nIngrese una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            Inventario::agregarProducto();
            break;

        case 2:
            Inventario::consultarProductos();
            break;

        case 3:
            Inventario::agregarCompra();
            break;

        case 4:
            Inventario::agregarVenta();
            break;

        case 5:
            std::cout << "Gracias!" << std::endl;
            break;

        default:
            std::cout << "Opción incorrecta!!" << std::endl;
            break;
        }
    } while (opcion != 5);


	_getch();
}