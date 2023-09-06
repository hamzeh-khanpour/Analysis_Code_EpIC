
//*
//*   ---- Code to drow Plots -----  [ 15 August 2023 ]
//*

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "TString.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TTree.h"
#include <TLegend.h>
#include "TCanvas.h"



   Float_t Mll = 0;
   Float_t Ptll = 0;
   Float_t tvalue = 0;


   Float_t  nentries = 0;
   Float_t  integrated_luminosity = 0;
   Float_t  integrated_cross_section_value_EIC_All_Polm = 0;
   Float_t  integrated_cross_section_value_EIC_All_GM0_Polm = 0;
   Float_t  integrated_cross_section_value_EIC_All_Polp = 0;
   Float_t  integrated_cross_section_value_EIC_All_GM0_Polp = 0;
   
   Float_t  event_weight_All_Polm  = 0;
   Float_t  event_weight_All_GM0_Polm = 0;
   Float_t  event_weight_All_Polp = 0;
   Float_t  event_weight_All_GM0_Polp = 0;
   
   
//*   -----------------------------------------------

void Plots_EIC_GM0_Ratio_Pol(){

    
    
   Float_t  nentries = 1000000.0;
   Float_t  integrated_luminosity = 300.0 / 1000.0; // fb^{-1} 
   Float_t  integrated_cross_section_value_EIC_All_Polm     = 3.32295456492990   * 1000.0;   //   nb  EIC_All_Polm
   Float_t  integrated_cross_section_value_EIC_All_GM0_Polm = 3.20711317192575   * 1000.0;   //   nb  EIC_All_GM0_Polm 
   Float_t  integrated_cross_section_value_EIC_All_Polp     = 3.32295456492990   * 1000.0;   //   nb  EIC_All_Polp  
   Float_t  integrated_cross_section_value_EIC_All_GM0_Polp = 3.20033492867845   * 1000.0;   //   nb  EIC_All_GM0_Polp   
   
   
   Float_t  event_weight_All_Polm  = integrated_cross_section_value_EIC_All_Polm  * integrated_luminosity / nentries;
   Float_t  event_weight_All_GM0_Polm = integrated_cross_section_value_EIC_All_GM0_Polm * integrated_luminosity / nentries;
   Float_t  event_weight_All_Polp = integrated_cross_section_value_EIC_All_Polp * integrated_luminosity / nentries;
   Float_t  event_weight_All_GM0_Polp = integrated_cross_section_value_EIC_All_GM0_Polp * integrated_luminosity / nentries;   
    
    
   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);


TH1F * histMll_BH = new TH1F ("Mll", "", 40, 0.0, 4.0);
TH1F * histMll_BH_GM0 = new TH1F ("Mll", "", 40, 0.0, 4.0);
TH1F * histMll_All = new TH1F ("Mll", "", 40, 0.0, 4.0);
TH1F * histMll_All_GM0 = new TH1F ("Mll", "", 40, 0.0, 4.0);

TH1F * histPtll_BH = new TH1F ("Ptll", "", 20, 0.0, 0.50);
TH1F * histPtll_BH_GM0 = new TH1F ("Ptll", "", 20, 0.0, 0.50);
TH1F * histPtll_All = new TH1F ("Ptll", "", 20, 0.0, 0.50);
TH1F * histPtll_All_GM0 = new TH1F ("Ptll", "", 20, 0.0, 0.50);

TH1F * histtvalue_All_Polm = new TH1F ("tvalue", "",  40, 0.0, 0.2);
TH1F * histtvalue_All_GM0_Polm = new TH1F ("tvalue", "", 40, 0.0, 0.2);
TH1F * histtvalue_All_Polp = new TH1F ("tvalue", "", 40, 0.0, 0.2);
TH1F * histtvalue_All_GM0_Polp = new TH1F ("tvalue", "", 40, 0.0, 0.2);



