CC  = g++
DEPS= backend.hpp genetica.hpp
_OBJ = genetica.o backend.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
ODIR= obj

$(ODIR)/%.o: %.cpp %.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: rtv

rtv: $(OBJ)
	$(CC) $^ -o rtv

.PHONY: clean

clean:
	rm rtv $(OBJ) *.txt

#o corran lo siguiente en la terminal lol:
#g++ genetica.cpp backend.cpp main.cpp -o rtv
# agregar esto en windows: -static-libstdc++ -static-libgcc
