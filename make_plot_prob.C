#include "TH1.h"
#include "TH2.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TStyle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

void make_plot_prob(){

    auto gre  = new TGraph("probability_matter_DUNE_e.dat");
    auto grmu  = new TGraph("probability_matter_DUNE_mu.dat");
    auto grtau  = new TGraph("probability_matter_DUNE_tau.dat");

    gre->GetXaxis()->SetRangeUser(0.25,10.0);
    gre->GetYaxis()->SetRangeUser(0,1);

    gre->SetTitle("Neutrino probabilities in matter;E (GeV);Probability");
    gre->GetXaxis()->CenterTitle();
    gre->GetYaxis()->CenterTitle();
    gre->GetYaxis()->SetNdivisions(505);

    gre->SetLineStyle(7);
    gre->SetLineStyle(7);
    
    gre->SetLineColor(kGreen);
    gre->SetLineWidth(2);
    grmu->SetLineColor(kBlue);
    grmu->SetLineWidth(2);
    grtau->SetLineColor(kRed);
    grtau->SetLineWidth(2);

    gre->Draw();
    grmu->Draw("SAME");
    grtau->Draw("SAME");
}
