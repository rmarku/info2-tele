//9)	Escribir un programa que, usando punteros, copie en orden inverso una cadena de
//caracteres en otra.
//asi se usan punteros?????
// Estan bien usados para pasar argumentos, dentro de la función se usarían de esta otra forma.
#include <stdio.h>

void inverso(int *arr1, int *arr2, int n);

main() {
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arreglo2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;
    printf("arreglo 1\n");
    for (i = 0; i < 10; i++)
        printf("%d\t", arreglo[i]);

    printf("\narreglo 2\n");
    for (i = 0; i < 10; i++)
        printf("%d\t", arreglo2[i]);

    inverso(arreglo, arreglo2, 10);

    printf("\nLos arreglos ahora son\n");

    printf("\narreglo 1\n");
    for (i = 0; i < 10; i++)
        printf("%d\t", arreglo[i]);

    printf("\narreglo 2\n");
    for (i = 0; i < 10; i++)
        printf("%d\t", arreglo2[i]);

}

void inverso(int *arr1, int *arr2, int n) {
    int i;

    for (i = 0; i < n; i++) {
        arr2[9 - i] = arr1[i];
        // arr2[....]  =>  *(arr2 + .... )
        *(arr2 + 9 - i) = *(arr1 + i);
    }
}

