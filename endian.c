#include <stdio.h>

void mostrar_bytes(void *ptr, size_t size) {
    unsigned char *byte = (unsigned char *)ptr;
    printf("Bytes en memoria: ");
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", byte[i]);
    }
    printf("\n");
}

int es_little_endian() {
    unsigned int x = 1;
    return *((unsigned char*)&x);  // Retorna 1 si es little-endian, 0 si es big-endian
}

int main() {
    // Un entero de 4 bytes con el valor hexadecimal 0x12345678
    // Valor en decimal: 305419896
    int var = 0x12345678;  

    printf("Valor de var en hexadecimal: 0x%x\n", var);
    printf("Valor de var en decimal: %d\n", var);
    printf("Direccion de var: %p\n", (void*)&var);

    // Mostrar los bytes de var en memoria
    mostrar_bytes(&var, sizeof(var));

    // Determinar si el sistema es little-endian o big-endian
    if (es_little_endian()) {
        printf("El sistema es Little-endian\n");
    } else {
        printf("El sistema es Big-endian\n");
    }

    return 0;
}

/* 
BIG ENDIAN
Dirección de memoria:
[0x1000]: 0x12  (MSB)
[0x1001]: 0x34
[0x1002]: 0x56
[0x1003]: 0x78  (LSB)

LITTLE ENDIAN
Dirección de memoria:
[0x1000]: 0x78  (LSB)
[0x1001]: 0x56
[0x1002]: 0x34
[0x1003]: 0x12  (MSB)


Los bits se almacenan de la siguiente forma
Byte: 0x12  -> 00010010  (8 bits)
Byte: 0x34  -> 00110100
Byte: 0x56  -> 01010110
Byte: 0x78  -> 01111000
*/