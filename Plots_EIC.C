
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

void Plots_EIC(){

    
   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);


   Float_t Mll;
   Float_t Ptll;
   Float_t tvalue;


TH1F * histMll_BH = new TH1F ("Mll", "", 40, 0.0, 4.0);
TH1F * histMll_All = new TH1F ("Mll", "", 40, 0.0, 4.0);


TH1F * histPtll_BH = new TH1F ("Ptll", "", 40, 0.0, 2.0);
TH1F * histPtll_All = new TH1F ("Ptll", "", 40, 0.0, 2.0);


TH1F * histtvalue_BH = new TH1F ("tvalue", "", 40, 0.0, 0.4);
TH1F * histtvalue_All = new TH1F ("tvalue", "", 40, 0.0, 0.4);



// ============================================

  TFile *file;
  TTree *tree_EIC_BH;
  TTree *tree_EIC_All;


   file = TFile::Open("EIC_Hadi.root");
 
   tree_EIC_BH = (TTree*)file->Get("EIC1");
   tree_EIC_All = (TTree*)file->Get("EIC2");


   cout << "tree Entries Signal_eebbee_LL == " << tree_EIC_BH->GetEntries() << endl;
   cout << "tree Entries Signal_eebbee_LR == " << tree_EIC_All->GetEntries() << endl;   
   
   tree_EIC_BH->SetBranchAddress("Mll",&Mll);
   tree_EIC_All->SetBranchAddress("Mll",&Mll);


   tree_EIC_BH->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_All->SetBranchAddress("Ptll",&Ptll);

   
   tree_EIC_BH->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_All->SetBranchAddress("tvalue",&tvalue);

  

   
  for (Long64_t ievt=0; ievt<tree_EIC_BH->GetEntries();ievt++) {
  tree_EIC_BH->GetEntry(ievt);
  
  histMll_BH->Fill(Mll);
  histPtll_BH->Fill(Ptll);
  histtvalue_BH->Fill(tvalue);

    }
    


  for (Long64_t ievt=0; ievt<tree_EIC_All->GetEntries();ievt++) {
  tree_EIC_All->GetEntry(ievt);
  
  histMll_All->Fill(Mll);
  histPtll_All->Fill(Ptll);
  histtvalue_All->Fill(tvalue);

    }

// ------------------- 
 
 
 
Double_t xl1=0.70, yl1=0.650, xl2=xl1+0.150, yl2=yl1+0.150;

TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
leg->SetBorderSize(0);

leg->AddEntry(histMll_BH,"BH","L")->SetTextColor(1);
leg->AddEntry(histMll_All,"BH+TCS","L")->SetTextColor(1);

leg->SetTextSize(0.032);
leg->SetTextFont(12);
leg->SetFillStyle(0);

//    (#sqrt{s} = 365 GeV, L_{int} = 1.5 ab^{-1})    1.5 ab^{-1} (365 GeV)

TLatex *t2a = new TLatex(0.5,0.9,"#bf{Electron-Ion Collider (EIC)}");
                t2a->SetNDC();
                t2a->SetTextFont(42);
                t2a->SetTextSize(0.04);
                t2a->SetTextAlign(20);

                
TLatex *t3a = new TLatex(0.27,0.8,"E_{e} = 18 GeV");
                t3a->SetNDC();
                t3a->SetTextFont(42);
                t3a->SetTextSize(0.04);
                t3a->SetTextAlign(20);
                
            
TLatex *t4a = new TLatex(0.276,0.75,"E_{p} = 275 GeV");
                t4a->SetNDC();
                t4a->SetTextFont(42);
                t4a->SetTextSize(0.04);
                t4a->SetTextAlign(20);


TLatex *t5a = new TLatex(0.666,0.60,"lepton_polarisation = -1");
                t5a->SetNDC();
                t5a->SetTextFont(42);
                t5a->SetTextSize(0.04);
                t5a->SetTextAlign(20);
                
TLatex *t6a = new TLatex(0.692,0.55,"hadron_polarisation = 0|0|1");
                t6a->SetNDC();
                t6a->SetTextFont(42);
                t6a->SetTextSize(0.04);
                t6a->SetTextAlign(20);
                
                
