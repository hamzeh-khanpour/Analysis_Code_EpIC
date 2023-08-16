
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


int n_signal_eebb_LL = 0.0;
int n_signal_eebb_LR = 0.0;
int n_signal_eebb_RL = 0.0;
int n_signal_eebb_RR = 0.0;


int total_signal_eebb_LL = 1904441.0;
int total_signal_eebb_LR = 1927580.0;
int total_signal_eebb_RL = 1887536.0;
int total_signal_eebb_RR = 1881525.0;


int  n_bkg_eebbll   = 0.0;
int  n_bkg_eeLjLjll = 0.0;
int  n_bkg_eeccll   = 0.0;    
int  n_bkg_eebb     = 0.0;  



int  total_bkg_eebbll   = 1995145.0;
int  total_bkg_eeLjLjll = 2000000.0;
int  total_bkg_eeccll   = 2000000.0;    
int  total_bkg_eebb     = 2000000.0;  





//*   -----------------------------------------------

void Plots_ee_bb_ee_eekt_Durham_Electron(){

    
   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);


Float_t mll;    Float_t cosll;        Float_t mbb;        
Float_t ht;     Float_t ptb;          Float_t dphill; 
Float_t coslb;  Float_t deltaetall;   Float_t deltarlb;  
Float_t etab;   Float_t eventweight;  Float_t ptll;       Float_t met;
Float_t jetsmulti;
Float_t bjetsmulti;
Float_t pratio; Float_t eleptonratio; Float_t splplm;


TH1F * histMll_signal_eebb_LL = new TH1F ("mll", "", 40, 1.0, 80.0);
TH1F * histMll_signal_eebb_LR = new TH1F ("mll", "", 40, 1.0, 80.0);
TH1F * histMll_signal_eebb_RL = new TH1F ("mll", "", 40, 1.0, 80.0);
TH1F * histMll_signal_eebb_RR = new TH1F ("mll", "", 40, 1.0, 80.0);
TH1F * histMll_bkg_eebb = new TH1F ("mll", "", 40, 1.0, 80.0);
TH1F * histMll_bkg_bb = new TH1F ("mll", "", 40, 1.0, 80.0);
TH1F * histMll_bkg_eecc = new TH1F ("mll", "", 40, 1.0, 80.0);
TH1F * histMll_bkg_eeLjLj = new TH1F ("mll", "", 40, 1.0, 80.0);



TH1F * histcosll_signal_eebb_LL = new TH1F ("cosll", "", 30, -1.0, 1.0);
TH1F * histcosll_signal_eebb_LR = new TH1F ("cosll", "", 30, -1.0, 1.0);
TH1F * histcosll_signal_eebb_RL = new TH1F ("cosll", "", 30, -1.0, 1.0);
TH1F * histcosll_signal_eebb_RR = new TH1F ("cosll", "", 30, -1.0, 1.0);
TH1F * histcosll_bkg_eebb = new TH1F ("cosll", "", 30, -1.0, 1.0);
TH1F * histcosll_bkg_bb = new TH1F ("cosll", "", 30, -1.0, 1.0);
TH1F * histcosll_bkg_eecc = new TH1F ("cosll", "", 30, -1.0, 1.0);
TH1F * histcosll_bkg_eeLjLj = new TH1F ("cosll", "", 30, -1.0, 1.0);



TH1F * histMbb_signal_eebb_LL = new TH1F ("mbb", "", 40, 1.0, 120.0);
TH1F * histMbb_signal_eebb_LR = new TH1F ("mbb", "", 40, 1.0, 120.0);
TH1F * histMbb_signal_eebb_RL = new TH1F ("mbb", "", 40, 1.0, 120.0);
TH1F * histMbb_signal_eebb_RR = new TH1F ("mbb", "", 40, 1.0, 120.0);
TH1F * histMbb_bkg_eebb = new TH1F ("mbb", "", 40, 1.0, 120.0);
TH1F * histMbb_bkg_bb = new TH1F ("mbb", "", 40, 1.0, 120.0);
TH1F * histMbb_bkg_eecc = new TH1F ("mbb", "", 40, 1.0, 120.0);
TH1F * histMbb_bkg_eeLjLj = new TH1F ("mbb", "", 40, 1.0, 120.0);



TH1F * histht_signal_eebb_LL = new TH1F ("ht", "", 40, 1.0, 120.0);
TH1F * histht_signal_eebb_LR = new TH1F ("ht", "", 40, 1.0, 120.0);
TH1F * histht_signal_eebb_RL = new TH1F ("ht", "", 40, 1.0, 120.0);
TH1F * histht_signal_eebb_RR = new TH1F ("ht", "", 40, 1.0, 120.0);
TH1F * histht_bkg_eebb = new TH1F ("ht", "", 40, 1.0, 120.0);
TH1F * histht_bkg_bb = new TH1F ("ht", "", 40, 1.0, 120.0);
TH1F * histht_bkg_eecc = new TH1F ("ht", "", 40, 1.0, 120.0);
TH1F * histht_bkg_eeLjLj = new TH1F ("ht", "", 40, 1.0, 120.0);



TH1F * histptb_signal_eebb_LL = new TH1F ("ptb", "", 40, 1.0, 60.0);
TH1F * histptb_signal_eebb_LR = new TH1F ("ptb", "", 40, 1.0, 60.0);
TH1F * histptb_signal_eebb_RL = new TH1F ("ptb", "", 40, 1.0, 60.0);
TH1F * histptb_signal_eebb_RR = new TH1F ("ptb", "", 40, 1.0, 60.0);
TH1F * histptb_bkg_eebb = new TH1F ("ptb", "", 40, 1.0, 60.0);
TH1F * histptb_bkg_bb = new TH1F ("ptb", "", 40, 1.0, 60.0);
TH1F * histptb_bkg_eecc = new TH1F ("ptb", "", 40, 1.0, 60.0);
TH1F * histptb_bkg_eeLjLj = new TH1F ("ptb", "", 40, 1.0, 60.0);



TH1F * histetab_signal_eebb_LL = new TH1F ("etab", "", 40, -2.50, 2.50);
TH1F * histetab_signal_eebb_LR = new TH1F ("etab", "", 40, -2.50, 2.50);
TH1F * histetab_signal_eebb_RL = new TH1F ("etab", "", 40, -2.50, 2.50);
TH1F * histetab_signal_eebb_RR = new TH1F ("etab", "", 40, -2.50, 2.50);
TH1F * histetab_bkg_eebb = new TH1F ("etab", "", 40, -2.50, 2.50);
TH1F * histetab_bkg_bb = new TH1F ("etab", "", 40, -2.50, 2.50);
TH1F * histetab_bkg_eecc = new TH1F ("etab", "", 40, -2.50, 2.50);
TH1F * histetab_bkg_eeLjLj = new TH1F ("etab", "", 40, -2.50, 2.50);



TH1F * histptll_signal_eebb_LL = new TH1F ("ptll", "", 40, 1.0, 60.0);
TH1F * histptll_signal_eebb_LR = new TH1F ("ptll", "", 40, 1.0, 60.0);
TH1F * histptll_signal_eebb_RL = new TH1F ("ptll", "", 40, 1.0, 60.0);
TH1F * histptll_signal_eebb_RR = new TH1F ("ptll", "", 40, 1.0, 60.0);
TH1F * histptll_bkg_eebb = new TH1F ("ptll", "", 40, 1.0, 60.0);
TH1F * histptll_bkg_bb = new TH1F ("ptll", "", 40, 1.0, 60.0);
TH1F * histptll_bkg_eecc = new TH1F ("ptll", "", 40, 1.0, 60.0);
TH1F * histptll_bkg_eeLjLj = new TH1F ("ptll", "", 40, 1.0, 60.0);



TH1F * histmet_signal_eebb_LL = new TH1F ("met", "", 40, 1.0, 30.0);
TH1F * histmet_signal_eebb_LR = new TH1F ("met", "", 40, 1.0, 30.0);
TH1F * histmet_signal_eebb_RL = new TH1F ("met", "", 40, 1.0, 30.0);
TH1F * histmet_signal_eebb_RR = new TH1F ("met", "", 40, 1.0, 30.0);
TH1F * histmet_bkg_eebb = new TH1F ("met", "", 40, 1.0, 30.0);
TH1F * histmet_bkg_bb = new TH1F ("met", "", 40, 1.0, 30.0);
TH1F * histmet_bkg_eecc = new TH1F ("met", "", 40, 1.0, 30.0);
TH1F * histmet_bkg_eeLjLj = new TH1F ("met", "", 40, 1.0, 30.0);



TH1F * histcoslb_signal_eebb_LL = new TH1F ("coslb", "", 20, -1.0, 1.0);
TH1F * histcoslb_signal_eebb_LR = new TH1F ("coslb", "", 20, -1.0, 1.0);
TH1F * histcoslb_signal_eebb_RL = new TH1F ("coslb", "", 20, -1.0, 1.0);
TH1F * histcoslb_signal_eebb_RR = new TH1F ("coslb", "", 20, -1.0, 1.0);
TH1F * histcoslb_bkg_eebb = new TH1F ("coslb", "", 20, -1.0, 1.0);
TH1F * histcoslb_bkg_bb = new TH1F ("coslb", "", 20, -1.0, 1.0);
TH1F * histcoslb_bkg_eecc = new TH1F ("coslb", "", 20, -1.0, 1.0);
TH1F * histcoslb_bkg_eeLjLj = new TH1F ("coslb", "", 20, -1.0, 1.0);



