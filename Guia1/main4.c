#include <stdio.h>

int busquedaBinaria(char *arr, int tam, char n) {
    int inicio = 0;
    int fin = tam - 1;
    int mitad;

    while (fin > inicio) {
        mitad = (fin + inicio) / 2;
        if (arr[mitad] == n) {
            return mitad;
        } else if (arr[mitad] > n) {
            fin = mitad;
        } else {
            inicio = mitad;
        }
    }
    return -1;
}

//   300 301 302 303 304 305
//   [3] [4] [5] [6] [7] [8]
//   arr
//   ini    mitad       fin

int busquedaBPuntero(char *arr, int tam, char n) {
    char *inicio = arr;
    char *fin = arr + tam - 1;
    char *mitad;

    while (fin > inicio) {
        mitad = inicio + (fin - inicio) / 2;
        if (*mitad == n) {
            return mitad - arr;
        } else if (*mitad > n) {
            fin = mitad;
        } else {
            inicio = mitad;
        }
    }
    return -1;
}

int main() {
    char miArreglo[100];
    int pos;

    for (int i = 0; i < 100; ++i) {
        miArreglo[i] = i +34;
    }

    pos = busquedaBPuntero(miArreglo, 100, 100);
    if (pos >= 0)
        printf("La letra a está en: %d", pos);
    else
        printf("No está");

}

