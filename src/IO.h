#ifndef IO_H 
#define IO_H

#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>

#include "exceptions.h"
#include "banco.h"

namespace console{

	template<class T>
		T read(std::string msg = ""){
			T value;
			std::string buffer;
			while(1){
				try{
					if(msg != "")
						std::cout << msg << std::endl;
					std::cout << "# ";
					std::getline(std::cin, buffer);
					std::stringstream ss(buffer);
					if(!(ss>> value))
						throw excpt_leitura::ErroDeLeitura(); 

					for(auto val: buffer) 
						if(((val<48 && val>59) && (val!=46) && (val!=45)))
							throw excpt_leitura::ErroDeLeitura(); 

				}
				catch(std::exception &e){
					std::cout << std::endl;
					std::cerr << e.what() << std::endl;
					continue;
				}
				break;	
			}
			return value;
		}
	template<>
		std::string read(std::string msg );

	std::string readDataNasc(std::string msg = "");
	std::string readCpf_Cnpj();
	int readOp(int i, int f, std::string msg = "");

}

#endif