TH1F * histjetsmulti_signal_eebb_LL = new TH1F ("jetsmulti", "", 6, 0, 6);
TH1F * histjetsmulti_signal_eebb_LR = new TH1F ("jetsmulti", "", 6, 0, 6);
TH1F * histjetsmulti_signal_eebb_RL = new TH1F ("jetsmulti", "", 6, 0, 6);
TH1F * histjetsmulti_signal_eebb_RR = new TH1F ("jetsmulti", "", 6, 0, 6);
TH1F * histjetsmulti_bkg_eebb = new TH1F ("jetsmulti", "", 6, 0, 6);
TH1F * histjetsmulti_bkg_bb = new TH1F ("jetsmulti", "", 6, 0, 6);
TH1F * histjetsmulti_bkg_eecc = new TH1F ("jetsmulti", "", 6, 0, 6);
TH1F * histjetsmulti_bkg_eeLjLj = new TH1F ("jetsmulti", "", 6, 0, 6);



TH1F * histbjetsmulti_signal_eebb_LL = new TH1F ("bjetsmulti", "", 5, 0.0, 5.0);
TH1F * histbjetsmulti_signal_eebb_LR = new TH1F ("bjetsmulti", "", 5, 0.0, 5.0);
TH1F * histbjetsmulti_signal_eebb_RL = new TH1F ("bjetsmulti", "", 5, 0.0, 5.0);
TH1F * histbjetsmulti_signal_eebb_RR = new TH1F ("bjetsmulti", "", 5, 0.0, 5.0);
TH1F * histbjetsmulti_bkg_eebb = new TH1F ("bjetsmulti", "", 5, 0.0, 5.0);
TH1F * histbjetsmulti_bkg_bb = new TH1F ("bjetsmulti", "", 5, 0.0, 5.0);
TH1F * histbjetsmulti_bkg_eecc = new TH1F ("bjetsmulti", "", 5, 0.0, 5.0);
TH1F * histbjetsmulti_bkg_eeLjLj = new TH1F ("bjetsmulti", "", 5, 0.0, 5.0);



TH1F * histpratio_signal_eebb_LL = new TH1F ("pratio", "", 40, 1.0, 200.0);
TH1F * histpratio_signal_eebb_LR = new TH1F ("pratio", "", 40, 1.0, 200.0);
TH1F * histpratio_signal_eebb_RL = new TH1F ("pratio", "", 40, 1.0, 200.0);
TH1F * histpratio_signal_eebb_RR = new TH1F ("pratio", "", 40, 1.0, 200.0);
TH1F * histpratio_bkg_eebb = new TH1F ("pratio", "", 40, 1.0, 200.0);
TH1F * histpratio_bkg_bb = new TH1F ("pratio", "", 40, 1.0, 200.0);
TH1F * histpratio_bkg_eecc = new TH1F ("pratio", "", 40, 1.0, 200.0);
TH1F * histpratio_bkg_eeLjLj = new TH1F ("pratio", "", 40, 1.0, 200.0);




TH1F * histeleptonratio_signal_eebb_LL = new TH1F ("eleptonratio", "", 10, 1.0, 5.0);
TH1F * histeleptonratio_signal_eebb_LR = new TH1F ("eleptonratio", "", 10, 1.0, 5.0);
TH1F * histeleptonratio_signal_eebb_RL = new TH1F ("eleptonratio", "", 10, 1.0, 5.0);
TH1F * histeleptonratio_signal_eebb_RR = new TH1F ("eleptonratio", "", 10, 1.0, 5.0);
TH1F * histeleptonratio_bkg_eebb = new TH1F ("eleptonratio", "", 10, 1.0, 5.0);
TH1F * histeleptonratio_bkg_bb = new TH1F ("eleptonratio", "", 10, 1.0, 5.0);
TH1F * histeleptonratio_bkg_eecc = new TH1F ("eleptonratio", "", 10, 1.0, 5.0);
TH1F * histeleptonratio_bkg_eeLjLj = new TH1F ("eleptonratio", "", 10, 1.0, 5.0);



TH1F * histsplplm_signal_eebb_LL = new TH1F ("splplm", "", 20, -0.2, 0.2);
TH1F * histsplplm_signal_eebb_LR = new TH1F ("splplm", "", 20, -0.2, 0.2);
TH1F * histsplplm_signal_eebb_RL = new TH1F ("splplm", "", 20, -0.2, 0.2);
TH1F * histsplplm_signal_eebb_RR = new TH1F ("splplm", "", 20, -0.2, 0.2);
TH1F * histsplplm_bkg_eebb = new TH1F ("splplm", "", 20, -0.2, 0.2);
TH1F * histsplplm_bkg_bb = new TH1F ("splplm", "", 20, -0.2, 0.2);
TH1F * histsplplm_bkg_eecc = new TH1F ("splplm", "", 20, -0.2, 0.2);
TH1F * histsplplm_bkg_eeLjLj = new TH1F ("splplm", "", 20, -0.2, 0.2);




