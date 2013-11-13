# Escaneo de archivos de fuentes y dependencias
ALL_SOURCES := $(shell find source/ -regex .*\.cpp$$)
ALL_DIRECTORIES := $(shell find source/ -type d)
ALL_TARGET_DIRECTORIES := $(subst source/,build/obj/, $(ALL_DIRECTORIES))

# Definición de archivos binarios pre-linkeo
ALL_OBJS := $(subst source/,build/obj/,$(ALL_SOURCES:.cpp=.o))
ALL_DEPS := $(ALL_OBJS:.o=.d)

# Definición de target default que buildea todo el programa
all : build/6671

# Ejecuta el programa buildeado
run : build/6671
	./build/6671

# Definición de target que linkea el ejecutable del proyecto
build/6671 : $(ALL_OBJS)
	g++  -o"build/6671" ${ALL_OBJS} -lGLEW -lGLU -lGL -lglut

# Target de limpieza
clean:
	rm -rf build

build/obj/%.o : source/%.cpp
	mkdir -p $(dir $@)
	g++ -std=c++11 -O3 -g3 -Wall -Wextra -c -fmessage-length=0 -Isource -MD -MP -o"$@" "$<"

-include $(ALL_DEPS)

