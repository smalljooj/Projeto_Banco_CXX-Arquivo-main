#ifndef TRANSACAO_H 
#define TRANSACAO_H 

#include <string>

class transacao{
	std::string data;
	double valor;
	std::string descricao;

public:
	transacao() = default;
	transacao(std::string data_, float valor_, std::string descricao_):
	 data(std::move(data_)), valor(std::move(valor_)), descricao(std::move(descricao_)){}
	
	std::string const& get_data()const{return this->data;}
	float get_valor()const{return valor;}
 	std::string const& get_descricao()const{return this->descricao;}
	
	transacao& set_data(std::string data_){this->data = std::move(data_); return *this;}
	transacao& set_valor(float valor_){this->valor = valor_;return *this;}
	transacao& set_descricao(std::string descricao_){this->descricao = std::move(descricao_); return *this;}

};
#endif
