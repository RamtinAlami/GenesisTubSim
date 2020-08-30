#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <bsd/stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#include "organism.h"
#include "simulator.h"
#include "location.h"

using namespace std;

bool try_event(double probability)
{
    assert(probability >= 0.0 && probability <= 1.0); // to make sure probabilities are in [0.0,1.0]
    const int resolution = 100000;
    double rand_num = arc4random_uniform(resolution);
    rand_num = rand_num / (double)resolution;
    return rand_num <= probability;
}

void sim_main()
{
    // std::vector<sf::RectangleShape *> pShapes;

    // for (int i = 0; i < 10; i++)
    // {
    //     sf::RectangleShape *p;
    //     p = new sf::RectangleShape(sf::Vector2f(5, 5));
    //     p->setPosition(100 + (i * 10), 100);
    //     pShapes.push_back(p);
    // }

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Sim!");
    // for (int i = 0; i < 1000000000000000000; i++)
    int alive_organism;
    while (window.isOpen())
    {
        alive_organism = 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // move people.
        int num_organism = organisms.size();

        usleep(8000);
        window.clear(sf::Color(212, 237, 255));
        for (int p = 0; p < num_organism; p++)
        {
            if (organisms[p].is_alive())
            {
                alive_organism++;
                sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(8, 8));
                shape.setPosition(organisms[p].location.getX(), organisms[p].location.getY());
                shape.setFillColor(sf::Color(16, 74, 4));
                window.draw(shape);
                organisms[p].move();
                organisms[p].progress();
            }
        }

        for (int p = 0; p < num_organism; p++)
        {
            if (organisms[p].is_alive())
            {
                for (int p2 = 0; p2 < num_organism; p2++)
                {
                    organisms[p].try_mate(organisms[p2]);
                }
            }
        }

        window.display();
        std::cout << "Num of organism " << alive_organism << "\n";
    }
}

int main()
{
    sim_main();
    return 0;
}