#include <stdio.h>
#include <stdlib.h>

// Definición de una estructura 'Persona' con typedef
typedef struct {
    char nombre[50];
    int edad;
    float altura;
} Persona;

int main() {
    // Explicación de estructuras
    printf("Uso de estructuras en C:\n\n");

    // Declaración de una variable de tipo 'Persona'
    Persona persona1 = {"Juan", 25, 1.75};

    printf("Primero, definimos una estructura 'Persona' con los siguientes campos:\n");
    printf("Persona persona = {\"Juan\", 25, 1.75};\n\n");
    printf("┌───────────────────────────────────────────────┐\n");
    printf("│  Nombre   │    Edad     │     Altura          │\n");
    printf("├───────────────────────────────────────────────┤\n");
    printf("│   Juan    │     25      │      1.75           │\n");
    printf("└───────────────────────────────────────────────┘\n\n");

    // Mostrar el contenido de la estructura persona1
    printf("Accediendo a los valores de 'persona1' directamente:\n");
    printf("printf(\"Nombre: %%s\\n, persona1.nombre)\"\n");
    printf("Nombre: %s\n", persona1.nombre);
    printf("printf(\"Edad: %%d\\n, persona1.edad)\"\n");
    printf("Edad: %d\n", persona1.edad);
    printf("printf(\"Nombre: %%.2f\\n, persona1.altura)\"\n");
    printf("Altura: %.2f\n", persona1.altura);

    // Explicación de punteros a estructuras
    printf("\n\nAhora usaremos un puntero para acceder a la estructura.\n");
    printf("\nPersona *ptrPersona = &persona1\n");

    // Declaración de un puntero a una estructura Persona
    Persona *ptrPersona = &persona1;

    printf("┌──────────────────────────────────────────────────────────┐\n");
    printf("│    Puntero     │             Valor Apuntado              │\n");
    printf("├──────────────────────────────────────────────────────────┤\n");
    printf("│ ptrPersona     │ Dirección de 'persona1': %p │\n", (void*)ptrPersona);
    printf("└──────────────────────────────────────────────────────────┘\n\n");

    // Accediendo a la estructura usando el puntero (con operador '->')
    printf("Accediendo a los valores de 'persona1' a través del puntero 'ptrPersona':\n");
    printf("printf(\"Nombre: %%s\\n, persona1->nombre)\"\n");
    printf("Nombre: %s\n", ptrPersona->nombre);
    printf("printf(\"Nombre: %%d\\n, persona1->edad)\"\n");
    printf("Edad: %d\n", ptrPersona->edad);
    printf("printf(\"Nombre: %%.2f\\n, persona1->altura)\"\n");
    printf("Altura: %.2f\n", ptrPersona->altura);

    // Explicación de la diferencia entre "." y "->"
    printf("\nDiferencia entre '.' y '->':\n");
    printf("┌─────────────────────────────────────────────────────────────┐\n");
    printf("│  '.' se usa para acceder a los campos directamente          │\n");
    printf("│  '->' se usa para acceder a los campos a través de punteros │\n");
    printf("└─────────────────────────────────────────────────────────────┘\n\n");

    // Uso de malloc para crear una nueva estructura dinámica
    Persona *personaDinamica = (Persona*)malloc(sizeof(Persona));
    if (personaDinamica == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Asignar valores a la estructura dinámica
    printf("Ahora creamos una estructura dinámica utilizando malloc:\n");
    printf("Persona personaDinamica = (Persona*)malloc(sizeof(Persona));\n");
    printf("Asignando valores a los campos de 'personaDinamica':\n");
    printf("*personaDinamica = (Persona){\"Ana\", 30, 1.65};\n");
    *personaDinamica = (Persona){"Ana", 30, 1.65};

    // Acceder a la estructura dinámica usando punteros
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
    printf("Altura: %.2f\n", personaDinamica->altura);

    // Liberar la memoria asignada dinámicamente
    free(personaDinamica);

    return 0;
}
