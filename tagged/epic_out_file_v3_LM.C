
// Exclusive lepton pair production at the EIC
// Hamzeh & Hadi & Krzysztof
// 15 August 2023 

// Stdlib header file for input and output 
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


// epic_out_file_v3_LM

#define epic_out_file_v3_LM_cxx
#include "epic_out_file_v3_LM.h"




double getPhiL(const TLorentzVector& q,
                const TLorentzVector& p, const TLorentzVector& pS, const TLorentzVector& e,
                const TLorentzVector& eS) {

	TVector3 boost;
	TLorentzVector q_boosted, p_boosted, pS_boosted, e_boosted, eS_boosted;
	double sinb2, cosb2;
	double sign;

	boost = (q+pS).BoostVector();
	q_boosted = q;                q_boosted.Boost(-boost);
	p_boosted = p;                p_boosted.Boost(-boost);
	pS_boosted = pS;              pS_boosted.Boost(-boost);
	e_boosted = e;                e_boosted.Boost(-boost);
	eS_boosted = eS;              eS_boosted.Boost(-boost);

	TVector3 a = pS_boosted.Vect().Unit().Cross(p_boosted.Vect().Unit());
	TVector3 b = eS_boosted.Vect().Unit().Cross(e_boosted.Vect().Unit());

	sign = a.Cross(b).Dot((pS_boosted.Vect()).Unit());
	sign /= fabs(sign);

	sinb2 = a.Cross(b).Mag();
	cosb2 = a.Dot(b);

	double phi = atan2(sign*sinb2, cosb2);
	if( phi < 0. ) phi = phi + 2.*TMath::Pi();

	return phi;
}





double getThetaL(const TLorentzVector& q,  const TLorentzVector& pS, const TLorentzVector& e, 
                const TLorentzVector& eS) {

	TVector3 boost;
	TLorentzVector q_boosted, p_boosted, pS_boosted, e_boosted, eS_boosted;
	double sinb2, cosb2;
	double sign;

	boost = (q+pS).BoostVector();

	q_boosted = q;                q_boosted.Boost(-boost);
	pS_boosted = pS;              pS_boosted.Boost(-boost);
	e_boosted = e;                e_boosted.Boost(-boost);
	eS_boosted = eS;              eS_boosted.Boost(-boost);

	boost = (e_boosted+eS_boosted).BoostVector();

	pS_boosted.Boost(-boost);
	e_boosted.Boost(-boost);
	eS_boosted.Boost(-boost);

	return pS_boosted.Vect().Angle(e_boosted.Vect());
}




TFile *target;
TTree *Tsignal_EIC = new TTree("EIC_BH_LM","EIC_BH_LM");
TFile *F;


// **********************************************************************   
// Book Histograms 
// **********************************************************************   

    TH1 *histMassdilepton =  new TH1F("M_{inv}", "", 40, 0.0, 10.0);
    TH1 *histPtdilepton   =  new TH1F("Pt", "",      30, 0.0, 1.0);
    TH1 *histtvalue       =  new TH1F("tvalue", "",  30, 0.0, 4.0);
    TH1 *histthetal       =  new TH1F("thetal", "",  30, 0.0, 4.0);
    TH1 *histphil         =  new TH1F("phil", "",    30, 0.0, 7.0);

    TH1 *histetal         =  new TH1F("etal", "",    30, -3.0, 3.0);
    TH1 *histq2           =  new TH1F("q2", "",      30, 0.0, 0.01);
    TH1 *histq2prime      =  new TH1F("q2prime", "", 30, 1.0, 10.0);

    TH1 *histepT          =  new TH1F("epT", "",     30, 0.0, 1.0);


    TLorentzVector MyGoodLeptonplus;
    TLorentzVector MyGoodLeptonminus;
    TLorentzVector MydiLepton;

    TLorentzVector Electronin;    
    TLorentzVector Electronout;    
    
    TLorentzVector Protonin;    
    TLorentzVector Protonout;

    TLorentzVector t;    

    TLorentzVector QPrim;
    TLorentzVector q;


    TVector3 boost1, boost2;
    TLorentzVector p_boosted, pS_boosted, e_boosted, eS_boosted;
    
    
   Float_t Mll = 0.0;
   Float_t Ptll = 0.0;
   Float_t tvalue = 0.0;

   Float_t sinb2  = 0.0;
   Float_t cosb2  = 0.0;;
   Float_t sign  = 0.0;;

   Float_t thetaL = 0.0;
   Float_t thetal = 0.0;

   Float_t phiL = 0.0;
   Float_t phil = 0.0;

   Float_t etaL = 0.0;
   Float_t etal = 0.0;

   Float_t Q2 = 0.0;
   Float_t q2 = 0.0;

   Float_t Q2prime = 0.0;
   Float_t q2prime = 0.0;

   Float_t epT = 0.0;

   Int_t N_Cut_I = 0.0;
   Int_t N_Cut_II = 0.0;
   Int_t N_Cut_III = 0.0;  
   Int_t N_Cut_IIII = 0.0;  

   
   Float_t  integrated_luminosity = 0.0;
   Float_t  integrated_cross_section_value_BH = 0.0;
   Float_t  integrated_cross_section_value_TCS = 0.0;
   Float_t  integrated_cross_section_value_All = 0.0;

   Float_t  event_weight_BH  = 0.0;
   Float_t  event_weight_TCS = 0.0;
   Float_t  event_weight_All = 0.0;
     

