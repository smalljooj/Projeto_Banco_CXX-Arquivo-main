cmake_minimum_required(VERSION 3.15)
project(BANCO_CXX)

add_executable(BANCO_CXX)

target_sources(
	BANCO_CXX
	PRIVATE
	main.cpp
	banco.cpp
	conta_corrente.cpp
	conta_limite.cpp
	conta_poupanca.cpp
	menu.cpp
	pessoa.cpp
	pessoa_fisica.cpp
	pessoa_juridica.cpp
	gerente.cpp
	usuario.cpp
	IO.cpp

	)