// ============================================

  TFile *file;
  TTree *tree_signal_eebbee_LL;
  TTree *tree_signal_eebbee_LR;
  TTree *tree_signal_eebbee_RL;
  TTree *tree_signal_eebbee_RR;
  TTree *tree_bkg_eebbll;
  TTree *tree_bkg_eebb;  
  TTree *tree_bkg_eeccll;
  TTree *tree_bkg_eeLjLjll;

  
   file = TFile::Open("Four_Fermion_ee_bb_ee_eekt_Durham_electron.root");
 
   tree_signal_eebbee_LL = (TTree*)file->Get("Signal_eebbee_LL");
   tree_signal_eebbee_LR = (TTree*)file->Get("Signal_eebbee_LR");
   tree_signal_eebbee_RL = (TTree*)file->Get("Signal_eebbee_RL");
   tree_signal_eebbee_RR = (TTree*)file->Get("Signal_eebbee_RR"); 
   tree_bkg_eebbll    = (TTree*)file->Get("bkg_eebbll");
   tree_bkg_eebb    = (TTree*)file->Get("bkg_eebb");   
   tree_bkg_eeccll    = (TTree*)file->Get("bkg_eeccll");
   tree_bkg_eeLjLjll  = (TTree*)file->Get("bkg_eeLjLjll");

   cout << "tree Entries Signal_eebbee_LL == " << tree_signal_eebbee_LL->GetEntries() << endl;
   cout << "tree Entries Signal_eebbee_LR == " << tree_signal_eebbee_LR->GetEntries() << endl;   
   cout << "tree Entries Signal_eebbee_RL == " << tree_signal_eebbee_RL->GetEntries() << endl;   
   cout << "tree Entries Signal_eebbee_RR == " << tree_signal_eebbee_RR->GetEntries() << endl;   
   cout << "tree Entries bkg_eebbll    == " << tree_bkg_eebbll->GetEntries() << endl;
   cout << "tree Entries bkg_eebb      == " << tree_bkg_eebb->GetEntries() << endl;  
   cout << "tree Entries bkg_eeccll    == " << tree_bkg_eeccll->GetEntries() << endl;
   cout << "tree Entries bkg_eeLjLjll  == " << tree_bkg_eeLjLjll->GetEntries() << endl;

   
   tree_signal_eebbee_LL->SetBranchAddress("eventweight",&eventweight);
   tree_signal_eebbee_LR->SetBranchAddress("eventweight",&eventweight);   
   tree_signal_eebbee_RL->SetBranchAddress("eventweight",&eventweight);
   tree_signal_eebbee_RR->SetBranchAddress("eventweight",&eventweight);
   tree_bkg_eebbll->SetBranchAddress("eventweight",&eventweight);
   tree_bkg_eebb->SetBranchAddress("eventweight",&eventweight);   
   tree_bkg_eeccll->SetBranchAddress("eventweight",&eventweight);
   tree_bkg_eeLjLjll->SetBranchAddress("eventweight",&eventweight);   
      
   
   tree_signal_eebbee_LL->SetBranchAddress("mll",&mll);
   tree_signal_eebbee_LR->SetBranchAddress("mll",&mll);
   tree_signal_eebbee_RL->SetBranchAddress("mll",&mll);
   tree_signal_eebbee_RR->SetBranchAddress("mll",&mll);   
   tree_bkg_eebbll->SetBranchAddress("mll",&mll);
   tree_bkg_eebb->SetBranchAddress("mll",&mll);   
   tree_bkg_eeccll->SetBranchAddress("mll",&mll);
   tree_bkg_eeLjLjll->SetBranchAddress("mll",&mll);
   
   
   tree_signal_eebbee_LL->SetBranchAddress("cosll",&cosll);
   tree_signal_eebbee_LR->SetBranchAddress("cosll",&cosll);
   tree_signal_eebbee_RL->SetBranchAddress("cosll",&cosll);
   tree_signal_eebbee_RR->SetBranchAddress("cosll",&cosll);
   tree_bkg_eebbll->SetBranchAddress("cosll",&cosll);
   tree_bkg_eebb->SetBranchAddress("cosll",&cosll);   
   tree_bkg_eeccll->SetBranchAddress("cosll",&cosll);
   tree_bkg_eeLjLjll->SetBranchAddress("cosll",&cosll);  
   
   
   tree_signal_eebbee_LL->SetBranchAddress("mbb",&mbb);
   tree_signal_eebbee_LR->SetBranchAddress("mbb",&mbb);
   tree_signal_eebbee_RL->SetBranchAddress("mbb",&mbb);
   tree_signal_eebbee_RR->SetBranchAddress("mbb",&mbb);   
   tree_bkg_eebbll->SetBranchAddress("mbb",&mbb);
   tree_bkg_eebb->SetBranchAddress("mbb",&mbb);   
   tree_bkg_eeccll->SetBranchAddress("mbb",&mbb);
   tree_bkg_eeLjLjll->SetBranchAddress("mbb",&mbb);    
   
   
   tree_signal_eebbee_LL->SetBranchAddress("ht",&ht);
   tree_signal_eebbee_LR->SetBranchAddress("ht",&ht);
   tree_signal_eebbee_RL->SetBranchAddress("ht",&ht);
   tree_signal_eebbee_RR->SetBranchAddress("ht",&ht);   
   tree_bkg_eebbll->SetBranchAddress("ht",&ht);
   tree_bkg_eebb->SetBranchAddress("ht",&ht);   
   tree_bkg_eeccll->SetBranchAddress("ht",&ht);
   tree_bkg_eeLjLjll->SetBranchAddress("ht",&ht); 
   

   tree_signal_eebbee_LL->SetBranchAddress("ptb",&ptb);
   tree_signal_eebbee_LR->SetBranchAddress("ptb",&ptb);
   tree_signal_eebbee_RL->SetBranchAddress("ptb",&ptb);
   tree_signal_eebbee_RR->SetBranchAddress("ptb",&ptb);   
   tree_bkg_eebbll->SetBranchAddress("ptb",&ptb);
   tree_bkg_eebb->SetBranchAddress("ptb",&ptb);   
   tree_bkg_eeccll->SetBranchAddress("ptb",&ptb);
   tree_bkg_eeLjLjll->SetBranchAddress("ptb",&ptb); 
   

   tree_signal_eebbee_LL->SetBranchAddress("etab",&etab);
   tree_signal_eebbee_LR->SetBranchAddress("etab",&etab);
   tree_signal_eebbee_RL->SetBranchAddress("etab",&etab);
   tree_signal_eebbee_RR->SetBranchAddress("etab",&etab);   
   tree_bkg_eebbll->SetBranchAddress("etab",&etab);
   tree_bkg_eebb->SetBranchAddress("etab",&etab);   
   tree_bkg_eeccll->SetBranchAddress("etab",&etab);
   tree_bkg_eeLjLjll->SetBranchAddress("etab",&etab);  
   

   tree_signal_eebbee_LL->SetBranchAddress("ptll",&ptll);
   tree_signal_eebbee_LR->SetBranchAddress("ptll",&ptll);
   tree_signal_eebbee_RL->SetBranchAddress("ptll",&ptll);
   tree_signal_eebbee_RR->SetBranchAddress("ptll",&ptll);   
   tree_bkg_eebbll->SetBranchAddress("ptll",&ptll);
   tree_bkg_eebb->SetBranchAddress("ptll",&ptll);   
   tree_bkg_eeccll->SetBranchAddress("ptll",&ptll);
   tree_bkg_eeLjLjll->SetBranchAddress("ptll",&ptll); 
   
   
   tree_signal_eebbee_LL->SetBranchAddress("met",&met);
   tree_signal_eebbee_LR->SetBranchAddress("met",&met);
   tree_signal_eebbee_RL->SetBranchAddress("met",&met);
   tree_signal_eebbee_RR->SetBranchAddress("met",&met);   
   tree_bkg_eebbll->SetBranchAddress("met",&met);
   tree_bkg_eebb->SetBranchAddress("met",&met);   
   tree_bkg_eeccll->SetBranchAddress("met",&met);
   tree_bkg_eeLjLjll->SetBranchAddress("met",&met); 
   

   tree_signal_eebbee_LL->SetBranchAddress("coslb",&coslb);
   tree_signal_eebbee_LR->SetBranchAddress("coslb",&coslb);
   tree_signal_eebbee_RL->SetBranchAddress("coslb",&coslb);
   tree_signal_eebbee_RR->SetBranchAddress("coslb",&coslb);   
   tree_bkg_eebbll->SetBranchAddress("coslb",&coslb);
   tree_bkg_eebb->SetBranchAddress("coslb",&coslb);   
   tree_bkg_eeccll->SetBranchAddress("coslb",&coslb);
   tree_bkg_eeLjLjll->SetBranchAddress("coslb",&coslb);   
   

   tree_signal_eebbee_LL->SetBranchAddress("jetsmulti",&jetsmulti);
   tree_signal_eebbee_LR->SetBranchAddress("jetsmulti",&jetsmulti);
   tree_signal_eebbee_RL->SetBranchAddress("jetsmulti",&jetsmulti);
   tree_signal_eebbee_RR->SetBranchAddress("jetsmulti",&jetsmulti);   
   tree_bkg_eebbll->SetBranchAddress("jetsmulti",&jetsmulti);
   tree_bkg_eebb->SetBranchAddress("jetsmulti",&jetsmulti);   
   tree_bkg_eeccll->SetBranchAddress("jetsmulti",&jetsmulti);
   tree_bkg_eeLjLjll->SetBranchAddress("jetsmulti",&jetsmulti);   
   

   tree_signal_eebbee_LL->SetBranchAddress("bjetsmulti",&bjetsmulti);
   tree_signal_eebbee_LR->SetBranchAddress("bjetsmulti",&bjetsmulti);
   tree_signal_eebbee_RL->SetBranchAddress("bjetsmulti",&bjetsmulti);
   tree_signal_eebbee_RR->SetBranchAddress("bjetsmulti",&bjetsmulti);   
   tree_bkg_eebbll->SetBranchAddress("bjetsmulti",&bjetsmulti);
   tree_bkg_eebb->SetBranchAddress("bjetsmulti",&bjetsmulti);   
   tree_bkg_eeccll->SetBranchAddress("bjetsmulti",&bjetsmulti);
   tree_bkg_eeLjLjll->SetBranchAddress("bjetsmulti",&bjetsmulti);   
   

   tree_signal_eebbee_LL->SetBranchAddress("pratio",&pratio);
   tree_signal_eebbee_LR->SetBranchAddress("pratio",&pratio);
   tree_signal_eebbee_RL->SetBranchAddress("pratio",&pratio);
   tree_signal_eebbee_RR->SetBranchAddress("pratio",&pratio);   
   tree_bkg_eebbll->SetBranchAddress("pratio",&pratio);
   tree_bkg_eebb->SetBranchAddress("pratio",&pratio);   
   tree_bkg_eeccll->SetBranchAddress("pratio",&pratio);
   tree_bkg_eeLjLjll->SetBranchAddress("pratio",&pratio);    


   tree_signal_eebbee_LL->SetBranchAddress("eleptonratio",&eleptonratio);
   tree_signal_eebbee_LR->SetBranchAddress("eleptonratio",&eleptonratio);
   tree_signal_eebbee_RL->SetBranchAddress("eleptonratio",&eleptonratio);
   tree_signal_eebbee_RR->SetBranchAddress("eleptonratio",&eleptonratio);   
   tree_bkg_eebbll->SetBranchAddress("eleptonratio",&eleptonratio);
   tree_bkg_eebb->SetBranchAddress("eleptonratio",&eleptonratio);   
   tree_bkg_eeccll->SetBranchAddress("eleptonratio",&eleptonratio);
   tree_bkg_eeLjLjll->SetBranchAddress("eleptonratio",&eleptonratio);   


   tree_signal_eebbee_LL->SetBranchAddress("splplm",&splplm);
   tree_signal_eebbee_LR->SetBranchAddress("splplm",&splplm);
   tree_signal_eebbee_RL->SetBranchAddress("splplm",&splplm);
   tree_signal_eebbee_RR->SetBranchAddress("splplm",&splplm);   
   tree_bkg_eebbll->SetBranchAddress("splplm",&splplm);
   tree_bkg_eebb->SetBranchAddress("splplm",&splplm);   
   tree_bkg_eeccll->SetBranchAddress("splplm",&splplm);
   tree_bkg_eeLjLjll->SetBranchAddress("splplm",&splplm);     

   

   
  for (Long64_t ievt=0; ievt<tree_signal_eebbee_LL->GetEntries();ievt++) {
  tree_signal_eebbee_LL->GetEntry(ievt);
  
  histMll_signal_eebb_LL->Fill(mll);
  histcosll_signal_eebb_LL->Fill(cosll);
  histMbb_signal_eebb_LL->Fill(mbb);
  histht_signal_eebb_LL->Fill(ht);
  histptb_signal_eebb_LL->Fill(ptb);
  histetab_signal_eebb_LL->Fill(etab);
  histptll_signal_eebb_LL->Fill(ptll);
  histmet_signal_eebb_LL->Fill(met);
  histcoslb_signal_eebb_LL->Fill(coslb);
  
  histjetsmulti_signal_eebb_LL->Fill(jetsmulti);
  histbjetsmulti_signal_eebb_LL->Fill(bjetsmulti);
  histpratio_signal_eebb_LL->Fill(pratio);  
  histeleptonratio_signal_eebb_LL->Fill(eleptonratio);
  histsplplm_signal_eebb_LL->Fill(splplm);


//  cout << "mll_signal  == " << mll << endl;  
//  cout << "eventweight_signal  == " << eventweight << endl;  
  
  
if (mll > 15.0 && cosll < 0.40 && mbb > 20.0 && ptll < 20.0) {n_signal_eebb_LL++;} // coslb > -0.6   && splplm < -0.001
      
    }
    
  cout << "signal_eff_1_LL  == " << tree_signal_eebbee_LL->GetEntries()*1.0/total_signal_eebb_LL << endl;  
  cout << "n_signal_eebb_LL  == " << n_signal_eebb_LL << endl;  
 // cout << "signal_eff  == " << n_signal_eebb*1.0/tree_signal_eebbee_LL->GetEntries() << endl;  
  cout << "signal_eff_Final_LL  == " << n_signal_eebb_LL*1.0/total_signal_eebb_LL << endl;  
  
      
  
  

  for (Long64_t ievt=0; ievt<tree_signal_eebbee_LR->GetEntries();ievt++) {
  tree_signal_eebbee_LR->GetEntry(ievt);
  
  histMll_signal_eebb_LR->Fill(mll);
  histcosll_signal_eebb_LR->Fill(cosll);
  histMbb_signal_eebb_LR->Fill(mbb);
  histht_signal_eebb_LR->Fill(ht);
  histptb_signal_eebb_LR->Fill(ptb);
  histetab_signal_eebb_LR->Fill(etab);
  histptll_signal_eebb_LR->Fill(ptll);
  histmet_signal_eebb_LR->Fill(met);
  histcoslb_signal_eebb_LR->Fill(coslb);
  
  histjetsmulti_signal_eebb_LR->Fill(jetsmulti);
  histbjetsmulti_signal_eebb_LR->Fill(bjetsmulti);
  histpratio_signal_eebb_LR->Fill(pratio);  
  histeleptonratio_signal_eebb_LR->Fill(eleptonratio);
  histsplplm_signal_eebb_LR->Fill(splplm);


//  cout << "mll_signal  == " << mll << endl;  
//  cout << "eventweight_signal  == " << eventweight << endl;  
  
  
if (mll > 15.0 && cosll < 0.40 && mbb > 20.0 && ptll < 20.0) {n_signal_eebb_LR++;} // coslb > -0.6   && splplm < -0.001
      
    }
    
  cout << "signal_eff_1_LR  == " << tree_signal_eebbee_LR->GetEntries()*1.0/total_signal_eebb_LR << endl;  
  cout << "n_signal_eebb_LR  == " << n_signal_eebb_LR << endl;  
 // cout << "signal_eff  == " << n_signal_eebb*1.0/tree_signal_eebbee_LL->GetEntries() << endl;  
  cout << "signal_eff_Final_LR  == " << n_signal_eebb_LR*1.0/total_signal_eebb_LR << endl;  
  
      
  
  
   

   
  for (Long64_t ievt=0; ievt<tree_signal_eebbee_RL->GetEntries();ievt++) {
  tree_signal_eebbee_RL->GetEntry(ievt);
  
  histMll_signal_eebb_RL->Fill(mll);
  histcosll_signal_eebb_RL->Fill(cosll);
  histMbb_signal_eebb_RL->Fill(mbb);
  histht_signal_eebb_RL->Fill(ht);
  histptb_signal_eebb_RL->Fill(ptb);
  histetab_signal_eebb_RL->Fill(etab);
  histptll_signal_eebb_RL->Fill(ptll);
  histmet_signal_eebb_RL->Fill(met);
  histcoslb_signal_eebb_RL->Fill(coslb);
  
  histjetsmulti_signal_eebb_RL->Fill(jetsmulti);
  histbjetsmulti_signal_eebb_RL->Fill(bjetsmulti);
  histpratio_signal_eebb_RL->Fill(pratio);  
  histeleptonratio_signal_eebb_RL->Fill(eleptonratio);
  histsplplm_signal_eebb_RL->Fill(splplm);


//  cout << "mll_signal  == " << mll << endl;  
//  cout << "eventweight_signal  == " << eventweight << endl;  
  
  
if (mll > 25.0 && cosll < 0.20 && mbb > 20.0 && ptll < 20.0 ) {n_signal_eebb_RL++;} // coslb > -0.6  && splplm < -0.001
      
    }
    
  cout << "signal_eff_1_RL  == " << tree_signal_eebbee_RL->GetEntries()*1.0/total_signal_eebb_RL << endl;  
  cout << "n_signal_eebb_RL  == " << n_signal_eebb_RL << endl;  
 // cout << "signal_eff  == " << n_signal_eebb*1.0/tree_signal_eebbee_LL->GetEntries() << endl;  
  cout << "signal_eff_Final_RL  == " << n_signal_eebb_RL*1.0/total_signal_eebb_RL << endl;  
  
      
  
  
   

   
  for (Long64_t ievt=0; ievt<tree_signal_eebbee_RR->GetEntries();ievt++) {
  tree_signal_eebbee_RR->GetEntry(ievt);
  
  histMll_signal_eebb_RR->Fill(mll);
  histcosll_signal_eebb_RR->Fill(cosll);
  histMbb_signal_eebb_RR->Fill(mbb);
  histht_signal_eebb_RR->Fill(ht);
  histptb_signal_eebb_RR->Fill(ptb);
  histetab_signal_eebb_RR->Fill(etab);
  histptll_signal_eebb_RR->Fill(ptll);
  histmet_signal_eebb_RR->Fill(met);
  histcoslb_signal_eebb_RR->Fill(coslb);
  
  histjetsmulti_signal_eebb_RR->Fill(jetsmulti);
  histbjetsmulti_signal_eebb_RR->Fill(bjetsmulti);
  histpratio_signal_eebb_RR->Fill(pratio);  
  histeleptonratio_signal_eebb_RR->Fill(eleptonratio);
  histsplplm_signal_eebb_RR->Fill(splplm);


//  cout << "mll_signal  == " << mll << endl;  
//  cout << "eventweight_signal  == " << eventweight << endl;  
  
  
if (mll > 25.0 && cosll < 0.20 && mbb > 20.0 && ptll < 20.0 ) {n_signal_eebb_RR++;} // coslb > -0.6   && splplm < -0.001
      
    }
    
  cout << "signal_eff_1_RR  == " << tree_signal_eebbee_RR->GetEntries()*1.0/total_signal_eebb_RR << endl;  
  cout << "n_signal_eebb_RR  == " << n_signal_eebb_RR << endl;  
 // cout << "signal_eff  == " << n_signal_eebb*1.0/tree_signal_eebbee_LL->GetEntries() << endl;  
  cout << "signal_eff_Final_RR  == " << n_signal_eebb_RR*1.0/total_signal_eebb_RR << endl;  
  
      
  
  
  
  
  for (Long64_t ievt=0; ievt<tree_bkg_eebbll->GetEntries();ievt++) {
  tree_bkg_eebbll->GetEntry(ievt);
  
  histMll_bkg_eebb->Fill(mll);
  histcosll_bkg_eebb->Fill(cosll);
  histMbb_bkg_eebb->Fill(mbb);
  histht_bkg_eebb->Fill(ht);
  histptb_bkg_eebb->Fill(ptb);
  histetab_bkg_eebb->Fill(etab);
  histptll_bkg_eebb->Fill(ptll);
  histmet_bkg_eebb->Fill(met);
  histcoslb_bkg_eebb->Fill(coslb);
  
  histjetsmulti_bkg_eebb->Fill(jetsmulti);
  histbjetsmulti_bkg_eebb->Fill(bjetsmulti);
  histpratio_bkg_eebb->Fill(pratio);  
  histeleptonratio_bkg_eebb->Fill(eleptonratio);
  histsplplm_bkg_eebb->Fill(splplm);


//  cout << "mll_bkg_eebb  == " << mll << endl;  
//  cout << "eventweight_bkg_eebb  == " << eventweight << endl;  
  
if (mll > 15.0 && cosll < 0.40 && mbb > 20.0 && ptll < 20.0 ) {n_bkg_eebbll++;}  // && splplm < -0.001 coslb > -0.6 
  
      } 

  cout << "bkg_eebbll_eff_1  == " << tree_bkg_eebbll->GetEntries()*1.0/total_bkg_eebbll << endl;    
  cout << "n_bkg_eebbll  == " << n_bkg_eebbll << endl;  
  //cout << "bkg_eebbll_eff  == " << n_bkg_eebbll*1.0/tree_bkg_eebbll->GetEntries() << endl; 
  cout << "bkg_eebbll_eff_Final  == " << n_bkg_eebbll*1.0/total_bkg_eebbll << endl;
  
 

  
  
  for (Long64_t ievt=0; ievt<tree_bkg_eeccll->GetEntries();ievt++) {
  tree_bkg_eeccll->GetEntry(ievt);
  
  histMll_bkg_eecc->Fill(mll); 
  histcosll_bkg_eecc->Fill(cosll);  
  histMbb_bkg_eecc->Fill(mbb);
  histht_bkg_eecc->Fill(ht);
  histptb_bkg_eecc->Fill(ptb);
  histetab_bkg_eecc->Fill(etab);
  histptll_bkg_eecc->Fill(ptll);
  histmet_bkg_eecc->Fill(met);
  histcoslb_bkg_eecc->Fill(coslb);
  
  histjetsmulti_bkg_eecc->Fill(jetsmulti);
  histbjetsmulti_bkg_eecc->Fill(bjetsmulti);
  histpratio_bkg_eecc->Fill(pratio);  
  histeleptonratio_bkg_eecc->Fill(eleptonratio);
  histsplplm_bkg_eecc->Fill(splplm);


if (mll > 15.0 && cosll < 0.40 && mbb > 20.0 && ptll < 20.0 ) {n_bkg_eeccll++;}  // && splplm < -0.001 coslb > -0.6 
  
      } 

  cout << "bkg_eeccll_eff_1  == " << tree_bkg_eeccll->GetEntries()*1.0/total_bkg_eeccll << endl;    
  cout << "n_bkg_eeccll  == " << n_bkg_eeccll << endl;  
  //cout << "bkg_eeccll_eff  == " << n_bkg_eeccll*1.0/tree_bkg_eeccll->GetEntries() << endl; 
  cout << "bkg_eeccll_eff_Final  == " << n_bkg_eeccll*1.0/total_bkg_eeccll << endl;
  
      
 



      
  for (Long64_t ievt=0; ievt<tree_bkg_eeLjLjll->GetEntries();ievt++) {
  tree_bkg_eeLjLjll->GetEntry(ievt); 
  
  histMll_bkg_eeLjLj->Fill(mll); 
  histcosll_bkg_eeLjLj->Fill(cosll);  
  histMbb_bkg_eeLjLj->Fill(mbb);
  histht_bkg_eeLjLj->Fill(ht);
  histptb_bkg_eeLjLj->Fill(ptb);
  histetab_bkg_eeLjLj->Fill(etab);
  histptll_bkg_eeLjLj->Fill(ptll);
  histmet_bkg_eeLjLj->Fill(met);
  histcoslb_bkg_eeLjLj->Fill(coslb);
  
  histjetsmulti_bkg_eeLjLj->Fill(jetsmulti);
  histbjetsmulti_bkg_eeLjLj->Fill(bjetsmulti);
  histpratio_bkg_eeLjLj->Fill(pratio);
  histeleptonratio_bkg_eeLjLj->Fill(eleptonratio);
  histsplplm_bkg_eeLjLj->Fill(splplm);
  

  
if (mll > 15.0 && cosll < 0.40 && mbb > 20.0 && ptll < 20.0 ) {n_bkg_eeLjLjll++;}  //  && splplm < -0.001 coslb > -0.6 
  
      } 

  cout << "bkg_eeLjLjll_eff_1  == " << tree_bkg_eeLjLjll->GetEntries()*1.0/total_bkg_eeLjLjll << endl;    
  cout << "n_bkg_eeLjLjll  == " << n_bkg_eeLjLjll << endl;  
  //cout << "bkg_eeLjLjll_eff  == " << n_bkg_eeLjLjll*1.0/tree_bkg_eeLjLjll->GetEntries() << endl; 
  cout << "bkg_eeLjLjll_eff_Final  == " << n_bkg_eeLjLjll*1.0/total_bkg_eeLjLjll << endl;
      
      

 

