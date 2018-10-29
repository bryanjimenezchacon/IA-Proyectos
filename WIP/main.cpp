#include "backend.hpp"
//#include "genetica.cpp"


int main(){

  //representa una linea de servicio
  //aqui se inicializa con 100 segundos de capacidad maxima
  //tambien se puede incializar con un
  //std::map de VType como segundo parametro
  Lane lane(100);
  //VType es un enum, representa los tipos de vehiculo
  lane.addType(VType::Moto);
  lane.addType(VType::Moto_v);
  //no importa si trata de agregar el mismo tipo dos veces
  lane.addType(VType::Moto_v);
  //se borran tipos
  lane.removeType(VType::Moto);
  //no importa si trata de borrar el mismo dos veces
  lane.removeType(VType::Moto);
  lane.printAllowed();
  return 0;
}
