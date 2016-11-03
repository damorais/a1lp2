#include <iostream>
#include <string>
#include "ListaLigadaDeStrings.h"

ListaLigadaDeStrings::ListaLigadaDeStrings(std::string valor) {
    this -> valor = valor;
    this -> cauda = NULL;
}

ListaLigadaDeStrings::~ListaLigadaDeStrings(){
    std::cout << "--Argh!!!! Estou derretendo!!!" << std::endl;
    std::cout << "-- Destrutor: " << this -> valor << std::endl;
}

ListaLigadaDeStrings * ListaLigadaDeStrings::remover(int posicao){

    ListaLigadaDeStrings *resultado;

    if(posicao == 1)
    {
        ListaLigadaDeStrings *temporario = this -> cauda;

        this -> cauda = this -> cauda -> cauda;

        resultado = this;

        delete temporario;
    }
    else if(posicao == 0)
    {
        ListaLigadaDeStrings *temporario = this;

        resultado = this -> cauda;

        delete temporario;
    }
    else
    {
        ListaLigadaDeStrings *temporario = this -> cauda;

        this -> cauda = this -> cauda -> remover(posicao - 1);

        resultado = this;

        delete temporario;
    }

    return resultado;

}

//void ListaLigadaDeStrings::remover(int posicao){
//
//    if(posicao == 1)
//    {
//        if(this -> cauda -> cauda == NULL)
//        {
//            delete this -> cauda;
//            this -> cauda = NULL;
//        }
//        else
//        {
//            ListaLigadaDeStrings *caudaOriginal = this -> cauda;
//            this -> cauda = this -> cauda -> cauda;
//            delete caudaOriginal;
//        }
//    }
//    else
//    {
//        this -> cauda -> remover(posicao - 1);
//    }
//}
//
void ListaLigadaDeStrings::adicionar(std::string valor) {

    if(this->cauda == NULL)
        this -> cauda = new ListaLigadaDeStrings(valor);
    else
        this -> cauda -> adicionar(valor);
}

std::string ListaLigadaDeStrings::getValorEm(int posicao) {
    std::string resultado;

    if(posicao == 0)
        resultado = this -> valor;
    else
        resultado = this -> cauda -> getValorEm(posicao - 1);

    return resultado;
}

int ListaLigadaDeStrings::getTamanho() {
    int resultado = 0;
    if((this -> cauda) == NULL)
        resultado = 1;
    else
        resultado = 1 + this -> cauda -> getTamanho();

    return resultado;
}

std::string ListaLigadaDeStrings::toString() {
    std::string resultado = this -> valor + " | ";

    if(this->cauda != NULL)
        resultado += this->cauda->toString();

    return resultado;
}




//ListaLigadaDeStrings::ListaLigadaDeStrings(std::string valor){
//    this -> valor = valor;
//    this -> cauda = NULL;
//}
//
//
//void ListaLigadaDeStrings::adicionar(std::string valor){
//
//    if(this->cauda == NULL)
//        this -> cauda = new ListaLigadaDeStrings(valor);
//    else
//        this -> cauda -> adicionar(valor);
//}
//
//std::string ListaLigadaDeStrings::toString(){
//    std::string resultado = this -> valor + " | ";
//
//    if(this->cauda != NULL)
//        resultado += this->cauda->toString();
//
//    return resultado;
//}
