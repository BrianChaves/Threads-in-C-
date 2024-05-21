## ¿Qué es la Torre de Hanoi?

La Torre de Hanoi es un rompecabezas o juego matemático que consiste en mover una pila de discos de un poste a otro, siguiendo ciertas reglas, con el objetivo de llegar a una configuración final específica. Se dice que este juego fue inventado por un matemático francés llamado Édouard Lucas en el siglo XIX, aunque su origen exacto es incierto.

### ¿Cómo se juega?

Imagina tres postes verticales y una serie de discos de diferentes tamaños apilados en uno de los postes, en orden decreciente de tamaño (el disco más grande en la parte inferior y el más pequeño en la parte superior). El objetivo es mover todos los discos del poste inicial al poste final, utilizando el tercer poste como auxiliar, con la menor cantidad de movimientos posibles.

### Reglas del juego:

- Solo se puede mover un disco a la vez.
- Nunca se puede colocar un disco más grande encima de uno más pequeño.
- Solo se puede mover el disco que está en la parte superior de una pila.

### ¿Por qué es interesante?

Lo que hace que la Torre de Hanoi sea interesante es la solución óptima para mover la pila de discos de un poste a otro. La cantidad mínima de movimientos necesarios para resolver el rompecabezas se puede calcular de manera recursiva y sigue un patrón muy específico: \(2^n - 1\), donde \(n\) es el número de discos.

# Proyecto de Torre de Hanoi con Templates, Nodos, Listas y Hilos.

Este proyecto es la implementación de 2 juegos de la Torre de Hanoi uno de estos utilizando templates, nodos, listas este con los tiempos de ejecucion cronometrados y otro con sus mismas caracteristicas pero con el distitivo que usa hilos.

## Descripción

El proyecto consiste en una aplicación de consola que permite jugar al juego de la Torre de Hanoi, además de proporcionar funcionalidades adicionales como mostrar el número mínimo de movimientos requeridos para ganar, mostrar el algoritmo completo paso a paso de la solución y su tiempo de respuesta.

## Funcionalidades

- **Ingresar al juego**: Permite iniciar el juego de la Torre de Hanoi.
- **Mostrar el número mínimo de movimientos para ganar**: Muestra el número mínimo de movimientos requeridos para ganar el juego.
- **Mostrar el algoritmo completo paso a paso de la solución**: Proporciona los pasos detallados para completar el juego con los movimientos mínimos.
- **Salir**: Permite salir de la aplicación.

## Requerimientos

- Cálculo correcto del tiempo de ejecución para ambas versiones del juego.
- Implementación efectiva de hilos para lograr un alto grado de paralelismo y mejorar el rendimiento.
- Aplicación experta de técnicas de sincronización para evitar condiciones de carrera y garantizar la exclusión mutua.
- Diseño sólido y modular que facilite la comprensión y el mantenimiento.
- Manejo efectivo de situaciones de error y excepciones en un entorno concurrente.

## Resultados del proyecto del Proyecto
A continuacion de va a mostrar una tabla con los resultados de la solucion completa del algoritmo y se va a realizar una comparacion de tiempos entre el uso de hilos y cuando no se usan hilos. 

|                      | Implementación       | Tiempo de Ejecución (s) | Tiempo Diferencia(s)|
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 3.6                     | 0.9                 |
|Paso 1                | Con Hilos            | 2.7                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 2.1                     | 0.4                 |
|Paso 2                | Con Hilos            | 1.7                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 4.2                     | 2.1                 |
|Paso 3                | Con Hilos            | 2.1                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 3                       | 0.6                 |
|Paso 4                | Con Hilos            | 2.4                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 3                       | 0.3                 |
|Paso 5                | Con Hilos            | 2.7                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 2.1                     | -0.3                |
|Paso 6                | Con Hilos            | 2.4                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 2.9                     | 0.7                 |
|Paso 7                | Con Hilos            | 2.2                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 2.4                     | 1                   |
|Paso 8                | Con Hilos            | 1.4                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 3.1                     | 1.1                 |
|Paso 9                | Con Hilos            | 2                       |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 3.2                     | 1.7                 |
|Paso 10               | Con Hilos            | 1.5                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 3.3                     | 1.98                |
|Paso 11               | Con Hilos            | 1.32                    |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 3.5                     | 1.6                 |
|Paso 12               | Con Hilos            | 1.9                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 2.2                     | 0.9                 |
|Paso 13               | Con Hilos            | 1.3                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 2.2                     | 0.6                 |
|Paso 14               | Con Hilos            | 1.6                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 4.3                     | 3                   |
|Paso 15               | Con Hilos            | 1.3                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
### Análisis de los Resultados

