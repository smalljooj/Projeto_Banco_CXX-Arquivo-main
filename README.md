# Sistema de banco

## Detalhes:

O sistema conta com 2 pastas uma para os arquivos fonte(src) e outra(dat) para o arquivo que irá guardar
os dados do Banco.

## Comentarios:
O sistema possui o banco em si(.cpp/h) e outras classes auxiliares que formam o banco.
A parte visual foi separada e está nos arquivos de menu(.h/cpp), usuario(.h/cpp) e gerente(.h/cpp).
As exceptions estão em um arquivo chamado exceptions.h.
E as todas as funcoes customizadas de entrada e saida estao no arquivo IO(.h/cpp)

É aconselhado o uso do cmake para compilar, utilize os seguintes comandos para utilizar:
- > cmake -S src -B build -G "MinGW Makefiles"
- > cmake --build build
- > cd build
- > ./BANCO_CXX

Ou use a forma que desejar.

## Executando...
Para entrar na parte do gerente no menu utilize o "admin" como login.
Para entrar na parte do usuario digite o numero da conta ja criada e sua senha.

Os numeros das contas sao gerados "automaticamente".

