CC= gcc-4.1

CFLAGS= -Wall -pedantic-errors -O3 -std=gnu89

HEADERS= -I./

all: clean panel cci


panel: panel.c semaforo.c clave.c funciones.c
	$(CC) -o panel panel.c semaforo.c clave.c funciones.c $(CFLAGS) $(HEADERS)

cci: cci.c semaforo.c clave.c
	$(CC) -o cci cci.c semaforo.c clave.c funciones.c $(CFLAGS) $(HEADERS)

clean: 
	rm -rf *.o panel cci
