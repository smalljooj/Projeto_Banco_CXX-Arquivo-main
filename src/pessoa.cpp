#include "pessoa.h"

std::string const& pessoa::get_type() const
{
	return this->type;
}

std::string const& pessoa::get_nome() const
{
	return this->nome;
}

pessoa& pessoa::set_nome(std::string nome_)
{
	this->nome = std::move(nome_);
	return *this;
}	

std::string const& pessoa::get_data_nasc() const
{
	return this->data_nasc; 
}

pessoa& pessoa::set_data_nasc(std::string dt)
{
	this->data_nasc = std::move(dt);
	return *this;
}	

int pessoa::get_pos()const
{
	return this->pos;
}
