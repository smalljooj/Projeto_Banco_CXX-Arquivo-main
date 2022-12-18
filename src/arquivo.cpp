#include "arquivo.h"
#include <fstream>

namespace IO
{

arquivo* arquivo::arquivo_unique = nullptr;

arquivo::~arquivo()
{
	delete arquivo_unique;
}
arquivo * arquivo::get_instance()
{
	if(arquivo_unique == nullptr)
		arquivo_unique = new arquivo;
	return arquivo_unique;
}

arquivo* arquivo::salvar_arquivo(banco& bank, std::string const& nome_arquivo){
	std::ofstream arquivo_aberto(nome_arquivo, std::ios::trunc);	

	if(!arquivo_aberto)
		std::cerr << "Erro ao abrir arquivo" << std::endl;

	auto contas = bank.listar_contas();
	auto pessoas = bank.listar_pessoas();

	std::cout << "Pessoas salvas: " << pessoas.size() << std::endl;
	std::cout << "Contas salvas: " << contas.size() << std::endl;

	arquivo_aberto << "$" << "P\n";
	for(int i = 0; i<pessoas.size(); i++){

		arquivo_aberto << "$" << pessoas[i]->get_type() << ", ";
		arquivo_aberto << pessoas[i]->get_nome() << ", ";
		arquivo_aberto << pessoas[i]->get_data_nasc() << ", ";
		arquivo_aberto << pessoas[i]->get_cpf_cnpj() << ", ";
		arquivo_aberto << pessoas[i]->get_pos() << "\n";

	}
	arquivo_aberto << "$" << "C\n";
	for(int i = 0; i<contas.size(); i++){

		arquivo_aberto << "$" << contas[i]->get_tconta() << ", ";
		arquivo_aberto << contas[i]->get_numero() << ", ";
		arquivo_aberto << contas[i]->get_senha() << ", ";
		arquivo_aberto << contas[i]->get_saldo() << ", ";
		arquivo_aberto << contas[i]->get_pos() << ", ";
		arquivo_aberto << contas[i]->get_limite();

		std::vector<const transacao *> tran = contas[i]->get_transacoes();

		for(int j = 0; j<tran.size(); j++){
			arquivo_aberto << ", ";
			arquivo_aberto << tran[j]->get_data()<< ", ";
			arquivo_aberto << tran[j]->get_valor() << ", ";
			arquivo_aberto << tran[j]->get_descricao();
		}
		arquivo_aberto << "\n";

	}
	arquivo_aberto.close();
	return arquivo_unique;
}


arquivo* arquivo::ler_arquivo(banco& bank, std::string const& nome_arquivo){
	std::ifstream arquivo_aberto(nome_arquivo);

	if(!arquivo_aberto)
		std::cerr << "Erro ao abrir arquivo" << std::endl;

	std::string linha;
	bool pessoas = true;
	bool contas = false;

	while(std::getline(arquivo_aberto, linha)){

		if(arquivo_aberto.eof())
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
	arquivo_aberto.close();
	return arquivo_unique;
}

}
