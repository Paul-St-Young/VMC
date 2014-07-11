#include "wavefunction.h"

#include <iostream>

using namespace std;

Wavefunction::Wavefunction()
{
    name = "Hydrogen Molecule";
    Z = 2;

    // put the 2 H atoms at (0,0,0) and (1.4,0,0)
    vector<double> R1(3,0);
    vector<double> R2(3,0);
    R2[0]=1.4;
    R.push_back(R1);
    R.push_back(R2);
}

double Wavefunction::at(vector<vector<double>> v){

    // check input validity
    if (v.size()!=2){
        cout << name << " must have " << Z << " electrons - no more, no less" << endl;
        exit(0);
    }
    const double pi = 3.1415926535897;

    // calculate electron-nuclei distances
    vector<double> r(v.size());
    for (unsigned int n=0;n<v.size();n++){
        r[n]=distance(v[n],R[n]);
    }

    // return the value of the wave function
    return 1/sqrt(pi)*exp(-r[0])-1/sqrt(pi)*exp(-r[1]);
}

double Wavefunction::distance(vector<double> v1, vector<double> v2){
    // check input validity
    if (v1.size()!= v2.size()){
        throw VectorSizeMismatch();
    }

    // calculate distance^2 r2
    double r2=0;
    for (unsigned int i=0;i<v1.size();i++){
        r2 += (v1[i]-v2[i])*(v1[i]-v2[i]);
    }

    // return distance r
    return sqrt(r2);
}
