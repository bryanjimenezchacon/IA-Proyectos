#ifndef BACKEND
#define BACKEND

#include <bits/stdc++.h>

class Time{
  public:
  void executeSeconds(int seconds);
  virtual void executeSecond() = 0;
};


enum class VType {
  Moto      ,  // moto
  Moto_v    ,  // moto vieja
  Auto      ,  // automovil
  Auto_v    ,  // automovil viejo
  Bus       ,  // bus
  Camion    ,  // camion
  Camion_v     // camion viejo
};

// duracion de servicio de cada vehiculo en segundos
const std::map<VType, int> VDuration
{
    { VType::Moto     , 20  },
    { VType::Moto_v   , 30  },
    { VType::Auto     , 40  },
    { VType::Auto_v   , 60  },
    { VType::Bus      , 80  },
    { VType::Camion   , 100 },
    { VType::Camion_v , 120 }
};

// nombres del enum, util para prints
const std::map<VType, const std::string> VName
{
    { VType::Moto     ,  "Moto    " },
    { VType::Moto_v   ,  "Moto_v  " },
    { VType::Auto     ,  "Auto    " },
    { VType::Auto_v   ,  "Auto_v  " },
    { VType::Bus      ,  "Bus     " },
    { VType::Camion   ,  "Camion  " },
    { VType::Camion_v ,  "Camion_v" }
};

// different types with different values
class Vehicle : Time{
  int    duration;
  VType  type    ;

  public:
  Vehicle(VType vtype);
  VType getType(){return type;}
  int getDuration(){return duration;}
  void executeSecond(){duration--;};
};

// contains the vehicles
class Lane : public Time{
  int pause = 0;
  std::deque<Vehicle> vehicleQ;
  std::map<int,VType> allowedVehicles; //no repeated elements
  int max_capacity;

  bool isAllowed(VType);
  int currentCapacity();

  public:
  Lane(int capacity, std::map<int,VType> = std::map<int,VType>());

  void removeType(VType);
  void addType(VType);
  bool addToQueue(VType); //false = not allowed, true = allowed
  void removeFirst();
  void pauseLane(int seconds){pause=seconds;};
  void unpauseLane(){pause=0;};
  void executeSecond();

  void printVehicleQ();
  void printAllowed();
  void printLane();

};


//contains the whole model of the simulation
// - lanes
// - waiting room
class Facility {
  std::vector<Vehicle> waitingRoom;
  std::vector<Lane> allLanes;

  public:
  Facility(){};

};

#endif
