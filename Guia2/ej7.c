#include <stdio.h>
#include <string.h>

int esVocal(char letra) {
    if (letra == 'a' ||
        letra == 'e' ||
        letra == 'i' ||
        letra == 'o' ||
        letra == 'u')
        return 1;
    else
        return 0;
}

int mostrarSilaba(char palabra[], int inicio, int cant) {
    for (int i = 0; i < cant; i++)
        printf("%c", palabra[inicio + i]);

    printf(" ");
    return inicio + cant;
}


void mostrarPalabra(char palabra[]) {
    int i = 0;
    while (i < strlen(palabra)) {
        // ver si la primera letra es consontante
        if (!esVocal(palabra[i])) {
            if (esVocal(palabra[i + 1])) { // Encontre CV
                if (!esVocal(palabra[i + 2])) { // Encontre CVC
                    if (!esVocal(palabra[i + 3]) || esVocal(palabra[i + 3]) == '\0') { // No encontre CVCV
                        i = mostrarSilaba(palabra, i, 3);
                    } else {
                        i = mostrarSilaba(palabra, i, 2);
                    }
                } else {   //  CVV
                    if (palabra[i + 1] == 'i' || palabra[i + 1] == 'u') {
                        if (!esVocal(palabra[i + 3])) { // CVVC
                            i = mostrarSilaba(palabra, i, 4);
                        } else {  // CVV
                            i = mostrarSilaba(palabra, i, 3);
                        }
                    } else {
                        i = mostrarSilaba(palabra, i, 2);
                    }
                }
            } else {   // CC
                if (esVocal(palabra[i + 2])) { // CCV
                    if (!esVocal(palabra[i + 3])) { // CCVC
                        i = mostrarSilaba(palabra, i, 4);
                    } else { // CCV V
                        i = mostrarSilaba(palabra, i, 3);
                    }
                }
            }
        } else {
            if (!esVocal(palabra[i + 1]) && (esVocal(palabra[i + 2]) || palabra[i + 2] == '\0')) { // VC
                i = mostrarSilaba(palabra, i, 2);
            } else {    // VV
                i = mostrarSilaba(palabra, i, 1);
            }
        }
    }
}

int main() {
    mostrarPalabra("casa");
    putchar('\n');
    mostrarPalabra("salon");
    putchar('\n');
    mostrarPalabra("gimnacio");
    putchar('\n');
    mostrarPalabra("calcificacion");
    putchar('\n');
    mostrarPalabra("acrostico");
    putchar('\n');
    mostrarPalabra("atraen");
    putchar('\n');
    mostrarPalabra("playa");
    putchar('\n');
    mostrarPalabra("casa");
    putchar('\n');


    return 0;
}
