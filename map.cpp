#include "map.h"
#include "simulator.h"

Tile grid_map[X_LIMIT][Y_LIMIT];

Map::Map()
{
    for (int i = 0; i <= X_LIMIT; i++)
    {
        for (int j = 0; j <= Y_LIMIT; j++)
        {
            grid_map[i][j] = Tile(i, j);
        }
    }
}

bool food_present_next(Tile tile)
{
    int cord_x = tile.cord_x;
    int cord_y = tile.cord_y;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            cord_x = cord_x - 1 + i;
            cord_y = cord_y - 1 + j;
            if (cord_x < 0 || cord_x > X_LIMIT || cord_y < 0 || cord_y > Y_LIMIT)
                continue;
            // if (grid_map[cord_x][cord_y])
        }
    }
}

bool organism_present_next()
{
    return false;
}

Tilable *get_food_next(){

};

Tilable *get_organism_next(){

};
