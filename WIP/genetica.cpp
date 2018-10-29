#include <bits/stdc++.h>
#include "backend.hpp"
#include "genetica.hpp"


Individual::Individual(std::deque<int> x,std:deque<int> y, Distribute& b)
    : distribute(b),
    {
    //reproduce individual from two individuals
    //mutate chance individual
    //eval fitness
};

Individual::Individual(Distribute& b)
    : distribute(b)
    {
    //randomize individual
    //eval fitness
};

void Individual::evaluate_fitness(){
};

void Individual::mutate_individual(){
};

Distribute::Distribute(Facility& f)
    : facility(f),
    population(*this) {
  waitingRoom = f.getWaitingRoom();
  allLanes = f.getAllLanes();
  max_val = allLanes.size();
  max_len = waitingRoom.size();
}



Population::Population(Distribute& d):distribute(d){}

