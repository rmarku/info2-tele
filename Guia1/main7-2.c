
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int asientos[25][4];
    int *ptr;

    int n, opcion = 1;

    ptr = &asientos[0][0];

    // Limpiar la matriz
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 4; j++)
            asientos[i][j] = 0;


    printf("Buenos días, bienvenido, para reservar o cancelar un asiendo del avion presione enter\n");


    while (opcion != 0) {
        printf(" ✈ Menu ✈️\n");
        printf("    ====\n\n");
        printf("1️⃣) ✅ Reservar asiento\n");
        printf("2️⃣) ❌ Cancelar asiento\n");
        printf("3️⃣)    Mostrar Reservas\n");
        printf("\n");
        printf("0️⃣️⃣)  Salir\n");

        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("\ningrese el numero del asiento a reservar\n");
                scanf("%d", &n);
                if (*(ptr + n) == 1) {
                    printf("\nDisculpe ese asiento se encuentra ocupado");
                } else {
                    *(ptr + n) = 1;
                    printf("\nSu asiento fue reservado exitosamente");
                }
                break;

            case 2:
                printf("ingrese el numero del asiento a cancelar");
                scanf("%d", &n);

                if (*(ptr + n) == 1) {
                    *(ptr + n) = 0;
                    printf("\nSu asiento fue cancelado exitosamente");
                } else {
                    printf("\nSu asiento nunca estuvo reservado");
                }
                break;

            case 3:
                printf("\nAsientos reservados:\n");

                // Limpiar la matriz
                printf("\n  ");
                for (int j = 0; j < 25; j++)
                    printf("%d\t", j + 1);

                printf("\n");
                for (int j = 0; j < 4; j++) {
                    printf("%d ", j + 1);
                    for (int i = 0; i < 25; i++) {
                        if (asientos[i][j] == 1)
                            printf("X\t");
                        else
                            printf(" \t");
                    }
                    printf("\n");
                }
                break;

        }
    }


    return 0;
}