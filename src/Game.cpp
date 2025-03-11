#include "Game.hpp"

#include "../ASCII_Engine/Fase.hpp"
//#include "FaseTeste.hpp"
#include "FaseMenu.hpp"
#include "FaseLevel1.hpp"

/*
#include "FaseMenu.hpp"
#include "FaseLevel1.hpp"
#include "FaseAjuda.hpp"
#include "FaseGameOver.hpp"
#include "FaseLevelComplete.hpp"
*/

#include <iostream>

SpriteBuffer Game::screen(419,80);

void Game::run()
{
	FaseMenu fase("FaseMenu",Sprite("rsc/restaurante.txt")); 
	fase.init();
	unsigned state = Fase::MENU;
	unsigned level = Fase::LEVEL_1;
	while (state != Fase::END_GAME)
	{
		switch (state)
		{
			case Fase::MENU:
				state = fase.run(screen);
				level = Fase::LEVEL_1;
				break;
			case Fase::OP_1:
				{
					if (level == Fase::LEVEL_1)
					{
						FaseLevel1 level1("Level1",Sprite("rsc/restaurante.txt"));
						level1.init();
						state = level1.run(screen);
					} 
					else
						state = Fase::MENU;
				}
				break;
			case Fase::OP_2:
		

					system("clear");
					std::cout << "Saindo...\n";
					system("sleep 1");
					state = Fase::END_GAME;
					break;


			case Fase::OP_3:
					{//FaseAjuda faseAjuda("FaseAjuda",Sprite("rsc/background.img"));
					//faseAjuda.init();
					//state = faseAjuda.run(screen);
					}
				break;
			case Fase::LEVEL_COMPLETE:
				{ //TERMINO DO JOGO - MOSTRA ALGO
					//FaseLevelComplete faseLC("FaseLC",Sprite("rsc/background.img"));
					//faseLC.init();
					//state = faseLC.run(screen);
					//level++;
					//state = Fase::OP_1;
				}
				break;
			case Fase::GAME_OVER:
				{//TELA QUANDO A PESSOA PERDE
					//FaseGameOver faseGO("FaseGO",Sprite("rsc/background.img"));
					//faseGO.init();
					//state = faseGO.run(screen);
				}
				break;
		}
	}
}
