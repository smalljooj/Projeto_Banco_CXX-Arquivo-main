#include "IO.h"

namespace console
{
template<>
    std::string read(std::string msg){

        std::string buffer = "";
        while(1){
            try{
                if(msg != "")
                    std::cout << msg << std::endl;
                std::cout << "# ";
                std::getline(std::cin, buffer);

                if((buffer == ""))
                    throw excpt_leitura::ErroDeLeitura(); 
            }
            catch(std::exception &e){
                std::cout << std::endl;
                std::cerr << e.what() << std::endl;
                continue;
            }
            break;	
        }
        return buffer;
    };

	std::string readDataNasc(std::string msg){

		std::string data_nasc= "";
		while(1){
			try{

				data_nasc = console::read<std::string>(msg);

				std::string dia = "";
				std::string mes = "";
				std::string ano = "";
				int d, m, y;
				if(data_nasc.size()!=10)
					throw excpt_leitura::DataNascInvalida();
				if(std::isdigit(data_nasc[0])==0)throw excpt_leitura::DataNascInvalida();
				if(std::isdigit(data_nasc[1])==0)throw excpt_leitura::DataNascInvalida();
				if(!(data_nasc[2] == '/'))throw excpt_leitura::DataNascInvalida() ;
				if(std::isdigit(data_nasc[3])==0)throw excpt_leitura::DataNascInvalida();
				if(std::isdigit(data_nasc[4])==0)throw excpt_leitura::DataNascInvalida();
				if(!(data_nasc[5] == '/'))throw excpt_leitura::DataNascInvalida();
				if(std::isdigit(data_nasc[6])==0)throw excpt_leitura::DataNascInvalida();
				if(std::isdigit(data_nasc[7])==0)throw excpt_leitura::DataNascInvalida();
				if(std::isdigit(data_nasc[8])==0)throw excpt_leitura::DataNascInvalida();
				if(std::isdigit(data_nasc[9])==0)throw excpt_leitura::DataNascInvalida();

				const char * str = data_nasc.c_str();

				dia.append(data_nasc, 0, 2);
				mes.append(data_nasc, 3, 2);
				ano.append(data_nasc, 6, 4);
				d = std::stoi(dia);
				m = std::stoi(mes);
				y = std::stoi(ano);
				if(!(m>0 && m<13))return 0;
				if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && (d<1 || d>31))throw excpt_leitura::DataNascInvalida();
				if((m==4 || m==6 || m==9 || m==11 ) && (d<1 || d>30)) throw excpt_leitura::DataNascInvalida();
				if(y%4==0){
					if((m==2) && (d<1 || d>29)) throw excpt_leitura::DataNascInvalida();
				}
				else
					if((m==2) && (d<1 || d>28)) throw excpt_leitura::DataNascInvalida();
			}
			catch(std::exception &e){
				std::cout << std::endl;
				std::cerr << e.what() << std::endl;
				continue;
			}
			break;	
		}
		return data_nasc;
	}
    std::string readCpf_Cnpj(){
            std::string msg = "Digite o Cpf/Cnpj da pessoa:   (xxx.xxx.xxx-xx)  (xx.xxx.xxx/xxxx-xx)";
            std::string cpf_cnpj= "";
            while(1){
                try{
                    cpf_cnpj = console::read<std::string>(msg);

                    if(cpf_cnpj.size()==18){
                        if(std::isdigit(cpf_cnpj[0])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[1])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(!(cpf_cnpj[2] == '.')) throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[3])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[4])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[5])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(!(cpf_cnpj[6] == '.'))throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[7])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[8])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[9])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(!(cpf_cnpj[10] == '/'))throw excpt_leitura::Cpf_Cnpj_Invalido() ;
                        if(std::isdigit(cpf_cnpj[11])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[12])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[13])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[14])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(!(cpf_cnpj[15] == '-'))throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[16])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[17])==0)throw excpt_leitura::ErroDeLeitura();
                    }
                    else if(cpf_cnpj.size()==14){
                        if(std::isdigit(cpf_cnpj[0])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[1])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[2])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(!(cpf_cnpj[3] == '.'))throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[4])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[5])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[6])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(!(cpf_cnpj[7] == '.')) throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[8])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[9])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[10])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(!(cpf_cnpj[11] == '-')) throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[12])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                        if(std::isdigit(cpf_cnpj[13])==0)throw excpt_leitura::Cpf_Cnpj_Invalido();
                    }
                    else
                        throw excpt_leitura::Cpf_Cnpj_Invalido();
                }
                catch(std::exception &e){
                    std::cout << std::endl;
                    std::cerr << e.what() << std::endl;
                    continue;
                }
                break;	
            }
            return cpf_cnpj;
        }

	int readOp(int i, int f, std::string msg){
		int value;
		while(1){
			try{
				value = console::read<int>(msg);
				if(value<i || value>f)
					throw excpt_leitura::ForaDeFaixa();

			}
			catch(std::exception &e){
				std::cout << std::endl;
				std::cerr << e.what() << std::endl;
				continue;
			}
			break;	
		}
		return value;
	};
}


