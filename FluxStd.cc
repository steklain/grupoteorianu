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

	ofstream outstdmu,outstde;

	outstdmu.open("spectrum_DUNE_mu.dat");
	outstde.open("spectrum_DUNE_e.dat");
	
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

	double energy,probmumu,probemu,probtaumu,probmue,probee,probtaue,fluxmu,fluxe,fluxtau; 
	double emin= 0.25 ; //GeV
	double emax=10 ; //GeV
	double step= 3000;
	[[maybe_unused]] double L = 1300;// km

	for (energy=emin;energy<=emax;energy+=(emax-emin)/step)
	{
	  fluxe=glbFlux(0,0,energy,L,1,+1)/4.10414e+12;
	  fluxmu=glbFlux(0,0,energy,L,2,+1)/4.10414e+12;
	  fluxtau=glbFlux(0,0,energy,L,3,+1)/4.10414e+12; 
	  probmumu=glbProfileProbability(0,2,2,+1,energy);
	  probemu=glbProfileProbability(0,1,2,+1,energy);
	  probtaumu=glbProfileProbability(0,3,2,+1,energy);
	  probmue=glbProfileProbability(0,2,1,+1,energy);
	  probee=glbProfileProbability(0,1,1,+1,energy);
	  probtaue=glbProfileProbability(0,3,1,+1,energy);
	  outstdmu<<energy<<"  "<<log10(probmumu*fluxmu+probemu*fluxe+probtaumu*fluxtau)<<endl;
	  outstde<<energy<<"  "<<log10(probmue*fluxmu+probee*fluxe+probtaue*fluxtau)<<endl;
	}


	outstdmu.close();
	outstde.close();
	glbFreeParams(true_values);
 	return 0;

}