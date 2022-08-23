#ifndef BANCO_H
#define BANCO_H

#include <memory>
#include <vector>
#include <sstream>

#include "pessoa_fisica.h"
#include "pessoa_juridica.h"
#include "conta_corrente.h"
#include "conta_limite.h"
#include "conta_poupanca.h"
#include "exceptions.h"

class banco : public pessoa_juridica{
	std::string nome_banco;
	std::vector<std::shared_ptr<pessoa>> correntistas;
	std::vector<std::shared_ptr<conta>> contas;
public:
	banco(std::string nome_pessoa, std::string data_nasc_, std::string cnpj_, std::string nome_banco_): 
		pessoa_juridica(std::move(nome_pessoa), std::move(data_nasc_), std::move(cnpj_), -1),
			nome_banco(std::move(nome_banco_)){}

	std::string const& get_nome_banco(){return this->nome_banco;}

	std::vector<std::shared_ptr<conta const>> listar_contas_correntista(std::string const&) const;
	std::vector<std::shared_ptr<conta const>> listar_contas() const;
	std::vector<std::shared_ptr<pessoa const>> listar_pessoas() const;

	std::shared_ptr<pessoa> criar_pessoa(std::string, std::string, std::string, int);
	std::shared_ptr<conta> criar_conta(std::string const&, int, int, double, double = 0);
	banco& atualizar_conta(std::string const&, int, double = 0);
	banco& fechar_conta(std::string const&);

	std::shared_ptr<conta const> get_conta(std::string const&) const;
	std::shared_ptr<pessoa const> get_pessoa(std::string const&, std::string const&) const;
	std::shared_ptr<pessoa const> get_pessoa(int) const;
	
	void operacoes_do_usuario(int, double, std::string const&, std::string const& = "");
};

#endif
