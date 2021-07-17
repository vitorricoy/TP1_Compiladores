#ifndef MONTADOR_H
#define MONTADOR_H

#include "leitor_arquivos.h"
#include "tabela_simbolos.h"

class Montador {
    private:
        LeitorArquivos leitorArquivos;
        TabelaSimbolos tabelaSimbolos;
    public:
        void executarPassoUm();
        void executarPassoDois();
        void montarPrograma(std::string arquivoPrograma);
}

#endif
