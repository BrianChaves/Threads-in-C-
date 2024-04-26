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

|                      | Implementación       | Tiempo de Ejecución (s) | Tiempo Restante (s) |
|----------------------|----------------------|-------------------------|---------------------|
|                      | Sin Hilos            | 10.5                    | 4.2                 |
|                      | Con Hilos            | 6.8                     | 2.9                 |
|----------------------|----------------------|-------------------------|---------------------|


## Ejecución del Proyecto

Para ejecutar el proyecto, sigue estos pasos:

1. Clona el repositorio desde GitHub: `git clone <url_del_repositorio>`
2. Navega al directorio del proyecto: `cd torre-de-hanoi`
3. Compila el proyecto: `make`
4. Ejecuta la aplicación: `./hanoi`

## Contribuciones

Las contribuciones al proyecto son bienvenidas. Si deseas contribuir, sigue estos pasos:

1. Haz un fork del repositorio.
2. Realiza tus cambios en una nueva rama: `git checkout -b feature/nueva-funcionalidad`
3. Haz commit de tus cambios: `git commit -am 'Añadir nueva funcionalidad'`
4. Sube tus cambios a tu fork: `git push origin feature/nueva-funcionalidad`
5. Crea un pull request en GitHub.

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo `LICENSE` para obtener más información.

