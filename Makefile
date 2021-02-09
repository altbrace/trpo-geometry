.PHONY: all clean debug

all: geom debug

geom: ./geometry/geometry.o ./geometry/main.o
	gcc ./geometry/geometry.o ./geometry/main.o -o geom -lm

geometry.o: ./geometry/geometry.c
	gcc  -c ./geometry/geometry.c

main.o: ./geometry/main.c
	gcc -c ./geometry/main.c

clean:
	rm -rf ./geometry/*.o geom

debug: ./geometry/geometry_d.o ./geometry/main_d.o
	gcc -Wall ./geometry/geometry_d.o ./geometry/main_d.o -o debug -lm -g3

geometry_d.o: ./geometry/geometry.c
	gcc -g ./geometry/geometry.c

main_d.o: ./geometry/main.c
	gcc -g ./geometry/main.c
