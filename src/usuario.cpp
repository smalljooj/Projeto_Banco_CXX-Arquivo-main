#include "usuario.h"

void usuario::depositar(banco& bank, std::shared_ptr<conta const> c)
{
	std::cout<< std::endl;
	double d;
	while(1){
		try{
			d = console::read<double>("Digite o valor a ser depositado:");
			bank.operacoes_do_usuario(1, d, c->get_numero());
			break;
		}catch(std::exception& e){
			std::cerr << e.what() << std::endl;
			auto sn = console::readOp(0, 1, "Deseja tentar novamente? (1->Sim ,0->Nao)");
			if(!sn)
				break;
		}
	}
}
void usuario::retirar(banco& bank, std::shared_ptr<conta const> c)
{
	std::cout<< std::endl;
	double r;
	while(1){
		try{
			r = console::read<double>("Digite o valor a ser retirado:");
			bank.operacoes_do_usuario(2, r, c->get_numero());
			break;
		}catch(std::exception& e){
			std::cerr << e.what() << std::endl;
			auto sn = console::readOp(0, 1, "Deseja tentar novamente? (1->Sim ,0->Nao)");
			if(!sn)
				break;
		}
	}
}
void usuario::transferir(banco& bank, std::shared_ptr<conta const> c)
{
	std::cout<< std::endl;
	while(1){
		std::string n;
		n = console::read<std::string>("Digite o numero da conta para onde vai ser transferido:");
		try{
			while(1){
				double t;
				t = console::read<double>("Digite o valor a ser transferido:");
				try{
					bank.operacoes_do_usuario(3, t, c->get_numero(), n);
					break;
				}catch(std::exception& e){
					std::cerr << e.what() << std::endl;
					auto sn = console::readOp(0, 1, "Deseja tentar novamente? (1->Sim ,0->Nao)");
					if(!sn)
						break;
				}
			}
			break;
		}catch(std::exception& e){
			std::cerr << e.what() << std::endl;
			auto sn = console::readOp(0, 1, "Deseja tentar novamente? (1->Sim ,0->Nao)");
			if(!sn)
				break;
		}
		std::cout<< std::endl;
	}
}
void usuario::saldo(banco& bank, std::shared_ptr<conta const> c)
{
	std::cout<< c->get_saldo() << std::endl;
}
void usuario::extrato(banco& bank, std::shared_ptr<conta const> c)
{
	c->extrato();
}