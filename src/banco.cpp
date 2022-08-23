#include "banco.h"
#include <cstddef>

std::vector<std::shared_ptr<conta const>> banco::listar_contas_correntista
													(std::string const& cpf_cnpj) const
{
	std::vector<std::shared_ptr<conta const>> contass; 
	for(auto c: contas)
	{
		if(c->get_pessoa()->get_cpf_cnpj() == cpf_cnpj)
			contass.push_back(c);
	}
	return contass;
}

std::vector<std::shared_ptr<conta const>> banco::listar_contas() const
{
	std::vector<std::shared_ptr<conta const>> contass; 
	for(auto c: contas)
	{
		contass.push_back(c);
	}
	return contass;
}

std::vector<std::shared_ptr<pessoa const>> banco::listar_pessoas() const
{
	std::vector<std::shared_ptr<pessoa const>> pessoas; 
	for(auto p: correntistas)
	{
		pessoas.push_back(p);
	}
	return pessoas;
}

std::shared_ptr<conta> banco::criar_conta(std::string const& cpf_cnpj, int senha_, 
							int tipo, double saldo, double limite )
{
	std::string numero = "";
	std::shared_ptr<pessoa> pessoa;

	for(auto p: correntistas)
	{
		if(p->get_cpf_cnpj() == cpf_cnpj)
		{
			pessoa = p;
		}
	}
	try{
		if(tipo==1){
			std::string buf;
			if(std::dynamic_pointer_cast<pessoa_fisica>(pessoa))
				numero.append("001.");
			else if(std::dynamic_pointer_cast<pessoa_juridica>(pessoa))
				numero.append("003.");
			else
				throw std::runtime_error("Erro ao criar conta");

			buf = std::to_string(contas.size());

			while(buf.size()<6)
				buf.insert(0, "0");
			numero.append(buf+"-0");

			std::shared_ptr<conta> nova_conta_ = std::make_shared<conta_corrente>
												(pessoa, numero, saldo, pessoa->get_pos(), senha_);
			contas.push_back(nova_conta_);
			return nova_conta_;
		}
		else if(tipo==2){
			std::string buf;
			if(std::dynamic_pointer_cast<pessoa_fisica>(pessoa))
				numero.append("101.");
			else if(std::dynamic_pointer_cast<pessoa_juridica>(pessoa))
				numero.append("103.");
			else
				throw std::runtime_error("Erro ao criar conta");

			buf = std::to_string(contas.size());

			while(buf.size()<6)
				buf.insert(0, "0");
			numero.append(buf+"-0");

			std::shared_ptr<conta> nova_conta_ = std::make_shared<conta_limite>
												(pessoa, numero, saldo, limite, pessoa->get_pos(), senha_);
			contas.push_back(nova_conta_);
			return nova_conta_;
		}
		else if(tipo==3){
			std::string buf;
			if(std::dynamic_pointer_cast<pessoa_fisica>(pessoa))
				numero.append("013.");
			else if(std::dynamic_pointer_cast<pessoa_juridica>(pessoa))
				numero.append("023.");
			else
				throw std::runtime_error("Erro ao criar conta");

			buf = std::to_string(contas.size());

			while(buf.size()<6)
				buf.insert(0, "0");
			numero.append(buf+"-0");

			time_t t;
			time(&t);
			char buffer[30];
			strftime(buffer, 30, "%d/%m/%Y  %H-%M-%S", localtime(&t));
			std::shared_ptr<conta> nova_conta_ = std::make_shared<conta_poupanca>
												(pessoa, numero, saldo, buffer, pessoa->get_pos(), senha_);
			contas.push_back(nova_conta_);
			return nova_conta_;
		}
	}
	catch(...){
		throw excpt_Banco::ErroaoCriarConta();
	}
	throw excpt_Banco::ErroaoCriarConta();
}

std::shared_ptr<pessoa> banco::criar_pessoa(std::string nom, std::string dt, std::string cpf_cnpj, int tipo)
{
	std::shared_ptr<pessoa> nova_pessoa;
	try{
		if(tipo==1)
		{
			nova_pessoa = std::make_shared<pessoa_fisica>(nom, dt, cpf_cnpj, correntistas.size());
			correntistas.push_back(nova_pessoa);
		}
		else
		{
			nova_pessoa = std::make_shared<pessoa_juridica>(nom, dt, cpf_cnpj, correntistas.size());
			correntistas.push_back(nova_pessoa);
		}
	}catch(...){
		throw excpt_Banco::ErroaoCriarConta();
	}
	return nova_pessoa;
}

