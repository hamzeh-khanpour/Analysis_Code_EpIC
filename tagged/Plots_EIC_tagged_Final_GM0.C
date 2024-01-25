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

   Float_t thetal = 0;
   Float_t phil = 0;


   Float_t  nentries = 0;
   Float_t  integrated_luminosity = 0;

   Float_t  integrated_cross_section_value_LM_BH = 0;
   Float_t  integrated_cross_section_value_HM_BH = 0;

   Float_t  integrated_cross_section_value_LM_BH_GM0 = 0;
   Float_t  integrated_cross_section_value_HM_BH_GM0 = 0;

   Float_t  integrated_cross_section_value_LM_ALL = 0;
   Float_t  integrated_cross_section_value_HM_ALL = 0;
   
   Float_t  event_weight_LM_BH  = 0;
   Float_t  event_weight_HM_BH  = 0;

   Float_t  event_weight_LM_BH_GM0  = 0;
   Float_t  event_weight_HM_BH_GM0  = 0;

   Float_t  event_weight_LM_ALL  = 0;
   Float_t  event_weight_HM_ALL  = 0;
   
//*   -----------------------------------------------

void Plots_EIC_tagged_Final_GM0(){

    
   
   Float_t  nentries = 5000000.0;
   Float_t  integrated_luminosity = 300.0 / 1000.0; // fb^{-1} 



   Float_t  integrated_cross_section_value_LM_BH  = 3.355      * 1000.0;   //    nb   BH LM
   Float_t  integrated_cross_section_value_HM_BH  = 0.219293   * 1000.0;   //    nb   BH HM

   Float_t  integrated_cross_section_value_LM_BH_GM0  = 3.08048    * 1000.0;   //    nb   BH_GM0 LM
   Float_t  integrated_cross_section_value_HM_BH_GM0  = 0.186446   * 1000.0;   //    nb   BH_GM0 HM

   Float_t  integrated_cross_section_value_LM_ALL  = 3.79989    * 1000.0;   //    nb   ALL LM
   Float_t  integrated_cross_section_value_HM_ALL  = 0.247091   * 1000.0;   //    nb   ALL HM

   
   Float_t  event_weight_LM_BH  = integrated_cross_section_value_LM_BH  * 1.0 / nentries;
   Float_t  event_weight_HM_BH  = integrated_cross_section_value_HM_BH  * 1.0 / nentries;

   Float_t  event_weight_LM_BH_GM0  = integrated_cross_section_value_LM_BH_GM0  * 1.0 / nentries;
   Float_t  event_weight_HM_BH_GM0  = integrated_cross_section_value_HM_BH_GM0  * 1.0 / nentries;
    
   Float_t  event_weight_LM_ALL  = integrated_cross_section_value_LM_ALL  * 1.0 / nentries;
   Float_t  event_weight_HM_ALL  = integrated_cross_section_value_HM_ALL  * 1.0 / nentries;

    
   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);


TH1F * histMll_LM_BH  = new TH1F ("Mll", "", 40, 0.0, 10.0);
TH1F * histMll_HM_BH = new TH1F ("Mll", "", 40, 0.0, 10.0);

TH1F * histPtll_LM_BH  = new TH1F ("Ptll", "",  30, 0.0, 1.0);
TH1F * histPtll_HM_BH = new TH1F ("Ptll", "", 30, 0.0, 1.0);

TH1F * histtvalue_LM_BH  = new TH1F ("tvalue", "",  30, 0.0, 4.0);
TH1F * histtvalue_HM_BH = new TH1F ("tvalue", "", 30, 0.0, 4.0);


TH1F * histthetal_LM_BH  = new TH1F ("thetal", "",  30, 0.0, 4.0);
TH1F * histthetal_HM_BH = new TH1F ("thetal", "", 30, 0.0, 4.0);


TH1F * histphil_LM_BH  = new TH1F ("phil", "",  30, 0.0, 7.0);
TH1F * histphil_HM_BH = new TH1F ("phil", "", 30, 0.0, 7.0);





TH1F * histMll_LM_BH_GM0  = new TH1F ("Mll", "", 40, 0.0, 10.0);
TH1F * histMll_HM_BH_GM0 = new TH1F ("Mll", "", 40, 0.0, 10.0);

TH1F * histPtll_LM_BH_GM0  = new TH1F ("Ptll", "",  30, 0.0, 1.0);
TH1F * histPtll_HM_BH_GM0 = new TH1F ("Ptll", "", 30, 0.0, 1.0);

TH1F * histtvalue_LM_BH_GM0  = new TH1F ("tvalue", "",  30, 0.0, 4.0);
TH1F * histtvalue_HM_BH_GM0 = new TH1F ("tvalue", "", 30, 0.0, 4.0);


TH1F * histthetal_LM_BH_GM0  = new TH1F ("thetal", "",  30, 0.0, 4.0);
TH1F * histthetal_HM_BH_GM0 = new TH1F ("thetal", "", 30, 0.0, 4.0);


TH1F * histphil_LM_BH_GM0  = new TH1F ("phil", "",  30, 0.0, 7.0);
TH1F * histphil_HM_BH_GM0 = new TH1F ("phil", "", 30, 0.0, 7.0);





TH1F * histMll_LM_ALL  = new TH1F ("Mll", "", 40, 0.0, 10.0);
TH1F * histMll_HM_ALL = new TH1F ("Mll", "", 40, 0.0, 10.0);

TH1F * histPtll_LM_ALL  = new TH1F ("Ptll", "",  30, 0.0, 1.0);
TH1F * histPtll_HM_ALL = new TH1F ("Ptll", "", 30, 0.0, 1.0);

TH1F * histtvalue_LM_ALL  = new TH1F ("tvalue", "",  30, 0.0, 4.0);
TH1F * histtvalue_HM_ALL = new TH1F ("tvalue", "", 30, 0.0, 4.0);


TH1F * histthetal_LM_ALL  = new TH1F ("thetal", "",  30, 0.0, 4.0);
TH1F * histthetal_HM_ALL = new TH1F ("thetal", "", 30, 0.0, 4.0);


TH1F * histphil_LM_ALL  = new TH1F ("phil", "",  30, 0.0, 7.0);
TH1F * histphil_HM_ALL = new TH1F ("phil", "", 30, 0.0, 7.0);



