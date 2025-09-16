# Curso de C paso a paso

Este repositorio contiene una serie de programas cortos en C diseñados para **aprender desde cero** los conceptos fundamentales del lenguaje, avanzando de forma progresiva con ejemplos prácticos y explicaciones claras en cada archivo.

Cada lección es un archivo `.c` autocontenible, con explicaciones y ejemplos intercalados.
El orden recomendado es importante, porque cada archivo construye sobre lo visto en el anterior.

---

## Contenido y orden de las lecciones

### 1 `punteros.c`
- Introducción a los punteros.
- Cómo declarar y usar punteros.
- Operadores `&` (dirección) y `*` (desreferencia).
- Punteros y constantes.
- Puntero nulo (`NULL`) y buenas prácticas.

### 2 `malloc.c`
- Memoria dinámica en C.
- Uso de `malloc`, `calloc`, `realloc` y `free`.
- Diferencia entre memoria en **stack** y en **heap**.
- Qué pasa si no se libera la memoria (fugas de memoria).
- Buenas prácticas: siempre comprobar si la asignación fue exitosa.

### 3 `array.c`
- Qué es un array en C y cómo se almacena en memoria.
- Relación entre arrays y punteros:
  `arr[i]` ≡ `*(arr + i)`.
- Diferencias entre `sizeof(arr)` y `sizeof(ptr)`.
- Arrays estáticos vs dinámicos.
- Paso de arrays a funciones (por valor vs referencia implícita).
- Arrays multidimensionales y cómo se representan en memoria contigua.

### 4 `estructuras.c`
- Qué es una estructura en C y cómo se accedea sus valores.
- Punteros a estructuras, y acceso a sus valores.

---

## Requisitos previos

- Conocimientos básicos de programación (variables, bucles, funciones).
- Tener instalado un **compilador de C**:
  - En Linux: `gcc` o `clang`.
  - En Windows: `MinGW`, WSL, IDEs.
  - En macOS: `clang` viene por defecto con Xcode Command Line Tools.

Para comprobar que tienes compilador:
```bash
gcc --version
```

Todos los programas se pueden simplemente ejecutar y leer las lecciones, pero recomiendo **debuggear**, para ejecutar linea por linea el código.

Para comprobar que tienes debugger:
```bash
gdb --version
```
