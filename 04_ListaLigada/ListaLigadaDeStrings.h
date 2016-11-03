#include <iostream>
#include <string>

class ListaLigadaDeStrings{

private:
    std::string valor;
    ListaLigadaDeStrings *cauda;

public:
    ListaLigadaDeStrings(std::string valor);
    ~ListaLigadaDeStrings();

    void adicionar(std::string valor);
    ListaLigadaDeStrings *remover(int posicao);
    std::string getValorEm(int posicao);
    int getTamanho();

    std::string toString();
};
