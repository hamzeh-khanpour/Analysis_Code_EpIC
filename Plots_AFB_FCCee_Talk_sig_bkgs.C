
//*
//*   ---- Code to drow Plots -----  [ 28 Sep 2022 ]
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

void Plots_AFB_FCCee_Talk_sig_bkgs(){

   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);
    

Float_t  Zmass_Zbb, Zmass_Zcc, Zmass_Zuds, Zmass_Zmumu;
Float_t  leading_b_jet_energy_Zbb, leading_b_jet_energy_Zcc, leading_b_jet_energy_Zuds, leading_b_jet_energy_Zmumu;
Float_t  Promptmuon_Momentum_Zbb, Promptmuon_Momentum_Zcc, Promptmuon_Momentum_Zuds, Promptmuon_Momentum_Zmumu;
Float_t  Cos_theta_bjet_p_Zbb, Cos_theta_bjet_p_Zcc, Cos_theta_bjet_p_Zuds, Cos_theta_bjet_p_Zmumu;


TH1F * histZMass_Zbb = new TH1F ("Zmass_Zbb", "", 50, 20.0, 120.0);
TH1F * histZMass_Zcc = new TH1F ("Zmass_Zcc", "", 50, 20.0, 120.0);
TH1F * histZMass_Zuds = new TH1F ("Zmass_Zuds", "", 50, 20.0, 120.0);
TH1F * histZMass_Zmumu = new TH1F ("Zmass_Zmumu", "", 50, 20.0, 120.0);



TH1F * histleading_b_jet_energy_Zbb = new TH1F ("leading_b_jet_energy_Zbb", "",  50, 1.0, 100.0);
TH1F * histleading_b_jet_energy_Zcc = new TH1F ("leading_b_jet_energy_Zcc", "",  50, 1.0, 100.0);
TH1F * histleading_b_jet_energy_Zuds = new TH1F ("leading_b_jet_energy_Zuds", "",  50, 1.0, 100.0);
TH1F * histleading_b_jet_energy_Zmumu = new TH1F ("leading_b_jet_energy_Zmumu", "",  50, 1.0, 100.0);



TH1F * histPromptmuon_Momentum_Zbb = new TH1F ("Promptmuon_Momentum_Zbb", "",  20, 2.0, 40.0);
TH1F * histPromptmuon_Momentum_Zcc = new TH1F ("Promptmuon_Momentum_Zcc", "",  20, 2.0, 40.0);
TH1F * histPromptmuon_Momentum_Zuds = new TH1F ("Promptmuon_Momentum_Zuds", "",  20, 2.0, 40.0);
TH1F * histPromptmuon_Momentum_Zmumu = new TH1F ("Promptmuon_Momentum_Zmumu", "",  20, 2.0, 40.0);



TH1F * histCos_theta_bjet_p_Zbb = new TH1F ("Cos_theta_bjet_p_Zbb", "", 20, -1.0, 1.0);
TH1F * histCos_theta_bjet_p_Zcc = new TH1F ("Cos_theta_bjet_p_Zcc", "", 20, -1.0, 1.0);
TH1F * histCos_theta_bjet_p_Zuds = new TH1F ("Cos_theta_bjet_p_Zuds", "", 20, -1.0, 1.0);
TH1F * histCos_theta_bjet_p_Zmumu = new TH1F ("Cos_theta_bjet_p_Zmumu", "", 20, -1.0, 1.0);



