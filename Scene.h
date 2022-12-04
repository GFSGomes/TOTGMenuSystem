#pragma once
#include <iostream>
#include <conio.h>
#include "MenuSystem/GameMenu/GameMenu.h"

bool leaveScene = false; // Global

class Scene
{
	public:
	GameMenu gameMenu;


	Scene()
	{

	}
	~Scene()
	{

	}

	void LoadScene()
	{
		leaveScene = false;

		while (!leaveScene)
		{
			gameMenu.Header();

			std::cout << "\n   GRID AQUI\n";

			gameMenu.Body();
		}
	}
};