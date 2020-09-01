#ifndef ORGANISM_H
#define ORGANISM_H

#include "simulator.h"
#include "location.h"
#include "gene.h"
#include "food.h"
#include "brain.h"
#include "tilable.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Organism : public Tilable
{
protected:
    int size;
    int been_stationary;
    bool fertile;
    double speed;
    Gene gene;
    int food_level;
    Brain controller_brian;
    bool is_living;

public:
    Organism();
    Organism(Organism *parten1, Organism *parent2);

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    void init();

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    void mate(Organism *other_organism);

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    bool tryMate(Organism *other_person);

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    bool tryConsume(Food *food_item);

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    void consumeFood(Food *food_item);

    // @brief Method returns a random boolean value with input probability
    /// @return a boolean based on input probability
    void progress();

    /// @brief Method returns a random boolean value with input probability
    /// @return a boolean based on input probability
    void move();

    /// @brief Method returns a random boolean value with input probability
    /// @return a boolean based on input probability
    bool isFertile();

    /// @brief Method returns a random boolean value with input probability
    /// @return a boolean based on input probability
    int getSpeed();

    /// @brief Method returns a random boolean value with input probability
    /// @return a boolean based on input probability
    bool is_alive();

    double observations[3];
};

extern std::vector<Organism> organisms;

#endif