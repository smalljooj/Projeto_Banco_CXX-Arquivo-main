#ifndef USUARIOS_H
#define USUARIOS_H

#include "banco.h"
#include "gerente.h"
#include "usuario.h"

class interfaces 
{
	static interfaces* interface_unique;

	interfaces(){}
	~interfaces(){ delete interface_unique; }

	gerente gerente_;
	usuario usuario_;
public:
	interfaces(interfaces&) = delete;
	interfaces& operator=(interfaces const&) = delete;


	static interfaces* get_instance();	         

	void depositar(banco&, std::shared_ptr<conta const>);
	void retirar(banco&, std::shared_ptr<conta const>);
	void transferir(banco&, std::shared_ptr<conta const>);
	void saldo(banco&, std::shared_ptr<conta const>);
	void extrato(banco&, std::shared_ptr<conta const>);

	void abrir_conta(banco&);
	void consultar_conta(banco&);
	void atualizar_conta(banco&);
	void fechar_conta(banco&);
	void listar_contas(banco&);
	void listar_contas_correntista(banco&);

};

#endif
