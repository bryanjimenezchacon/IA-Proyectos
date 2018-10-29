#include <bits/stdc++.h>
#include "backend.hpp"



void Time::executeSeconds(int seconds){
  for(;seconds>0;--seconds){
    this->executeSecond();
  }
}


Vehicle::Vehicle(VType vtype){
  type     = vtype;
  duration = VDuration.at(type);
};

// contains the vehicles
Lane::Lane(int capacity, std::map<int,VType> types){
  max_capacity = capacity;
  allowedVehicles = types;
}

void Lane::addType(VType type){
  int key = static_cast<int>(type);
  auto it = allowedVehicles.find(key);
  //checks if type already is added
  if(it == allowedVehicles.end()){
    allowedVehicles[key]=type;
    //adds if it doesn't exist
  }
}
void Lane::removeType(VType type){
  int key = static_cast<int>(type);
  auto it = allowedVehicles.find(key);
  //checks if type is already added
  if(it != allowedVehicles.end()){
    allowedVehicles.erase(it);
    //removes if it exists
  }

}

void Lane::addToQueue(Vehicle v){
}

void Lane::printAllowed(){
  std::cout << "--- allowedVehicles ---" << "\n";
  for(auto it=allowedVehicles.begin(); it!=allowedVehicles.end(); ++it){
    std::cout << VName.at(it->second);
  }
  std::cout << "\n";
}

