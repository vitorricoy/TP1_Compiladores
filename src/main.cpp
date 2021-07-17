#include <iostream>

#include "montador.h"

int main(int argc, char *argv[]) {
    string arquivo = argv[1];
    Montador montador(arquivo);
    auto tokens = montador.executarPassoUm();
    auto resultado = montador.executarPassoDois(tokens);
    string programa = montador.gerarPrograma(resultado);
    cout << programa;
    return 0;
}
