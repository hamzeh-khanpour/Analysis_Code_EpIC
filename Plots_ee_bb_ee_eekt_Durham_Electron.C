
//*
//*   ---- Code to drow Plots -----  [ 5 Feb 2023 ]
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



//*   -----------------------------------------------

void Plots_ee_bb_ee_eekt_Durham_Electron(){

    
   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);


   Float_t Mll;
   Float_t Ptll;
   Float_t tvalue;


TH1F * histMll_signal_eebb_LL = new TH1F ("Mll", "", 50, 0.0, 5.0);
TH1F * histMll_signal_eebb_LR = new TH1F ("Mll", "", 50, 0.0, 5.0);


TH1F * histcosll_signal_eebb_LL = new TH1F ("Ptll", "", 50, 0.0, 2.0);
TH1F * histcosll_signal_eebb_LR = new TH1F ("Ptll", "", 50, 0.0, 2.0);


TH1F * histMbb_signal_eebb_LL = new TH1F ("tvalue", "", 50, 0.0, 3.0);
TH1F * histMbb_signal_eebb_LR = new TH1F ("tvalue", "", 50, 0.0, 3.0);



// ============================================

  TFile *file;
  TTree *tree_signal_eebbee_LL;
  TTree *tree_signal_eebbee_LR;


   file = TFile::Open("EIC_Final.root");
 
   tree_signal_eebbee_LL = (TTree*)file->Get("EIC1");
   tree_signal_eebbee_LR = (TTree*)file->Get("EIC2");


   cout << "tree Entries Signal_eebbee_LL == " << tree_signal_eebbee_LL->GetEntries() << endl;
   cout << "tree Entries Signal_eebbee_LR == " << tree_signal_eebbee_LR->GetEntries() << endl;   
   
   tree_signal_eebbee_LL->SetBranchAddress("Mll",&Mll);
   tree_signal_eebbee_LR->SetBranchAddress("Mll",&Mll);


   tree_signal_eebbee_LL->SetBranchAddress("Ptll",&Ptll);
   tree_signal_eebbee_LR->SetBranchAddress("Ptll",&Ptll);

   
   tree_signal_eebbee_LL->SetBranchAddress("tvalue",&tvalue);
   tree_signal_eebbee_LR->SetBranchAddress("tvalue",&tvalue);

  

   
  for (Long64_t ievt=0; ievt<tree_signal_eebbee_LL->GetEntries();ievt++) {
  tree_signal_eebbee_LL->GetEntry(ievt);
  
  histMll_signal_eebb_LL->Fill(Mll);
  histcosll_signal_eebb_LL->Fill(Ptll);
  histMbb_signal_eebb_LL->Fill(tvalue);

    }
    


  for (Long64_t ievt=0; ievt<tree_signal_eebbee_LR->GetEntries();ievt++) {
  tree_signal_eebbee_LR->GetEntry(ievt);
  
  histMll_signal_eebb_LR->Fill(Mll);
  histcosll_signal_eebb_LR->Fill(Ptll);
  histMbb_signal_eebb_LR->Fill(tvalue);

    }

// ------------------- 
 
 
 
 Double_t xl1=0.70, yl1=0.60, xl2=xl1+0.250, yl2=yl1+0.250;

TLegend *leg1 = new TLegend(xl1,yl1,xl2,yl2);
leg1->SetBorderSize(0);

leg1->AddEntry(histMll_signal_eebb_LL,"signal (eebb)","L")->SetTextColor(1);

leg1->SetTextSize(0.05);
leg1->SetTextFont(12);
leg1->SetFillStyle(0);



// ------------------- 
 
 
 
TLegend *leg15 = new TLegend(xl1,yl1,xl2,yl2);
leg15->SetBorderSize(0);

leg15->AddEntry(histMll_signal_eebb_LL,"BH","L")->SetTextColor(1);
leg15->AddEntry(histMll_signal_eebb_LR,"BH+TCS","L")->SetTextColor(2);

leg15->SetTextSize(0.05);
leg15->SetTextFont(12);
leg15->SetFillStyle(0);


// --------------------



TCanvas* c1 = new TCanvas("c1"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histMll_signal_eebb_LL->GetXaxis()->SetTitle("Mll");
histMll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histMll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histMll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histMll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histMll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histMll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histMll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histMll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histMll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);

   histMll_signal_eebb_LL->SetLineWidth(2);
   histMll_signal_eebb_LR->SetLineWidth(2);
 

   histMll_signal_eebb_LL->SetLineColor(1);
   histMll_signal_eebb_LR->SetLineColor(2);


   histMll_signal_eebb_LL->DrawNormalized("hist");
   histMll_signal_eebb_LR->DrawNormalized("hist same");


   leg15->Draw("same");
 
c1->SaveAs("Mll.pdf");
//c1->SaveAs("ptll.C");
//c1->SaveAs("ptll.eps");
//c1->SaveAs("ptll.root");


// --------------------



TCanvas* c2 = new TCanvas("c2"," ",1);

//histcosll_signal_eebb_LL->SetTitle("m_{ll}");
histcosll_signal_eebb_LL->GetXaxis()->SetTitle("Ptll");
histcosll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histcosll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histcosll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histcosll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histcosll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histcosll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histcosll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histcosll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histcosll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);

   histcosll_signal_eebb_LL->SetLineWidth(2);
   histcosll_signal_eebb_LR->SetLineWidth(2);
 

   histcosll_signal_eebb_LL->SetLineColor(1);
   histcosll_signal_eebb_LR->SetLineColor(2);


   histcosll_signal_eebb_LL->DrawNormalized("hist");
   histcosll_signal_eebb_LR->DrawNormalized("hist same");


   leg15->Draw("same");
 
c2->SaveAs("Ptll.pdf");
//c2->SaveAs("ptll.C");
//c2->SaveAs("ptll.eps");
//c2->SaveAs("ptll.root");


// --------------------



TCanvas* c3 = new TCanvas("c3"," ",1);

//histMbb_signal_eebb_LL->SetTitle("m_{ll}");
histMbb_signal_eebb_LL->GetXaxis()->SetTitle("tvalue");
histMbb_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histMbb_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histMbb_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histMbb_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histMbb_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histMbb_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histMbb_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histMbb_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histMbb_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);

   histMbb_signal_eebb_LL->SetLineWidth(2);
   histMbb_signal_eebb_LR->SetLineWidth(2);
 

   histMbb_signal_eebb_LL->SetLineColor(1);
   histMbb_signal_eebb_LR->SetLineColor(2);


   histMbb_signal_eebb_LL->Draw("hist");
   histMbb_signal_eebb_LR->Draw("hist same");

   c3->SetLogy(1);

   leg15->Draw("same");
 
c3->SaveAs("tvalue.pdf");
//c3->SaveAs("ptll.C");
//c3->SaveAs("ptll.eps");
//c3->SaveAs("ptll.root");


}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