// ------------------- 
 
  
  
  
  for (Long64_t ievt=0; ievt<tree_bkg_eebb->GetEntries();ievt++) {
  tree_bkg_eebb->GetEntry(ievt);
  
  histMll_bkg_bb->Fill(mll);
  histcosll_bkg_bb->Fill(cosll);
  histMbb_bkg_bb->Fill(mbb);
  histht_bkg_bb->Fill(ht);
  histptb_bkg_bb->Fill(ptb);
  histetab_bkg_bb->Fill(etab);
  histptll_bkg_bb->Fill(ptll);
  histmet_bkg_bb->Fill(met);
  histcoslb_bkg_bb->Fill(coslb);
  
  histjetsmulti_bkg_bb->Fill(jetsmulti);
  histbjetsmulti_bkg_bb->Fill(bjetsmulti);
  histpratio_bkg_bb->Fill(pratio);  
  histeleptonratio_bkg_bb->Fill(eleptonratio);
  histsplplm_bkg_bb->Fill(splplm);


//  cout << "mll_bkg_eebb  == " << mll << endl;  
//  cout << "eventweight_bkg_eebb  == " << eventweight << endl;  
  
if (mll > 15.0 && cosll < 0.40 && mbb > 20.0 && ptll < 20.0) {n_bkg_eebb++;}  //  && splplm < -0.001 coslb > -0.6 
  
      } 

  cout << "bkg_eebb_eff_1  == " << tree_bkg_eebb->GetEntries()*1.0/total_bkg_eebb << endl;    
  cout << "n_bkg_eebb  == " << n_bkg_eebb << endl;  
  //cout << "bkg_eebb_eff  == " << n_bkg_eebb*1.0/tree_bkg_eebb->GetEntries() << endl; 
  cout << "bkg_eebb_eff_Final  == " << n_bkg_eebb*1.0/total_bkg_eebb << endl;
  
 
 
    
