#include "SocketDatagrama.h"

#include "gfxModified.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define BUF_SIZE 1000
#define PI 3.1416

int main(int args, char *argv[]){
	int ysize = 600;
	int xsize = 800;
	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Grafica Fourier");

	//cout << "Soy el servidor" << endl;
	char *IP = argv[1];
	int PUERTO = atoi(argv[2]);
	int  leidos = 0, destino;
	int PUERTOCli = atoi(argv[3]);
	SocketDatagrama sock(PUERTO);
	int cooX=0, cooY=0;

	gfx_color(0,200,100);
	gfx_line(xsize/2,0,xsize/2,ysize);
	gfx_line(0,ysize/2,xsize,ysize/2);
	gfx_flush();

	while(1){
		PaqueteDatagrama resp(sizeof(int));
		//recibe x para graficar
		sock.recibe(resp);
		cout << "Se ha recibido algo " << atoi(resp.obtieneDatos()) << endl;	
		//guarda coordenada x
		cooX = atoi(resp.obtieneDatos());
		//recibe y para graficar
		sock.recibe(resp);
		cooY = atoi(resp.obtieneDatos());
		//grafica el punto
		//blue
		gfx_color(0,0,200);
		gfx_point(cooX, cooY);
		gfx_flush();			
	}
	
	//if((c = gfx_wait()) == 'q')
	//	break;
	close(destino);
	return 0;
}