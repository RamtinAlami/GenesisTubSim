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

int mod(int a, int b) { return (a % b + b) % b; }

void sim_main()
{
    sf::RenderWindow window(sf::VideoMode(X_LIMIT, Y_LIMIT), "Sim!");
    window.setSize(sf::Vector2u(1000, 1000));
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

        // Set here to make sure indexes don't get messed up
        int num_organism = organisms.size();

        usleep(20000);
        if (true)
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
                }
            }
        }

        for (int p = 0; p < num_organism; p++)
        {
            int p_limit = p + 1;

            if (organisms[p].is_alive())
            {
                alive_organism++;
                organisms[p].move();
                organisms[p].progress();

                for (int p2 = p_limit; p2 < num_organism; p2++)
                {
                    organisms[p].try_mate(&organisms[p2]);
                }

                for (int p3 = 0; p3 < NUMBER_OF_FOOD; p3++)
                {
                    if (foods[p3].is_avaliable())
                    {
                        organisms[p].try_consume(&foods[p3]);
                    }
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