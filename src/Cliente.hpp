/*#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/TextSprite.hpp"


class Cliente : public ObjetoDeJogo{


private:
    std::string nome; 
    std:: vector<std::string> itens_escolhidos;
    std::vector<TextSprite> itens;

    Sprite *balao;
   
    bool pedido_ativo;

public:
    
    Cliente(const ObjetoDeJogo &obj) :ObjetoDeJogo(obj), balao(new Sprite("rsc/Balao.txt", COR::BRANCA)), pedido_ativo(false) {}

    
    void fazerpedido(){

        if(pedido_ativo == false){

            std::srand(static_cast<unsigned int>(std::time(0)));

            std::vector<std::string> itens_disponiveis = {
                "Pizza", "Sanduiche", "Torta doce", "Torta salgada",
                "Biscoito doce", "Bolo", "Cafe", "Suco", "Banana",
                "Maca", "Pera", "Sorvete"
            };

            // Escolhe um número aleatório de itens (entre 2 e 5)
            int numero_de_itens = 2 + (std::rand() % 4); // Entre 2 e 5 itens


            for (int i = 0; i < numero_de_itens; ++i) {
                // Escolhe um índice aleatório para selecionar um item
                int indice_aleatorio = std::rand() % itens_disponiveis.size();
                itens_escolhidos.push_back(itens_disponiveis[indice_aleatorio]);

                // Remove o item escolhido para evitar repetição
                itens_disponiveis.erase(itens_disponiveis.begin() + indice_aleatorio);

            }

            pedido_ativo=true;

            for(int i=0; i<numero_de_itens; i++){

                itens.push_back(TextSprite(itens_escolhidos[i], COR::BRANCA));
            }
        }
    }

 

    void draw(SpriteBase &screen, int x, int y)override{
        
        if (active){
             pSprite->draw(screen,x,y);
             if(pedido_ativo){

                int y_balao= getPosC()-20;
                int x_balao= getPosL()-8;

                balao->draw(screen,x_balao,y_balao);

                for(int i=0; i<itens_escolhidos.size();i++){
                    itens[i].draw(screen,x_balao+i+2,y_balao+1);
                }
 
            }
        }
    }

};

#endif // CLIENTE_HPP
*/

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/TextSprite.hpp"

class Cliente : public ObjetoDeJogo {
private:
    std::string nome; 
    std::vector<std::string> itens_escolhidos;
    std::vector<TextSprite> itens;
    Sprite *balao;
    bool pedido_ativo;
    int tempo_de_espera; // Variável para controlar o tempo de espera do pedido

public:
    Cliente(const ObjetoDeJogo &obj)
      : ObjetoDeJogo(obj),
        balao(new Sprite("rsc/Balao.txt", COR::BRANCA)),
        pedido_ativo(false),
        tempo_de_espera(30) // Exemplo: 30 unidades de tempo
    {}

    void fazerpedido() {
        if (!pedido_ativo) {
            std::srand(static_cast<unsigned int>(std::time(0)));
            std::vector<std::string> itens_disponiveis = {
                "Pizza", "Sanduiche", "Torta doce", "Torta salgada",
                "Biscoito doce", "Bolo", "Cafe", "Suco", "Banana",
                "Maca", "Pera", "Sorvete"
            };

            int numero_de_itens = 2 + (std::rand() % 4); // Entre 2 e 5 itens
            for (int i = 0; i < numero_de_itens; ++i) {
                int indice_aleatorio = std::rand() % itens_disponiveis.size();
                itens_escolhidos.push_back(itens_disponiveis[indice_aleatorio]);
                itens_disponiveis.erase(itens_disponiveis.begin() + indice_aleatorio);
            }

            pedido_ativo = true;
            for (int i = 0; i < numero_de_itens; i++) {
                itens.push_back(TextSprite(itens_escolhidos[i], COR::BRANCA));
            }
        }
    }

    // Método para o cliente conferir o pedido entregue
    void conferirPedido(const std::vector<std::string>& pedidoEntregue) {
        if (pedidoEntregue.size() != itens_escolhidos.size()) {
            std::cout << "Pedido incorreto! Tamanho diferente." << std::endl;
        } else {
            bool ok = true;
            for (size_t i = 0; i < pedidoEntregue.size(); ++i) {
                if (pedidoEntregue[i] != itens_escolhidos[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                std::cout << "Pedido correto!" << std::endl;
            else
                std::cout << "Pedido incorreto!" << std::endl;
        }
        pedido_ativo = false;
        itens_escolhidos.clear();
        itens.clear();
    }

    // Retorna o tempo de espera restante
    int getTempoDeEspera() const {
        return tempo_de_espera;
    }

    // Atualiza (diminui) o tempo de espera (pode ser chamado a cada frame ou ciclo)
    void atualizarTempo() {
        if (tempo_de_espera > 0)
            tempo_de_espera--;
    }

    void draw(SpriteBase &screen, int x, int y) override {
        if (active) {
            pSprite->draw(screen, x, y);
            if (pedido_ativo) {
                int y_balao = getPosC() - 20;
                int x_balao = getPosL() - 8;
                balao->draw(screen, x_balao, y_balao);
                for (size_t i = 0; i < itens_escolhidos.size(); i++) {
                    itens[i].draw(screen, x_balao + i + 2, y_balao + 1);
                }
            }
        }
    }
};

#endif // CLIENTE_HPP


