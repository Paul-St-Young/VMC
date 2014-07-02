#include "wavefunction.h"

using namespace std;

Wavefunction::Wavefunction()
{
    name = "Hydrogen Atom";
}

double Wavefunction::at(vector<double> v){
    const double pi = 3.1415926535897;
    double r = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
    return 1/sqrt(pi)*exp(-r);
}