banco& banco::atualizar_conta(std::string const& numero, int tipo, double limite){
	try{
		for(auto & c: contas)		
		{
			if(c->get_numero() == numero)
			{
				std::string novo_numero = c->get_numero();
				std::shared_ptr<conta> nova_conta;
				if(tipo == 1)
				{
					if(std::dynamic_pointer_cast<pessoa_fisica>(c->get_pessoa()))
					{
						novo_numero[0] = '0'; 
						novo_numero[1] = '0'; 
						novo_numero[2] = '1'; 
					}
					else
					{
						novo_numero[0] = '0'; 
						novo_numero[1] = '0'; 
						novo_numero[2] = '3'; 
					}
					nova_conta = std::make_shared<conta_corrente>
						(c->get_pessoa(), novo_numero, c->get_saldo(), c->get_pos(), c->get_senha());
				}
				else if(tipo == 2)
				{
					if(std::dynamic_pointer_cast<pessoa_fisica>(c->get_pessoa()))
					{
						novo_numero[0] = '1'; 
						novo_numero[1] = '0'; 
						novo_numero[2] = '1'; 
					}
					else
					{
						novo_numero[0] = '1'; 
						novo_numero[1] = '0'; 
						novo_numero[2] = '3'; 
					}
					nova_conta = std::make_shared<conta_limite>
						(c->get_pessoa(), novo_numero, c->get_saldo(), limite, c->get_pos(), c->get_senha());
				}
				else
				{
					if(std::dynamic_pointer_cast<pessoa_fisica>(c->get_pessoa()))
					{
						novo_numero[0] = '0'; 
						novo_numero[1] = '2'; 
						novo_numero[2] = '1'; 
					}
					else 
					{
						novo_numero[0] = '0'; 
						novo_numero[1] = '2'; 
						novo_numero[2] = '3'; 
					}
					time_t t;
					time(&t);
					char buffer[30];
					strftime(buffer, 30, "%d/%m/%Y  %H-%M-%S", localtime(&t));
					nova_conta = std::make_shared<conta_poupanca>
						(c->get_pessoa(), novo_numero, c->get_saldo(), buffer, c->get_pos(),c->get_senha());
				}
				c.reset();
				c = nova_conta;
			}
		}
	}
	catch(...)
	{
		throw excpt_Banco::ErroaoAtualizarConta();
	}
	return *this;
}

banco& banco::fechar_conta(std::string const& numero)
{
	for(int i = 0; i < contas.size(); i++)
	{
		if(contas[i]->get_numero() == numero)
		{
			contas[i].reset();
			contas.erase(contas.begin() + i);
			return *this;
		} 
	}
	throw excpt_Banco::ErroaoFecharConta();
}

std::shared_ptr<conta const> banco::get_conta(std::string const& numero) const
{
	for(auto c: contas)
	{
		if(c->get_numero() == numero)
		{
			return c;
		}
	}
	throw excpt_Banco::ErroaoBuscarConta();
}

std::shared_ptr<pessoa const> banco::get_pessoa(const std::string& nome_,
													const std::string& cpf_cnpj) const
{
	for(auto p: correntistas)
	{
		if(p->get_nome() == nome_ && p->get_cpf_cnpj() == cpf_cnpj)
		{
			return p;
		}
	}
	throw excpt_Banco::ErroaoBuscarPessoa();
}


std::shared_ptr<pessoa const> banco::get_pessoa(int pos) const
{
	return correntistas[pos]; 
}

void banco::operacoes_do_usuario(int tipo, double valor, 
									std::string const& numero, 
										std::string const& numero_transferencia)
{
	for(auto c: contas)
	{
		if(c->get_numero() == numero)
		{
			if(tipo ==1)
				*c << valor;
			else if(tipo == 2)
				*c >> valor;
			else
				for(auto c2: contas)
				{
					if(c2->get_numero() == numero_transferencia)
						c->transferencia(*c2, valor);
				}
		}
	}
}
