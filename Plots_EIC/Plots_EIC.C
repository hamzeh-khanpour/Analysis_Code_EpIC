
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
   Float_t  integrated_cross_section_value_TCS = 0;
   Float_t  integrated_cross_section_value_All = 0;
   
   Float_t  event_weight_BH  = 0;
   Float_t  event_weight_TCS = 0;
   Float_t  event_weight_All = 0;
   
//*   -----------------------------------------------

void Plots_EIC(){

    
    
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
  histtvalue_BH->Fill(tvalue);   // ,event_weight_BH ,integrated_cross_section_value_BH
cout << "event_weight_BH =" << event_weight_BH << endl;
    }
    

  for (Long64_t ievt=0; ievt<tree_EIC_TCS->GetEntries();ievt++) {
  tree_EIC_TCS->GetEntry(ievt);
  
  histMll_TCS->Fill(Mll);
  histPtll_TCS->Fill(Ptll);
  histtvalue_TCS->Fill(tvalue);  //  ,integrated_cross_section_value_TCS
cout << "event_weight_TCS =" << event_weight_TCS << endl;
    }


  for (Long64_t ievt=0; ievt<tree_EIC_All->GetEntries();ievt++) {
  tree_EIC_All->GetEntry(ievt);
  
  histMll_All->Fill(Mll);
  histPtll_All->Fill(Ptll);
  histtvalue_All->Fill(tvalue);  //  ,integrated_cross_section_value_All
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

   histMll_BH->GetYaxis()->SetRangeUser(0,10000);
//   histMll_BH->GetXaxis()->SetRangeUser(0,1);

   histMll_BH->SetLineWidth(3);
   histMll_TCS->SetLineWidth(3); 
   histMll_All->SetLineWidth(3);
   
   histMll_BH->SetLineColor(2);
   histMll_TCS->SetLineColor(6);
   histMll_All->SetLineColor(4);   

   histMll_BH->DrawNormalized("hist");
   histMll_TCS->DrawNormalized("hist same");
   histMll_All->DrawNormalized("hist same");

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
  
 
c1->SaveAs("Mll_Qp100.pdf");
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

   histPtll_BH->GetYaxis()->SetRangeUser(0,10000);
//   histPtll_BH->GetXaxis()->SetRangeUser(0,1);

   histPtll_BH->SetLineWidth(3);
   histPtll_TCS->SetLineWidth(3);
   histPtll_All->SetLineWidth(3); 

   histPtll_BH->SetLineColor(2);
   histPtll_TCS->SetLineColor(6);
   histPtll_All->SetLineColor(4);

   histPtll_BH->DrawNormalized("hist");
   histPtll_TCS->DrawNormalized("hist same");
   histPtll_All->DrawNormalized("hist same");

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
 
 
c2->SaveAs("Ptll_Qp100.pdf");
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
histtvalue_BH->GetYaxis()->SetTitle("Events normalised to unit area");  // d#sigma/d|t| [pb]
histtvalue_BH->GetYaxis()->SetTitleOffset(1.40);
histtvalue_BH->GetYaxis()->SetLabelFont(22);
histtvalue_BH->GetYaxis()->SetTitleFont(22);

   histtvalue_BH->GetXaxis()->SetRangeUser(0,8000);
//   histtvalue_BH->GetXaxis()->SetRangeUser(0,1);

   histtvalue_BH->SetLineWidth(3);
   histtvalue_TCS->SetLineWidth(3);
   histtvalue_All->SetLineWidth(3); 

   histtvalue_BH->SetLineColor(2);
   histtvalue_TCS->SetLineColor(6);
   histtvalue_All->SetLineColor(4);

   histtvalue_BH->DrawNormalized("hist");
   histtvalue_TCS->DrawNormalized("hist same");
   histtvalue_All->DrawNormalized("hist same");   

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
 

c3->SaveAs("t-value_Qp100.pdf");
//c3->SaveAs("t-value.C");
//c3->SaveAs("t-value.eps");
//c3->SaveAs("t-value.root");



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

//     c4->SetLogy(1);
//   c4->SetLogx(1);

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
 

c4->SaveAs("t-value-nonorm_Qp100.pdf");
//c4->SaveAs("t-value-nonorm.C");
//c4->SaveAs("t-value-nonorm.eps");
//c4->SaveAs("t-value-nonorm.root");




}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