// --------------------


TCanvas* c1 = new TCanvas("c1","Massdilepton", 10, 10, 900, 700);

//histMll_BH->SetTitle("m_{ll}");
histMll_BH->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
histMll_BH->GetXaxis()->SetTitleOffset(1.25);
histMll_BH->GetXaxis()->SetLabelFont(22);
histMll_BH->GetXaxis()->SetTitleFont(22);
histMll_BH->GetYaxis()->SetTitle("Events normalised to unit area");
histMll_BH->GetYaxis()->SetTitleOffset(1.40);
histMll_BH->GetYaxis()->SetLabelFont(22);
histMll_BH->GetYaxis()->SetTitleFont(22);

//   histMll_BH->GetXaxis()->SetRangeUser(0,1);
//   histMll_BH->GetXaxis()->SetRangeUser(0,1);

   histMll_BH->SetLineWidth(3);
   histMll_All->SetLineWidth(3);
 

   histMll_BH->SetLineColor(2);
   histMll_All->SetLineColor(4);


   histMll_BH->DrawNormalized("hist");
   histMll_All->DrawNormalized("hist same");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
 t6a->Draw("same");  
 
c1->SaveAs("Mll.pdf");
//c1->SaveAs("Mll.C");
//c1->SaveAs("Mll.eps");
//c1->SaveAs("Mll.root");


// --------------------



TCanvas* c2 = new TCanvas("c2","Ptdilepton", 10, 10, 900, 700);

//histPtll_BH->SetTitle("m_{ll}");
histPtll_BH->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
histPtll_BH->GetXaxis()->SetTitleOffset(1.25);
histPtll_BH->GetXaxis()->SetLabelFont(22);
histPtll_BH->GetXaxis()->SetTitleFont(22);
histPtll_BH->GetYaxis()->SetTitle("Events normalised to unit area");
histPtll_BH->GetYaxis()->SetTitleOffset(1.40);
histPtll_BH->GetYaxis()->SetLabelFont(22);
histPtll_BH->GetYaxis()->SetTitleFont(22);

//   histPtll_BH->GetXaxis()->SetRangeUser(0,1);
//   histPtll_BH->GetXaxis()->SetRangeUser(0,1);

   histPtll_BH->SetLineWidth(3);
   histPtll_All->SetLineWidth(3);
 

   histPtll_BH->SetLineColor(2);
   histPtll_All->SetLineColor(4);


   histPtll_BH->DrawNormalized("hist");
   histPtll_All->DrawNormalized("hist same");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
 t6a->Draw("same");  
 
c2->SaveAs("Ptll.pdf");
//c2->SaveAs("ptll.C");
//c2->SaveAs("ptll.eps");
//c2->SaveAs("ptll.root");


// --------------------



TCanvas* c3 = new TCanvas("c3","tvalue", 10, 10, 900, 700);

//histtvalue_BH->SetTitle("m_{ll}");
histtvalue_BH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_BH->GetXaxis()->SetTitleOffset(1.25);
histtvalue_BH->GetXaxis()->SetLabelFont(22);
histtvalue_BH->GetXaxis()->SetTitleFont(22);
histtvalue_BH->GetYaxis()->SetTitle("#Events");
histtvalue_BH->GetYaxis()->SetTitleOffset(1.40);
histtvalue_BH->GetYaxis()->SetLabelFont(22);
histtvalue_BH->GetYaxis()->SetTitleFont(22);

//   histtvalue_BH->GetXaxis()->SetRangeUser(0,1);
//   histtvalue_BH->GetXaxis()->SetRangeUser(0,1);

   histtvalue_BH->SetLineWidth(3);
   histtvalue_All->SetLineWidth(3);
 

   histtvalue_BH->SetLineColor(2);
   histtvalue_All->SetLineColor(4);


   histtvalue_BH->Draw("hist");
   histtvalue_All->Draw("hist same");

   c3->SetLogy(1);
//   c3->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
 t6a->Draw("same");  
 
c3->SaveAs("t-value.pdf");
//c3->SaveAs("t-value.C");
//c3->SaveAs("t-value.eps");
//c3->SaveAs("t-value.root");


}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
