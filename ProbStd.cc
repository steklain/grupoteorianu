#include <iostream>
#include <cmath>
#include <string.h>
#include<float.h>
#include<complex.h>
#include <vector>
#include<gsl/gsl_complex.h>
#include<gsl/gsl_complex_math.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_blas.h>
#include <globes/globes.h>
#include<fstream>

using namespace std;

char AEDLFILE[] = "DUNE_GLoBES.glb";


int main(int argc, char * argv[])
{

	glbInit(argv[0]);
	glbInitExperiment(AEDLFILE, &glb_experiment_list[0], &glb_num_of_exps);

	ofstream outstdmu,outstde,outstdtau;

	outstdmu.open("probability_matter_DUNE_mu.dat");
	outstde.open("probability_matter_DUNE_e.dat");
	outstdtau.open("probability_matter_DUNE_tau.dat");
	
	double dm21 = 7.55e-5;
	double dm31 = 2.50e-3;
	double theta12 = asin(sqrt(0.320));
	double theta23 = asin(sqrt(0.547));
	double theta13 = asin(sqrt(0.02160));
	double deltacp = -0.68 * M_PI;

	/* Define "true" oscillation parameter vector */
	glb_params true_values = glbAllocParams();

    glbDefineParams(true_values,theta12,theta13,theta23,deltacp,dm21,dm31);
	
	glbSetDensityParams(true_values, 1.0, GLB_ALL);

	glbSetOscillationParameters(true_values);
	glbSetRates();

	double energy,probe,probmu,probtau; 
	double emin= 0.25 ; //GeV
	double emax=10 ; //GeV
	double step= 3000;
	[[maybe_unused]] double L = 1300;// km

	for (energy=emin;energy<=emax;energy+=(emax-emin)/step)
	{
	  //probmu=glbVacuumProbability(2,2,+1,energy,L);
	  //probe=glbVacuumProbability(2,1,+1,energy,L);
	  //probtau=glbVacuumProbability(2,3,+1,energy,L);
	  probmu=glbProfileProbability(0,2,2,+1,energy);
	  probe=glbProfileProbability(0,2,1,+1,energy);
	  probtau=glbProfileProbability(0,2,3,+1,energy);
	  outstdmu<<energy<<"  "<<probmu<<endl;
	  outstde<<energy<<"  "<<probe<<endl;
	  outstdtau<<energy<<"  "<<probtau<<endl;
	}


	outstdmu.close();
	outstde.close();
	outstdtau.close();
	glbFreeParams(true_values);
 	return 0;

}