// ============================================

  TFile *file;
  TTree *tree_Zbb;
  TTree *tree_Zcc;
  TTree *tree_Zuds;
  TTree *tree_Zmumu;

  
  file = TFile::Open("Final_AFB_FCCee_ES_sig_bkgs.root");
 
   tree_Zbb = (TTree*)file->Get("AFB_FCCee_ES_Zbb");
   tree_Zcc = (TTree*)file->Get("AFB_FCCee_ES_Zcc");
   tree_Zuds = (TTree*)file->Get("AFB_FCCee_ES_Zuds");
   tree_Zmumu = (TTree*)file->Get("AFB_FCCee_ES_Zmumu");


   cout << "tree Entries == " << tree_Zbb->GetEntries() << endl;

   tree_Zbb->SetBranchAddress("Zmass_Zbb",&Zmass_Zbb);
   tree_Zcc->SetBranchAddress("Zmass_Zcc",&Zmass_Zcc);
   tree_Zuds->SetBranchAddress("Zmass_Zuds",&Zmass_Zuds);
   tree_Zmumu->SetBranchAddress("Zmass_Zmumu",&Zmass_Zmumu);

   
   tree_Zbb->SetBranchAddress("leading_b_jet_energy_Zbb",&leading_b_jet_energy_Zbb);
   tree_Zcc->SetBranchAddress("leading_b_jet_energy_Zcc",&leading_b_jet_energy_Zcc); 
   tree_Zuds->SetBranchAddress("leading_b_jet_energy_Zuds",&leading_b_jet_energy_Zuds); 
   tree_Zmumu->SetBranchAddress("leading_b_jet_energy_Zmumu",&leading_b_jet_energy_Zmumu); 
   
   
   tree_Zbb->SetBranchAddress("Promptmuon_Momentum_Zbb",&Promptmuon_Momentum_Zbb);
   tree_Zcc->SetBranchAddress("Promptmuon_Momentum_Zcc",&Promptmuon_Momentum_Zcc); 
   tree_Zuds->SetBranchAddress("Promptmuon_Momentum_Zuds",&Promptmuon_Momentum_Zuds);
   tree_Zmumu->SetBranchAddress("Promptmuon_Momentum_Zmumu",&Promptmuon_Momentum_Zmumu); 
   

   tree_Zbb->SetBranchAddress("Cos_theta_bjet_p_Zbb",&Cos_theta_bjet_p_Zbb);
   tree_Zcc->SetBranchAddress("Cos_theta_bjet_p_Zcc",&Cos_theta_bjet_p_Zcc); 
   tree_Zuds->SetBranchAddress("Cos_theta_bjet_p_Zuds",&Cos_theta_bjet_p_Zuds);
   tree_Zmumu->SetBranchAddress("Cos_theta_bjet_p_Zmumu",&Cos_theta_bjet_p_Zmumu);    
   
   

  for (Long64_t ievt=0; ievt<tree_Zbb->GetEntries();ievt++) {
  tree_Zbb->GetEntry(ievt);
  tree_Zcc->GetEntry(ievt);
  tree_Zuds->GetEntry(ievt);
  tree_Zmumu->GetEntry(ievt); 

  
  histZMass_Zbb->Fill(Zmass_Zbb);
  histZMass_Zcc->Fill(Zmass_Zcc);
  histZMass_Zuds->Fill(Zmass_Zuds);  
  histZMass_Zmumu->Fill(Zmass_Zmumu);  
  

  histleading_b_jet_energy_Zbb->Fill(leading_b_jet_energy_Zbb);
  histleading_b_jet_energy_Zcc->Fill(leading_b_jet_energy_Zcc);
  histleading_b_jet_energy_Zuds->Fill(leading_b_jet_energy_Zuds);  
  histleading_b_jet_energy_Zmumu->Fill(leading_b_jet_energy_Zmumu);  


  histPromptmuon_Momentum_Zbb->Fill(Promptmuon_Momentum_Zbb);
  histPromptmuon_Momentum_Zcc->Fill(Promptmuon_Momentum_Zcc);
  histPromptmuon_Momentum_Zuds->Fill(Promptmuon_Momentum_Zuds);  
  histPromptmuon_Momentum_Zmumu->Fill(Promptmuon_Momentum_Zmumu); 
  
  
  histCos_theta_bjet_p_Zbb->Fill(Cos_theta_bjet_p_Zbb);
  histCos_theta_bjet_p_Zcc->Fill(Cos_theta_bjet_p_Zcc);
  histCos_theta_bjet_p_Zuds->Fill(Cos_theta_bjet_p_Zuds);  
  histCos_theta_bjet_p_Zmumu->Fill(Cos_theta_bjet_p_Zmumu);   
  
  
 
      }
      
 

// ------------------- 
 
 
 
 Double_t xl1=0.70, yl1=0.60, xl2=xl1+0.250, yl2=yl1+0.250;

TLegend *leg1 = new TLegend(xl1,yl1,xl2,yl2);
leg1->SetBorderSize(0);

leg1->AddEntry(histZMass_Zbb,"Zbb","L")->SetTextColor(1);
leg1->AddEntry(histZMass_Zcc,"Zcc","L")->SetTextColor(2);
leg1->AddEntry(histZMass_Zuds,"Zuds","L")->SetTextColor(4);
leg1->AddEntry(histZMass_Zmumu,"Z#mu#mu","L")->SetTextColor(6);


