#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <memory>

#include "banco.h"
#include "IO.h"

class usuario
{
public:
	void depositar(banco&, std::shared_ptr<conta const>);
	void retirar(banco&, std::shared_ptr<conta const>);
	void transferir(banco&, std::shared_ptr<conta const>);
	void saldo(banco&, std::shared_ptr<conta const>);
	void extrato(banco&, std::shared_ptr<conta const>);
};

#endif