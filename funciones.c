#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <define.h>

void leer_archivo(int in_panel_id, char* mensaje){
	
	/*Puntero a archivo.*/
	FILE *fileptr;
	int panel_id;

	/*Create filepath for panel*/
	char file_path[100];	

	/*Creo espacio en memoria*/
	memset(mensaje, 0x00, sizeof(mensaje));

	/*Creo el filepath para el panel que voy a trabajar*/
	sprintf(file_path, "%s%d.txt", PANELS_DATA_FILE_PATH, in_panel_id);

	/*Verifico que se pueda abrir el archivo*/
	if ((fileptr = fopen(file_path, "r")) == NULL){
		/*Mensaje de Error (no se pudo acceder)*/
		printf("\nERROR.\nNo se ha podido abrir el archivo %s", file_path);
	}
	
	else{
		/*Leo hasta end of file*/
		while(!feof(fileptr)){

			fscanf(fileptr,"%d", &panel_id);
		
			fgets(mensaje, LONGITUD_MENSAJE_PANEL, fileptr);
			
		}
	}
	
	/*Cierro puntero*/
	fclose(fileptr);
	
}
	
void escribir_archivo(int in_panel_id, char in_mensaje[LONGITUD_MENSAJE_PANEL]){

	/*Puntero a archivo.*/
	FILE *fileptr;
	
	/*Create filepath for panel*/
	char file_path[100];

	/*Creo espacio en memoria*/
	memset(file_path, 0x00, sizeof(file_path));

	/*Creo el filepath para el panel que voy a trabajar*/
	sprintf(file_path, "%s%d.txt", PANELS_DATA_FILE_PATH, in_panel_id);

	/*Verifico que se pueda abrir el archivo*/
	if ((fileptr = fopen(file_path, "w")) == NULL){
		/*Mensaje de Error (no se pudo acceder)*/
		printf("\nERROR.\nNo se ha podido abrir el archivo %s", PANELS_DATA_FILE_PATH);
	}
	
	/*Se pudo acceder*/
	else{

		/*Grabo los datos del archivo*/
		fprintf(fileptr,"%d %s\n", in_panel_id, in_mensaje);	

	}

	/*Limpio espacio en memoria*/
	memset(file_path, 0x00, sizeof(file_path));

	/*Cierro puntero*/
	fclose(fileptr);
}	


