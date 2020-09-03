//
// Created by martin on 3/9/20.
//

#include <stdio.h>
#include <string.h>

int main() {
    char miTexto[500] = "Hola Como va todo por ahí.";

    int i = 0;
    while (miTexto[i] != '\0') {
        putchar(miTexto[i]);
        i++;
    }
    printf("\n");

    for (i = 0; miTexto[i] != '\0'; i++) {
        putchar(miTexto[i]);
    }
    printf("\n");
}

