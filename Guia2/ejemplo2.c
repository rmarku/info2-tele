#include <stdio.h>
#include <string.h>


int txtlen(char txt[]) {
    int i = 0;
    while (txt[i] != '\0')
        i++;

    return i;
}


int txtcmp(char txt1[], char txt2[]) {
    int i = 0;
    int dif;
    while (txt1[i] != '\0' && txt2[i] != '\0') {
        dif = txt1[i] - txt2[i];
        if (dif != 0) {
            return dif;
        }
        i++;
    }
    return txt1[i] - txt2[i];
}

int main() {
    char miTexto1[500] = "Casasasa";
    char miTexto[500] = "Casa";

    printf("El texto es: %s %d", miTexto1, 563576);
    printf("\n");
    printf(miTexto1);
    printf("\n");
    puts(miTexto1);
    printf("\n");

    printf("%d\n", strlen(miTexto));
    printf("%d\n", txtlen(miTexto));

    printf("%d\n", strcmp(miTexto, miTexto1));
    printf("%d\n", txtcmp(miTexto, miTexto1));
}

