#ifndef GERENTE_H
#define GERENTE_H

#include <iostream>
#include "exceptions.h"
#include "IO.h"
#include "banco.h"

class gerente
{

public:
	void abrir_conta(banco&);
	void consultar_conta(banco&);
	void atualizar_conta(banco&);
	void fechar_conta(banco&);
	void listar_contas(banco&);
	void listar_contas_correntista(banco&);

};

#endif