// ------------------- 
 
 
 
 Double_t xl1=0.70, yl1=0.60, xl2=xl1+0.250, yl2=yl1+0.250;

TLegend *leg1 = new TLegend(xl1,yl1,xl2,yl2);
leg1->SetBorderSize(0);

leg1->AddEntry(histMll_signal_eebb_LL,"signal (eebb)","L")->SetTextColor(1);
leg1->AddEntry(histMll_bkg_eebb,"bkg (eebb)","L")->SetTextColor(2);
//leg1->AddEntry(histMll_bkg_eecc,"bkg (eecc)","L")->SetTextColor(4);
//leg1->AddEntry(histMll_bkg_eeLjLj,"bkg (eeqq) (uds)","L")->SetTextColor(6);



leg1->SetTextSize(0.05);
leg1->SetTextFont(12);
leg1->SetFillStyle(0);



// ------------------- 
 
 
 
TLegend *leg15 = new TLegend(xl1,yl1,xl2,yl2);
leg15->SetBorderSize(0);

leg15->AddEntry(histMll_signal_eebb_LL,"Signal (C^{e}_{LL})","L")->SetTextColor(1);
leg15->AddEntry(histMll_signal_eebb_LR,"Signal (C^{e}_{LR})","L")->SetTextColor(2);
leg15->AddEntry(histMll_signal_eebb_RL,"Signal (C^{e}_{RL})","L")->SetTextColor(4);
leg15->AddEntry(histMll_signal_eebb_RR,"Signal (C^{e}_{RR})","L")->SetTextColor(6);



leg15->SetTextSize(0.05);
leg15->SetTextFont(12);
leg15->SetFillStyle(0);


// --------------------




