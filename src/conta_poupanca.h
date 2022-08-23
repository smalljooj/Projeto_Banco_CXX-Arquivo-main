#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "conta.h"
#include <memory>

class conta_poupanca : public conta{
	std::string aniversarioconta;
public:
	conta_poupanca(std::shared_ptr<pessoa> proprietario_, std::string numero_,
		double saldo_, std::string aniv, int ps, int senha_):
	 		conta(std::move(proprietario_), numero_, saldo_, ps, "Conta Poupanca", senha_),
				aniversarioconta(std::move(aniv)){}

	virtual std::shared_ptr<pessoa> get_pessoa() const override;
	virtual double get_saldo() const override;
	virtual int get_pos() const override;
	virtual std::string const& get_numero() const override;
	virtual std::string const& get_tconta() const override;
	virtual std::vector<const transacao *> get_transacoes() const override;
	virtual int get_limite()const override;
	virtual int get_senha() const override;
	const std::string& getAniversarioConta();

	virtual conta& set_pessoa(std::shared_ptr<pessoa>) override;
	virtual conta& set_numero(std::string& num) override;
	virtual conta& set_saldo(double sald) override;
	virtual conta& set_pos(int posicao) override;
	virtual conta& set_transacoes(std::vector<transacao>&) override;
	conta& set_aniversario_conta(std::string& aniv);

	virtual conta& operator>>(double retirada) override;
	virtual conta& operator<<(double deposito) override;
	virtual conta& transferencia(conta& other, double value) override;

	virtual conta const& dados_conta() const override;
	virtual conta const& extrato() const override;

	virtual bool verificar_senha(int) const override;
};
#endif
