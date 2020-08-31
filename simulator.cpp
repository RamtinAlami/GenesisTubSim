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
#include "food.h"

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

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Sim!");
    int time = 0;
    int alive_organism;
    while (window.isOpen())
    {
        time++;
        alive_organism = 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // move people.
        int num_organism = organisms.size();

        // usleep(8000);
        if (time % 2 == 0)
        {
            window.clear(sf::Color(212, 237, 255));

            for (int p = 0; p < num_organism; p++)
            {
                if (organisms[p].is_alive())
                {
                    organisms[p].moveShape();
                    window.draw(organisms[p].shape);
                }
            }

            for (int p = 0; p < NUMBER_OF_FOOD; p++)
            {
                if (foods[p].is_avaliable())
                {
                    window.draw(foods[p].shape);
                    std::cout << foods[p].location.getX() << " " << foods[p].location.getY() << "\n";
                }
            }
        }

#pragma omp parallel for
        for (int p = 0; p < num_organism; p++)
        {
            int p_limit = p + 1;

            if (organisms[p].is_alive())
            {
                organisms[p].move();
                // organisms[p].progress();

                // for (int p2 = p_limit; p2 < num_organism; p2++)
                // {
                //     organisms[p].try_mate(organisms[p2]);
                // }
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