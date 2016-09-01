#include <iostream>
#include <string>

using namespace std;

class ContaCorrente{
	private:

		float saldo;
		string titular;
		int numero_conta;

		ContaCorrente(){
		}

	public:

		ContaCorrente(const string p_titular, const int p_numero_conta){
			saldo = 0.0;
			titular = p_titular;
			numero_conta = p_numero_conta;
		}

		ContaCorrente(string p_titular, int p_numero_conta, float p_saldo_inicial){
			saldo = p_saldo_inicial;
			titular = p_titular;
			numero_conta = p_numero_conta;
		}

		float depositar(float valor){
			saldo = saldo + valor;

			return saldo;
		}

		float sacar(float valor){
			saldo = saldo - valor;

			return saldo;
		}

		float getSaldo() 
		{ 
			return saldo;
		}

		int getNumeroConta() 
		{
			return numero_conta;
		}

		string getTitular() 
		{
			return titular;
		}

		void transferirPara(ContaCorrente &conta_destino, float valor)
		{
			sacar(valor);
			conta_destino.depositar(valor);
		}
};


int main(){

	int tipoConta = 0;

	ContaCorrente *conta = NULL;

	cout << "Insira o tipo de conta que você quer criar: " << endl
		<< "1 - Conta sem saldo inicial " << endl
		<< "2 - Conta com saldo inicial " << endl;	

	cin >> tipoConta;

	switch(tipoConta)
	{
		case 1:
			{
				ContaCorrente conta_sem_saldo("Daniel", 123);
				conta = &conta_sem_saldo; 
				break;
			}
		case 2:
			{
				ContaCorrente conta_com_saldo("Daniel", 123, 1000);
				conta = &conta_com_saldo;
				break;
			}
		default:
			{
				cout << "OPÇÃO INVÁLIDA!!!" << endl;
			}
	}


	cout << "A conta criada foi: " << endl
		 << "- Titular: " << conta->getTitular()	    << endl  
		 << "- Conta:   " << conta->getNumeroConta() << endl 
		 << "- Saldo:   " << conta->getSaldo() 		<< endl;

	return 0;
}
