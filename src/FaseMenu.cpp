#include "../ASCII_Engine/TextSprite.hpp"
#include "../ASCII_Engine/Sound.hpp"
#include "FaseMenu.hpp"
#include <string>
#include <iostream>

void FaseMenu::init()
{
	//crio objetos de jogo aqui

	objs.push_back(new ObjetoDeJogo("Fundo",Sprite("rsc/restaurante.txt"),0,0));
	objs.push_back(new ObjetoDeJogo("Titulo",Sprite("rsc/bem_vindo.txt"),6,141));
	objs.push_back(new ObjetoDeJogo("capa",Sprite("rsc/capa_projeto.txt"),16,141));
	objs.push_back(new ObjetoDeJogo("regras",Sprite("rsc/regras.txt"),20,186));                                                                            
	//objs.push_back(new ObjetoDeJogo("TextGame",TextSprite("The ASCII Rescue Game"),20,68));
	objs.push_back(new ObjetoDeJogo("Text----",TextSprite("-----------------------"),35,210)); //21,67
	objs.push_back(new ObjetoDeJogo("MenuOp1",TextSprite("Start Game"),38,217)); //23,74
	objs.push_back(new ObjetoDeJogo("MenuOp3",TextSprite("Sair"),40,220)); //27,77
	
	objs.push_back(new ObjetoDeJogo("SelOpE",TextSprite("---->"),38,209)); //23,66
	pSelE = objs.back();
	objs.push_back(new ObjetoDeJogo("SelOpD",TextSprite("<----"),38,230)); //23,87
	pSelD = objs.back();
	
	op = Fase::OP_1;

}

unsigned FaseMenu::run(SpriteBuffer &screen)
{
	

	std::string ent;
	
	//Sound backMusic("rsc/sounds/Techno2.mp3");
	//backMusic.playloop();
	
	system("clear");
	this->draw(screen);
	this->show(screen);
	
	while (true)
	{
		getline(std::cin, ent);
		//logica da fase acontece aqui
		//getline(std::cin,ent);
		if (ent == "q") break;
		else if (ent == "s") {
			op = Fase::OP_1 + (op - Fase::OP_1  + 1) % 2;
			
			pSelE->moveTo(38 + (op - Fase::OP_1) * 2, 209);
			pSelD->moveTo(38 + (op - Fase::OP_1) * 2, 230);
		}
		else if (ent == "w") {
			op = Fase::OP_1 + (3 + ((op - Fase::OP_1) - 1)) % 2;
			
			pSelE->moveTo(38 + (op - Fase::OP_1) * 2, 209);
			pSelD->moveTo(38 + (op - Fase::OP_1) * 2, 230);
		}
		else if (ent == "x")
		{
			//backMusic.stop();
			return op;
		}
			
		
		system("clear");
		this->update();
		this->draw(screen);
		this->show(screen);
		
		//system("sleep .2");
	}
	//backMusic.stop();
	return Fase::END_GAME;
}
