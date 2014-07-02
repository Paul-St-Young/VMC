#ifndef WAVEFUNCTION_H
#define WAVEFUNCTION_H

#include <vector>
#include <string>
#include <cmath>

class Wavefunction
{
public:
    Wavefunction();

    std::string name;
    double at(std::vector<double> v);
};

#endif // WAVEFUNCTION_H
