#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <clave.h>
#include <semaforo.h>
#include <define.h>

int crear_semaforo(){
	key_t clave_semaforo = crear_clave_semaforo();
		
	/*Creo semaforo*/
	/*PRIMER PARAMETRO ES LA CLAVE, EL SEGUNDO CANT SEMAFORO, EL TERCERO 0600 LO UTILIZA CUALQUIERA, IPC ES CONSTANTE*/		
	int id_semaforo = semget(clave_semaforo, 1, 0600|IPC_CREAT);

	printf("\nID SEMAFORO (SEMAFORO.C): %d", id_semaforo);
	
	/*Verficar que se pudo crear el semaforo*/
	if(id_semaforo == -1){
		printf("\nERROR.\nNo se pudo crear el semaforo.");
	}
	
	return id_semaforo;
}

void iniciar_semaforo(int id_semaforo, int valor){
	semctl(id_semaforo, 0, SETVAL, valor);
	
}

void levantar_semaforo(int id_semaforo) {
	struct sembuf operacion;
	operacion.sem_num = 0;
	operacion.sem_op = 1;
	operacion.sem_flg = 0;
	semop(id_semaforo,&operacion,1);
}

void esperar_semaforo(int id_semaforo){
	struct sembuf operacion;
	operacion.sem_num = 0;
	operacion.sem_op = -1; 
	operacion.sem_flg = 0;
	semop(id_semaforo,&operacion,1);
}


