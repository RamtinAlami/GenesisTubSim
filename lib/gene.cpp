#include <math.h>
#include <bsd/stdlib.h>
#include <iostream>

#include "../include/gene.h"
#include "../include/simulator.h"

Gene::Gene()
// Init gene with random values
{
    for (int i = 0; i < SIZE_OF_DNA; i++)
    {
        double val = ((double)arc4random() / UINT32_MAX);

        if (try_event(0.5))
        {
            gene_data[i] = -1.0 * val;
        }
        else
        {
            gene_data[i] = val;
        }
    }
}

Gene::Gene(Gene parent1_gene, Gene parent2_gene)
// Init gene with two parent genes
{
    for (int i = 0; i < SIZE_OF_DNA; i++)
    {
        if (try_event(0.5))
        {
            gene_data[i] = parent1_gene.gene_data[i];
        }
        else
        {
            gene_data[i] = parent2_gene.gene_data[i];
        }
    }
}

void Gene::mutate()
{
    for (int i = 0; i < SIZE_OF_DNA; i++)
    {
        if (try_event(MUTATION_PROB))
        {
            int resolution = 1000000;
            gene_data[i] = (double)(arc4random_uniform(resolution) / resolution);
        }
    }
}