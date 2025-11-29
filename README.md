# Curso de C paso a paso

Este repositorio contiene una serie de programas cortos en C diseñados para **aprender desde cero** los conceptos fundamentales del lenguaje, avanzando de forma progresiva con ejemplos prácticos y explicaciones claras en cada archivo.

Cada lección es un archivo `.c` autocontenible, con explicaciones y ejemplos intercalados.
El orden recomendado es importante, porque cada archivo construye sobre lo visto en el anterior.

---

## Contenido y orden de las lecciones

### 1 [`punteros.c`](punteros.c)
- Introducción a los punteros.
- Cómo declarar y usar punteros.
- Operadores `&` (dirección) y `*` (desreferencia).
- Punteros y constantes.
- Puntero nulo (`NULL`) y buenas prácticas.

### 2 [`malloc.c`](malloc.c)
- Memoria dinámica en C.
- Uso de `malloc`, `calloc`, `realloc` y `free`.
- Diferencia entre memoria en **stack** y en **heap**.
- Qué pasa si no se libera la memoria (fugas de memoria).
- Buenas prácticas: siempre comprobar si la asignación fue exitosa.

### 3 [`array.c`](array.c)
- Qué es un array en C y cómo se almacena en memoria.
- Relación entre arrays y punteros:
  `arr[i]` ≡ `*(arr + i)`.
- Diferencias entre `sizeof(arr)` y `sizeof(ptr)`.
- Arrays estáticos vs dinámicos.
- Paso de arrays a funciones (por valor vs referencia implícita).
- Arrays multidimensionales y cómo se representan en memoria contigua.

### 4 [`estructuras.c`](estructuras.c)
- Qué es una estructura en C y cómo se accedea sus valores.
- Punteros a estructuras, y acceso a sus valores.

---

## Requisitos previos

- Conocimientos básicos de programación (variables, bucles, funciones).
- Tener instalado un **compilador y un debugger de C**:

Si no tienes el compilador y el debugger, aqui explico [`como instalarlos`](HowToDebug.md).
