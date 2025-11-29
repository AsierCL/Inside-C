#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    int edad;
    float altura;
} Persona;

int main() {
    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t1.- Uso de estructuras\n\n");
    printf("──────────────────────────────────────────────\n\n");

    Persona persona1 = {"Juan", 25, 1.75};

    printf("Primero, definimos una estructura 'Persona' con los siguientes campos:\n");
    printf("typedef struct {\n");
    printf("    char nombre[50];\n");
    printf("    int edad;\n");
    printf("    float altura;\n");
    printf("} Persona;\n\n");

    printf("Ahora, creamos una persona con esta estructura.\n");
    printf("Persona persona1 = {\"Juan\", 25, 1.75};\n\n");
    printf("┌───────────────────────────────────────────────┐\n");
    printf("│  Nombre   │    Edad     │     Altura          │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│   Juan    │     25      │      1.75           │\n");
    printf("└───────────────────────────────────────────────┘\n\n");

    printf("Accediendo a los valores de 'persona1' directamente:\n");
    printf("printf(\"Nombre: %%s\\n, persona1.nombre)\"\n");
    printf("Nombre: %s\n", persona1.nombre);
    printf("printf(\"Edad: %%d\\n, persona1.edad)\"\n");
    printf("Edad: %d\n", persona1.edad);
    printf("printf(\"Nombre: %%.2f\\n, persona1.altura)\"\n");
    printf("Altura: %.2f\n", persona1.altura);

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t2.- Punteros a estructuras\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("\n\nAhora usaremos un puntero para acceder a la estructura.\n");
    printf("\nPersona *ptrPersona = &persona1\n");

    Persona *ptrPersona = &persona1;

    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("│    Puntero     │             Valor Apuntado              │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ ptrPersona     │ Dirección de 'persona1': %p │\n", (void*)ptrPersona);
    printf("└──────────────────────────────────────────────────────────┘\n\n");

    printf("Accediendo a los valores de 'persona1' a través del puntero 'ptrPersona':\n");
    printf("printf(\"Nombre: %%s\\n, ptrPersona->nombre)\"\n");
    printf("Nombre: %s\n", ptrPersona->nombre);
    printf("printf(\"Nombre: %%d\\n, ptrPersona->edad)\"\n");
    printf("Edad: %d\n", ptrPersona->edad);
    printf("printf(\"Nombre: %%.2f\\n, ptrPersona->altura)\"\n");
    printf("Altura: %.2f\n", ptrPersona->altura);

    // Explicación de la diferencia entre "." y "->"
    printf("\nDiferencia entre '.' y '->':\n");
    printf("┌─────────────────────────────────────────────────────────────┐\n");
    printf("│  '.' se usa para acceder a los campos directamente          │\n");
    printf("│  '->' se usa para acceder a los campos a través de punteros │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");

    getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t3.- Estructurs dinámicas\n\n");
    printf("──────────────────────────────────────────────\n\n");
    Persona *personaDinamica = (Persona*)malloc(sizeof(Persona));
    if (personaDinamica == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Ahora creamos una estructura dinámica utilizando malloc:\n");
    printf("Persona personaDinamica = (Persona*)malloc(sizeof(Persona));\n");
    printf("Asignando valores a los campos de 'personaDinamica':\n");
    printf("*personaDinamica = (Persona){\"Ana\", 30, 1.65};\n");
    *personaDinamica = (Persona){"Ana", 30, 1.65};

    printf("┌───────────────────────────────────────────────┐\n");
    printf("│  Nombre   │    Edad     │     Altura          │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│   Ana     │     30      │      1.65           │\n");
    printf("└───────────────────────────────────────────────┘\n\n");

    printf("Accediendo a los valores de 'personaDinamica' con el puntero:\n");
    printf("printf(\"Nombre: %%s\\n, personaDinamica->nombre)\"\n");
    printf("Nombre: %s\n", personaDinamica->nombre);
    printf("printf(\"Nombre: %%d\\n, personaDinamica->edad)\"\n");
    printf("Edad: %d\n", personaDinamica->edad);
    printf("printf(\"Nombre: %%.2f\\n, personaDinamica->altura)\"\n");
    printf("Altura: %.2f\n\n", personaDinamica->altura);

    printf("Finalmente, liberamos la memoria asignada dinámicamente con free:\n");
    printf("free(personaDinamica);\n");
    free(personaDinamica);

    getchar();
    return 0;
}
