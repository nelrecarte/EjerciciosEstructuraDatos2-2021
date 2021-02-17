#pragma once
#include <ctime>
#include <string>

struct fileEntry
{
	char name[30];
	char type;
	int size;
	int padre;
	int hijo;
	int nextSibling;
	int primerBloq;
	bool available;
};

