#ifndef SIMULATOR_H
#define SIMULATOR_H

// Limits of the simulation space
#define X_LIMIT 1000
#define Y_LIMIT 1000

//general simulation parameters
#define SIM_HOURS 5000
#define STARING_NUM_ORGANISM 500

#define PROBABILITY_OF_FOOD_GROWING_BACK 0.5 // set to 0 if not, 1 if always
#define NUMBER_OF_FOOD 5000

#define ORGANISM_SIZE 4
#define FOOD_SIZE 1.5

#define MUTATION_PROB 0.01

//stage
enum States
{
    ALIVE,
    DEAD
};

// how many hours the infection lasts
#define INFECTION_TIME (24 * 20)

//likelihood of the infection when exposed
#define MATING_PROBABILITY 0.5

//disease dynamics
#define NORMAL_FATALITY_RATE 0.01    // when normal
#define SATURARED_FATALITY_RATE 0.06 // when too many people in hospital
#define MATING_PROXIMITY 5.0
#define INITIAL_INFECTIONS 5

// Num of people that can saturate healthcase
#define SATURATION_THRESHOLD (NUM_PEOPLE / 5)

// std::vector<Organism> organisms;

// dive roller
// returns true or false based on probability
bool try_event(double probability);

#endif