#ifndef MAP_H
#define MAP_H

#include "simulator.h"
#include "location.h"
#include "tile.h"
#include <vector>

class Map
{
public:
    Map();
    bool food_present_next(Tile tile);
    bool organism_present_next(Tile tile);
    Tilable *get_food_next(Tile tile);
    Tilable *get_organism_next(Tile tile);
};

extern Tile grid_map[X_LIMIT][Y_LIMIT];

#endif