// ============================================

  TFile *file;
  TTree *tree_EIC_All_Polm;
  TTree *tree_EIC_All_GM0_Polm;
  TTree *tree_EIC_All_Polp;
  TTree *tree_EIC_All_GM0_Polp;
  

   file = TFile::Open("EIC_Polm_Polp.root");

 
   tree_EIC_All_Polm  = (TTree*)file->Get("EIC_All_Polm");
   tree_EIC_All_GM0_Polm = (TTree*)file->Get("EIC_All_GM0_Polm");   
   tree_EIC_All_Polp = (TTree*)file->Get("EIC_All_Polp");
   tree_EIC_All_GM0_Polp = (TTree*)file->Get("EIC_All_GM0_Polp");   


   cout << "tree Entries tree_EIC_All_Polm  == " << tree_EIC_All_Polm->GetEntries() << endl;
   cout << "tree Entries tree_EIC_All_GM0_Polm == " << tree_EIC_All_GM0_Polm->GetEntries() << endl;     
   cout << "tree Entries tree_EIC_All_Polp == " << tree_EIC_All_Polp->GetEntries() << endl;  
   cout << "tree Entries tree_EIC_All_GM0_Polp == " << tree_EIC_All_GM0_Polp->GetEntries() << endl;  
   
      
   tree_EIC_All_Polm->SetBranchAddress("Mll",&Mll);
   tree_EIC_All_GM0_Polm->SetBranchAddress("Mll",&Mll);
   tree_EIC_All_Polp->SetBranchAddress("Mll",&Mll);
   tree_EIC_All_GM0_Polp->SetBranchAddress("Mll",&Mll);   

   
   tree_EIC_All_Polm->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_All_GM0_Polm->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_All_Polp->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_All_GM0_Polp->SetBranchAddress("Ptll",&Ptll);   
   
   
   tree_EIC_All_Polm->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_All_GM0_Polm->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_All_Polp->SetBranchAddress("tvalue",&tvalue);  
   tree_EIC_All_GM0_Polp->SetBranchAddress("tvalue",&tvalue);     

   
  for (Long64_t ievt=0; ievt<tree_EIC_All_Polm->GetEntries();ievt++) {
  tree_EIC_All_Polm->GetEntry(ievt);
  
  histMll_BH->Fill(Mll);
  histPtll_BH->Fill(Ptll);
  histtvalue_All_Polm->Fill(tvalue,event_weight_All_Polm);   // ,event_weight_All_Polm ,integrated_cross_section_value_BH
cout << "event_weight_All_Polm =" << event_weight_All_Polm << endl;
    }


  for (Long64_t ievt=0; ievt<tree_EIC_All_GM0_Polm->GetEntries();ievt++) {
  tree_EIC_All_GM0_Polm->GetEntry(ievt);
  
  histMll_BH_GM0->Fill(Mll);
  histPtll_BH_GM0->Fill(Ptll);
  histtvalue_All_GM0_Polm->Fill(tvalue,event_weight_All_GM0_Polm);  //event_weight_All_GM0_Polm  ,integrated_cross_section_value_TCS
cout << "event_weight_All_GM0_Polm =" << event_weight_All_GM0_Polm << endl;
    }


  for (Long64_t ievt=0; ievt<tree_EIC_All_Polp->GetEntries();ievt++) {
  tree_EIC_All_Polp->GetEntry(ievt);
  
  histMll_All->Fill(Mll);
  histPtll_All->Fill(Ptll);
  histtvalue_All_Polp->Fill(tvalue,event_weight_All_Polp);  //event_weight_All_Polp  ,integrated_cross_section_value_All
cout << "event_weight_All_Polp =" << event_weight_All_Polp << endl;
    }
    
 
  for (Long64_t ievt=0; ievt<tree_EIC_All_GM0_Polp->GetEntries();ievt++) {
  tree_EIC_All_GM0_Polp->GetEntry(ievt);
  
  histMll_All_GM0->Fill(Mll);
  histPtll_All_GM0->Fill(Ptll);
  histtvalue_All_GM0_Polp->Fill(tvalue,event_weight_All_GM0_Polp);  //event_weight_All_GM0_Polp  ,integrated_cross_section_value_All
cout << "event_weight_All_GM0_Polp =" << event_weight_All_GM0_Polp << endl;
    }
    
    
// ------------------- 

//    (#sqrt{s} = 365 GeV, L_{int} = 1.5 ab^{-1})    1.5 ab^{-1} (365 GeV)

TLatex *t2a = new TLatex(0.5,0.9,"#bf{Electron-Ion Collider (EIC)}");
                t2a->SetNDC();
                t2a->SetTextFont(42);
                t2a->SetTextSize(0.04);
                t2a->SetTextAlign(20);

                
