#ifndef GENETICA_H
#define GENETICA_H

#include "backend.hpp"

//to write files after distributing

class Distribute;

class Individual{
  //each index represents a vehicle in the waiting room
  //each integer represents a lane
  std::deque<uint32_t> representation;
  Distribute* info; //pointer and not reference cuz std::sort
  double fitness;

  static constexpr double mutation_chance = 3; //3% out of 100

  Individual()=delete;

  public:
  std::deque<uint32_t> getRep(){return representation;};
  int getFitness(){return fitness;};
  //create individual from deque
  //Individual(Individual,Individual, Distribute&);
  Individual(Individual x,Individual y, std::deque<int> mask, Distribute& b);
  Individual(Individual, Distribute&);
  Individual(Distribute&);

  //returns fitness score of an individual
  void evaluate_fitness();

  //adds mutation
  void mutate_individual();
  uint32_t& operator[](int i) { return representation[i]; };

  void printIndividual();


};

class Population{
  const int p_size = 150;
  int fitness;
  std::deque<Individual> population;
  Distribute& info;

  int individual_selection(); //based on exponential distribution

  Population()=delete;

  std::deque<int> generate_mask();
  std::deque<int> invert_mask(std::deque<int> m);

  public:

  Individual get_fittest(){return population[0];};

  Population(Distribute&);

  //creates initial population
  void initialize_population();

  //the mean of all the individuals fitness
  void evaluate_population_fitness();

  //sorts population by fitness
  //returns the ones to be reproduced
  void sort_population(); //sorts by fitness

  void advance_generation(); //selects for reproduction

  //selects which progenitors will crossover
  //creates the new population
  //removes the old population
  Individual& operator[](int i) { return population[i]; };

  double mean();
  void printPopulation();

};

static int file_count = 0;

class Distribute {

  const int generations = 50;

  std::deque<Vehicle> waitingRoom;
  std::deque<Lane> allLanes;
  Facility& facility;
  std::mt19937 rng;
  std::uniform_int_distribution<uint32_t> uint_dist;
  std::uniform_int_distribution<uint32_t> index_dist;
  std::uniform_int_distribution<uint32_t> binary_dist;
  std::default_random_engine rng2;
  std::exponential_distribution<double> exp_dist = std::exponential_distribution<double> (0.25);

  Population population;

  std::ofstream outfile;
  std::string outfile_name();



  //main function to find a solution
  //to the partitioning problem
  //through the genetic algorithm
  void generate_distribution();

  public:

  // WIP
  void sort_p(){population.sort_population();}


  int totalCapacity();
  int laneCapacity(int index);
  void printPopulation(){population.printPopulation();};
  void nextgen(){population.advance_generation();};

  const int max_val; //number of lanes
  const int max_len; //number of vehicles to distribute

  auto getWaitingRoom(){return waitingRoom;};
  auto getAllLanes(){return allLanes;};

  int random_lane(){return uint_dist(rng);}; //value
  int random_car(){return index_dist(rng);}; //index
  int random_binary(){return binary_dist(rng);};
  int random_exp(){return exp_dist(rng2);};
  //calling the constructor will be all that's
  //needed to go through the whole process
  Distribute(Facility&);

  void execute();
  void distribute_cars();

};
#endif
