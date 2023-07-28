# # Snake Game con Allegro 5

Este es un juego desarrollado en C++ utilizando la librería Allegro 5 que consiste en una versión del clásico juego de la serpiente. El juego presenta un menú principal con opciones para jugar y salir, y un menú secundario con cuatro niveles: fácil, intermedio, difícil y dinámico.

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

## Requisitos  
- C++11 o superior - Allegro 5 (https://liballeg.org/) 
- ## Instalación de Allegro 5 
- Para compilar y ejecutar el programa, asegúrate de tener instalada la librería Allegro 5 en tu sistema. Puedes seguir las instrucciones de instalación en el sitio web oficial de Allegro (https://liballeg.org/download.html) o utilizar un administrador de paquetes de tu sistema operativo si está disponible.
- ## Configuracion de visual estudio 
- Se debe de tener la version de visual estudio 2017 o superior
- Se debe de instalar allegro 5 desde los paquetes NuGet... para que se instale correctamente (Reinstalar en caso de ya estar instalado)
- Activar configuraciones desde las propiedades de la solucion


## Menú Principal

Al iniciar el juego, se mostrará un menú principal con dos opciones:

-   **Jugar**: Lleva al menú de selección de niveles.
-   **Salir**: Cierra el juego.

## Menú de Selección de Niveles

El menú de selección de niveles presenta cuatro opciones:

-   **Fácil**: Nivel fácil sin obstáculos.
-   **Intermedio**: Nivel con algunos obstáculos que deben evitarse.
-   **Difícil**: Nivel con obstáculos más complejos y desafiantes.
-   **Dinámico**: Nivel con obstáculos y cada 30 segundos se incrementa la velocidad del snake.

## Jugabilidad

Una vez que selecciones un nivel, el juego comenzará. Controla la serpiente utilizando las teclas de dirección (arriba, abajo, izquierda, derecha)  o utilizando las teclas (A, W, S, D) para moverla por el mapa. El objetivo es comer las frutas que aparecen aleatoriamente en el mapa sin chocar con las orillas del tablero o con el cuerpo de la serpiente. Cuantas más frutas comas, más largo será el cuerpo de la serpiente y mas puntos obtendras.

Si seleccionas los niveles intermedio, difícil o dinámico, deberás evitar los obstáculos que se encuentran en el camino mientras recolectas las frutas.

![Captura de pantalla 1](/SnakeProyecto/Recursos/capturas/p1.png)

![Captura de pantalla 2](/SnakeProyecto/Recursos/capturas/p2.png)

![Captura de pantalla 3](/SnakeProyecto/Recursos/capturas/p3.png)

![Captura de pantalla 4](/SnakeProyecto/Recursos/capturas/p4.png)

![Captura de pantalla 5](/SnakeProyecto/Recursos/capturas/p5.png)

![Captura de pantalla 6](/SnakeProyecto/Recursos/capturas/p6.png)

![Captura de pantalla 7](/SnakeProyecto/Recursos/capturas/p7.png)


## Contribuciones  
¡Las  contribuciones  son  bienvenidas!  Si  encuentras  errores  o  mejoras  que  se  pueden  hacer,  por  favor  abre  un  issue  o  envía  un  pull  request. 


## Créditos
Este programa fue creado por [Josue Maldonado Lepe](https://github.com/Jos-mlp).


## Licencia  
Este  programa  está  bajo  la  Licencia  MIT. 
**Free Software, Claro que si!**

