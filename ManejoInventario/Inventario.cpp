#include "Inventario.h"
#include <iostream>
#include <fstream>

void Inventario::agregarProducto()
{
	std::fstream archivoProductos("productos.bin", std::ios::out | std::ios::binary | std::ios::app);

	if (!archivoProductos)
	{
		std::cout << "Error al intentar abrir el archivo"; 
		return;

	}

	std::cout << "***   I N G R E S O   D E   P R O D U C T O S ***\n";

	std::cout << "Ingrese cuantos Productos desea agregar: ";
	int cantidad; 
	std::cin >> cantidad; 

	producto nuevo;
	
	for (int i = 0; i < cantidad; i++)
	{
		std::cout << "Ingrese codigo de producto: ";
		std::cin >> nuevo.codigo;

		std::cout << "Ingrese nombre de producto: ";
		std::cin >> nuevo.nombre;

		nuevo.existencias = 0; 
		nuevo.precioPromedio = 0;

		archivoProductos.write(reinterpret_cast<const char*>(&nuevo), sizeof(producto));

		std::cout << "Producto agregado correctamente!\n";

	}

	archivoProductos.close();
}

void Inventario::consultarProductos()
{
	std::fstream archivoProductos("productos.bin", std::ios::in, std::ios::binary);

	if (!archivoProductos)
	{
		std::cout << "Error al intentar abrir el archivo";
		return;
	}

	std::cout << "*** Consulta Productos ****\n\n"; 
	//posicionarnos al inicio del archivo; 

	archivoProductos.seekg(0, std::ios::beg);

	producto actual;
	archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));

	while (!archivoProductos.eof())
	{
		std::cout << "Producto { codigo: " << actual.codigo << ", nombre: " << actual.nombre << ", existencias: " << actual.existencias << ", precioPromedio: " << actual.precioPromedio << " }\n";

		archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));
	}

	archivoProductos.close();
}

void Inventario::agregarCompra()
{

	std::fstream archivoCompra("compras.bin", std::ios::out | std::ios::binary | std::ios::app);

	if (!archivoCompra)
	{
		std::cout << "Error al intentar abrir el archivo";
		return;

	}

	std::cout << "***   I N G R E S O   D E   C O M P R A S  ***\n";

	std::cout << "Ingrese cuantas Compras desea agregar: ";
	int cantidad;
	std::cin >> cantidad;

	compra nuevo;

	for (int i = 0; i < cantidad; i++)
	{
		std::cout << "Ingrese nombre de producto: ";
		std::cin >> nuevo.nombre;

		do
		{
			std::cout << "Ingrese codigo de producto: ";
			std::cin >> nuevo.codigo;

		} while (!existeProducto(nuevo.codigo));

		std::cout << "Ingrese precio de compra del producto: "; 
		std::cin >> nuevo.precioCompra;

		std::cout << "Ingrese la cantidad de compras: ";
		std::cin >> nuevo.cantidad;

		archivoCompra.write(reinterpret_cast<const char*>(&nuevo), sizeof(producto));
		std::cout << "Compra agregado correctamente!\n";

		//agregar en archivo de movimientos
		agregarMovimiento(nuevo.codigo, tipoMovimiento::Entrada, nuevo.cantidad, nuevo.precioCompra);

		//actualizar en archivo de productos
		actualizarProducto(tipoMovimiento::Entrada, nuevo.codigo, nuevo.cantidad, nuevo.precioCompra);

	}
	std::cout << "\n";
	archivoCompra.close();

}

