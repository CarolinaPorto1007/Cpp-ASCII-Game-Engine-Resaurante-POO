#ifndef GAME_HPP
#define GAME_HPP

#include "FaseLevel1.hpp"
#include "FaseStart.hpp"
#include "FaseFinal.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/SpriteAnimado.hpp"
#include "../ASCII_Engine/Cores.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
		SpriteBuffer buffer(419,80);
	
		FaseLevel1 fase1("Fase1",Sprite("rsc/restaurante.txt",COR::BRANCA));
		
		
		buffer.clear();
		fase1.init();
		int ret1 = fase1.run(buffer);
		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
		
			buffer.clear();
		}
		else
			std::cout << "GAME OVER" << std::endl;
		
		std::cout << "Saindo..." << std::endl;
	}

};

#endif // GAME_HPP
