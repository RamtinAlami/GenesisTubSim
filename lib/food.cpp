#include <math.h>
#include <bsd/stdlib.h>
#include <stdio.h>

#include "../include/food.h"
#include "../include/simulator.h"

// Food foods[NUMBER_OF_FOOD] = {Food()};
std::vector<Food> foods(NUMBER_OF_FOOD);

Food::Food()
{
    shape = sf::RectangleShape(sf::Vector2f(FOOD_SIZE, FOOD_SIZE));
    shape.setFillColor(sf::Color(55, 55, 55));
    location = Location();
    shape.setPosition(location.getX(), location.getY());
    isConsumed = true;
    type = FOOD;
}

void Food::consume()
{
    if (try_event(PROBABILITY_OF_FOOD_GROWING_BACK))
    {
        // location.setX(a)
        location = Location();
        shape.setPosition(location.getX(), location.getY());
    }
    else
    {
        isConsumed = false;
    }
}

bool Food::isAvaliable()
{
    return isConsumed;
};
