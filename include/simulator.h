#ifndef SIMULATOR_H
#define SIMULATOR_H

// Limits of the simulation space
#define X_LIMIT 180
#define Y_LIMIT 180

//general simulation parameters
#define STARING_NUM_ORGANISM 1000
#define NUMBER_OF_FOOD 2500
#define ORGANISM_SIZE 2
#define FOOD_SIZE 0.5

// Randomness
#define PROBABILITY_OF_FOOD_GROWING_BACK 0.999 // set to 0 if not, 1 if always
#define PROBABILITY_OF_STARVATION 0.5
#define MUTATION_PROB 0.05
#define MATING_PROBABILITY 1.0

// Other constants
#define MATING_PROXIMITY 3.0

// Some general global functions to be used

/// @brief Random boolean generator based on input probability
/// @param probability the probability of returning true
/// @return a boolean based on input probability
bool try_event(double probability);

/// @brief Better modulo function that works with negative numbers
/// @param a The input number for taking modulo of
/// @param b the base which modulo is calculated
/// @return The modulo of first value based on second a % b
int mod(int a, int b);

void moveShape();

#endif