// ============================================

   TFile *file;
   TTree *tree_EIC_LM_BH;
   TTree *tree_EIC_HM_BH;

   TTree *tree_EIC_LM_BH_GM0;
   TTree *tree_EIC_HM_BH_GM0;

   TTree *tree_EIC_LM_ALL;
   TTree *tree_EIC_HM_ALL;


   file = TFile::Open("EIC_tagged_GM_no_GM.root");

 
   tree_EIC_LM_BH  = (TTree*)file->Get("EIC_BH_LM");
   tree_EIC_HM_BH  = (TTree*)file->Get("EIC_BH_HM");

   tree_EIC_LM_BH_GM0  = (TTree*)file->Get("EIC_BH_LM_GM0");
   tree_EIC_HM_BH_GM0  = (TTree*)file->Get("EIC_BH_HM_GM0");

   tree_EIC_LM_ALL  = (TTree*)file->Get("EIC_ALL_LM");
   tree_EIC_HM_ALL  = (TTree*)file->Get("EIC_ALL_HM");


   cout << "tree Entries tree_EIC_LM_BH  == " << tree_EIC_LM_BH->GetEntries() << endl;
   cout << "tree Entries tree_EIC_HM_BH  == " << tree_EIC_HM_BH->GetEntries() << endl;

   cout << "tree Entries tree_EIC_LM_BH_GM0  == " << tree_EIC_LM_BH_GM0->GetEntries() << endl;
   cout << "tree Entries tree_EIC_HM_BH_GM0  == " << tree_EIC_HM_BH_GM0->GetEntries() << endl;

   cout << "tree Entries tree_EIC_LM_ALL  == " << tree_EIC_LM_ALL->GetEntries() << endl;
   cout << "tree Entries tree_EIC_HM_ALL  == " << tree_EIC_HM_ALL->GetEntries() << endl;

      
   tree_EIC_LM_BH->SetBranchAddress("Mll",&Mll);
   tree_EIC_HM_BH->SetBranchAddress("Mll",&Mll);

   tree_EIC_LM_BH_GM0->SetBranchAddress("Mll",&Mll);
   tree_EIC_HM_BH_GM0->SetBranchAddress("Mll",&Mll);

   tree_EIC_LM_ALL->SetBranchAddress("Mll",&Mll);
   tree_EIC_HM_ALL->SetBranchAddress("Mll",&Mll);


   tree_EIC_LM_BH->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_HM_BH->SetBranchAddress("Ptll",&Ptll);

   tree_EIC_LM_BH_GM0->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_HM_BH_GM0->SetBranchAddress("Ptll",&Ptll);

   tree_EIC_LM_ALL->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_HM_ALL->SetBranchAddress("Ptll",&Ptll);

   
   tree_EIC_LM_BH->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_HM_BH->SetBranchAddress("tvalue",&tvalue);

   tree_EIC_LM_BH_GM0->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_HM_BH_GM0->SetBranchAddress("tvalue",&tvalue);

   tree_EIC_LM_ALL->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_HM_ALL->SetBranchAddress("tvalue",&tvalue);


   tree_EIC_LM_BH->SetBranchAddress("thetal",&thetal);
   tree_EIC_HM_BH->SetBranchAddress("thetal",&thetal);

   tree_EIC_LM_BH_GM0->SetBranchAddress("thetal",&thetal);
   tree_EIC_HM_BH_GM0->SetBranchAddress("thetal",&thetal);

   tree_EIC_LM_ALL->SetBranchAddress("thetal",&thetal);
   tree_EIC_HM_ALL->SetBranchAddress("thetal",&thetal);


   tree_EIC_LM_BH->SetBranchAddress("phil",&phil);
   tree_EIC_HM_BH->SetBranchAddress("phil",&phil);

   tree_EIC_LM_BH_GM0->SetBranchAddress("phil",&phil);
   tree_EIC_HM_BH_GM0->SetBranchAddress("phil",&phil);

   tree_EIC_LM_ALL->SetBranchAddress("phil",&phil);
   tree_EIC_HM_ALL->SetBranchAddress("phil",&phil);

// -------------------

   
  for (Long64_t ievt=0; ievt<tree_EIC_LM_BH->GetEntries();ievt++) {
  tree_EIC_LM_BH->GetEntry(ievt);
  
  histMll_LM_BH->Fill(Mll,event_weight_LM_BH/(10.0/40.0));
  histPtll_LM_BH->Fill(Ptll,event_weight_LM_BH/(1.0/30.0));
  histtvalue_LM_BH->Fill(tvalue,tvalue*event_weight_LM_BH/(4.0/30.0));   // ,event_weight_LM_BH ,integrated_cross_section_value_LM_BH
//cout << "event_weight_LM_BH =" << event_weight_LM_BH << endl;
  histthetal_LM_BH->Fill(thetal,event_weight_LM_BH/(4.0/30.0));
  histphil_LM_BH->Fill(phil,event_weight_LM_BH/(7.0/30.0));

    }
    
    
    
  int N_b = histMll_LM_BH->GetNbinsX();
  cout <<  " N_b = " << N_b << endl;
    
  for (size_t i=1; i < N_b+1;i++) {
  
    cout <<  " histMll_LM_BH->GetBinContent(i) = " << histMll_LM_BH->GetBinContent(i) << endl;
   
  }   
  
  for(size_t i=1;  i < N_b+1; i++){
//			histPtll_LM_BH->SetBinContent(i, histMll_LM_BH->GetBinContent(i)/0.25 );
		}


  for (Long64_t ievt=0; ievt<tree_EIC_HM_BH->GetEntries();ievt++) {
  tree_EIC_HM_BH->GetEntry(ievt);
  
  histMll_HM_BH->Fill(Mll,event_weight_HM_BH/(10.0/40.0));
  histPtll_HM_BH->Fill(Ptll,event_weight_HM_BH/(1.0/30.0));
  histtvalue_HM_BH->Fill(tvalue,tvalue*event_weight_HM_BH/(4.0/30.0));  //  ,integrated_cross_section_value_HM_BH
//cout << "event_weight_HM_BH =" << event_weight_HM_BH << endl;
  histthetal_HM_BH->Fill(thetal,event_weight_HM_BH/(4.0/30.0));
  histphil_HM_BH->Fill(phil,event_weight_HM_BH/(7.0/30.0));

    }


