#include "FaseLevel1.hpp"

#include <iostream>

void FaseLevel1::init()
{	

	Mesa = new ObjetoDeJogo("frontDoor",Sprite("rsc/mesa.txt",COR::BRANCA),61,8);
	objs.push_back(Mesa);

	Mesa = new ObjetoDeJogo("frontDoor",Sprite("rsc/mesa.txt",COR::BRANCA),61,60);
	objs.push_back(Mesa);

	Balcao = new ObjetoDeJogo("frontDoor",Sprite("rsc/balcao.txt",COR::BRANCA),45,180);
	objs.push_back(Balcao);

	int DISTANCIA_ESTANTES = 50;

	//Estante_bebidas = new ObjetoDeJogo("frontDoor",Sprite("rsc/estante_bebidas.txt",COR::BRANCA),2,10);
	//objs.push_back(Estante_bebidas);

	//Estante_doces = new ObjetoDeJogo("frontDoor",Sprite("rsc/estante_doces.txt",COR::BRANCA),2,10+ DISTANCIA_ESTANTES);
	//objs.push_back(Estante_doces);

	//Estante_frios = new ObjetoDeJogo("frontDoor",Sprite("rsc/estante_frios.txt",COR::BRANCA),2, 10+(2*DISTANCIA_ESTANTES));
	//objs.push_back(Estante_frios);

	//Estante_frutas = new ObjetoDeJogo("frontDoor",Sprite("rsc/estante_frutas.txt",COR::BRANCA),2,10+(3*DISTANCIA_ESTANTES));
	//objs.push_back(Estante_frutas);

	//Estante_massas = new ObjetoDeJogo("frontDoor",Sprite("rsc/estante_massas.txt",COR::BRANCA),2,10+(4*DISTANCIA_ESTANTES));
	//objs.push_back(Estante_massas);

	//Menu = new ObjetoDeJogo("frontDoor",Sprite("rsc/cardapio.txt",COR::BRANCA),2,10+(5*DISTANCIA_ESTANTES));
	//objs.push_back(Menu);
	
	 // new ObjetoDeJogo("frontDoor",Sprite("rsc/bonsai.txt",COR::VERDE),17,300);
	//objs.push_back(new ObjetoDeJogo("frontDoor",Sprite("rsc/bonsai.txt",COR::VERDE),17,300));

	
	Personagem_feminina = new Cozinheira(ObjetoDeJogo("Feminina",SpriteAnimado("rsc/personagem_feminina.txt",1,COR::ROSA),25,285));
	objs.push_back(Personagem_feminina);
	
	
	Cadeira = new ObjetoDeJogo("frontDoor",Sprite("rsc/cadeira.txt",COR::BRANCA),50,28);
	objs.push_back(Cadeira);

	
	//Personagem_sheipado = new Cliente(ObjetoDeJogo("frontDoor",SpriteAnimado("rsc/personagem_masculino.txt",1,COR::MARROM),43,28));
	//objs.push_back(Personagem_sheipado);
	
	Cadeira = new ObjetoDeJogo("frontDoor",Sprite("rsc/cadeira.txt",COR::BRANCA),49,75);
	objs.push_back(Cadeira);

	int DISTANCIA_COMIDAS= 40;

	Pizza = new ObjetoDeJogo("frontDoor",Sprite("rsc/pizza.txt",COR::BRANCA),58,190);
	objs.push_back(Pizza);

	Pie = new ObjetoDeJogo("frontDoor",Sprite("rsc/torta.txt",COR::BRANCA),56,215 + DISTANCIA_COMIDAS);
	objs.push_back(Pie);

	Coffe = new ObjetoDeJogo("frontDoor",Sprite("rsc/coffe.txt",COR::BRANCA),54,220 + (2*DISTANCIA_COMIDAS));
	objs.push_back(Coffe);

	Bread = new ObjetoDeJogo("frontDoor",Sprite("rsc/bread.txt",COR::BRANCA),58,98 + (3*DISTANCIA_COMIDAS));
	objs.push_back(Bread);

	Cake = new ObjetoDeJogo("frontDoor",Sprite("rsc/cake.txt",COR::BRANCA),56,180 + (4*DISTANCIA_COMIDAS));
	objs.push_back(Cake);

	Mesa_cliente = new ObjetoDeJogo("frontDoor",Sprite("rsc/cliente_mesa.txt",COR::BRANCA),48,115);
	objs.push_back(Mesa_cliente);
	Mesa_cliente->ativarObj();

	Panela1 = new ObjetoDeJogo("frontDoor",Sprite("rsc/panela_1.txt",COR::BRANCA),44,190);
	objs.push_back(Panela1);

	Pnaela2= new ObjetoDeJogo("frontDoor",Sprite("rsc/panela_2.txt",COR::BRANCA),39,240);
	objs.push_back(Pnaela2);

	Panela1 = new ObjetoDeJogo("frontDoor",Sprite("rsc/panela_1.txt",COR::BRANCA),44,260);
	objs.push_back(Panela1);

	Sofa = new ObjetoDeJogo("frontDoor",Sprite("rsc/sofa.txt",COR::BRANCA),2,340);
	objs.push_back(Sofa);

	Tapete = new ObjetoDeJogo("frontDoor",Sprite("rsc/tapete.txt",COR::BRANCA),16,319);
	objs.push_back(Tapete);
}


unsigned FaseLevel1::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
	
	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		
		 //processando entradas
		
		if (ent == "w" )
			Personagem_feminina->moveUp(6);
		else if (ent == "s" )
			Personagem_feminina->moveDown(6);
		else if (ent == "a")
			Personagem_feminina->moveLeft(6);
		else if (ent == "d")
     		Personagem_feminina->moveRight(6);

		else if(ent== "e" && Personagem_feminina->colideComBordas(*Personagem_sheipado) )
			 Personagem_sheipado->fazerpedido();

		


		/*else if (ent == "x") {
			for (int g = 0 ; g < 2 ; g++)
				if (hero->colideComBordas(*guardas[g])) {
					guardas[g]->sofrerAtaque(hero->atacar());
					if (!guardas[g]->isAlive())
						guardas[g]->desativarObj();
				}
		}
		else if (ent == "q")
			return Fase::END_GAME;
			

		if (colideComBloco())
			hero->moveTo(posL,posC);
		
		
		//processando eventos
		for (int g = 0 ; g < 2 ; g++)
				if (hero->colideComBordas(*guardas[g])) {
					hero->sofrerAtaque(guardas[g]->atacar());
					
					if (!hero->isAlive())
						return Fase::GAME_OVER;
					
					life->setText(std::string(hero->getLife()/5,'#'));
				}
		
		if (hero->colideComBordas(*chave))
		{
			chave->desativarObj();
			miniChave->ativarObj();
			hero->pegarChave();
		}
		else if (hero->colideComBordas(*tapetePorta) && hero->possuiChave())
		{
			porta->openTheDoor();
		}
		else if (hero->colideComBordas(*princesa))
		{
			princesa->desativarObj();
			hero->salvarPrincesa();
		}
		else if (hero->colideComBordas(*portao) && hero->salvouPrincesa())
		{
			return Fase::LEVEL_COMPLETE;
		}
		*/
		
		//padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);
	}
	
	return Fase::END_GAME; // não necessário
}

