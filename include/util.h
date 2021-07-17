#ifndef LEITOR_ARQUIVOS_H
#define LEITOR_ARQUIVOS_H

std::vector<std::string> separaPalavras(std::string linha);

std::string juntaPalavras(std::vector<std::string> linha);

std::string removeComentario(std::string linha);

#endif