// ------------------- 
 

  for (Long64_t ievt=0; ievt<tree_EIC_LM_BH_GM0->GetEntries();ievt++) {
  tree_EIC_LM_BH_GM0->GetEntry(ievt);

  histMll_LM_BH_GM0->Fill(Mll,event_weight_LM_BH_GM0/(10.0/40.0));
  histPtll_LM_BH_GM0->Fill(Ptll,event_weight_LM_BH_GM0/(1.0/30.0));
  histtvalue_LM_BH_GM0->Fill(tvalue,tvalue*event_weight_LM_BH_GM0/(4.0/30.0));   // ,event_weight_LM_BH_GM0 ,integrated_cross_section_value_LM_BH_GM0
//cout << "event_weight_LM_BH_GM0 =" << event_weight_LM_BH_GM0 << endl;
  histthetal_LM_BH_GM0->Fill(thetal,event_weight_LM_BH_GM0/(4.0/30.0));
  histphil_LM_BH_GM0->Fill(phil,event_weight_LM_BH_GM0/(7.0/30.0));

    }


  for (Long64_t ievt=0; ievt<tree_EIC_HM_BH_GM0->GetEntries();ievt++) {
  tree_EIC_HM_BH_GM0->GetEntry(ievt);

  histMll_HM_BH_GM0->Fill(Mll,event_weight_HM_BH_GM0/(10.0/40.0));
  histPtll_HM_BH_GM0->Fill(Ptll,event_weight_HM_BH_GM0/(1.0/30.0));
  histtvalue_HM_BH_GM0->Fill(tvalue,tvalue*event_weight_HM_BH_GM0/(4.0/30.0));  //  ,integrated_cross_section_value_HM_BH_GM0
//cout << "event_weight_HM_BH_GM0 =" << event_weight_HM_BH_GM0 << endl;
  histthetal_HM_BH_GM0->Fill(thetal,event_weight_HM_BH_GM0/(4.0/30.0));
  histphil_HM_BH_GM0->Fill(phil,event_weight_HM_BH_GM0/(7.0/30.0));

    }


// -------------------


  for (Long64_t ievt=0; ievt<tree_EIC_LM_ALL->GetEntries();ievt++) {
  tree_EIC_LM_ALL->GetEntry(ievt);

  histMll_LM_ALL->Fill(Mll,event_weight_LM_ALL/(10.0/40.0));
  histPtll_LM_ALL->Fill(Ptll,event_weight_LM_ALL/(1.0/30.0));
  histtvalue_LM_ALL->Fill(tvalue,tvalue*event_weight_LM_ALL/(4.0/30.0));   // ,event_weight_LM_ALL ,integrated_cross_section_value_LM_ALL
//cout << "event_weight_LM_ALL =" << event_weight_LM_ALL << endl;
  histthetal_LM_ALL->Fill(thetal,event_weight_LM_ALL/(4.0/30.0));
  histphil_LM_ALL->Fill(phil,event_weight_LM_ALL/(7.0/30.0));

    }


  for (Long64_t ievt=0; ievt<tree_EIC_HM_ALL->GetEntries();ievt++) {
  tree_EIC_HM_ALL->GetEntry(ievt);

  histMll_HM_ALL->Fill(Mll,event_weight_HM_ALL/(10.0/40.0));
  histPtll_HM_ALL->Fill(Ptll,event_weight_HM_ALL/(1.0/30.0));
  histtvalue_HM_ALL->Fill(tvalue,tvalue*event_weight_HM_ALL/(4.0/30.0));  //  ,integrated_cross_section_value_HM_ALL
//cout << "event_weight_HM_ALL =" << event_weight_HM_ALL << endl;
  histthetal_HM_ALL->Fill(thetal,event_weight_HM_ALL/(4.0/30.0));
  histphil_HM_ALL->Fill(phil,event_weight_HM_ALL/(7.0/30.0));

    }





// -------------------




 
 
Double_t xl1=0.750, yl1=0.720, xl2=xl1+0.150, yl2=yl1+0.150;

TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
leg->SetBorderSize(0);

leg->AddEntry(histMll_LM_BH,"BH LM","L")->SetTextColor(2);
leg->AddEntry(histMll_HM_BH,"BH HM","L")->SetTextColor(6);

leg->SetTextSize(0.032);
leg->SetTextFont(12);
leg->SetFillStyle(0);






//    (#sqrt{s} = 365 GeV, L_{int} = 1.5 ab^{-1})    1.5 ab^{-1} (365 GeV)

TLatex *t2a = new TLatex(0.5,0.9,"#bf{Electron-Ion Collider (EIC)}");
                t2a->SetNDC();
                t2a->SetTextFont(42);
                t2a->SetTextSize(0.04);
                t2a->SetTextAlign(20);

                
TLatex *t3a = new TLatex(0.3,0.83,"E_{e} = 18 GeV; E_{p} = 275 GeV");
                t3a->SetNDC();
                t3a->SetTextFont(42);
                t3a->SetTextSize(0.04);
                t3a->SetTextAlign(20);
                
            
TLatex *t4a = new TLatex(0.276,0.80,"E_{p} = 275 GeV");
                t4a->SetNDC();
                t4a->SetTextFont(42);
                t4a->SetTextSize(0.04);
                t4a->SetTextAlign(20);


TLatex *t5a = new TLatex(0.58,0.66,"#gamma-tagged (low & high mass sample)");
                t5a->SetNDC();
                t5a->SetTextFont(12);
                t5a->SetTextSize(0.04);
                t5a->SetTextAlign(20);
                
TLatex *t6a = new TLatex(0.692,0.61,"hadron_polarisation = 0|0|1");
                t6a->SetNDC();
                t6a->SetTextFont(12);
                t6a->SetTextSize(0.04);
                t6a->SetTextAlign(20);
                
TLatex *t2b = new TLatex(0.70,0.60,"0.5<E'_{e}/E_{e}<0.9 & #pi-#theta_{e}<10 mrad");
                t2b->SetNDC();
                t2b->SetTextFont(12);
                t2b->SetTextSize(0.04);
                t2b->SetTextAlign(20);

                
TLatex *t3b = new TLatex(0.64,0.55,"x_{L}<0.97 || p_{T}^{p}>100 Mev");
                t3b->SetNDC();
                t3b->SetTextFont(12);
                t3b->SetTextSize(0.04);
                t3b->SetTextAlign(20);
                
                
