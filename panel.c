#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <clave.h>
#include <semaforo.h>
#include <funciones.h>
#include <define.h>
#include <unistd.h>



/*Estuctura del panel*/
typedef struct Paneles {
	unsigned int id_panel;
	char mensaje[LONGITUD_MENSAJE_PANEL];
}Panel;

int main(int argc, char *argv[]){
	
	/*Variables*/
	unsigned int id_panel;
	int id_semaforo;
	Panel panel;
	


	/*Checkear si se pasaron argumentos (id_panel)*/
	if (argc < 2) {
		/*Mensaje de error (no pasaron id del panel por argumentos)*/
        	printf("\nERROR.\nNo se han detectado argumentos!\nEs necesario pasar la id para el panel a traves de argumentos\n\n");

		/*FInalizo el proceso con error*/
		exit(-1);

    	}

 

	/*Transformar tipo de dato del parametro a int*/
	id_panel = atoi(argv[1]);
	
	/*Asigno id_panel a la estructura*/
	panel.id_panel = id_panel;

	/*Mensaje default para la estructura*/
	strcpy(panel.mensaje, "default");

	/*escribir_archivo(panel.id_panel, panel.mensaje);*/
	
	printf("\nENTREEE");

	/*Creo el semaforo*/
	id_semaforo = crear_semaforo();
	
	printf("\nENTREEEX2");
	

	while(1){
		/*Inicio el semaforo*/
		esperar_semaforo(id_semaforo);
		
		/*Leo archivo de mensajes y actualizo el mensaje del panel*/
		leer_archivo(panel.id_panel, panel.mensaje);


		/*Imprimo mensaje del panel*/
		printf("\nMensaje: %s", panel.mensaje);

		/*Levanto el semaforo*/
		levantar_semaforo(id_semaforo);
	
		/*Mando a dormir al proceso*/
		usleep(INTERVALO_ESPERA_PANEL*1000);		
	}


	return 0;

}
