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
    int Z;

    double at(std::vector<std::vector<double> > v);

private:
    std::vector<std::vector<double>> R;
    double distance(std::vector<double> v1, std::vector<double> v2);
};

class VectorSizeMismatch{};
#endif // WAVEFUNCTION_H
