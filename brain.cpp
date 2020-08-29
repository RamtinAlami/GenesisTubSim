#include <math.h>
#include <bsd/stdlib.h>

#include "gene.h"
#include "brain.h"
#include "simulator.h"

Brain::Brain(Gene organism_gene)
// init the brain
{
    gene = organism_gene;
}

double *Brain::next_move(double *observations)
// TODO FIX THIS TO PROPER BRAIN
{
    double output[2] = {0.1, 0.1};
    return output;
};