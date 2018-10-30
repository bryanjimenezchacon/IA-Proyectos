#ifndef GENETICA_H
#define GENETICA_H

#include "backend.hpp"


class Distribute;

class Individual{
  std::deque<uint32_t> representation;
  Distribute& info;
  double fitness;

  Individual()=delete;

  public:
  int getFitness(){return fitness;};
  //create individual from deque
  Individual(std::deque<int>,std::deque<int>, Distribute&);
  Individual(Distribute&);

  //returns fitness score of an individual
  void evaluate_fitness();

  //adds mutation
  void mutate_individual();
  uint32_t& operator[](int i) { return representation[i]; };

  void printIndividual();


};

class Population{
  const int p_size = 100;
  int fitness;
  std::deque<Individual> population;
  Distribute& info;

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
  Individual& operator[](int i) { return population[i]; };

  void printPopulation();

};


class Distribute{

  std::deque<Vehicle> waitingRoom;
  std::deque<Lane> allLanes;
  Facility& facility;
  std::mt19937 rng;
  std::uniform_int_distribution<uint32_t> uint_dist;

  Population population;



  //main function to find a solution
  //to the partitioning problem
  //through the genetic algorithm
  void generate_distribution();

  public:
  int totalCapacity();
  int laneCapacity(int index);
  void printPopulation(){population.printPopulation();};

  const int max_val; //number of lanes
  const int max_len; //number of vehicles to distribute

  auto getWaitingRoom(){return waitingRoom;};
  auto getAllLanes(){return allLanes;};

  int random(){return uint_dist(rng);};
  //calling the constructor will be all that's
  //needed to go through the whole process
  Distribute(Facility&);

  void execute();

};
#endif
