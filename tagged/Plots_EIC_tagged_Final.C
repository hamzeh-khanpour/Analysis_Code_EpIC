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

   Float_t etal = 0;
   Float_t q2 = 0;
   Float_t q2prime = 0;


   int n_signal_BH_LM  = 0.0;
   int n_signal_TCS_LM = 0.0;
   int n_signal_BH_HM  = 0.0;
   int n_signal_TCS_HM = 0.0;

   Float_t PI = 3.14159;


   Float_t  nentries = 0;
   Float_t  integrated_luminosity = 0;

   Float_t  integrated_cross_section_value_LM_BH = 0;
   Float_t  integrated_cross_section_value_HM_BH = 0;

   Float_t  integrated_cross_section_value_LM_TCS = 0;
   Float_t  integrated_cross_section_value_HM_TCS = 0;

   Float_t  integrated_cross_section_value_LM_ALL = 0;
   Float_t  integrated_cross_section_value_HM_ALL = 0;
   
   Float_t  event_weight_LM_BH  = 0;
   Float_t  event_weight_HM_BH  = 0;

   Float_t  event_weight_LM_TCS  = 0;
   Float_t  event_weight_HM_TCS  = 0;

   Float_t  event_weight_LM_ALL  = 0;
   Float_t  event_weight_HM_ALL  = 0;
   
//*   -----------------------------------------------

