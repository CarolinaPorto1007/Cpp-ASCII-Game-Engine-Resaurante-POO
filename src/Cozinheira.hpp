#ifndef COZINHEIRA_HPP
#define COZINHEIRA_HPP

#include "Cliente.hpp"
#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "../ASCII_Engine/Sprite.hpp"
#include "../ASCII_Engine/TextSprite.hpp"
#include <vector>
#include <string>

class Cozinheira : public ObjetoDeJogo {
private:
    std::vector<std::string> bandeja;  

     TextSprite* mensagemEntrega;          

public:

    Cozinheira(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj){}

    // Adiciona um item à bandeja
    // Na classe Cozinheira (Cozinheira.hpp)
    void pegarComida(std::string &comida) {
        bandeja.push_back(comida);
    }

    // Tenta entregar o pedido ao Cliente e cria uma mensagem (TextSprite) de acordo com o resultado
    void entregarPedido(Cliente &cliente) {
        if (cliente.getTempoDeEspera() > 0) {
            cliente.conferirPedido(bandeja);
            if (mensagemEntrega) {
                delete mensagemEntrega;
                mensagemEntrega = nullptr;
            }
            mensagemEntrega = new TextSprite("Pedido entregue!", COR::VERDE);
        } else {
            if (mensagemEntrega) {
                delete mensagemEntrega;
                mensagemEntrega = nullptr;
            }
            mensagemEntrega = new TextSprite("Tempo de espera esgotado Pedido nao entregue.", COR::VERMELHA);
        }
        bandeja.clear();
    }

    // Desenha a sprite da Cozinheira e, se houver, a mensagem de entrega
    void draw(SpriteBase &screen, int x, int y) override {
        if (active) {
            // Desenha a sprite da Cozinheira
            if (pSprite) {
                pSprite->draw(screen, x, y);
            }
            // Desenha a mensagem de entrega, se existir, em uma posição ajustada
            if (mensagemEntrega != nullptr) {
                mensagemEntrega->draw(screen, x, y - 7);
            }
        }
    }

        };

#endif // COZINHEIRA_HPP
