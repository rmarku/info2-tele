#include <stdio.h>
 // https://github.com/rmarku/info2-tele
int main() {
    int arreglo[10];
    int *ptr;

    for (int cont = 0; cont < 10; ++cont) {
        arreglo[cont] = cont * 2;
    }
    ptr = &arreglo[0]; // arreglo == &arreglo[0]
    ptr = arreglo;

    printf("Variable: %p\n", arreglo);
    for (int cont = 0; cont < 10; ++cont) {
        printf("Variable %d: %d\n", cont, arreglo[cont]);
    }

    printf("Puntero: %p\n", ptr);
    for (int cont = 0; cont < 10; ++cont) {
        printf("Valores: %d\n", ptr[cont]);

    }

    printf("Puntero: %p\n", ptr);
    return 0;
}
