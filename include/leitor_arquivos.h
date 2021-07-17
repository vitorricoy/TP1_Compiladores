#ifndef LEITOR_ARQUIVOS_H
#define LEITOR_ARQUIVOS_H

#include <fstream>
#include <string>

class LeitorArquivos {
    private:
        ifstream arquivo;
    public:
        LeitorArquivos(std::string nomeArquivo);

        bool arquivoLidoAteFim();

        std::string obterProximaLinha();
}

#endif
