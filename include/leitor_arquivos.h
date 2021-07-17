#ifndef LEITOR_ARQUIVOS_H
#define LEITOR_ARQUIVOS_H

#include <fstream>
#include <string>

class LeitorArquivos {
    private:
        std::ifstream arquivo;
    public:
        ~LeitorArquivos();

        LeitorArquivos(std::string nomeArquivo);

        bool arquivoLidoAteFim();

        std::string obterProximaLinha();
};

#endif
