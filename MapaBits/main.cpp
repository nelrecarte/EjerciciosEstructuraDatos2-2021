
#include <conio.h>
#include <iostream>

#define DB_AMOUNT 100

void initBitMap(char*);
void printbitMap(char*);
void setOn(char*, int);
void setOff(char*, int);

int main()
{
	char* bitmap; 

	//Reserva de memoria para bitMap
	bitmap = new char[DB_AMOUNT / 8];

	initBitMap(bitmap);
	printbitMap(bitmap);

	int numeroBloque = 0;
	std::cout << "\nIngrese numero de bloque a encender: ";
	std::cin >> numeroBloque;

	setOn(bitmap, numeroBloque);

	printbitMap(bitmap);

	std::cout << "\nIngrese numero de bloque a encender: ";
	std::cin >> numeroBloque;

	setOn(bitmap, numeroBloque);

	printbitMap(bitmap);

	std::cout << "\nIngrese numero de bloque a apagar: ";
	std::cin >> numeroBloque;

	setOff(bitmap, numeroBloque);

	printbitMap(bitmap);

	_getch();
}

void initBitMap(char* bitMap)
{

	for (int i = 0; i < DB_AMOUNT / 8; i++)
	{
		bitMap[i] = 0; 
	}

}

void printbitMap(char* bitMap)
{
	const int SHIFT = 8 * sizeof(char) - 1;
	const char MASK = 1 << SHIFT; 
	
	for (int i = 0; i < DB_AMOUNT / 8; i++)
	{
		char tmpByte;
		tmpByte = bitMap[i];

		for (int j = 1; j <= SHIFT + 1; j++)
		{
			std::cout << (tmpByte & MASK ? '1' : '0');

			//corrimiento de bit hacia la izquierda de 1 bit 
			tmpByte <<= 1;

			if (j % 8 == 0)
			{
				std::cout << ' ';
			}
		}
	}
}

void setOn(char* bitMap, int nBlock)
{
	int posicionByte = nBlock / 8; 
	int posicionInicial = (nBlock / 8) * 8;

	for (int i = posicionInicial, x = 7; i < (posicionByte * 8) + 8; i++, x--)
	{
		if (i == nBlock)
		{
			bitMap[posicionByte] = bitMap[posicionByte] | (1 << x);
			break;
		}
	}
}

void setOff(char* bitMap, int nBlock)
{
	int posicionByte = nBlock / 8;
	int posicionInicial = (nBlock / 8) * 8;

	for (int i = posicionInicial, x = 7; i < (posicionByte * 8) + 8; i++, x--)
	{
		if (i == nBlock)
		{
			bitMap[posicionByte] = bitMap[posicionByte] & ~(1 << x);
			break;
		}
	}
}