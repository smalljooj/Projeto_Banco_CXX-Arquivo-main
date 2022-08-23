#include "pessoa_fisica.h"

std::string const& pessoa_fisica:: get_cpf_cnpj() const 
{
	return this->cpf;
}

pessoa& pessoa_fisica:: set_cpf_cnpj(std::string cpf_) 
{
	this->cpf = std::move(cpf_);
	return *this;
}
