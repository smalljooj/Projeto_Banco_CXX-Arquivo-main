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


namespace arquivo{

	void salvar_arquivo(banco& bank){
		std::ofstream arquivo("../dat/DadosDoBanco.csv", std::ios::trunc);	

		auto contas = bank.listar_contas();
		auto pessoas = bank.listar_pessoas();

		std::cout << "Pessoas salvas: " << pessoas.size() << std::endl;
		std::cout << "Contas salvas: " << contas.size() << std::endl;

		arquivo << "$" << "P\n";
		for(int i = 0; i<pessoas.size(); i++){

			arquivo << "$" << pessoas[i]->get_type() << ", ";
			arquivo << pessoas[i]->get_nome() << ", ";
			arquivo << pessoas[i]->get_data_nasc() << ", ";
			arquivo << pessoas[i]->get_cpf_cnpj() << ", ";
			arquivo << pessoas[i]->get_pos() << "\n";

		}
		arquivo << "$" << "C\n";
		for(int i = 0; i<contas.size(); i++){

			arquivo << "$" << contas[i]->get_tconta() << ", ";
			arquivo << contas[i]->get_numero() << ", ";
			arquivo << contas[i]->get_senha() << ", ";
			arquivo << contas[i]->get_saldo() << ", ";
			arquivo << contas[i]->get_pos() << ", ";
			arquivo << contas[i]->get_limite();

			std::vector<const transacao *> tran = contas[i]->get_transacoes();

			for(int j = 0; j<tran.size(); j++){
				arquivo << ", ";
				arquivo << tran[j]->get_data()<< ", ";
				arquivo << tran[j]->get_valor() << ", ";
				arquivo << tran[j]->get_descricao();
			}
			arquivo << "\n";

		}
		arquivo.close();
	}

	void ler_arquivo(banco& bank){
		std::ifstream arquivo("../dat/DadosDoBanco.csv");

		std::string linha;
		bool pessoas = true;
		bool contas = false;

		while(std::getline(arquivo, linha)){

			if(arquivo.eof())
				break;

			if(linha == "$P")
				continue;
			else if(linha=="$C"){
				pessoas = false;
				contas = true;
				continue;
			}

			if(pessoas){
				int cont = 0;
				std::string buffer = "";
				int type;
				std::string nome;
				std::string data_nasc;
				std::string cpf_cnpj;
				int pos;

				for(int i = 0; i<linha.size(); i++){
					if(linha[i]==','){
						i++;
						if(cont==0){
							if(buffer=="$Pessoa Fisica")
								type = 1;
							else 
								type = 2;
						}
						else if(cont==1){
							nome = buffer;
						}
						else if(cont==2){
							data_nasc = buffer;
						}
						else if(cont==3){
							cpf_cnpj = buffer;
						}
						else if(cont==4){
							pos = std::stoi(buffer);
						}
						cont++;
						buffer = "";
					}
					else
						buffer+=linha[i];
				}
				bank.criar_pessoa(nome, data_nasc, cpf_cnpj, type);
			}

			if(contas){

				int cont = 0;
				std::string buffer = "";
				int type;
				std::string numero;
				double saldo;
				int pos = 0;
				int senha = 0;
				double limite = 0;
				int i;

				for(i = 0; i<linha.size(); i++){
					if(linha[i]==','){
						i++;
						if(cont==0){
							if(buffer=="$Conta Corrente")
								type = 1;
							else if(buffer=="$Conta Limite")
								type = 2;
							else 
								type = 3;
						}
						else if(cont==1){
							numero = buffer;
						}
						else if(cont==2)
						{
							senha = std::stoi(buffer);
						}
						else if(cont==3){
							saldo = std::stod(buffer);
						}
						else if(cont==4)
							pos = std::stoi(buffer);
						else if(cont==5){
							limite = std::stod(buffer);
							break;
						}
						cont++;
						buffer = "";

					}
					else{
						buffer+=linha[i];
						if(linha[i]== '\n' && cont==5)
							limite = std::stod(buffer);
					}
				}

				auto conta_ = bank.criar_conta(bank.get_pessoa(pos)->get_cpf_cnpj(), senha, type, saldo, limite);

				std::vector<transacao> tran;
				std::string data;
				double valor;
				std::string desc;
				buffer = "";
				cont = 0;

				for(int j = i+1; j<= linha.size(); j++){
					if(linha[j]==',' || j==linha.size()){
						j++;
						if(cont==0){
							data = buffer;
							cont++;
						}
						else if(cont==1){
							valor = std::stod(buffer);
							cont++;
						}
						else if(cont==2){
							desc = buffer;
							cont =0;
							tran.push_back(transacao(data, valor, desc));
						}
						buffer = "";
					}
					else{
						buffer+=linha[j];
					}
				}
                conta_->set_transacoes(tran);
			}
		}
		arquivo.close();
	}
}
