#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t1.- Valor y dirección\n\n");
    printf("──────────────────────────────────────────────\n\n");

    int var = 45;
    printf("Empezamos creando una variabe tipo int\n");
    printf("int var = 45\n");
    printf("Esta variable tiene un valor de 45. Podemos consultar dicho valor:\n");
    printf("printf(\"%%d\", var);\n");
    printf("Nos devuelve lo siguiente: %d\n",var);
    printf("Esta variable se encuentra almacenada en algún sitio\n");
    printf("Para consultar la direccion de memoria en la que se encuentra, podemos usar &var\n");
    printf("Imprimimos &var usando %%p, ya que es un valor hexadecimal\n");
    printf("printf(\"%%p\", &var);\n");
    printf("%p\n",&var);

    printf("Resumiendo rápido:\n\n");
    printf("┌───────────────────────────────────┐\n");
    printf("│ Dirección de memoria │  Variable  │\n");
    printf("│         &var         │    var     │\n");
    printf("│    %p    │     %d     │\n",&var,var);
    printf("└───────────────────────────────────┘\n\n");


    printf("\n\n──────────────────────────────────────────────\n\n");
    printf("\t2.- Punteros\n\n");
    printf("──────────────────────────────────────────────\n\n");

    int *ptr;
    ptr = malloc(sizeof(int));
    *ptr = 30;
    printf("Ahora, crearemos una variable de tipo puntero. Para ello usamos el *\n");
    printf("int *ptr\n");
    printf("Acabamos de declarar donde empieza la dir de memoria que almacenará algo, en este caso un int\n");
    printf("Para que esto sirva de algo, tenemos que asignar un espacio en memoria,\nes decir, definir cuanto ocupa el dato, para saber cuantos \"huecos\" de memoria asignar\n");
    printf("Para ello, usamos malloc, de la siguiente forma:\n");
    printf("ptr = malloc(sizeof(int));\n");
    printf("En esta linea, declaramos que puntero tendrá el tamaño de un int\n\n");

    printf("Ahora, volvemos a tener una situación similar a el apartado 1\n");
    printf("En este caso, ptr es un puntero.\n");
    printf("printf(\"%%p\", ptr);\n");
    printf("%p\n",ptr);
    printf("Para acceder a su contenido, debemos usar *ptr\n");
    printf("printf(\"%%d\", *ptr);\n");
    printf("%d\n",*ptr);
    printf("Ahora, a su vez, el puntero ptr, está almacenado en una dirección de memoria\n");
    printf("Para ver esta dirección, usamos &ptr\n");
    printf("printf(\"%%p\", &ptr);\n");
    printf("%p\n",&ptr);
    
    printf("Representación en memoria:\n");
    printf("┌─────────────────────────────────────────────┐\n");
    printf("│ Valor int │    Dir int     │  Dir puntero   │\n");
    printf("├─────────────────────────────────────────────┤\n");
    printf("│   *ptr    │      ptr       │      &ptr      │\n", var, (void*)&var);
    printf("│    %d     │ %p │ %p │\n",*ptr,ptr,&ptr);
    printf("└─────────────────────────────────────────────┘\n\n");
    
    
    printf("\n\n──────────────────────────────────────────────\n\n");
    printf("\t3.- Cambio de valores\n\n");
    printf("──────────────────────────────────────────────\n\n");

    printf("Ahora, vamos a experimentar un poco con los punteros\n");
    printf("Declaramos 2 variables tipo int: int a=5, b=3;\n");
    printf("Declaramos 1 variable tipo *int: int *c = malloc(sizeof(int));\n");
    int a = 5,b = 3;
    int *c = malloc(sizeof(int));


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

    printf("Ahora, vamos a hacer que el puntero 'c' apunte a la posiciónde memoria donde está 'a'");
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



    printf("\n\n──────────────────────────────────────────────\n\n");
    printf("\t4.- Puntero a puntero\n\n");
    printf("──────────────────────────────────────────────\n\n");

    var = 10;
    ptr = &var;
    int **pptr = &ptr;

    printf("Ahora vamos a ver el concepto de puntero a puntero.\n");
    printf("Primero, tenemos una variable normal:\n");
    printf("int var = 10;\n");
    printf("Podemos consultar el valor de esta variable con var o su dirección con &var.\n");
    printf("printf(\"%%d\", var);\n");
    printf("%d\n", var);
    printf("printf(\"%%p\", &var);\n");
    printf("%p\n", &var);

    printf("\nA continuación, tenemos un puntero que apunta a 'var':\n");
    printf("int *ptr = &var;\n");
    printf("Podemos consultar el valor de 'var' usando *ptr y su dirección con ptr.\n");
    printf("printf(\"%%d\", *ptr);\n");
    printf("%d\n", *ptr);
    printf("printf(\"%%p\", ptr);\n");
    printf("%p\n", ptr);

    printf("\nFinalmente, creamos un puntero a puntero, que guarda la dirección del puntero 'ptr':\n");
    printf("int **pptr = &ptr;\n");
    printf("Este puntero a puntero nos permite acceder tanto a la dirección del puntero como al valor de 'var'.\n");
    printf("Para consultar el valor de 'var', debemos desreferenciar dos veces: **pptr\n");
    printf("printf(\"%%d\", **pptr);\n");
    printf("%d\n", **pptr);
    printf("Para consultar la dirección de 'ptr', usamos *pptr\n");
    printf("printf(\"%%p\", *pptr);\n");
    printf("%p\n", *pptr);
    printf("Y para consultar la dirección de 'pptr', simplemente pptr\n");
    printf("printf(\"%%p\", pptr);\n");
    printf("%p\n", pptr);

    printf("\nRepresentación en memoria:\n");
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("│        Var       │        ptr       │       pptr       │\n");
    printf("├────────────────────────────────────────────────────────┤\n");
    printf("│        var       │       *ptr       │       pptr       │\n");
    printf("│        %d        │        %d        │        %d        │\n", var, *ptr, **pptr);
    printf("│       &var       │        ptr       │      *pptr       │\n");
    printf("│  %p  │  %p  │  %p  │\n", &var, ptr, *pptr);
    printf("│                  │       &ptr       │       pptr       │\n");
    printf("│                  │  %p  │  %p  │\n", &ptr, pptr);
    printf("│                  │                  │      &pptr       │\n");
    printf("│                  │                  │  %p  │\n", &pptr);
    printf("└────────────────────────────────────────────────────────┘\n\n");

    printf("Resumiendo, un puntero a puntero es simplemente una variable que contiene la dirección de otro puntero.\n");
    printf("Este concepto es útil para acceder y modificar variables de manera indirecta a través de múltiples niveles de punteros.\n");


    return 0;
}