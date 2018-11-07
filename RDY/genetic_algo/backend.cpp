#include <iostream>
#include <string>
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



int Lane::remainingCapacity(){
  return max_capacity-currentCapacity();
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

bool Lane::compatibleType(VType v){
  int key = static_cast<int>(v);
  auto it = allowedVehicles.find(key);
  //if allowed type
  if(it != allowedVehicles.end()){
    return true;
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

bool Lane::addToQueue(Vehicle v){
  if(isAllowed(v.getType())){
    vehicleQ.push_back(v);
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

void Facility::addToWaitingRoom(VType v){
  waitingRoom.push_back(Vehicle(v));
}

void Facility::addLane(int capacity, std::map<int,VType> types){
  allLanes.push_back(Lane(capacity,types));
}

void Facility::addLane(Lane lane){
  allLanes.push_back(lane);
}

void Facility::executeSecond(){
  for(auto it=allLanes.begin(); it!=allLanes.end(); ++it){
    it->executeSecond();
  }
}

void Facility::printWaitingRoom(){
  std::cout << "--- waitingRoom ---" << "\n[";
  for(auto it=waitingRoom.begin(); it!=waitingRoom.end(); ++it){
    std::cout << it->getDuration() << VName.at(it->getType());
  }
  std::cout << "]\n";
}
void Facility::printFacility(){
  std::cout << "\n";
  std::cout << "00000000000000000000000000" << "\n";
  std::cout << "0000     FACILITY     0000" << "\n";
  printWaitingRoom();
  for(int i = 0; i < allLanes.size(); ++i){
    allLanes[i].printLane();
  }
  std::cout << "0000                  0000" << "\n";
  std::cout << "00000000000000000000000000" << "\n";
}

