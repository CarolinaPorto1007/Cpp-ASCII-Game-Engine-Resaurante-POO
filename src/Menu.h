#ifndef JOGO_WAR_MENU_H
#define JOGO_WAR_MENU_H

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/TextSprite.hpp"
#include <vector>


class Menu : public ObjetoDeJogo {
public:
    Menu(COR::Cor corMenu, std::vector<std::string> opcoes, int largura, int x = 0, int y = 0) 
        : MAX(opcoes.size()), ObjetoDeJogo("Menu de Ação", SpriteBuffer(largura, opcoes.size() + 2), y, x), 
          selectedOption(0) {
            std::string linha = "+";
            std::string meio = "|";
            for (int i = 1; i < largura - 1; i++) {
                linha += "-";
                meio += " ";
            }
            linha += "+";
            meio += "|";
            for (int i = 1; i < MAX + 1; i++)
                TextSprite(meio, corMenu).draw(*pSprite, i, 0);

            TextSprite(linha, corMenu).draw(*pSprite, 0, 0);
            TextSprite(linha, corMenu).draw(*pSprite, MAX + 1, 0);

            for (int i = 0; i < opcoes.size(); i ++)
                TextSprite(opcoes[i], corMenu).draw(*pSprite, 1 + i, 4);
            
            close();
        }

    void update() override {
        if (active) {
            for (int i = 0; i < MAX; i++) {
                TextSprite(" ").draw(*pSprite, 1 + i, 2);
            }
            TextSprite(">", COR::BRANCA).draw(*pSprite, 1 + selectedOption, 2);
        }
    }

    void moveDown() { selectedOption = (selectedOption + 1) % MAX; }
    void moveUp() { selectedOption = (selectedOption == 0 ? MAX - 1 : selectedOption - 1); }

    bool isOpen() const { return active; }
    void open() {
        selectedOption = 0;
        ativarObj();
    }

    void close() {
        desativarObj();
    }

    int getSelectedOption() const { return selectedOption; }

private:
    int selectedOption, MAX;
};

#endif //JOGO_WAR_MENU_H
