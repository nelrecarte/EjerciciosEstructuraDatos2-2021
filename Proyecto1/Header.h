#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

struct Header_info
{
	char name[20];
	unsigned int size;
	bool type;
	string date;
	int parent;
	int firstchild;
	int rightsibling;

};


class Consule
{
public:

	static void make_directory(string comand)
	{


	}

	static string get_time()
	{
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%d/%m/%Y \t %H:%M:%S");
		string str = oss.str();
		return str;
	}

	static string Comand(char comand[20])
	{
		string action, reader;
		int a = 0;
		for (int i = 0; i < 20; i++)
		{
			if (comand[i] != 32 && comand[i] != -52)
			{
				reader = reader + comand[i];
				a++;

				if (reader == "mkdir" && comand[i + 1] == 32)
				{
					action = "mkdir";
					cout << "\n" << action << "\n";
					system("pause");
					reader = "";
				}
				else if (reader == "cd" && comand[i + 1] == 32)
				{
					action = "cd";
					cout << "\n" << action << "\n";
					system("pause");
					reader = "";
				}
				else if (reader == "cd.." && comand[i + 1] == 32)
				{
					action = "cd..";
					cout << "\n" << action << "\n";
					system("pause");
					reader = "";
				}
				else if (reader == "rm" && comand[i + 1] == 32)
				{
					action = "rm";
					cout << "\n" << action << "\n";
					system("pause");
					reader = "";
				}
				else if (reader == "import" && comand[i + 1] == 32)
				{
					action = "import";
					cout << "\n" << action << "\n";
					system("pause");
					reader = "";
				}
				else if (reader == "export" && comand[i + 1] == 32)
				{
					action = "export";
					cout << "\n" << action << "\n";
					system("pause");
					reader = "";
				}

			}
		}
		return reader;
	}

	static void comand_prompt(string s)
	{
		char action[20];
		//cin.ignore();
		cin.getline(action, 20);
		strcpy(action, Comand(action).c_str());
		cin.ignore();
		cout << "\nProyecto@EstructuraDatos" << "/" << s << "/" << action << "~$";

	}

	static void Create_Disk(string comand)
	{
		string const disk1 = comand + ".bin";
		fstream Disk(disk1, ios::in | ios::binary | ios::app);
		Header_info info;

		if (!Disk)
		{
			cout << "\n\nError Creating the Disk!\n\n";
			return;
		}

		strcpy(info.name, disk1.c_str());
		info.firstchild = -1;
		info.parent = -1;
		info.rightsibling = -1;
		info.size = 0;
		info.type = false;
		info.date = get_time();
		Disk.write(reinterpret_cast<const char*>(&info), sizeof(Header_info));
		system("cls");
		cout << "\nProyecto@EstructuraDatos" << "/" << comand << "$";
		Disk.close();

	}

	static string inicialize_format()
	{
		char comand[20];
		cout << "\n\n\tCreate A Disk:\t";
		cin >> comand;
		cin.ignore();
		Create_Disk(comand);
		return comand;
	}


	Consule();
	~Consule();

private:

};
