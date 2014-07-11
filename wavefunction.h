#ifndef WAVEFUNCTION_H
#define WAVEFUNCTION_H

#include <vector>
#include <string>
#include <cmath>

class Wavefunction
{
public:
    Wavefunction();

    std::string name(){return _name;};

    double at(std::vector<std::vector<double> > v);
	double distance(std::vector<double> v1, std::vector<double> v2);

private:
    std::vector< std::vector<double> > R;
	std::string _name;
    int Z;
};

class VectorSizeMismatch{};
class ElectronNucleiMismatch{};
#endif // WAVEFUNCTION_H
