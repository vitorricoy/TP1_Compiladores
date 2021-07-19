#include <iostream>
#include <vector>
#include <string>

#include "conversor_instrucoes.h"
#include "tabela_simbolos.h"

int Conversor::converterOperando(std::string operando, TabelaSimbolos& tabela, int& linhaAtual) {
    if(operando == "R0") {
        return 0;
    }

    if(operando == "R1") {
        return 1;
    }
    
    if(operando == "R2") {
        return 2;
    }

    if(operando == "R3") {
        return 3;
    }

    if(tabela.simboloEstaRegistrado(operando)) {
        return tabela.obterValorSimbolo(operando)-linhaAtual;
    }
    return stoi(operando); // Posição de memória
}

std::vector<int> Conversor::converterInstrucao(std::vector<std::string> instrucao, TabelaSimbolos& tabela, int& linhaAtual, int& constantesInicio) {
    std::string mnemonico = instrucao[0];
    std::vector<int> retorno;
    if(mnemonico == "HALT") {
        linhaAtual+=1;
        return {0};
    }
    
    if(mnemonico == "LOAD") {
        linhaAtual+=3;
        retorno.push_back(1);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "STORE") {
        linhaAtual+=3;
        retorno.push_back(2);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "READ") {
        linhaAtual+=2;
        retorno.push_back(3);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "WRITE") {
        linhaAtual+=2;
        retorno.push_back(4);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "COPY") {
        linhaAtual+=3;
        retorno.push_back(5);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "PUSH") {
        linhaAtual+=2;
        retorno.push_back(6);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "POP") {
        linhaAtual+=2;
        retorno.push_back(7);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "ADD") {
        linhaAtual+=3;
        retorno.push_back(8);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "SUB") {
        linhaAtual+=3;
        retorno.push_back(9);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "MUL") {
        linhaAtual+=3;
        retorno.push_back(10);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "DIV") {
        linhaAtual+=3;
        retorno.push_back(11);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "MOD") {
        linhaAtual+=3;
        retorno.push_back(12);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "AND") {
        linhaAtual+=3;
        retorno.push_back(13);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "OR") {
        linhaAtual+=3;
        retorno.push_back(14);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        retorno.push_back(converterOperando(instrucao[2], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "NOT") {
        linhaAtual+=2;
        retorno.push_back(15);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "JUMP") {
        linhaAtual+=2;
        retorno.push_back(16);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "JZ") {
        linhaAtual+=2;
        retorno.push_back(17);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "JN") {
        linhaAtual+=2;
        retorno.push_back(18);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "CALL") {
        linhaAtual+=2;
        retorno.push_back(19);
        retorno.push_back(converterOperando(instrucao[1], tabela, linhaAtual));
        return retorno;
    }

    if(mnemonico == "RET") {
        linhaAtual+=1;
        return {20};
    }
    linhaAtual+=1;
    // É uma constante
    constantesInicio++;
    return {stoi(mnemonico)};
}
