#include <bits/stdc++.h>
#include "backend.hpp"
#include "genetica.hpp"



Individual::Individual(std::deque<int> x,std::deque<int> y, Distribute& b)
    : info(b)
    {
    //reproduce individual from two individuals
    //mutate chance individual
    //eval fitness
};

Individual::Individual(Distribute& b)
    : info(b)
    {
    //randomize individual
    for(int i = 0;i<info.max_len;++i){
      uint32_t num = info.random();
      representation.push_back(num);
    }
    //eval fitness
    evaluate_fitness();
};

void Individual::evaluate_fitness(){
  double score = 0;
  double mean = (double)info.totalCapacity()/(double)info.max_val;

  //gets total load for lane
  //represents each lane
  std::vector<int> loadxlane(info.max_val,0);
  //non allowed vehicles, doesnt matter which lane
  int non_allowed = 0; //number of vehicles
  int non_distributed = 0; //total weight
  //goes through each element, each vehicle distributed
  for(int i = 0; i < info.max_len; ++i){
    VType type = info.getWaitingRoom()[i].getType();
    int weight = info.getWaitingRoom()[i].getDuration();
    //checks for non distributed vehicles
    if(representation[i]==0){
      non_distributed += weight;
      continue;
    }
    //we know it isnt 0 so we proceed in getting the lane
    Lane lane  = info.getAllLanes()[representation[i]-1];
    //checks for non allowed vehicles
    if(!lane.compatibleType(type)){
      ++non_allowed;
    }
    //adds weight to the lane chosen
    loadxlane[representation[i]-1] += weight;
  }
  //goes through each lane and its total weight
  for(int i = 0; i < info.max_len; ++i){
    //substracts how far from the mean it was
    score += std::abs(loadxlane[i]-mean);
    //substracts how much it went past capacity
    int overfull = loadxlane[i]-info.laneCapacity(i);
    if(overfull>0){
      score += overfull*5;
      //score += pow(overfull*10,2);
    }
  }
  //substracts the ones that were not distributed
  score += non_distributed*2;
  //substracts the ones that werent allowed
  score += non_allowed*170*7;
  //score += pow(non_allowed*170,2);
  fitness = score;
};

void Individual::mutate_individual(){
};

void Individual::printIndividual(){
  std::cout<< "[";
  for(int i = 0; i<representation.size(); ++i){
    std::cout<<representation[i];
  }
  std::cout<< ":"<<fitness<<"]";
}


void Population::initialize_population(){
  for(int i = 0;i<p_size;i++){
    population.push_back(Individual(info));
  }
}

Population::Population(Distribute& d):info(d){
  //population.resize(info.max_len);
}

void Population::printPopulation(){
  double mean = (double)info.totalCapacity()/(double)info.max_val;
  std::cout<< "e:"<<mean<<"{\n";
  for(int i = 0; i<population.size(); ++i){
    population[i].printIndividual();
  }
  std::cout<< "\n}\n";
}


Distribute::Distribute(Facility& f)
    : facility(f),
    max_val(f.getAllLanes().size()),
    max_len(f.getWaitingRoom().size()),
    population(Population(*this))
    {
  std::cout<<"max len:"<<max_len<<"\n";
  waitingRoom = f.getWaitingRoom();
  allLanes = f.getAllLanes();
  rng.seed(std::random_device()());
  uint_dist = std::uniform_int_distribution<uint32_t>(0,max_val);
  execute();


}

int Distribute::laneCapacity(int index){
  return allLanes[index].remainingCapacity();
}


int Distribute::totalCapacity(){
  int num = 0;
  for(int i = 0; i<max_val;i++){
    num = num+allLanes[i].remainingCapacity();
  }
  return num;
}

void Distribute::execute(){
  population.initialize_population();
}

