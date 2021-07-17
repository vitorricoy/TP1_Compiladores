#ifndef CONVERSOR_INSTRUCOES_H
#define CONVERSOR_INSTRUCOES_H

#include <iostream>
#include <vector>

#include "tabela_simbolos.h"

namespace Conversor {
    int converterOperando(std::string operando, TabelaSimbolos& tabela);
    std::vector<int> converterInstrucao(std::vector<std::string> instrucao, TabelaSimbolos& tabela);
}

#endif
