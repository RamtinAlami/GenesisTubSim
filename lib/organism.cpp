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
    fertile = false;
    gene = Gene();
    been_stationary = 0;
    observations[3] = {0.0};
    speed = (gene.gene_data[35] + 1) * 5;
    shape = sf::RectangleShape(sf::Vector2f(ORGANISM_SIZE + (gene.gene_data[33] * 1.5), ORGANISM_SIZE + (gene.gene_data[33] * 1.5)));
    shape.setFillColor(sf::Color((gene.gene_data[30] + 1) * 100, (gene.gene_data[31] + 1) * 100, (gene.gene_data[32] + 1) * 100));
    is_living = true;
    food_level = 100;
    location = Location();
    controller_brian = Brain(gene);
    type = ORGANISM;
}

Organism::Organism(Organism *parent1, Organism *parent2)
{
    fertile = false;
    been_stationary = 0;
    gene = Gene(parent1->gene, parent2->gene);
    observations[3] = {0.0};
    speed = (gene.gene_data[35] + 1) * 5;
    shape = sf::RectangleShape(sf::Vector2f(ORGANISM_SIZE + (gene.gene_data[33] * 1.5), ORGANISM_SIZE + (gene.gene_data[33] * 1.5)));
    shape.setFillColor(sf::Color((gene.gene_data[30] + 1) * 100, (gene.gene_data[31] + 1) * 100, (gene.gene_data[32] + 1) * 100));
    is_living = true;
    gene.mutate(); // Mutate the gene after creation
    food_level = 100;
    location = Location(parent1->location.getX(), parent1->location.getY()); // Location next to parent
    controller_brian = Brain(gene);
    type = ORGANISM;
}

void Organism::mate(Organism *other_organism)
{
    // TODO CHECK THIS !!! THIS ACTS WEIRD
    organisms.push_back(Organism(this, other_organism));
}

void Organism::consumeFood(Food *food_item)
{
    // TODO CHECK THIS !!! THIS ACTS WEIRD
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
    food_level = food_level - (speed * 10);
    if (food_level >= 140)
    {
        fertile = true;
    }
    if (location.next_to_end)
    {
        fertile = false;
    }
    if ((food_level < 30 && try_event(PROBABILITY_OF_STARVATION)) || been_stationary >= 12)
    {
        is_living = false;
    }
}

void Organism::move()
{
    // TODO change this to actual observations
    // double observations[3] = {0.2, 1.1, 1};
    observations[1] = (double)location.getX() / (double)X_LIMIT;
    observations[2] = (double)location.getY() / (double)Y_LIMIT;
    controller_brian.next_move(observations);
    double *commands = controller_brian.output;
    location.move_directions(commands[0], commands[1], speed);
    if ((fabs(commands[0]) <= 0.5 && fabs(commands[1]) <= 0.5) || speed < 0.2)
    {
        is_living = false;
    }
    else
    {
        been_stationary = 0;
    }
}

bool Organism::is_alive()
{
    return is_living;
}
