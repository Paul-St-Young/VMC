#include <gtest/gtest.h>
#include "../wavefunction.h"
#include <iostream>
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

// ----------------------- Test Constructor ----------------------- //
TEST(WavefunctionTest,EmptyConstructor){
    Wavefunction wf; 
    EXPECT_EQ(wf.name(),"Hydrogen Molecule");
}
// ---------------------------------------------------------------- //

//----------------------------Test Distance----------------------------
TEST(WavefunctionTest,DistanceH2){
    Wavefunction wf;
    vector<double> v1(3,0);
    vector<double> v2(3,0);
    v2[0]=1.4;
    EXPECT_EQ(1.4,wf.distance(v1,v2));
}

TEST(WavefunctionTest,DistanceRandom){
    Wavefunction wf;
    vector<double> v1(3,0);
    vector<double> v2(3,0);
    v1[0]=1.2;v1[1]=0.51;v1[2]=1.7;
    v2[0]=3.0;v2[1]=1.15;v2[2]=0.33;
    EXPECT_EQ("2.350851",to_string(wf.distance(v1,v2)));
}
// ---------------------------------------------------------------- //

//----------------------------Test Value----------------------------
TEST(WavefunctionTest,ValueH2Nuclei){
	Wavefunction wf;
	
	// put electrons at the nuclei
	vector<double> v1(3,0);
	vector<double> v2(3,0);
	v2[0]=1.4;
	vector< vector<double> > v;
	v.push_back(v1);
	v.push_back(v2);
	
	EXPECT_EQ(0,wf.at(v));
}

TEST(WavefunctionTest,ValueOrigin){
	Wavefunction wf;
	
	// put electrons at the nuclei
	vector<double> v1(3,0);
	vector<double> v2(3,0);
	vector< vector<double> > v;
	v.push_back(v1);
	v.push_back(v2);
	
	EXPECT_EQ(1/sqrt(M_PI)-1/sqrt(M_PI)*exp(-1.4),wf.at(v));
}

TEST(WavefunctionTest,ValueMiddle){
	Wavefunction wf;
	
	// put electrons at the nuclei
	vector<double> v1(3,0);
	vector<double> v2(3,0);
	v1[0]=0.7;
	v2[0]=0.7;
	vector< vector<double> > v;
	v.push_back(v1);
	v.push_back(v2);
	
	EXPECT_EQ(0,wf.at(v));
}
// ---------------------------------------------------------------- //

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
