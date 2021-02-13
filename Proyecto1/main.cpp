#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include<fstream>
#include<string>
#include<iostream>
#include<fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Header.h"

using namespace std;



int main()
{
	Header_info disk;

	strcpy(disk.name, Consule::inicialize_format().c_str());
	do
	{
		Consule::comand_prompt(disk.name);

	} while (true);


}