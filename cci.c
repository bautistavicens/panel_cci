#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaforo.h>
#include <funciones.h>
#include <define.h>
#include <unistd.h>



int main(void){
	/*Variables*/
	int opcion = 0;
	int id_semaforo;
	int id_panel;
	char mensaje[LONGITUD_MENSAJE_PANEL];
	/*Mensaje de bienvenida*/
	printf("\n-------------------- Bienvenido --------------------");
	printf("\n    ----Centro de Control Inteligente V.1.0-----\n\n");
	
	printf("\n\nENTRE");
	/*Creo el semaforo*/
	id_semaforo = crear_semaforo();
	
	printf("\n\nENTRE x2");
	
	/*Inicio el semaforo*/
	iniciar_semaforo(id_semaforo, VERDE);		
		
	while(1){
		/*Espero al semaforo*/
		esperar_semaforo(id_semaforo);
				
		/*Menú principal*/;
		printf("\n	Menú Principal	\n");
		printf("\n1- Leer panel");
		printf("\n2- Escribir panel");
		printf("\n3- Salir");
		
		printf("\n\n¿Qué desea hacer?: ");
		scanf("%d", &opcion);

		switch (opcion){
			case 1:
				printf("\n¿Qué panel desea leer?: ");

				scanf("%d", &id_panel);
					
				/*Creo espacio en memoria*/
				memset(mensaje, 0x00, sizeof(mensaje));

				/*Creo espacio en memoria*/
				leer_archivo(id_panel, mensaje);
	
				/*leo mensaje del panel*/
				printf("\nPanel: %d\nMensaje: %s\n\n", id_panel, mensaje);

				break;
			case 2:
				printf("\n¿En qué panel desea escribir?: ");

				scanf("%d", &id_panel);
				
				/*Consumo el espacio que queda en el buffer a causa del scanf*/
				while((getchar()) != '\n');

				/*Creo espacio en memoria*/
				memset(mensaje, 0x00, sizeof(mensaje));
				
				printf("\nEscriba su mensaje: ");

				/*Capturo mensaje*/
				fgets(mensaje, LONGITUD_MENSAJE_PANEL, stdin);
				
				printf("Mensaje: %s ", mensaje);
				
				/*Escribo el mensaje en el archivo del panel*/
				escribir_archivo(id_panel, mensaje);
				
				/*Limpio espacio en memoria*/
				memset(mensaje, 0x00, sizeof(mensaje));

				break;
			case 3:
				printf("\nAdios!");
				exit(0);		
		}
		
		/*Levanto el semaforo*/
		levantar_semaforo(id_semaforo);
			
		/*Mando a dormir al proceso*/
		usleep(INTERVALO_ESPERA_CCI*1000);
	}
	return 0;
}
