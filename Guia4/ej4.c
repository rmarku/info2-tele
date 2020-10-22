#include <stdio.h>
#include <math.h>

int main() {
    FILE *salida;
    double angulo;
    salida = fopen("Lut_Cos.dat", "w");

    if (salida == NULL) {
        printf("No se pudo abrir el archivo");
        return 1;
    }

    for (int i = 0; i < 1024; ++i) {
        angulo = 2.0 * M_PI / 1024.0 * i;
        fprintf(salida, "%f\n", cos(angulo));
    }
    fclose(salida);
    return 0;
}

