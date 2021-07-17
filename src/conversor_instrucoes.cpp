#include <iostream>
#include <vector>
#include <string>

#include "conversor_instrucoes.h"
#include "tabela_simbolos.h"

int Conversor::converterOperando(std::string operando, TabelaSimbolos& tabela) {
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
        return tabela.obterValorSimbolo(operando);
    }
    return stoi(operando); // Posição de memória
}

std::vector<int> Conversor::converterInstrucao(std::vector<std::string> instrucao, TabelaSimbolos& tabela) {
    std::string mnemonico = instrucao[0];
    std::vector<int> retorno;
    if(mnemonico == "HALT") {
        return {0};
    }
    
    if(mnemonico == "LOAD") {
        retorno.push_back(1);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "STORE") {
        retorno.push_back(2);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "READ") {
        retorno.push_back(3);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "WRITE") {
        retorno.push_back(4);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "COPY") {
        retorno.push_back(5);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "PUSH") {
        retorno.push_back(6);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "POP") {
        retorno.push_back(7);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "ADD") {
        retorno.push_back(8);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "SUB") {
        retorno.push_back(9);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "MUL") {
        retorno.push_back(10);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "DIV") {
        retorno.push_back(11);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "MOD") {
        retorno.push_back(12);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "AND") {
        retorno.push_back(13);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "OR") {
        retorno.push_back(14);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        retorno.push_back(converterOperando(instrucao[2], tabela));
        return retorno;
    }

    if(mnemonico == "NOT") {
        retorno.push_back(15);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "JUMP") {
        retorno.push_back(16);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "JZ") {
        retorno.push_back(17);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "JN") {
        retorno.push_back(18);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "CALL") {
        retorno.push_back(19);
        retorno.push_back(converterOperando(instrucao[1], tabela));
        return retorno;
    }

    if(mnemonico == "RET") {
        return {20};
    }
    // É uma constante
    return {stoi(mnemonico)};
}
