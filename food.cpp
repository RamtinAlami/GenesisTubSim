#include "food.h"
#include "simulator.h"
#include <math.h>
#include <bsd/stdlib.h>

// Food foods[NUMBER_OF_FOOD] = {Food()};
std::vector<Food> foods(NUMBER_OF_FOOD);

Food::Food()
{
    shape = sf::RectangleShape(sf::Vector2f(FOOD_SIZE, FOOD_SIZE));
    shape.setFillColor(sf::Color(55, 55, 55));
    location = Location();
    shape.setPosition(location.getX(), location.getY());
    isAvaliable = true;
}

void Food::consumed()
{
    if (try_event(PROBABILITY_OF_FOOD_GROWING_BACK))
    {
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
    return true;
}