#include <iostream>
#include <string>
//#include <ListaLigadaDeStrings.h>
#include "ListaLigada.h"

using namespace std;

template <typename T>
void printList(ListaLigada<T> *lista){

    int tamanhoLista = lista->getTamanho();

    for(int i = 0; i < tamanhoLista; i++)
        cout << lista->getValorEm(i) << "|";

    cout << endl;
}

int main(){

    ListaLigada<int> *lista = new ListaLigada<int>(123);
    lista -> adicionar(456);
    lista -> adicionar(789);

    printList(lista);
    cout << lista -> getTamanho() << endl;

    while(lista != NULL){
        lista = lista -> remover(0);
        if(lista != NULL)
            printList(lista);
            //cout << lista -> toString() << endl;
    }


    cout << "Acabando o programa" << endl;

//    ListaLigadaDeStrings *lista = new ListaLigadaDeStrings("Meu primeiro item");
//    lista -> adicionar("Meu segundo item");
//    lista -> adicionar("Meu terceiro item");
//
//    cout << lista -> toString() << endl;
//    cout << lista -> getTamanho() << endl;
//
////    lista = lista -> remover(1);
////    cout << lista -> toString() << endl;
////
////    lista = lista -> remover(1);
////    cout << lista -> toString() << endl;
//
//    while(lista != NULL){
//        lista = lista -> remover(0);
//        if(lista != NULL)
//            cout << lista -> toString() << endl;
//    }
//
//
//    cout << "Acabando o programa" << endl;





    return 0;

}
