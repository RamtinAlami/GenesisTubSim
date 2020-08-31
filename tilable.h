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
    // Abstract class that Organism and items that can places on times inherit from
public:
    Tilable();
    void change_tile_index(int new_tile_index);
    void set_tile(int x, int y);
    int get_tile_index();
    int tile_index;
    Tile_type type;
};

#endif