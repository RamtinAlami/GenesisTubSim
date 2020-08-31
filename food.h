#ifndef FOOD_H
#define FOOD_H

#include "simulator.h"
#include "location.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Food
{
public:
    Food();
    void consumed();
    bool isAvaliable;
    bool is_avaliable();
    Location location;
    sf::RectangleShape shape;
};

extern std::vector<Food> foods;

// extern Food foods[NUMBER_OF_FOOD];

#endif