# 66.71 - Sistemas Gráficos

Este repositorio contiene el proyecto realizado en la materia (66.71) Sistemas
Gráficos en la FIUBA. El mismo consiste de una aplicación de escritorio que
permite explorar una escena renderizada utilizando OpenGL, en su versión 3.0,
GLSL 1.30.

## Prerequisitos

Para ubuntu, instalar las siguientes dependencias:

```
sudo apt-get install freeglut3-dev libxmu-dev libxi-dev libxrandr-dev libglew-dev libglfw-dev build-essential libglm-dev
```

## Estructura del repositorio

El repositorio está subdividio en los siguientes directorios:

* **build**: Directorio en donde se almacenan todos los artefactos generados a
  partir del código fuente (incluyendo archivos objeto y ejecutables) cuando se
corre el sistema de build. No está incluido en el repositorio, se genera
automáticamente cuando se corre el build.

* **samples**: Referencias dadas por los profesores de la práctica en clase.

* **source**: Código fuente del proyecto.

## Ambiente de desarrollo

Se incluye un `makefile` para compilar y ejecutar el proyecto. Son de especial
interés las siguientes tareas:

* `make all`: Compila y linkea el ejecutable del proyecto, dejándolo en
  `buld/6671`.

* `make run`: Compila, linkea y ejecuta el proyecto.

* `make clean`: Elimina el directorio `build` junto con todos los otros
  productos generados a partir del código fuente del proyecto.

## Licencia

Copyright (C) 2013 Andrés Arana

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