TCanvas* c1 = new TCanvas("c1"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histMll_signal_eebb_LL->GetXaxis()->SetTitle("M_{ll} [GeV]");
histMll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histMll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histMll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histMll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histMll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histMll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histMll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histMll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histMll_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histMll_signal_eebb_LL->SetLineWidth(2);
   histMll_bkg_eebb->SetLineWidth(2);
   histMll_bkg_eecc->SetLineWidth(2);   
   histMll_bkg_eeLjLj->SetLineWidth(2);      

   histMll_signal_eebb_LL->SetLineColor(1);
   histMll_bkg_eebb->SetLineColor(2);
   histMll_bkg_eecc->SetLineColor(4);
   histMll_bkg_eeLjLj->SetLineColor(6);

   histMll_signal_eebb_LL->DrawNormalized("hist");
   histMll_bkg_eebb->DrawNormalized("hist same");
//   histMll_bkg_eecc->DrawNormalized("hist same"); 
//   histMll_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c1->SaveAs("mll-ee.pdf");
//c1->SaveAs("mll.C");
//c1->SaveAs("mll.eps");
//c1->SaveAs("mll.root");


// ...................................................


TCanvas* c2 = new TCanvas("c2"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histcosll_signal_eebb_LL->GetXaxis()->SetTitle("cos(l,l)");
histcosll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histcosll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histcosll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histcosll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histcosll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histcosll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histcosll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histcosll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histcosll_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histcosll_signal_eebb_LL->SetLineWidth(2);
   histcosll_bkg_eebb->SetLineWidth(2);
   histcosll_bkg_eecc->SetLineWidth(2);   
   histcosll_bkg_eeLjLj->SetLineWidth(2);      

   histcosll_signal_eebb_LL->SetLineColor(1);
   histcosll_bkg_eebb->SetLineColor(2);
   histcosll_bkg_eecc->SetLineColor(4);
   histcosll_bkg_eeLjLj->SetLineColor(6);

   histcosll_signal_eebb_LL->DrawNormalized("hist");
   histcosll_bkg_eebb->DrawNormalized("hist same");
//   histcosll_bkg_eecc->DrawNormalized("hist same"); 
//   histcosll_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c2->SaveAs("cosll-ee.pdf");
//c2->SaveAs("cosll.C");
//c2->SaveAs("cosll.eps");
//c2->SaveAs("cosll.root");


// ...................................................


TCanvas* c3 = new TCanvas("c3"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histMbb_signal_eebb_LL->GetXaxis()->SetTitle("M_{bb} [GeV]");
histMbb_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histMbb_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histMbb_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histMbb_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histMbb_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histMbb_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histMbb_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histMbb_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histMbb_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histMbb_signal_eebb_LL->SetLineWidth(2);
   histMbb_bkg_eebb->SetLineWidth(2);
   histMbb_bkg_eecc->SetLineWidth(2);   
   histMbb_bkg_eeLjLj->SetLineWidth(2);      

   histMbb_signal_eebb_LL->SetLineColor(1);
   histMbb_bkg_eebb->SetLineColor(2);
   histMbb_bkg_eecc->SetLineColor(4);
   histMbb_bkg_eeLjLj->SetLineColor(6);

   histMbb_signal_eebb_LL->DrawNormalized("hist");
   histMbb_bkg_eebb->DrawNormalized("hist same");
//   histMbb_bkg_eecc->DrawNormalized("hist same"); 
//   histMbb_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c3->SaveAs("mbb-ee.pdf");
//c3->SaveAs("mbb.C");
//c3->SaveAs("mbb.eps");
//c3->SaveAs("mbb.root");


// ...................................................



TCanvas* c4 = new TCanvas("c4"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histht_signal_eebb_LL->GetXaxis()->SetTitle("H_{T} [GeV]");
histht_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histht_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histht_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histht_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histht_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histht_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histht_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histht_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histht_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histht_signal_eebb_LL->SetLineWidth(2);
   histht_bkg_eebb->SetLineWidth(2);
   histht_bkg_eecc->SetLineWidth(2);   
   histht_bkg_eeLjLj->SetLineWidth(2);      

   histht_signal_eebb_LL->SetLineColor(1);
   histht_bkg_eebb->SetLineColor(2);
   histht_bkg_eecc->SetLineColor(4);
   histht_bkg_eeLjLj->SetLineColor(6);

   histht_signal_eebb_LL->DrawNormalized("hist");
   histht_bkg_eebb->DrawNormalized("hist same");
//   histht_bkg_eecc->DrawNormalized("hist same"); 
//   histht_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c4->SaveAs("ht-ee.pdf");
//c4->SaveAs("ht.C");
//c4->SaveAs("ht.eps");
//c4->SaveAs("ht.root");


// ...................................................



TCanvas* c5 = new TCanvas("c5"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histptb_signal_eebb_LL->GetXaxis()->SetTitle("p_{T}^{b-tag} [GeV]");
histptb_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histptb_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histptb_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histptb_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histptb_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histptb_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histptb_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histptb_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histptb_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histptb_signal_eebb_LL->SetLineWidth(2);
   histptb_bkg_eebb->SetLineWidth(2);
   histptb_bkg_eecc->SetLineWidth(2);   
   histptb_bkg_eeLjLj->SetLineWidth(2);      

   histptb_signal_eebb_LL->SetLineColor(1);
   histptb_bkg_eebb->SetLineColor(2);
   histptb_bkg_eecc->SetLineColor(4);
   histptb_bkg_eeLjLj->SetLineColor(6);

   histptb_signal_eebb_LL->DrawNormalized("hist");
   histptb_bkg_eebb->DrawNormalized("hist same");
//   histptb_bkg_eecc->DrawNormalized("hist same"); 
//   histptb_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c5->SaveAs("ptb-ee.pdf");
//c5->SaveAs("ptb.C");
//c5->SaveAs("ptb.eps");
//c5->SaveAs("ptb.root");


// ...................................................




TCanvas* c6 = new TCanvas("c6"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histetab_signal_eebb_LL->GetXaxis()->SetTitle("#eta_{b-tag}");
histetab_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histetab_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histetab_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histetab_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histetab_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histetab_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histetab_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histetab_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histetab_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histetab_signal_eebb_LL->SetLineWidth(2);
   histetab_bkg_eebb->SetLineWidth(2);
   histetab_bkg_eecc->SetLineWidth(2);   
   histetab_bkg_eeLjLj->SetLineWidth(2);      

   histetab_signal_eebb_LL->SetLineColor(1);
   histetab_bkg_eebb->SetLineColor(2);
   histetab_bkg_eecc->SetLineColor(4);
   histetab_bkg_eeLjLj->SetLineColor(6);

   histetab_signal_eebb_LL->DrawNormalized("hist");
   histetab_bkg_eebb->DrawNormalized("hist same");
//   histetab_bkg_eecc->DrawNormalized("hist same"); 
//   histetab_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c6->SaveAs("etab-ee.pdf");
//c6->SaveAs("etab.C");
//c6->SaveAs("etab.eps");
//c6->SaveAs("etab.root");




// ...................................................




TCanvas* c7 = new TCanvas("c7"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histptll_signal_eebb_LL->GetXaxis()->SetTitle("p_{T}^{ll} [GeV]");
histptll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histptll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histptll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histptll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histptll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histptll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histptll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histptll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histptll_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histptll_signal_eebb_LL->SetLineWidth(2);
   histptll_bkg_eebb->SetLineWidth(2);
   histptll_bkg_eecc->SetLineWidth(2);   
   histptll_bkg_eeLjLj->SetLineWidth(2);      

   histptll_signal_eebb_LL->SetLineColor(1);
   histptll_bkg_eebb->SetLineColor(2);
   histptll_bkg_eecc->SetLineColor(4);
   histptll_bkg_eeLjLj->SetLineColor(6);

   histptll_signal_eebb_LL->DrawNormalized("hist");
   histptll_bkg_eebb->DrawNormalized("hist same");
//   histptll_bkg_eecc->DrawNormalized("hist same"); 
//   histptll_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c7->SaveAs("ptll-ee.pdf");
//c7->SaveAs("ptll.C");
//c7->SaveAs("ptll.eps");
//c7->SaveAs("ptll.root");


// ...................................................



TCanvas* c8 = new TCanvas("c8"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histmet_signal_eebb_LL->GetXaxis()->SetTitle("MET");
histmet_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histmet_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histmet_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histmet_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histmet_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histmet_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histmet_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histmet_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histmet_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histmet_signal_eebb_LL->SetLineWidth(2);
   histmet_bkg_eebb->SetLineWidth(2);
   histmet_bkg_eecc->SetLineWidth(2);   
   histmet_bkg_eeLjLj->SetLineWidth(2);      

   histmet_signal_eebb_LL->SetLineColor(1);
   histmet_bkg_eebb->SetLineColor(2);
   histmet_bkg_eecc->SetLineColor(4);
   histmet_bkg_eeLjLj->SetLineColor(6);

   histmet_signal_eebb_LL->DrawNormalized("hist");
   histmet_bkg_eebb->DrawNormalized("hist same");
//   histmet_bkg_eecc->DrawNormalized("hist same"); 
//   histmet_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c8->SaveAs("met-ee.pdf");
//c8->SaveAs("met.C");
//c8->SaveAs("met.eps");
//c8->SaveAs("met.root");


// ...................................................



TCanvas* c9 = new TCanvas("c9"," ",1);

//histMlb_signal_eebb_LL->SetTitle("m_{lb}");
histcoslb_signal_eebb_LL->GetXaxis()->SetTitle("cos(l,b)");
histcoslb_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histcoslb_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histcoslb_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histcoslb_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histcoslb_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histcoslb_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histcoslb_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histcoslb_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histcoslb_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histcoslb_signal_eebb_LL->SetLineWidth(2);
   histcoslb_bkg_eebb->SetLineWidth(2);
   histcoslb_bkg_eecc->SetLineWidth(2);   
   histcoslb_bkg_eeLjLj->SetLineWidth(2);      

   histcoslb_signal_eebb_LL->SetLineColor(1);
   histcoslb_bkg_eebb->SetLineColor(2);
   histcoslb_bkg_eecc->SetLineColor(4);
   histcoslb_bkg_eeLjLj->SetLineColor(6);

   histcoslb_signal_eebb_LL->DrawNormalized("hist");
   histcoslb_bkg_eebb->DrawNormalized("hist same");
//   histcoslb_bkg_eecc->DrawNormalized("hist same"); 
//   histcoslb_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c9->SaveAs("coslb-ee.pdf");
//c9->SaveAs("coslb.C");
//c9->SaveAs("coslb.eps");
//c9->SaveAs("coslb.root");


// ...................................................



TCanvas* c10 = new TCanvas("c10"," ",1);

//histMlb_signal_eebb_LL->SetTitle("m_{lb}");
histjetsmulti_signal_eebb_LL->GetXaxis()->SetTitle("Jet multiplicity");
histjetsmulti_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histjetsmulti_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histjetsmulti_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histjetsmulti_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histjetsmulti_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histjetsmulti_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histjetsmulti_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histjetsmulti_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histjetsmulti_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histjetsmulti_signal_eebb_LL->SetLineWidth(2);
   histjetsmulti_bkg_eebb->SetLineWidth(2);
   histjetsmulti_bkg_eecc->SetLineWidth(2);   
   histjetsmulti_bkg_eeLjLj->SetLineWidth(2);      

   histjetsmulti_signal_eebb_LL->SetLineColor(1);
   histjetsmulti_bkg_eebb->SetLineColor(2);
   histjetsmulti_bkg_eecc->SetLineColor(4);
   histjetsmulti_bkg_eeLjLj->SetLineColor(6);

   histjetsmulti_signal_eebb_LL->DrawNormalized("hist");
   histjetsmulti_bkg_eebb->DrawNormalized("hist same");
   histjetsmulti_bkg_eecc->DrawNormalized("hist same"); 
   histjetsmulti_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c10->SaveAs("jetsmulti-ee.pdf");
//c10->SaveAs("jetsmulti.C");
//c10->SaveAs("jetsmulti.eps");
//c10->SaveAs("jetsmulti.root");



// ...................................................



TCanvas* c11 = new TCanvas("c11"," ",1);

//histMlb_signal_eebb_LL->SetTitle("m_{lb}");
histbjetsmulti_signal_eebb_LL->GetXaxis()->SetTitle("b-tagged jet multiplicity");
histbjetsmulti_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histbjetsmulti_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histbjetsmulti_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histbjetsmulti_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histbjetsmulti_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histbjetsmulti_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histbjetsmulti_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histbjetsmulti_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histbjetsmulti_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histbjetsmulti_signal_eebb_LL->SetLineWidth(2);
   histbjetsmulti_bkg_eebb->SetLineWidth(2);
   histbjetsmulti_bkg_eecc->SetLineWidth(2);   
   histbjetsmulti_bkg_eeLjLj->SetLineWidth(2);      

   histbjetsmulti_signal_eebb_LL->SetLineColor(1);
   histbjetsmulti_bkg_eebb->SetLineColor(2);
   histbjetsmulti_bkg_eecc->SetLineColor(4);
   histbjetsmulti_bkg_eeLjLj->SetLineColor(6);

   histbjetsmulti_signal_eebb_LL->DrawNormalized("hist");
   histbjetsmulti_bkg_eebb->DrawNormalized("hist same");
//   histbjetsmulti_bkg_eecc->DrawNormalized("hist same"); 
//   histbjetsmulti_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c11->SaveAs("bjetsmulti-ee.pdf");
//c11->SaveAs("bjetsmulti.C");
//c11->SaveAs("bjetsmulti.eps");
//c11->SaveAs("bjetsmulti.root");




// ...................................................



TCanvas* c12 = new TCanvas("c12"," ",1);

//histMlb_signal_eebb_LL->SetTitle("m_{lb}");
histpratio_signal_eebb_LL->GetXaxis()->SetTitle("p^{ll}/p^{bb}");
histpratio_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histpratio_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histpratio_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histpratio_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histpratio_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histpratio_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histpratio_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

   histpratio_signal_eebb_LL->GetYaxis()->SetRangeUser(0,1000);
//   histpratio_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histpratio_signal_eebb_LL->SetLineWidth(2);
   histpratio_bkg_eebb->SetLineWidth(2);
   histpratio_bkg_eecc->SetLineWidth(2);   
   histpratio_bkg_eeLjLj->SetLineWidth(2);      

   histpratio_signal_eebb_LL->SetLineColor(1);
   histpratio_bkg_eebb->SetLineColor(2);
   histpratio_bkg_eecc->SetLineColor(4);
   histpratio_bkg_eeLjLj->SetLineColor(6);

   histpratio_signal_eebb_LL->DrawNormalized("hist");
   histpratio_bkg_eebb->DrawNormalized("hist same");
//   histpratio_bkg_eecc->DrawNormalized("hist same"); 
//   histpratio_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c12->SaveAs("pratio-ee.pdf");
//c12->SaveAs("pratio.C");
//c12->SaveAs("pratio.eps");
//c12->SaveAs("pratio.root");





// ...................................................



TCanvas* c13 = new TCanvas("c13"," ",1);

//histMlb_signal_eebb_LL->SetTitle("m_{lb}");
histeleptonratio_signal_eebb_LL->GetXaxis()->SetTitle("E^{l+}/E^{l-}");
histeleptonratio_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histeleptonratio_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histeleptonratio_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histeleptonratio_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histeleptonratio_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histeleptonratio_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histeleptonratio_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histeleptonratio_signal_eebb_LL->GetYaxis()->SetRangeUser(0,1000);
//   histeleptonratio_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histeleptonratio_signal_eebb_LL->SetLineWidth(2);
   histeleptonratio_bkg_eebb->SetLineWidth(2);
   histeleptonratio_bkg_eecc->SetLineWidth(2);   
   histeleptonratio_bkg_eeLjLj->SetLineWidth(2);      

   histeleptonratio_signal_eebb_LL->SetLineColor(1);
   histeleptonratio_bkg_eebb->SetLineColor(2);
   histeleptonratio_bkg_eecc->SetLineColor(4);
   histeleptonratio_bkg_eeLjLj->SetLineColor(6);

   histeleptonratio_signal_eebb_LL->DrawNormalized("hist");
   histeleptonratio_bkg_eebb->DrawNormalized("hist same");
//   histeleptonratio_bkg_eecc->DrawNormalized("hist same"); 
//   histeleptonratio_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c13->SaveAs("eleptonratio-ee.pdf");
//c13->SaveAs("eleptonratio.C");
//c13->SaveAs("eleptonratio.eps");
//c13->SaveAs("eleptonratio.root");





// ...................................................



TCanvas* c14 = new TCanvas("c14"," ",1);

//histMlb_signal_eebb_LL->SetTitle("m_{lb}");
histsplplm_signal_eebb_LL->GetXaxis()->SetTitle("p^{l+}.p^{l-}/s");
histsplplm_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histsplplm_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histsplplm_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histsplplm_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histsplplm_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histsplplm_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histsplplm_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histsplplm_signal_eebb_LL->GetYaxis()->SetRangeUser(0,1000);
//   histsplplm_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histsplplm_signal_eebb_LL->SetLineWidth(2);
   histsplplm_bkg_eebb->SetLineWidth(2);
   histsplplm_bkg_eecc->SetLineWidth(2);   
   histsplplm_bkg_eeLjLj->SetLineWidth(2);      

   histsplplm_signal_eebb_LL->SetLineColor(1);
   histsplplm_bkg_eebb->SetLineColor(2);
   histsplplm_bkg_eecc->SetLineColor(4);
   histsplplm_bkg_eeLjLj->SetLineColor(6);

   histsplplm_signal_eebb_LL->DrawNormalized("hist");
   histsplplm_bkg_eebb->DrawNormalized("hist same");
//   histsplplm_bkg_eecc->DrawNormalized("hist same"); 
//   histsplplm_bkg_eeLjLj->DrawNormalized("hist same"); 

   

   leg1->Draw("same");
 
c14->SaveAs("splplm-ee.pdf");
//c14->SaveAs("splplm.C");
//c14->SaveAs("splplm.eps");
//c14->SaveAs("eleptonratio.root");




// --------------------



TCanvas* c15 = new TCanvas("c15"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histMll_signal_eebb_LL->GetXaxis()->SetTitle("M_{ll} [GeV]");
histMll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histMll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histMll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histMll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histMll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histMll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histMll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histMll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histMll_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histMll_signal_eebb_LL->SetLineWidth(2);
   histMll_signal_eebb_LR->SetLineWidth(2);
   histMll_signal_eebb_RL->SetLineWidth(2);   
   histMll_signal_eebb_RR->SetLineWidth(2);      

   histMll_signal_eebb_LL->SetLineColor(1);
   histMll_signal_eebb_LR->SetLineColor(2);
   histMll_signal_eebb_RL->SetLineColor(4);
   histMll_signal_eebb_RR->SetLineColor(6);
   
   histMll_signal_eebb_LL->SetLineStyle(1);
   histMll_signal_eebb_LR->SetLineStyle(1);
   histMll_signal_eebb_RL->SetLineStyle(1);
   histMll_signal_eebb_RR->SetLineStyle(1);    
   

   histMll_signal_eebb_LL->DrawNormalized("hist");
   histMll_signal_eebb_LR->DrawNormalized("hist same");
   histMll_signal_eebb_RL->DrawNormalized("hist same"); 
   histMll_signal_eebb_RR->DrawNormalized("hist same"); 

   

   leg15->Draw("same");
 
c15->SaveAs("mll_signals-ee.pdf");
//c15->SaveAs("mll_signals.C");
//c15->SaveAs("mll_signals.eps");
//c15->SaveAs("mll_signals.root");





// ...................................................


TCanvas* c16 = new TCanvas("c16"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histcosll_signal_eebb_LL->GetXaxis()->SetTitle("cos(l,l)");
histcosll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histcosll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histcosll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histcosll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histcosll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histcosll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histcosll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histcosll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histcosll_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histcosll_signal_eebb_LL->SetLineWidth(2);
   histcosll_signal_eebb_LR->SetLineWidth(2);
   histcosll_signal_eebb_RL->SetLineWidth(2);   
   histcosll_signal_eebb_RR->SetLineWidth(2);      

   histcosll_signal_eebb_LL->SetLineColor(1);
   histcosll_signal_eebb_LR->SetLineColor(2);
   histcosll_signal_eebb_RL->SetLineColor(4);
   histcosll_signal_eebb_RR->SetLineColor(6);
   
   histcosll_signal_eebb_LL->SetLineStyle(1);
   histcosll_signal_eebb_LR->SetLineStyle(1);
   histcosll_signal_eebb_RL->SetLineStyle(1);
   histcosll_signal_eebb_RR->SetLineStyle(1); 
   

   histcosll_signal_eebb_LL->DrawNormalized("hist");
   histcosll_signal_eebb_LR->DrawNormalized("hist same");
   histcosll_signal_eebb_RL->DrawNormalized("hist same"); 
   histcosll_signal_eebb_RR->DrawNormalized("hist same"); 

   

   leg15->Draw("same");
 
c16->SaveAs("cosll_signals-ee.pdf");
//c16->SaveAs("cosll_signals.C");
//c16->SaveAs("cosll_signals.eps");
//c16->SaveAs("cosll_signals.root");



// ...................................................




TCanvas* c17 = new TCanvas("c17"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histptll_signal_eebb_LL->GetXaxis()->SetTitle("p_{T}^{ll} [GeV]");
histptll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histptll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histptll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histptll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histptll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histptll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histptll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histptll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histptll_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histptll_signal_eebb_LL->SetLineWidth(2);
   histptll_signal_eebb_LR->SetLineWidth(2);
   histptll_signal_eebb_RL->SetLineWidth(2);   
   histptll_signal_eebb_RR->SetLineWidth(2);      

   histptll_signal_eebb_LL->SetLineColor(1);
   histptll_signal_eebb_LR->SetLineColor(2);
   histptll_signal_eebb_RL->SetLineColor(4);
   histptll_signal_eebb_RR->SetLineColor(6);
   
   histptll_signal_eebb_LL->SetLineStyle(1);
   histptll_signal_eebb_LR->SetLineStyle(1);
   histptll_signal_eebb_RL->SetLineStyle(1);
   histptll_signal_eebb_RR->SetLineStyle(1); 
   

   histptll_signal_eebb_LL->DrawNormalized("hist");
   histptll_signal_eebb_LR->DrawNormalized("hist same");
   histptll_signal_eebb_RL->DrawNormalized("hist same"); 
   histptll_signal_eebb_RR->DrawNormalized("hist same"); 

   

   leg15->Draw("same");
 
c17->SaveAs("ptll_signals-ee.pdf");
//c17->SaveAs("ptll_signals.C");
//c17->SaveAs("ptll_signals.eps");
//c17->SaveAs("ptll_signals.root");





// ...................................................



TCanvas* c18 = new TCanvas("c18"," ",1);

//histMlb_signal_eebb_LL->SetTitle("m_{lb}");
histsplplm_signal_eebb_LL->GetXaxis()->SetTitle("p^{l+}.p^{l-}/s");
histsplplm_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histsplplm_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histsplplm_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histsplplm_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histsplplm_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histsplplm_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histsplplm_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histsplplm_signal_eebb_LL->GetYaxis()->SetRangeUser(0,1000);
//   histsplplm_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histsplplm_signal_eebb_LL->SetLineWidth(2);
   histsplplm_signal_eebb_LR->SetLineWidth(2);
   histsplplm_signal_eebb_RL->SetLineWidth(2);   
   histsplplm_signal_eebb_RR->SetLineWidth(2);      

   histsplplm_signal_eebb_LL->SetLineColor(1);
   histsplplm_signal_eebb_LR->SetLineColor(2);
   histsplplm_signal_eebb_RL->SetLineColor(4);
   histsplplm_signal_eebb_RR->SetLineColor(6);
   
   histsplplm_signal_eebb_LL->SetLineStyle(1);
   histsplplm_signal_eebb_LR->SetLineStyle(1);
   histsplplm_signal_eebb_RL->SetLineStyle(1);
   histsplplm_signal_eebb_RR->SetLineStyle(1); 
   

   histsplplm_signal_eebb_LL->DrawNormalized("hist");
   histsplplm_signal_eebb_LR->DrawNormalized("hist same");
   histsplplm_signal_eebb_RL->DrawNormalized("hist same"); 
   histsplplm_signal_eebb_RR->DrawNormalized("hist same"); 

   

   leg15->Draw("same");
 
c18->SaveAs("splplm_signals-ee.pdf");
//c18->SaveAs("splplm_signals.C");
//c18->SaveAs("splplm_signals.eps");
//c18->SaveAs("splplm_signals.root");



// ...................................................


TCanvas* c19 = new TCanvas("c19"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histMbb_signal_eebb_LL->GetXaxis()->SetTitle("M_{bb} [GeV]");
histMbb_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histMbb_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histMbb_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histMbb_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histMbb_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histMbb_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histMbb_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histMbb_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histMbb_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histMbb_signal_eebb_LL->SetLineWidth(2);
   histMbb_signal_eebb_LR->SetLineWidth(2);
   histMbb_signal_eebb_RL->SetLineWidth(2);   
   histMbb_signal_eebb_RR->SetLineWidth(2);      

   histMbb_signal_eebb_LL->SetLineColor(1);
   histMbb_signal_eebb_LR->SetLineColor(2);
   histMbb_signal_eebb_RL->SetLineColor(4);
   histMbb_signal_eebb_RR->SetLineColor(6);

   histMbb_signal_eebb_LL->DrawNormalized("hist");
   histMbb_signal_eebb_LR->DrawNormalized("hist same");
   histMbb_signal_eebb_RL->DrawNormalized("hist same"); 
   histMbb_signal_eebb_RR->DrawNormalized("hist same"); 

   

   leg15->Draw("same");
 
c19->SaveAs("mbb_signals-ee.pdf");
//c19->SaveAs("mbb_signals.C");
//c19->SaveAs("mbb_signals.eps");
//c19->SaveAs("mbb_signals.root");





// ...................................................




TCanvas* c20 = new TCanvas("c20"," ",1);

//histMll_signal_eebb_LL->SetTitle("m_{ll}");
histptll_signal_eebb_LL->GetXaxis()->SetTitle("p_{T}^{ll} [GeV]");
histptll_signal_eebb_LL->GetXaxis()->SetTitleOffset(1.25);
histptll_signal_eebb_LL->GetXaxis()->SetLabelFont(22);
histptll_signal_eebb_LL->GetXaxis()->SetTitleFont(22);
histptll_signal_eebb_LL->GetYaxis()->SetTitle("Events normalised to unit area");
histptll_signal_eebb_LL->GetYaxis()->SetTitleOffset(1.40);
histptll_signal_eebb_LL->GetYaxis()->SetLabelFont(22);
histptll_signal_eebb_LL->GetYaxis()->SetTitleFont(22);

//   histptll_signal_eebb_LL->GetXaxis()->SetRangeUser(0,1);
//   histptll_bkg_eebb->GetXaxis()->SetRangeUser(0,1);

   histptll_signal_eebb_LL->SetLineWidth(2);
   histptll_signal_eebb_LR->SetLineWidth(2);
   histptll_signal_eebb_RL->SetLineWidth(2);   
   histptll_signal_eebb_RR->SetLineWidth(2);      

   histptll_signal_eebb_LL->SetLineColor(1);
   histptll_signal_eebb_LR->SetLineColor(2);
   histptll_signal_eebb_RL->SetLineColor(4);
   histptll_signal_eebb_RR->SetLineColor(6);

   histptll_signal_eebb_LL->DrawNormalized("hist");
   histptll_signal_eebb_LR->DrawNormalized("hist same");
   histptll_signal_eebb_RL->DrawNormalized("hist same"); 
   histptll_signal_eebb_RR->DrawNormalized("hist same"); 

   

   leg15->Draw("same");
 
c20->SaveAs("ptll-ee.pdf");
//c20->SaveAs("ptll.C");
//c20->SaveAs("ptll.eps");
//c20->SaveAs("ptll.root");




}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
