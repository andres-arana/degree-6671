# 6671 1er c 2013

all: main
	g++  main.o myWindow.o myApplication.o glutWindow.o glWindow.o glApplication.o -lGLEW -lGLU -lGL -lglut -o 6671

glApplication: glApplication.cpp glApplication.h
	g++ -DFREEGLUT_STATIC -DGLEW_STATIC -c glApplication.cpp

glWindow: glWindow.cpp glWindow.h
	g++ -DFREEGLUT_STATIC -DGLEW_STATIC -c glWindow.cpp

glutWindow: glutWindow.cpp glutWindow.h
	g++ -DFREEGLUT_STATIC -DGLEW_STATIC -c glutWindow.cpp
	
myApplication: myApplication.cpp myApplication.h glApplication
	g++ -DFREEGLUT_STATIC -DGLEW_STATIC -c myApplication.cpp

myWindow: myWindow.cpp myWindow.h glutWindow glWindow
	g++ -DFREEGLUT_STATIC -DGLEW_STATIC -c myWindow.cpp

main: main.cpp myWindow myApplication
	g++ -DFREEGLUT_STATIC -DGLEW_STATIC -c main.cpp

clean:
	rm -rf *o main
