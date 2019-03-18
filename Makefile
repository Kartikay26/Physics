all: main.out

data: main.out
	./main.out

main.out: main.cpp physics.h math3d.h physics.o math3d.o
	g++ -o main.out main.cpp physics.o math3d.o

math3d.o: math3d.cpp math3d.h
	g++ -c math3d.cpp

physics.o: physics.cpp physics.h
	g++ -c physics.cpp

clean:
	rm math3d.o physics.o main.out || true