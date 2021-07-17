#ifndef MONTADOR_H
#define MONTADOR_H

#include <iostream>

#include "leitor_arquivos.h"
#include "tabela_simbolos.h"

class Montador {
    private:
        LeitorArquivos leitorArquivos;
        TabelaSimbolos tabelaSimbolos;
    public:
        void Montador(std::string arquivoPrograma);
        void executarPassoUm();
        void executarPassoDois();
};

#endif
