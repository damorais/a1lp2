#include <iostream>
#include <string>

using namespace std;

class ContaCorrente{
	private:
		float saldo;
		string titular;
		int numero_conta;

		ContaCorrente(){
			string teste = "";
		}

	public:
		//ContaCorrente(const string p_titular,const int p_numero_conta){
		//	saldo = 0.0;
		//	titular = p_titular;
		//	numero_conta = p_numero_conta;
		//}

		ContaCorrente(const string p_titular, const int p_numero_conta, const float p_saldo_inicial = 0){
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

		float getSaldo() const
		{ 
			return saldo;
		}

		int getNumeroConta() const
		{
			return numero_conta;
		}

		string getTitular() const 
		{
			return titular;
		}
};



int main(){

	const ContaCorrente conta1("Daniel Morais", 1);
	cout << conta1.getTitular() 	<< " - " 
		 << conta1.getNumeroConta() << " - "
		 << conta1.getSaldo() 		<< endl;

//	conta1.depositar(150);

	cout << conta1.getTitular() 	<< " - " 
		 << conta1.getNumeroConta() << " - "
		 << conta1.getSaldo() 		<< endl;

//	conta1.sacar(35);

	string teste = conta1.getTitular();
	teste = "batata";

	cout << conta1.getTitular() << endl;
	cout << teste << endl;


	cout << conta1.getTitular() 	<< " - " 
		 << conta1.getNumeroConta() << " - "
		 << conta1.getSaldo() 		<< endl;

	ContaCorrente conta2("Maria da Silva", 2, 355);
	cout << conta2.getTitular() 	<< " - " 
		 << conta2.getNumeroConta() << " - "
		 << conta2.getSaldo() 		<< endl;

	conta2.sacar(237);

	cout << conta2.getTitular() 	<< " - " 
		 << conta2.getNumeroConta() << " - "
		 << conta2.getSaldo() 		<< endl;

	conta2.depositar(32);

	cout << conta2.getTitular() << " - " 
		 << conta2.getNumeroConta() << " - "
		 << conta2.getSaldo() << endl;

	return 0;
}
