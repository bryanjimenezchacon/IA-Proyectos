#include <iostream>
#include <string>
#include <ctime> 
#include <algorithm> 
#include "backend.hpp"
#include "genetica.hpp"


//to initialize individuals as offspring from two parents
Individual::Individual(Individual x,Individual y, std::deque<int> mask, Distribute& b)
    : info(&b)
    {
    //reproduce individual from two individuals
    std::deque<uint32_t> offspring;
    for(int i=0; i<info->max_len ; ++i){
      offspring.push_back(mask[i]==1?x[i]:y[i]);
//std::cout<<"?!\n";
    }
    representation = offspring;
    //mutate chance individual
    mutate_individual();
    //eval fitness
    evaluate_fitness();
};

void Individual::mutate_individual(){
    if(rand() % 100<mutation_chance){
      representation[info->random_car()]=info->random_lane();
      mutate_individual(); //another chance to remutate!
    }
};

//to copy individuals from another individual
Individual::Individual(Individual self, Distribute& b)
    : info(&b)
    {
    representation = self.getRep();
    evaluate_fitness();
};

//to initialize individuals with random values
Individual::Individual(Distribute& b)
    : info(&b)
    {
    //randomize individual
    for(int i = 0;i<info->max_len;++i){
      uint32_t num = info->random_lane();
      representation.push_back(num);
    }
    //eval fitness
    evaluate_fitness();
};

void Individual::evaluate_fitness(){
  double score = 0;
  double mean = (double)info->totalCapacity()/(double)info->max_val;

  //gets total load for lane
  //represents each lane
  std::vector<int> loadxlane(info->max_val,0);
  //non allowed vehicles, doesnt matter which lane
  int non_allowed = 0; //number of vehicles
  int non_distributed = 0; //total weight
  //goes through each element, each vehicle distributed
  for(int i = 0; i < info->max_len; ++i){
    VType type = info->getWaitingRoom()[i].getType();
    int weight = info->getWaitingRoom()[i].getDuration();
    //checks for non distributed vehicles
    if(representation[i]==0){
      non_distributed += weight;
      continue;
    }
    //we know it isnt 0 so we proceed in getting the lane
    Lane lane  = info->getAllLanes()[representation[i]-1];
    //checks for non allowed vehicles
    if(!lane.compatibleType(type)){
      ++non_allowed;
    }
    //adds weight to the lane chosen
    loadxlane[representation[i]-1] += weight;
  }
  //goes through each lane and its total weight
  for(int i = 0; i < info->max_val; ++i){
    //substracts how far from the mean it was
    score += std::abs(loadxlane[i]-mean);
    //substracts how much it went past capacity
    int overfull = loadxlane[i]-info->laneCapacity(i);
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


void Individual::printIndividual(){
  std::cout<< "[";
  for(int i = 0; i<representation.size(); ++i){
    std::cout<<representation[i];
  }
  std::cout<< ":"<<fitness<<"]";
}

Population::Population(Distribute& d):info(d){
  //population.resize(info.max_len);
}

void Population::initialize_population(){
  for(int i = 0;i<p_size;i++){
    population.push_back(Individual(info));
  }
  sort_population();
}

bool isFitter(Individual a, Individual b){ //a is fitter than b
  return (a.getFitness()<b.getFitness());
}

void Population::sort_population(){
  std::sort(population.begin(), population.end(), isFitter);
}

int Population::individual_selection(){
    double p = info.random_exp()/10.0;
//std::cout<<info.random_exp()<<"p"<<p<<"!\n";
    p = p>=1?std::fmod(p,1):p; //p will be a number between 0 and 1
    int index = (int)std::floor(p_size*p); //index on solution space
//std::cout<<index<<"!\n";
    return index;
}

std::deque<int> Population::generate_mask(){
  std::deque<int> mask;
  for(int i=0; i<info.max_len; ++i){
    mask.push_back(info.random_binary());
  }
  return mask;
}

std::deque<int> Population::invert_mask(std::deque<int> m){
  for(int i =0; i<m.size();++i){
    m[i]=std::abs(m[i]-1);
  }
  return m;
}

//selects and reproduces de population for a new generation
void Population::advance_generation(){//returns pop to be reproduced
  std::deque<Individual> next_gen;
  //fittest individual always lives
  next_gen.push_back(Individual(population[0],info));
  //create probability of picking an index (being)
  for(int i=1; i<=p_size/2; i++){
    Individual first_parent = population[individual_selection()];
    Individual second_parent = population[individual_selection()];
    auto mask = generate_mask();
    auto specimen = Individual(first_parent,second_parent,mask,info);
    next_gen.push_back(specimen);
    specimen = Individual(second_parent,first_parent,mask,info);
//std::cout<<"!\n";
    next_gen.push_back(specimen);
  }
  next_gen.pop_back();
  population=next_gen;
  sort_population();
}

//calculates the mean fitness of the population
double Population::mean(){
  double mean =  0;
  for(int i=0; i<population.size(); ++i){
    mean+=population[i].getFitness();
  }
  return mean/(double)population.size();
}

void Population::printPopulation(){
  //double capacity_per_lane = (double)info.totalCapacity()/(double)info.max_val;
  std::cout<< "e:"<<mean()<<" len:"<< population.size() <<"{\n";
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
  //std::cout<<"max len:"<<max_len<<"\n";
  waitingRoom = f.getWaitingRoom();
  allLanes = f.getAllLanes();
  rng.seed(std::random_device()());
  rng2.seed(std::random_device()());
  uint_dist = std::uniform_int_distribution<uint32_t>(0,max_val);
  index_dist = std::uniform_int_distribution<uint32_t>(0,max_len-1);
  binary_dist = std::uniform_int_distribution<uint32_t>(0,1);
  srand (time(NULL));

  outfile.open(outfile_name(), std::ios::out | std::ios::trunc );
  std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
  std::cout.rdbuf(outfile.rdbuf()); //redirect cout to outfile

  execute();

  std::cout.rdbuf(coutbuf);
  outfile.close();
}

std::string Distribute::outfile_name(){
  std::string name = "d"+std::to_string(file_count)+".txt";
  ++file_count;
  return name;
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
  if(waitingRoom.size()==0){return;}
  population.initialize_population();
  population.printPopulation();
  //run as many generations as defined in the class
  for(int i=0;i<generations;++i){
    population.advance_generation();
    population.printPopulation();
  }
  distribute_cars();
}

void Distribute::distribute_cars(){
  std::deque<Vehicle> fails; //failed to distribute, new waiting room
  Individual best = population.get_fittest();
  bool success;
  int len = max_len;
  for(int i=0;i<len;++i){
    if(best[i]==0){
      fails.push_back(waitingRoom[i]);
    }
    else{
      success = allLanes[best[i]-1].addToQueue(waitingRoom[i]);
      //std::cout<<best[i]<<"\n";
      if(!success){
        fails.push_back(waitingRoom[i]);
      }
    }
  }
  facility.setWaitingRoom(fails);
  facility.setAllLanes(allLanes);
  //facility.printFacility();
}

