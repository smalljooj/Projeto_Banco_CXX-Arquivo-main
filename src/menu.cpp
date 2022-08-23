#include "menu.h"
#include <memory>
#include <iomanip>

void menu(banco& bank)
{
	int op = 0;
	while(1)
	{
		std::cout << std::endl;
		std::cout << "--------->Sistema Bancario ";
		std::cout << bank.get_nome_banco() << "<-----------\n" << std::endl;
		std::cout << "Digite o numero da sua conta: " << std::endl;
		std::cout << "( -1 -> sair )" << std::endl;
		auto num = console::read<std::string>();
		if(num == "admin")
			op = secao_gerente(bank);
		else
		{
			try
			{	
				auto c = bank.get_conta(num);
				auto senha_ = console::read<int>("Digite a senha da sua conta: ");
				if(c->verificar_senha(senha_))
					op = secao_usuario(bank, c);
				else
					std::cout << "Senha Inválida" << std::endl;
			}
			catch(std::exception& e)
			{
				if(num == "-1")
				{
					break;
				}
			std::cerr << e.what() << std::endl;
			continue;
			}
		}
		if(op == 0)
		{
			break;
		}
	}
}

int secao_usuario(banco& bank, std::shared_ptr<conta const> c)
{
	int op;
	std::cout<< std::endl;
	while(1){

		std::cout << std::endl;
		std::cout << c->get_pessoa()->get_nome() << std::endl;
		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << "Saldo                                         Numero" << std::endl;
		std::cout << "R$ " << std::left << std::setw(10) << std::setprecision(3) << c->get_saldo();
		std::cout << "                           " << c->get_numero() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::string menu_usuario = "Escolha a operacao desejada:\n";
		menu_usuario += "1-> Depositar\n";
		menu_usuario += "2-> Retirar\n";
		menu_usuario += "3-> Transferir\n";
		menu_usuario += "4-> Saldo \n";
		menu_usuario += "5-> Extrato\n";
		menu_usuario += "0-> Sair\n";
		op = console::readOp(0, 5, menu_usuario);

		switch(op)
		{
			case 1:
				usuario::depositar(bank, c);
				break;
			case 2:
				usuario::retirar(bank, c);
				break;
			case 3:
				usuario::transferir(bank, c);
				break;
			case 4:
				usuario::saldo(bank, c);
				break;
			case 5:
				usuario::extrato(bank, c);
				break;
			default:
				std::cout<< std::endl;
				std::string menu_op = "Deseja sair do sistema ou deslogar?\n";
				menu_op += "( continuar -> 2, deslogar -> 1, sair -> 0 )...";
				op = console::readOp(0,2, menu_op);
				if(op == 2)
					continue;
				return op;
		}
	}
}
int secao_gerente(banco& bank)
{
	int op;
	std::cout<< std::endl;
	while(1)
	{
		std::cout << std::endl;
		std::cout <<"ADMIN" << std::endl;
		std::cout << "----------------------------------------------------" << std::endl;
		std::string menu_gerente = "Escolha a operacao desejada:\n";
		std::cout << std::endl;
		std::cout << std::endl;

		menu_gerente += "1-> Abrir conta\n";
		menu_gerente += "2-> Consultar conta\n";
		menu_gerente +=	"3-> Atualizar tipo da conta\n";
		menu_gerente +=	"4-> Fechar conta\n";
		menu_gerente +=	"5-> Listar Contas\n";
		menu_gerente +=	"6-> Listar Contas de um Correntista\n";
		menu_gerente +=	"0-> Sair";
		op = console::readOp(0, 6, menu_gerente);

		switch(op)
		{
			case 1:
				gerente::abrir_conta(bank);
				break;
			case 2:
				gerente::consultar_conta(bank);
				break;
			case 3:
				gerente::atualizar_conta(bank);
				break;
			case 4:
				gerente::fechar_conta(bank);
				break;
			case 5:
				gerente::listar_contas(bank);
				break;
			case 6:
				gerente::listar_contas_correntista(bank);
				break;
			default:
				std::cout<< std::endl;
				std::string menu_op = "Deseja sair do sistema ou deslogar?\n";
				menu_op += "( continuar -> 2, deslogar -> 1, sair -> 0 )...";
				op = console::readOp(0,2, menu_op);
				if(op == 2)
					continue;
				return op;
		}
	}
	return 0;
}