TLatex *t4b = new TLatex(0.58,0.5,"#theta_{p}<13 mrad");
                t4b->SetNDC();
                t4b->SetTextFont(12);
                t4b->SetTextSize(0.04);
                t4b->SetTextAlign(20);
                
                
TLatex *t5b = new TLatex(0.65,0.45,"p_{T}^{#mu}>300 MeV & |#eta_{#mu}|<3.5");
                t5b->SetNDC();
                t5b->SetTextFont(12);
                t5b->SetTextSize(0.04);
                t5b->SetTextAlign(20);





// --------------------
// --------------------



TCanvas* c1BH = new TCanvas("c1BH","Massdilepton", 10, 10, 900, 700);

//histMll_LM_BH->SetTitle("m_{ll}");
histMll_LM_BH->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
histMll_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histMll_LM_BH->GetXaxis()->SetLabelFont(22);
histMll_LM_BH->GetXaxis()->SetTitleFont(22);
histMll_LM_BH->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
histMll_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histMll_LM_BH->GetYaxis()->SetLabelFont(22);
histMll_LM_BH->GetYaxis()->SetTitleFont(22);

   histMll_LM_BH->GetYaxis()->SetRangeUser(0.1,10000);
//   histMll_LM_BH->GetXaxis()->SetRangeUser(0,1);

   histMll_LM_BH->SetLineWidth(4);
   histMll_HM_BH->SetLineWidth(4);
   
   histMll_LM_BH->SetLineColor(2);
   histMll_HM_BH->SetLineColor(6);

   histMll_LM_BH->Draw("hist");
   histMll_HM_BH->Draw("hist same");
   
   cout << "Integral histMll_LM_BH = "  <<  histMll_LM_BH->Integral()/4.0 << endl;
   
   c1BH->SetLogy(1);
//   c1BH->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");  
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");
  
 
//c1BH->SaveAs("Mll_tagged_Qprime10_Compare.pdf");
//c1BH->SaveAs("Mll_tagged_Qprime10_Compare.C");
//c1BH->SaveAs("Mll_tagged_Qprime10_Compare.eps");
//c1BH->SaveAs("Mll_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasMll_BH = new TCanvas("canvasMll_BH", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Mll_BH = (TH1F*)histMll_LM_BH->Clone(); // Clone histMll_LM_BH to keep the original histogram
resultHist_Mll_BH->Add(histMll_HM_BH);


Double_t xl3=0.70, yl3=0.70, xl4=xl3+0.150, yl4=yl3+0.150;

TLegend *leg2 = new TLegend(xl3,yl3,xl4,yl4);
leg2->SetBorderSize(0);

leg2->AddEntry(resultHist_Mll_BH,"BH (LM+HM)","L")->SetTextColor(2);


leg2->SetTextSize(0.032);
leg2->SetTextFont(12);
leg2->SetFillStyle(0);


resultHist_Mll_BH->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
resultHist_Mll_BH->GetXaxis()->SetTitleOffset(1.25);
resultHist_Mll_BH->GetXaxis()->SetLabelFont(22);
resultHist_Mll_BH->GetXaxis()->SetTitleFont(22);
resultHist_Mll_BH->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Mll_BH->GetYaxis()->SetTitleOffset(1.40);
resultHist_Mll_BH->GetYaxis()->SetLabelFont(22);
resultHist_Mll_BH->GetYaxis()->SetTitleFont(22);

resultHist_Mll_BH->Draw("hist");


cout << "Integral resultHist_Mll_BH = "  <<  resultHist_Mll_BH->Integral()/4.0 << endl;


 leg2->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasMll_BH->Update();
//delete canvas;
//canvasMll_BH->SaveAs("Mll_tagged_LM_HM_BH.pdf");




// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c1BH_GM0 = new TCanvas("c1BH_GM0","Massdilepton", 10, 10, 900, 700);

//histMll_LM_BH_GM0->SetTitle("m_{ll}");
histMll_LM_BH_GM0->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
histMll_LM_BH_GM0->GetXaxis()->SetTitleOffset(1.25);
histMll_LM_BH_GM0->GetXaxis()->SetLabelFont(22);
histMll_LM_BH_GM0->GetXaxis()->SetTitleFont(22);
histMll_LM_BH_GM0->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
histMll_LM_BH_GM0->GetYaxis()->SetTitleOffset(1.40);
histMll_LM_BH_GM0->GetYaxis()->SetLabelFont(22);
histMll_LM_BH_GM0->GetYaxis()->SetTitleFont(22);

   histMll_LM_BH_GM0->GetYaxis()->SetRangeUser(0.1,10000);
//   histMll_LM_BH_GM0->GetXaxis()->SetRangeUser(0,1);

   histMll_LM_BH_GM0->SetLineWidth(4);
   histMll_HM_BH_GM0->SetLineWidth(4);

   histMll_LM_BH_GM0->SetLineColor(2);
   histMll_HM_BH_GM0->SetLineColor(6);

   histMll_LM_BH_GM0->Draw("hist");
   histMll_HM_BH_GM0->Draw("hist same");

   cout << "Integral histMll_LM_BH_GM0 = "  <<  histMll_LM_BH_GM0->Integral()/4.0 << endl;

   c1BH_GM0->SetLogy(1);
//   c1BH_GM0->SetLogx(1);

// leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


//c1BH_GM0->SaveAs("Mll_tagged_Qprime10_Compare.pdf");
//c1BH_GM0->SaveAs("Mll_tagged_Qprime10_Compare.C");
//c1BH_GM0->SaveAs("Mll_tagged_Qprime10_Compare.eps");
//c1BH_GM0->SaveAs("Mll_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasMll_BH_GM0 = new TCanvas("canvasMll_BH_GM0", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Mll_BH_GM0 = (TH1F*)histMll_LM_BH_GM0->Clone(); // Clone histMll_LM_BH_GM0 to keep the original histogram
resultHist_Mll_BH_GM0->Add(histMll_HM_BH_GM0);

leg2->AddEntry(resultHist_Mll_BH_GM0,"BH_GM0 (LM+HM)","L")->SetTextColor(4);

