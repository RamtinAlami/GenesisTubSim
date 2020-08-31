#include <math.h>
#include <cmath>
#include <bsd/stdlib.h>
#include <algorithm>
#include <iostream>

#include "gene.h"
#include "brain.h"
#include "simulator.h"

Brain::Brain()
{
    gene = Gene();
    double memory[4] = {0};
    double output[2] = {0};
}

Brain::Brain(Gene organism_gene)
// init the brain
{
    gene = organism_gene;
}

void Brain::next_move(double *observations)
// TODO FIX THIS TO PROPER BRAIN
{
    double first_layer[4] = {0};
    double second_layer[2] = {0};
    int weight_counter = 0;

    for (int n = 0; n < 4; n++)
    {
        for (int x = 0; x < 2; x++)
        {
            first_layer[n] = first_layer[n] + gene.gene_data[weight_counter] * observations[x];
            weight_counter++;
        }
        first_layer[n] = first_layer[n] + memory[n] * gene.gene_data[weight_counter]; // adds memory
        first_layer[n] = first_layer[n] + gene.gene_data[weight_counter];             // adds b
        first_layer[n] = std::max(first_layer[n], 0.0);
        memory[n] = first_layer[n]; // saves the memory
        weight_counter = weight_counter + 2;
    }
    // std::cout << memory[0] << " " << memory[0] << " " << memory[0] << " " << '\n';

    for (int n = 0; n < 2; n++)
    {
        for (int x = 0; x < 4; x++)
        {
            output[n] = output[n] + gene.gene_data[weight_counter] * first_layer[x];
            weight_counter++;
        }
        output[n] = output[n] + gene.gene_data[weight_counter]; // adds b
        output[n] = tanh(output[n]);
        weight_counter++;
    }
};