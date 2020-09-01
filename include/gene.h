#ifndef GENE_H
#define GENE_H

#define SIZE_OF_DNA 36
// first 30 are brain, next 3 are color, next 2 are size, last one is speed

class Gene
{
public:
    Gene();
    Gene(Gene parent1_gene, Gene parent2_gene);
    void mutate();

    double gene_data[SIZE_OF_DNA];
};

#endif