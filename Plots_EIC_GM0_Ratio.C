
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
   Float_t  integrated_cross_section_value_BH = 0;
   Float_t  integrated_cross_section_value_BH_GM0 = 0;
   Float_t  integrated_cross_section_value_All = 0;
   Float_t  integrated_cross_section_value_All_GM0 = 0;
   
   Float_t  event_weight_BH  = 0;
   Float_t  event_weight_BH_GM0 = 0;
   Float_t  event_weight_All = 0;
   Float_t  event_weight_All_GM0 = 0;
   
   
//*   -----------------------------------------------

void Plots_EIC_GM0_Ratio(){

    
    
   Float_t  nentries = 1000000.0;
   Float_t  integrated_luminosity = 300.0 / 1000.0; // fb^{-1} 
   Float_t  integrated_cross_section_value_BH      = 3.04779064167665   * 1000.0;   //   nb  BH
   Float_t  integrated_cross_section_value_BH_GM0  = 2.92648225395116   * 1000.0;   //   nb  BH-GM0 
   Float_t  integrated_cross_section_value_All     = 3.30875099292885   * 1000.0;   //   nb  BH+TCS  
   Float_t  integrated_cross_section_value_All_GM0 = 3.18878564045189   * 1000.0;   //   nb  BH+TCS-GM0   
   
   
   Float_t  event_weight_BH  = integrated_cross_section_value_BH  * integrated_luminosity / nentries;
   Float_t  event_weight_BH_GM0 = integrated_cross_section_value_BH_GM0 * integrated_luminosity / nentries;
   Float_t  event_weight_All = integrated_cross_section_value_All * integrated_luminosity / nentries;
   Float_t  event_weight_All_GM0 = integrated_cross_section_value_All_GM0 * integrated_luminosity / nentries;   
    
    
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

TH1F * histtvalue_BH = new TH1F ("tvalue", "",  40, 0.0, 0.2);
TH1F * histtvalue_BH_GM0 = new TH1F ("tvalue", "", 40, 0.0, 0.2);
TH1F * histtvalue_All = new TH1F ("tvalue", "", 40, 0.0, 0.2);
TH1F * histtvalue_All_GM0 = new TH1F ("tvalue", "", 40, 0.0, 0.2);



// ============================================

  TFile *file;
  TTree *tree_EIC_BH;
  TTree *tree_EIC_BH_GM0;
  TTree *tree_EIC_All;
  TTree *tree_EIC_All_GM0;
  

   file = TFile::Open("EIC_Hamzeh_New_1M_x_L_GM0.root");

 
   tree_EIC_BH  = (TTree*)file->Get("EIC_BH");
   tree_EIC_BH_GM0 = (TTree*)file->Get("EIC_BH_GM0");   
   tree_EIC_All = (TTree*)file->Get("EIC_ALL");
   tree_EIC_All_GM0 = (TTree*)file->Get("EIC_ALL_GM0");   


   cout << "tree Entries tree_EIC_BH  == " << tree_EIC_BH->GetEntries() << endl;
   cout << "tree Entries tree_EIC_BH_GM0 == " << tree_EIC_BH_GM0->GetEntries() << endl;     
   cout << "tree Entries tree_EIC_All == " << tree_EIC_All->GetEntries() << endl;  
   cout << "tree Entries tree_EIC_All_GM0 == " << tree_EIC_All_GM0->GetEntries() << endl;  
   
      
   tree_EIC_BH->SetBranchAddress("Mll",&Mll);
   tree_EIC_BH_GM0->SetBranchAddress("Mll",&Mll);
   tree_EIC_All->SetBranchAddress("Mll",&Mll);
   tree_EIC_All_GM0->SetBranchAddress("Mll",&Mll);   

   
   tree_EIC_BH->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_BH_GM0->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_All->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_All_GM0->SetBranchAddress("Ptll",&Ptll);   
   
   
   tree_EIC_BH->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_BH_GM0->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_All->SetBranchAddress("tvalue",&tvalue);  
   tree_EIC_All_GM0->SetBranchAddress("tvalue",&tvalue);     

   
  for (Long64_t ievt=0; ievt<tree_EIC_BH->GetEntries();ievt++) {
  tree_EIC_BH->GetEntry(ievt);
  
  histMll_BH->Fill(Mll);
  histPtll_BH->Fill(Ptll);
  histtvalue_BH->Fill(tvalue);   // ,event_weight_BH ,integrated_cross_section_value_BH
cout << "event_weight_BH =" << event_weight_BH << endl;
    }


  for (Long64_t ievt=0; ievt<tree_EIC_BH_GM0->GetEntries();ievt++) {
  tree_EIC_BH_GM0->GetEntry(ievt);
  
  histMll_BH_GM0->Fill(Mll);
  histPtll_BH_GM0->Fill(Ptll);
  histtvalue_BH_GM0->Fill(tvalue);  //  ,integrated_cross_section_value_TCS
cout << "event_weight_BH_GM0 =" << event_weight_BH_GM0 << endl;
    }


  for (Long64_t ievt=0; ievt<tree_EIC_All->GetEntries();ievt++) {
  tree_EIC_All->GetEntry(ievt);
  
  histMll_All->Fill(Mll);
  histPtll_All->Fill(Ptll);
  histtvalue_All->Fill(tvalue);  //  ,integrated_cross_section_value_All
cout << "event_weight_All =" << event_weight_All << endl;
    }
    
 
  for (Long64_t ievt=0; ievt<tree_EIC_All_GM0->GetEntries();ievt++) {
  tree_EIC_All_GM0->GetEntry(ievt);
  
  histMll_All_GM0->Fill(Mll);
  histPtll_All_GM0->Fill(Ptll);
  histtvalue_All_GM0->Fill(tvalue);  //  ,integrated_cross_section_value_All
cout << "event_weight_All_GM0 =" << event_weight_All_GM0 << endl;
    }
    
    
// ------------------- 
 
Double_t xl1=0.70, yl1=0.720, xl2=xl1+0.150, yl2=yl1+0.150;

TLegend *leg1 = new TLegend(xl1,yl1,xl2,yl2);
leg1->SetBorderSize(0);

leg1->AddEntry(histMll_BH,"BH (G_{E}+G_{M})","L")->SetTextColor(2);
leg1->AddEntry(histMll_BH_GM0,"BH (G_{E})","L")->SetTextColor(4);

leg1->SetTextSize(0.032);
leg1->SetTextFont(12);
leg1->SetFillStyle(0);


// ------------------- 

Double_t xl3=0.65, yl3=0.720, xl4=xl3+0.150, yl4=yl3+0.150;

TLegend *leg2 = new TLegend(xl3,yl3,xl4,yl4);
leg2->SetBorderSize(0);

leg2->AddEntry(histPtll_All,"BH+TCS (G_{E}+G_{M})","L")->SetTextColor(2);
leg2->AddEntry(histPtll_All_GM0,"BH+TCS (G_{E})","L")->SetTextColor(4);

leg2->SetTextSize(0.032);
leg2->SetTextFont(12);
leg2->SetFillStyle(0);







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


TCanvas* c4 = new TCanvas("c4","tvalue", 10, 10, 900, 700);

//histtvalue_BH->SetTitle("m_{ll}");
histtvalue_BH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_BH->GetXaxis()->SetTitleOffset(1.25);
histtvalue_BH->GetXaxis()->SetLabelFont(22);
histtvalue_BH->GetXaxis()->SetTitleFont(22);
histtvalue_BH->GetYaxis()->SetTitle("# Events");  // d#sigma/d|t| [pb]
histtvalue_BH->GetYaxis()->SetTitleOffset(1.40);
histtvalue_BH->GetYaxis()->SetLabelFont(22);
histtvalue_BH->GetYaxis()->SetTitleFont(22);

  histtvalue_BH->GetYaxis()->SetRangeUser(100,10000);
//   histtvalue_BH->GetXaxis()->SetRangeUser(0,1);

   histtvalue_BH->SetLineWidth(3);
   histtvalue_BH_GM0->SetLineWidth(3);

   histtvalue_BH->SetLineColor(2);
   histtvalue_BH_GM0->SetLineColor(4);

   histtvalue_BH->Draw("hist");
   histtvalue_BH_GM0->Draw("hist same");

     c4->SetLogy(1);
//   c4->SetLogx(1);

 leg1->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
 t6a->Draw("same");  
 t2b->Draw("same");   
 t3b->Draw("same");    
 t4b->Draw("same");    
 t5b->Draw("same");  
 

c4->SaveAs("t-value-nonorm_BH_GM0.pdf");
//c4->SaveAs("t-value-nonorm_BH_GM0.C");
//c4->SaveAs("t-value-nonorm_BH_GM0.eps");
//c4->SaveAs("t-value-nonorm_BH_GM0.root");


// --------------------



TCanvas* c6 = new TCanvas("c6","tvalue", 10, 10, 900, 700);

//histtvalue_All->SetTitle("m_{ll}");
histtvalue_All->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_All->GetXaxis()->SetTitleOffset(1.25);
histtvalue_All->GetXaxis()->SetLabelFont(22);
histtvalue_All->GetXaxis()->SetTitleFont(22);
histtvalue_All->GetYaxis()->SetTitle("# Events");  // d#sigma/d|t| [pb]
histtvalue_All->GetYaxis()->SetTitleOffset(1.40);
histtvalue_All->GetYaxis()->SetLabelFont(22);
histtvalue_All->GetYaxis()->SetTitleFont(22);

  histtvalue_All->GetYaxis()->SetRangeUser(100,10000);
//   histtvalue_All->GetXaxis()->SetRangeUser(0,1);

   histtvalue_All->SetLineWidth(3);
   histtvalue_All_GM0->SetLineWidth(3);

   histtvalue_All->SetLineColor(2);
   histtvalue_All_GM0->SetLineColor(4);

   histtvalue_All->Draw("hist");
   histtvalue_All_GM0->Draw("hist same");

     c6->SetLogy(1);
//   c6->SetLogx(1);

 leg2->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
 t6a->Draw("same");  
 t2b->Draw("same");   
 t3b->Draw("same");    
 t4b->Draw("same");    
 t5b->Draw("same");  
 

c6->SaveAs("t-value-nonorm_All_GM0.pdf");
//c6->SaveAs("t-value-nonorm_All_GM0.C");
//c6->SaveAs("t-value-nonorm_All_GM0.eps");
//c6->SaveAs("t-value-nonorm_All_GM0.root");



// --------------------


   // Define the ratio plot
   TH1F *RatioAll = (TH1F*)histtvalue_All_GM0->Clone("RatioAll");

TCanvas* c7 = new TCanvas("c7","RatioAll", 10, 10, 900, 700);


   // Ratio plot (Ratio) settings
   RatioAll->SetTitle(""); // Remove the ratio title
 

   // Y axis ratio plot settings
   RatioAll->GetYaxis()->SetTitle("BH+TCS: (GE)/(GE+GM)");
   RatioAll->GetYaxis()->SetNdivisions(505);
   RatioAll->GetYaxis()->SetTitleSize(25);
   RatioAll->GetYaxis()->SetTitleFont(43);
   RatioAll->GetYaxis()->SetTitleOffset(1);
   RatioAll->GetYaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioAll->GetYaxis()->SetLabelSize(15);
 

   // X axis ratio plot settings
   RatioAll->GetXaxis()->SetTitle("|t| [GeV^{2}]");
   RatioAll->GetXaxis()->SetTitleSize(25);
   RatioAll->GetXaxis()->SetTitleFont(43);
   RatioAll->GetXaxis()->SetTitleOffset(1);
   RatioAll->GetXaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioAll->GetXaxis()->SetLabelSize(15); 
 

   RatioAll->SetLineColor(kBlack);
   RatioAll->SetMinimum(0);            // Define Y ..
   RatioAll->SetMaximum(2);            // .. range
   RatioAll->Sumw2();
   RatioAll->SetStats(0);              // No statistics on lower plot
   RatioAll->Divide(histtvalue_All);
   RatioAll->SetMarkerStyle(21);
   RatioAll->Draw("EX0");              // Draw the ratio plot
 

// leg->Draw("same");
  t2a->Draw("same");
  t3a->Draw("same");
  t4a->Draw("same"); 


c7->SaveAs("Ratio_GE_to_GE-GM_GM0.pdf");
//c7->SaveAs("Ratio_GE_to_GE-GM_GM0.C");
//c7->SaveAs("Ratio_GE_to_GE-GM_GM0.eps");
//c7->SaveAs("Ratio_GE_to_GE-GM_GM0.root");


// --------------------


   // Define the ratio plot
   TH1F *RatioBH = (TH1F*)histtvalue_BH_GM0->Clone("RatioBH");

TCanvas* c8 = new TCanvas("c8","RatioBH", 10, 10, 900, 700);


   // Ratio plot (Ratio) settings
   RatioBH->SetTitle(""); // Remove the ratio title
 

   // Y axis ratio plot settings
   RatioBH->GetYaxis()->SetTitle("BH: (GE)/(GE+GM)");
   RatioBH->GetYaxis()->SetNdivisions(505);
   RatioBH->GetYaxis()->SetTitleSize(25);
   RatioBH->GetYaxis()->SetTitleFont(43);
   RatioBH->GetYaxis()->SetTitleOffset(1);
   RatioBH->GetYaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioBH->GetYaxis()->SetLabelSize(15);
 

   // X axis ratio plot settings
   RatioBH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
   RatioBH->GetXaxis()->SetTitleSize(25);
   RatioBH->GetXaxis()->SetTitleFont(43);
   RatioBH->GetXaxis()->SetTitleOffset(1);
   RatioBH->GetXaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioBH->GetXaxis()->SetLabelSize(15); 
 

   RatioBH->SetLineColor(kBlack);
   RatioBH->SetMinimum(0);            // Define Y ..
   RatioBH->SetMaximum(2);            // .. range
   RatioBH->Sumw2();
   RatioBH->SetStats(0);              // No statistics on lower plot
   RatioBH->Divide(histtvalue_BH);
   RatioBH->SetMarkerStyle(21);
   RatioBH->Draw("EX0");              // Draw the ratio plot
   //RatioAll->Draw("EX0 same");    

// leg->Draw("same");
  t2a->Draw("same");
  t3a->Draw("same");
  t4a->Draw("same"); 


c8->SaveAs("Ratio_GE_to_GE-GM_BH_GM0.pdf");
//c8->SaveAs("Ratio_GE_to_GE-GM_GM0.C");
//c8->SaveAs("Ratio_GE_to_GE-GM_GM0.eps");
//c8->SaveAs("Ratio_GE_to_GE-GM_GM0.root");



// --------------------

// ------------------- 

Double_t xl5=0.65, yl5=0.720, xl6=xl5+0.150, yl6=yl5+0.150;

TLegend *leg3 = new TLegend(xl5,yl5,xl6,yl6);
leg3->SetBorderSize(0);

leg3->AddEntry(RatioBH,"Pol+","L")->SetTextColor(2);
leg3->AddEntry(RatioAll,"Pol-","L")->SetTextColor(4);

leg3->SetTextSize(0.032);
leg3->SetTextFont(12);
leg3->SetFillStyle(0);

TCanvas* c9 = new TCanvas("c9","RatioBH", 10, 10, 900, 700);


   // Ratio plot (Ratio) settings
   RatioBH->SetTitle(""); // Remove the ratio title
 

   // Y axis ratio plot settings
   RatioBH->GetYaxis()->SetTitle("GE/(GE+GM)");
   RatioBH->GetYaxis()->SetNdivisions(505);
   RatioBH->GetYaxis()->SetTitleSize(25);
   RatioBH->GetYaxis()->SetTitleFont(43);
   RatioBH->GetYaxis()->SetTitleOffset(1);
   RatioBH->GetYaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioBH->GetYaxis()->SetLabelSize(15);
 

   // X axis ratio plot settings
   RatioBH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
   RatioBH->GetXaxis()->SetTitleSize(25);
   RatioBH->GetXaxis()->SetTitleFont(43);
   RatioBH->GetXaxis()->SetTitleOffset(1);
   RatioBH->GetXaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   RatioBH->GetXaxis()->SetLabelSize(15); 
 

   RatioBH->SetLineColor(kBlack);
   RatioAll->SetLineColor(kBlue);
   RatioBH->SetMinimum(0);            // Define Y ..
   RatioBH->SetMaximum(2);            // .. range
   RatioBH->Sumw2();
   RatioBH->SetStats(0);              // No statistics on lower plot
   RatioBH->SetMarkerStyle(21);
   RatioAll->SetMarkerStyle(24);
   RatioBH->Draw("hist");              // Draw the ratio plot
   RatioAll->Draw("hist same");    

  leg3->Draw("same");
  t2a->Draw("same");
  t3a->Draw("same");
  t4a->Draw("same"); 


c9->SaveAs("Ratio_diff_pol.pdf");
//c9->SaveAs("Ratio_GE_to_GE-GM_GM0.C");
//c9->SaveAs("Ratio_GE_to_GE-GM_GM0.eps");
//c9->SaveAs("Ratio_GE_to_GE-GM_GM0.root");




}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
