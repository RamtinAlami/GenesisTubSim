#ifndef TILABLE_H
#define TILABLE_H

#include "simulator.h"
#include "location.h"
#include <vector>
#include <SFML/Graphics.hpp>

enum Tile_type
{
    FOOD,
    ORGANISM
};

class Tilable
{
protected:
    Location location;
    sf::RectangleShape shape;

public:
    Tilable();
    int tile_index;
    Tile_type type;

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    void change_tile_index(int new_tile_index);

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    int get_tile_index();

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    Location getLocation();

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    sf::RectangleShape getShape();

    /// @brief Method returns a random boolean value with input probability
    /// @param probability the probability of returning true
    /// @return a boolean based on input probability
    void moveShape();
};

#endif