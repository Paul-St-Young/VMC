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
    void setup(int myNSTEPS=100, double mysigma=0.5, int myN_walker=2);
    void evaluate();

    double culm_A;

private:
    Wavefunction wfs;

    int N; // number of electrons
    std::vector<std::vector<double>> walker;
    double sigma;
    int NSTEPS;

    std::ofstream trajfile,datfile;


};

#include <ostream>
template<typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T> v) {
    os << "("; for(int i = 0; i < v.size(); i++) os << v[i] << ", "; os << ")";
    return os;
}

#endif // METROPOLIS_H
