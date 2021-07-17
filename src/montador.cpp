#include <iostream>

#include "montador.h"

void Montador::Montador(std::string arquivoPrograma) {
    this->leitorArquivos = new LeitorArquivos(arquivoPrograma);
}

void Montador::executarPassoUm() {

}

void Montador::executarPassoDois() {

}