resultHist_Mll_BH_GM0->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
resultHist_Mll_BH_GM0->GetXaxis()->SetTitleOffset(1.25);
resultHist_Mll_BH_GM0->GetXaxis()->SetLabelFont(22);
resultHist_Mll_BH_GM0->GetXaxis()->SetTitleFont(22);
resultHist_Mll_BH_GM0->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Mll_BH_GM0->GetYaxis()->SetTitleOffset(1.40);
resultHist_Mll_BH_GM0->GetYaxis()->SetLabelFont(22);
resultHist_Mll_BH_GM0->GetYaxis()->SetTitleFont(22);


resultHist_Mll_BH_GM0->GetYaxis()->SetRangeUser(0.1,200);


resultHist_Mll_BH_GM0->SetLineColor(4);

resultHist_Mll_BH_GM0->Draw("hist");
resultHist_Mll_BH->Draw("hist same");

cout << "Integral resultHist_Mll_BH_GM0 = "  <<  resultHist_Mll_BH_GM0->Integral()/4.0 << endl;

 canvasMll_BH_GM0->SetLogy(1);

 leg2->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasMll_BH_GM0->Update();
//delete canvas;
canvasMll_BH_GM0->SaveAs("Mll_tagged_LM_HM_BH_BH_GM0.pdf");







// --------------------
// --------------------






TCanvas* c2BH = new TCanvas("c2BH","Ptdilepton", 10, 10, 900, 700);

//histPtll_LM_BH->SetTitle("m_{ll}");
histPtll_LM_BH->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
histPtll_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histPtll_LM_BH->GetXaxis()->SetLabelFont(22);
histPtll_LM_BH->GetXaxis()->SetTitleFont(22);
histPtll_LM_BH->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
histPtll_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histPtll_LM_BH->GetYaxis()->SetLabelFont(22);
histPtll_LM_BH->GetYaxis()->SetTitleFont(22);

   histPtll_LM_BH->GetYaxis()->SetRangeUser(0.1,1000000);
//   histPtll_LM_BH->GetXaxis()->SetRangeUser(0,1);

   histPtll_LM_BH->SetLineWidth(4);
   histPtll_HM_BH->SetLineWidth(4);

   histPtll_LM_BH->SetLineColor(2);
   histPtll_HM_BH->SetLineColor(6);

   histPtll_LM_BH->Draw("hist");
   histPtll_HM_BH->Draw("hist same");
   
   c2BH->SetLogy(1);
//   c2BH->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");
 
 
//c2BH->SaveAs("Ptll_tagged_Qprime10_Compare.pdf");
//c2BH->SaveAs("ptll_tagged_Qprime10_Compare.C");
//c2BH->SaveAs("ptll_tagged_Qprime10_Compare.eps");
//c2BH->SaveAs("ptll_tagged_Qprime10_Compare.root");





// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasPtll_BH = new TCanvas("canvasPtll_BH", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Ptll_BH = (TH1F*)histPtll_LM_BH->Clone(); // Clone histPtll_LM_BH to keep the original histogram
resultHist_Ptll_BH->Add(histPtll_HM_BH);


Double_t xl5=0.70, yl5=0.70, xl6=xl5+0.150, yl6=yl5+0.150;

TLegend *leg3 = new TLegend(xl5,yl5,xl6,yl6);
leg3->SetBorderSize(0);

leg3->AddEntry(resultHist_Ptll_BH,"BH (LM+HM)","L")->SetTextColor(2);

leg3->SetTextSize(0.032);
leg3->SetTextFont(12);
leg3->SetFillStyle(0);


resultHist_Ptll_BH->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
resultHist_Ptll_BH->GetXaxis()->SetTitleOffset(1.25);
resultHist_Ptll_BH->GetXaxis()->SetLabelFont(22);
resultHist_Ptll_BH->GetXaxis()->SetTitleFont(22);
resultHist_Ptll_BH->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Ptll_BH->GetYaxis()->SetTitleOffset(1.40);
resultHist_Ptll_BH->GetYaxis()->SetLabelFont(22);
resultHist_Ptll_BH->GetYaxis()->SetTitleFont(22);

resultHist_Ptll_BH->Draw("hist");


cout << "Integral resultHist_Ptll_BH = "  <<  resultHist_Ptll_BH->Integral()/4.0 << endl;


 leg3->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasPtll_BH->Update();
//delete canvas;
//canvasPtll_BH->SaveAs("Ptll_tagged_LM_HM_BH.pdf");



// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c2BH_GM0 = new TCanvas("c2BH_GM0","Ptdilepton", 10, 10, 900, 700);

//histPtll_LM_BH_GM0->SetTitle("m_{ll}");
histPtll_LM_BH_GM0->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
histPtll_LM_BH_GM0->GetXaxis()->SetTitleOffset(1.25);
histPtll_LM_BH_GM0->GetXaxis()->SetLabelFont(22);
histPtll_LM_BH_GM0->GetXaxis()->SetTitleFont(22);
histPtll_LM_BH_GM0->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
histPtll_LM_BH_GM0->GetYaxis()->SetTitleOffset(1.40);
histPtll_LM_BH_GM0->GetYaxis()->SetLabelFont(22);
histPtll_LM_BH_GM0->GetYaxis()->SetTitleFont(22);

   histPtll_LM_BH_GM0->GetYaxis()->SetRangeUser(0.1,10000);
//   histPtll_LM_BH_GM0->GetXaxis()->SetRangeUser(0,1);

   histPtll_LM_BH_GM0->SetLineWidth(4);
   histPtll_HM_BH_GM0->SetLineWidth(4);

   histPtll_LM_BH_GM0->SetLineColor(2);
   histPtll_HM_BH_GM0->SetLineColor(6);

   histPtll_LM_BH_GM0->Draw("hist");
   histPtll_HM_BH_GM0->Draw("hist same");

   cout << "Integral histPtll_LM_BH_GM0 = "  <<  histPtll_LM_BH_GM0->Integral()/4.0 << endl;

   c2BH_GM0->SetLogy(1);
//   c2BH_GM0->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


//c2BH_GM0->SaveAs("Ptll_tagged_Qprime10_Compare.pdf");
//c2BH_GM0->SaveAs("Ptll_tagged_Qprime10_Compare.C");
//c2BH_GM0->SaveAs("Ptll_tagged_Qprime10_Compare.eps");
//c2BH_GM0->SaveAs("Ptll_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasPtll_BH_GM0 = new TCanvas("canvasPtll_BH_GM0", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Ptll_BH_GM0 = (TH1F*)histPtll_LM_BH_GM0->Clone(); // Clone histPtll_LM_BH_GM0 to keep the original histogram
resultHist_Ptll_BH_GM0->Add(histPtll_HM_BH_GM0);

