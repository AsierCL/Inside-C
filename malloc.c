#include <stdio.h>
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

    getchar();

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

    getchar();

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

    getchar();

    return 0;
}
