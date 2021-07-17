#include <iostream>

#include "montador.h"

Montador::Montador(std::string arquivoPrograma) {
    this->leitorArquivos = new LeitorArquivos(arquivoPrograma);
}

void Montador::executarPassoUm() {

}

std::vector<int> Montador::executarPassoDois(std::vector<std::vector<std::string> > tokens) {
    std::vector<int> resultadoFinal;
    for(std::vector<std::string> linha : this->tokens) {
        std::vector<int> codigoMaquina = Conversor::converterInstrucao(linha);
        resultadoFinal.insert(resultadoFinal.end(), codigoMaquina.begin(), codigoMaquina.end());
    }
    return resultadoFinal;
}
