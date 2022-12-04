#pragma once
#include <iostream>
#include <conio.h>
#include "../Scene.h"

class MainMenu
{
	bool applicationQuit = false;
	bool debug = false;
	char input = '\0';
	int index = 0;

	Scene scene_01;

	public:
	MainMenu()
	{

	}
	~MainMenu()
	{

	}

	void ResetInput() // É saudável resetar estas variáveis a cada mudança de menu.
	{
		input = '\0';
		index = 0;
	}

	void StartGame()
	{
		scene_01.LoadScene();
	}

	void Options()
	{
		ResetInput();
		bool mainMenu_options = true;

		while (mainMenu_options)
		{
			system("cls");
			switch (index)
			{
				case 0:
					std::cout << "\n";
					std::cout << " |OPTIONS\n";
					std::cout << " |\n";

					if (debug)
					std::cout << " '-> Debug Mode [ON]\n";
					else 
					std::cout << " '-> Debug Mode [OFF]\n";
					std::cout << "    Back\n";
					break;

				case 1:
					std::cout << "\n";
					std::cout << " |OPTIONS\n";
					std::cout << " |\n";

					if(debug)
					std::cout << " |  Debug Mode [ON]\n";
					else 
					std::cout << " |  Debug Mode [OFF]\n";
					std::cout << " '-> Back\n";
					break;

				default: break;
			}

			input = _getch();

			switch (input)
			{
				case 'w': case 'W': if (index > 0) index--; break;
				case 's': case 'S': if (index < 1) index++; break;
				case 27: mainMenu_options = false; break;
				case '\r':
					switch (index)
					{
						case 0: debug = !debug; break;
						case 1: mainMenu_options = false; break;
						default: break;
					}
					break;
				default: break;
			}
		}
	}

	void QuitGame()
	{
		ResetInput();
		bool mainMenu_quitGame = true;

		while (mainMenu_quitGame)
		{
			system("cls");
			switch (index)
			{
				case 0: 
					std::cout << "\n";
					std::cout << " |ARE YOU SURE?\n";
					std::cout << " |\n";
					std::cout << " '-> NO\n";
					std::cout << "    YES\n";
					break;

				case 1: 
					std::cout << "\n";
					std::cout << " |ARE YOU SURE?\n";
					std::cout << " |\n";
					std::cout << " |  NO\n";
					std::cout << " '-> YES\n";
					break;

				default: break;
			}

			input = _getch();

			switch (input)
			{
				case 'w': case 'W': if (index > 0) index--; break;
				case 's': case 'S': if (index < 1) index++; break;
				case 27: mainMenu_quitGame = false; break;
				case '\r':
					switch (index)
					{
						case 0: mainMenu_quitGame = false; break;
						case 1:
							applicationQuit = true;     //<-- Quebrar o loop principal não basta;
							mainMenu_quitGame = false;  //<-- Deve-se quebrar também este loop.
							break;
						default: break;
					}
					break;
				default: break;
			}
		}
	}

	public: 
	void Initialize()
	{
		while (!applicationQuit)
		{
			system("cls");
			switch (index)
			{
				case 0: 
					std::cout << "\n";
					std::cout << " |TOMB OF THE GIANTS\n";
					std::cout << " |\n";
					std::cout << " '-> Start Game\n";
					std::cout << "    Options\n";
					std::cout << "    Quit Game\n";
					break;

				case 1:
					std::cout << "\n";
					std::cout << " |TOMB OF THE GIANTS\n";
					std::cout << " |\n";
					std::cout << " |  Start Game\n";
					std::cout << " '-> Options\n";
					std::cout << "    Quit Game\n";
					break;

				case 2:
					std::cout << "\n";
					std::cout << " |TOMB OF THE GIANTS\n";
					std::cout << " |\n";
					std::cout << " |  Start Game\n";
					std::cout << " |  Options\n";
					std::cout << " '-> Quit Game\n";
					break;

				default: break;
			}

			input = _getch();

			switch (input)
			{
				case 'w': case 'W': if (index > 0) index--; break;
				case 's': case 'S': if (index < 2) index++; break;
				case '\r': 
					switch (index)
					{
						case 0: StartGame();break;
						case 1: Options();  break;
						case 2: QuitGame(); break;
						default: break;
					}
					break;

				default: break;
			}
		}
	}
};