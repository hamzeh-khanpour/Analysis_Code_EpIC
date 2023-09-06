
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





// Function for fit
double fitfunc(double *x, double *p){
	double fitval;
	double a = p[0];		    // acceptance. It would be: double amp = p[1];
	double b = p[1];		    // forward-backward asimmetry coefficient
	fitval = a*x[0] + b;        // from "Tenchini"
	return fitval;
}




   Float_t Mll = 0;
   Float_t Ptll = 0;
   Float_t tvalue = 0;


   Float_t  nentries = 0;
   Float_t  integrated_luminosity = 0;
   Float_t  integrated_cross_section_value_BH = 0;
   Float_t  integrated_cross_section_value_TCS = 0;
   Float_t  integrated_cross_section_value_All = 0;
   
   Float_t  event_weight_BH  = 0;
   Float_t  event_weight_TCS = 0;
   Float_t  event_weight_All = 0;
   
//*   -----------------------------------------------

void Plots_EIC_Ratio_Fit(){

    
    
   Float_t  nentries = 1000000.0;
   Float_t  integrated_luminosity = 300.0 / 1000.0; // fb^{-1} 
   Float_t  integrated_cross_section_value_BH  = 3.05987329334281   * 1000.0;   //   nb   BH
   Float_t  integrated_cross_section_value_TCS = 0.0449484650949493 * 1000.0;   //   nb   TCS   
   Float_t  integrated_cross_section_value_All = 3.32295456492990   * 1000.0;   //   nb   BH+TCS  
   
   Float_t  event_weight_BH  = integrated_cross_section_value_BH  * integrated_luminosity / nentries;
   Float_t  event_weight_TCS = integrated_cross_section_value_TCS * integrated_luminosity / nentries;
   Float_t  event_weight_All = integrated_cross_section_value_All * integrated_luminosity / nentries;
    
    
   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);


TH1F * histMll_BH = new TH1F ("Mll", "", 40, 0.0, 4.0);
TH1F * histMll_TCS = new TH1F ("Mll", "", 40, 0.0, 4.0);
TH1F * histMll_All = new TH1F ("Mll", "", 40, 0.0, 4.0);

TH1F * histPtll_BH = new TH1F ("Ptll", "", 20, 0.0, 0.50);
TH1F * histPtll_TCS = new TH1F ("Ptll", "", 20, 0.0, 0.50);
TH1F * histPtll_All = new TH1F ("Ptll", "", 20, 0.0, 0.50);

TH1F * histtvalue_BH = new TH1F ("tvalue", "",  30, 0.0, 0.2);
TH1F * histtvalue_TCS = new TH1F ("tvalue", "", 30, 0.0, 0.2);
TH1F * histtvalue_All = new TH1F ("tvalue", "", 30, 0.0, 0.2);

// ============================================

  TFile *file;
  TTree *tree_EIC_BH;
  TTree *tree_EIC_TCS;
  TTree *tree_EIC_All;


   file = TFile::Open("EIC_Hamzeh_Final_New_1M_x_L_Qp100.root");

 
   tree_EIC_BH  = (TTree*)file->Get("EIC_BH");
   tree_EIC_TCS = (TTree*)file->Get("EIC_TCS");   
   tree_EIC_All = (TTree*)file->Get("EIC_ALL");


   cout << "tree Entries tree_EIC_BH  == " << tree_EIC_BH->GetEntries() << endl;
   cout << "tree Entries tree_EIC_TCS == " << tree_EIC_TCS->GetEntries() << endl;     
   cout << "tree Entries tree_EIC_All == " << tree_EIC_All->GetEntries() << endl;  
      
   tree_EIC_BH->SetBranchAddress("Mll",&Mll);
   tree_EIC_TCS->SetBranchAddress("Mll",&Mll);
   tree_EIC_All->SetBranchAddress("Mll",&Mll);

   tree_EIC_BH->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_TCS->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_All->SetBranchAddress("Ptll",&Ptll);
   
   tree_EIC_BH->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_TCS->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_All->SetBranchAddress("tvalue",&tvalue);  

   
  for (Long64_t ievt=0; ievt<tree_EIC_BH->GetEntries();ievt++) {
  tree_EIC_BH->GetEntry(ievt);
  
  histMll_BH->Fill(Mll);
  histPtll_BH->Fill(Ptll);
  histtvalue_BH->Fill(tvalue,event_weight_BH);   // ,event_weight_BH ,integrated_cross_section_value_BH
cout << "event_weight_BH =" << event_weight_BH << endl;
    }
    

  for (Long64_t ievt=0; ievt<tree_EIC_TCS->GetEntries();ievt++) {
  tree_EIC_TCS->GetEntry(ievt);
  
  histMll_TCS->Fill(Mll);
  histPtll_TCS->Fill(Ptll);
  histtvalue_TCS->Fill(tvalue,event_weight_TCS);  //  ,integrated_cross_section_value_TCS
cout << "event_weight_TCS =" << event_weight_TCS << endl;
    }


  for (Long64_t ievt=0; ievt<tree_EIC_All->GetEntries();ievt++) {
  tree_EIC_All->GetEntry(ievt);
  
  histMll_All->Fill(Mll);
  histPtll_All->Fill(Ptll);
  histtvalue_All->Fill(tvalue,event_weight_All);  //  ,integrated_cross_section_value_All
cout << "event_weight_All =" << event_weight_All << endl;
    }
  
    
// ------------------- 
 
 
 
Double_t xl1=0.750, yl1=0.720, xl2=xl1+0.150, yl2=yl1+0.150;

TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
leg->SetBorderSize(0);

leg->AddEntry(histMll_BH,"BH","L")->SetTextColor(2);
leg->AddEntry(histMll_TCS,"TCS","L")->SetTextColor(6);
leg->AddEntry(histMll_All,"BH+TCS","L")->SetTextColor(4);

leg->SetTextSize(0.032);
leg->SetTextFont(12);
leg->SetFillStyle(0);

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
                
                
TLatex *t6b = new TLatex(0.65,0.40,"y = ax + b");
                t6b->SetNDC();
                t6b->SetTextFont(12);
                t6b->SetTextSize(0.04);
                t6b->SetTextAlign(20);
                
                
TLatex *t7b = new TLatex(0.60,0.35,"a= 1.31248#pm0.178593,  b= 1.12512#pm0.011509");
                t7b->SetNDC();
                t7b->SetTextFont(12);
                t7b->SetTextSize(0.04);
                t7b->SetTextAlign(20);


// --------------------


TCanvas* c3 = new TCanvas("c3","tvalue", 10, 10, 900, 700);

//histtvalue_BH->SetTitle("m_{ll}");
histtvalue_BH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_BH->GetXaxis()->SetTitleOffset(1.25);
histtvalue_BH->GetXaxis()->SetLabelFont(22);
histtvalue_BH->GetXaxis()->SetTitleFont(22);
histtvalue_BH->GetYaxis()->SetTitle("# Events");  // d#sigma/d|t| [pb]
histtvalue_BH->GetYaxis()->SetTitleOffset(1.40);
histtvalue_BH->GetYaxis()->SetLabelFont(22);
histtvalue_BH->GetYaxis()->SetTitleFont(22);

  histtvalue_BH->GetYaxis()->SetRangeUser(0,8000);
//   histtvalue_BH->GetXaxis()->SetRangeUser(0,1);

   histtvalue_BH->SetLineWidth(3);
   histtvalue_TCS->SetLineWidth(3);
   histtvalue_All->SetLineWidth(3); 

   histtvalue_BH->SetLineColor(2);
   histtvalue_TCS->SetLineColor(6);
   histtvalue_All->SetLineColor(4);

   histtvalue_BH->Draw("hist");
   histtvalue_TCS->Draw("hist same");
   histtvalue_All->Draw("hist same");   

//   c3->SetLogy(1);
//   c3->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
 t6a->Draw("same");  
 t2b->Draw("same");   
 t3b->Draw("same");    
 t4b->Draw("same");    
 t5b->Draw("same");  
 

//c3->SaveAs("t-value.pdf");
//c3->SaveAs("t-value.C");
//c3->SaveAs("t-value.eps");
//c3->SaveAs("t-value.root");



// --------------------



// For Fit
  TF1 *fitval = new TF1("fit", fitfunc, 0.0, 0.2, 2);       // create a TF1 object using the fitfunc function. We need to have 2 parameters for fit


   // Define the ratio plot
   TH1F *Ratio = (TH1F*)histtvalue_All->Clone("Ratio");

TCanvas* c4 = new TCanvas("c4","Ratio", 10, 10, 900, 700);


   // Ratio plot (Ratio) settings
   Ratio->SetTitle(""); // Remove the ratio title
 

   // Y axis ratio plot settings
   Ratio->GetYaxis()->SetTitle("(BH+TCS)/BH");
   Ratio->GetYaxis()->SetNdivisions(505);
   Ratio->GetYaxis()->SetTitleSize(25);
   Ratio->GetYaxis()->SetTitleFont(43);
   Ratio->GetYaxis()->SetTitleOffset(1);
   Ratio->GetYaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   Ratio->GetYaxis()->SetLabelSize(15);
 

   // X axis ratio plot settings
   Ratio->GetXaxis()->SetTitle("|t| [GeV^{2}]");
   Ratio->GetXaxis()->SetTitleSize(25);
   Ratio->GetXaxis()->SetTitleFont(43);
   Ratio->GetXaxis()->SetTitleOffset(1);
   Ratio->GetXaxis()->SetLabelFont(43);  // Absolute font size in pixel (precision 3)
   Ratio->GetXaxis()->SetLabelSize(15); 
 

   Ratio->SetLineColor(kBlack);
   Ratio->SetMinimum(0);            // Define Y ..
   Ratio->SetMaximum(2);            // .. range
   Ratio->Sumw2();
   Ratio->SetStats(0);              // No statistics on lower plot
   Ratio->Divide(histtvalue_BH);
   Ratio->SetMarkerStyle(21);
   Ratio->Draw("ep");              // Draw the ratio plot
 


   // To Do Fit Here
   fitval->SetParameter(0,0.10);
   fitval->SetLineColor(kBlue);
   fitval->SetLineWidth(3);
   fitval->Draw("hist same"); 
   Ratio->Fit("fit");   


   
// leg->Draw("same");
  t2a->Draw("same");
  t3a->Draw("same");
  t4a->Draw("same"); 
//  t5a->Draw("same");
//  t6a->Draw("same");  
//  t2b->Draw("same");   
//  t3b->Draw("same");    
//  t4b->Draw("same");    
  t6b->Draw("same");  
  t7b->Draw("same");  

c4->SaveAs("Ratio_All_to_BH_Fit_Qp100.pdf");
//c4->SaveAs("Ratio_All_to_BH.C");
//c4->SaveAs("Ratio_All_to_BH.eps");
//c4->SaveAs("Ratio_All_to_BH.root");


}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