TLatex *t3a = new TLatex(0.27,0.85,"E_{e} = 18 GeV");
                t3a->SetNDC();
                t3a->SetTextFont(42);
                t3a->SetTextSize(0.04);
                t3a->SetTextAlign(20);
                
            
TLatex *t4a = new TLatex(0.276,0.80,"E_{p} = 275 GeV");
                t4a->SetNDC();
                t4a->SetTextFont(42);
                t4a->SetTextSize(0.04);
                t4a->SetTextAlign(20);


TLatex *t5a = new TLatex(0.666,0.66,"lepton_polarisation = -1");
                t5a->SetNDC();
                t5a->SetTextFont(12);
                t5a->SetTextSize(0.04);
                t5a->SetTextAlign(20);
                
TLatex *t6a = new TLatex(0.692,0.61,"hadron_polarisation = 0|0|1");
                t6a->SetNDC();
                t6a->SetTextFont(12);
                t6a->SetTextSize(0.04);
                t6a->SetTextAlign(20);
                
TLatex *t2b = new TLatex(0.70,0.550,"0.5<E'_{e}/E_{e}<0.99 & #pi-#theta_{e}<10 mrad");
                t2b->SetNDC();
                t2b->SetTextFont(12);
                t2b->SetTextSize(0.04);
                t2b->SetTextAlign(20);

                
TLatex *t3b = new TLatex(0.64,0.50,"x_{L}<0.97 || p_{T}^{p}>100 Mev");
                t3b->SetNDC();
                t3b->SetTextFont(12);
                t3b->SetTextSize(0.04);
                t3b->SetTextAlign(20);
                
                
TLatex *t4b = new TLatex(0.58,0.45,"#theta_{p}<13 mrad");
                t4b->SetNDC();
                t4b->SetTextFont(12);
                t4b->SetTextSize(0.04);
                t4b->SetTextAlign(20);
                
                
TLatex *t5b = new TLatex(0.65,0.39,"p_{T}^{#mu}>300 MeV & |#eta_{#mu}|<3.5");
                t5b->SetNDC();
                t5b->SetTextFont(12);
                t5b->SetTextSize(0.04);
                t5b->SetTextAlign(20);

    
// --------------------


   // Define the ratio plot
   TH1F *RatioPolp = (TH1F*)histtvalue_All_GM0_Polp->Clone("RatioPolp");

   
 

Double_t xl1=0.65, yl1=0.720, xl2=xl1+0.150, yl2=yl1+0.150;

TLegend *leg1 = new TLegend(xl1,yl1,xl2,yl2);
leg1->SetBorderSize(0);

leg1->AddEntry(RatioPolp,"BH+TCS (Pol+)","L")->SetTextColor(4);

leg1->SetTextSize(0.032);
leg1->SetTextFont(12);
leg1->SetFillStyle(0);


TCanvas* c7 = new TCanvas("c7","RatioPolp", 10, 10, 900, 700);


   // Ratio plot (Ratio) settings
   RatioPolp->SetTitle(""); // Remove the ratio title
 

   // Y axis ratio plot settings
   RatioPolp->GetYaxis()->SetTitle("(GE)/(GE+GM)");
   RatioPolp->GetYaxis()->SetNdivisions(505);
   RatioPolp->GetYaxis()->SetTitleSize(25);
   RatioPolp->GetYaxis()->SetTitleFont(43);
   RatioPolp->GetYaxis()->SetTitleOffset(1);
   RatioPolp->GetYaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioPolp->GetYaxis()->SetLabelSize(15);
 

   // X axis ratio plot settings
   RatioPolp->GetXaxis()->SetTitle("|t| [GeV^{2}]");
   RatioPolp->GetXaxis()->SetTitleSize(25);
   RatioPolp->GetXaxis()->SetTitleFont(43);
   RatioPolp->GetXaxis()->SetTitleOffset(1);
   RatioPolp->GetXaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioPolp->GetXaxis()->SetLabelSize(15); 
 

   RatioPolp->SetLineColor(4);
   RatioPolp->SetMinimum(0);            // Define Y ..
   RatioPolp->SetMaximum(2);            // .. range
   RatioPolp->Sumw2();
   RatioPolp->SetStats(0);              // No statistics on lower plot
   RatioPolp->Divide(histtvalue_All_Polp);
   RatioPolp->SetMarkerStyle(21);
   RatioPolp->Draw("EX0");              // Draw the ratio plot
 

  leg1->Draw("same");
  t2a->Draw("same");
  t3a->Draw("same");
  t4a->Draw("same"); 


