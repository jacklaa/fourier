
graf: graficaFourier.o gfxModified.o
	g++ graficaFourier.o gfxModified.o SocketDatagrama.o PaqueteDatagrama.o -o graf -lX11 -lm
graficaFourier.o: graficaFourier.cpp gfxModified.o
	g++ graficaFourier.cpp -c
gfxModified.o: gfxModified.c gfxModified.h
	gcc gfxModified.c -c
SocketDatagrama.o: SocketDatagrama.cpp SocketDatagrama.h PaqueteDatagrama.o
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
clean:
	rm graf
