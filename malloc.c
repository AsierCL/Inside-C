#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void printBinary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%c", (byte & (1 << i)) ? '1' : '0');
    }
}

int main() {
    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t1.- Estructura mínima\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("Empezamos hablando del bit y del byte. Un byte son 8 bits, y es la estructura MINIMA de valor a la que podemos acceder en memoria\n");
    printf("Esto se debe a como estan construidas las memorias. Una celda de memoria (actuales) almacena 8bits, es decir 8 unos o ceros\n");
    printf("Toda la información de nuestro ordenador, a nivel microscópico son eses unos y eses ceros\n");
    printf("Por tanto, la diferencia entre un int, un float o un char es la interpretación que le damos a esos bits\n");
    printf("Los tipos de datos como int o float, tienen un tamaño predefinido. Otras estructuras, como los arrays, no\n");
    printf("Para saber el tamaño de un tipo de elemento, podemos usar printf(\"%%zu\",sizeof(tipo))\n");
    printf("Tamaño de int: %zu bytes\n", sizeof(int));
    printf("Tamaño de float: %zu bytes\n", sizeof(float));
    printf("Tamaño de double: %zu bytes\n", sizeof(double));
    printf("Tamaño de char: %zu bytes\n", sizeof(char));
    printf("Tamaño de uint8_t: %zu bytes\n", sizeof(uint8_t));
    printf("Este último tipo es parte de la libreria stdint.h, donde el 8 hace referencia a los bits que ocupa. Lo usaremos más adelante\n");

    //getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t2.- Almacenamiento en memoria\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("Ahora, vamos a ver como se almacena un int en memoria. Existen variso formatos, pero los más comunes son big-endian y little-endian\n");
    printf("En los ordenadores modernos, el habitual es el segundo. Big y little hacen referencia a que byte se almacena primero\n");
    printf("Big-endian es lo \"normal\", ya que los bytes de más peso se almacenan primero. Little endian es justo al contrario\n");
    printf("Para verlo más facil, vamos a hacer una prueba. Creamos un int numero = 305419896. Este int es el valor hexadecimal 0x12345678\n");
    printf("Si imprimimos el valor con printf(%%d), vemos que retorna el valor numérico. Si lo imprimimos con %%x, lo devuelve en hexadecimal\n");
    int numero = 305419896;
    printf("Print con %%d: %d\n",numero);
    printf("Print con %%x: 0x%x\n",numero);
    printf("Si tenemos una visión macroscópica en nuestros programas, las variables están en cajas, cada una con su información\n");
    printf("Esas cajas están colocadas en x dirección de memoria, como vimos en punteros\n");
    printf("Sin embargo, si hacemos zoom, vemos que las cajas a nivel microscópico tienen subcajas, que son los bytes\n");
    printf("Asi, nuestra variable número tiene 4 subcajas, dado que un int ocupa 4 bytes\n");
    printf("Cuando imprimimos el puntero a una variable, este apunta a la dirección de memoria del primer byte de esta\n");
    printf("Por ello, cuando hacemos un printf, debemos de especificar el tipo de variable que imprimimos\n");
    printf("No es lo mismo imprimir un char, que solo tienes que imprimir el valor de la primera subcajita a la que apuntas\n");
    printf("a tener que imprimir un int, en el que tienes que cojer el valor de la primera, la segunda, la tercera y la cuarta subcajita\n");

    //getchar();

    printf("\nVamos a verlo gráficamente:\n");
    uintptr_t direccion = (uintptr_t)&numero;
    printf("La dirección de memoria de nuestra variable número es: %p\n",direccion);
    printf("Sin embargo, como un int ocupa 4bits, desde esa direccion hasta %p son bytes de nuestro int\n",direccion+3);
    printf("Ahora, para ver lo que hay en el primer byte, vamos a hacer lo siguiente:\n");
    printf("Creamos un uint8_t (un byte), que apunte a la dirección de memoria de numero\n");
    printf("uint8_t *byte = (uint8_t *)&numero;\n");
    printf("Lo imprimimos por pantalla con printf(\"%%x\",byte[0])\n");
    uint8_t *byte = (uint8_t *)&numero;
    printf("%X\n",byte[0]);
    printf("Si recordamos, esto corresponde a los últimos 8bits, es decir, el último byte\n");
    printf("Sin embargo, vamos a imprimir exactamente el mismo byte, pero como un char:\n");
    printf("printf(\"%%c\",byte[0])\n");
    printf("%c\n",byte[0]);
    printf("Ahora vemos claramente como, la misma información, se interpreta de 2 formas diferentes\n");
    printf("En este caso, hay un byte con los bits: 01111000. Si lo interpretamos como un int, tenemos un 78, y como un char, una \"X\"\n");
    printf("\nRepresentado nuestro int a nivel de memoria, tenemos lo siguiente:\n");
    printf("\tint numero\n");
    printf("--------------------------------------\n");
    printf("|    Dir de mem    |  Hex | Binario  |\n");
    printf("--------------------------------------\n");

    for(int i = 0; i<4; i++){
        printf("|  %p  |  %X  | ",direccion+i,byte[i],byte[i]);
        printBinary(byte[i]);
        printf(" |\n");
    }
    printf("--------------------------------------\n");

    //getchar();
    printf("\n\n\n\n\n\n\n\n");

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t3.- Malloc, memoria dinámica\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("Hasta ahora hemos estado trabajando con variables que tienen un tamaño fijo, como los int o float.\n");
    printf("Pero en ocasiones, no sabemos cuánta memoria necesitaremos durante la ejecución de un programa.\n");
    printf("En estos casos, utilizamos el concepto de memoria dinámica.\n");
    printf("Para solicitar memoria de forma dinámica en C, usamos la función malloc (memory allocation), incluida en <stdlib.h>\n");
    printf("Malloc reserva el número de bytes que le indiquemos y devuelve un puntero al primer byte de esa región de memoria.\n");
    printf("\nVeamos un ejemplo. Supongamos que queremos reservar espacio para un array de 10 enteros:\n");
    printf("\tint *array = (int *)malloc(10 * sizeof(int));\n");
    printf("Aquí, malloc está reservando espacio suficiente para almacenar 10 enteros, y nos devuelve un puntero a esa memoria.\n");
    printf("Es importante usar sizeof para que el código sea más flexible, ya que el tamaño de un int puede variar en diferentes sistemas.\n");
    printf("Malloc devuelve un puntero de tipo void, por lo que debemos hacer una conversión (cast) al tipo que esperamos, en este caso, un puntero a int.\n");

    printf("\n¿Qué pasa si no hay suficiente memoria disponible? Malloc retornará NULL.\n");
    printf("Por eso es recomendable siempre verificar si malloc tuvo éxito antes de usar la memoria asignada:\n");
    printf("\tif (array == NULL) {\n");
    printf("\t\tprintf(\"Error: No se pudo asignar memoria\\n\");\n");
    printf("\t\treturn 1;\n");
    printf("\t}\n");

    printf("\nUna vez que hemos terminado de usar la memoria dinámica, es crucial liberarla para evitar fugas de memoria.\n");
    printf("Para liberar la memoria asignada por malloc, usamos la función free:\n");
    printf("\tfree(array);\n");
    printf("Esto le dice al sistema que ya no necesitamos ese espacio, y puede reutilizarse para otras tareas.\n");

    printf("\nFinalmente, un error común al usar malloc es no liberar la memoria, o intentar liberar la misma memoria más de una vez,\n");
    printf("lo que puede causar problemas en nuestros programas. También debemos tener cuidado de no usar memoria después de liberarla.\n");
    printf("\nResumiendo:\n");
    printf("\t1. Usamos malloc para reservar memoria dinámica.\n");
    printf("\t2. Verificamos siempre si malloc devuelve NULL.\n");
    printf("\t3. Liberamos la memoria con free cuando ya no la necesitamos.\n");

    //getchar();

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\t4.- Cambiando el tamaño de memoria y usando realloc\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("En el capítulo anterior, vimos cómo asignar memoria usando malloc. Pero, ¿qué pasa si después de asignar la memoria ");
    printf("necesitamos más o menos espacio? Para cambiar el tamaño de una porción de memoria que ya fue asignada, utilizamos la función realloc.\n");
    printf("\nLa función realloc nos permite redimensionar la memoria asignada sin perder los datos existentes. Veamos cómo usarla.\n");
    printf("\nSupongamos que empezamos reservando espacio para un array de 5 enteros:\n");
    printf("\tint *array = (int *)malloc(5 * sizeof(int));\n");
    printf("Si más tarde necesitamos espacio para 10 enteros en lugar de 5, usamos realloc para redimensionar el array:\n");
    printf("\tarray = (int *)realloc(array, 10 * sizeof(int));\n");
    printf("Es importante notar que realloc intenta mantener los datos existentes mientras cambia el tamaño del bloque de memoria.\n");
    printf("Pero, si no hay espacio suficiente, puede mover el bloque a otra dirección y devolver un nuevo puntero.\n");

    printf("\nVamos a ver un ejemplo completo donde redimensionamos un array de enteros dinámicamente:\n");
    printf("\tint *array = (int *)malloc(5 * sizeof(int));\n");
    printf("\tif (array == NULL) {\n");
    printf("\t\tprintf(\"Error: No se pudo asignar memoria\\n\");\n");
    printf("\t\treturn 1;\n");
    printf("\t}\n");
    printf("\tfor (int i = 0; i < 5; i++) {\n");
    printf("\t\tarray[i] = i * 2;\n");
    printf("\t}\n");
    printf("\t// Ahora necesitamos más espacio. Redimensionamos el array a 10 enteros\n");
    printf("\tarray = (int *)realloc(array, 10 * sizeof(int));\n");
    printf("\tif (array == NULL) {\n");
    printf("\t\tprintf(\"Error: No se pudo redimensionar la memoria\\n\");\n");
    printf("\t\treturn 1;\n");
    printf("\t}\n");
    printf("\t// Asignamos nuevos valores a los 5 elementos adicionales\n");
    printf("\tfor (int i = 5; i < 10; i++) {\n");
    printf("\t\tarray[i] = i * 2;\n");
    printf("\t}\n");
    printf("\t// Imprimimos el array completo\n");
    printf("\tfor (int i = 0; i < 10; i++) {\n");
    printf("\t\tprintf(\"array[%d] = %d\\n\", i, array[i]);\n");
    printf("\t}\n");
    printf("\nCon realloc, pudimos expandir el tamaño del array sin perder los datos que ya habíamos almacenado.\n");

    printf("\n──────────────────────────────────────────────\n\n");
    printf("\tUsando calloc para inicializar memoria\n\n");
    printf("──────────────────────────────────────────────\n\n");
    printf("Otra variante de malloc es calloc. Esta función también asigna memoria dinámicamente, pero tiene la ventaja ");
    printf("de que inicializa todos los bytes de la memoria asignada a cero.\n");
    printf("\nLa sintaxis de calloc es un poco diferente. En lugar de especificar los bytes totales, especificamos la cantidad de ");
    printf("elementos y el tamaño de cada uno:\n");
    printf("\tint *array = (int *)calloc(10, sizeof(int));\n");
    printf("Esto asigna memoria para 10 enteros y, además, inicializa todos esos enteros a 0, lo que puede ahorrarnos algo de trabajo inicial.\n");

    printf("\nEl uso de calloc es útil cuando queremos asegurarnos de que los valores en la memoria asignada sean todos 0. Esto ");
    printf("puede evitar errores al usar memoria no inicializada.\n");

    printf("\nComo con malloc, también es importante recordar liberar la memoria asignada con calloc una vez que ya no la necesitemos:\n");
    printf("\tfree(array);\n");

    printf("\nResumiendo:\n");
    printf("\t1. realloc nos permite cambiar el tamaño de la memoria ya asignada.\n");
    printf("\t2. realloc puede devolver un nuevo puntero si es necesario mover el bloque de memoria.\n");
    printf("\t3. calloc asigna memoria e inicializa todos sus bytes a cero.\n");

    //getchar();
    int *array = (int *)malloc(5 * sizeof(int));
    if (array == NULL) {
            printf("Error: No se pudo asignar memoria\n");
            return 1;
    }
    for (int i = 0; i < 5; i++) {
            array[i] = i * 2;
    }
    // Ahora necesitamos más espacio. Redimensionamos el array a 10 enteros
    array = (int *)realloc(array, 10 * sizeof(int));
    if (array == NULL) {
            printf("Error: No se pudo redimensionar la memoria\n");
            return 1;
    }
    // Asignamos nuevos valores a los 5 elementos adicionales
    for (int i = 5; i < 10; i++) {
            array[i] = i * 2;
    }
    // Imprimimos el array completo
    for (int i = 0; i < 10; i++) {
            printf("array[%d] = %d\n", i, array[i]);
    }

    array = (int *)calloc(2, sizeof(int));

    // Imprimimos el array completo
    for (int i = 0; i < 2; i++) {
            printf("array[%d] = %d\n", i, array[i]);
    }


    return 0;
}
