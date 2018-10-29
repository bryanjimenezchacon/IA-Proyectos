#ifndef GENETICA_H
#define GENETICA_H

#include "backend.hpp"


class Distribute;

class Individual{
  std::deque<int> representation;
  const Distribute& distribute;
  int fitness;

  Individual()=delete;

  public:
  //create individual from deque
  Individual(std::deque<int>,std::deque<int>, Distribute&);
  Individual(Distribute&);

  //returns fitness score of an individual
  void evaluate_fitness();

  //adds mutation
  void mutate_individual();

};


class Population{
  const int size = 100;
  int fitness;
  std::deque<Individual> population;
  const Distribute& distribute;

  Population()=delete;

  public:

  Population(Distribute&);

  //creates initial population
  void initialize_population();

  //the mean of all the individuals fitness
  void evaluate_population_fitness();

  //sorts population by fitness
  //returns the ones to be reproduced
  void rank_population();

  //selects which progenitors will crossover
  //creates the new population
  //removes the old population
  void reproduce_population();

};


class Distribute{

  std::deque<Vehicle> waitingRoom;
  std::deque<Lane> allLanes;
  int max_val;
  int max_len;
  const Facility& facility;

  Population population;



  //main function to find a solution
  //to the partitioning problem
  //through the genetic algorithm
  void generate_distribution();

  public:
  auto getWaitingRoom(){return waitingRoom;};
  auto getAllLanes(){return allLanes;};

  //calling the constructor will be all that's
  //needed to go through the whole process
  Distribute(Facility&);

};
#endif
