#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
void mostrar_oracion();

int main() {
    srand(time(NULL)); // inicializaod el motor de numeros aleatorios.

    for(int i=0;i<20;i++){
        mostrar_oracion();
    }

    return 0;
}

void mostrar_oracion(){
    char *articulos[5] = {"el", "una", "la", "un", "algún"};
    char *sustantivos[5] = {"niño", "perro", "ciudad", "auto", "gato"};
    char *verbos[5] = {"saltó", "manejó", "corrió", "caminó", "esquivó"};
    char *preposiciones[5] = {"sobre", "debajo", "en", "de", "a"};
    char oracion[500] = "";

    strcat(oracion, articulos[rand() % 5]);
    strcat(oracion, " ");
    strcat(oracion, sustantivos[rand() % 5]);
    strcat(oracion, " ");
    strcat(oracion, verbos[rand() % 5]);
    strcat(oracion, " ");
    strcat(oracion, preposiciones[rand() % 5]);
    strcat(oracion, " ");
    strcat(oracion, articulos[rand() % 5]);
    strcat(oracion, " ");
    strcat(oracion, sustantivos[rand() % 5]);
    strcat(oracion, ".");
    oracion[0] = toupper(oracion[0]);

    printf("%s\n", oracion);
}
