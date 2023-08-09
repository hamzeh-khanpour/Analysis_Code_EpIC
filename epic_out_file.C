
// Stdlib header file for input and output.
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>


// include statements for all needed dependencies  
 
#include "TH1F.h"
#include "TTree.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"
#include "TLorentzVector.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1D.h"
#include "TVirtualFitter.h"
#include "TMath.h"
#include "stdlib.h"
#include "math.h"
#include "TPaveText.h"
#include <string>
#include <vector>  
#include "TVirtualFitter.h"
#include "TBranch.h"
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include "TGraph.h"
#include "TFrame.h"
#include "TAttFill.h"
#include "TNamed.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TRandom3.h"
#include "THStack.h"
#include "TLegend.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "Math/LorentzVector.h"


// epic_out_file

#define epic_out_file_cxx
#include "epic_out_file.h"


  // Book histograms
  TH1 *histMassdilepton = new TH1F("mass", "M_{inv}(l_{1}, l_{2})", 100, 1.0, 100.0);
  TH1 *histPtdilepton = new TH1F("Pt", "P_{t}(l_{1}, l_{2})", 100, 1.0, 100.0);

    TLorentzVector MyGoodLeptonplus;
    TLorentzVector MyGoodLeptonminus;
    TLorentzVector MydiLepton;
    
   Float_t Mll = 0.0;
   Float_t Ptll = 0.0;


void epic_out_file::Loop()
{
//   In a ROOT session, you can do:
//      root> .L epic_out_file.C
//      root> epic_out_file t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
    
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries; jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      
      
//     MyGoodLeptonplus.clear();
//     MyGoodLeptonminus.clear();
//     MydiLepton.clear();      
    
     Mll = 0.0; 
     Ptll = 0.0;    
      
//     cout << "kMaxparticles= "   <<  kMaxparticles  << endl;
//     cout << "nentries= "   <<  nentries  << endl;
//     cout << "event_number= "   <<  event_number  << endl;
//     cout << "particles_pid= "   <<  particles_pid[1]  << endl;
//     cout << "particles_status= "   <<  particles_status[1]  << endl;
//     cout << "particles_mass= "   <<  particles_mass[1]  << endl;
//     cout << "particles_momentum_m_v1= "   <<  particles_momentum_m_v1[1]  << endl;
     
     
//    for (Int_t i = 1; i <= kMaxparticles; i++) {      
//     cout << "particles_pid= "   <<  particles_pid[i]  << endl;        
//    }
     
     
    for (Int_t i = 1; i <= kMaxparticles; i++) {      
     
        if (particles_pid[i] == 13 ) {  // && particles_status[i] == 5 

            
 TVector3 Muonplus;
            
//        cout << "particles_momentum_m_v1= "   <<  particles_momentum_m_v1[i]  << endl;        
//        cout << "particles_momentum_m_v2= "   <<  particles_momentum_m_v2[i]  << endl;     
//        cout << "particles_momentum_m_v3= "   <<  particles_momentum_m_v3[i]  << endl;     
//        cout << "particles_momentum_m_v4= "   <<  particles_momentum_m_v4[i]  << endl;     
        
  Muonplus.SetXYZ( particles_momentum_m_v1[i], particles_momentum_m_v2[i], particles_momentum_m_v3[i] );

//        cout << "Muonplus Px = "   <<  Muonplus.Px()  << endl;    
        
  MyGoodLeptonplus.SetPxPyPzE( particles_momentum_m_v1[i], particles_momentum_m_v2[i], particles_momentum_m_v3[i], particles_momentum_m_v4[i] );
  
//        cout << "MyGoodLeptonplus Px = "   <<  MyGoodLeptonplus.Px()  << endl;    

        

        
  
        }
        
        
        else if (particles_pid[i] == -13 ) {  // && particles_status[i] == 5 

            
 TVector3 Muonminus;
            
//        cout << "particles_momentum_m_v1= "   <<  particles_momentum_m_v1[i]  << endl;        
//        cout << "particles_momentum_m_v2= "   <<  particles_momentum_m_v2[i]  << endl;     
//        cout << "particles_momentum_m_v3= "   <<  particles_momentum_m_v3[i]  << endl;     
//        cout << "particles_momentum_m_v4= "   <<  particles_momentum_m_v4[i]  << endl;     
        
  Muonminus.SetXYZ( particles_momentum_m_v1[i], particles_momentum_m_v2[i], particles_momentum_m_v3[i] );

//        cout << "Muonminus Px = "   <<  Muonminus.Px()  << endl;    
        
  MyGoodLeptonminus.SetPxPyPzE( particles_momentum_m_v1[i], particles_momentum_m_v2[i], particles_momentum_m_v3[i], particles_momentum_m_v4[i] );
  
//        cout << "MyGoodLeptonminus Px = "   <<  MyGoodLeptonminus.Px()  << endl;    
//        cout << "MyGoodLeptonminus Pt = "   <<  MyGoodLeptonminus.Pt()  << endl;            
//        cout << "MyGoodLeptonminus M = "    <<  MyGoodLeptonminus.M()   << endl;      
//        cout << "MyGoodLeptonminus P = "    <<  MyGoodLeptonminus.P()   << endl;   
//        cout << "MyGoodLeptonminus Pt = "   <<  MyGoodLeptonminus.Pt()  << endl;   
  
        }
        
    }
    
    
      MydiLepton = MyGoodLeptonplus + MyGoodLeptonminus;

//      cout << "MydiLepton Pt =" << MydiLepton.Pt() << endl; 
//      cout << "MydiLepton M ="  << MydiLepton.M()  << endl;       
//      cout << "MydiLepton P ="  << MydiLepton.P()  << endl;     
      
      Mll = MydiLepton.M();
      
     cout << "Mll ="  << Mll  << endl;       
      

   }
}



