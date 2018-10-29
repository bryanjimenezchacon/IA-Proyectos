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

int Lane::currentCapacity(){
  int seconds=0;
  for(auto it=vehicleQ.begin(); it!=vehicleQ.end(); ++it){
    seconds=seconds+it->getDuration();
  }
  return seconds;
}

bool Lane::isAllowed(VType v){
  int key = static_cast<int>(v);
  auto it = allowedVehicles.find(key);
  //if allowed type
  if(it != allowedVehicles.end()){
    //if lane capacity has space
    if(max_capacity-currentCapacity()>=VDuration.at(v)){
      return true;
    }
  }
  return false;
}

bool Lane::addToQueue(VType v){
  if(isAllowed(v)){
    vehicleQ.push_back(Vehicle(v));
    return true;
  }
  return false;
}

void Lane::removeFirst(){
  if(!vehicleQ.empty()){
    vehicleQ.pop_front();
  }
}

void Lane::executeSecond(){
  if(vehicleQ.empty()){
    //do nothing if no cars
    return;
  }
  vehicleQ.front().executeSecond();
  if(vehicleQ.front().getDuration()==0){
    vehicleQ.pop_front();
  }
}


void Lane::printVehicleQ(){
  std::cout << "--- vehicleQueue ---" << "\n" << "front:";
  for(auto it=vehicleQ.begin(); it!=vehicleQ.end(); ++it){
    std::cout << it->getDuration() << VName.at(it->getType());
  }
  std::cout << ":back\n";
}

void Lane::printAllowed(){
  std::cout << "--- allowedVehicles ---" << "\n";
  for(auto it=allowedVehicles.begin(); it!=allowedVehicles.end(); ++it){
    std::cout << VName.at(it->second);
  }
  std::cout << "\n";
}

void Lane::printLane(){
  std::cout << "\n" << "####     LANE     ####" << "\n";
  std::cout << "max_capacity:" << max_capacity;
  std::cout << " current_capacity:" << currentCapacity() << "\n";
  printAllowed();
  printVehicleQ();
}
