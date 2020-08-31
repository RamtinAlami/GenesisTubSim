#ifndef BRAIN_H
#define BRAIN_H

#include "gene.h"

class Brain
{
private:
    Gene gene;

public:
    Brain();
    Brain(Gene organism_gene);
    void next_move(double *observations);
    double memory[4];
    double output[2];
};

#endif