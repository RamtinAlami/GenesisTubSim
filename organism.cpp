#include "organism.h"
#include "gene.h"
#include "brain.h"
#include "simulator.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <bsd/stdlib.h>

std::vector<Organism> organisms(STARING_NUM_ORGANISM);

Organism::Organism()
{
    fertile = false;
    gene = Gene();
    observations[3] = {0.0};
    speed = (gene.gene_data[35] + 1) * 5;
    shape = sf::RectangleShape(sf::Vector2f(ORGANISM_SIZE + (gene.gene_data[33] * 1.5), ORGANISM_SIZE + (gene.gene_data[33] * 1.5)));
    shape.setFillColor(sf::Color((gene.gene_data[30] + 1) * 100, (gene.gene_data[31] + 1) * 100, (gene.gene_data[32] + 1) * 100));
    state = ALIVE;
    food_level = arc4random_uniform(100);
    location = Location();
    controller_brian = Brain(gene);
    type = ORGANISM;
    set_tile(location.getX(), location.getY());
}

Organism::Organism(Organism *parent1, Organism *parent2)
{
    fertile = false;
    gene = Gene(parent1->gene, parent2->gene);
    observations[3] = {0.0};
    speed = (gene.gene_data[35] + 1) * 5;
    shape = sf::RectangleShape(sf::Vector2f(ORGANISM_SIZE + (gene.gene_data[33] * 1.5), ORGANISM_SIZE + (gene.gene_data[33] * 1.5)));
    shape.setFillColor(sf::Color((gene.gene_data[30] + 1) * 100, (gene.gene_data[31] + 1) * 100, (gene.gene_data[32] + 1) * 100));
    state = ALIVE;
    gene.mutate(); // Mutate the gene after creation
    food_level = arc4random_uniform(100);
    location = Location(parent1->location.getX(), parent1->location.getY()); // Location next to parent
    controller_brian = Brain(gene);
    type = ORGANISM;
    set_tile(location.getX(), location.getY());
}

void Organism::mate(Organism *other_organism)
{
    // TODO CHECK THIS !!! THIS ACTS WEIRD
    organisms.push_back(Organism(this, other_organism));
}

void Organism::consume(Food *food_item)
{
    // TODO CHECK THIS !!! THIS ACTS WEIRD
    food_item->consume();
    food_level = food_level + 10;
}

bool Organism::try_consume(Food *food_item)
{
    double distance = location.get_distance(food_item->location);
    observations[1] = std::min(observations[1], distance);
    if (location.get_distance(food_item->location) > 2)
    {
        return false;
    }
    if (try_event(0.9))
    {
        consume(food_item);
        return true;
    }
    return false;
}

bool Organism::try_mate(Organism *other_organism)
{
    if (!(other_organism->fertile))
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
        // std::cout << "mating";
        mate(other_organism);
        return true;
    }
    return false;
}

void Organism::progress()
{
    food_level = food_level - speed;
    if (food_level >= 140)
    {
        fertile = true;
    }
    if (food_level < 30 && try_event(PROBABILITY_OF_STARVATION))
    {
        state = DEAD;
    }
}

void Organism::move()
{
    // TODO change this to actual observations
    // double observations[3] = {0.2, 1.1, 1};
    controller_brian.next_move(observations);
    double *commands = controller_brian.output;

    int aim_x = location.getX();
    int aim_y = location.getY();

    aim_x = aim_x + (commands[0] * 2);
    aim_y = aim_y + (commands[1] * 2);

    // if (try_event(0.5))
    // {
    //     aim_x = aim_x + arc4random_uniform(4);
    // }
    // else
    // {
    //     aim_x = aim_x - arc4random_uniform(4);
    // }

    // if (try_event(0.5))
    // {
    //     aim_y = aim_y + arc4random_uniform(4);
    // }
    // else
    // {
    //     aim_y = aim_y - arc4random_uniform(4);
    // }

    location.move_toward(aim_x, aim_y, 5);
    set_tile(location.getX(), location.getY());
}

bool Organism::is_alive()
{
    return state != DEAD;
}

void Organism::moveShape()
{
    shape.setPosition(location.getX(), location.getY());
}