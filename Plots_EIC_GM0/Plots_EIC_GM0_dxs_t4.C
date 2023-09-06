//
//   histtvalue_BH->Scale(tree_EIC_BH->GetEntries()*event_weight_BH/histtvalue_BH->Integral());
//   histtvalue_BH_GM0->Scale(tree_EIC_BH_GM0->GetEntries()*event_weight_BH_GM0/histtvalue_BH_GM0->Integral());   
//   histtvalue_BH->Draw("hist");
//   histtvalue_BH_GM0->Draw("hist same");
//
//
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

void Plots_EIC_GM0_dxs_t4(){

    
    
   Float_t  nentries = 1000000.0;
   Float_t  integrated_luminosity = 300.0 / 1000.0; // fb^{-1} 
   Float_t  integrated_cross_section_value_BH      = 3.20707522890871   * 1000.0;   //   nb  BH Q'=100, t=4
   Float_t  integrated_cross_section_value_BH_GM0  = 3.02965954863237   * 1000.0;   //   nb  BH-GM0   Q'=100, t=4
   Float_t  integrated_cross_section_value_All     = 3.50464474849106   * 1000.0;   //   nb  BH+TCS   Q'=100, t=4 
   Float_t  integrated_cross_section_value_All_GM0 = 3.31689022158091   * 1000.0;   //   nb  BH+TCS-GM0   Q'=100, t=4  
   
   
   Float_t  event_weight_BH  = integrated_cross_section_value_BH  * 1.0 / nentries;
   Float_t  event_weight_BH_GM0 = integrated_cross_section_value_BH_GM0 * 1.0 / nentries;
   Float_t  event_weight_All = integrated_cross_section_value_All * 1.0 / nentries;
   Float_t  event_weight_All_GM0 = integrated_cross_section_value_All_GM0 * 1.0 / nentries;   
    
    
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

TH1F * histtvalue_BH = new TH1F ("tvalue", "",  40, 0.0, 4.0);
TH1F * histtvalue_BH_GM0 = new TH1F ("tvalue", "", 40, 0.0, 4.0);
TH1F * histtvalue_All = new TH1F ("tvalue", "", 40, 0.0, 4.0);
TH1F * histtvalue_All_GM0 = new TH1F ("tvalue", "", 40, 0.0, 4.0);

// ============================================

  TFile *file;
  TTree *tree_EIC_BH;
  TTree *tree_EIC_BH_GM0;
  TTree *tree_EIC_All;
  TTree *tree_EIC_All_GM0;
  

   file = TFile::Open("EIC_Hamzeh_Qp100_t4_GM0.root");

 
   tree_EIC_BH  = (TTree*)file->Get("EIC_BH_t4");
   tree_EIC_BH_GM0 = (TTree*)file->Get("EIC_BH_GM0_t4");   
   tree_EIC_All = (TTree*)file->Get("EIC_ALL_t4");
   tree_EIC_All_GM0 = (TTree*)file->Get("EIC_ALL_GM0_t4");   


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
  histtvalue_BH->Fill(tvalue,event_weight_BH);   //  
cout << "event_weight_BH =" << event_weight_BH << endl;
    }


  for (Long64_t ievt=0; ievt<tree_EIC_BH_GM0->GetEntries();ievt++) {
  tree_EIC_BH_GM0->GetEntry(ievt);
  
  histMll_BH_GM0->Fill(Mll);
  histPtll_BH_GM0->Fill(Ptll);
  histtvalue_BH_GM0->Fill(tvalue,event_weight_BH_GM0);  //   
cout << "event_weight_BH_GM0 =" << event_weight_BH_GM0 << endl;
    }


  for (Long64_t ievt=0; ievt<tree_EIC_All->GetEntries();ievt++) {
  tree_EIC_All->GetEntry(ievt);
  
  histMll_All->Fill(Mll);
  histPtll_All->Fill(Ptll);
  histtvalue_All->Fill(tvalue,event_weight_All);  //   
cout << "event_weight_All =" << event_weight_All << endl;
    }
    
 
  for (Long64_t ievt=0; ievt<tree_EIC_All_GM0->GetEntries();ievt++) {
  tree_EIC_All_GM0->GetEntry(ievt);
  
  histMll_All_GM0->Fill(Mll);
  histPtll_All_GM0->Fill(Ptll);
  histtvalue_All_GM0->Fill(tvalue,event_weight_All_GM0);  //  
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

//   histtvalue_BH->GetXaxis()->SetRangeUser(0,8000);
//   histtvalue_BH->GetXaxis()->SetRangeUser(0,1);

   histtvalue_BH->SetLineWidth(3);
   histtvalue_BH_GM0->SetLineWidth(3);

   histtvalue_BH->SetLineColor(2);
   histtvalue_BH_GM0->SetLineColor(4);

   histtvalue_BH->DrawNormalized("hist");
   histtvalue_BH_GM0->DrawNormalized("hist same");

//   c3->SetLogy(1);
//   c3->SetLogx(1);

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
 

c3->SaveAs("t-value_BH_GM0_t4.pdf");
//c3->SaveAs("t-value_BH_GM0_t4.C");
//c3->SaveAs("t-value_BH_GM0_t4.eps");
//c3->SaveAs("t-value_BH_GM0_t4.root");



// --------------------



TCanvas* c4 = new TCanvas("c4","tvalue", 10, 10, 900, 700);

//histtvalue_BH->SetTitle("m_{ll}");
histtvalue_BH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_BH->GetXaxis()->SetTitleOffset(1.25);
histtvalue_BH->GetXaxis()->SetLabelFont(22);
histtvalue_BH->GetXaxis()->SetTitleFont(22);
histtvalue_BH->GetYaxis()->SetTitle("d#sigma/d|t| [pb/GeV^{2}]");  // d#sigma/d|t| [pb]
histtvalue_BH->GetYaxis()->SetTitleOffset(1.40);
histtvalue_BH->GetYaxis()->SetLabelFont(22);
histtvalue_BH->GetYaxis()->SetTitleFont(22);

//  histtvalue_BH->GetYaxis()->SetRangeUser(1,100000);
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
 

c4->SaveAs("t-value-nonorm_BH_GM0_t4.pdf");
//c4->SaveAs("t-value-nonorm_BH_GM0_t4.C");
//c4->SaveAs("t-value-nonorm_BH_GM0_t4.eps");
//c4->SaveAs("t-value-nonorm_BH_GM0_t4.root");




// --------------------


TCanvas* c5 = new TCanvas("c5","tvalue", 10, 10, 900, 700);

//histtvalue_All->SetTitle("m_{ll}");
histtvalue_All->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_All->GetXaxis()->SetTitleOffset(1.25);
histtvalue_All->GetXaxis()->SetLabelFont(22);
histtvalue_All->GetXaxis()->SetTitleFont(22);
histtvalue_All->GetYaxis()->SetTitle("Events normalised to unit area");  // d#sigma/d|t| [pb]
histtvalue_All->GetYaxis()->SetTitleOffset(1.40);
histtvalue_All->GetYaxis()->SetLabelFont(22);
histtvalue_All->GetYaxis()->SetTitleFont(22);

//   histtvalue_All->GetXaxis()->SetRangeUser(0,8000);
//   histtvalue_All->GetXaxis()->SetRangeUser(0,1);

   histtvalue_All->SetLineWidth(3);
   histtvalue_All_GM0->SetLineWidth(3);

   histtvalue_All->SetLineColor(2);
   histtvalue_All_GM0->SetLineColor(4);

   histtvalue_All->DrawNormalized("hist");
   histtvalue_All_GM0->DrawNormalized("hist same");

//   c5->SetLogy(1);
//   c5->SetLogx(1);

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
 

c5->SaveAs("t-t-value_All_GM0_t4.pdf");
//c5->SaveAs("t-t-value_All_GM0_t4.C");
//c5->SaveAs("t-t-value_All_GM0_t4.eps");
//c5->SaveAs("t-t-value_All_GM0_t4.root");





// --------------------



TCanvas* c6 = new TCanvas("c6","tvalue", 10, 10, 900, 700);

//histtvalue_All->SetTitle("m_{ll}");
histtvalue_All->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_All->GetXaxis()->SetTitleOffset(1.25);
histtvalue_All->GetXaxis()->SetLabelFont(22);
histtvalue_All->GetXaxis()->SetTitleFont(22);
histtvalue_All->GetYaxis()->SetTitle("d#sigma/d|t| [pb/GeV^{2}]");  // d#sigma/d|t| [pb]
histtvalue_All->GetYaxis()->SetTitleOffset(1.40);
histtvalue_All->GetYaxis()->SetLabelFont(22);
histtvalue_All->GetYaxis()->SetTitleFont(22);

//  histtvalue_All->GetYaxis()->SetRangeUser(1,100000);
//   histtvalue_All->GetXaxis()->SetRangeUser(0,1);

   histtvalue_All->SetLineWidth(3);
   histtvalue_All_GM0->SetLineWidth(3);

   histtvalue_All->SetLineColor(2);
   histtvalue_All_GM0->SetLineColor(4);


//   histtvalue_All->Scale(tvalue*histtvalue_All);
//   histtvalue_All_GM0->Scale(tvalue*histtvalue_All_GM0);

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
 

c6->SaveAs("t-value-nonorm_All_GM0_t4.pdf");
//c6->SaveAs("t-value-nonorm_All_GM0_t4.C");
//c6->SaveAs("t-value-nonorm_All_GM0_t4.eps");
//c6->SaveAs("t-value-nonorm_All_GM0_t4.root");




}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
