#ifndef CONTA_H 
#define CONTA_H 

#include <iostream>
#include <vector>
#include <ctime>
#include <memory>

#include "pessoa.h"
#include "transacao.h"
#include "exceptions.h"

class conta{

protected:
	std::shared_ptr<pessoa> proprietario;
	std::string numero;
	double saldo;
	std::vector<transacao> transacoes;
	int pos;
	std::string tconta;
	int senha;

public:
	conta(std::shared_ptr<pessoa> proprietario_, std::string numero_, double saldo_, 
			int ps, std::string tconta_, int senha_):
				proprietario(proprietario_), numero(std::move(numero_)), saldo(saldo_),
		 			pos(ps), tconta(std::move(tconta_)), senha(senha_){}

	virtual std::shared_ptr<pessoa> get_pessoa() const = 0;
	virtual double get_saldo() const = 0;
	virtual int get_pos() const = 0;
	virtual std::string const& get_numero() const = 0;
	virtual std::string const& get_tconta() const = 0;
	virtual std::vector<transacao const*> get_transacoes() const = 0;
	virtual int get_limite() const = 0;
	virtual int get_senha() const = 0;

	virtual conta& set_pessoa(std::shared_ptr<pessoa>) = 0;
	virtual conta& set_numero(std::string&) = 0; //obs
	virtual conta& set_saldo(double) = 0;
	virtual conta& set_pos(int) = 0;
	virtual conta& set_transacoes(std::vector<transacao>&) = 0;

	virtual conta& operator>>(double) = 0; 
	virtual conta& operator<<(double) = 0; 
	virtual conta& transferencia(conta&, double) = 0;

	virtual conta const& dados_conta() const = 0;
	virtual conta const& extrato() const = 0;

	virtual bool verificar_senha(int) const = 0;
};
#endif

