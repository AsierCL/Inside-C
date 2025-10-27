#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

void printBinary(unsigned char byte) {
    for (int i = 7; i >= 0; i--)
        printf("%c", (byte & (1 << i)) ? '1' : '0');
}

int main() {
    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t1.- Representación de la información en memoria\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("La memoria del ordenador solo almacena bits (0 o 1).\n");
    printf("Es decir, los tipos de datos (int, char, float, etc.) solo son 0 o 1 vistos con diferentes ojos,\n");
    printf("Veamos cómo se ve realmente un valor en memoria.\n");

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t2.- Mismo valor, distintas interpretaciones\n\n");
    printf("──────────────────────────────────────────────\n\n");

    printf("Vamos a crear un puntero, en el que almacenaremos un número entero:\n\n");
    printf("int *numero = NULL;\n\n");
    int *numero = NULL;

    printf("Ahora, vamos a asignarle un espacio en memoria, del tamaño de un entero usando malloc:\n");
    printf("numero = (int *)malloc(sizeof(int));\n\n");
    numero = (int *)malloc(sizeof(int));

    printf("Asignamos el valor 65 a ese espacio de memoria:\n\n");
    printf("*numero = 65;\n\n");
    *numero = 65; // 0x41 en ASCII -> 'A'

    printf("Si vemos las tablas de interpretación de tipos, 65 puede interpretarse de varias formas:\n");
    printf("En ASCII por ejemplo, corresponde al carácter 'A'. (El 66 a 'B', el 67 a 'C'...)\n\n");

    printf("Vamos a ver cómo se almacena ese valor en memoria, byte a byte:\n\n");
    printBinary((unsigned char)(*numero));
    printf("\n\n");

    printf("Ahora, vamos a usar el printf para imprimir estes bits con diferentes formatos:\n\n");
    printf("┌──────────────────────────────────────────┐\n");
    printf("│   Tipo   │  Printf Format  │  Resultado  │\n");
    printf("├──────────┼─────────────────┼─────────────┤\n");
    printf("│   int    │       %%d        │     %d      │\n", *numero);
    printf("│   char   │       %%c        │    '%c'      │\n", *numero);
    printf("│   bool   │       %%d        │     %d       │\n", *numero != 0);
    printf("└──────────────────────────────────────────┘\n\n");

    return 0;
}