leg3->AddEntry(resultHist_Ptll_BH_GM0,"BH_GM0 (LM+HM)","L")->SetTextColor(2);

resultHist_Ptll_BH_GM0->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
resultHist_Ptll_BH_GM0->GetXaxis()->SetTitleOffset(1.25);
resultHist_Ptll_BH_GM0->GetXaxis()->SetLabelFont(22);
resultHist_Ptll_BH_GM0->GetXaxis()->SetTitleFont(22);
resultHist_Ptll_BH_GM0->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Ptll_BH_GM0->GetYaxis()->SetTitleOffset(1.40);
resultHist_Ptll_BH_GM0->GetYaxis()->SetLabelFont(22);
resultHist_Ptll_BH_GM0->GetYaxis()->SetTitleFont(22);


resultHist_Ptll_BH_GM0->GetYaxis()->SetRangeUser(0.1,1000);


resultHist_Ptll_BH_GM0->SetLineColor(4);

resultHist_Ptll_BH_GM0->Draw("hist");
resultHist_Ptll_BH->Draw("hist same");

cout << "Integral resultHist_Ptll_BH_GM0 = "  <<  resultHist_Ptll_BH_GM0->Integral()/4.0 << endl;

 canvasPtll_BH_GM0->SetLogy(1);

 leg2->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasPtll_BH_GM0->Update();
//delete canvas;
canvasPtll_BH_GM0->SaveAs("Ptll_tagged_LM_HM_BH_BH_GM0.pdf");






// --------------------
// --------------------
// --------------------





TCanvas* c3 = new TCanvas("c3","tvalue", 10, 10, 900, 700);

//histtvalue_LM_BH->SetTitle("m_{ll}");
histtvalue_LM_BH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histtvalue_LM_BH->GetXaxis()->SetLabelFont(22);
histtvalue_LM_BH->GetXaxis()->SetTitleFont(22);
histtvalue_LM_BH->GetYaxis()->SetTitle("Events normalised to unit area");  // d#sigma/d|t| [pb]
histtvalue_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histtvalue_LM_BH->GetYaxis()->SetLabelFont(22);
histtvalue_LM_BH->GetYaxis()->SetTitleFont(22);

//   histtvalue_LM_BH->GetXaxis()->SetRangeUser(0,8000);
//   histtvalue_LM_BH->GetXaxis()->SetRangeUser(0,1);

   histtvalue_LM_BH->SetLineWidth(3);
   histtvalue_HM_BH->SetLineWidth(3);

   histtvalue_LM_BH->SetLineColor(2);
   histtvalue_HM_BH->SetLineColor(6);

   histtvalue_LM_BH->DrawNormalized("hist");
   histtvalue_HM_BH->DrawNormalized("hist same");

   c3->SetLogy(1);
//   c3->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");
 

// c3->SaveAs("t-value_conf_099_Final_Compare.pdf");
//c3->SaveAs("t-value.C");
//c3->SaveAs("t-value.eps");
//c3->SaveAs("t-value.root");









// --------------------





TCanvas* c4BH = new TCanvas("c4BH","tvalue", 10, 10, 900, 700);

//histtvalue_LM_BH->SetTitle("m_{ll}");
histtvalue_LM_BH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histtvalue_LM_BH->GetXaxis()->SetLabelFont(22);
histtvalue_LM_BH->GetXaxis()->SetTitleFont(22);
histtvalue_LM_BH->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");  // d#sigma/d|t| [pb]
histtvalue_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histtvalue_LM_BH->GetYaxis()->SetLabelFont(22);
histtvalue_LM_BH->GetYaxis()->SetTitleFont(22);

//   histtvalue_LM_BH->GetYaxis()->SetRangeUser(0,50000);
//   histtvalue_LM_BH->GetXaxis()->SetRangeUser(0,1);

   histtvalue_LM_BH->SetLineWidth(3);
   histtvalue_HM_BH->SetLineWidth(3);

   histtvalue_LM_BH->SetLineColor(2);
   histtvalue_HM_BH->SetLineColor(6);

   histtvalue_LM_BH->Draw("ep");
   histtvalue_HM_BH->Draw("ep same");

     c4BH->SetLogy(1);
//   c4BH->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");
 

//c4BH->SaveAs("t_value_tagged_Qprime10_Compare.pdf");
//c4BH->SaveAs("t_value_tagged_Qprime10_Compare.C");
//c4BH->SaveAs("t_value_tagged_Qprime10_Compare.eps");
//c4BH->SaveAs("t_value_tagged_Qprime10_Compare.root");





// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvastvalue_BH = new TCanvas("canvastvalue_BH", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_tvalue_BH = (TH1F*)histtvalue_LM_BH->Clone(); // Clone histtvalue_LM_BH to keep the original histogram
resultHist_tvalue_BH->Add(histtvalue_HM_BH);


Double_t xl7=0.70, yl7=0.70, xl8=xl7+0.150, yl8=yl7+0.150;

TLegend *leg4 = new TLegend(xl7,yl7,xl8,yl8);
leg4->SetBorderSize(0);

leg4->AddEntry(resultHist_tvalue_BH,"BH (LM+HM)","L")->SetTextColor(2);

leg4->SetTextSize(0.032);
leg4->SetTextFont(12);
leg4->SetFillStyle(0);


resultHist_tvalue_BH->GetXaxis()->SetTitle("|t| [GeV^{2}]");
resultHist_tvalue_BH->GetXaxis()->SetTitleOffset(1.25);
resultHist_tvalue_BH->GetXaxis()->SetLabelFont(22);
resultHist_tvalue_BH->GetXaxis()->SetTitleFont(22);
resultHist_tvalue_BH->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");
resultHist_tvalue_BH->GetYaxis()->SetTitleOffset(1.40);
resultHist_tvalue_BH->GetYaxis()->SetLabelFont(22);
resultHist_tvalue_BH->GetYaxis()->SetTitleFont(22);

resultHist_tvalue_BH->Draw("ep");


cout << "Integral resultHist_tvalue_BH = "  <<  resultHist_tvalue_BH->Integral()/4.0 << endl;


 canvastvalue_BH->SetLogy(1);


 leg4->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvastvalue_BH->Update();
