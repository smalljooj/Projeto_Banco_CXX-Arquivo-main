#ifndef CONTALIMITE_H
#define CONTALIMITE_H

#include "conta.h"
#include <memory>

class conta_limite : public conta{
	double limite;
public:
	conta_limite(std::shared_ptr<pessoa> proprietario_, std::string numero_,
		double saldo_, double limite, int ps, int senha_):
			conta(proprietario_, std::move(numero_), saldo_, ps, "Conta Limite", senha_),
				limite(limite){}

	virtual std::shared_ptr<pessoa> get_pessoa() const override;
	virtual double get_saldo() const override;
	virtual int get_pos() const override;
	virtual std::string const& get_numero() const override;
	virtual std::string const& get_tconta() const override;
	virtual std::vector<const transacao *> get_transacoes() const override;
	virtual int get_limite() const override;
	virtual int get_senha() const override;

	virtual conta& set_pessoa(std::shared_ptr<pessoa>) override;
	virtual conta& set_numero(std::string&) override;
	virtual conta& set_saldo(double) override;
	virtual conta& set_pos(int) override;
	virtual conta& set_transacoes(std::vector<transacao> &) override;
	conta_limite& setLimite(int);

	virtual conta& transferencia(conta&, double) override;
	virtual conta& operator>>(double) override;
	virtual conta& operator<<(double) override;

	virtual conta const& dados_conta() const override;
	virtual conta const& extrato() const override;

	virtual bool verificar_senha(int) const override;
};

#endif
