#include "backend.hpp"
//#include "genetica.cpp"


int main(){

  //VType es un enum, representa las categorias de vehiculos

  //class Lane representa una linea de servicio
  //aqui se inicializa con 100 segundos de capacidad maxima
  //tambien se puede incializar con un
  //std::map de VType como segundo parametro
  Lane lane(130);
  //VType es un enum, representa los tipos de vehiculo
  lane.addType(VType::Moto);
  lane.addType(VType::Moto_v);
  //no importa si trata de agregar el mismo tipo dos veces
  lane.addType(VType::Moto_v);
  //se borran tipos
  lane.removeType(VType::Moto);
  //no importa si trata de borrar el mismo dos veces
  lane.removeType(VType::Moto);
  lane.addType(VType::Auto);
  lane.printAllowed();

  //agregar vehiculo a la linea de espera para brindar servicio
  lane.addToQueue(VType::Moto_v);
  lane.addToQueue(VType::Auto);
  lane.addToQueue(VType::Moto_v);
  //si agrega algun vehiculo no aceptado la funcion retorna "FALSE"
  bool aceptado = lane.addToQueue(VType::Camion);
  std::cout << aceptado << "\n";
  lane.printVehicleQ();

  lane.removeFirst(); //eliminar el primero de la fila
  lane.printVehicleQ();

  lane.addType(VType::Camion);
  lane.addToQueue(VType::Camion); //no se agrega porque no hay capacidad
  lane.addToQueue(VType::Moto_v); //si se agrega

  //lane.executeSeconds(45); ejemplo para ejecutar 45 segundos
  //ejecuta 1 segundo, el primer vehiculo en fila pierde duracion
  lane.executeSecond();
  lane.printLane();


  return 0;
}
