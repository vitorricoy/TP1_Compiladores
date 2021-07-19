#include <iostream>
#include <vector>
#include <utility>

#include "util.h"
#include "montador.h"
#include "leitor_arquivos.h"
#include "tabela_simbolos.h"
#include "conversor_instrucoes.h"

Montador::Montador(std::string arquivoPrograma): leitorArquivos(arquivoPrograma){

}

std::vector<std::vector<std::string>> Montador::executarPassoUm() {

    std::vector<std::vector<std::string>> resultado;

    std::vector<std::string> palavras;

    int numeroLinha = 0;

    while(!leitorArquivos.arquivoLidoAteFim()) {
        std::string linha = this->leitorArquivos.obterProximaLinha();

        linha = removeComentario(linha);

        palavras = separaPalavras(linha);

        if(palavras.empty()) {
            continue;
        }
        if(palavras[0].back() == ':') {
            tabelaSimbolos.salvarSimbolo(palavras[0].substr(0, palavras[0].size()-1), numeroLinha);
            palavras.erase(palavras.begin());
        }

        if(palavras[0] == "WORD") {
            palavras.erase(palavras.begin());
        }
        
        if(palavras[0] == "END") {
            break;
        }

        numeroLinha += tamanhoInstrucao(palavras[0]);

        if(palavras[0] == "") {
            continue;
        }
        resultado.push_back(palavras);
    }

    return resultado;
}

std::vector<int> Montador::executarPassoDois(std::vector<std::vector<std::string> > tokens) {
    std::vector<int> resultadoFinal;
    int linhaAtual = 0;
    int constantesInicioAux = 0; // Identificar quantas constantes existem no inicio do programa
    for(std::vector<std::string> linha : tokens) {
        int constantesInicioAntiga = constantesInicioAux;
        std::vector<int> codigoMaquina = Conversor::converterInstrucao(linha, this->tabelaSimbolos, linhaAtual, constantesInicioAux);
        if(constantesInicioAntiga == constantesInicioAux) { // Se acabaram as constantes no começo do programa
            this->constantesInicio = constantesInicioAntiga; // Salva o numero de constantes no inicio
        }
        resultadoFinal.insert(resultadoFinal.end(), codigoMaquina.begin(), codigoMaquina.end());
    }
    return resultadoFinal;
}

std::string Montador::gerarPrograma(std::vector<int> instrucoes) {
    std::string saida = "MV-EXE\n";
    saida+=std::to_string(instrucoes.size());
    saida+=" 0 999 ";
    saida+=std::to_string(this->constantesInicio) + "\n";
    for(int inteiro : instrucoes) {
        saida+=std::to_string(inteiro) + " ";
    }
    saida+= "\n";
    return saida;
}