c7->SaveAs("Ratio_GE_to_GE-GM_GM0_Qp100.pdf");
//c7->SaveAs("Ratio_GE_to_GE-GM_GM0.C");
//c7->SaveAs("Ratio_GE_to_GE-GM_GM0.eps");
//c7->SaveAs("Ratio_GE_to_GE-GM_GM0.root");


// --------------------


   // Define the ratio plot
   TH1F *RatioPolm = (TH1F*)histtvalue_All_GM0_Polm->Clone("RatioPolm");

   
 

Double_t xl3=0.65, yl3=0.720, xl4=xl3+0.150, yl4=yl3+0.150;

TLegend *leg2 = new TLegend(xl3,yl3,xl4,yl4);
leg2->SetBorderSize(0);

leg2->AddEntry(RatioPolm,"BH+TCS (Pol-)","L")->SetTextColor(2);

leg2->SetTextSize(0.032);
leg2->SetTextFont(12);
leg2->SetFillStyle(0);
   
   
   
TCanvas* c8 = new TCanvas("c8","RatioPolm", 10, 10, 900, 700);


   // Ratio plot (Ratio) settings
   RatioPolm->SetTitle(""); // Remove the ratio title
 

   // Y axis ratio plot settings
   RatioPolm->GetYaxis()->SetTitle("BH+TCS: GE/(GE+GM)");
   RatioPolm->GetYaxis()->SetNdivisions(505);
   RatioPolm->GetYaxis()->SetTitleSize(25);
   RatioPolm->GetYaxis()->SetTitleFont(43);
   RatioPolm->GetYaxis()->SetTitleOffset(1);
   RatioPolm->GetYaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioPolm->GetYaxis()->SetLabelSize(15);
 

   // X axis ratio plot settings
   RatioPolm->GetXaxis()->SetTitle("|t| [GeV^{2}]");
   RatioPolm->GetXaxis()->SetTitleSize(25);
   RatioPolm->GetXaxis()->SetTitleFont(43);
   RatioPolm->GetXaxis()->SetTitleOffset(1);
   RatioPolm->GetXaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioPolm->GetXaxis()->SetLabelSize(15); 
 

   RatioPolm->SetLineColor(2);
   RatioPolm->SetMinimum(0);            // Define Y ..
   RatioPolm->SetMaximum(2);            // .. range
   RatioPolm->Sumw2();
   RatioPolm->SetStats(0);              // No statistics on lower plot
   RatioPolm->Divide(histtvalue_All_Polm);
   RatioPolm->SetMarkerStyle(21);
   RatioPolm->Draw("EX0");              // Draw the ratio plot
   //RatioPolp->Draw("EX0 same");    

  leg2->Draw("same");
  t2a->Draw("same");
  t3a->Draw("same");
  t4a->Draw("same"); 


c8->SaveAs("Ratio_GE_to_GE-GM_BH_GM0_Qp100.pdf");
//c8->SaveAs("Ratio_GE_to_GE-GM_GM0.C");
//c8->SaveAs("Ratio_GE_to_GE-GM_GM0.eps");
//c8->SaveAs("Ratio_GE_to_GE-GM_GM0.root");



// --------------------


// ------------------- 

Double_t xl5=0.65, yl5=0.720, xl6=xl5+0.150, yl6=yl5+0.150;

TLegend *leg3 = new TLegend(xl5,yl5,xl6,yl6);
leg3->SetBorderSize(0);

leg3->AddEntry(RatioPolp,"BH+TCS (Pol+)","L")->SetTextColor(4);
leg3->AddEntry(RatioPolm,"BH+TCS (Pol-)","L")->SetTextColor(2);

leg3->SetTextSize(0.032);
leg3->SetTextFont(12);
leg3->SetFillStyle(0);


