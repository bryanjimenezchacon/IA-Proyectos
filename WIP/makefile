all: rtv

rtv: genetica.hpp backend.hpp backend.cpp genetica.cpp
	g++ genetica.hpp genetica.cpp backend.cpp backend.hpp main.cpp -o rtv

genetica.hpp: genetica.cpp
	makeheaders genetica.cpp

backend.hpp: backend.cpp
	makeheaders backend.cpp

