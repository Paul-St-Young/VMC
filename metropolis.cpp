#include "metropolis.h"

#include <iostream>
using namespace std;

Metropolis::Metropolis(){
}

Metropolis::~Metropolis(){
    trajfile.close();
}

void Metropolis::setup(int myNSTEPS, double mysigma, string mytraj){
    walker.assign(3,.5);
    sigma   = mysigma;
    NSTEPS  = myNSTEPS;

    trajfile.open(mytraj);
}

void Metropolis::evaluate(){
    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<double> dist_uni(0.0,1.0);
    normal_distribution<double> dist_gauss(0,sigma);

    for (int istep=1;istep<=NSTEPS;istep++){

        // record trajectory
        trajfile << walker[0] << " " << walker[1] << " " << walker[2] << endl;

        // suggest a new move
        vector<double> move(3,0);
        for (int i=0;i<3;i++){
            move[i]=walker[i]+dist_gauss(gen);
        }

        // calculate Metropolis acceptance rate
        double A = (wfs.at(move)*wfs.at(move))/
                (wfs.at(walker)*wfs.at(walker));
        A = 1<A?1:A;

        // accept/reject
        if (dist_uni(gen)<.5){ // accept move
            walker[0]=move[0];walker[1]=move[1];walker[2]=move[2];
        } else { // reject move

        }

    }


}
