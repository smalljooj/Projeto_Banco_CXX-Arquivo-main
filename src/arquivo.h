#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <fstream>
#include "banco.h"

namespace IO
{

class arquivo 
{
protected:
	static arquivo* arquivo_unique;

	arquivo(){}
	~arquivo();

public:
	arquivo(arquivo&) = delete;
	arquivo& operator=(arquivo const&) = delete;


	static arquivo * get_instance();	

	arquivo * salvar_arquivo(banco&, std::string const& = "../dat/DadosDoBanco.csv");
	arquivo * ler_arquivo(banco&, std::string  const& = "../dat/DadosDoBanco.csv");

};

}


#endif
