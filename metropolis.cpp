#include "metropolis.h"

#include <iostream>
using namespace std;

Metropolis::Metropolis(){
}

Metropolis::~Metropolis(){
    trajfile.close();
    datfile.close();
}

void Metropolis::setup(int myNSTEPS, double mysigma, int myN_walker){
    N_walker= myN_walker;
    for (int i=0;i<myN_walker;i++){
        vector<double> new_walker(3,0); // start the electrons at the nucleis
        walker.push_back(new_walker);
    } walker[1][0]=1.4; // start the electrons at the nucleis

    sigma   = mysigma;
    NSTEPS  = myNSTEPS;
    culm_A  = 0;

    trajfile.open("traj.dat");
    datfile.open("data.dat");
}

void Metropolis::evaluate(){
    random_device rd;
    default_random_engine gen(rd());
    uniform_real_distribution<double> dist_uni(0.0,1.0);
    normal_distribution<double> dist_gauss(0,sigma);

    for (int istep=1;istep<=NSTEPS;istep++){

        // record trajectory
        for (int i=0;i<N_walker;i++){
            for (int j=0;j<walker[0].size();j++){
                trajfile << walker[i][j] << " ";
            }trajfile << endl;
        }

        // suggest a new move
        vector<vector<double>> move=walker;
        for (int n=0;n<N_walker;n++){
            for (int i=0;i<3;i++){
                move[n][i]+=dist_gauss(gen);
            }
        }

        // calculate Metropolis acceptance rate
        datfile << istep << ": move=" << move[0] << ", " << move[1]
                         << "  walker=" << walker[0] << ", " << walker[1] << endl;
        datfile << "wfs@move^2=" << pow(wfs.at(move),2)
                         << "  wfs@walker^2=" << pow(wfs.at(walker),2) << endl;
        double A = (wfs.at(move)*wfs.at(move))/
                (wfs.at(walker)*wfs.at(walker));
        datfile << A << endl;

        A = 1<A?1:A;
        culm_A+=A;

        // accept/reject
        if (dist_uni(gen)<A){ // accept move
            walker=move;
        } else { // reject move

        }

    }

    culm_A/=(double)NSTEPS;
}
