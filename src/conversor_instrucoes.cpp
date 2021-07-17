#include <iostream>
#include <string>

#include "conversor_instrucoes.h"

int converterOperando(std:string operando) {
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

    return stoi(operando); // Posição de memória
}

std::vector<int> Conversor::converterInstrucao(std::vector<std::string> instrucao) {
    std::string mnemonico = instrucao[0];
    vector<int> retorno;
    if(mnemonico == "HALT") {
        return {0};
    }
    
    if(mnemonico == "LOAD") {
        retorno.pb(1);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "STORE") {
        retorno.pb(2);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "READ") {
        retorno.pb(3);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "WRITE") {
        retorno.pb(4);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "COPY") {
        retorno.pb(5);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "PUSH") {
        retorno.pb(6);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "POP") {
        retorno.pb(7);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "ADD") {
        retorno.pb(8);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "SUB") {
        retorno.pb(9);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "MUL") {
        retorno.pb(10);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "DIV") {
        retorno.pb(11);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "MOD") {
        retorno.pb(12);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "AND") {
        retorno.pb(13);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "OR") {
        retorno.pb(14);
        retorno.pb(converterOperando(instrucao[1]));
        retorno.pb(converterOperando(instrucao[2]));
    }

    if(mnemonico == "NOT") {
        retorno.pb(15);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "JUMP") {
        retorno.pb(16);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "JZ") {
        retorno.pb(17);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "JN") {
        retorno.pb(18);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "CALL") {
        retorno.pb(19);
        retorno.pb(converterOperando(instrucao[1]));
    }

    if(mnemonico == "RET") {
        return {20};
    }

    // É uma constante
    return {stoi(mnemonico)};
}