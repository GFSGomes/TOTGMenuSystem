#pragma once
#include <iostream>
#include <conio.h>
#include "CharacterMenu.h"
#include "InventoryMenu.h"
#include "AbilitiesMenu.h"
#include "OptionsMenu.h"
#include "LeaveGame.h"

class GameMenu
{
	public:
	bool pauseGame = false;
	CharacterMenu characterMenu;
	InventoryMenu inventoryMenu;
	AbilitiesMenu abilitiesMenu;
	OptionsMenu optionsMenu;
	LeaveGame leaveGame;

	private:
	int index = 0;
	char input = '\0';


	public: 
	GameMenu()
	{

	}
	~GameMenu()
	{

	}


	void Header()
	{
		system("cls");
		if (!pauseGame)
		{
			std::cout << "\n";
			std::cout << " |[M]MENU|Pause \n";
			std::cout << "\n";
		}
		else
		{
			switch (index)
			{
				case 0:
				{
					std::cout << "\n";
					std::cout << " |[M]MENU|Resume\n";
					std::cout << " '-> Character\n";
					std::cout << "    Inventory\n";
					std::cout << "    Abilities\n";
					std::cout << "    Options\n";
					std::cout << "    Leave Game\n";
				} break;			   
									   
				case 1:				   
				{					   
					std::cout << "\n";
					std::cout << " |[M]MENU|Resume\n";
					std::cout << " |  Character\n";
					std::cout << " '-> Inventory\n";
					std::cout << "    Abilities\n";
					std::cout << "    Options\n";
					std::cout << "    Leave Game\n";
				} break;			   
									   
				case 2:				   
				{					   
					std::cout << "\n";
					std::cout << " |[M]MENU|Resume\n";
					std::cout << " |  Character\n";
					std::cout << " |  Inventory\n";
					std::cout << " '-> Abilities\n";
					std::cout << "    Options\n";
					std::cout << "    Leave Game\n";
				} break;			   
									   
				case 3:				   
				{					   
					std::cout << "\n";
					std::cout << " |[M]MENU|Resume\n";
					std::cout << " |  Character\n";
					std::cout << " |  Inventory\n";
					std::cout << " |  Abilities\n";
					std::cout << " '-> Options\n";
					std::cout << "    Leave Game\n";
				} break;			   
									   
				case 4: 			   
				{					   
					std::cout << "\n";
					std::cout << " |[M]MENU|Resume\n";
					std::cout << " |  Character\n";
					std::cout << " |  Inventory\n";
					std::cout << " |  Abilities\n";
					std::cout << " |  Options\n";
					std::cout << " '-> Leave Game\n";
				} break;

				default: break;
			}
		}
	}

	void Body()
	{
		std::cout << "\n";
		std::cout << "     |W|   To          [T] Lit Torch\n";
		std::cout << "   [A|S|D] Move\n";

		input = _getch();

		// Player Input:
		if (!pauseGame)
		{
			switch (input)
			{
				case 27: case 'm': case 'M': pauseGame = !pauseGame; break;
				default: break;
			}
		}

		// Paused Game:
		else
		{
			switch (input)
			{
				case 27: case 'm': case 'M': pauseGame = !pauseGame; break;
				case 'w': case 'W': if (index > 0) index--; break;
				case 's': case 'S': if (index < 4) index++; break;
				case '\r':
					switch (index)
					{
						case 0: break;
						case 1: break;
						case 2: break;
						case 3: optionsMenu.Initialize(); break;
						case 4: leaveGame.Initialize();  break;
						default: break;
					} break;
				default: break;
			}
		}
		
	}
};