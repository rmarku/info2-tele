#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//   4 5 0
void itoa(int n, char txt[]) {
    int i = 0;
    int n2= n;

    while (n2 != 0) {
        n2 = n2 / 10;
        i++;
    }
    txt[i] = '\0';
    i--;

    while (n != 0) {
        txt[i] = n % 10 + 48;
        n = n / 10;
        i--;
    }
}

int main() {
    char numero[500] = "81357";
    char tmp[500];
    int cant1, cant2;

    // sprintf(miTexto1, "Hola mundo %d", 5654);
    // sscanf(numero, "%d %d", &cant1, &cant2);

    cant1 = atoi(numero);

    printf("La cantidad es: %d\n", cant1);

    puts("La cantidad es: ");
    itoa(cant1, tmp);
    puts(tmp);
    puts("\n");

}

