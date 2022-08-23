#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H

#include "pessoa.h"

class pessoa_juridica : public pessoa{
	std::string cnpj;
public:
	pessoa_juridica(std::string nome_, std::string data_nasc_, std::string cnpj_, int ps):
		pessoa(std::move(nome_), std::move(data_nasc_), ps, "Pessoa Juridica"), cnpj(std::move(cnpj_)){}

	virtual std::string const& get_cpf_cnpj() const override;
	virtual pessoa& set_cpf_cnpj(std::string) override;

};

#endif
