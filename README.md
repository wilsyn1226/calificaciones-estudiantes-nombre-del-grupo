Registro de Calificaciones Estudiantiles - Cálculo Diferencial

Asignatura: Lógica de Programación  
Docente: Gamalier Reyes del Carmen  

Integrantes del Grupo
Integrante 1: Wilsyn David Martínez Mota 2026-0977
Integrante 2: Elieser Suarez Solis 2026-0132

Descripción del Proyecto
Este programa en C++ fue desarrollado para el profesor de la asignatura de Lógica De Programación. Permite registrar las calificaciones finales de N cantidad de estudiantes, validar que las notas se encuentren en el rango correcto (0 a 100) y presentar un informe estadístico detallado del grupo.


Explicación Técnica: Arreglos Paralelos
Para este proyecto se implementaron dos arreglos dinámicos (`std::vector`) unidimensionales que trabajan en paralelo:
1. `vector<string> nombres`: Almacena el nombre del estudiante.
2. `vector<double> notas`: Almacena la calificación del estudiante.

Relación de Paralelismo:
Ambos vectores están vinculados mediante el uso de índices compartidos. Es decir, la posición `i` dentro de `nombres[i]` corresponde de forma directa y sincronizada a la nota almacenada en `notas[i]`. Esto permite manipular y asociar la información de cada estudiante sin necesidad de estructuras complejas en memoria.

Instrucciones de Compilación y Ejecución
 Opción A: Desde consola (GCC / G++)
1. Abrir la terminal en la carpeta del proyecto.
2. Compilar el archivo ejecutando:
   ```bash
   g++ -o programa main.cpp

[Logica De Programacion 04.pdf](https://github.com/user-attachments/files/30440955/Logica.De.Programacion.04.pdf)
