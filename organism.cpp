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
    shape = sf::RectangleShape(sf::Vector2f(ORGANISM_SIZE, ORGANISM_SIZE));
    shape.setFillColor(sf::Color(16, 74, 4));
    gene = Gene();
    state = ALIVE;
    food_level = arc4random_uniform(100);
    location = Location();
    controller_brian = Brain(gene);
    type = ORGANISM;
    set_tile(location.getX(), location.getY());
}

Organism::Organism(Organism *parent1, Organism *parent2)
{
    shape = sf::RectangleShape(sf::Vector2f(3, 3));
    shape.setFillColor(sf::Color(16, 74, 4));
    state = ALIVE;
    gene = Gene(parent1->gene, parent2->gene);
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
    if (location.get_distance(food_item->location) > MATING_PROXIMITY)
    {
        return false;
    }
    if (try_event(MATING_PROBABILITY))
    {
        consume(food_item);
        return true;
    }
    return false;
}

bool Organism::try_mate(Organism *other_organism)
{
    if (other_organism->food_level <= 120)
    {
        return false;
    }
    if (location.get_distance(other_organism->location) > MATING_PROXIMITY)
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
    food_level--;
    if (food_level < 30 && try_event(0.2))
    {
        state = ALIVE;
    }
}

void Organism::move()
{
    // TODO change this to actual observations
    // double observations[4] = {9.2, 1.1, 2.3, 1.1};
    // double *next_moves = controller_brian.next_move(observations);

    // double dest_x = location.getX() + cos(next_moves[0]) * next_moves[1];
    // double dest_y = location.getY() + sin(next_moves[0]) * next_moves[1];

    // // delete next_moves;
    // location.move_toward(dest_x, dest_y, 5);
    location.move_toward(arc4random_uniform(X_LIMIT), arc4random_uniform(Y_LIMIT), 5);
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