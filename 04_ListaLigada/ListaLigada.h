#include <iostream>

template<typename T>
class ListaLigada{
private:
    T valor;
    ListaLigada<T> *cauda;

public:
    ListaLigada(T valor);
    ~ListaLigada();

    void adicionar(T valor);
    ListaLigada<T> *remover(int posicao);
    T getValorEm(int posicao);
    int getTamanho();
};


template<typename T>
ListaLigada<T>::ListaLigada(T valor) {
    this -> valor = valor;
    this -> cauda = NULL;
}

template<typename T>
ListaLigada<T>::~ListaLigada(){
    std::cout << "--Argh!!!! Estou derretendo!!!" << std::endl;
    std::cout << "--" << this -> valor << std::endl;
}

template<typename T>
ListaLigada<T> *ListaLigada<T>::remover(int posicao){

   ListaLigada<T> *resultado;

    if(posicao == 1)
    {
        ListaLigada<T> *temporario = this -> cauda;

        this -> cauda = this -> cauda -> cauda;

        resultado = this;

        delete temporario;
    }
    else if(posicao == 0)
    {
        ListaLigada<T> *temporario = this;

        resultado = this -> cauda;

        delete temporario;
    }
    else
    {
        ListaLigada<T> *temporario = this -> cauda;

        this -> cauda = this -> cauda -> remover(posicao - 1);

        resultado = this;

        delete temporario;
    }

    return resultado;
}


template<typename T>
void ListaLigada<T>::adicionar(T valor) {

    if(this->cauda == NULL)
        this -> cauda = new ListaLigada<T>(valor);
    else
        this -> cauda -> adicionar(valor);
}

template<typename T>
T ListaLigada<T>::getValorEm(int posicao) {
    T resultado;

    if(posicao == 0)
        resultado = this -> valor;
    else
        resultado = this -> cauda -> getValorEm(posicao - 1);

    return resultado;
}

template <typename T>
int ListaLigada<T>::getTamanho() {
    int resultado = 0;
    if((this -> cauda) == NULL)
        resultado = 1;
    else
        resultado = 1 + this -> cauda -> getTamanho();

    return resultado;
}
