# Escaneo de archivos de fuentes y dependencias
ALL_SOURCES := $(shell find source/ -regex .*\.cpp$$)
ALL_DEPENDENCIES := $(shell find build/obj/ -regex .*\.d$$)
ALL_DIRECTORIES := $(shell find source/ -type d)
ALL_TARGET_DIRECTORIES := $(subst source/,build/obj/, $(ALL_DIRECTORIES))

# Definición de archivos binarios pre-linkeo
ALL_OBJS := $(subst source/,build/obj/,$(ALL_SOURCES:.cpp=.o))

# Definición de target default que buildea todo el programa
all : build/6671

# Ejecuta el programa buildeado
run : build/6671
	./build/6671

# Definición de target que linkea el ejecutable del proyecto
build/6671 : compile
	@echo ' '
	g++  -o"build/6671" ${ALL_OBJS} -lGLEW -lGLU -lGL -lglut
	@echo ' '
	
# Target de limpieza
clean:
	@echo ' '
	rm -rf build
	@echo ' '

# Target de preparación
prepare:
	@echo ' '
	mkdir -p $(ALL_TARGET_DIRECTORIES)
	@echo ' '
	
# Target que compila
compile: prepare $(ALL_OBJS)

# Función generadora de reglas para buildear cualquier *.o
define COMPILE_TEMPLATE 
$(1) : $(subst .o,.cpp, $(subst build/obj/,source/,$(1)))
	@echo 'Building file: $$<'
	g++ -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$$*.d" -MT"$$*.d" -o"$$@" "$$<" -Isource
	@echo ' '
endef

# Generamos las reglas para buildear los .o
$(foreach obj,$(ALL_OBJS),$(eval $(call COMPILE_TEMPLATE,$(obj))))

# Inclusión de los archivos de manejo de dependencias
-include $(ALL_DEPENDENCIES)
