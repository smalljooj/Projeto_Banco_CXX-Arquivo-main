#ifndef MENU_H
#define MENU_H

#include <memory>
#include <vector>

#include "gerente.h"
#include "usuario.h"

void menu(banco&);
int secao_usuario(banco&, std::shared_ptr<conta const>);
int secao_gerente(banco&);


#endif
