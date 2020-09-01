#ifndef FOOD_H
#define FOOD_H

#include "simulator.h"
#include "location.h"
#include "tilable.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Food : public Tilable
{
protected:
    bool isAvaliable;
    Location location;
    sf::RectangleShape shape;

public:
    Food();

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    void consume();

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    bool isAvaliable();

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    Location getLocation();
};

extern std::vector<Food> foods;

#endif