COMPILE_OPTIONS=-DFREEGLUT_STATIC -DGLEW_STATIC -Isrc
COMPILE=g++ ${COMPILE_OPTIONS}
LINK_OPTIONS=
LINK=g++ ${LINK_OPTIONS}

run: all
	./build/6671

all: build/6671

build/6671: build/main.o build/fwk/system.o build/fwk/window.o
	${LINK} build/main.o build/fwk/system.o build/fwk/window.o -lGLEW -lGLU -lGL -lglut -o build/6671

build/main.o: prepare
	${COMPILE} -c src/main.cpp -o build/main.o 

build/fwk/system.o: prepare
	${COMPILE} -c src/fwk/system.cpp -o build/fwk/system.o

build/fwk/window.o: prepare
	${COMPILE} -c src/fwk/window.cpp -o build/fwk/window.o

prepare:
	mkdir -p build
	mkdir -p build/fwk

clean:
	rm -rf build
