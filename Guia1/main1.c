#include <stdio.h>

/*
 * Escribir un programa en C que declare una variable,
 * un puntero del tipo de la variable creada,
 * inicialice la variable e inicialice el puntero para
 * que apunte a la variable creada. Luego que imprima
 * por pantalla: la dirección de memoria de la
 * variable, el valor que almacena la variable, el
 * valor del puntero y el valor al que apunta el
 * puntero.
 */
int main() {
    int  dato;
    int *ptr;

    dato = 5;
    ptr = &dato;

    printf("variable: %d\n", dato);
    printf("variable Dir: %p\n", &dato);
    printf("Puntero: %p\n", ptr);
    printf("Puntero: %d\n", *ptr);


    return 0;
}
