#ifndef SIMULATOR_H
#define SIMULATOR_H

// Limits of the simulation space
#define X_LIMIT 300
#define Y_LIMIT 300

//general simulation parameters
#define SIM_HOURS 5000
#define STARING_NUM_ORGANISM 500

#define PROBABILITY_OF_FOOD_GROWING_BACK 0.9 // set to 0 if not, 1 if always
#define NUMBER_OF_FOOD 1000

#define PROBABILITY_OF_STARVATION 0.005

#define ORGANISM_SIZE 2
#define FOOD_SIZE 1

#define MUTATION_PROB 0.01

//stage
enum States
{
    ALIVE,
    DEAD
};

#define MATING_PROBABILITY 1

#define MATING_PROXIMITY 5.0

// std::vector<Organism> organisms;

// dive roller
// returns true or false based on probability
bool try_event(double probability);
int mod(int a, int b);

#endif