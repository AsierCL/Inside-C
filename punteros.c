#include <stdio.h>

int main(){
    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t1.- Valor y dirección\n\n");
    printf("──────────────────────────────────────────────\n\n");

    int var = 45;
    printf("Empezamos creando una variable tipo int:\n");
    printf("int var = 45;\n\n");
    printf("Esta variable tiene un valor de 45. Podemos consultar dicho valor:\n");
    printf("printf(\"%%d\", var);\n");
    printf("Nos devuelve lo siguiente: %d\n\n", var);

    printf("Esta variable se encuentra almacenada en algún sitio.\n");
    printf("Para consultar la dirección de memoria en la que se encuentra, usamos &var.\n");
    printf("Imprimimos &var usando %%p, ya que es un valor hexadecimal:\n");
    printf("printf(\"%%p\", (void*)&var);\n");
    printf("%p\n\n", (void*)&var);

    printf("Resumiendo rápido:\n\n");
    printf("┌───────────────────────────────────┐\n");
    printf("│ Dirección de memoria │  Variable  │\n");
    printf("│         &var         │    var     │\n");
    printf("│    %p    │     %d     │\n",(void*)&var, var);
    printf("└───────────────────────────────────┘\n\n");

    getchar();

    printf("\n\n──────────────────────────────────────────────\n\n");
    printf("\t2.- Punteros\n\n");
    printf("──────────────────────────────────────────────\n\n");

    int *ptr = &var;
    printf("Ahora creamos una variable de tipo puntero:\n");
    printf("int *ptr = &var;\n\n");

    printf("En este caso, ptr almacena la dirección de memoria de 'var'.\n");
    printf("printf(\"%%p\", (void*)ptr);\n");
    printf("%p\n", (void*)ptr);

    printf("Para acceder a su contenido, usamos *ptr:\n");
    printf("printf(\"%%d\", *ptr);\n");
    printf("%d\n\n", *ptr);

    printf("El puntero 'ptr' también está almacenado en una dirección de memoria propia:\n");
    printf("printf(\"%%p\", (void*)&ptr);\n");
    printf("%p\n\n", (void*)&ptr);

    printf("Representación en memoria:\n");
    printf("┌─────────────────────────────────────────────┐\n");
    printf("│ Valor int │    Dir int     │  Dir puntero   │\n");
    printf("├─────────────────────────────────────────────┤\n");
    printf("│   *ptr    │      ptr       │      &ptr      │\n");
    printf("│    %d     │ %p │ %p │\n", *ptr, (void*)ptr, (void*)&ptr);
    printf("└─────────────────────────────────────────────┘\n\n");

    getchar();

    printf("\n\n──────────────────────────────────────────────\n\n");
    printf("\t3.- Cambio de valores\n\n");
    printf("──────────────────────────────────────────────\n\n");

    int a = 5, b = 3;
    int *c = &a;

    printf("Declaramos dos variables: int a=5, b=3;\n");
    printf("Declaramos un puntero: int *c = &a;\n\n");

    printf("La situación actual es la siguiente:\n");
    printf("┌──────────────────────────┐\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│   a   │        &a        │\n");
    printf("│   %d   │  %p  │\n",a,&a);
    printf("├──────────────────────────┤\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│   b   │        &b        │\n");
    printf("│   %d   │  %p  │\n",b,&b);
    printf("├──────────────────────────┤\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│  *c   │         c        │\n");
    printf("│   %d   │  %p  │\n",*c,c);
    printf("└──────────────────────────┘\n");

    printf("Ahora, vamos a hacer que el puntero 'c' apunte a la posiciónde memoria donde está 'a'\n");
    printf("c = &a;\n");
    c = &a;
    printf("Si ahora imprimimos *c, veremos que es igual a el valor de a,\npuesto que estamos imprimiendo el contenido de la dirección de memoria en la que se almacenó 'a'\n");
    printf("printf(\"%%d\", *c);\n");
    printf("%d\n", *c);

    printf("┌──────────────────────────┐\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│   a   │        &a        │\n");
    printf("│   %d   │  %p  │\n",a,&a);
    printf("├──────────────────────────┤\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│   b   │        &b        │\n");
    printf("│   %d   │  %p  │\n",b,&b);
    printf("├──────────────────────────┤\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│  *c   │         c        │\n");
    printf("│   %d   │  %p  │\n",*c,c);
    printf("└──────────────────────────┘\n");

    getchar();

    printf("\nIMPORTANTE:\n");
    printf("Ahora empieza lo curioso... Si modificamos el valor almacenado en c, modificamos también a\n");
    printf("Es decir, si ahora hacemos: *c = 2; el valor de a pása 'a' ser 2\n");
    *c = 2;
    printf("printf(\"%%d\", *c);\n");
    printf("%d\n", *c);
    printf("printf(\"%%d\", a);\n");
    printf("%d\n", a);

    printf("┌──────────────────────────┐\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│   a   │        &a        │\n");
    printf("│   %d   │  %p  │\n",a,&a);
    printf("├──────────────────────────┤\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│   b   │        &b        │\n");
    printf("│   %d   │  %p  │\n",b,&b);
    printf("├──────────────────────────┤\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│  *c   │         c        │\n");
    printf("│   %d   │  %p  │\n",*c,c);
    printf("└──────────────────────────┘\n");


    printf("\nUn último cambio. Vamos a hacer que ahora la dir de 'c' apunte a la dir de 'b'\n");
    printf("c = &b\n");
    c = &b;
    printf("printf(\"%%d\", *c);\n");
    printf("%d\n", *c);

    printf("┌──────────────────────────┐\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│   a   │        &a        │\n");
    printf("│   %d   │  %p  │\n",a,&a);
    printf("├──────────────────────────┤\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│   b   │        &b        │\n");
    printf("│   %d   │  %p  │\n",b,&b);
    printf("├──────────────────────────┤\n");
    printf("│ Valor │     Dirección    │\n");
    printf("│  *c   │         c        │\n");
    printf("│   %d   │  %p  │\n",*c,c);
    printf("└──────────────────────────┘\n");

    getchar();

    printf("\n\n──────────────────────────────────────────────\n\n");
    printf("\t4.- Puntero a puntero\n\n");
    printf("──────────────────────────────────────────────\n\n");

    var = 10;
    ptr = &var;
    int **pptr = &ptr;

    printf("Un puntero a puntero es una variable que contiene la dirección de otro puntero.\n\n");
    printf("Ejemplo:\n");
    printf("int var = 10;\n");
    printf("int *ptr = &var;\n");
    printf("int **pptr = &ptr;\n\n");

    printf("Valor de var: %d\n", var);
    printf("Dirección de var: %p\n", (void*)&var);
    printf("Valor de *ptr (contenido de var): %d\n", *ptr);
    printf("Dirección almacenada en ptr: %p\n", (void*)ptr);
    printf("Valor de **pptr (contenido de var): %d\n", **pptr);
    printf("Dirección almacenada en *pptr (es decir, ptr): %p\n", (void*)*pptr);
    printf("Dirección de pptr: %p\n\n", (void*)pptr);

    getchar();

    printf("\n\n──────────────────────────────────────────────\n\n");
    printf("\t5.- Puntero nulo (NULL)\n\n");
    printf("──────────────────────────────────────────────\n\n");

    int *null_ptr = NULL;
    printf("Un puntero nulo es un puntero que no apunta a ninguna dirección válida.\n");
    printf("Ejemplo: int *null_ptr = NULL;\n\n");

    printf("Dirección almacenada en null_ptr: %p\n", (void*)null_ptr);
    printf("Intentar acceder a *null_ptr provocaría un error (segmentation fault).\n\n");

    getchar();

    printf("\n\n──────────────────────────────────────────────\n\n");
    printf("\t6.- Punteros con const\n\n");
    printf("──────────────────────────────────────────────\n\n");

    const int x = 42;
    const int *p1 = &x;  // Puntero a un entero constante
    int y = 100;
    int *const p2 = &y;  // Puntero constante a un entero

    printf("Existen dos formas comunes de combinar const con punteros:\n\n");
    printf("1) const int *p1 → puntero a un entero constante.\n");
    printf("   El valor al que apunta no puede modificarse a través del puntero.\n");
    printf("   *p1 = 50;  // error\n\n");

    printf("2) int *const p2 → puntero constante a un entero.\n");
    printf("   El puntero no puede cambiar de dirección, pero el valor sí puede modificarse.\n");
    printf("   *p2 = 200; // válido\n\n");

    printf("Ejemplo:\n");
    printf("x = %d (acceso con p1 = %p)\n", *p1, (void*)p1);
    *p2 = 200;
    printf("y (modificado a través de p2) = %d (p2 = %p)\n", *p2, (void*)p2);

    return 0;
}
