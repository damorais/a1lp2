#include <iostream>
#include "ListaLigada.h"

//template<typename T>
//ListaLigada<T>::ListaLigada(T valor) {
//    this -> valor = valor;
//    this -> cauda = NULL;
//}

//ListaLigada<T>::~ListaLigadaDeStrings(){
//    std::cout << "--Argh!!!! Estou derretendo!!!" << std::endl;
//    std::cout << "--" << this -> valor << std::endl;
//}
//template<typename T>
//void ListaLigada<T>::remover(int posicao){
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
//            ListaLigada<T> *caudaOriginal = this -> cauda;
//            this -> cauda = this -> cauda -> cauda;
//            delete caudaOriginal;
//        }
//
//    }
//    else
//    {
//        this -> cauda -> remover(posicao - 1);
//    }
//}


//template<typename T>
//void ListaLigada<T>::adicionar(T valor) {
//
//    if(this->cauda == NULL)
//        this -> cauda = new ListaLigada<T>(valor);
//    else
//        this -> cauda -> adicionar(valor);
//}
//
//template<typename T>
//T ListaLigada<T>::getValorEm(int posicao) {
//    std::string resultado;
//
//    if(posicao == 0)
//        resultado = this -> valor;
//    else
//        resultado = this -> cauda -> getValorEm(posicao - 1);
//
//    return resultado;
//}
//
//template <typename T>
//int ListaLigada<T>::getTamanho() {
//    int resultado = 0;
//    if((this -> cauda) == NULL)
//        resultado = 1;
//    else
//        resultado = 1 + this -> cauda -> getTamanho();
//
//    return resultado;
//}
//
//template <typename T>
//std::string ListaLigada<T>::toString() {
//    std::string resultado = this -> valor + " | ";
//
//    if(this->cauda != NULL)
//        resultado += this->cauda->toString();
//
//    return resultado;
//}




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
