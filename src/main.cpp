#include <iostream>
#include "menu.h"

int main()try{

	std::string nome = "jose";
	std::string data = "12/12/1950";
	std::string cnpj= "01.123.123/1234-12";

	banco banquito{nome, data, cnpj, "banquito"};
	arquivo::ler_arquivo(banquito);

	menu(banquito);

	arquivo::salvar_arquivo(banquito);
	return 0;
}catch(...){}
