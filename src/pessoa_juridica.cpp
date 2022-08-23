#include "pessoa_juridica.h"

std::string const& pessoa_juridica::get_cpf_cnpj() const 
{
	return this->cnpj;
};

pessoa& pessoa_juridica::set_cpf_cnpj(std::string cnpj_)
{
	this->cnpj = std::move(cnpj_);
	return *this;
}
