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

void make_plot(){

//    auto gr  = new TGraph("probability_DUNE.dat");
//    auto grBSM  = new TGraph("BSMprobability_cmueDUNE.dat");
//    auto grBSMn  = new TGraph("BSMprobability_cmueDUNEn.dat");

    auto gr  = new TGraph("probability_DUNE_mu.dat");
    auto grBSM  = new TGraph("BSMprobabilitycmumu1e-22DUNEmu.dat");
    auto gre  = new TGraph("probability_DUNE_e.dat");
    auto grBSMe  = new TGraph("BSMprobabilitycmumu1e-22DUNEe.dat");
    //auto grBSMn  = new TGraph("BSMprobabilitycmumu1e-22DUNE.dat");

    gr->GetXaxis()->SetRangeUser(0.25,10.0);
    gr->GetYaxis()->SetRangeUser(-4,3);
    //gr->GetYaxis()->SetRangeUser(0,0.2);
    gr->SetTitle("Neutrino spectra at DUNE FD;E (GeV);Flux");
    gr->GetXaxis()->CenterTitle();
    gr->GetYaxis()->CenterTitle();
    gr->GetYaxis()->SetNdivisions(505);

    gr->SetLineStyle(7);
    gre->SetLineStyle(7);
    
    gr->SetLineColor(kBlue);
    gr->SetLineWidth(2);
    grBSM->SetLineColor(kBlue);
    grBSM->SetLineWidth(2);
    gre->SetLineColor(kRed);
    gre->SetLineWidth(2);
    grBSMe->SetLineColor(kRed);
    grBSMe->SetLineWidth(2);
    //grBSMn->SetLineColor(kRed);

    gr->Draw();
    grBSM->Draw("SAME");
    gre->Draw("SAME");
    grBSMe->Draw("SAME");
    //grBSMn->Draw("SAME");
}
