#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t1.- Arrays en C\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("Un array es un conjunto de elementos del mismo tipo almacenados de forma contigua en memoria.\n");
    printf("Ejemplo: int arr[5]; → crea 5 enteros seguidos en memoria.\n");
    printf("A diferencia de malloc, este array se reserva en el stack y su tamaño debe ser conocido en tiempo de compilación.\n");

    int arr[5] = {10, 20, 30, 40, 50};
    printf("\nEjemplo de array estático:\n");
    printf("int arr[5] = {10, 20, 30, 40, 50};\n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t2.- Relación entre arrays y punteros\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("El nombre de un array (arr) se comporta como un puntero constante al primer elemento.\n");
    printf("Por eso, arr[i] es equivalente a *(arr + i).\n");
    printf("Es decir, estamos accediendo a la dirección de memoria de arr + i casillas adelante.\n");

    printf("\nEjemplo comparando ambas formas:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d  |  *(arr+%d) = %d\n", i, arr[i], i, *(arr + i));
    }

    printf("\nDirecciones de memoria de cada elemento:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("&arr[%d] = %p\n", i, (void *)&arr[i]);
    }

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t3.- sizeof en arrays vs punteros\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("sizeof(array) devuelve el tamaño total en bytes del array.\n");
    printf("Pero cuando pasamos un array a una función, se convierte en puntero, y sizeof devuelve el tamaño del puntero.\n");

    printf("\nEjemplo:\n");
    printf("sizeof(arr) = %zu bytes (5 enteros)\n", sizeof(arr));
    int *ptr = arr;
    printf("int *ptr = arr;\n");
    printf("sizeof(ptr) = %zu bytes (tamaño de un puntero)\n", sizeof(ptr));

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t4.- Arrays dinámicos con malloc\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("La principal diferencia es que con malloc podemos crear arrays cuyo tamaño se conoce en tiempo de ejecución.\n");

    int n = 5;
    int *dynArr = malloc(n * sizeof(int));
    printf("int *dynArr = malloc(%d * sizeof(int));\n", n);
    if (dynArr == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        dynArr[i] = (i + 1) * 100;
    }

    printf("\nArray dinámico creado con malloc:\n");
    for (int i = 0; i < n; i++)
    {
        printf("dynArr[%d] = %d\n", i, dynArr[i]);
    }

    free(dynArr);

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t5.- Paso de arrays a funciones\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("Cuando pasamos un array a una función, en realidad pasamos un puntero al primer elemento.\n");
    printf("Ejemplo: void printArray(int *a, int n) { ... }\n");
    printf("Esto implica que dentro de la función no sabemos el tamaño real del array, solo el puntero.\n");

    void printArray(int *a, int n);
    int arr2[3] = {7, 8, 9};
    printArray(arr2, 3);

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t6.- Arrays multidimensionales\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("Un array bidimensional es simplemente un array de arrays.\n");
    printf("En memoria, todo sigue siendo contiguo (fila por fila).\n");

    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    printf("\nEjemplo de matriz 2x3:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("mat[%d][%d] = %d  ", i, j, mat[i][j]);
        }
        printf("\n");
    }

    printf("\nDirecciones de memoria (comprobamos contigüidad):\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("&mat[%d][%d] = %p\n", i, j, (void *)&mat[i][j]);
        }
    }

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\tResumen\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("1. Un array es memoria contigua de elementos del mismo tipo.\n");
    printf("2. arr[i] ≡ *(arr+i).\n");
    printf("3. sizeof(array) ≠ sizeof(puntero).\n");
    printf("4. Arrays estáticos se crean en stack, los dinámicos con malloc en heap.\n");
    printf("5. Al pasar arrays a funciones, en realidad pasamos punteros.\n");
    printf("6. Arrays 2D también son contiguos en memoria (fila mayor).\n");

    return 0;
}

void printArray(int *a, int n)
{
    printf("\nImprimiendo array recibido en función:\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
}
