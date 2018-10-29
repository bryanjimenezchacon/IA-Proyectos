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
  lane.printLane(); //prints lane information

  // 000000000000000000000000000000
  // un Faciliy es como el objeto que contiene todo
  // el modelo del problema, los lanes y el waitingRoom
  Facility f;
  // se agrega la linea que creamos
  f.addLane(lane);
  // se agrega una nueva linea, vacia, de capacidad 300
  f.addLane(300);
  f.addToWaitingRoom(VType::Camion);
  f.addToWaitingRoom(VType::Camion);
  f.addToWaitingRoom(VType::Moto_v);
  f.printFacility();

  std::cout<<"\n total lanes in facility: " << f.getLanesSize() << "\n";
  //recibir un lane para cambiarlo:
  f.getLaneAt(1).printLane(); // out_of_range si se pasa
  //o tambien se puede acceder como si fuera un array
  f[1].addType(VType::Camion); //se agrega camion en allowedVehicles
  f[1].addToQueue(VType::Camion); //se agrega camion en allowedVehicles
  f[1].printLane(); //el lane dentro del facility cambia

  f.executeSeconds(40);
  f.printFacility(); //demostrar que cambia





  return 0;
}
