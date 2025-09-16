#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void printBinary(unsigned char byte)
{
        for (int i = 7; i >= 0; i--)
        {
                printf("%c", (byte & (1 << i)) ? '1' : '0');
        }
}

int main()
{
        printf("\n──────────────────────────────────────────────\n\n");
        printf("\t1.- Estructura mínima\n\n");
        printf("──────────────────────────────────────────────\n\n");
        printf("Un byte son 8 bits, y es la estructura MINIMA de valor a la que podemos acceder en memoria.\n");
        printf("En C, la unidad mínima direccionable es el tipo char (que ocupa 1 byte).\n");
        printf("Podemos ver el tamaño de distintos tipos con sizeof:\n\n");

        printf("Tamaño de int: %zu bytes\n", sizeof(int));
        printf("Tamaño de float: %zu bytes\n", sizeof(float));
        printf("Tamaño de double: %zu bytes\n", sizeof(double));
        printf("Tamaño de char: %zu bytes\n", sizeof(char));
        printf("Tamaño de uint8_t: %zu bytes\n", sizeof(uint8_t));
        printf("El tipo uint8_t viene de stdint.h y garantiza 1 byte (8 bits).\n");

        getchar();

        printf("\n──────────────────────────────────────────────\n\n");
        printf("\t2.- Almacenamiento en memoria (endianness)\n\n");
        printf("──────────────────────────────────────────────\n\n");

        int numero = 305419896; // 0x12345678
        printf("Creamos un int numero = 305419896 (0x12345678 en hexadecimal).\n");
        printf("Print con %%d: %d\n", numero);
        printf("Print con %%x: 0x%x\n", numero);

        uintptr_t direccion = (uintptr_t)&numero;
        printf("La dirección de memoria de 'numero' es: %p\n", (void *)&numero);
        printf("Como ocupa 4 bytes, el rango es [%p .. %p]\n", (void *)direccion, (void *)(direccion + 3));

        uint8_t *byte = (uint8_t *)&numero;
        printf("\nRepresentación byte a byte en memoria:\n");
        printf("┌────────────────────────────────────┐\n");
        printf("│    Dir de mem    │  Hex │ Binario  │\n");
        printf("├────────────────────────────────────┤\n");
        for (int i = 0; i < 4; i++)
        {
                printf("│  %p  │  %02X  │ ", (void *)(direccion + i), byte[i]);
                printBinary(byte[i]);
                printf(" │\n");
        }
        printf("└────────────────────────────────────┘\n");

        printf("\nEn little endian, el byte menos significativo (78h) se guarda primero.\n");
        printf("En big endian, sería al revés (12h primero).\n");

        getchar();

        printf("\n──────────────────────────────────────────────\n\n");
        printf("\t3.- Malloc, memoria dinámica\n\n");
        printf("──────────────────────────────────────────────\n\n");
        printf("Malloc reserva memoria dinámica. Ejemplo: reservar un array de 10 enteros.\n");

        int *array = malloc(10 * sizeof(int));
        if (array == NULL)
        {
                printf("Error: no se pudo asignar memoria\n");
                return 1;
        }

        for (int i = 0; i < 10; i++)
        {
                array[i] = i * 10;
        }

        printf("Contenido del array dinámico:\n");
        for (int i = 0; i < 10; i++)
        {
                printf("array[%d] = %d\n", i, array[i]);
        }

        free(array); // liberar memoria

        printf("→ Siempre que usamos malloc, debemos liberar con free.\n");

        getchar();

        printf("\n──────────────────────────────────────────────\n\n");
        printf("\t4.- Cambiando tamaño con realloc\n\n");
        printf("──────────────────────────────────────────────\n\n");

        int *arr = malloc(5 * sizeof(int));
        if (arr == NULL)
        {
                printf("Error: no se pudo asignar memoria\n");
                return 1;
        }
        for (int i = 0; i < 5; i++)
        {
                arr[i] = i * 2;
        }

        printf("Array inicial de 5 elementos:\n");
        for (int i = 0; i < 5; i++)
        {
                printf("arr[%d] = %d\n", i, arr[i]);
        }

        arr = realloc(arr, 10 * sizeof(int));

        for (int i = 5; i < 10; i++)
        {
                arr[i] = i * 2;
        }

        printf("\nArray redimensionado a 10 elementos:\n");
        for (int i = 0; i < 10; i++)
        {
                printf("arr[%d] = %d\n", i, arr[i]);
        }

        free(arr);

        getchar();

        printf("\n──────────────────────────────────────────────\n\n");
        printf("\t5.- Usando calloc\n\n");
        printf("──────────────────────────────────────────────\n\n");

        int *zeroArray = calloc(5, sizeof(int));
        if (zeroArray == NULL)
        {
                printf("Error: no se pudo asignar memoria\n");
                return 1;
        }

        printf("Array creado con calloc (inicializado a 0):\n");
        for (int i = 0; i < 5; i++)
        {
                printf("zeroArray[%d] = %d\n", i, zeroArray[i]);
        }

        free(zeroArray);

        printf("\nResumen rápido:\n");
        printf("1. malloc → asigna memoria sin inicializar.\n");
        printf("2. calloc → asigna memoria inicializada a 0.\n");
        printf("3. realloc → cambia tamaño de memoria ya asignada.\n");
        printf("4. free → siempre liberar cuando ya no se use.\n");

        return 0;
}