void Inventario::agregarVenta()
{
	std::fstream archivoVentas("ventas.bin", std::ios::out | std::ios::binary | std::ios::app);

	if (!archivoVentas)
	{
		std::cout << "Error al abrir\n";
		return;

	}

	std::cout << "\n *** Ingreso de Ventas *** \n";
	std::cout << "Ingrese cuantas ventas desea hacer"; 
	int cantidad;
	std::cin >> cantidad;

	ventas nuevaVenta;

	for (int i = 0; i < cantidad; i++)
	{
		std::cout << "Ingrese Nombre Cliente: ";
		std::cin >> nuevaVenta.nombreCliente;

		do
		{
			std::cout << "Ingrese codigo del Producto: "; 
			std::cin >> nuevaVenta.codigoProducto;
		} while (!existeProducto(nuevaVenta.codigoProducto));

		std::cout << "Ingrese cantidad del Producto: "; 
		std::cin >> nuevaVenta.cantidad;

		std::cout << "Ingrese Precio de venta del Producto: "; 
		std::cin >> nuevaVenta.precioVenta;

		//escribir 
		archivoVentas.write(reinterpret_cast<const char*>(&nuevaVenta), sizeof(ventas));

		std::cout << "Venta realizada correctamente \n";

		agregarMovimiento(nuevaVenta.codigoProducto, tipoMovimiento::Salida, nuevaVenta.cantidad, nuevaVenta.precioVenta);

		actualizarProducto(tipoMovimiento::Salida, nuevaVenta.codigoProducto, nuevaVenta.cantidad, nuevaVenta.precioVenta);
	}

	std::cout << "\n";
	archivoVentas.close();
}

void Inventario::agregarMovimiento(int codigo, tipoMovimiento tipoM, int cantidad, float precio)
{
	std::fstream archivoMovimientos("inventario.bin", std::ios::out | std::ios::binary | std::ios::app);

	if (!archivoMovimientos)
	{
		std::cout << "Error al abrir archivo .bin\n";
		return;
	}

	movimiento nuevoMov; 
	nuevoMov.codigoProducto = codigo;
	nuevoMov.tipoMov = tipoM;
	nuevoMov.cantidadProducto = cantidad;
	nuevoMov.precio = precio;

	archivoMovimientos.write(reinterpret_cast<const char*>(&nuevoMov), sizeof(movimiento));
	std::cout << "Movimiento realizado correctamente!\n";

	archivoMovimientos.close();

}

bool Inventario::existeProducto(int codigo)
{
	std::fstream archivoProductos("productos.bin", std::ios::in, std::ios::binary);

	if (!archivoProductos)
	{
		std::cout << "Error al intentar abrir el archivo";
		//return false;
	}

	std::cout << "*** Consulta Productos ****\n\n";
	//posicionarnos al inicio del archivo; 

	archivoProductos.seekg(0, std::ios::beg);

	producto actual;
	archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));

	while (!archivoProductos.eof())
	{
		if (actual.codigo == codigo)
		{
			archivoProductos.close();
			return true;
		}

		archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));
	}

	archivoProductos.close();
	return false;
}

void Inventario::actualizarProducto(tipoMovimiento tipoM, int codigo, int existenciaNueva, float precio)
{
	std::fstream archivoProductos("productos.bin", std::ios::out | std::ios::in | std::ios::binary);
	
	if (!archivoProductos)
	{
		std::cout << "Error al intentar abrir el archivo.bin\n";
		return;
	}

	archivoProductos.seekg(0, std::ios::beg); //ubicarse al inicio

	producto actual; 
	long posicionActual = 0;

	//lear el primer registro y almacenarlo 
	archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));

	while (!archivoProductos.eof())
	{
		if (actual.codigo == codigo)
		{
			if (tipoM == tipoMovimiento::Entrada)
			{
				float precioPromedio = ((actual.existencias * actual.precioPromedio) + (existenciaNueva * precio)) / (actual.existencias + existenciaNueva);
				actual.existencias += existenciaNueva;
				actual.precioPromedio = precioPromedio;
			}
			else
			{
				actual.existencias -= existenciaNueva;
			}

			archivoProductos.seekp(posicionActual, std::ios::beg);
			archivoProductos.write(reinterpret_cast<char*>(&actual), sizeof(producto));
			archivoProductos.close();

			std::cout << "Producto actualizado exitosamente \n";
			return;
		}

		posicionActual = archivoProductos.tellg();
		archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));//ir leyendo los siguientes registros.
	}
	archivoProductos.close();

}