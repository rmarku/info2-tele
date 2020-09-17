#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void ordenar(char arr[], int tam) {
    char tmp;
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            if (arr[i]< arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main() {
    char vector[25];
    srand(time(NULL));

    for (int i = 0; i < 25; i++)
        vector[i] = rand() % 25 + 65;

    for (int i = 0; i < 25; i++)
        putchar(vector[i]);

    putchar('\n');
    ordenar(vector, 25);

    for (int i = 0; i < 25; i++)
        putchar(vector[i]);

    return 0;
}
