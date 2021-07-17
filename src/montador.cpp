#include <iostream>
#include <string>
#include <vector>

#include "util.h"
#include "montador.h"
#include "conversor_instrucoes.h"

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

std::vector<int> Montador::executarPassoDois(std::vector<std::vector<std::string> > tokens) {
    std::vector<int> resultadoFinal;
    for(std::vector<std::string> linha : this->tokens) {
        std::vector<int> codigoMaquina = Conversor::converterInstrucao(linha);
        resultadoFinal.insert(resultadoFinal.end(), codigoMaquina.begin(), codigoMaquina.end());
    }
    return resultadoFinal;
}

std::string Montador::gerarPrograma(std::vector<int> instrucoes) {
    string saida = "MV-EXE\n";
    saida+=to_string(instrucoes.size());
    saida+=" 0 999 0\n";
    for(int inteiro : instrucoes) {
        saida+=to_string(inteiro) + " ";
    }
    saida+= "\n";
    return saida;
}
