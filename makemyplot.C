void makemyplot(){
     TCanvas *c1 = new TCanvas("c1","Fluxos",200,10,700,500);
     auto pad = new TPad();
     c1->SetLogy();
     fstream file;
     file.open("flux.txt",ios::in);
     auto gre = new TGraph();
     auto grmu = new TGraph();
     auto grtau = new TGraph();
     double en,nue,numu,nutau,antinue,antinumu,antinutau;
     int k = 0;
     while(!file.eof())
     {
         file >> en >> nue >> numu >> nutau >> antinue >> antinumu >> antinutau;
         gre->SetPoint(k,en,nue);
         grmu->SetPoint(k,en,numu);
         grtau->SetPoint(k,en,nutau);
         k++;
     }
     file.close();
     
     gre->SetMarkerColor(kBlue);
     gre->SetMarkerStyle(kFullCircle);

     grmu->SetMarkerColor(kRed);
     grmu->SetMarkerStyle(kFullCircle);

     grtau->SetMarkerColor(kGreen);
     grtau->SetMarkerStyle(kFullCircle);
     
     auto g = new TMultiGraph();
     g->Add(gre);
     g->Add(grmu);
     g->Add(grtau);
     g->GetXaxis()->SetRangeUser(0.25,10.0);
     g->GetYaxis()->SetRangeUser(1.e-14,1.e-10);
     g->Draw("AP");
     
}
