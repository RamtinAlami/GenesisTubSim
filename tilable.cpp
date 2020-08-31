#include "tilable.h"
#include "map.h"

Tilable::Tilable()
{
}

void Tilable::change_tile_index(int new_tile_index)
{
    tile_index = new_tile_index;
}

int Tilable::get_tile_index()
{
    return tile_index;
}

void Tilable::set_tile(int x, int y)
{
    grid_map[x][y].add_tilable(this);
}