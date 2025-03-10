#ifndef ESTANTE_HPP
#define ESTANTE_HPP

#include <vector>
#include <string>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Menu.hpp"

class Estante : public ObjetoDeJogo {
private:
    std::vector<std::string> itens; // Itens disponíveis na estante
    Menu* menu;                     // Menu de seleção de itens
    bool menuAberto;                 // Indica se o menu está aberto
    std::vector<Estante*> est;

public:
    // Construtor da estante que recebe uma lista de itens disponíveis
    Estante(std::string nome, std::string spritePath, COR::Cor cor, int x, int y, std::vector<std::string> itensDisponiveis) 
        : ObjetoDeJogo(nome, Sprite(spritePath, cor), x, y), itens(itensDisponiveis) 
    {
        menu = new Menu(cor, itens, 12, x, y);
    }

    // Destrutor para liberar a memória do menu
    ~Estante() {
        delete menu;
    }

    // Abre o menu de seleção de itens
    void abrirMenu() {
        menu->open();
    }

    // Fecha o menu de seleção
    void fecharMenu() {
        menu->close();
    }


    // Permite que o jogador escolha itens manualmente da estante
    std::string selecionarItem() {
     
            int opcao = menu->getSelectedOption();
            return itens[opcao];


    }
    // Atualiza o estado do menu, caso esteja aberto
    void update() override {
        if (menuAberto) {
            menu->update();
        }
    }

    void draw(SpriteBase &screen, int x, int y) override {
        if (active) {
            pSprite->draw(screen, x, y);
            if (menu->isOpen()) {
                int y_menu = getPosC() +2;
                int x_menu = getPosL() +6;
                menu->draw(screen, x_menu, y_menu);

            }
           
        }
    }

};

#endif // ESTANTE_HPP
