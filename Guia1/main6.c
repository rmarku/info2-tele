#include <stdio.h>

void copyArr(int *arr1, int *arr2, int tam) {
    int i;
    arr1 = arr2;

    for (i = 0; i < tam; i++)
        arr1[i] = arr2[i];
}

void mostrarArr(int arr[], int tam, char nombre[]){
    int i;
    printf(" Los elementos de %s[] son:\n", nombre);
    for (i = 0; i < tam; i++)
        printf(" %d ", arr[i]);

    printf("\n");
}


int main() {
    int arregloa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arreglob[10] = {0, 2, 4, 6, 8, 0, 0, 0, 0, 0};


    mostrarArr(arregloa,10,"arregloa");
    mostrarArr(arreglob,10,"arreglob");

    copyArr(arregloa, arreglob, 10);

    mostrarArr(arregloa,10,"arregloa");
    mostrarArr(arreglob,10,"arreglob");

    printf("\n");
    printf("\n");
}