TCanvas* c9 = new TCanvas("c9","RatioPolmPolp", 10, 10, 900, 700);


   // Ratio plot (Ratio) settings
   RatioPolm->SetTitle(""); // Remove the ratio title
 

   // Y axis ratio plot settings
   RatioPolm->GetYaxis()->SetTitle("GE/(GE+GM)");
   RatioPolm->GetYaxis()->SetNdivisions(505);
   RatioPolm->GetYaxis()->SetTitleSize(25);
   RatioPolm->GetYaxis()->SetTitleFont(43);
   RatioPolm->GetYaxis()->SetTitleOffset(1);
   RatioPolm->GetYaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioPolm->GetYaxis()->SetLabelSize(15);
 

   // X axis ratio plot settings
   RatioPolm->GetXaxis()->SetTitle("|t| [GeV^{2}]");
   RatioPolm->GetXaxis()->SetTitleSize(25);
   RatioPolm->GetXaxis()->SetTitleFont(43);
   RatioPolm->GetXaxis()->SetTitleOffset(1);
   RatioPolm->GetXaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioPolm->GetXaxis()->SetLabelSize(15); 
 

   RatioPolm->SetLineColor(2);
   RatioPolp->SetLineColor(4);
   RatioPolm->SetLineWidth(3);
   RatioPolp->SetLineWidth(3);   
   RatioPolm->SetMinimum(0);            // Define Y ..
   RatioPolm->SetMaximum(2);            // .. range
   RatioPolm->Sumw2();
   RatioPolm->SetStats(0);              // No statistics on lower plot
   RatioPolm->SetMarkerStyle(21);
   RatioPolp->SetMarkerStyle(24);
   RatioPolm->Draw("hist");              // Draw the ratio plot
   RatioPolp->Draw("hist same");    

  leg3->Draw("same");
  t2a->Draw("same");
  t3a->Draw("same");
  t4a->Draw("same"); 


c9->SaveAs("Ratio_diff_polm_polp_Qp100.pdf");
//c9->SaveAs("Ratio_GE_to_GE-GM_GM0.C");
//c9->SaveAs("Ratio_GE_to_GE-GM_GM0.eps");
//c9->SaveAs("Ratio_GE_to_GE-GM_GM0.root");



TCanvas* c10 = new TCanvas("c10","RatioPolmPolp", 10, 10, 900, 700);


   // Ratio plot (Ratio) settings
   RatioPolm->SetTitle(""); // Remove the ratio title
 

   // Y axis ratio plot settings
   RatioPolm->GetYaxis()->SetTitle("GE/(GE+GM)");
   RatioPolm->GetYaxis()->SetNdivisions(505);
   RatioPolm->GetYaxis()->SetTitleSize(25);
   RatioPolm->GetYaxis()->SetTitleFont(43);
   RatioPolm->GetYaxis()->SetTitleOffset(1);
   RatioPolm->GetYaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioPolm->GetYaxis()->SetLabelSize(15);
 

   // X axis ratio plot settings
   RatioPolm->GetXaxis()->SetTitle("|t| [GeV^{2}]");
   RatioPolm->GetXaxis()->SetTitleSize(25);
   RatioPolm->GetXaxis()->SetTitleFont(43);
   RatioPolm->GetXaxis()->SetTitleOffset(1);
   RatioPolm->GetXaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioPolm->GetXaxis()->SetLabelSize(15); 
 

   RatioPolm->SetLineColor(2);
   RatioPolp->SetLineColor(4);
   RatioPolm->SetLineWidth(3);
   RatioPolp->SetLineWidth(3);   
   RatioPolm->SetMinimum(0);            // Define Y ..
   RatioPolm->SetMaximum(2);            // .. range
   RatioPolm->Sumw2();
   RatioPolm->SetStats(0);              // No statistics on lower plot
   RatioPolm->SetMarkerStyle(21);
   RatioPolp->SetMarkerStyle(24);
   RatioPolm->Draw("EX0");              // Draw the ratio plot
   RatioPolp->Draw("EX0 same");    

  leg3->Draw("same");
  t2a->Draw("same"); 
  t3a->Draw("same");
  t4a->Draw("same"); 


c10->SaveAs("Ratio_diff_polm_polp_EX0_Qp100.pdf");
//c10->SaveAs("Ratio_GE_to_GE-GM_GM0.C");
//c10->SaveAs("Ratio_GE_to_GE-GM_GM0.eps");
//c10->SaveAs("Ratio_GE_to_GE-GM_GM0.root");




}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
