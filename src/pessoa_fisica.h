#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H

#include "pessoa.h"

class pessoa_fisica : public pessoa{
	std::string cpf;
public:
	pessoa_fisica(std::string nome_, std::string data_nasc_, std::string cpf_, int ps): 
		pessoa(std::move(nome_), std::move(data_nasc_), ps, "Pessoa Fisica"), cpf(std::move(cpf_)){}

	virtual std::string const& get_cpf_cnpj() const override;
	virtual pessoa& set_cpf_cnpj(std::string) override;

};

#endif
