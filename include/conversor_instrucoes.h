#ifndef CONVERSOR_INSTRUCOES_H
#define CONVERSOR_INSTRUCOES_H

#include <iostream>
#include <vector>

namespace Conversor {
    int converterOperando(std::string operando);
    std::vector<int> converterInstrucao(std::vector<std::string> instrucao);
}

#endif
