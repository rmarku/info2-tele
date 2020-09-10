#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// el
// Ayer el lindo perro saltaba el rio.
//      ^puntero
// 2
char *buscar(char *oracion, char *busqueda, int *cant);

int main() {
    char oracion[] = "Ayer el lindo perro saltaba el rio.";
    char bus[] = "el";
    int c;
    char *primeraVez;

    primeraVez = buscar(oracion, bus, &c);

    printf("%d\n", c);
    printf("%s\n", primeraVez);
    return 0;
}

/* er el lindo perro saltaba el rio.
 * el
 */
int buescarSimple(char *oracion, char *busqueda) {
    //                  casa           casamiento
    int largo_busqueda = strlen(busqueda);
    int resultado = 1;

    for (int i = 0; i < largo_busqueda; i++) {
        if (oracion[i] == '\0' || oracion[i] != busqueda[i]) {
            resultado = 0;
            break;
        }
    }
    return resultado;
}


char *buscar(char *oracion, char *busqueda, int *cant) {
    int largo_oracion = strlen(oracion);
    char *primera = NULL;

    *cant = 0;

    for (int i = 0; i < largo_oracion; i++) {
        if (oracion[i] == busqueda[0]) {
            /* Ayer el lindo perro saltaba el rio.
             *   el
             */
            if (1 == buescarSimple(&oracion[i], busqueda)){
                (*cant)++;
                if (primera == NULL)
                    primera = oracion + i;
            }
        }
    }
    return primera;
}
