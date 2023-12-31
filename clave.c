#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <define.h>

key_t crear_clave_semaforo(){
	key_t clave_semaforo;
	
	clave_semaforo = ftok(BASE_DIR_PATH, CLAVE_BASE);
	
	printf("\nCLAVE SEMAFORO (CLAVE.C): %d", clave_semaforo);

	if(clave_semaforo == (key_t)-1){
		printf("\nERROR.\nNo se ha podido obtener una clave para el semaforo");
		
		exit(0);	
	}
	
	return clave_semaforo;
}