//delete canvas;
//canvastvalue_BH->SaveAs("t_value_tagged_LM_HM_BH.pdf");




// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c4BH_GM0 = new TCanvas("c4BH_GM0","tvalue", 10, 10, 900, 700);

//histtvalue_LM_BH_GM0->SetTitle("m_{ll}");
histtvalue_LM_BH_GM0->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_LM_BH_GM0->GetXaxis()->SetTitleOffset(1.25);
histtvalue_LM_BH_GM0->GetXaxis()->SetLabelFont(22);
histtvalue_LM_BH_GM0->GetXaxis()->SetTitleFont(22);
histtvalue_LM_BH_GM0->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");
histtvalue_LM_BH_GM0->GetYaxis()->SetTitleOffset(1.40);
histtvalue_LM_BH_GM0->GetYaxis()->SetLabelFont(22);
histtvalue_LM_BH_GM0->GetYaxis()->SetTitleFont(22);

   histtvalue_LM_BH_GM0->GetYaxis()->SetRangeUser(0.1,10000);
//   histtvalue_LM_BH_GM0->GetXaxis()->SetRangeUser(0,1);

   histtvalue_LM_BH_GM0->SetLineWidth(4);
   histtvalue_HM_BH_GM0->SetLineWidth(4);

   histtvalue_LM_BH_GM0->SetLineColor(2);
   histtvalue_HM_BH_GM0->SetLineColor(6);

   histtvalue_LM_BH_GM0->Draw("hist");
   histtvalue_HM_BH_GM0->Draw("hist same");

   cout << "Integral histtvalue_LM_BH_GM0 = "  <<  histtvalue_LM_BH_GM0->Integral()/4.0 << endl;

   c4BH_GM0->SetLogy(1);
//   c4BH_GM0->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


//c4BH_GM0->SaveAs("tvalue_tagged_Qprime10_Compare.pdf");
//c4BH_GM0->SaveAs("tvalue_tagged_Qprime10_Compare.C");
//c4BH_GM0->SaveAs("tvalue_tagged_Qprime10_Compare.eps");
//c4BH_GM0->SaveAs("tvalue_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvastvalue_BH_GM0 = new TCanvas("canvastvalue_BH_GM0", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_tvalue_BH_GM0 = (TH1F*)histtvalue_LM_BH_GM0->Clone(); // Clone histtvalue_LM_BH_GM0 to keep the original histogram
resultHist_tvalue_BH_GM0->Add(histtvalue_HM_BH_GM0);

leg3->AddEntry(resultHist_tvalue_BH_GM0,"BH_GM0 (LM+HM)","L")->SetTextColor(2);

resultHist_tvalue_BH_GM0->GetXaxis()->SetTitle("|t| [GeV^{2}]");
resultHist_tvalue_BH_GM0->GetXaxis()->SetTitleOffset(1.25);
resultHist_tvalue_BH_GM0->GetXaxis()->SetLabelFont(22);
resultHist_tvalue_BH_GM0->GetXaxis()->SetTitleFont(22);
resultHist_tvalue_BH_GM0->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");
resultHist_tvalue_BH_GM0->GetYaxis()->SetTitleOffset(1.40);
resultHist_tvalue_BH_GM0->GetYaxis()->SetLabelFont(22);
resultHist_tvalue_BH_GM0->GetYaxis()->SetTitleFont(22);


resultHist_tvalue_BH_GM0->GetYaxis()->SetRangeUser(0.01,100);


resultHist_tvalue_BH_GM0->SetLineColor(4);

resultHist_tvalue_BH_GM0->Draw("ep");
resultHist_tvalue_BH->Draw("ep same");

cout << "Integral resultHist_tvalue_BH_GM0 = "  <<  resultHist_tvalue_BH_GM0->Integral()/4.0 << endl;

 canvastvalue_BH_GM0->SetLogy(1);

 leg2->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvastvalue_BH_GM0->Update();
//delete canvas;
canvastvalue_BH_GM0->SaveAs("t_value_tagged_LM_HM_BH_BH_GM0.pdf");







// =======================================================================
// =======================================================================
// =======================================================================
// =======================================================================





TCanvas* c5BH = new TCanvas("c5BH","thetal", 10, 10, 900, 700);

//histthetal_LM_BH->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histthetal_LM_BH->GetXaxis()->SetTitle("#theta_{l}");
//histthetal_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histthetal_LM_BH->GetXaxis()->SetLabelFont(22);
histthetal_LM_BH->GetXaxis()->SetTitleFont(22);
histthetal_LM_BH->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
histthetal_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histthetal_LM_BH->GetYaxis()->SetLabelFont(22);
histthetal_LM_BH->GetYaxis()->SetTitleFont(22);

histthetal_LM_BH->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(thetal) ="<<histthetal_LM_BH->Integral()<<endl;

   histthetal_LM_BH->SetLineWidth(3);
   histthetal_HM_BH->SetLineWidth(3);

   histthetal_LM_BH->SetLineColor(2);
   histthetal_HM_BH->SetLineColor(6);

   histthetal_LM_BH->Draw("hist");
   histthetal_HM_BH->Draw("hist same");



 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");

 c5BH->SetLogy(1);


//c5BH->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c5BH->SaveAs("thetal_tagged_Qprime10_Compare.C");
//c5BH->SaveAs("thetal_tagged_Qprime10_Compare.eps");
//c5BH->SaveAs("thetal_tagged_Qprime10_Compare.root");
//c5BH->SaveAs("thetal_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasthetal_BH = new TCanvas("canvasthetal_BH", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_thetal_BH = (TH1F*)histthetal_LM_BH->Clone(); // Clone histtvalue_LM_BH to keep the original histogram
resultHist_thetal_BH->Add(histthetal_HM_BH);


Double_t xl9=0.70, yl9=0.70, xl10=xl9+0.150, yl10=yl9+0.150;

TLegend *leg5 = new TLegend(xl9,yl9,xl10,yl10);
leg5->SetBorderSize(0);

leg5->AddEntry(resultHist_thetal_BH,"BH (LM+HM)","L")->SetTextColor(2);

leg5->SetTextSize(0.032);
leg5->SetTextFont(12);
leg5->SetFillStyle(0);


