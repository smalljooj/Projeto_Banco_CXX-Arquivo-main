#include "gerente.h"

namespace gerente
{
	void abrir_conta(banco& bank)
	{
		std::cout<< std::endl;
		auto nome = console::read<std::string>("Digite o nome da pessoa:");
		std::cout<< std::endl;
		auto cpf_cnpj = console::readCpf_Cnpj();
		int senha;

		try
		{
			auto p = bank.get_pessoa(nome, cpf_cnpj);
			std::cout<< std::endl ;

			std::string menu_conta = "Digite o tipo de Conta:\n";
			menu_conta += "1-> Conta Corrente\n";
			menu_conta += "2-> Conta Corrente com Limite\n";
			menu_conta += "3-> Conta Poupanca\n";
			auto tipoConta = console::readOp(1, 3, menu_conta);

			while(1)
			{
				try
				{
					senha = console::read<int>("Digite a senha:");
					if(senha < 0)
						throw excpt_operacoesBancarias::QuantiaNegativa();
					break;
				}
				catch(std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}

			std::cout<< std::endl;
			double saldo;
			while(1)
			{
				try
				{
					saldo = console::read<double>("Digite o Saldo:");
					if(saldo<0)
						throw excpt_operacoesBancarias::QuantiaNegativa();
					break;
				}
				catch(std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			if(tipoConta==2)
			{
				std::cout<< std::endl;
				while(1)
				{
					try
					{
						double limite = console::read<double>("Digite o limite de saque da conta:");
						if(limite<=0)
							throw excpt_operacoesBancarias::QuantiaNegativa();
						auto conta = bank.criar_conta(p->get_cpf_cnpj(), senha, tipoConta, saldo, limite);
						conta->dados_conta();
						break;
					}
					catch(std::exception& e)
					{
						std::cerr << e.what() << std::endl;
					}
				}
			}
			else{
				try
				{
					auto conta = bank.criar_conta(p->get_cpf_cnpj(), senha, tipoConta, saldo);
					conta->dados_conta();
				}catch(std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
		}
		catch(...)
		{
			std::cout<< std::endl;

			std::string data_nasc = console::readDataNasc("Digite a data de Nascimento da pessoa:   (dd/mm/yyyy)");
			std::cout<< std::endl;

			auto tipoPessoa = (cpf_cnpj.size() == 18)? 2: 1;

			auto p = bank.criar_pessoa(nome, data_nasc, cpf_cnpj, tipoPessoa);
			std::cout<< std::endl;

			std::string menuConta = "Digite o tipo de Conta:\n";
			menuConta += "1-> Conta Corrente\n";
			menuConta += "2-> Conta Corrente com Limite\n";
			menuConta += "3-> Conta Poupanca\n";

			auto tipoConta = console::readOp(1, 3, menuConta);

			std::cout << std::endl;
			double saldo;
			int senha;

			while(1)
			{
				try
				{
					senha = console::read<int>("Digite a senha:");
					if(senha < 0)
						throw excpt_operacoesBancarias::QuantiaNegativa();
					break;
				}
				catch(std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}

			while(1)
			{
				try
				{
					saldo = console::read<double>("Digite o Saldo:");
					if(saldo<0)
						throw excpt_operacoesBancarias::QuantiaNegativa();
					break;
				}
				catch(std::exception& e)
				{
					std::cerr << e.what() << std::endl;
				}
			}
			if(tipoConta==2)
			{
				std::cout<< std::endl;
				while(1)
				{
					try
					{
						double limite = console::read<double>("Digite o limite de saque da conta:");
						if(limite<=0)
							throw excpt_operacoesBancarias::QuantiaNegativa();
						auto conta = bank.criar_conta(p->get_cpf_cnpj(), senha, tipoConta, saldo, limite);
						conta->dados_conta();
					}
					catch(std::exception& e)
					{
						std::cerr << e.what() << std::endl;
					}
				}
			}
			else
			{
				try
				{
					auto conta = bank.criar_conta(p->get_cpf_cnpj(), senha, tipoConta, saldo);
					conta->dados_conta();
				}catch(std::exception& e){
					std::cerr << e.what() << std::endl;
				}
			}
		}
	}

	void consultar_conta(banco& bank)
	{
		std::cout << std::endl;
		auto numeroconta = console::read<std::string>("Digite o numero da conta a ser consultada:");
		try
		{
			auto c = bank.get_conta(numeroconta);
			c->dados_conta();
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	void atualizar_conta(banco& bank)
	{
		std::cout << std::endl;
		auto numero_conta = console::read<std::string>("Digite o numero da conta a ser atualizada:");
		try{
			auto c = bank.get_conta(numero_conta);
			c->dados_conta();
			std::cout << std::endl;
			std::cout << std::endl;
			std::string menuConta = "Digite o tipo de Conta:\n";
			menuConta += "1-> Conta Corrente\n";
			menuConta += "2-> Conta Corrente com Limite\n";
			menuConta += "3-> Conta Poupanca\n";

			auto opc = console::readOp(1, 3, menuConta);
			if(opc==1)
			{
				if(c->get_tconta() == "Conta Corrente")
					throw excpt_Banco::Autoatualizacao();
				bank.atualizar_conta(c->get_numero(), 1);
			}
			else if(opc==2)
			{
				if(c->get_tconta() == "Conta Limite")
					throw excpt_Banco::Autoatualizacao();
				std::cout << std::endl;
				auto limit = console::read<double>("Digite o Limite de saque da conta:");
				bank.atualizar_conta(c->get_numero(), 2, limit);
			}
			else if(opc==3)
			{
				if(c->get_tconta() == "Conta Poupanca")
					throw excpt_Banco::Autoatualizacao();
				time_t t;
				time(&t);
				char buffer[30];
				strftime(buffer, 30, "%d/%m/%Y  %H-%M-%S", localtime(&t));
				bank.atualizar_conta(c->get_numero(), 3);
			}
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	void fechar_conta(banco& bank)
	{
		std::cout << std::endl;
		auto numero = console::read<std::string>("Digite o numero da conta:");
		try
		{
			bank.fechar_conta(numero);
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	void listar_contas(banco& bank)
	{
		auto contas = bank.listar_contas();
		for(auto c: contas)
		{
			c->dados_conta();
		}
	}

	void listar_contas_correntista(banco& bank)
	{
		std::cout << std::endl;
		auto nome = console::read<std::string>("Digite o Nome da Pessoa: ");
		auto cpf_cnpj = console::readCpf_Cnpj();
		try
		{
			auto p = bank.get_pessoa(nome, cpf_cnpj);
			auto contascorr = bank.listar_contas_correntista(p->get_cpf_cnpj());
			for(auto c: contascorr){
				c->dados_conta();
			}
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
