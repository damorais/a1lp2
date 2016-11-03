#include <iostream>
#include <string>

using namespace std;

class Conta {
	private:
		float saldo;
		string titular;
		int numero_conta;

	protected:
		Conta(){
		}

	public:

		Conta(const string p_titular, const int p_numero_conta){
			saldo = 0.0;
			titular = p_titular;
			numero_conta = p_numero_conta;
		}

		Conta(string p_titular, int p_numero_conta, float p_saldo_inicial){
			saldo = p_saldo_inicial;
			titular = p_titular;
			numero_conta = p_numero_conta;
		}

		virtual float depositar(float valor){
			saldo = saldo + valor;

			return saldo;
		}

		virtual float sacar(float valor){
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

		void transferirPara(Conta &conta_destino, float valor)
		{
			sacar(valor);
			conta_destino.depositar(valor);
		}

		virtual string toString() = 0;
};

class ContaCorrente : public Conta{
	private:
		ContaCorrente(){
		}

	public:
		ContaCorrente(string p_titular, int p_numero_conta, float p_saldo_inicial)
			: Conta(p_titular, p_numero_conta, p_saldo_inicial)
		{

		}

		float depositar(float valor){
			cout << "Depositar de conta corrente" << endl;
			return Conta::depositar(valor);
		}

		float sacar(float valor){
			cout << "Sacar de conta corrente" << endl;
			return Conta::sacar(valor);
		}

		string toString(){
		 	return "Conta Corrente";
		}
};

class ContaPoupanca : public Conta{
	private:
		ContaPoupanca(){
		}

	public:
		ContaPoupanca(string p_titular, int p_numero_conta, float p_saldo_inicial)
			: Conta(p_titular, p_numero_conta, p_saldo_inicial)
		{

		}

		float depositar(float valor){
			cout << "Depositar de poupanca" << endl;
			return Conta::depositar(valor);
		}

		float sacar(float valor){
			cout << "Sacar de poupança" << endl;
			return Conta::sacar(valor);
		}

		string toString(){
			return "Conta Poupança";
		}
};

class ContaInvestimento : public Conta{
	private:
		ContaInvestimento(){
		}

	public:
		ContaInvestimento(string p_titular, int p_numero_conta, float p_saldo_inicial)
			: Conta(p_titular, p_numero_conta, p_saldo_inicial)
		{

		}

		float depositar(float valor){
			cout << "Depositar de investimento" << endl;
			return Conta::depositar(valor);
		}

		float sacar(float valor){
			cout << "Sacar de investimento" << endl;
			return Conta::sacar(valor);
		}

		string toString(){
			return "Conta Investimento";
		}
};


// Pessoa GetContaCorrente()
// {
// 	ContaCorrente conta_sem_saldo("Daniel", 123);
// 	return conta_sem_saldo;
// }

void TestarConta(Conta *conta, float valorDeposito, float valorSaque){

	conta -> depositar(valorDeposito);
	conta -> sacar(valorSaque);

}

Conta *GeradorDeContas(int tipoConta, string correntista, int numeroConta, float saldoInicial){

	Conta *conta = NULL;

	switch(tipoConta){
		case 1:{
				   conta = new ContaCorrente(correntista, numeroConta, saldoInicial);
				   break;
			   }
		case 2:{
				   conta = new ContaPoupanca(correntista, numeroConta, saldoInicial);
				   break;
			   }
		case 3:
			   {
				   conta = new ContaInvestimento(correntista, numeroConta, saldoInicial);
				   break;
			   }
		default:
			   cout << "Tá ERRADO!!!!!" << endl;
	}

	return conta;
}

void ImprimirDadosConta(Conta *conta){

	cout 
		<< "- Tipo da conta: " << conta -> toString() << endl
		<< "- Correntista: " << conta -> getTitular() << endl
		<< "- Número da Conta: " << conta -> getNumeroConta() << endl	
		<< "- O saldo desta conta é: " << conta -> getSaldo() << endl;
}


int main(){


	Conta* contas[10];
	int contasRegistradas = 0;


	int operacao = 100;
	cout << "Digite o que deseja fazer: " << endl;


	while(operacao != 0){
		cout 	<< "Digite 1 para conta corrente" << endl
			<< "Digite 2 para conta poupança" << endl
			<< "Digite 3 para conta investimento" << endl
			<< "Digite 4 para listar as contas" << endl
			<< "Digite 0 para sair" << endl;

		cin >> operacao;


		if(operacao != 0 && operacao != 4) {
			string correntista;
			int numeroConta;
			float saldoInicial;

			int tipoConta = operacao;

			cout << "Digite o nome do correntista" << endl;
			cin >> correntista;

			cout << "Digite o número da conta" << endl;
			cin >> numeroConta;

			cout << "Digite o saldo inicial" << endl;
			cin >> saldoInicial;

			Conta *conta = GeradorDeContas(tipoConta,
					correntista, numeroConta, saldoInicial);

			contas[contasRegistradas] = conta;
			contasRegistradas++;
			//ImprimirDadosConta(conta);
		}

		if(operacao == 4)
		{
			int i = 0;
			for(i = 0; i < contasRegistradas; i++)
				ImprimirDadosConta(contas[i]);
		}	

	}


	return 0;
}