- **Implementación sin Hilos vs con Hilos**: Se muestra claramente que la implementación con hilos logra tiempos de ejecución más bajos en comparación con la implementación sin hilos en la mayoría de los casos. Esta diferencia en el tiempo de ejecución es especialmente notable a medida que aumenta el número de pasos.

- **Tiempo de Ejecución y Diferencia**: En cada paso, se proporciona el tiempo de ejecución tanto para la implementación sin hilos como para la implementación con hilos. Además, se calcula la diferencia de tiempo entre ambas implementaciones.

- **Interacción de Pasos**: Junto con los tiempos de ejecución, se muestra una lista de las interacciones de pasos realizadas en cada paso del algoritmo de la Torre de Hanoi. Esto proporciona una visión detallada de cómo se están realizando los movimientos en cada paso del juego.

Con base en estos resultados, podemos concluir que la implementación con hilos ofrece un mejor rendimiento en términos de tiempo de ejecución en comparación con la implementación sin hilos esto para el problema dado. Esto puede ser especialmente útil en situaciones donde se requiere procesamiento concurrente para mejorar la eficiencia de la aplicación.

## A continuacion se va a mostrar otro Resultado con un enfoque diferente
### Se realizo una solucion completa del algoritmo de las torres de hanoi del cual se utilizan 3 hilos para resolver los 15 pasos en una sola ejecucion y la otra solucion sin hilos siendo esta iterativa con ciclos.

|                      | Implementación       | Tiempo de Ejecución (s) | Tiempo Diferencia(s)|
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 0.09                    | 0.02                |
|Prueba 1              | Con Hilos            | 0.11                    |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 0.10                    | 0.01                |
|Prueba 2              | Con Hilos            | 0.09                    |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 0.10                    | 0.01                |
|Prueba 3              | Con Hilos            | 0.09                    |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 0.12                    | 0.03                |
|Prueba 4              | Con Hilos            | 0.9                     |                     |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 0.10                    | 0                   |
|Prueba 5              | Con Hilos            | 0.10                    |                     |
|----------------------|----------------------|-------------------------|---------------------|


### Análisis de Resultados

Los resultados obtenidos al comparar la implementación de las Torres de Hanoi con y sin hilos (threads) muestran que, en general, no hay una diferencia significativa en el tiempo de ejecución entre ambas implementaciones.

#### Razones para la falta de diferencia significativa:

1. **Tamaño del problema:** El problema de las Torres de Hanoi es relativamente pequeño y secuencial por naturaleza. Cada movimiento debe realizarse en un orden específico, lo que limita la capacidad de los hilos para paralelizar el trabajo de manera efectiva.

2. **Naturaleza del problema:** Dado que el problema de las Torres de Hanoi es secuencial, no se pueden realizar múltiples movimientos simultáneamente. Por lo tanto, la capacidad de los hilos para mejorar el rendimiento es limitada.

3. **Overhead de los hilos:** La creación y gestión de hilos conlleva un overhead en términos de recursos del sistema. Para problemas pequeños como el de las Torres de Hanoi, este overhead puede ser comparable o incluso mayor que el tiempo de ejecución del propio algoritmo, lo que minimiza cualquier beneficio potencial de los hilos.

#### Conclusiones:
Los resultados muestran que, para este problema específico de las Torres de Hanoi, la introducción de hilos no proporciona una mejora significativa en el rendimiento en comparación con la implementación sin hilos. La decisión de utilizar hilos debe basarse en un análisis detallado de las características del problema y las necesidades de rendimiento específicas.