void epic_out_file_v3_LM::Loop()
{
//   In a ROOT session, you can do:
//      root> .L epic_out_file_v3_LM.C
//      root> epic_out_file_v3_LM t
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
 

	Tsignal_EIC->Branch("Mll",&Mll);
	Tsignal_EIC->Branch("Ptll",&Ptll);
	Tsignal_EIC->Branch("tvalue",&tvalue);
	Tsignal_EIC->Branch("thetal",&thetal);    
	Tsignal_EIC->Branch("phil",&phil);

  	Tsignal_EIC->Branch("etal",&etal);
	Tsignal_EIC->Branch("q2",&q2);
	Tsignal_EIC->Branch("q2prime",&q2prime);

	Tsignal_EIC->Branch("epT",&epT);

    
   gStyle->SetOptStat(0);   
    

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries; jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      

      Float_t  integrated_luminosity = 300.0 / 1000.0; // fb^{-1} 

      Float_t  integrated_cross_section_value_BH  = 3.355        * 1000.0;   //   nb   BH       LM *
      Float_t  integrated_cross_section_value_TCS = 0.00207609   * 1000.0;   //   nb   TCS      LM *
      Float_t  integrated_cross_section_value_All = 3.79989      * 1000.0;   //   nb   BH+TCS   LM *

//      Float_t  integrated_cross_section_value_BH  = 0.219293       * 1000.0;   //   nb   BH       HM *
//      Float_t  integrated_cross_section_value_TCS = 0.0000504905   * 1000.0;   //   nb   TCS      HM *
//      Float_t  integrated_cross_section_value_All = 0.247091       * 1000.0;   //   nb   BH+TCS   HM *

      Float_t  event_weight_BH  = integrated_cross_section_value_BH  * 1.0 / nentries;
      Float_t  event_weight_TCS = integrated_cross_section_value_TCS * 1.0 / nentries;
      Float_t  event_weight_All = integrated_cross_section_value_All * 1.0 / nentries;
      
      
//     MyGoodLeptonplus.clear();
//     MyGoodLeptonminus.clear();
//     MydiLepton.clear();      
    
//      Mll = 0.0; 
//      Ptll = 0.0;  
//      tvalue = 0.0;

//     cout << "kMaxparticles= "   <<  kMaxparticles  << endl;
    // cout << "nentries= "   <<  nentries  << endl;
//     cout << "event_number= "   <<  event_number  << endl;
//     cout << "particles_pid= "   <<  particles_pid[1]  << endl;
//     cout << "particles_status= "   <<  particles_status[1]  << endl;
//     cout << "particles_mass= "   <<  particles_mass[1]  << endl;
//     cout << "particles_momentum_m_v1= "   <<  particles_momentum_m_v1[1]  << endl;
     
     
//    for (Int_t i = 1; i <= kMaxparticles; i++) {      
//     cout << "particles_pid= "   <<  particles_pid[i]  << endl;        
//    }
     
     
// ============================================================================================
      
        
//        if ( kMaxparticles == 0 ) { 


  Electronin.SetPxPyPzE( particles_momentum_m_v1[0], particles_momentum_m_v2[0], particles_momentum_m_v3[0], particles_momentum_m_v4[0] );
  
//        cout << "Electronin Pz = "   <<  Electronin.Pz()  << endl;    
//        cout << "Electronin E = "   <<  Electronin.E()  << endl;    

 //       }  
        
//        else if ( kMaxparticles == 1 ) {  


  Electronout.SetPxPyPzE( particles_momentum_m_v1[1], particles_momentum_m_v2[1], particles_momentum_m_v3[1], particles_momentum_m_v4[1] );
  
//        cout << "Electronout Pz = "   <<  Electronout.Pz()  << endl;    
//        cout << "Electronout E = "   <<  Electronout.E()  << endl;    
//        cout << "Electronout Theta = "   <<  Electronout.Theta()  << endl;    
  
//        }  
  


 

// ============================================================================================
 
 
 
//        if ( kMaxparticles == 3 ) {  // particles_pid[i] == 2212 && particles_status[i] == 0


  Protonin.SetPxPyPzE( particles_momentum_m_v1[3], particles_momentum_m_v2[3], particles_momentum_m_v3[3], particles_momentum_m_v4[3] );
  
//        cout << "Protonin Px = "   <<  Protonin.Px()  << endl;    

 //       }  
        
//        else if ( kMaxparticles == 5 ) {  // particles_pid[i] == 2212 && particles_status[i] == -2


  Protonout.SetPxPyPzE( particles_momentum_m_v1[5], particles_momentum_m_v2[5], particles_momentum_m_v3[5], particles_momentum_m_v4[5] );
  
//        cout << "Protonout Px = "   <<  Protonout.Px()  << endl;    

//        }  
    


// ============================================================================================       

      
    for (Int_t i = 1; i <= kMaxparticles; i++) {      
     
        if ( particles_pid[i] == -13 ) {  // && particles_status[i] == 5 

            
 TVector3 Muonplus;
            
//        cout << "particles_status= "          <<  particles_status[i]  << endl;        
//        cout << "particles_momentum_m_v1= "   <<  particles_momentum_m_v1[i]  << endl;        
//        cout << "particles_momentum_m_v2= "   <<  particles_momentum_m_v2[i]  << endl;     
//        cout << "particles_momentum_m_v3= "   <<  particles_momentum_m_v3[i]  << endl;     
//        cout << "particles_momentum_m_v4= "   <<  particles_momentum_m_v4[i]  << endl;     
        
  Muonplus.SetXYZ( particles_momentum_m_v1[i], particles_momentum_m_v2[i], particles_momentum_m_v3[i] );

//        cout << "Muonplus Px = "   <<  Muonplus.Px()  << endl;    
        
  MyGoodLeptonplus.SetPxPyPzE( particles_momentum_m_v1[i], particles_momentum_m_v2[i], particles_momentum_m_v3[i], particles_momentum_m_v4[i] );
  
//        cout << "MyGoodLeptonplus Px = "   <<  MyGoodLeptonplus.Px()  << endl;    

        }


        else if ( particles_pid[i] == 13 ) {  // && particles_status[i] == 5 

            
 TVector3 Muonminus;
            
//        cout << "particles_momentum_m_v1= "   <<  particles_momentum_m_v1[i]  << endl;        
//        cout << "particles_momentum_m_v2= "   <<  parti	Tsig_Afb_ee_kt_ES_REC->Fill();cles_momentum_m_v2[i]  << endl;     
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
        
        
    }  // End do loop on kMaxparticles
    


// ============================================================================================


  QPrim.SetPxPyPzE( particles_momentum_m_v1[4], particles_momentum_m_v2[4], particles_momentum_m_v3[4], particles_momentum_m_v4[4] );

  q.SetPxPyPzE( particles_momentum_m_v1[2], particles_momentum_m_v2[2], particles_momentum_m_v3[2], particles_momentum_m_v4[2] );


 // cout << "QPrim Px = "   <<  QPrim.Px()  << endl;


	boost1 = (QPrim + Protonout).BoostVector();

	p_boosted  = Protonin;                      p_boosted.Boost(-boost1);
    pS_boosted = Protonout;                     pS_boosted.Boost(-boost1);
	e_boosted  = MyGoodLeptonminus;             e_boosted.Boost(-boost1);
    eS_boosted = MyGoodLeptonplus;              eS_boosted.Boost(-boost1);


    TVector3 a = pS_boosted.Vect().Unit().Cross(p_boosted.Vect().Unit());
	TVector3 b = eS_boosted.Vect().Unit().Cross(e_boosted.Vect().Unit());

	sign = a.Cross(b).Dot((pS_boosted.Vect()).Unit());
	sign /= fabs(sign);

	sinb2 = a.Cross(b).Mag();
	cosb2 = a.Dot(b);

	phiL = atan2(sign*sinb2, cosb2);
	if( phiL < 0.0 ) phiL = phiL + 2.0*TMath::Pi();


// -----------------------------------------------------


	boost2 = (e_boosted+eS_boosted).BoostVector();

	pS_boosted.Boost(-boost2);
	e_boosted.Boost(-boost2);


    thetaL = pS_boosted.Vect().Angle(e_boosted.Vect());

//      cout << "thetaL  = "  << thetaL   << endl;

// ============================================================================================



 Float_t Electronin_E  = Electronin.E();
 Float_t Electronout_E = Electronout.E();

 Float_t Energy_Ratio = Electronout_E*1.0/Electronin_E*1.0;


// if (Energy_Ratio < 0.50  ||  Energy_Ratio > 0.99) { continue; }

//        cout << "Energy_Ratio = "   <<  Energy_Ratio  << endl;


 Float_t Pi = 3.14159265359;
 Float_t Pi_Theta_e = Pi - Electronout.Theta();



// if (Pi_Theta_e > 10.0/1000.0) { continue; }  // 10 mrad

//       cout << "Pi_Theta_e = "   <<  Pi_Theta_e  << endl;


 if ( !(Energy_Ratio >=  0.50  &&  Energy_Ratio <=  0.90 &&  Pi_Theta_e <=  10.0/1000.0) ) { continue; }

 N_Cut_I++;




// ============================================================================================ 



 Float_t xL = Protonout.Pz() / Protonin.P();

// if (xL < 0.97) {
//   cout << "xL = "   <<  xL  << endl;
// }


 Float_t Protonout_Pt = Protonout.Pt();

 if ( !(Protonout_Pt >=  0.10  ||  xL <=  0.97) ) { continue; }


//        cout << "Protonout_Pt = "   <<  Protonout_Pt  << endl;

// if (xL < 0.97) {
//   cout << "xL = "   <<  xL  << endl;
// }


 Float_t Protonout_Theta = Protonout.Theta();


 if (Protonout_Theta >=  13.0/1000.0) { continue; }  // 13 mrad

//       cout << "Protonout_Theta = "   <<  Protonout_Theta  << endl;

 N_Cut_II++;





// ============================================================================================



 if ( MyGoodLeptonplus.Pt()  <=  0.30 ) { continue; }  // 300 MeV
 if ( MyGoodLeptonminus.Pt() <=  0.30 ) { continue; }  // 300 MeV

 //        cout << "MyGoodLeptonplus Pt = "    <<  MyGoodLeptonplus.Pt()  << endl;   
 //        cout << "MyGoodLeptonminus Pt = "   <<  MyGoodLeptonminus.Pt()  << endl;   


 if ( abs(MyGoodLeptonplus.Eta())  >=  3.50 ) { continue; }  // 3.5
 if ( abs(MyGoodLeptonminus.Eta()) >=  3.50 ) { continue; }  // 3.5

 

// if ( !( (MyGoodLeptonplus.Pt()  > 0.30)  &&  (MyGoodLeptonminus.Pt() > 0.30) && (abs(MyGoodLeptonplus.Eta())  < 3.50) && (abs(MyGoodLeptonminus.Eta()) < 3.50) ) ) { continue; }
 
 

// if ( !(MyGoodLeptonplus.Pt()  > 0.30  ||  MyGoodLeptonminus.Pt() > 0.30) ) { continue; }
 
 

//        cout << "fbs(MyGoodLeptonplus Eta) = "    <<  abs(MyGoodLeptonplus.Eta())  << endl;   
//        cout << "fbs(MyGoodLeptonminus Eta) = "   <<  abs(MyGoodLeptonminus.Eta())  << endl;           


 N_Cut_III++;


 
      MydiLepton = MyGoodLeptonplus + MyGoodLeptonminus;
      
      
// if ( MydiLepton.M()  < 1 ) { continue; }  // dilepton Mll > 1 GeV
    
      
 N_Cut_IIII++;
      

//      cout << "MydiLepton Pt = " << MydiLepton.Pt() << endl; 
//      cout << "MydiLepton M = "  << MydiLepton.M()  << endl;       
//      cout << "MydiLepton P = "  << MydiLepton.P()  << endl;     
      

      Mll  = MydiLepton.M();
      Ptll = MydiLepton.Pt();

//    etaL =   MydiLepton.Eta();

    // Calculate pseudorapidity using hyperbolic arctangent
    etaL = -TMath::Log(TMath::Tan(thetaL / 2.0));

    // Calculate rapidity using hyperbolic arctangent
//  etaL = -TMath::ATanH(TMath::Tan(thetaL / 2.0));


//      cout << "Mll  = "  << Mll   << endl;       
//      cout << "Ptll = "  << Ptll  << endl;     

      
      t = Protonout - Protonin;

      tvalue =  fabs(t.Mag2());  // t.P() * t.P();
    //  thetal =  MydiLepton.Theta();


      Q2 = fabs(q.Mag2());
      Q2prime = fabs(QPrim.Mag2());


      thetal = thetaL;
      phil   = phiL;
      etal = etaL;

      q2 = Q2;
      q2prime = Q2prime;

      epT = Electronout.Pt();



//      cout << "tvalue    = "  << tvalue     << endl; 
//      cout << "t.Dot(t)  = "  << t.Dot(t)   << endl; 

//      cout << "phil    = "  << phil     << endl;
        // cout << "thetal  = "  << thetal   << endl;


      histMassdilepton->Fill(Mll,event_weight_BH/(10.0/40.0));      
      histPtdilepton->Fill(Ptll,event_weight_BH/(1.0/30.0));    
      histtvalue->Fill(tvalue,tvalue*event_weight_BH/(4.0/30.0));    // event_weight_BH
      histthetal->Fill(thetal,event_weight_BH/(4.0/30.0));    // event_weight_BH
      histphil->Fill(phil,event_weight_BH/(7.0/30.0));    // event_weight_BH

      histetal->Fill(etal,event_weight_BH/(6.0/30.0));    // event_weight_BH
      histq2->Fill(q2,event_weight_BH/(0.01/30.0));    // event_weight_BH
      histq2prime->Fill(q2prime,event_weight_BH/(10.0/30.0));    // event_weight_BH

      histepT->Fill(epT);


      
      Tsignal_EIC->Fill();
    

   } // end events loop 


     target = new TFile ("EIC_BH_tagged_LM.root","recreate");
     target->cd();

     Tsignal_EIC->Write();
    
     target->Close();

   
    cout << "N_Cut_I    = " << N_Cut_I*1.0/nentries << endl;    
    cout << "N_Cut_II   = " << N_Cut_II*1.0/nentries << endl;    
    cout << "N_Cut_III  = " << N_Cut_III*1.0/nentries << endl;    
    cout << "N_Cut_IIII = " << N_Cut_IIII*1.0/nentries << endl;    



// **********************************************************************   
//  Show Resulting Histograms 
// **********************************************************************   

//  TCanvas * c1 = new TCanvas("c1","",1);
//  c1->cd();
//  histMassdilepton->Scale(1/histMassdilepton->Integral());
//  histMassdilepton->Draw();
//  c1 -> SaveAs("Massdilepton.C");   
//  c1 -> SaveAs("Massdilepton.pdf");    

//  TCanvas * c2 = new TCanvas("c2","",1);
//  c2->cd();
//  histPtdilepton->Scale(1/histPtdilepton->Integral());
//  histPtdilepton->Draw();
//  c2 -> SaveAs("Ptdilepton.C");   
  



Double_t xl1=0.70, yl1=0.70, xl2=xl1+0.250, yl2=yl1+0.250;

TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
leg->SetBorderSize(0);

leg->AddEntry(histMassdilepton,"BH","L")->SetTextColor(1);

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


TLatex *t5a = new TLatex(0.666,0.66,"#gamma-tagged (low-mass sample)");
                t5a->SetNDC();
                t5a->SetTextFont(12);
                t5a->SetTextSize(0.04);
                t5a->SetTextAlign(20);
                
TLatex *t6a = new TLatex(0.692,0.61,"hadron_polarisation = 0|0|1");
                t6a->SetNDC();
                t6a->SetTextFont(12);
                t6a->SetTextSize(0.04);
                t6a->SetTextAlign(20);
                
TLatex *t2b = new TLatex(0.70,0.550,"0.5<E'_{e}/E_{e}<0.90 & #pi-#theta_{e}<10 mrad");
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
                


// =======================================================================



TCanvas* c1 = new TCanvas("c1","Massdilepton", 10, 10, 900, 700);

//histMassdilepton->SetTitle("Jet Algorithem = ee_genkt_cambridge");
histMassdilepton->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
//histMassdilepton->GetXaxis()->SetTitleOffset(1.25);
histMassdilepton->GetXaxis()->SetLabelFont(22);
histMassdilepton->GetXaxis()->SetTitleFont(22);
histMassdilepton->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
histMassdilepton->GetYaxis()->SetTitleOffset(1.40);
histMassdilepton->GetYaxis()->SetLabelFont(22);
histMassdilepton->GetYaxis()->SetTitleFont(22);

// histMassdilepton->GetYaxis()->SetRangeUser(0,140);

cout<<"Integral(Massdilepton) =" << histMassdilepton->Integral()/4.0<<endl;

   // histMassdilepton->SetFillStyle(3001); 
//    histMassdilepton->SetFillColor(kGreen+1);
    histMassdilepton->SetLineWidth(3);
    histMassdilepton->SetLineColor(kGreen+1);
    
    histMassdilepton->Draw("hist");
    
    
//     c1->SetLogy(1);
//   c1->SetLogx(1);

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
// t6a->Draw("same");  
 t2b->Draw("same");   
 t3b->Draw("same");    
 t4b->Draw("same");    
 t5b->Draw("same");   
 
//c1->SaveAs("Massdilepton_tagged_Qprime10_LM.pdf");
//c1->SaveAs("Massdilepton_tagged_Qprime10_LM.C");
//c1->SaveAs("Massdilepton_tagged_Qprime10_LM.eps");
//c1->SaveAs("Massdilepton_tagged_Qprime10_LM.root");
//c1->SaveAs("Massdilepton_tagged_Qprime10_LM.jpg");
  


// =======================================================================



TCanvas* c2 = new TCanvas("c2","Ptdilepton", 10, 10, 900, 700);

//histPtdilepton->SetTitle("Jet Algorithem = ee_genkt_cambridge");
histPtdilepton->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
//histPtdilepton->GetXaxis()->SetTitleOffset(1.25);
histPtdilepton->GetXaxis()->SetLabelFont(22);
histPtdilepton->GetXaxis()->SetTitleFont(22);
histPtdilepton->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
histPtdilepton->GetYaxis()->SetTitleOffset(1.40);
histPtdilepton->GetYaxis()->SetLabelFont(22);
histPtdilepton->GetYaxis()->SetTitleFont(22);

//histPtdilepton->GetYaxis()->SetRangeUser(0,100);

cout<<"Integral(Ptdilepton) ="<<histPtdilepton->Integral()/(30.0/10.0)<<endl;

   // histPtdilepton->SetFillStyle(3001); 
//    histPtdilepton->SetFillColor(kGreen+1);
    histPtdilepton->SetLineWidth(3);
    histPtdilepton->SetLineColor(kGreen+1);
    
    histPtdilepton->Draw("hist");

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
// t6a->Draw("same");  
 t2b->Draw("same");   
 t3b->Draw("same");    
 t4b->Draw("same");    
 t5b->Draw("same");   

//c2->SaveAs("Ptdilepton_tagged_Qprime10_LM.pdf");
//c2->SaveAs("Ptdilepton_tagged_Qprime10_LM.C");
//c2->SaveAs("Ptdilepton_tagged_Qprime10_LM.eps");
//c2->SaveAs("Ptdilepton_tagged_Qprime10_LM.root");
//c2->SaveAs("Ptdilepton_tagged_Qprime10_LM.jpg");
  


// =======================================================================



TCanvas* c3 = new TCanvas("c3","tvalue", 10, 10, 900, 700);

//histtvalue->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histtvalue->GetXaxis()->SetTitle("|t| [GeV^{2}]");
//histtvalue->GetXaxis()->SetTitleOffset(1.25);
histtvalue->GetXaxis()->SetLabelFont(22);
histtvalue->GetXaxis()->SetTitleFont(22);
histtvalue->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");
histtvalue->GetYaxis()->SetTitleOffset(1.40);
histtvalue->GetYaxis()->SetLabelFont(22);
histtvalue->GetYaxis()->SetTitleFont(22);

//histtvalue->GetYaxis()->SetRangeUser(1,100);


 cout<<"Integral(tvalue) ="<<histtvalue->Integral()<<endl;

   // histtvalue->SetFillStyle(3001); 
//    histtvalue->SetFillColor(kGreen+1);
    histtvalue->SetLineWidth(3);
    histtvalue->SetLineColor(kGreen+1);
    
//    histtvalue->Draw("hist");
    histtvalue->Draw("ep");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
// t6a->Draw("same");  
 t2b->Draw("same");   
 t3b->Draw("same");    
 t4b->Draw("same");    
 t5b->Draw("same");   
 
 c3->SetLogy(1);
 
 
//c3->SaveAs("t_value_tagged_Qprime10_LM.pdf");
//c3->SaveAs("t_value_tagged_Qprime10_LM.C");
//c3->SaveAs("t_value_tagged_Qprime10_LM.eps");
//c3->SaveAs("t_value_tagged_Qprime10_LM.root");
//c3->SaveAs("t_value_tagged_Qprime10_LM.jpg");
  


// =======================================================================



TCanvas* c4 = new TCanvas("c4","thetal", 10, 10, 900, 700);

//histthetal->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histthetal->GetXaxis()->SetTitle("#theta_{l}");
//histthetal->GetXaxis()->SetTitleOffset(1.25);
histthetal->GetXaxis()->SetLabelFont(22);
histthetal->GetXaxis()->SetTitleFont(22);
histthetal->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
histthetal->GetYaxis()->SetTitleOffset(1.40);
histthetal->GetYaxis()->SetLabelFont(22);
histthetal->GetYaxis()->SetTitleFont(22);

//histthetal->GetYaxis()->SetRangeUser(1,100);


 cout<<"Integral(thetal) ="<<histthetal->Integral()<<endl;

   // histthetal->SetFillStyle(3001); 
//    histthetal->SetFillColor(kGreen+1);
    histthetal->SetLineWidth(3);
    histthetal->SetLineColor(kGreen+1);
    
//    histthetal->Draw("hist");
    histthetal->Draw("hist");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 t5a->Draw("same");
// t6a->Draw("same");  
 t2b->Draw("same");   
 t3b->Draw("same");    
 t4b->Draw("same");    
 t5b->Draw("same");   
 
// c4->SetLogy(1);
 
 
//c4->SaveAs("thetal_tagged_Qprime10_LM.pdf");
//c4->SaveAs("thetal_tagged_Qprime10_LM.C");
//c4->SaveAs("thetal_tagged_Qprime10_LM.eps");
//c4->SaveAs("thetal_tagged_Qprime10_LM.root");
//c4->SaveAs("thetal_tagged_Qprime10_LM.jpg");
  



// =======================================================================



TCanvas* c5 = new TCanvas("c5","phil", 10, 10, 900, 700);

//histphil->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histphil->GetXaxis()->SetTitle("#phi_{l}");
//histphil->GetXaxis()->SetTitleOffset(1.25);
histphil->GetXaxis()->SetLabelFont(22);
histphil->GetXaxis()->SetTitleFont(22);
histphil->GetYaxis()->SetTitle("d#sigma/d#phi_{l}");
histphil->GetYaxis()->SetTitleOffset(1.40);
histphil->GetYaxis()->SetLabelFont(22);
histphil->GetYaxis()->SetTitleFont(22);

//histphil->GetYaxis()->SetRangeUser(1,100);


 cout<<"Integral(phil) ="<<histphil->Integral()<<endl;

   // histphil->SetFillStyle(3001);
//    histphil->SetFillColor(kGreen+1);
    histphil->SetLineWidth(3);
    histphil->SetLineColor(kGreen+1);

//    histphil->Draw("hist");
    histphil->Draw("hist");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");

// c5->SetLogy(1);


//c5->SaveAs("phil_tagged_Qprime10_LM.pdf");
//c5->SaveAs("phil_tagged_Qprime10_LM.C");
//c5->SaveAs("phil_tagged_Qprime10_LM.eps");
//c5->SaveAs("phil_tagged_Qprime10_LM.root");
//c5->SaveAs("phil_tagged_Qprime10_LM.jpg");




// =======================================================================



TCanvas* c6 = new TCanvas("c6","epT", 10, 10, 900, 700);

//histepT->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histepT->GetXaxis()->SetTitle("P_{T}^{e} [GeV]");
//histepT->GetXaxis()->SetTitleOffset(1.25);
histepT->GetXaxis()->SetLabelFont(22);
histepT->GetXaxis()->SetTitleFont(22);
histepT->GetYaxis()->SetTitle("# Events");
histepT->GetYaxis()->SetTitleOffset(1.40);
histepT->GetYaxis()->SetLabelFont(22);
histepT->GetYaxis()->SetTitleFont(22);

//histepT->GetYaxis()->SetRangeUser(1,100);


 cout<<"Integral(epT) ="<<histepT->Integral()<<endl;

   // histepT->SetFillStyle(3001);
//    histepT->SetFillColor(kGreen+1);
    histepT->SetLineWidth(3);
    histepT->SetLineColor(kGreen+1);

//    histepT->Draw("hist");
    histepT->Draw("hist");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");

// c6->SetLogy(1);


//c6->SaveAs("epT_tagged_Qprime10_LM.pdf");
//c6->SaveAs("epT_tagged_Qprime10_LM.C");
//c6->SaveAs("epT_tagged_Qprime10_LM.eps");
//c6->SaveAs("epT_tagged_Qprime10_LM.root");
//c6->SaveAs("epT_tagged_Qprime10_LM.jpg");



 // =======================================================================



TCanvas* c7 = new TCanvas("c7","etal", 10, 10, 900, 700);

//histetal->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histetal->GetXaxis()->SetTitle("#eta^{l}");
//histetal->GetXaxis()->SetTitleOffset(1.25);
histetal->GetXaxis()->SetLabelFont(22);
histetal->GetXaxis()->SetTitleFont(22);
histetal->GetYaxis()->SetTitle("# Events");
histetal->GetYaxis()->SetTitleOffset(1.40);
histetal->GetYaxis()->SetLabelFont(22);
histetal->GetYaxis()->SetTitleFont(22);

//histetal->GetYaxis()->SetRangeUser(1,100);


 cout<<"Integral(etal) ="<<histetal->Integral()<<endl;

   // histetal->SetFillStyle(3001);
//    histetal->SetFillColor(kGreen+1);
    histetal->SetLineWidth(3);
    histetal->SetLineColor(kGreen+1);

//    histetal->Draw("hist");
    histetal->Draw("hist");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");

// c7->SetLogy(1);


//c7->SaveAs("etal_tagged_Qprime10_LM.pdf");
//c7->SaveAs("etal_tagged_Qprime10_LM.C");
//c7->SaveAs("etal_tagged_Qprime10_LM.eps");
//c7->SaveAs("etal_tagged_Qprime10_LM.root");
//c7->SaveAs("etal_tagged_Qprime10_LM.jpg");




  // =======================================================================



TCanvas* c8 = new TCanvas("c8","q2", 10, 10, 900, 700);

//histq2->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histq2->GetXaxis()->SetTitle("q^{2}");
//histq2->GetXaxis()->SetTitleOffset(1.25);
histq2->GetXaxis()->SetLabelFont(22);
histq2->GetXaxis()->SetTitleFont(22);
histq2->GetYaxis()->SetTitle("# Events");
histq2->GetYaxis()->SetTitleOffset(1.40);
histq2->GetYaxis()->SetLabelFont(22);
histq2->GetYaxis()->SetTitleFont(22);

//histq2->GetYaxis()->SetRangeUser(1,100);


 cout<<"Integral(q2) ="<<histq2->Integral()<<endl;

   // histq2->SetFillStyle(3001);
//    histq2->SetFillColor(kGreen+1);
    histq2->SetLineWidth(3);
    histq2->SetLineColor(kGreen+1);

//    histq2->Draw("hist");
    histq2->Draw("hist");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");

// c8->SetLogy(1);


//c8->SaveAs("q2_tagged_Qprime10_LM.pdf");
//c8->SaveAs("q2_tagged_Qprime10_LM.C");
//c8->SaveAs("q2_tagged_Qprime10_LM.eps");
//c8->SaveAs("q2_tagged_Qprime10_LM.root");
//c8->SaveAs("q2_tagged_Qprime10_LM.jpg");







  // =======================================================================



TCanvas* c9 = new TCanvas("c9","q2prime", 10, 10, 900, 700);

//histq2prime->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histq2prime->GetXaxis()->SetTitle("Q^{'2}");
//histq2prime->GetXaxis()->SetTitleOffset(1.25);
histq2prime->GetXaxis()->SetLabelFont(22);
histq2prime->GetXaxis()->SetTitleFont(22);
histq2prime->GetYaxis()->SetTitle("# Events");
histq2prime->GetYaxis()->SetTitleOffset(1.40);
histq2prime->GetYaxis()->SetLabelFont(22);
histq2prime->GetYaxis()->SetTitleFont(22);

//histq2prime->GetYaxis()->SetRangeUser(1,100);


 cout<<"Integral(q2prime) ="<<histq2prime->Integral()<<endl;

   // histq2prime->SetFillStyle(3001);
//    histq2prime->SetFillColor(kGreen+1);
    histq2prime->SetLineWidth(3);
    histq2prime->SetLineColor(kGreen+1);

//    histq2prime->Draw("hist");
    histq2prime->Draw("hist");


 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same");
 t5a->Draw("same");
// t6a->Draw("same");
 t2b->Draw("same");
 t3b->Draw("same");
 t4b->Draw("same");
 t5b->Draw("same");

// c9->SetLogy(1);


//c9->SaveAs("q2prime_tagged_Qprime10_LM.pdf");
//c9->SaveAs("q2prime_tagged_Qprime10_LM.C");
//c9->SaveAs("q2prime_tagged_Qprime10_LM.eps");
//c9->SaveAs("q2prime_tagged_Qprime10_LM.root");
//c9->SaveAs("q2prime_tagged_Qprime10_LM.jpg");








} // The end of main program epic_out_file_v3_LM



