#include "food.h"
#include "simulator.h"
#include <math.h>
#include <bsd/stdlib.h>
#include <stdio.h>

// Food foods[NUMBER_OF_FOOD] = {Food()};
std::vector<Food> foods(NUMBER_OF_FOOD);

Food::Food()
{
    shape = sf::RectangleShape(sf::Vector2f(FOOD_SIZE, FOOD_SIZE));
    shape.setFillColor(sf::Color(55, 55, 55));
    location = Location();
    set_tile(location.getX(), location.getY());
    shape.setPosition(location.getX(), location.getY());
    isAvaliable = true;
    type = FOOD;
}

void Food::consume()
{
    if (try_event(0.9999))
    {
        // location.setX(a)
        location = Location();
        shape.setPosition(location.getX(), location.getY());
    }
    else
    {
        isAvaliable = false;
    }
}

bool Food::is_avaliable()
{
    return isAvaliable;
}