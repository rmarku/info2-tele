#include <stdio.h>

#define tam 3

int incrementar(int indx[], int lim[]) {
    int i = 0;
    indx[i]++;
    do {
        if (indx[i] >= lim[i]) {
            indx[i] = 0;
            indx[i + 1]++;
        } else {
            return 0;
        }
        i++;
    } while (i <= tam);
    return 1;
}


int main() {
    FILE *archivo;
    char numero[tam + 1];
    int nInt[tam + 1];
    int nLim[tam + 1];
    int indx[tam];

    char tel[8][5] = {"abc", "def", "ghi",
                      "jkl", "mno", "pqrs",
                      "tuv", "wxyz"};

    for (int i = 0; i < tam; i++)
        indx[i] = 0;

    printf("Ingrese el numero de telefono: ");
    scanf("%s", &numero);

    for (int i = 0; i < tam; ++i) {
        nInt[i] = numero[i] - 48 - 2;
        if (numero[i] == '7' || numero[i] == '9')
            nLim[i] = 4;
        else
            nLim[i] = 3;
    }


    archivo = fopen("ej1-telefonos.txt", "w");
    if (archivo == NULL) {
        printf("No se puedo abrir telefonos.txt");
        return 1;
    }


    do {
        for (int i = 0; i < tam; ++i)
            fprintf(archivo, "%c", tel[nInt[i]][indx[i]]);

        fprintf(archivo, "\n");
    } while (incrementar(indx, nLim) != 1);

    fclose(archivo);

    return 0;
}