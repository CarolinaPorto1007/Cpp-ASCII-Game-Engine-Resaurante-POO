	#ifndef FASELEVEL1_HPP
	#define FASELEVEL1_HPP

	#include "../ASCII_Engine/Fase.hpp"
	#include <string>
	#include <list>

	#include "Menu.hpp"
	#include "Cozinheira.hpp"
	#include "Cliente.hpp"
	#include "../ASCII_Engine/ObjetoDeJogo.hpp"
	#include "Estante.hpp"


	class FaseLevel1 : public Fase
	{
	public:
	FaseLevel1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel1() {}


	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

	bool colideComBloco() const;

	private:

	std::vector<Estante*> est;
	
	bool moddo_selecao=false;

    ObjetoDeJogo *Mesa;
	ObjetoDeJogo *Balcao;
	Estante *Estante_frios;
	Estante *Estante_doces;
	Estante *Estante_massas;
	Estante *Estante_bebidas;
	Estante *Estante_frutas;
	ObjetoDeJogo *Menu1;
	Cozinheira   *Personagem_feminina;
	Cliente      *Personagem_sheipado;
	ObjetoDeJogo *Bonsai;
	ObjetoDeJogo *Cadeira;
	ObjetoDeJogo *Mesa_cliente;
	ObjetoDeJogo *Coffe;
	ObjetoDeJogo *Bread;
	ObjetoDeJogo *Cake;
	ObjetoDeJogo *Pie;
	ObjetoDeJogo *Pizza;
	ObjetoDeJogo *Copo;
	ObjetoDeJogo *Biscoito_doce;
	ObjetoDeJogo *Panela1;
	ObjetoDeJogo *Pnaela2;
	ObjetoDeJogo *Personagem_masculino;
	ObjetoDeJogo *Sofa;
	ObjetoDeJogo *Tapete;

	};

	#endif // FASELEVEL1_HPP
