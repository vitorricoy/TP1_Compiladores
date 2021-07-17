#ifndef LEITOR_ARQUIVOS_H
#define LEITOR_ARQUIVOS_H

#include <string>
#include <map>

class TabelaSimbolos {
    private:
        map<string, int> tabela;
    public:
        TabelaSimbolos();

        int obterValorSimbolo(std::string simbolo);

        void salvarSimbolo(std::string simbolo, int valor);
}

#endif
