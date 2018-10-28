#ifdef BACKEND
#define BACKEND

#include <bits/stdc++.h>
#include "genetica.cpp"


//contains the whole model of the simulation
// - lanes
// - waiting room
class Facility {
  std::vector<Vehicle> waitingRoom;
  std::vector<Lane> allLanes;

  public:
  Facility();

};

// contains the vehicles
class Lane {
  int max_capacity;
  int progressFirstV;
  Vehicle firstV;
  std::vector<Vehicle> queue;

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

std::map<VType, int> VDuration
{
    { VType::Moto     , 20  },
    { VType::Moto_v   , 30  },
    { VType::Auto     , 40  },
    { VType::Auto_v   , 60  },
    { VType::Bus      , 80  },
    { VType::Camion   , 100 },
    { VType::Camion_v , 120 }
};

// different types with different values
class Vehicle{
  int    duration;
  VType  type    ;

  public:
  Vehicle(VType type){
    this->type     = type;
    this->duration = VDuration[type];
  };
};

#endif
