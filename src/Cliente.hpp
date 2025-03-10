#ifndef CLIENTE_HPP
#define CLIENTE_HPP

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
    int tempo_de_espera; // Tempo de espera do pedido
    TextSprite* resultadoMensagem; // TextSprite para exibir o resultado da conferência do pedido

public:
    Cliente(const ObjetoDeJogo &obj)
        : ObjetoDeJogo(obj),
          balao(new Sprite("rsc/balao.txt", COR::BRANCA)),
          pedido_ativo(false),
          tempo_de_espera(100),
          resultadoMensagem(nullptr)
    {}

    // Gera o pedido do cliente com itens aleatórios
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

    // O cliente confere o pedido entregue e exibe o resultado por meio de um TextSprite
    void conferirPedido(const std::vector<std::string>& pedidoEntregue) {
        // Libera mensagem anterior, se houver
        if (resultadoMensagem) {
            delete resultadoMensagem;
            resultadoMensagem = nullptr;
        }

        if (pedidoEntregue.size() != itens_escolhidos.size()) {
            resultadoMensagem = new TextSprite("Pedido incorreto! Tamanho diferente.", COR::VERMELHA);
        } else {
            bool ok = true;
            for (size_t i = 0; i < pedidoEntregue.size(); ++i) {
                if (pedidoEntregue[i] != itens_escolhidos[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                resultadoMensagem = new TextSprite("Pedido correto!", COR::VERDE);
            else
                resultadoMensagem = new TextSprite("Pedido incorreto!", COR::VERMELHA);
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

    // Desenha o cliente, seu pedido e a mensagem de resultado (se houver)
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
            if (resultadoMensagem != nullptr) {
                // Exibe a mensagem de resultado; ajuste as coordenadas conforme necessário
                resultadoMensagem->draw(screen, x + 10, y + 30);
            }
        }
    }

    ~Cliente() {
        if (resultadoMensagem)
            delete resultadoMensagem;
        delete balao;
    }
};

#endif // CLIENTE_HPP
