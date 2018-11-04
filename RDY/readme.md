dentro de `\geneticalgo` esta el modelo del problema completo.

Incluye:

* **backend.cpp**:         el modelo, aqui vienen las clases de lineas, vehiculos, instalaciones (contiene todo), y sus funciones
* **backend.hpp**:         header de **backend.cpp**, es el archivo a incluir para usar las funciones de **backend.cpp** como libreria
* **genetica.cpp**:         la clase del algoritmo genetico, con solo llamar a su constructor de la siguiente manera: `Distribute{Facility f}` realiza las distribuciones dentro del model (la clase `Facillity`).
* **genetica.hpp**:         header de **genetica.cpp**, es el archivo a incluir para usar las funciones de **backend.cpp** como libreria
* **main.cpp**:    programa ejemplo para usar de guia y probar las funciones de **genetica.hpp** y **backend.hpp**
* **makefile**:            el makefile, compila el **main.cpp**, usen `$ make` para compilar facilmente (o se fijan en la ultima linea del makefile al final si quieren usar el comando)


dentro de `\asearch` esta el algoritmo completo.

Incluye:

* **asearch.cpp**:         el algoritmo asearch y definicion de funciones
* **asearch.hpp**:         header de **asearch.cpp**, es el archivo a incluir para usar las funciones de **asearch.cpp** como libreria
* **main.asearch.cpp**:    programa para probar **asearch.cpp** desde la linea de comandos
* **makefile**:            el makefile, compila el **main.asearch.cpp**, usen `$ make` para compilar facilmente (o lo compilan a su manera)
