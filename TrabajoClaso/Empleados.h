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
	static bool existeEmpleado(int);


	static void lista();


};

#endif // !EMPLEADOS_H
