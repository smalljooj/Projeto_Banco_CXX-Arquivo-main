#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

class pessoa{
protected:
	std::string nome;
	std::string data_nasc;
	int pos = 0;
	std::string type;

public:
	pessoa(std::string nome_, std::string data_nasc_, int ps, std::string type_):  
		nome(std::move(nome_)), data_nasc(std::move(data_nasc_)), pos(ps), type(std::move(type_)){}

	std::string const& get_nome() const;
	std::string const& get_data_nasc() const;
	std::string const& get_type() const;
	int get_pos()const;

	pessoa& set_nome(std::string);
	pessoa& set_data_nasc(std::string);
	
	virtual std::string const& get_cpf_cnpj() const = 0;
	virtual pessoa& set_cpf_cnpj(std::string) = 0;

};

#endif /* PESSOA_H */
