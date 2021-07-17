#include <iostream>
#include <string>
#include <vector>

#include "util.h"
#include "montador.h"

Montador::Montador(std::string arquivoPrograma) {
    this->leitorArquivos = new LeitorArquivos(arquivoPrograma);
}

std::vector<std::vector<std::string>> Montador::executarPassoUm() {

    std::vector<std::vector<std::string>> resultado;

    std::vector<std::string> palavras;

    int numeroLinha = 0;

    while(!leitorArquivos.arquivoLidoAteFim()) {
        std::string linha = this->leitorArquivos.obterProximaLinha();

        linha = removeComentario(linha);

        palavras = separaPalavras(linha);

        if(palavras[0].back() == ':') {
            tabelaSimbolos.salvarSimbolo(palavras[0].substr(0, palavras[0].size()-1), numeroLinha);
            palavras.erase(palavras.begin());
        }

        for(int i=0; i<palavras.size(); i++) {
            if(palavras[i] == "WORD") {
                palavras.erase(palavras.begin() + i);
            }
        }
        
        if(palavras[0] == "END") {
            break;
        }

        numeroLinha += 1;

        resultado.push_back(palavras);
    }

    return resultado;
}

void Montador::executarPassoDois() {

}
