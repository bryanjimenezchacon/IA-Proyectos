#include <bits/stdc++.h>
#include "backend.hpp"
#include "genetica.hpp"


Individual::Individual(std::deque<int> d, Distribute& b)
    : distribute(b),
    representation(d){
};

Individual::Individual(Distribute& b)
    : distribute(b)
    {
    //randomize individual
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

