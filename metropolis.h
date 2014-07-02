#ifndef METROPOLIS_H
#define METROPOLIS_H

#include <vector>
#include <random>
#include <fstream>
#include "wavefunction.h"

class Metropolis
{
public:
    Metropolis();
    ~Metropolis();
    void setup(int myNSTEPS=100, double mysigma=0.5, std::string mytraj="traj.dat");
    void evaluate(); // sample the hydrogen atom 1s orbital

private:
    Wavefunction wfs;

    std::vector<double> walker;
    double sigma;
    int NSTEPS;

    std::ofstream trajfile;


};

#endif // METROPOLIS_H
