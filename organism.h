#ifndef ORGANISM_H
#define ORGANISM_H

#include "simulator.h"
#include "location.h"
#include "gene.h"
#include "brain.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Organism
{
public:
    Organism();
    Organism(Organism parten1, Organism parent2);
    void mate(Organism other_organism);
    bool try_mate(Organism other_person);

    void progress();
    bool is_alive();
    void move();
    void moveShape();

    Gene gene;
    int food_level;
    Brain controller_brian;
    Location location;
    sf::RectangleShape shape;

    States state;
};

extern std::vector<Organism> organisms;

#endif