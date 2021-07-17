#include "util.h"
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> separaPalavras(std::string linha) {
    std::istringstream streamLinha(linha);
    std::string palavra;
    std::vector<std::string> palavras;

    while (streamLinha >> palavra) {
        palavras.push_back(palavra);
    }

    return palavras;
}

std::string juntaPalavras(std::vector<std::string> linha) {
    std::string join("");

    for (std::string palavra: linha) {
        join = join + palavra + " ";
    }

    return join;
}

std::string removeComentario(std::string linha) {
    return linha.substr(0, linha.find(";"));
}