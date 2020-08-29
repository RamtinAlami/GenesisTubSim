#ifndef BRAIN_H
#define BRAIN_H

#include "gene.h"

class Brain
{
private:
    Gene gene;

public:
    Brain(Gene organism_gene);
    double *next_move(double *observations);
};

#endif