#ifndef GENE_H
#define GENE_H

#include "gene.h"

#define SIZE_OF_DNA 23

class Gene
{

public:
    Gene();
    Gene(Gene parent1_gene, Gene parent2_gene);
    void mutate();

    double gene_data[SIZE_OF_DNA];
};

#endif