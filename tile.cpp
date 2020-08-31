#include "tile.h"
#include <bsd/stdlib.h>

#include "location.h"
#include "simulator.h"
Tile::Tile() {}
Tile::Tile(int x, int y)
{
    cord_x = x;
    cord_y = y;
};
bool Tile::food_present() { return true; };
bool Tile::organism_present() { return true; };

void Tile::add_tilable(Tilable *Tilable_object){
#pragma omp critical
    {Tilable_object->change_tile_index(tile_objects.size());
tile_objects.push_back(Tilable_object);
}
}
;
void Tile::remove_tilable(Tilable *Tilable_object){
#pragma omp critical
    {tile_objects.erase(tile_objects.begin() + Tilable_object->tile_index);
}
}
;