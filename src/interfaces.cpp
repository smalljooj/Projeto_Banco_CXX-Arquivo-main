#include "interfaces.h"
#include "IO.h"

interfaces* interfaces::interface_unique = nullptr;

interfaces* interfaces::get_instance()
{
	if(interface_unique == nullptr)
		interface_unique = new interfaces();
	return interface_unique;
}	        

void interfaces::depositar(banco& bank, std::shared_ptr<conta const> c)
{
	usuario_.depositar(bank, c);
}
void interfaces::retirar(banco& bank, std::shared_ptr<conta const> c)
{
	usuario_.retirar(bank, c);
}
void interfaces::transferir(banco& bank, std::shared_ptr<conta const> c)
{
	usuario_.transferir(bank, c);
}

void interfaces::saldo(banco& bank, std::shared_ptr<conta const> c)
{
	usuario_.saldo(bank, c);
}

void interfaces::extrato(banco& bank, std::shared_ptr<conta const> c)
{
	usuario_.extrato(bank, c);
}

void interfaces::abrir_conta(banco& bank)
{
	gerente_.abrir_conta(bank);
}

void interfaces::consultar_conta(banco& bank)
{
	gerente_.consultar_conta(bank);
}

void interfaces::atualizar_conta(banco& bank)
{
	gerente_.atualizar_conta(bank);
}

void interfaces::fechar_conta(banco& bank)
{
	gerente_.fechar_conta(bank);
}

void interfaces::listar_contas(banco& bank)
{
	gerente_.listar_contas(bank);
}

void interfaces::listar_contas_correntista(banco& bank)
{
	gerente_.listar_contas(bank);
}
