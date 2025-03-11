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

	
	Personagem_feminina = new Cozinheira(ObjetoDeJogo("Feminina",SpriteAnimado("rsc/personagem_feminina.txt",1,COR::ROSA),25,285));
	objs.push_back(Personagem_feminina);
	
	
	Cadeira = new ObjetoDeJogo("frontDoor",Sprite("rsc/cadeira.txt",COR::BRANCA),50,28);
	objs.push_back(Cadeira);

	
	Personagem_sheipado = new Cliente(ObjetoDeJogo("frontDoor",SpriteAnimado("rsc/personagem_shape.txt",1,COR::MARROM),43,28));
	objs.push_back(Personagem_sheipado);
	
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

	Bonsai= new ObjetoDeJogo("frontDoor",Sprite("rsc/bonsai.txt",COR::VERDE),17,300);
	objs.push_back(new ObjetoDeJogo("frontDoor",Sprite("rsc/bonsai.txt",COR::VERDE),17,368));

	Estante_bebidas = new Estante("Estante de Bebidas", "rsc/estante_bebidas.txt", COR::BRANCA, 2, 10, {"Suco", "Cafe"});
	est.push_back(Estante_bebidas);
	objs.push_back(Estante_bebidas);

	Estante_doces = new Estante("Estante de Doces", "rsc/estante_doces.txt", COR::BRANCA, 2, 10 + DISTANCIA_ESTANTES, 
		{"Bolo", "Torta_doce", "Biscoito_doce"});
	est.push_back(Estante_doces);
	objs.push_back(Estante_doces);

	
	Estante_frios = new Estante("Estante de Frios", "rsc/estante_frios.txt", COR::BRANCA, 2, 10 + (2 * DISTANCIA_ESTANTES),
		{"Sorvete"});
		est.push_back(Estante_frios);
		objs.push_back(Estante_frios);
	
	Estante_frutas = new Estante("Estante de Frutas", "rsc/estante_frutas.txt", COR::BRANCA, 2, 10 + (3 * DISTANCIA_ESTANTES),
		{"Banana", "Maca", "Pera", "Uva"});
		est.push_back(Estante_frutas);
		objs.push_back(Estante_frutas);
	
	Estante_massas = new Estante("Estante de Massas", "rsc/estante_massas.txt", COR::BRANCA, 2, 10 + (4 * DISTANCIA_ESTANTES),
		{"Pizza", "Sanduiche", "Torta salgada"});
		est.push_back(Estante_massas);
		objs.push_back(Estante_massas);
	

	Menu1 = new ObjetoDeJogo("frontDoor",Sprite("rsc/cardapio.txt",COR::BRANCA),2,10+(5*DISTANCIA_ESTANTES));
	objs.push_back(Menu1);

	

	//std::vector<std::string> bebidas;
	//bebidas.push_back("Suco");
	//bebidas.push_back("Cafe");

	//Menu *menu= new Menu(COR::BRANCA,bebidas,11,13,12);
	//menu->open();
	//objs.push_back(menu);




	
}


unsigned FaseLevel1::run(SpriteBuffer &screen)
{
    std::string ent;
   
    // Padrão de inicialização
    screen.clear();
    draw(screen);
    system("clear");
    show(screen);

	moddo_selecao= false;
	Sound backMusic("rsc/sound/game-music-loop-19-153393.mp3");
	backMusic.playloop();


    while (true)
    {
        // Lendo entrada do usuário
        getline(std::cin, ent);

		if(moddo_selecao){
			if(ent== "w") {estante->moveup();}
			if(ent=="s") {estante->movedown();}
			//if(ent== "a"|| ent=="d"){estante->fecharMenu();}
			if(ent== "f"){
				estante->fecharMenu();
				moddo_selecao=false;
			}
			if(ent== "c"){
				comida=estante->selecionarItem();
				Personagem_feminina->pegarComida(comida);
				moddo_selecao=false;
				estante->fecharMenu();
			}
		}
	// Movimentação do personagem

		else{
			if (ent == "w" && !Personagem_feminina->colideComBordas(*Balcao))
				Personagem_feminina->moveUp(6);
			else if (ent == "s")
				Personagem_feminina->moveDown(6);
			else if (ent == "a")
				Personagem_feminina->moveLeft(6);
			else if (ent == "d")
				Personagem_feminina->moveRight(6);

			// Cozinheira faz o pedido do cliente
			if (ent == "e" && Personagem_feminina->colideComBordas(*Personagem_sheipado))
				Personagem_sheipado->fazerpedido();

		
			else if (ent == "e") {
				for (Estante* e : est) { // Verifica todas as estantes
					if (Personagem_feminina->colideComBordas(*e)) {
						e->abrirMenu();
						moddo_selecao=true;
						estante= e;

					}
				}
			}
			if (ent == "o" && Personagem_feminina->colideComBordas(*Personagem_sheipado)){
				Personagem_feminina->entregarPedido(*Personagem_sheipado);
				
				break;
				//Personagem_sheipado->conferirPedido();
			}

				
		}
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);			
		
	}	
update();
screen.clear();
draw(screen);
system("clear");
show(screen);	
system("sleep 3");
backMusic.stop();
return Fase::MENU;

}        
       

   



