#pragma once
#include <iostream>
#include <conio.h>
extern bool leaveScene; // Referência à variável global em Scene.h


class LeaveGame
{
	private:

	public:


	LeaveGame()
	{

	}

	~LeaveGame()
	{

	}

	void Initialize()
	{
		bool confirm = false;
		char input = '\0';
		int index = 0;

		while (!confirm)
		{
			system("cls");
			switch (index)
			{
				case 0:
					std::cout << "\n";
					std::cout << " |LEAVE GAME\n";
					std::cout << " |  Are you sure?\n";
					std::cout << " |\n";
					std::cout << " '-> No\n";
					std::cout << "    Yes\n";
					break;

				case 1:
					std::cout << "\n";
					std::cout << " |LEAVE GAME\n";
					std::cout << " |  Are you sure?\n";
					std::cout << " |\n";
					std::cout << " |  No\n";
					std::cout << " '-> Yes, I'm afraid of the dark\n";
					break;
				default: break;
			}

			input = _getch();

			switch (input)
			{
				case 'w': case 'W': if (index > 0) index--; break;
				case 's': case 'S': if (index < 1) index++; break;
				case 27: confirm = true; break;
				case '\r':
				{
					switch (index)
					{
						case 0: confirm = true; break;
						case 1: leaveScene = true; confirm = true; break;
					}
					break;
				}
				default:break;
			}
		}
	}
};