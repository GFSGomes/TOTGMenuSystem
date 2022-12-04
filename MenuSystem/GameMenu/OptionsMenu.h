#pragma once
#include <iostream>
#include <conio.h>

class OptionsMenu
{
	public:
	bool debugMode = false;

	OptionsMenu()
	{

	}

	~OptionsMenu()
	{

	}

	void Initialize()
	{
		bool optionsMenu = true;
		char input = '\0';
		int  index = 0;
		while (optionsMenu)
		{
			system("cls");
			switch (index)
			{
				case 0:
				{
					if (!debugMode)
					{
						std::cout << "\n";
						std::cout << " |OPTIONS\n";
						std::cout << " |\n";
						std::cout << " '-> Debug Mode [ON]\n";
						std::cout << "\n";
						std::cout << "    Back\n";
					}
					else 
					{
						std::cout << "\n";
						std::cout << " |OPTIONS\n";
						std::cout << " |\n";
						std::cout << " '-> Debug Mode [OFF]\n";
						std::cout << "  \n";
						std::cout << "    Back\n";
					}
					break;
				}

				case 1:
				{
					if (!debugMode)
					{
						std::cout << "\n";
						std::cout << " |OPTIONS\n";
						std::cout << " |\n";
						std::cout << " |  Debug Mode [ON]\n";
						std::cout << " |\n";
						std::cout << " '-> Back\n";
					}
					else
					{
						std::cout << "\n";
						std::cout << " |OPTIONS\n";
						std::cout << " |\n";
						std::cout << " |  Debug Mode [OFF]\n";
						std::cout << " |\n";
						std::cout << " '-> Back\n";
					}
					break;
				}

				default: break;
			}

			input = _getch();

			switch (input)
			{
				case 'w': case 'W': if (index > 0) index--; break;
				case 's': case 'S': if (index < 1) index++; break;
				case 27: optionsMenu = false; break;
				case '\r':
				{
					switch (index)
					{
						case 0: debugMode = !debugMode; break;
						case 1: optionsMenu = false; break;
						default: break;
					}
				} break;
				default: break;
			}
		}
	};
};