#include "../include/tilable.h"

Tilable::Tilable() {}

void Tilable::change_tile_index(int new_tile_index) { tile_index = new_tile_index; }

int Tilable::get_tile_index() { return tile_index; }

Location Tilable::getLocation() { return location; }

sf::RectangleShape Tilable::getShape() { return shape; }

void Tilable::moveShape() { shape.setPosition(location.getX(), location.getY()); }