leg1->SetTextSize(0.05);
leg1->SetTextFont(12);
leg1->SetFillStyle(0);



// -------------------



TLegend *leg3 = new TLegend(xl1,yl1,xl2,yl2);
leg3->SetBorderSize(0);

leg3->AddEntry(histleading_b_jet_energy_Zbb,"Zbb","L")->SetTextColor(1);
leg3->AddEntry(histleading_b_jet_energy_Zcc,"Zcc","L")->SetTextColor(2);
leg3->AddEntry(histleading_b_jet_energy_Zuds,"Zuds","L")->SetTextColor(4);
leg3->AddEntry(histleading_b_jet_energy_Zmumu,"Z#mu#mu","L")->SetTextColor(6);


leg3->SetTextSize(0.05);
leg3->SetTextFont(12);
leg3->SetFillStyle(0);




// -------------------



TLegend *leg4 = new TLegend(xl1,yl1,xl2,yl2);
leg4->SetBorderSize(0);

leg4->AddEntry(histPromptmuon_Momentum_Zbb,"Zbb","L")->SetTextColor(2);
leg4->AddEntry(histPromptmuon_Momentum_Zcc,"Zcc","L")->SetTextColor(4);
leg4->AddEntry(histPromptmuon_Momentum_Zuds,"Zuds","L")->SetTextColor(6);
//leg4->AddEntry(histPromptmuon_Momentum_Zmumu,"Z#mu#mu","L")->SetTextColor(6);


leg4->SetTextSize(0.05);
leg4->SetTextFont(12);
leg4->SetFillStyle(0);




// -------------------



TLegend *leg5 = new TLegend(xl1,yl1,xl2,yl2);
leg5->SetBorderSize(0);

leg5->AddEntry(histCos_theta_bjet_p_Zbb,"Zbb","L")->SetTextColor(1);
leg5->AddEntry(histCos_theta_bjet_p_Zcc,"Zcc","L")->SetTextColor(2);
leg5->AddEntry(histCos_theta_bjet_p_Zuds,"Zuds","L")->SetTextColor(4);
leg5->AddEntry(histCos_theta_bjet_p_Zmumu,"Z#mu#mu","L")->SetTextColor(6);


leg5->SetTextSize(0.05);
leg5->SetTextFont(12);
leg5->SetFillStyle(0);



// --------------------


TCanvas* c1 = new TCanvas("c1"," ",1);

histZMass_Zbb->SetTitle("M_{Z}");
histZMass_Zbb->GetXaxis()->SetTitle("M_{Z}");
//histZMass_Zbb->GetXaxis()->SetTitleOffset(1.25);
histZMass_Zbb->GetXaxis()->SetLabelFont(22);
histZMass_Zbb->GetXaxis()->SetTitleFont(22);
histZMass_Zbb->GetYaxis()->SetTitle("Events normalised to unit area");
histZMass_Zbb->GetYaxis()->SetTitleOffset(1.40);
histZMass_Zbb->GetYaxis()->SetLabelFont(22);
histZMass_Zbb->GetYaxis()->SetTitleFont(22);


//   histZMass_Zbb->GetYaxis()->SetRangeUser(0,1);
//   histZMass_Zcc->GetYaxis()->SetRangeUser(0,1);
//   histZMass_Zuds->GetYaxis()->SetRangeUser(0,1);
//   histZMass_Zmumu->GetYaxis()->SetRangeUser(0,1);
      
    

   histZMass_Zbb->SetLineWidth(2);
   histZMass_Zcc->SetLineWidth(2);
   histZMass_Zuds->SetLineWidth(2);   
   histZMass_Zmumu->SetLineWidth(2);      
   
   
   histZMass_Zbb->SetLineColor(1);
   histZMass_Zcc->SetLineColor(2);
   histZMass_Zuds->SetLineColor(4);
   histZMass_Zmumu->SetLineColor(6);

   
   histZMass_Zbb->DrawNormalized("hist");
   histZMass_Zcc->DrawNormalized("hist same");
   histZMass_Zuds->DrawNormalized("hist same"); 
   histZMass_Zmumu->DrawNormalized("hist same"); 
 

   leg1->Draw("same");
 