void Plots_EIC_tagged_Final(){

    
   
   Float_t  nentries = 5000000.0;
   Float_t  integrated_luminosity = 300.0 / 1000.0; // fb^{-1}



   Float_t  integrated_cross_section_value_LM_BH  = 3.355           * 1000.0;   //    nb   BH LM
   Float_t  integrated_cross_section_value_HM_BH  = 0.219293        * 1000.0;   //    nb   BH HM

   Float_t  integrated_cross_section_value_LM_TCS  = 0.00207609     * 1000.0;   //    nb   TCS LM
   Float_t  integrated_cross_section_value_HM_TCS  = 0.0000504905   * 1000.0;   //    nb   TCS HM

   Float_t  integrated_cross_section_value_LM_ALL  = 3.79989        * 1000.0;   //    nb   ALL LM
   Float_t  integrated_cross_section_value_HM_ALL  = 0.247091       * 1000.0;   //    nb   ALL HM

   
   Float_t  event_weight_LM_BH  = integrated_cross_section_value_LM_BH  * 1.0 / nentries;
   Float_t  event_weight_HM_BH  = integrated_cross_section_value_HM_BH  * 1.0 / nentries;

   Float_t  event_weight_LM_TCS  = integrated_cross_section_value_LM_TCS  * 1.0 / nentries;
   Float_t  event_weight_HM_TCS  = integrated_cross_section_value_HM_TCS  * 1.0 / nentries;
    
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

TH1 *histetal_LM_BH         =  new TH1F("etal", "",    30, -3.0, 3.0);
TH1 *histetal_HM_BH         =  new TH1F("etal", "",    30, -3.0, 3.0);

TH1 *histq2_LM_BH           =  new TH1F("q2", "",      30, 0.0, 0.01);
TH1 *histq2_HM_BH           =  new TH1F("q2", "",      30, 0.0, 0.01);

TH1 *histq2prime_LM_BH           =  new TH1F("q2prime", "",      30, 1.0, 1000.0);
TH1 *histq2prime_HM_BH           =  new TH1F("q2prime", "",      30, 1.0, 1000.0);



TH1F * histMll_LM_TCS  = new TH1F ("Mll", "", 40, 0.0, 10.0);
TH1F * histMll_HM_TCS = new TH1F ("Mll", "", 40, 0.0, 10.0);

TH1F * histPtll_LM_TCS  = new TH1F ("Ptll", "",  30, 0.0, 1.0);
TH1F * histPtll_HM_TCS = new TH1F ("Ptll", "", 30, 0.0, 1.0);

TH1F * histtvalue_LM_TCS  = new TH1F ("tvalue", "",  30, 0.0, 4.0);
TH1F * histtvalue_HM_TCS = new TH1F ("tvalue", "", 30, 0.0, 4.0);

TH1F * histthetal_LM_TCS  = new TH1F ("thetal", "",  30, 0.0, 4.0);
TH1F * histthetal_HM_TCS = new TH1F ("thetal", "", 30, 0.0, 4.0);

TH1F * histphil_LM_TCS  = new TH1F ("phil", "",  30, 0.0, 7.0);
TH1F * histphil_HM_TCS = new TH1F ("phil", "", 30, 0.0, 7.0);

TH1 *histetal_LM_TCS         =  new TH1F("etal", "",    30, -3.0, 3.0);
TH1 *histetal_HM_TCS         =  new TH1F("etal", "",    30, -3.0, 3.0);

TH1 *histq2_LM_TCS           =  new TH1F("q2", "",      30, 0.0, 0.01);
TH1 *histq2_HM_TCS           =  new TH1F("q2", "",      30, 0.0, 0.01);

TH1 *histq2prime_LM_TCS           =  new TH1F("q2prime", "",      30, 1.0, 1000.0);
TH1 *histq2prime_HM_TCS           =  new TH1F("q2prime", "",      30, 1.0, 1000.0);



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

TH1 *histetal_LM_ALL         =  new TH1F("etal", "",    30, -3.0, 3.0);
TH1 *histetal_HM_ALL         =  new TH1F("etal", "",    30, -3.0, 3.0);

TH1 *histq2_LM_ALL           =  new TH1F("q2", "",      30, 0.0, 0.01);
TH1 *histq2_HM_ALL           =  new TH1F("q2", "",      30, 0.0, 0.01);

TH1 *histq2prime_LM_ALL           =  new TH1F("q2prime", "",      30, 1.0, 1000.0);
TH1 *histq2prime_HM_ALL           =  new TH1F("q2prime", "",      30, 1.0, 1000.0);



// ============================================

   TFile *file;
   TTree *tree_EIC_LM_BH;
   TTree *tree_EIC_HM_BH;

   TTree *tree_EIC_LM_TCS;
   TTree *tree_EIC_HM_TCS;

   TTree *tree_EIC_LM_ALL;
   TTree *tree_EIC_HM_ALL;


   file = TFile::Open("EIC_tagged.root");

 
   tree_EIC_LM_BH  = (TTree*)file->Get("EIC_BH_LM");
   tree_EIC_HM_BH  = (TTree*)file->Get("EIC_BH_HM");

   tree_EIC_LM_TCS  = (TTree*)file->Get("EIC_TCS_LM");
   tree_EIC_HM_TCS  = (TTree*)file->Get("EIC_TCS_HM");

   tree_EIC_LM_ALL  = (TTree*)file->Get("EIC_ALL_LM");
   tree_EIC_HM_ALL  = (TTree*)file->Get("EIC_ALL_HM");


   cout << "tree Entries tree_EIC_LM_BH  == " << tree_EIC_LM_BH->GetEntries() << endl;
   cout << "tree Entries tree_EIC_HM_BH  == " << tree_EIC_HM_BH->GetEntries() << endl;

   cout << "tree Entries tree_EIC_LM_TCS  == " << tree_EIC_LM_TCS->GetEntries() << endl;
   cout << "tree Entries tree_EIC_HM_TCS  == " << tree_EIC_HM_TCS->GetEntries() << endl;

   cout << "tree Entries tree_EIC_LM_ALL  == " << tree_EIC_LM_ALL->GetEntries() << endl;
   cout << "tree Entries tree_EIC_HM_ALL  == " << tree_EIC_HM_ALL->GetEntries() << endl;

      
   tree_EIC_LM_BH->SetBranchAddress("Mll",&Mll);
   tree_EIC_HM_BH->SetBranchAddress("Mll",&Mll);

   tree_EIC_LM_TCS->SetBranchAddress("Mll",&Mll);
   tree_EIC_HM_TCS->SetBranchAddress("Mll",&Mll);

   tree_EIC_LM_ALL->SetBranchAddress("Mll",&Mll);
   tree_EIC_HM_ALL->SetBranchAddress("Mll",&Mll);


   tree_EIC_LM_BH->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_HM_BH->SetBranchAddress("Ptll",&Ptll);

   tree_EIC_LM_TCS->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_HM_TCS->SetBranchAddress("Ptll",&Ptll);

   tree_EIC_LM_ALL->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_HM_ALL->SetBranchAddress("Ptll",&Ptll);

   
   tree_EIC_LM_BH->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_HM_BH->SetBranchAddress("tvalue",&tvalue);

   tree_EIC_LM_TCS->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_HM_TCS->SetBranchAddress("tvalue",&tvalue);

   tree_EIC_LM_ALL->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_HM_ALL->SetBranchAddress("tvalue",&tvalue);


   tree_EIC_LM_BH->SetBranchAddress("thetal",&thetal);
   tree_EIC_HM_BH->SetBranchAddress("thetal",&thetal);

   tree_EIC_LM_TCS->SetBranchAddress("thetal",&thetal);
   tree_EIC_HM_TCS->SetBranchAddress("thetal",&thetal);

   tree_EIC_LM_ALL->SetBranchAddress("thetal",&thetal);
   tree_EIC_HM_ALL->SetBranchAddress("thetal",&thetal);


   tree_EIC_LM_BH->SetBranchAddress("phil",&phil);
   tree_EIC_HM_BH->SetBranchAddress("phil",&phil);

   tree_EIC_LM_TCS->SetBranchAddress("phil",&phil);
   tree_EIC_HM_TCS->SetBranchAddress("phil",&phil);

   tree_EIC_LM_ALL->SetBranchAddress("phil",&phil);
   tree_EIC_HM_ALL->SetBranchAddress("phil",&phil);


   tree_EIC_LM_BH->SetBranchAddress("etal",&etal);
   tree_EIC_HM_BH->SetBranchAddress("etal",&etal);

   tree_EIC_LM_TCS->SetBranchAddress("etal",&etal);
   tree_EIC_HM_TCS->SetBranchAddress("etal",&etal);

   tree_EIC_LM_ALL->SetBranchAddress("etal",&etal);
   tree_EIC_HM_ALL->SetBranchAddress("etal",&etal);


   tree_EIC_LM_BH->SetBranchAddress("q2",&q2);
   tree_EIC_HM_BH->SetBranchAddress("q2",&q2);

   tree_EIC_LM_TCS->SetBranchAddress("q2",&q2);
   tree_EIC_HM_TCS->SetBranchAddress("q2",&q2);

   tree_EIC_LM_ALL->SetBranchAddress("q2",&q2);
   tree_EIC_HM_ALL->SetBranchAddress("q2",&q2);


   tree_EIC_LM_BH->SetBranchAddress("q2prime",&q2prime);
   tree_EIC_HM_BH->SetBranchAddress("q2prime",&q2prime);

   tree_EIC_LM_TCS->SetBranchAddress("q2prime",&q2prime);
   tree_EIC_HM_TCS->SetBranchAddress("q2prime",&q2prime);

   tree_EIC_LM_ALL->SetBranchAddress("q2prime",&q2prime);
   tree_EIC_HM_ALL->SetBranchAddress("q2prime",&q2prime);


// -------------------

   
  for (Long64_t ievt=0; ievt<tree_EIC_LM_BH->GetEntries();ievt++) {
  tree_EIC_LM_BH->GetEntry(ievt);
  
  histMll_LM_BH->Fill(Mll,event_weight_LM_BH/(10.0/40.0));
  histPtll_LM_BH->Fill(Ptll,event_weight_LM_BH/(1.0/30.0));
  histtvalue_LM_BH->Fill(tvalue,tvalue*event_weight_LM_BH/(4.0/30.0));   // ,event_weight_LM_BH ,integrated_cross_section_value_LM_BH
//cout << "event_weight_LM_BH =" << event_weight_LM_BH << endl;
  histthetal_LM_BH->Fill(thetal,event_weight_LM_BH/(4.0/30.0));
  histphil_LM_BH->Fill(phil,event_weight_LM_BH/(7.0/30.0));

  histetal_LM_BH->Fill(etal,event_weight_LM_BH/(6.0/30.0));

  histq2_LM_BH->Fill(q2,event_weight_LM_BH/(0.01/30.0));
  histq2prime_LM_BH->Fill(q2prime,event_weight_LM_BH/(0.01/30.0));



  if ( thetal < PI/4.0 ||  thetal > 3.0*PI/4.0  ) {n_signal_BH_LM++;}

    }
    
  cout << "n_signal_BH_LM =" << n_signal_BH_LM  << endl;


    
//  int N_b = histMll_LM_BH->GetNbinsX();
//  cout <<  " N_b = " << N_b << endl;
    
//  for (size_t i=1; i < N_b+1;i++) {
  
//    cout <<  " histMll_LM_BH->GetBinContent(i) = " << histMll_LM_BH->GetBinContent(i) << endl;
   
//  }
  
//  for(size_t i=1;  i < N_b+1; i++){
//			histPtll_LM_BH->SetBinContent(i, histMll_LM_BH->GetBinContent(i)/0.25 );
//		}




  for (Long64_t ievt=0; ievt<tree_EIC_HM_BH->GetEntries();ievt++) {
  tree_EIC_HM_BH->GetEntry(ievt);
  
  histMll_HM_BH->Fill(Mll,event_weight_HM_BH/(10.0/40.0));
  histPtll_HM_BH->Fill(Ptll,event_weight_HM_BH/(1.0/30.0));
  histtvalue_HM_BH->Fill(tvalue,tvalue*event_weight_HM_BH/(4.0/30.0));  //  ,integrated_cross_section_value_HM_BH
//cout << "event_weight_HM_BH =" << event_weight_HM_BH << endl;
  histthetal_HM_BH->Fill(thetal,event_weight_HM_BH/(4.0/30.0));
  histphil_HM_BH->Fill(phil,event_weight_HM_BH/(7.0/30.0));

  histetal_HM_BH->Fill(etal,event_weight_HM_BH/(6.0/30.0));

  histq2_HM_BH->Fill(q2,event_weight_HM_BH/(0.01/30.0));
  histq2prime_HM_BH->Fill(q2prime,event_weight_HM_BH/(0.01/30.0));

  if ( thetal < PI/4.0 ||  thetal > 3.0*PI/4.0  ) {n_signal_BH_HM++;}

    }

  cout << "n_signal_BH_HM =" << n_signal_BH_HM  << endl;


// ------------------- 
 

  for (Long64_t ievt=0; ievt<tree_EIC_LM_TCS->GetEntries();ievt++) {
  tree_EIC_LM_TCS->GetEntry(ievt);

  histMll_LM_TCS->Fill(Mll,event_weight_LM_TCS/(10.0/40.0));
  histPtll_LM_TCS->Fill(Ptll,event_weight_LM_TCS/(1.0/30.0));
  histtvalue_LM_TCS->Fill(tvalue,tvalue*event_weight_LM_TCS/(4.0/30.0));   // ,event_weight_LM_TCS ,integrated_cross_section_value_LM_TCS
//cout << "event_weight_LM_TCS =" << event_weight_LM_TCS << endl;
  histthetal_LM_TCS->Fill(thetal,event_weight_LM_TCS/(4.0/30.0));
  histphil_LM_TCS->Fill(phil,event_weight_LM_TCS/(7.0/30.0));

  histetal_LM_TCS->Fill(etal,event_weight_LM_TCS/(6.0/30.0));

  histq2_LM_TCS->Fill(q2,event_weight_LM_TCS/(0.01/30.0));
  histq2prime_LM_TCS->Fill(q2prime,event_weight_LM_TCS/(0.01/30.0));

  if ( thetal < PI/4.0 ||  thetal > 3.0*PI/4.0  ) {n_signal_TCS_LM++;}

    }

  cout << "n_signal_TCS_LM =" << n_signal_TCS_LM  << endl;


  for (Long64_t ievt=0; ievt<tree_EIC_HM_TCS->GetEntries();ievt++) {
  tree_EIC_HM_TCS->GetEntry(ievt);

  histMll_HM_TCS->Fill(Mll,event_weight_HM_TCS/(10.0/40.0));
  histPtll_HM_TCS->Fill(Ptll,event_weight_HM_TCS/(1.0/30.0));
  histtvalue_HM_TCS->Fill(tvalue,tvalue*event_weight_HM_TCS/(4.0/30.0));  //  ,integrated_cross_section_value_HM_TCS
//cout << "event_weight_HM_TCS =" << event_weight_HM_TCS << endl;
  histthetal_HM_TCS->Fill(thetal,event_weight_HM_TCS/(4.0/30.0));
  histphil_HM_TCS->Fill(phil,event_weight_HM_TCS/(7.0/30.0));

  histetal_HM_TCS->Fill(etal,event_weight_HM_TCS/(6.0/30.0));

  histq2_HM_TCS->Fill(q2,event_weight_HM_TCS/(0.01/30.0));
  histq2prime_HM_TCS->Fill(q2prime,event_weight_HM_TCS/(0.01/30.0));

  if ( thetal < PI/4.0 ||  thetal > 3.0*PI/4.0  ) {n_signal_TCS_HM++;}

    }

  cout << "n_signal_TCS_HM =" << n_signal_TCS_HM  << endl;


// -------------------


  for (Long64_t ievt=0; ievt<tree_EIC_LM_ALL->GetEntries();ievt++) {
  tree_EIC_LM_ALL->GetEntry(ievt);

  histMll_LM_ALL->Fill(Mll,event_weight_LM_ALL/(10.0/40.0));
  histPtll_LM_ALL->Fill(Ptll,event_weight_LM_ALL/(1.0/30.0));
  histtvalue_LM_ALL->Fill(tvalue,tvalue*event_weight_LM_ALL/(4.0/30.0));   // ,event_weight_LM_ALL ,integrated_cross_section_value_LM_ALL
//cout << "event_weight_LM_ALL =" << event_weight_LM_ALL << endl;
  histthetal_LM_ALL->Fill(thetal,event_weight_LM_ALL/(4.0/30.0));
  histphil_LM_ALL->Fill(phil,event_weight_LM_ALL/(7.0/30.0));

  histetal_LM_ALL->Fill(etal,event_weight_LM_ALL/(6.0/30.0));

  histq2_LM_ALL->Fill(q2,event_weight_LM_ALL/(0.01/30.0));
  histq2prime_LM_ALL->Fill(q2prime,event_weight_LM_ALL/(0.01/30.0));


    }


  for (Long64_t ievt=0; ievt<tree_EIC_HM_ALL->GetEntries();ievt++) {
  tree_EIC_HM_ALL->GetEntry(ievt);

  histMll_HM_ALL->Fill(Mll,event_weight_HM_ALL/(10.0/40.0));
  histPtll_HM_ALL->Fill(Ptll,event_weight_HM_ALL/(1.0/30.0));
  histtvalue_HM_ALL->Fill(tvalue,tvalue*event_weight_HM_ALL/(4.0/30.0));  //  ,integrated_cross_section_value_HM_ALL
//cout << "event_weight_HM_ALL =" << event_weight_HM_ALL << endl;
  histthetal_HM_ALL->Fill(thetal,event_weight_HM_ALL/(4.0/30.0));
  histphil_HM_ALL->Fill(phil,event_weight_HM_ALL/(7.0/30.0));

  histetal_HM_ALL->Fill(etal,event_weight_HM_ALL/(6.0/30.0));

  histq2_HM_ALL->Fill(q2,event_weight_HM_ALL/(0.01/30.0));
  histq2prime_HM_ALL->Fill(q2prime,event_weight_HM_ALL/(0.01/30.0));

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
   
//   cout << "Integral histMll_LM_BH = "  <<  histMll_LM_BH->Integral()/4.0 << endl;
   
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



  if ( thetal < PI/4.0 ||  thetal > 3.0*PI/4.0  ) {
cout << "Integral resultHist_Mll_BH = "  <<  resultHist_Mll_BH->Integral()/4.0 << endl;
  }

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





//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas* c1ALL = new TCanvas("c1ALL","Massdilepton", 10, 10, 900, 700);

//histMll_LM_ALL->SetTitle("m_{ll}");
histMll_LM_ALL->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
histMll_LM_ALL->GetXaxis()->SetTitleOffset(1.25);
histMll_LM_ALL->GetXaxis()->SetLabelFont(22);
histMll_LM_ALL->GetXaxis()->SetTitleFont(22);
histMll_LM_ALL->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
histMll_LM_ALL->GetYaxis()->SetTitleOffset(1.40);
histMll_LM_ALL->GetYaxis()->SetLabelFont(22);
histMll_LM_ALL->GetYaxis()->SetTitleFont(22);

   histMll_LM_ALL->GetYaxis()->SetRangeUser(0.1,10000);
//   histMll_LM_ALL->GetXaxis()->SetRangeUser(0,1);

   histMll_LM_ALL->SetLineWidth(4);
   histMll_HM_ALL->SetLineWidth(4);

   histMll_LM_ALL->SetLineColor(2);
   histMll_HM_ALL->SetLineColor(6);

   histMll_LM_ALL->Draw("hist");
   histMll_HM_ALL->Draw("hist same");

//   cout << "Integral histMll_LM_ALL = "  <<  histMll_LM_ALL->Integral()/4.0 << endl;

   c1ALL->SetLogy(1);
//   c1ALL->SetLogx(1);

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


//c1ALL->SaveAs("Mll_tagged_Qprime10_Compare.pdf");
//c1ALL->SaveAs("Mll_tagged_Qprime10_Compare.C");
//c1ALL->SaveAs("Mll_tagged_Qprime10_Compare.eps");
//c1ALL->SaveAs("Mll_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasMll_ALL = new TCanvas("canvasMll_ALL", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Mll_ALL = (TH1F*)histMll_LM_ALL->Clone(); // Clone histMll_LM_ALL to keep the original histogram
resultHist_Mll_ALL->Add(histMll_HM_ALL);


//Double_t xl3=0.70, yl3=0.70, xl4=xl3+0.150, yl4=yl3+0.150;

//TLegend *leg2 = new TLegend(xl3,yl3,xl4,yl4);
//leg2->SetBorderSize(0);

leg2->AddEntry(resultHist_Mll_ALL,"ALL (LM+HM)","L")->SetTextColor(3);


//leg2->SetTextSize(0.032);
//leg2->SetTextFont(12);
//leg2->SetFillStyle(0);


resultHist_Mll_ALL->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
resultHist_Mll_ALL->GetXaxis()->SetTitleOffset(1.25);
resultHist_Mll_ALL->GetXaxis()->SetLabelFont(22);
resultHist_Mll_ALL->GetXaxis()->SetTitleFont(22);
resultHist_Mll_ALL->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Mll_ALL->GetYaxis()->SetTitleOffset(1.40);
resultHist_Mll_ALL->GetYaxis()->SetLabelFont(22);
resultHist_Mll_ALL->GetYaxis()->SetTitleFont(22);

resultHist_Mll_ALL->Draw("hist");



  if ( thetal < PI/4.0 ||  thetal > 3.0*PI/4.0  ) {
cout << "Integral resultHist_Mll_ALL = "  <<  resultHist_Mll_ALL->Integral()/4.0 << endl;
  }

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


canvasMll_ALL->Update();
//delete canvas;
//canvasMll_ALL->SaveAs("Mll_tagged_LM_HM_ALL.pdf");










// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c1TCS = new TCanvas("c1TCS","Massdilepton", 10, 10, 900, 700);

//histMll_LM_TCS->SetTitle("m_{ll}");
histMll_LM_TCS->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
histMll_LM_TCS->GetXaxis()->SetTitleOffset(1.25);
histMll_LM_TCS->GetXaxis()->SetLabelFont(22);
histMll_LM_TCS->GetXaxis()->SetTitleFont(22);
histMll_LM_TCS->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
histMll_LM_TCS->GetYaxis()->SetTitleOffset(1.40);
histMll_LM_TCS->GetYaxis()->SetLabelFont(22);
histMll_LM_TCS->GetYaxis()->SetTitleFont(22);

   histMll_LM_TCS->GetYaxis()->SetRangeUser(0.1,10000);
//   histMll_LM_TCS->GetXaxis()->SetRangeUser(0,1);

   histMll_LM_TCS->SetLineWidth(4);
   histMll_HM_TCS->SetLineWidth(4);

   histMll_LM_TCS->SetLineColor(2);
   histMll_HM_TCS->SetLineColor(6);

   histMll_LM_TCS->Draw("hist");
   histMll_HM_TCS->Draw("hist same");

//   cout << "Integral histMll_LM_TCS = "  <<  histMll_LM_TCS->Integral()/4.0 << endl;

   c1TCS->SetLogy(1);
//   c1TCS->SetLogx(1);

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


//c1TCS->SaveAs("Mll_tagged_Qprime10_Compare.pdf");
//c1TCS->SaveAs("Mll_tagged_Qprime10_Compare.C");
//c1TCS->SaveAs("Mll_tagged_Qprime10_Compare.eps");
//c1TCS->SaveAs("Mll_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasMll_TCS = new TCanvas("canvasMll_TCS", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Mll_TCS = (TH1F*)histMll_LM_TCS->Clone(); // Clone histMll_LM_TCS to keep the original histogram
resultHist_Mll_TCS->Add(histMll_HM_TCS);

leg2->AddEntry(resultHist_Mll_TCS,"TCS (LM+HM)","L")->SetTextColor(4);

resultHist_Mll_TCS->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
resultHist_Mll_TCS->GetXaxis()->SetTitleOffset(1.25);
resultHist_Mll_TCS->GetXaxis()->SetLabelFont(22);
resultHist_Mll_TCS->GetXaxis()->SetTitleFont(22);
resultHist_Mll_TCS->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Mll_TCS->GetYaxis()->SetTitleOffset(1.40);
resultHist_Mll_TCS->GetYaxis()->SetLabelFont(22);
resultHist_Mll_TCS->GetYaxis()->SetTitleFont(22);


resultHist_Mll_TCS->GetYaxis()->SetRangeUser(0.1,200);


resultHist_Mll_TCS->SetLineColor(4);
resultHist_Mll_ALL->SetLineColor(3);
resultHist_Mll_BH->SetLineColor(2);


resultHist_Mll_TCS->Draw("hist");
resultHist_Mll_ALL->Draw("hist same");
resultHist_Mll_BH->Draw("hist same");


  if ( thetal < PI/4.0 ||  thetal > 3.0*PI/4.0  ) {
cout << "Integral resultHist_Mll_TCS = "  <<  resultHist_Mll_TCS->Integral()/4.0 << endl;
  }


 canvasMll_TCS->SetLogy(1);

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


canvasMll_TCS->Update();
//delete canvas;
canvasMll_TCS->SaveAs("Mll_tagged_LM_HM_BH_TCS_ALL.pdf");











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


//cout << "Integral resultHist_Ptll_BH = "  <<  resultHist_Ptll_BH->Integral()/4.0 << endl;


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




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++








TCanvas* c2ALL = new TCanvas("c2ALL","Ptdilepton", 10, 10, 900, 700);

//histPtll_LM_ALL->SetTitle("m_{ll}");
histPtll_LM_ALL->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
histPtll_LM_ALL->GetXaxis()->SetTitleOffset(1.25);
histPtll_LM_ALL->GetXaxis()->SetLabelFont(22);
histPtll_LM_ALL->GetXaxis()->SetTitleFont(22);
histPtll_LM_ALL->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
histPtll_LM_ALL->GetYaxis()->SetTitleOffset(1.40);
histPtll_LM_ALL->GetYaxis()->SetLabelFont(22);
histPtll_LM_ALL->GetYaxis()->SetTitleFont(22);

   histPtll_LM_ALL->GetYaxis()->SetRangeUser(0.1,1000000);
//   histPtll_LM_ALL->GetXaxis()->SetRangeUser(0,1);

   histPtll_LM_ALL->SetLineWidth(4);
   histPtll_HM_ALL->SetLineWidth(4);

   histPtll_LM_ALL->SetLineColor(2);
   histPtll_HM_ALL->SetLineColor(6);

   histPtll_LM_ALL->Draw("hist");
   histPtll_HM_ALL->Draw("hist same");

   c2ALL->SetLogy(1);
//   c2ALL->SetLogx(1);

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


//c2ALL->SaveAs("Ptll_tagged_Qprime10_Compare.pdf");
//c2ALL->SaveAs("ptll_tagged_Qprime10_Compare.C");
//c2ALL->SaveAs("ptll_tagged_Qprime10_Compare.eps");
//c2ALL->SaveAs("ptll_tagged_Qprime10_Compare.root");





// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasPtll_ALL = new TCanvas("canvasPtll_ALL", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Ptll_ALL = (TH1F*)histPtll_LM_ALL->Clone(); // Clone histPtll_LM_ALL to keep the original histogram
resultHist_Ptll_ALL->Add(histPtll_HM_ALL);


//Double_t xl5=0.70, yl5=0.70, xl6=xl5+0.150, yl6=yl5+0.150;

//TLegend *leg3 = new TLegend(xl5,yl5,xl6,yl6);
//leg3->SetBorderSize(0);

leg3->AddEntry(resultHist_Ptll_ALL,"ALL (LM+HM)","L")->SetTextColor(2);

//leg3->SetTextSize(0.032);
//leg3->SetTextFont(12);
//leg3->SetFillStyle(0);


resultHist_Ptll_ALL->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
resultHist_Ptll_ALL->GetXaxis()->SetTitleOffset(1.25);
resultHist_Ptll_ALL->GetXaxis()->SetLabelFont(22);
resultHist_Ptll_ALL->GetXaxis()->SetTitleFont(22);
resultHist_Ptll_ALL->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Ptll_ALL->GetYaxis()->SetTitleOffset(1.40);
resultHist_Ptll_ALL->GetYaxis()->SetLabelFont(22);
resultHist_Ptll_ALL->GetYaxis()->SetTitleFont(22);

resultHist_Ptll_ALL->Draw("hist");


//cout << "Integral resultHist_Ptll_ALL = "  <<  resultHist_Ptll_ALL->Integral()/4.0 << endl;


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


canvasPtll_ALL->Update();
//delete canvas;
//canvasPtll_ALL->SaveAs("Ptll_tagged_LM_HM_ALL.pdf");







// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c2TCS = new TCanvas("c2TCS","Ptdilepton", 10, 10, 900, 700);

//histPtll_LM_TCS->SetTitle("m_{ll}");
histPtll_LM_TCS->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
histPtll_LM_TCS->GetXaxis()->SetTitleOffset(1.25);
histPtll_LM_TCS->GetXaxis()->SetLabelFont(22);
histPtll_LM_TCS->GetXaxis()->SetTitleFont(22);
histPtll_LM_TCS->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
histPtll_LM_TCS->GetYaxis()->SetTitleOffset(1.40);
histPtll_LM_TCS->GetYaxis()->SetLabelFont(22);
histPtll_LM_TCS->GetYaxis()->SetTitleFont(22);

   histPtll_LM_TCS->GetYaxis()->SetRangeUser(0.1,10000);
//   histPtll_LM_TCS->GetXaxis()->SetRangeUser(0,1);

   histPtll_LM_TCS->SetLineWidth(4);
   histPtll_HM_TCS->SetLineWidth(4);

   histPtll_LM_TCS->SetLineColor(2);
   histPtll_HM_TCS->SetLineColor(6);

   histPtll_LM_TCS->Draw("hist");
   histPtll_HM_TCS->Draw("hist same");

//   cout << "Integral histPtll_LM_TCS = "  <<  histPtll_LM_TCS->Integral()/4.0 << endl;

   c2TCS->SetLogy(1);
//   c2TCS->SetLogx(1);

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


//c2TCS->SaveAs("Ptll_tagged_Qprime10_Compare.pdf");
//c2TCS->SaveAs("Ptll_tagged_Qprime10_Compare.C");
//c2TCS->SaveAs("Ptll_tagged_Qprime10_Compare.eps");
//c2TCS->SaveAs("Ptll_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasPtll_TCS = new TCanvas("canvasPtll_TCS", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Ptll_TCS = (TH1F*)histPtll_LM_TCS->Clone(); // Clone histPtll_LM_TCS to keep the original histogram
resultHist_Ptll_TCS->Add(histPtll_HM_TCS);

leg3->AddEntry(resultHist_Ptll_TCS,"TCS (LM+HM)","L")->SetTextColor(2);

resultHist_Ptll_TCS->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
resultHist_Ptll_TCS->GetXaxis()->SetTitleOffset(1.25);
resultHist_Ptll_TCS->GetXaxis()->SetLabelFont(22);
resultHist_Ptll_TCS->GetXaxis()->SetTitleFont(22);
resultHist_Ptll_TCS->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Ptll_TCS->GetYaxis()->SetTitleOffset(1.40);
resultHist_Ptll_TCS->GetYaxis()->SetLabelFont(22);
resultHist_Ptll_TCS->GetYaxis()->SetTitleFont(22);


resultHist_Ptll_TCS->GetYaxis()->SetRangeUser(0.1,1000);


resultHist_Ptll_TCS->SetLineColor(4);
resultHist_Ptll_ALL->SetLineColor(3);
resultHist_Ptll_BH->SetLineColor(2);


resultHist_Ptll_TCS->Draw("hist");
resultHist_Ptll_BH->Draw("hist same");
resultHist_Ptll_ALL->Draw("hist same");



//cout << "Integral resultHist_Ptll_TCS = "  <<  resultHist_Ptll_TCS->Integral()/4.0 << endl;

 canvasPtll_TCS->SetLogy(1);

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


canvasPtll_TCS->Update();
//delete canvas;
canvasPtll_TCS->SaveAs("Ptll_tagged_LM_HM_BH_TCS_ALL.pdf");








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


//cout << "Integral resultHist_tvalue_BH = "  <<  resultHist_tvalue_BH->Integral()/4.0 << endl;


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





//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






TCanvas* c4ALL = new TCanvas("c4ALL","tvalue", 10, 10, 900, 700);

//histtvalue_LM_ALL->SetTitle("m_{ll}");
histtvalue_LM_ALL->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_LM_ALL->GetXaxis()->SetTitleOffset(1.25);
histtvalue_LM_ALL->GetXaxis()->SetLabelFont(22);
histtvalue_LM_ALL->GetXaxis()->SetTitleFont(22);
histtvalue_LM_ALL->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");  // d#sigma/d|t| [pb]
histtvalue_LM_ALL->GetYaxis()->SetTitleOffset(1.40);
histtvalue_LM_ALL->GetYaxis()->SetLabelFont(22);
histtvalue_LM_ALL->GetYaxis()->SetTitleFont(22);

//   histtvalue_LM_ALL->GetYaxis()->SetRangeUser(0,50000);
//   histtvalue_LM_ALL->GetXaxis()->SetRangeUser(0,1);

   histtvalue_LM_ALL->SetLineWidth(3);
   histtvalue_HM_ALL->SetLineWidth(3);

   histtvalue_LM_ALL->SetLineColor(2);
   histtvalue_HM_ALL->SetLineColor(6);

   histtvalue_LM_ALL->Draw("ep");
   histtvalue_HM_ALL->Draw("ep same");

     c4ALL->SetLogy(1);
//   c4ALL->SetLogx(1);

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


//c4ALL->SaveAs("t_value_tagged_Qprime10_Compare.pdf");
//c4ALL->SaveAs("t_value_tagged_Qprime10_Compare.C");
//c4ALL->SaveAs("t_value_tagged_Qprime10_Compare.eps");
//c4ALL->SaveAs("t_value_tagged_Qprime10_Compare.root");





// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvastvalue_ALL = new TCanvas("canvastvalue_ALL", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_tvalue_ALL = (TH1F*)histtvalue_LM_ALL->Clone(); // Clone histtvalue_LM_ALL to keep the original histogram
resultHist_tvalue_ALL->Add(histtvalue_HM_ALL);


//Double_t xl7=0.70, yl7=0.70, xl8=xl7+0.150, yl8=yl7+0.150;

//TLegend *leg4 = new TLegend(xl7,yl7,xl8,yl8);
//leg4->SetBorderSize(0);

leg4->AddEntry(resultHist_tvalue_ALL,"ALL (LM+HM)","L")->SetTextColor(3);

//leg4->SetTextSize(0.032);
//leg4->SetTextFont(12);
//leg4->SetFillStyle(0);


resultHist_tvalue_ALL->GetXaxis()->SetTitle("|t| [GeV^{2}]");
resultHist_tvalue_ALL->GetXaxis()->SetTitleOffset(1.25);
resultHist_tvalue_ALL->GetXaxis()->SetLabelFont(22);
resultHist_tvalue_ALL->GetXaxis()->SetTitleFont(22);
resultHist_tvalue_ALL->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");
resultHist_tvalue_ALL->GetYaxis()->SetTitleOffset(1.40);
resultHist_tvalue_ALL->GetYaxis()->SetLabelFont(22);
resultHist_tvalue_ALL->GetYaxis()->SetTitleFont(22);

resultHist_tvalue_ALL->Draw("ep");


//cout << "Integral resultHist_tvalue_ALL = "  <<  resultHist_tvalue_ALL->Integral()/4.0 << endl;


 canvastvalue_ALL->SetLogy(1);


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


canvastvalue_ALL->Update();
//delete canvas;
//canvastvalue_BH->SaveAs("t_value_tagged_LM_HM_ALL.pdf");







// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c4TCS = new TCanvas("c4TCS","tvalue", 10, 10, 900, 700);

//histtvalue_LM_TCS->SetTitle("m_{ll}");
histtvalue_LM_TCS->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_LM_TCS->GetXaxis()->SetTitleOffset(1.25);
histtvalue_LM_TCS->GetXaxis()->SetLabelFont(22);
histtvalue_LM_TCS->GetXaxis()->SetTitleFont(22);
histtvalue_LM_TCS->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");
histtvalue_LM_TCS->GetYaxis()->SetTitleOffset(1.40);
histtvalue_LM_TCS->GetYaxis()->SetLabelFont(22);
histtvalue_LM_TCS->GetYaxis()->SetTitleFont(22);

   histtvalue_LM_TCS->GetYaxis()->SetRangeUser(0.1,10000);
//   histtvalue_LM_TCS->GetXaxis()->SetRangeUser(0,1);

   histtvalue_LM_TCS->SetLineWidth(4);
   histtvalue_HM_TCS->SetLineWidth(4);

   histtvalue_LM_TCS->SetLineColor(2);
   histtvalue_HM_TCS->SetLineColor(6);

   histtvalue_LM_TCS->Draw("hist");
   histtvalue_HM_TCS->Draw("hist same");

//cout << "Integral histtvalue_LM_TCS = "  <<  histtvalue_LM_TCS->Integral()/4.0 << endl;

   c4TCS->SetLogy(1);
//   c4TCS->SetLogx(1);

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


//c4TCS->SaveAs("tvalue_tagged_Qprime10_Compare.pdf");
//c4TCS->SaveAs("tvalue_tagged_Qprime10_Compare.C");
//c4TCS->SaveAs("tvalue_tagged_Qprime10_Compare.eps");
//c4TCS->SaveAs("tvalue_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvastvalue_TCS = new TCanvas("canvastvalue_TCS", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_tvalue_TCS = (TH1F*)histtvalue_LM_TCS->Clone(); // Clone histtvalue_LM_TCS to keep the original histogram
resultHist_tvalue_TCS->Add(histtvalue_HM_TCS);

leg3->AddEntry(resultHist_tvalue_TCS,"TCS (LM+HM)","L")->SetTextColor(2);

resultHist_tvalue_TCS->GetXaxis()->SetTitle("|t| [GeV^{2}]");
resultHist_tvalue_TCS->GetXaxis()->SetTitleOffset(1.25);
resultHist_tvalue_TCS->GetXaxis()->SetLabelFont(22);
resultHist_tvalue_TCS->GetXaxis()->SetTitleFont(22);
resultHist_tvalue_TCS->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");
resultHist_tvalue_TCS->GetYaxis()->SetTitleOffset(1.40);
resultHist_tvalue_TCS->GetYaxis()->SetLabelFont(22);
resultHist_tvalue_TCS->GetYaxis()->SetTitleFont(22);


resultHist_tvalue_TCS->GetYaxis()->SetRangeUser(0.1,100);


resultHist_tvalue_TCS->SetLineColor(4);
resultHist_tvalue_ALL->SetLineColor(3);
resultHist_tvalue_BH->SetLineColor(2);


resultHist_tvalue_TCS->Draw("ep");
resultHist_tvalue_ALL->Draw("ep same");
resultHist_tvalue_BH->Draw("ep same");


//cout << "Integral resultHist_tvalue_TCS = "  <<  resultHist_tvalue_TCS->Integral()/4.0 << endl;

 canvastvalue_TCS->SetLogy(1);

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


canvastvalue_TCS->Update();
//delete canvas;
canvastvalue_TCS->SaveAs("t_value_tagged_LM_HM_BH_TCS_ALL.pdf");





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


//cout << "Integral resultHist_thetal_BH = "  <<  resultHist_thetal_BH->Integral()/(4.0) << endl;


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




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





TCanvas* c5ALL = new TCanvas("c5ALL","thetal", 10, 10, 900, 700);

//histthetal_LM_ALL->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histthetal_LM_ALL->GetXaxis()->SetTitle("#theta_{l}");
//histthetal_LM_ALL->GetXaxis()->SetTitleOffset(1.25);
histthetal_LM_ALL->GetXaxis()->SetLabelFont(22);
histthetal_LM_ALL->GetXaxis()->SetTitleFont(22);
histthetal_LM_ALL->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
histthetal_LM_ALL->GetYaxis()->SetTitleOffset(1.40);
histthetal_LM_ALL->GetYaxis()->SetLabelFont(22);
histthetal_LM_ALL->GetYaxis()->SetTitleFont(22);

histthetal_LM_ALL->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(thetal) ="<<histthetal_LM_ALL->Integral()<<endl;

   histthetal_LM_ALL->SetLineWidth(3);
   histthetal_HM_ALL->SetLineWidth(3);

   histthetal_LM_ALL->SetLineColor(2);
   histthetal_HM_ALL->SetLineColor(6);

   histthetal_LM_ALL->Draw("hist");
   histthetal_HM_ALL->Draw("hist same");



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

 c5ALL->SetLogy(1);


//c5ALL->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c5ALL->SaveAs("thetal_tagged_Qprime10_Compare.C");
//c5ALL->SaveAs("thetal_tagged_Qprime10_Compare.eps");
//c5ALL->SaveAs("thetal_tagged_Qprime10_Compare.root");
//c5ALL->SaveAs("thetal_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasthetal_ALL = new TCanvas("canvasthetal_ALL", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_thetal_ALL = (TH1F*)histthetal_LM_ALL->Clone(); // Clone histtvalue_LM_ALL to keep the original histogram
resultHist_thetal_ALL->Add(histthetal_HM_ALL);


//Double_t xl9=0.70, yl9=0.70, xl10=xl9+0.150, yl10=yl9+0.150;

//TLegend *leg5 = new TLegend(xl9,yl9,xl10,yl10);
//leg5->SetBorderSize(0);

leg5->AddEntry(resultHist_thetal_ALL,"ALL (LM+HM)","L")->SetTextColor(3);

//leg5->SetTextSize(0.032);
//leg5->SetTextFont(12);
//leg5->SetFillStyle(0);


resultHist_thetal_ALL->GetXaxis()->SetTitle("#theta_{l}");
resultHist_thetal_ALL->GetXaxis()->SetTitleOffset(1.25);
resultHist_thetal_ALL->GetXaxis()->SetLabelFont(22);
resultHist_thetal_ALL->GetXaxis()->SetTitleFont(22);
resultHist_thetal_ALL->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
resultHist_thetal_ALL->GetYaxis()->SetTitleOffset(1.40);
resultHist_thetal_ALL->GetYaxis()->SetLabelFont(22);
resultHist_thetal_ALL->GetYaxis()->SetTitleFont(22);

resultHist_thetal_ALL->Draw("hist");


//cout << "Integral resultHist_thetal_ALL = "  <<  resultHist_thetal_ALL->Integral()/(4.0) << endl;


// canvasthetal_ALL->SetLogy(1);


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


canvasthetal_ALL->Update();
//delete canvas;
//canvasthetal_ALL->SaveAs("thetal_tagged_LM_HM_BH.pdf");







// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c5TCS = new TCanvas("c5TCS","thetal", 10, 10, 900, 700);

//histthetal_LM_TCS->SetTitle("m_{ll}");
histthetal_LM_TCS->GetXaxis()->SetTitle("#theta_{l}");
histthetal_LM_TCS->GetXaxis()->SetTitleOffset(1.25);
histthetal_LM_TCS->GetXaxis()->SetLabelFont(22);
histthetal_LM_TCS->GetXaxis()->SetTitleFont(22);
histthetal_LM_TCS->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
histthetal_LM_TCS->GetYaxis()->SetTitleOffset(1.40);
histthetal_LM_TCS->GetYaxis()->SetLabelFont(22);
histthetal_LM_TCS->GetYaxis()->SetTitleFont(22);

   histthetal_LM_TCS->GetYaxis()->SetRangeUser(0.1,10000);
//   histthetal_LM_TCS->GetXaxis()->SetRangeUser(0,1);

   histthetal_LM_TCS->SetLineWidth(4);
   histthetal_HM_TCS->SetLineWidth(4);

   histthetal_LM_TCS->SetLineColor(2);
   histthetal_HM_TCS->SetLineColor(6);

   histthetal_LM_TCS->Draw("hist");
   histthetal_HM_TCS->Draw("hist same");

//cout << "Integral histthetal_LM_TCS = "  <<  histthetal_LM_TCS->Integral()/4.0 << endl;

   c5TCS->SetLogy(1);
//   c5TCS->SetLogx(1);

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


//c5TCS->SaveAs("thetal_tagged_Qprime10_Compare.pdf");
//c5TCS->SaveAs("thetal_tagged_Qprime10_Compare.C");
//c5TCS->SaveAs("thetal_tagged_Qprime10_Compare.eps");
//c5TCS->SaveAs("thetal_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasthetal_TCS = new TCanvas("canvasthetal_TCS", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_thetal_TCS = (TH1F*)histthetal_LM_TCS->Clone(); // Clone histthetal_LM_TCS to keep the original histogram
resultHist_thetal_TCS->Add(histthetal_HM_TCS);

leg5->AddEntry(resultHist_thetal_TCS,"TCS (LM+HM)","L")->SetTextColor(2);

resultHist_thetal_TCS->GetXaxis()->SetTitle("#theta_{l}");
resultHist_thetal_TCS->GetXaxis()->SetTitleOffset(1.25);
resultHist_thetal_TCS->GetXaxis()->SetLabelFont(22);
resultHist_thetal_TCS->GetXaxis()->SetTitleFont(22);
resultHist_thetal_TCS->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
resultHist_thetal_TCS->GetYaxis()->SetTitleOffset(1.40);
resultHist_thetal_TCS->GetYaxis()->SetLabelFont(22);
resultHist_thetal_TCS->GetYaxis()->SetTitleFont(22);


resultHist_thetal_TCS->GetYaxis()->SetRangeUser(0.1,100);


resultHist_thetal_TCS->SetLineColor(4);
resultHist_thetal_ALL->SetLineColor(3);
resultHist_thetal_BH->SetLineColor(2);



resultHist_thetal_TCS->Draw("hist");
resultHist_thetal_ALL->Draw("hist same");
resultHist_thetal_BH->Draw("hist same");


// cout << "Integral resultHist_thetal_TCS = "  <<  resultHist_thetal_TCS->Integral()/(4.0) << endl;

 canvasthetal_TCS->SetLogy(1);

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


canvasthetal_TCS->Update();
//delete canvas;
canvasthetal_TCS->SaveAs("thetal_tagged_LM_HM_BH_TCS_ALL.pdf");









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



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





// =======================================================================
// =======================================================================





TCanvas* c7BH = new TCanvas("c7BH","etal", 10, 10, 900, 700);

//histetal_LM_BH->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histetal_LM_BH->GetXaxis()->SetTitle("#eta_{l}");
//histetal_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histetal_LM_BH->GetXaxis()->SetLabelFont(22);
histetal_LM_BH->GetXaxis()->SetTitleFont(22);
histetal_LM_BH->GetYaxis()->SetTitle("d#sigma/d#eta_{l}");
histetal_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histetal_LM_BH->GetYaxis()->SetLabelFont(22);
histetal_LM_BH->GetYaxis()->SetTitleFont(22);

histetal_LM_BH->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(etal) ="<<histetal_LM_BH->Integral()<<endl;

   histetal_LM_BH->SetLineWidth(3);
   histetal_HM_BH->SetLineWidth(3);

   histetal_LM_BH->SetLineColor(2);
   histetal_HM_BH->SetLineColor(6);

   histetal_LM_BH->Draw("hist");
   histetal_HM_BH->Draw("hist same");



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

 c7BH->SetLogy(1);


//c7BH->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c7BH->SaveAs("etal_tagged_Qprime10_Compare.C");
//c7BH->SaveAs("etal_tagged_Qprime10_Compare.eps");
//c7BH->SaveAs("etal_tagged_Qprime10_Compare.root");
//c7BH->SaveAs("etal_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasetal_BH = new TCanvas("canvasetal_BH", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_etal_BH = (TH1F*)histetal_LM_BH->Clone(); // Clone histtvalue_LM_BH to keep the original histogram
resultHist_etal_BH->Add(histetal_HM_BH);


Double_t xl11=0.70, yl11=0.70, xl12=xl11+0.150, yl12=yl11+0.150;

TLegend *leg7 = new TLegend(xl11,yl11,xl12,yl12);
leg7->SetBorderSize(0);

leg7->AddEntry(resultHist_etal_BH,"BH (LM+HM)","L")->SetTextColor(2);

leg7->SetTextSize(0.032);
leg7->SetTextFont(12);
leg7->SetFillStyle(0);


resultHist_etal_BH->GetXaxis()->SetTitle("#eta_{l}");
resultHist_etal_BH->GetXaxis()->SetTitleOffset(1.25);
resultHist_etal_BH->GetXaxis()->SetLabelFont(22);
resultHist_etal_BH->GetXaxis()->SetTitleFont(22);
resultHist_etal_BH->GetYaxis()->SetTitle("d#sigma/d#eta_{l}");
resultHist_etal_BH->GetYaxis()->SetTitleOffset(1.40);
resultHist_etal_BH->GetYaxis()->SetLabelFont(22);
resultHist_etal_BH->GetYaxis()->SetTitleFont(22);

resultHist_etal_BH->Draw("hist");


//cout << "Integral resultHist_etal_BH = "  <<  resultHist_etal_BH->Integral()/(4.0) << endl;


// canvasetal_BH->SetLogy(1);


 leg7->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasetal_BH->Update();
//delete canvas;
//canvasetal_BH->SaveAs("etal_tagged_LM_HM_BH.pdf");




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





TCanvas* c7ALL = new TCanvas("c7ALL","etal", 10, 10, 900, 700);

//histetal_LM_ALL->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histetal_LM_ALL->GetXaxis()->SetTitle("#eta_{l}");
//histetal_LM_ALL->GetXaxis()->SetTitleOffset(1.25);
histetal_LM_ALL->GetXaxis()->SetLabelFont(22);
histetal_LM_ALL->GetXaxis()->SetTitleFont(22);
histetal_LM_ALL->GetYaxis()->SetTitle("d#sigma/d#eta_{l}");
histetal_LM_ALL->GetYaxis()->SetTitleOffset(1.40);
histetal_LM_ALL->GetYaxis()->SetLabelFont(22);
histetal_LM_ALL->GetYaxis()->SetTitleFont(22);

histetal_LM_ALL->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(etal) ="<<histetal_LM_ALL->Integral()<<endl;

   histetal_LM_ALL->SetLineWidth(3);
   histetal_HM_ALL->SetLineWidth(3);

   histetal_LM_ALL->SetLineColor(2);
   histetal_HM_ALL->SetLineColor(6);

   histetal_LM_ALL->Draw("hist");
   histetal_HM_ALL->Draw("hist same");



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

 c7ALL->SetLogy(1);


//c7ALL->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c7ALL->SaveAs("etal_tagged_Qprime10_Compare.C");
//c7ALL->SaveAs("etal_tagged_Qprime10_Compare.eps");
//c7ALL->SaveAs("etal_tagged_Qprime10_Compare.root");
//c7ALL->SaveAs("etal_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasetal_ALL = new TCanvas("canvasetal_ALL", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_etal_ALL = (TH1F*)histetal_LM_ALL->Clone(); // Clone histtvalue_LM_ALL to keep the original histogram
resultHist_etal_ALL->Add(histetal_HM_ALL);


//Double_t xl9=0.70, yl9=0.70, xl10=xl9+0.150, yl10=yl9+0.150;

//TLegend *leg7 = new TLegend(xl9,yl9,xl10,yl10);
//leg7->SetBorderSize(0);

leg7->AddEntry(resultHist_etal_ALL,"ALL (LM+HM)","L")->SetTextColor(3);

//leg7->SetTextSize(0.032);
//leg7->SetTextFont(12);
//leg7->SetFillStyle(0);


resultHist_etal_ALL->GetXaxis()->SetTitle("#eta_{l}");
resultHist_etal_ALL->GetXaxis()->SetTitleOffset(1.25);
resultHist_etal_ALL->GetXaxis()->SetLabelFont(22);
resultHist_etal_ALL->GetXaxis()->SetTitleFont(22);
resultHist_etal_ALL->GetYaxis()->SetTitle("d#sigma/d#eta_{l}");
resultHist_etal_ALL->GetYaxis()->SetTitleOffset(1.40);
resultHist_etal_ALL->GetYaxis()->SetLabelFont(22);
resultHist_etal_ALL->GetYaxis()->SetTitleFont(22);

resultHist_etal_ALL->Draw("hist");


//cout << "Integral resultHist_etal_ALL = "  <<  resultHist_etal_ALL->Integral()/(4.0) << endl;


// canvasetal_ALL->SetLogy(1);


 leg7->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasetal_ALL->Update();
//delete canvas;
//canvasetal_ALL->SaveAs("etal_tagged_LM_HM_BH.pdf");







// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c7TCS = new TCanvas("c7TCS","etal", 10, 10, 900, 700);

//histetal_LM_TCS->SetTitle("m_{ll}");
histetal_LM_TCS->GetXaxis()->SetTitle("#eta_{l}");
histetal_LM_TCS->GetXaxis()->SetTitleOffset(1.25);
histetal_LM_TCS->GetXaxis()->SetLabelFont(22);
histetal_LM_TCS->GetXaxis()->SetTitleFont(22);
histetal_LM_TCS->GetYaxis()->SetTitle("d#sigma/d#eta_{l}");
histetal_LM_TCS->GetYaxis()->SetTitleOffset(1.40);
histetal_LM_TCS->GetYaxis()->SetLabelFont(22);
histetal_LM_TCS->GetYaxis()->SetTitleFont(22);

   histetal_LM_TCS->GetYaxis()->SetRangeUser(0.1,10000);
//   histetal_LM_TCS->GetXaxis()->SetRangeUser(0,1);

   histetal_LM_TCS->SetLineWidth(4);
   histetal_HM_TCS->SetLineWidth(4);

   histetal_LM_TCS->SetLineColor(2);
   histetal_HM_TCS->SetLineColor(6);

   histetal_LM_TCS->Draw("hist");
   histetal_HM_TCS->Draw("hist same");

//cout << "Integral histetal_LM_TCS = "  <<  histetal_LM_TCS->Integral()/4.0 << endl;

   c7TCS->SetLogy(1);
//   c7TCS->SetLogx(1);

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


//c7TCS->SaveAs("etal_tagged_Qprime10_Compare.pdf");
//c7TCS->SaveAs("etal_tagged_Qprime10_Compare.C");
//c7TCS->SaveAs("etal_tagged_Qprime10_Compare.eps");
//c7TCS->SaveAs("etal_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasetal_TCS = new TCanvas("canvasetal_TCS", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_etal_TCS = (TH1F*)histetal_LM_TCS->Clone(); // Clone histetal_LM_TCS to keep the original histogram
resultHist_etal_TCS->Add(histetal_HM_TCS);

leg7->AddEntry(resultHist_etal_TCS,"TCS (LM+HM)","L")->SetTextColor(2);

resultHist_etal_TCS->GetXaxis()->SetTitle("#eta_{l}");
resultHist_etal_TCS->GetXaxis()->SetTitleOffset(1.25);
resultHist_etal_TCS->GetXaxis()->SetLabelFont(22);
resultHist_etal_TCS->GetXaxis()->SetTitleFont(22);
resultHist_etal_TCS->GetYaxis()->SetTitle("d#sigma/d#eta_{l}");
resultHist_etal_TCS->GetYaxis()->SetTitleOffset(1.40);
resultHist_etal_TCS->GetYaxis()->SetLabelFont(22);
resultHist_etal_TCS->GetYaxis()->SetTitleFont(22);


resultHist_etal_TCS->GetYaxis()->SetRangeUser(0.1,100);


resultHist_etal_TCS->SetLineColor(4);
resultHist_etal_ALL->SetLineColor(3);
resultHist_etal_BH->SetLineColor(2);



resultHist_etal_TCS->Draw("hist");
resultHist_etal_ALL->Draw("hist same");
resultHist_etal_BH->Draw("hist same");


// cout << "Integral resultHist_etal_TCS = "  <<  resultHist_etal_TCS->Integral()/(4.0) << endl;

 canvasetal_TCS->SetLogy(1);

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


canvasetal_TCS->Update();
//delete canvas;
canvasetal_TCS->SaveAs("etal_tagged_LM_HM_BH_TCS_ALL.pdf");











// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






// =======================================================================
// =======================================================================





TCanvas* c8BH = new TCanvas("c8BH","q2", 10, 10, 900, 700);

//histq2_LM_BH->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histq2_LM_BH->GetXaxis()->SetTitle("q^{2}");
//histq2_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histq2_LM_BH->GetXaxis()->SetLabelFont(22);
histq2_LM_BH->GetXaxis()->SetTitleFont(22);
histq2_LM_BH->GetYaxis()->SetTitle("d#sigma/dq^{2}");
histq2_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histq2_LM_BH->GetYaxis()->SetLabelFont(22);
histq2_LM_BH->GetYaxis()->SetTitleFont(22);

histq2_LM_BH->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(q2) ="<<histq2_LM_BH->Integral()<<endl;

   histq2_LM_BH->SetLineWidth(3);
   histq2_HM_BH->SetLineWidth(3);

   histq2_LM_BH->SetLineColor(2);
   histq2_HM_BH->SetLineColor(6);

   histq2_LM_BH->Draw("hist");
   histq2_HM_BH->Draw("hist same");



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

 c8BH->SetLogy(1);


//c8BH->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c8BH->SaveAs("q2_tagged_Qprime10_Compare.C");
//c8BH->SaveAs("q2_tagged_Qprime10_Compare.eps");
//c8BH->SaveAs("q2_tagged_Qprime10_Compare.root");
//c8BH->SaveAs("q2_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasq2_BH = new TCanvas("canvasq2_BH", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_q2_BH = (TH1F*)histq2_LM_BH->Clone(); // Clone histtvalue_LM_BH to keep the original histogram
resultHist_q2_BH->Add(histq2_HM_BH);



Double_t xl13=0.70, yl13=0.70, xl15=xl13+0.150, yl15=yl13+0.150;

TLegend *leg8 = new TLegend(xl13,yl13,xl15,yl15);
leg8->SetBorderSize(0);

leg8->AddEntry(resultHist_q2_BH,"BH (LM+HM)","L")->SetTextColor(2);

leg8->SetTextSize(0.032);
leg8->SetTextFont(12);
leg8->SetFillStyle(0);


resultHist_q2_BH->GetXaxis()->SetTitle("q^{2}");
resultHist_q2_BH->GetXaxis()->SetTitleOffset(1.25);
resultHist_q2_BH->GetXaxis()->SetLabelFont(22);
resultHist_q2_BH->GetXaxis()->SetTitleFont(22);
resultHist_q2_BH->GetYaxis()->SetTitle("d#sigma/dq^{2}");
resultHist_q2_BH->GetYaxis()->SetTitleOffset(1.40);
resultHist_q2_BH->GetYaxis()->SetLabelFont(22);
resultHist_q2_BH->GetYaxis()->SetTitleFont(22);

resultHist_q2_BH->Draw("hist");


//cout << "Integral resultHist_q2_BH = "  <<  resultHist_q2_BH->Integral()/(4.0) << endl;


// canvasq2_BH->SetLogy(1);


 leg8->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasq2_BH->Update();
//delete canvas;
//canvasq2_BH->SaveAs("q2_tagged_LM_HM_BH.pdf");




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





TCanvas* c8ALL = new TCanvas("c8ALL","q2", 10, 10, 900, 700);

//histq2_LM_ALL->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histq2_LM_ALL->GetXaxis()->SetTitle("q^{2}");
//histq2_LM_ALL->GetXaxis()->SetTitleOffset(1.25);
histq2_LM_ALL->GetXaxis()->SetLabelFont(22);
histq2_LM_ALL->GetXaxis()->SetTitleFont(22);
histq2_LM_ALL->GetYaxis()->SetTitle("d#sigma/dq^{2}");
histq2_LM_ALL->GetYaxis()->SetTitleOffset(1.40);
histq2_LM_ALL->GetYaxis()->SetLabelFont(22);
histq2_LM_ALL->GetYaxis()->SetTitleFont(22);

histq2_LM_ALL->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(q2) ="<<histq2_LM_ALL->Integral()<<endl;

   histq2_LM_ALL->SetLineWidth(3);
   histq2_HM_ALL->SetLineWidth(3);

   histq2_LM_ALL->SetLineColor(2);
   histq2_HM_ALL->SetLineColor(6);

   histq2_LM_ALL->Draw("hist");
   histq2_HM_ALL->Draw("hist same");



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

 c8ALL->SetLogy(1);


//c8ALL->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c8ALL->SaveAs("q2_tagged_Qprime10_Compare.C");
//c8ALL->SaveAs("q2_tagged_Qprime10_Compare.eps");
//c8ALL->SaveAs("q2_tagged_Qprime10_Compare.root");
//c8ALL->SaveAs("q2_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasq2_ALL = new TCanvas("canvasq2_ALL", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_q2_ALL = (TH1F*)histq2_LM_ALL->Clone(); // Clone histtvalue_LM_ALL to keep the original histogram
resultHist_q2_ALL->Add(histq2_HM_ALL);


//Double_t xl9=0.70, yl9=0.70, xl10=xl9+0.150, yl10=yl9+0.150;

//TLegend *leg7 = new TLegend(xl9,yl9,xl10,yl10);
//leg7->SetBorderSize(0);

leg7->AddEntry(resultHist_q2_ALL,"ALL (LM+HM)","L")->SetTextColor(3);

//leg7->SetTextSize(0.032);
//leg7->SetTextFont(12);
//leg7->SetFillStyle(0);


resultHist_q2_ALL->GetXaxis()->SetTitle("q^{2}");
resultHist_q2_ALL->GetXaxis()->SetTitleOffset(1.25);
resultHist_q2_ALL->GetXaxis()->SetLabelFont(22);
resultHist_q2_ALL->GetXaxis()->SetTitleFont(22);
resultHist_q2_ALL->GetYaxis()->SetTitle("d#sigma/dq^{2}");
resultHist_q2_ALL->GetYaxis()->SetTitleOffset(1.40);
resultHist_q2_ALL->GetYaxis()->SetLabelFont(22);
resultHist_q2_ALL->GetYaxis()->SetTitleFont(22);

resultHist_q2_ALL->Draw("hist");


//cout << "Integral resultHist_q2_ALL = "  <<  resultHist_q2_ALL->Integral()/(4.0) << endl;


// canvasq2_ALL->SetLogy(1);


 leg8->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasq2_ALL->Update();
//delete canvas;
//canvasq2_ALL->SaveAs("q2_tagged_LM_HM_BH.pdf");







// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c8TCS = new TCanvas("c8TCS","q2", 10, 10, 900, 700);

//histq2_LM_TCS->SetTitle("m_{ll}");
histq2_LM_TCS->GetXaxis()->SetTitle("q^{2}");
histq2_LM_TCS->GetXaxis()->SetTitleOffset(1.25);
histq2_LM_TCS->GetXaxis()->SetLabelFont(22);
histq2_LM_TCS->GetXaxis()->SetTitleFont(22);
histq2_LM_TCS->GetYaxis()->SetTitle("d#sigma/dq^{2}");
histq2_LM_TCS->GetYaxis()->SetTitleOffset(1.40);
histq2_LM_TCS->GetYaxis()->SetLabelFont(22);
histq2_LM_TCS->GetYaxis()->SetTitleFont(22);

   histq2_LM_TCS->GetYaxis()->SetRangeUser(0.1,10000);
//   histq2_LM_TCS->GetXaxis()->SetRangeUser(0,1);

   histq2_LM_TCS->SetLineWidth(4);
   histq2_HM_TCS->SetLineWidth(4);

   histq2_LM_TCS->SetLineColor(2);
   histq2_HM_TCS->SetLineColor(6);

   histq2_LM_TCS->Draw("hist");
   histq2_HM_TCS->Draw("hist same");

//cout << "Integral histq2_LM_TCS = "  <<  histq2_LM_TCS->Integral()/4.0 << endl;

   c8TCS->SetLogy(1);
//   c8TCS->SetLogx(1);

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


//c8TCS->SaveAs("q2_tagged_Qprime10_Compare.pdf");
//c8TCS->SaveAs("q2_tagged_Qprime10_Compare.C");
//c8TCS->SaveAs("q2_tagged_Qprime10_Compare.eps");
//c8TCS->SaveAs("q2_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasq2_TCS = new TCanvas("canvasq2_TCS", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_q2_TCS = (TH1F*)histq2_LM_TCS->Clone(); // Clone histq2_LM_TCS to keep the original histogram
resultHist_q2_TCS->Add(histq2_HM_TCS);

leg7->AddEntry(resultHist_q2_TCS,"TCS (LM+HM)","L")->SetTextColor(2);

resultHist_q2_TCS->GetXaxis()->SetTitle("q^{2}");
resultHist_q2_TCS->GetXaxis()->SetTitleOffset(1.25);
resultHist_q2_TCS->GetXaxis()->SetLabelFont(22);
resultHist_q2_TCS->GetXaxis()->SetTitleFont(22);
resultHist_q2_TCS->GetYaxis()->SetTitle("d#sigma/dq^{2}");
resultHist_q2_TCS->GetYaxis()->SetTitleOffset(1.40);
resultHist_q2_TCS->GetYaxis()->SetLabelFont(22);
resultHist_q2_TCS->GetYaxis()->SetTitleFont(22);


resultHist_q2_TCS->GetYaxis()->SetRangeUser(10,1000000);


resultHist_q2_TCS->SetLineColor(4);
resultHist_q2_ALL->SetLineColor(3);
resultHist_q2_BH->SetLineColor(2);



resultHist_q2_TCS->Draw("hist");
resultHist_q2_ALL->Draw("hist same");
resultHist_q2_BH->Draw("hist same");


// cout << "Integral resultHist_q2_TCS = "  <<  resultHist_q2_TCS->Integral()/(4.0) << endl;

 canvasq2_TCS->SetLogy(1);

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


canvasq2_TCS->Update();
//delete canvas;
canvasq2_TCS->SaveAs("q2_tagged_LM_HM_BH_TCS_ALL.pdf");











// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






// =======================================================================
// =======================================================================





TCanvas* c9BH = new TCanvas("c9BH","q2prime", 10, 10, 900, 700);

//histq2prime_LM_BH->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histq2prime_LM_BH->GetXaxis()->SetTitle("Q^{'2}");
//histq2prime_LM_BH->GetXaxis()->SetTitleOffset(1.25);
histq2prime_LM_BH->GetXaxis()->SetLabelFont(22);
histq2prime_LM_BH->GetXaxis()->SetTitleFont(22);
histq2prime_LM_BH->GetYaxis()->SetTitle("d#sigma/dQ^{'2}");
histq2prime_LM_BH->GetYaxis()->SetTitleOffset(1.40);
histq2prime_LM_BH->GetYaxis()->SetLabelFont(22);
histq2prime_LM_BH->GetYaxis()->SetTitleFont(22);

histq2prime_LM_BH->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(q2prime) ="<<histq2prime_LM_BH->Integral()<<endl;

   histq2prime_LM_BH->SetLineWidth(3);
   histq2prime_HM_BH->SetLineWidth(3);

   histq2prime_LM_BH->SetLineColor(2);
   histq2prime_HM_BH->SetLineColor(6);

   histq2prime_LM_BH->Draw("hist");
   histq2prime_HM_BH->Draw("hist same");



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

 c9BH->SetLogy(1);


//c9BH->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c9BH->SaveAs("q2prime_tagged_Qprime10_Compare.C");
//c9BH->SaveAs("q2prime_tagged_Qprime10_Compare.eps");
//c9BH->SaveAs("q2prime_tagged_Qprime10_Compare.root");
//c9BH->SaveAs("q2prime_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasq2prime_BH = new TCanvas("canvasq2prime_BH", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_q2prime_BH = (TH1F*)histq2prime_LM_BH->Clone(); // Clone histtvalue_LM_BH to keep the original histogram
resultHist_q2prime_BH->Add(histq2prime_HM_BH);



Double_t xl16=0.70, yl16=0.70, xl17=xl16+0.150, yl17=yl16+0.150;

TLegend *leg9 = new TLegend(xl16,yl16,xl17,yl17);
leg9->SetBorderSize(0);

leg9->AddEntry(resultHist_q2prime_BH,"BH (LM+HM)","L")->SetTextColor(2);

leg9->SetTextSize(0.032);
leg9->SetTextFont(12);
leg9->SetFillStyle(0);


resultHist_q2prime_BH->GetXaxis()->SetTitle("Q^{'2}");
resultHist_q2prime_BH->GetXaxis()->SetTitleOffset(1.25);
resultHist_q2prime_BH->GetXaxis()->SetLabelFont(22);
resultHist_q2prime_BH->GetXaxis()->SetTitleFont(22);
resultHist_q2prime_BH->GetYaxis()->SetTitle("d#sigma/dQ^{'2}");
resultHist_q2prime_BH->GetYaxis()->SetTitleOffset(1.40);
resultHist_q2prime_BH->GetYaxis()->SetLabelFont(22);
resultHist_q2prime_BH->GetYaxis()->SetTitleFont(22);

resultHist_q2prime_BH->Draw("hist");


//cout << "Integral resultHist_q2prime_BH = "  <<  resultHist_q2prime_BH->Integral()/(4.0) << endl;


// canvasq2prime_BH->SetLogy(1);


 leg9->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasq2prime_BH->Update();
//delete canvas;
//canvasq2prime_BH->SaveAs("q2prime_tagged_LM_HM_BH.pdf");




//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





TCanvas* c9ALL = new TCanvas("c9ALL","q2prime", 10, 10, 900, 700);

//histq2prime_LM_ALL->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histq2prime_LM_ALL->GetXaxis()->SetTitle("Q^{'2}");
//histq2prime_LM_ALL->GetXaxis()->SetTitleOffset(1.25);
histq2prime_LM_ALL->GetXaxis()->SetLabelFont(22);
histq2prime_LM_ALL->GetXaxis()->SetTitleFont(22);
histq2prime_LM_ALL->GetYaxis()->SetTitle("d#sigma/dQ^{'2}");
histq2prime_LM_ALL->GetYaxis()->SetTitleOffset(1.40);
histq2prime_LM_ALL->GetYaxis()->SetLabelFont(22);
histq2prime_LM_ALL->GetYaxis()->SetTitleFont(22);

histq2prime_LM_ALL->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(q2prime) ="<<histq2prime_LM_ALL->Integral()<<endl;

   histq2prime_LM_ALL->SetLineWidth(3);
   histq2prime_HM_ALL->SetLineWidth(3);

   histq2prime_LM_ALL->SetLineColor(2);
   histq2prime_HM_ALL->SetLineColor(6);

   histq2prime_LM_ALL->Draw("hist");
   histq2prime_HM_ALL->Draw("hist same");



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

 c9ALL->SetLogy(1);


//c9ALL->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c9ALL->SaveAs("q2prime_tagged_Qprime10_Compare.C");
//c9ALL->SaveAs("q2prime_tagged_Qprime10_Compare.eps");
//c9ALL->SaveAs("q2prime_tagged_Qprime10_Compare.root");
//c9ALL->SaveAs("q2prime_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasq2prime_ALL = new TCanvas("canvasq2prime_ALL", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_q2prime_ALL = (TH1F*)histq2prime_LM_ALL->Clone(); // Clone histtvalue_LM_ALL to keep the original histogram
resultHist_q2prime_ALL->Add(histq2prime_HM_ALL);


//Double_t xl9=0.70, yl9=0.70, xl10=xl9+0.150, yl10=yl9+0.150;

//TLegend *leg7 = new TLegend(xl9,yl9,xl10,yl10);
//leg7->SetBorderSize(0);

leg7->AddEntry(resultHist_q2prime_ALL,"ALL (LM+HM)","L")->SetTextColor(3);

//leg7->SetTextSize(0.032);
//leg7->SetTextFont(12);
//leg7->SetFillStyle(0);


resultHist_q2prime_ALL->GetXaxis()->SetTitle("Q^{'2}");
resultHist_q2prime_ALL->GetXaxis()->SetTitleOffset(1.25);
resultHist_q2prime_ALL->GetXaxis()->SetLabelFont(22);
resultHist_q2prime_ALL->GetXaxis()->SetTitleFont(22);
resultHist_q2prime_ALL->GetYaxis()->SetTitle("d#sigma/dQ^{'2}");
resultHist_q2prime_ALL->GetYaxis()->SetTitleOffset(1.40);
resultHist_q2prime_ALL->GetYaxis()->SetLabelFont(22);
resultHist_q2prime_ALL->GetYaxis()->SetTitleFont(22);

resultHist_q2prime_ALL->Draw("hist");


//cout << "Integral resultHist_q2prime_ALL = "  <<  resultHist_q2prime_ALL->Integral()/(4.0) << endl;


// canvasq2prime_ALL->SetLogy(1);


 leg9->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
// t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");


canvasq2prime_ALL->Update();
//delete canvas;
//canvasq2prime_ALL->SaveAs("q2prime_tagged_LM_HM_BH.pdf");







// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------



TCanvas* c9TCS = new TCanvas("c9TCS","q2prime", 10, 10, 900, 700);

//histq2prime_LM_TCS->SetTitle("m_{ll}");
histq2prime_LM_TCS->GetXaxis()->SetTitle("Q^{'2}");
histq2prime_LM_TCS->GetXaxis()->SetTitleOffset(1.25);
histq2prime_LM_TCS->GetXaxis()->SetLabelFont(22);
histq2prime_LM_TCS->GetXaxis()->SetTitleFont(22);
histq2prime_LM_TCS->GetYaxis()->SetTitle("d#sigma/dQ^{'2}");
histq2prime_LM_TCS->GetYaxis()->SetTitleOffset(1.40);
histq2prime_LM_TCS->GetYaxis()->SetLabelFont(22);
histq2prime_LM_TCS->GetYaxis()->SetTitleFont(22);

   histq2prime_LM_TCS->GetYaxis()->SetRangeUser(0.1,10000);
//   histq2prime_LM_TCS->GetXaxis()->SetRangeUser(0,1);

   histq2prime_LM_TCS->SetLineWidth(4);
   histq2prime_HM_TCS->SetLineWidth(4);

   histq2prime_LM_TCS->SetLineColor(2);
   histq2prime_HM_TCS->SetLineColor(6);

   histq2prime_LM_TCS->Draw("hist");
   histq2prime_HM_TCS->Draw("hist same");

//cout << "Integral histq2prime_LM_TCS = "  <<  histq2prime_LM_TCS->Integral()/4.0 << endl;

   c9TCS->SetLogy(1);
//   c9TCS->SetLogx(1);

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


//c9TCS->SaveAs("q2prime_tagged_Qprime10_Compare.pdf");
//c9TCS->SaveAs("q2prime_tagged_Qprime10_Compare.C");
//c9TCS->SaveAs("q2prime_tagged_Qprime10_Compare.eps");
//c9TCS->SaveAs("q2prime_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasq2prime_TCS = new TCanvas("canvasq2prime_TCS", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_q2prime_TCS = (TH1F*)histq2prime_LM_TCS->Clone(); // Clone histq2prime_LM_TCS to keep the original histogram
resultHist_q2prime_TCS->Add(histq2prime_HM_TCS);

leg7->AddEntry(resultHist_q2prime_TCS,"TCS (LM+HM)","L")->SetTextColor(2);

resultHist_q2prime_TCS->GetXaxis()->SetTitle("Q^{'2}");
resultHist_q2prime_TCS->GetXaxis()->SetTitleOffset(1.25);
resultHist_q2prime_TCS->GetXaxis()->SetLabelFont(22);
resultHist_q2prime_TCS->GetXaxis()->SetTitleFont(22);
resultHist_q2prime_TCS->GetYaxis()->SetTitle("d#sigma/dQ^{'2}");
resultHist_q2prime_TCS->GetYaxis()->SetTitleOffset(1.40);
resultHist_q2prime_TCS->GetYaxis()->SetLabelFont(22);
resultHist_q2prime_TCS->GetYaxis()->SetTitleFont(22);


//resultHist_q2prime_TCS->GetYaxis()->SetRangeUser(0,1000);


resultHist_q2prime_TCS->SetLineColor(4);
resultHist_q2prime_ALL->SetLineColor(3);
resultHist_q2prime_BH->SetLineColor(2);



resultHist_q2prime_TCS->Draw("hist");
resultHist_q2prime_ALL->Draw("hist same");
resultHist_q2prime_BH->Draw("hist same");


// cout << "Integral resultHist_q2prime_TCS = "  <<  resultHist_q2prime_TCS->Integral()/(4.0) << endl;

 canvasq2prime_TCS->SetLogy(1);

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


canvasq2prime_TCS->Update();
//delete canvas;
canvasq2prime_TCS->SaveAs("q2prime_tagged_LM_HM_BH_TCS_ALL.pdf");











// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