resultHist_thetal_BH->GetXaxis()->SetTitle("#theta_{l}");
resultHist_thetal_BH->GetXaxis()->SetTitleOffset(1.25);
resultHist_thetal_BH->GetXaxis()->SetLabelFont(22);
resultHist_thetal_BH->GetXaxis()->SetTitleFont(22);
resultHist_thetal_BH->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
resultHist_thetal_BH->GetYaxis()->SetTitleOffset(1.40);
resultHist_thetal_BH->GetYaxis()->SetLabelFont(22);
resultHist_thetal_BH->GetYaxis()->SetTitleFont(22);

resultHist_thetal_BH->Draw("hist");


cout << "Integral resultHist_thetal_BH = "  <<  resultHist_thetal_BH->Integral()/4.0 << endl;


// canvasthetal_BH->SetLogy(1);


 leg5->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasthetal_BH->Update();
//delete canvas;
//canvasthetal_BH->SaveAs("thetal_tagged_LM_HM_BH.pdf");





// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c5BH_GM0 = new TCanvas("c5BH_GM0","thetal", 10, 10, 900, 700);

//histthetal_LM_BH_GM0->SetTitle("m_{ll}");
histthetal_LM_BH_GM0->GetXaxis()->SetTitle("#theta_{l}");
histthetal_LM_BH_GM0->GetXaxis()->SetTitleOffset(1.25);
histthetal_LM_BH_GM0->GetXaxis()->SetLabelFont(22);
histthetal_LM_BH_GM0->GetXaxis()->SetTitleFont(22);
histthetal_LM_BH_GM0->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
histthetal_LM_BH_GM0->GetYaxis()->SetTitleOffset(1.40);
histthetal_LM_BH_GM0->GetYaxis()->SetLabelFont(22);
histthetal_LM_BH_GM0->GetYaxis()->SetTitleFont(22);

   histthetal_LM_BH_GM0->GetYaxis()->SetRangeUser(0.1,10000);
//   histthetal_LM_BH_GM0->GetXaxis()->SetRangeUser(0,1);

   histthetal_LM_BH_GM0->SetLineWidth(4);
   histthetal_HM_BH_GM0->SetLineWidth(4);

   histthetal_LM_BH_GM0->SetLineColor(2);
   histthetal_HM_BH_GM0->SetLineColor(6);

   histthetal_LM_BH_GM0->Draw("hist");
   histthetal_HM_BH_GM0->Draw("hist same");

   cout << "Integral histthetal_LM_BH_GM0 = "  <<  histthetal_LM_BH_GM0->Integral()/4.0 << endl;

   c5BH_GM0->SetLogy(1);
//   c5BH_GM0->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


//c5BH_GM0->SaveAs("thetal_tagged_Qprime10_Compare.pdf");
//c5BH_GM0->SaveAs("thetal_tagged_Qprime10_Compare.C");
//c5BH_GM0->SaveAs("thetal_tagged_Qprime10_Compare.eps");
//c5BH_GM0->SaveAs("thetal_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasthetal_BH_GM0 = new TCanvas("canvasthetal_BH_GM0", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_thetal_BH_GM0 = (TH1F*)histthetal_LM_BH_GM0->Clone(); // Clone histthetal_LM_BH_GM0 to keep the original histogram
resultHist_thetal_BH_GM0->Add(histthetal_HM_BH_GM0);

leg5->AddEntry(resultHist_thetal_BH_GM0,"BH_GM0 (LM+HM)","L")->SetTextColor(2);

resultHist_thetal_BH_GM0->GetXaxis()->SetTitle("#theta_{l}");
resultHist_thetal_BH_GM0->GetXaxis()->SetTitleOffset(1.25);
resultHist_thetal_BH_GM0->GetXaxis()->SetLabelFont(22);
resultHist_thetal_BH_GM0->GetXaxis()->SetTitleFont(22);
resultHist_thetal_BH_GM0->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
resultHist_thetal_BH_GM0->GetYaxis()->SetTitleOffset(1.40);
resultHist_thetal_BH_GM0->GetYaxis()->SetLabelFont(22);
resultHist_thetal_BH_GM0->GetYaxis()->SetTitleFont(22);


resultHist_thetal_BH_GM0->GetYaxis()->SetRangeUser(0.1,100);


resultHist_thetal_BH_GM0->SetLineColor(4);

resultHist_thetal_BH_GM0->Draw("hist");
resultHist_thetal_BH->Draw("hist same");

cout << "Integral resultHist_thetal_BH_GM0 = "  <<  resultHist_thetal_BH_GM0->Integral()/4.0 << endl;

 canvasthetal_BH_GM0->SetLogy(1);

 leg2->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasthetal_BH_GM0->Update();
//delete canvas;
//canvasthetal_BH_GM0->SaveAs("thetal_tagged_LM_HM_BH_BH_GM0.pdf");









// =======================================================================





TCanvas* c6 = new TCanvas("c6","phil", 10, 10, 900, 700);

//histphil_LM_BH->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histphil_LM_BH->GetXaxis()->SetTitle("#phi_{l}");
//histphil_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histphil_LM_BH->GetXaxis()->SetLabelFont(22);
histphil_LM_BH->GetXaxis()->SetTitleFont(22);
histphil_LM_BH->GetYaxis()->SetTitle("d#sigma/d#phi_{l}");
histphil_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histphil_LM_BH->GetYaxis()->SetLabelFont(22);
histphil_LM_BH->GetYaxis()->SetTitleFont(22);

histphil_LM_BH->GetYaxis()->SetRangeUser(0.1,100);


 cout<<"Integral(phil) ="<<histphil_LM_BH->Integral()<<endl;

   histphil_LM_BH->SetLineWidth(3);
   histphil_HM_BH->SetLineWidth(3);

   histphil_LM_BH->SetLineColor(2);
   histphil_HM_BH->SetLineColor(6);

   histphil_LM_BH->Draw("hist");
   histphil_HM_BH->Draw("hist same");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");

 c6->SetLogy(1);


//c6->SaveAs("phil_tagged_Qprime10_Compare.pdf");
//c6->SaveAs("thetal_tagged_Qprime10_Compare.C");
//c6->SaveAs("thetal_tagged_Qprime10_Compare.eps");
//c6->SaveAs("thetal_tagged_Qprime10_Compare.root");
//c6->SaveAs("thetal_tagged_Qprime10_Compare.jpg");






}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
