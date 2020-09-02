#include <iostream>
#include <vector>
#include <math.h>
#include <bsd/stdlib.h>

#include "../include/organism.h"
#include "../include/gene.h"
#include "../include/brain.h"
#include "../include/simulator.h"

std::vector<Organism> organisms(STARING_NUM_ORGANISM);

Organism::Organism()
{
    gene = Gene();
    init();
}

Organism::Organism(Organism *parent1, Organism *parent2)
{
    gene = Gene(parent1->gene, parent2->gene);
    gene.mutate(); // Mutate the gene after creation
    init();
}

void Organism::init()
{
    fertile = false;
    age = 0;
    is_young = true;
    been_stationary = 0;
    speed = (gene.gene_data[35] + 1) * 5;
    shape = sf::RectangleShape(sf::Vector2f(ORGANISM_SIZE + (gene.gene_data[33] * 1.5), ORGANISM_SIZE + (gene.gene_data[33] * 1.5)));
    shape.setFillColor(sf::Color((gene.gene_data[30] + 1) * 100, (gene.gene_data[31] + 1) * 100, (gene.gene_data[32] + 1) * 100));
    is_living = true;
    food_level = 70;
    location = Location();
    controller_brian = Brain(gene);
    type = ORGANISM;
}

void Organism::mate(Organism *other_organism)
{
    organisms.push_back(Organism(this, other_organism));
}

void Organism::consumeFood(Food *food_item)
{
    food_item->consume();
    food_level = food_level + 10;
}

bool Organism::tryConsume(Food *food_item)
{
    double distance = location.get_distance(food_item->getLocation());

    observations[1] = std::min(observations[1], distance);

    if (location.get_distance(food_item->getLocation()) > 2)
    {
        return false;
    }
    if (try_event(0.9))
    {
        consumeFood(food_item);
        return true;
    }
    return false;
}

bool Organism::tryMate(Organism *other_organism)
{
    if (!(other_organism->isFertile()))
    {
        return false;
    }

    double distance = location.get_distance(other_organism->location);

    observations[0] = std::min(distance, observations[0]);

    if (distance > MATING_PROXIMITY)
    {
        return false;
    }
    if (try_event(MATING_PROBABILITY))
    {
        mate(other_organism);
        return true;
    }
    return false;
}

void Organism::progress()
{
    food_level = food_level - speed;
    age++;
    if (food_level >= 130)
    {
        fertile = true;
    }
    if (((food_level < 30 && try_event(PROBABILITY_OF_STARVATION)) || fertile) || (age >= 50))
    {
        is_living = false;
    }
}

void Organism::move()
{
    controller_brian.next_move(observations);
    double *commands = controller_brian.output;
    location.move_directions(commands[0], commands[1], speed);
}

bool Organism::is_alive()
{
    return is_living;
}

bool Organism::isFertile()
{
    return fertile;
}
