#include <stdio.h>

int main() {
    int var = 42;          // Una variable entera
    int *ptr = &var;       // Un puntero que guarda la dirección de var
    int **dptr = &ptr;     // Un puntero a puntero (doble puntero)

    // Mostrando el valor de la variable y sus direcciones
    printf("Valor de var: %d\n", var);                  // Imprime el valor de var
    printf("Direccion de var (&var): %p\n", &var);      // Imprime la dirección de var
    printf("Valor de ptr (*ptr): %d\n", *ptr);          // Imprime el valor al que apunta ptr (es decir, var)
    printf("Direccion de ptr (&ptr): %p\n", &ptr);      // Imprime la dirección de ptr
    printf("Valor de dptr (**dptr): %d\n", **dptr);     // Imprime el valor al que apunta dptr, que es el valor de var
    printf("Direccion de dptr (&dptr): %p\n", &dptr);   // Imprime la dirección de dptr

    // Modificar el valor de var usando punteros
    *ptr = 100;    // Modificando el valor de var a través de ptr
    printf("\nNuevo valor de var (modificado con *ptr): %d\n", *ptr);

    **dptr = 200;  // Modificando el valor de var a través de dptr
    printf("Nuevo valor de var (modificado con **dptr): %d\n", **dptr);
    printf("Vemos como si imprimimos var, coincide con el último valor: %d\n", var);

    return 0;
}