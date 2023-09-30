# up_panel_cci

Ejercicio ejemplo de manejo de semaforos en C.

###S.O utilizado: Ubuntu 
###Compilador: gcc-4.1

##Centro de Control Inteligente

Una autopista posee 3 Paneles de Mensajería Variable (PMV) para informar a sususuarios, y 1 Centro de Control Inteligente para controlar los PMV (carteles quemodifican el texto que muestran remotamente).

Para comunicar los procesos se implementa ARCHIVOS y SEMÁFOROS

###Proceso CCI (Centro de Control Inteligente)Realizar un menú para controlar y modificar los 3 paneles (PMV).
1. Opción 1 – Leer Panel
   Se solicita por teclado el número de panel, y se muestra el mensaje que estámostrando en ese momento.
2. Opción 2 – Escribir Panel
   Se solicita por teclado el número de panel y el mensaje a enviar.

###Proceso PANEL (ejecutar 3 veces con el mismo código fuente)

Recibe por parámetro el número de panel (de 1 a 3). Carga al panel el mensaje inicial“default”.

Cada 100 ms chequea el mensaje que debe mostrar. 
Es decir:
1. Espera semáforo.
2. Lee el mensaje que le corresponde y lo muestra en pantalla.
3. Levanta semáforo.
4. Espera 100 ms y vuelve al punto.

Realizar la solución utilizando ARCHIVOS y SEMÁFOROS. En total son 4 procesoscorriendo en forma simultánea. Se debe mostrar la actividad de cada proceso. El CCI esquien inicializa el semáforo y los datos de inicio.
