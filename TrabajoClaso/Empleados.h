#pragma once
#ifndef EMPLEADOS_H
#define EMPLEADOS_H

struct empleado
{
	int codigo;
	char nombre[20];
	double salario;
	bool estado;
};

class Empleados
{

public: 
	static void generarEmpleados();
	
	static void busquedaSecuencial();
	static void busquedaBinaria();


};

#endif // !EMPLEADOS_H
