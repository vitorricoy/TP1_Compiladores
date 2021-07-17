#ifndef MONTADOR_H
#define MONTADOR_H

#include <iostream>
#include <vector>

#include "leitor_arquivos.h"
#include "tabela_simbolos.h"

class Montador {
    private:
        LeitorArquivos leitorArquivos;
        TabelaSimbolos tabelaSimbolos;
    public:
        Montador(std::string arquivoPrograma);
        std::vector<std::vector<std::string>> executarPassoUm();
        std::vector<int> executarPassoDois(std::vector<std::vector<std::string>> tokens);
        std::string gerarPrograma(std::vector<int> instrucoes);

};

#endif
