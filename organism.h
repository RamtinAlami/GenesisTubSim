#ifndef ORGANISM_H
#define ORGANISM_H

#include "simulator.h"
#include "location.h"
#include "gene.h"
#include "brain.h"
#include <vector>

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

    Gene gene;
    int food_level;
    Brain controller_brian;
    Location location;

    States state;
};

extern std::vector<Organism> organisms;

#endif