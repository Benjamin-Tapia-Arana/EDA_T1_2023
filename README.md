# ReadMe

## Estructura del Proyecto

El proyecto consta de las siguientes carpetas y archivos:

- **data**: Carpeta donde debes colocar los archivos de datos a ordenar.
- **build**: Carpeta donde se generará el ejecutable y donde se guardarán los archivos ordenados.
- **utils.cpp y utils.hpp**: Archivos que contienen funciones utilizadas en el desarrollo de los algoritmos.
- **sort.cpp y sort.hpp**: Archivos con las definiciones de los algoritmos de ordenación.
- **sort_ruts.cpp**: Archivo principal del programa que permite ejecutar los algoritmos de ordenación.

## Compilación

Sigue estos pasos para compilar el proyecto:

1. Asegúrate de tener instalado el compilador `g++` y la herramienta `CMake` en tu sistema.

2. Crea las carpetas "data" y "build" en el directorio principal del proyecto.

3. Coloca los archivos de datos a ordenar en la carpeta "data".

4. Desde el directorio build ejecua el siguiente comando `cmake ..`
   
5. Compila el proyecto con `make`:


## Ejecucion

Una vez compilado el proyecto, puedes ejecutar el programa proporcionando dos argumentos:

1. Nombre del archivo .txt que contiene el dataset de los números a ordenar.

2. Letra mayúscula que representa el algoritmo de ordenación a utilizar:
- M: MergeSort
- Q: QuickSort
- R: RadixSort
- I: InsertSort

Por ejemplo, para ordenar un archivo llamado "dataset.txt" con el algoritmo MergeSort, ejecuta: ./sort_ruts dataset.txt M



