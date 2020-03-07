all: geom

geom: ./geometry/geometry.o ./geometry/main.o
	gcc ./geometry/geometry.o ./geometry/main.o -o geom -lm

geometry.o: ./geometry/geometry.c
	gcc  -c ./geometry/geometry.c

main.o: ./geometry/main.o
	gcc -c ./geometry/main.c

clean:
	rm -rf ./geometry/*.o geom

debug: ./geometry/geometry.o ./geometry/main.o
	gcc -Wall ./geometry/geometry.o ./geometry/main.o -o geom -lm -g3
