#include <math.h>
#include <cmath>
#include <bsd/stdlib.h>
#include <algorithm>
#include <iostream>

#include "../include/gene.h"
#include "../include/brain.h"
#include "../include/simulator.h"

Brain::Brain()
{
    gene = Gene();
}

// Main brain constructor
Brain::Brain(Gene organism_gene)
{
    gene = organism_gene;
}

// sets the brain's output variables at each call based on observations
// the values will be between [-1,1]
// output[0] will be set to horizontal direction
// output[1] will be set to vertical direction
// current model is 2-4-2 NN
void Brain::next_move(double *observations)
{
    double first_layer[4] = {0};
    int num_observations = (sizeof(observations) / sizeof(*observations));
    int weight_counter = 0;

    for (int n = 0; n < 4; n++)
    {
        for (int x = 0; x < num_observations; x++)
        {
            first_layer[n] = first_layer[n] + gene.gene_data[weight_counter] * observations[x];
            weight_counter++;
        }
        first_layer[n] = first_layer[n] + memory[n] * gene.gene_data[weight_counter]; // adds memory
        first_layer[n] = first_layer[n] + gene.gene_data[weight_counter + 1];         // adds constant
        first_layer[n] = std::max(first_layer[n], 0.0);                               // relu func
        memory[n] = first_layer[n];                                                   // saves the memory
        weight_counter = weight_counter + 2;
    }
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