#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

namespace excpt_leitura{

	class ErroDeLeitura: public std::runtime_error{
	public:
			ErroDeLeitura(const char * err = "Erro ao ler o valor inserido...\nDigite corretamente o que se pede.\n"): runtime_error(err){}
	};
	class ForaDeFaixa: public std::runtime_error{
	public:
			ForaDeFaixa(const char * err = "Erro ao ler o valor inserido...\nDigite o valor entre a faixa pedida.\n"): runtime_error(err){}
	};
	class Cpf_Cnpj_Invalido: public std::runtime_error{
	public:
			Cpf_Cnpj_Invalido(const char * err = "Digite o cpf/cnpj Corretamente\n"): runtime_error(err){}
	};
	class DataNascInvalida: public std::runtime_error{
	public:
			DataNascInvalida(const char * err = "Digite a data de Nascimento Corretamente\n"): runtime_error(err){}
	};

}

namespace excpt_operacoesBancarias{

	class SaldoInsuficiente: public std::runtime_error{
	public:
			SaldoInsuficiente(const char * err = "Valor invalido\nSaldo insuficiente para realizar o saque.\n"): runtime_error(err){}
	};
	class QuantiaNegativa: public std::runtime_error{
	public:
			QuantiaNegativa(const char * err = "Valor invalido\nNao e permitido valor negativo ou igual a zero.\n"): runtime_error(err){}
	};
	class ForaDeLimite: public std::runtime_error{
	public:
			ForaDeLimite(const char * err = "Valor excede o limite de sua conta.\n"): runtime_error(err){}
	};

}

namespace excpt_Banco{

	class ErroaoBuscarConta: public std::runtime_error{
	public:
			ErroaoBuscarConta(const char * err = "Nao foi possivel encontrar a Conta informada.\n"): runtime_error(err){}
	};
	class ErroaoBuscarPessoa: public std::runtime_error{
	public:
			ErroaoBuscarPessoa(const char * err = "Nao foi possivel encontrar a Pessoa informada.\n"): runtime_error(err){}
	};
	class ErroaoFecharConta: public std::runtime_error{
	public:
			ErroaoFecharConta(const char * err = "Nao foi possivel fechar a conta informada.\n"): runtime_error(err){}
	};
	class ErroaoCriarPessoa: public std::runtime_error{
	public:
			ErroaoCriarPessoa(const char * err = "Nao foi possivel criar a Pessoa.\n"): runtime_error(err){}
	};
	class ErroaoAtualizarConta: public std::runtime_error{
	public:
			ErroaoAtualizarConta(const char * err = "Nao foi possivel atualizar a Pessoa.\n"): runtime_error(err){}
	};
	class ErroaoCriarConta: public std::runtime_error{
	public:
			ErroaoCriarConta(const char * err = "Nao foi possivel criar a conta.\n"): runtime_error(err){}
	};
	class Autoatualizacao: public std::runtime_error{
	public:
			Autoatualizacao(const char * err = "A conta ja e deste tipo.\n"): runtime_error(err){}
	};

}


#endif

