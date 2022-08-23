#include "conta_poupanca.h"
#include <memory>

std::shared_ptr<pessoa> conta_poupanca:: get_pessoa() const 
{
	return this->proprietario;
}

double conta_poupanca:: get_saldo() const 
{
	return this->saldo;
} 

int conta_poupanca:: get_pos() const 
{
	return this->pos;
}

const std::string& conta_poupanca:: get_numero() const 
{
	return this->numero;
}

const std::string& conta_poupanca:: get_tconta() const 
{
	return this->tconta;
}

int conta_poupanca::get_senha() const
{
	return this->senha;
}

std::vector<const transacao *> conta_poupanca:: get_transacoes() const 
{
	std::vector<const transacao *> tran;
	int size = this->transacoes.size();
	int i = 0;
	if(size>30)
		i = size-30;

	for(; i<size; i++){
		tran.push_back(&(this->transacoes[i]));
	}
	return tran;
}

int conta_poupanca::get_limite() const
{
	return 0;
}

conta& conta_poupanca:: set_pessoa(std::shared_ptr<pessoa> p) 
{
	this->proprietario = p;
	return *this;
}

conta& conta_poupanca:: set_numero(std::string& num) 
{
	this->numero = std::move(num);
	return *this;
}

conta& conta_poupanca:: set_saldo(double sald) 
{
	if(sald<0)
		throw excpt_operacoesBancarias::QuantiaNegativa();
	this->saldo = sald;
	return *this;
}

conta& conta_poupanca:: set_pos(int posicao) 
{
	this->pos = posicao;
	return *this;
}

conta& conta_poupanca:: set_transacoes(std::vector<transacao>& tran)
{
	this->transacoes = std::move(tran);
	return *this;
}

conta& conta_poupanca:: operator>>(double retirada) 
{
	time_t t;
	time(&t);
	char buf[30];
	strftime(buf, 30, "%d/%m/%Y  %H-%M-%S", localtime(&t));
	if(retirada <= 0)
		throw excpt_operacoesBancarias::QuantiaNegativa();
	if(retirada>saldo)
		throw excpt_operacoesBancarias::SaldoInsuficiente();	
	this->saldo -= retirada;
	std::string buffer = buf;
	this->transacoes.push_back(transacao(buffer, retirada, "RETIRADA"));
	return *this;
}

conta& conta_poupanca:: operator<<(double deposito) 
{
	time_t t;
	time(&t);
	char buf[30];
	strftime(buf, 30, "%d/%m/%Y  %H-%M-%S", localtime(&t));

	if(deposito <= 0)
		throw excpt_operacoesBancarias::QuantiaNegativa();
	this->saldo += deposito;
	std::string buffer = buf;
	this->transacoes.push_back(transacao(buffer, deposito, "DEPOSITO"));
	return *this;
}

conta& conta_poupanca:: transferencia(conta& other, double value) 
{
	time_t t;
	time(&t);
	char buf[30];
	strftime(buf, 30, "%d/%m/%Y  %H-%M-%S", localtime(&t));

	if(value <= 0)
		throw excpt_operacoesBancarias::QuantiaNegativa();
	if(value > this->saldo)
		throw excpt_operacoesBancarias::SaldoInsuficiente();
	this->saldo-=value;
	other << value;
	std::string buffer = buf;
	this->transacoes.push_back(transacao(buffer, value, "TRANSFERENCIA"));
	return *this;
}

const conta& conta_poupanca:: extrato() const 
{
	std:: cout<< "O numero da conta e: " << this->numero << std:: endl;
	std:: cout << "O Nome do Dono e: "<< this->proprietario->get_nome()<< std:: endl << std:: endl;
	std:: cout << "................................................................" << std:: endl;
	int size = this->transacoes.size();
	int i = 0;
	if(size>30)
		i = size-30;
	for(; i<size; i++){
		std:: cout << "+---------------------------------------------------------------" << std:: endl;
		std:: cout << "|Data: "<< transacoes[i].get_data() << std:: endl;
		std:: cout << "|Valor: " <<transacoes[i].get_valor() << std:: endl;
		std:: cout << "|Operacao: " << transacoes[i].get_descricao() << std:: endl;
		std:: cout << "+---------------------------------------------------------------" << std:: endl;
		printf("\n");
	}
	std:: cout << "................................................................" << std:: endl;
	printf("\n");
	std:: cout << "Saldo: "<< this->saldo << std:: endl;
	return *this;
}

const std::string& conta_poupanca:: getAniversarioConta()
{
	return this->aniversarioconta;
}

conta& conta_poupanca:: set_aniversario_conta(std::string& aniv)
{
	this->aniversarioconta = std::move(aniv);
	return *this;
}

conta const& conta_poupanca::dados_conta() const
{
	std::cout << "Dados da Conta" << std::endl;
	std::cout << "+--------------------------------------------" << std::endl;
	std::cout << "| Nome: " << proprietario->get_nome() << std::endl;
	std::cout << "| Cpf/Cnpj: " << proprietario->get_cpf_cnpj() << std::endl;
	std::cout << "|\n| "<< tconta << std::endl; 
	std::cout << "| Numero: " << numero << std::endl;
	std::cout << "+--------------------------------------------" << std::endl;
	std::cout << std::endl;
	return *this;
}

bool conta_poupanca::verificar_senha(int senha_) const
{
	if(senha == senha_)
		return  true;
	return false;
}
