#ifndef TILE_H
#define TILE_H

#include "simulator.h"
#include "tilable.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Tile
{
public:
    Tile(int cord_x, int cord_y);
    Tile();
    int cord_x;
    int cord_y;
    bool food_present();
    bool organism_present();
    void add_tilable(Tilable *Tilable_object);
    void remove_tilable(Tilable *Tilable_object);
    Tilable *get_food();
    Tilable *get_organism();
    std::vector<Tilable *> tile_objects;
};

#endif