c1->SaveAs("ZMass-sig-bkgs.pdf");
//c1->SaveAs("ZMass-sig-bkgs.C");
//c1->SaveAs("ZMass-sig-bkgs.eps");
//c1->SaveAs("ZMass-sig-bkgs.root");


// ...................................................


TCanvas* c3 = new TCanvas("c3"," ",1);


//histleading_b_jet_energy_Zbb->SetTitle("M_{Z}");
histleading_b_jet_energy_Zbb->GetXaxis()->SetTitle("E_{b-tagged}");
//histleading_b_jet_energy_Zbb->GetXaxis()->SetTitleOffset(1.25);
histleading_b_jet_energy_Zbb->GetXaxis()->SetLabelFont(22);
histleading_b_jet_energy_Zbb->GetXaxis()->SetTitleFont(22);
histleading_b_jet_energy_Zbb->GetYaxis()->SetTitle("Events normalised to unit area");
histleading_b_jet_energy_Zbb->GetYaxis()->SetTitleOffset(1.40);
histleading_b_jet_energy_Zbb->GetYaxis()->SetLabelFont(22);
histleading_b_jet_energy_Zbb->GetYaxis()->SetTitleFont(22);



histleading_b_jet_energy_Zbb->SetLineWidth(2);
histleading_b_jet_energy_Zcc->SetLineWidth(2);
histleading_b_jet_energy_Zuds->SetLineWidth(2);
histleading_b_jet_energy_Zmumu->SetLineWidth(2);


histleading_b_jet_energy_Zbb->SetLineColor(1);
histleading_b_jet_energy_Zcc->SetLineColor(2);
histleading_b_jet_energy_Zuds->SetLineColor(4);
histleading_b_jet_energy_Zmumu->SetLineColor(6);
      

histleading_b_jet_energy_Zbb->DrawNormalized("hist");
histleading_b_jet_energy_Zcc->DrawNormalized("hist same");
histleading_b_jet_energy_Zuds->DrawNormalized("hist same");
histleading_b_jet_energy_Zmumu->DrawNormalized("hist same");

   leg3->Draw("same");
 
c3->SaveAs("leading_b_jet_energy-sig-bkgs.pdf");
//c3->SaveAs("leading_b_jet_energy-sig-bkgs.C");
//c3->SaveAs("leading_b_jet_energy-sig-bkgs.eps");
//c3->SaveAs("leading_b_jet_energy-sig-bkgs.root");




// ----------------------------------------------



TCanvas* c4 = new TCanvas("c4"," ",1);


  //c4->SetFrameFillColor(0);
  //c4->SetFrameFillStyle(4000);
//   c4->SetFillColor(0);
//   c4->SetBorderMode(0);
//   c4->SetBorderSize(2);
//   c4->SetTickx(1);
//   c4->SetTicky(1);
//  gPad->SetLeftMargin(.135);
//  gPad->SetRightMargin(0.071);
//  gPad->SetTopMargin(0.062);
//  gPad->SetBottomMargin(0.165);
  //gPad->SetTicky(); //ticks on both y axis
  //gPad->SetTicks(); //ticks on all four axes


//histleading_b_jet_energy_Zbb->SetTitle("M_{Z}");
histPromptmuon_Momentum_Zuds->GetXaxis()->SetTitle("p^{#mu}_{leading} [GeV]");
histPromptmuon_Momentum_Zuds->GetXaxis()->SetTitleOffset(1.5);
histPromptmuon_Momentum_Zuds->GetXaxis()->SetLabelFont(22);
histPromptmuon_Momentum_Zuds->GetXaxis()->SetTitleFont(22);
histPromptmuon_Momentum_Zuds->GetYaxis()->SetTitle("Events normalised to unit area");
histPromptmuon_Momentum_Zuds->GetYaxis()->SetTitleOffset(1.5);
histPromptmuon_Momentum_Zuds->GetYaxis()->SetLabelFont(22);
histPromptmuon_Momentum_Zuds->GetYaxis()->SetTitleFont(22);


//    histPromptmuon_Momentum_Zbb->GetYaxis()->SetRangeUser(0,0.25);
//    histPromptmuon_Momentum_Zcc->GetYaxis()->SetRangeUser(0,0.25);
//    histPromptmuon_Momentum_Zuds->GetYaxis()->SetRangeUser(0,0.3);
//    histPromptmuon_Momentum_Zmumu->GetYaxis()->SetRangeUser(0,0.25);


