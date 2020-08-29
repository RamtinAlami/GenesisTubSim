#include <math.h>
#include <bsd/stdlib.h>

#include "gene.h"
#include "simulator.h"

Gene::Gene()
// Init gene with random values
{
    for (int i = 0; i < SIZE_OF_DNA; i++)
    {
        int resolution = 1000000;
        gene_data[i] = (double)(arc4random_uniform(resolution) / resolution);
    }
}

Gene::Gene(Gene parent1_gene, Gene parent2_gene)
// Init gene with random values
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