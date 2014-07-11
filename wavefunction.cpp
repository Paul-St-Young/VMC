#include "wavefunction.h"

#include <iostream>

using namespace std;

Wavefunction::Wavefunction()
{
    _name = "Hydrogen Molecule";
    Z = 2;

    // put the 2 H atoms at (0,0,0) and (1.4,0,0)
    vector<double> R1(3,0);
    vector<double> R2(3,0);
    R2[0]=1.4;
    R.push_back(R1);
    R.push_back(R2);
}

double Wavefunction::at(vector< vector<double> > v){

    // check input validity
    if (v.size()!=2){
        cout << _name << " must have " << Z << " electrons - no more, no less" << endl;
        throw ElectronNucleiMismatch();
    }

    // calculate electron-nuclei distances
    vector< vector<double> > r(v.size());
    for (unsigned int i=0;i<v.size();i++) r[i].assign(v.size(),0);
    for (unsigned int i=0;i<v.size();i++){
        for (unsigned int j=0;j<v.size();j++){
            r[i][j]=distance(v[i],R[j]);
        }
    }

    double psi11=exp(-r[0][0])+exp(-r[0][1]);
    double psi12=exp(-r[1][0])+exp(-r[1][1]);
    double psi21=exp(-r[0][0])-exp(-r[0][1]);
    double psi22=exp(-r[1][0])-exp(-r[1][1]);
    // return the value of the wave function
    return psi21*psi22;
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