histPromptmuon_Momentum_Zbb->SetLineWidth(3);
histPromptmuon_Momentum_Zcc->SetLineWidth(3);
histPromptmuon_Momentum_Zuds->SetLineWidth(3);
//histPromptmuon_Momentum_Zmumu->SetLineWidth(2);


histPromptmuon_Momentum_Zbb->SetLineColor(2);
histPromptmuon_Momentum_Zcc->SetLineColor(4);
histPromptmuon_Momentum_Zuds->SetLineColor(6);
//histPromptmuon_Momentum_Zmumu->SetLineColor(6);
      

histPromptmuon_Momentum_Zbb->SetFillColor(kRed-4);
histPromptmuon_Momentum_Zcc->SetFillColor(kBlue-4);
histPromptmuon_Momentum_Zuds->SetFillColor(kMagenta-4);


histPromptmuon_Momentum_Zuds->DrawNormalized("hist");
histPromptmuon_Momentum_Zcc->DrawNormalized("hist same");
histPromptmuon_Momentum_Zbb->DrawNormalized("hist same");

//histPromptmuon_Momentum_Zmumu->DrawNormalized("hist same");

   leg4->Draw("same");
 
c4->SaveAs("Promptmuon_Momentum-sig-bkgs.pdf");
//c4->SaveAs("Promptmuon_Momentum-sig-bkgs.C");
//c4->SaveAs("Promptmuon_Momentum-sig-bkgs.eps");
//c4->SaveAs("Promptmuon_Momentum-sig-bkgs.root");



// ----------------------------------------------



TCanvas* c5 = new TCanvas("c5"," ",1);



//histCos_theta_bjet_p_Zbb->SetTitle("M_{Z}");
histCos_theta_bjet_p_Zbb->GetXaxis()->SetTitle("p^{#mu}");
//histCos_theta_bjet_p_Zbb->GetXaxis()->SetTitleOffset(1.25);
histCos_theta_bjet_p_Zbb->GetXaxis()->SetLabelFont(22);
histCos_theta_bjet_p_Zbb->GetXaxis()->SetTitleFont(22);
histCos_theta_bjet_p_Zbb->GetYaxis()->SetTitle("Events normalised to unit area");
histCos_theta_bjet_p_Zbb->GetYaxis()->SetTitleOffset(1.40);
histCos_theta_bjet_p_Zbb->GetYaxis()->SetLabelFont(22);
histCos_theta_bjet_p_Zbb->GetYaxis()->SetTitleFont(22);


//    histCos_theta_bjet_p_Zbb->GetYaxis()->SetRangeUser(0,0.16);
//    histCos_theta_bjet_p_Zcc->GetYaxis()->SetRangeUser(0,0.16);
//    histCos_theta_bjet_p_Zuds->GetYaxis()->SetRangeUser(0,0.16);
//    histCos_theta_bjet_p_Zmumu->GetYaxis()->SetRangeUser(0,0.16);


histCos_theta_bjet_p_Zbb->SetLineWidth(2);
histCos_theta_bjet_p_Zcc->SetLineWidth(2);
histCos_theta_bjet_p_Zuds->SetLineWidth(2);
histCos_theta_bjet_p_Zmumu->SetLineWidth(2);


histCos_theta_bjet_p_Zbb->SetLineColor(1);
histCos_theta_bjet_p_Zcc->SetLineColor(2);
histCos_theta_bjet_p_Zuds->SetLineColor(4);
histCos_theta_bjet_p_Zmumu->SetLineColor(6);
      

histCos_theta_bjet_p_Zbb->DrawNormalized("hist");
// histCos_theta_bjet_p_Zcc->DrawNormalized("hist same");
// histCos_theta_bjet_p_Zuds->DrawNormalized("hist same");
// histCos_theta_bjet_p_Zmumu->DrawNormalized("hist same");


   leg5->Draw("same");
 
c5->SaveAs("Cos_theta_bjet_p-sig-bkgs.pdf");
//c5->SaveAs("Cos_theta_bjet_p-sig-bkgs.C");
//c5->SaveAs("Cos_theta_bjet_p-sig-bkgs.eps");
//c5->SaveAs("Cos_theta_bjet_p-sig-bkgs.root");





// ----------------------------------------------





}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
