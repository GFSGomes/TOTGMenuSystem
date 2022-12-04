#pragma once
#include <iostream>
#include <conio.h>
#include "MenuSystem/GameMenu/GameMenu.h"

class Scene
{
	public:
	GameMenu gameMenu;
	bool leaveScene = false;


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