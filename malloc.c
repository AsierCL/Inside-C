#include <stdio.h>

// Función para mostrar los bits de un valor dado
void mostrar_bits(void *ptr, size_t size) {
    unsigned char *byte = (unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        for (int bit = 7; bit >= 0; bit--) {
            printf("%d", (byte[i] >> bit) & 1);  // Desplazamos y aplicamos AND para obtener cada bit
        }
        printf(" ");  // Espacio entre bytes
    }
    printf("\n");
}

// Función para mostrar los bits en orden big-endian (de mayor a menor dirección de memoria)
void mostrar_bits_big_endian(void *ptr, size_t size) {
    unsigned char *byte = (unsigned char *)ptr;
    // Imprimir de mayor a menor dirección de memoria
    for (size_t i = size; i > 0; i--) {
        for (int bit = 7; bit >= 0; bit--) {
            printf("%d", (byte[i-1] >> bit) & 1);  // Desplazamos y aplicamos AND para obtener cada bit
        }
        printf(" ");  // Espacio entre bytes
    }
    printf("\n");
}

int main() {
    int entero = 42;
    float flotante = 42.0;

    // Tamaño en bytes de varios tipos
    printf("Tamaño de int: %zu bytes\n", sizeof(int));
    printf("Tamaño de float: %zu bytes\n", sizeof(float));
    printf("Tamaño de double: %zu bytes\n", sizeof(double));
    printf("Tamaño de char: %zu bytes\n\n", sizeof(char));

    // Mostrar los bits del entero y flotante
    printf("Representación en bits de entero (42):\n");
    mostrar_bits(&entero, sizeof(entero));

    printf("Representación en bits de flotante (42.0):\n");
    mostrar_bits(&flotante, sizeof(flotante));

    // Mostrar los bits del entero y flotante en orden big-endian
    printf("\nRepresentación en bits de entero (42):\n");
    mostrar_bits_big_endian(&entero, sizeof(entero));

    printf("Representación en bits de flotante (42.0):\n");
    mostrar_bits_big_endian(&flotante, sizeof(flotante));
    return 0;
}
