
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


// epic_out_file_v4

#define epic_out_file_v4_cxx
#include "epic_out_file_v4.h"


TFile *target;
TTree *Tsignal_EIC1 = new TTree("EIC1","EIC1");
TTree *Tsignal_EIC2 = new TTree("EIC2","EIC2");
TFile *F;


// **********************************************************************   
// Book Histograms 
// **********************************************************************   

  TH1 *histMassdilepton1 = new TH1F("M_{inv}", "", 50, 0.0, 10.0);
  TH1 *histPtdilepton1 = new TH1F("Pt", "", 50, 0.0, 10.0);
  TH1 *histtvalue1 = new TH1F("tvalue", "", 50, 0.0, 5.0);  


  TH1 *histMassdilepton2 = new TH1F("M_{inv}", "", 50, 0.0, 10.0);
  TH1 *histPtdilepton2 = new TH1F("Pt", "", 50, 0.0, 10.0);
  TH1 *histtvalue2 = new TH1F("tvalue", "", 50, 0.0, 5.0);  
  
  
    TLorentzVector MyGoodLeptonplus;
    TLorentzVector MyGoodLeptonminus;
    TLorentzVector MydiLepton;

    TLorentzVector Electronin;    
    TLorentzVector Electronout;    
    
    TLorentzVector Protonin;    
    TLorentzVector Protonout;    

    TLorentzVector t;    
    
    
   Float_t Mll = 0.0;
   Float_t Ptll = 0.0;
   Float_t tvalue = 0.0;
   
   Int_t N_Cut_I;
   Int_t N_Cut_II;
   Int_t N_Cut_III;   
     

void epic_out_file_v4::Loop()
{
//   In a ROOT session, you can do:
//      root> .L epic_out_file_v4.C
//      root> epic_out_file_v4 t
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
 

	Tsignal_EIC1->Branch("Mll",&Mll);
	Tsignal_EIC1->Branch("Ptll",&Ptll);
	Tsignal_EIC1->Branch("tvalue",&tvalue);
    
	Tsignal_EIC2->Branch("Mll",&Mll);
	Tsignal_EIC2->Branch("Ptll",&Ptll);
	Tsignal_EIC2->Branch("tvalue",&tvalue);


// ++++++++++++++++++++++++++++++++++++++++++++++++  Sample Loop: Start
   
 for(int sample = 1; sample < 3; sample++)
   {

if(sample == 1) { F = new TFile("/home/hamzeh-khanpour/Documents/GitHub/Analysis_Code_EpIC/epic_out_file_BH_hel_-1_pol001.root","READ"); }
if(sample == 2) { F = new TFile("/home/hamzeh-khanpour/Documents/GitHub/Analysis_Code_EpIC/epic_out_file_ALL_hel_-1_pol001.root","READ"); }


TTree *TChain = (TTree*) F->Get("hepmc3_tree");   
    
    
    
   gStyle->SetOptStat(0);   
   
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
      tvalue = 0.0;

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
     
     
// ============================================================================================
      
        
//        if ( kMaxparticles == 0 ) { 


  Electronin.SetPxPyPzE( particles_momentum_m_v1[0], particles_momentum_m_v2[0], particles_momentum_m_v3[0], particles_momentum_m_v4[0] );
  
//        cout << "Electronin Px = "   <<  Electronin.Px()  << endl;    
//        cout << "Electronin E = "   <<  Electronin.E()  << endl;    

 //       }  
        
//        else if ( kMaxparticles == 1 ) {  


  Electronout.SetPxPyPzE( particles_momentum_m_v1[1], particles_momentum_m_v2[1], particles_momentum_m_v3[1], particles_momentum_m_v4[1] );
  
//        cout << "Electronout Px = "   <<  Electronout.Px()  << endl;    
//        cout << "Electronout E = "   <<  Electronout.E()  << endl;    
//        cout << "Electronout Theta = "   <<  Electronout.Theta()  << endl;    
  
//        }  
  
  
 Float_t Electronin_E  = Electronin.E();
 Float_t Electronout_E = Electronout.E();

 Float_t Energy_Ratio = Electronout_E*1.0/Electronin_E*1.0;

if ( Energy_Ratio < 0.5 ||  Energy_Ratio > 0.9 ) { continue; }

//        cout << "Energy_Ratio = "   <<  Energy_Ratio  << endl;    


 Float_t Pi = 3.14159265359;
 Float_t Pi_Theta_e = Pi - Electronout.Theta();


       
if ( Pi_Theta_e > 10.0/1000.0 ) { continue; }  // 10 mrad

//       cout << "Pi_Theta_e = "   <<  Pi_Theta_e  << endl; 
        
        
 N_Cut_I++;        

 

// ============================================================================================
 
 
 
//        if ( kMaxparticles == 3 ) {  // particles_pid[i] == 2212 && particles_status[i] == 0


  Protonin.SetPxPyPzE( particles_momentum_m_v1[3], particles_momentum_m_v2[3], particles_momentum_m_v3[3], particles_momentum_m_v4[3] );
  
//        cout << "Protonin Px = "   <<  Protonin.Px()  << endl;    

 //       }  
        
//        else if ( kMaxparticles == 5 ) {  // particles_pid[i] == 2212 && particles_status[i] == -2


  Protonout.SetPxPyPzE( particles_momentum_m_v1[5], particles_momentum_m_v2[5], particles_momentum_m_v3[5], particles_momentum_m_v4[5] );
  
//        cout << "Protonout Px = "   <<  Protonout.Px()  << endl;    

//        }  
    

 Float_t xL = Protonout.Pz() / Protonout.P();
  
//       cout << "xL = "   <<  xL  << endl; 

 Float_t Protonout_Pt = Protonout.Pt();  
    
 if ( Protonout_Pt < 0.10 ) { continue; }    // 100 MeV

//        cout << "Protonout_Pt = "   <<  Protonout_Pt  << endl; 
       
 Float_t Protonout_Theta = Protonout.Theta();       

       
 if ( Protonout_Theta > 13.0/1000.0 ) { continue; }  // 13 mrad 
 
//       cout << "Protonout_Theta = "   <<  Protonout_Theta  << endl; 
       
 N_Cut_II++;

    
// ============================================================================================       

      
    for (Int_t i = 1; i <= kMaxparticles; i++) {      
     
        if (particles_pid[i] == -13 ) {  // && particles_status[i] == 5 

            
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


        else if (particles_pid[i] == 13 ) {  // && particles_status[i] == 5 

            
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


 if ( MyGoodLeptonplus.Pt()  < 0.30 ) { continue; }  // 300 MeV
 if ( MyGoodLeptonminus.Pt() < 0.30 ) { continue; }  // 300 MeV

 //        cout << "MyGoodLeptonplus Pt = "   <<  MyGoodLeptonplus.Pt()  << endl;   
 //        cout << "MyGoodLeptonminus Pt = "   <<  MyGoodLeptonminus.Pt()  << endl;   


 if ( abs(MyGoodLeptonplus.Eta())  > 3.50 ) { continue; }  // 3.5
 if ( abs(MyGoodLeptonminus.Eta()) > 3.50 ) { continue; }  // 3.5
 

//        cout << "fbs(MyGoodLeptonplus Eta) = "    <<  abs(MyGoodLeptonplus.Eta())  << endl;   
//        cout << "fbs(MyGoodLeptonminus Eta) = "   <<  abs(MyGoodLeptonminus.Eta())  << endl;           


 N_Cut_III++;


      MydiLepton = MyGoodLeptonplus + MyGoodLeptonminus;

//      cout << "MydiLepton Pt = " << MydiLepton.Pt() << endl; 
//      cout << "MydiLepton M = "  << MydiLepton.M()  << endl;       
//      cout << "MydiLepton P = "  << MydiLepton.P()  << endl;     
      

      Mll  = MydiLepton.M();
      Ptll = MydiLepton.Pt();
      
//      cout << "Mll  = "  << Mll   << endl;       
//      cout << "Ptll = "  << Ptll  << endl;     

      
      t = Protonout - Protonin;
      tvalue =  fabs(t.Mag2());  // t.P() * t.P();
      
      cout << "tvalue  = "  << tvalue   << endl;               
      
      
      Float_t integrated_cross_section_value = 0.0522193380793077;  // pb
      Float_t integrated_luminosity = 300000; // pb^{-1} 
      Float_t event_weight = integrated_cross_section_value * integrated_luminosity / nentries;

if(sample == 1) {      
      histMassdilepton1->Fill(Mll);      
      histPtdilepton1->Fill(Ptll);    
      histtvalue1->Fill(tvalue);    // ,event_weight
}

if(sample == 2) {
      histMassdilepton2->Fill(Mll);      
      histPtdilepton2->Fill(Ptll);    
      histtvalue2->Fill(tvalue);    // ,event_weight      
}
      

     if(sample == 1) { Tsignal_EIC1->Fill(); }
     if(sample == 2) { Tsignal_EIC2->Fill(); }

   
//   cout << "N_Cut_I   = " << N_Cut_I*1.0/nentries << endl;    
//   cout << "N_Cut_II  = " << N_Cut_II*1.0/nentries << endl;    
//   cout << "N_Cut_III = " << N_Cut_III*1.0/nentries << endl;    
     

   } // end events loop 


} //======================================================= Sample Loop: End

   
    target = new TFile ("EIC.root","recreate");
    target->cd();

    Tsignal_EIC1->Write();
    Tsignal_EIC2->Write();
    
    target->Close();


// **********************************************************************   
// Show Resulting Histograms 
// **********************************************************************   

//  TCanvas * c1 = new TCanvas("c1","",1);
//  c1->cd();
  //histMassdilepton1->Scale(1/histMassdilepton1->Integral());
//  histMassdilepton1->Draw();
 // c1 -> SaveAs("Massdilepton.C");   
//    c1 -> SaveAs("Massdilepton.pdf");    

//  TCanvas * c2 = new TCanvas("c2","",1);
//  c2->cd();
  //histPtdilepton->Scale(1/histPtdilepton->Integral());
//  histPtdilepton->Draw();
 // c2 -> SaveAs("Ptdilepton.C");   
  


Double_t xl1=0.70, yl1=0.70, xl2=xl1+0.250, yl2=yl1+0.250;

TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
leg->SetBorderSize(0);

leg->AddEntry(histMassdilepton1,"BH","L")->SetTextColor(1);

leg->SetTextSize(0.032);
leg->SetTextFont(12);
leg->SetFillStyle(0);

//    (#sqrt{s} = 365 GeV, L_{int} = 1.5 ab^{-1})    1.5 ab^{-1} (365 GeV)

TLatex *t2a = new TLatex(0.5,0.9,"#bf{Electron-Ion Collider (EIC)}");
                t2a->SetNDC();
                t2a->SetTextFont(42);
                t2a->SetTextSize(0.04);
                t2a->SetTextAlign(20);

                
TLatex *t3a = new TLatex(0.27,0.8,"E_e = 18 GeV");
                t3a->SetNDC();
                t3a->SetTextFont(42);
                t3a->SetTextSize(0.04);
                t3a->SetTextAlign(20);
                
            
TLatex *t4a = new TLatex(0.276,0.75,"E_p = 275 GeV");
                t4a->SetNDC();
                t4a->SetTextFont(42);
                t4a->SetTextSize(0.04);
                t4a->SetTextAlign(20);
                

// =======================================================================


TCanvas* c1 = new TCanvas("c1","Massdilepton", 10, 10, 900, 700);

//histMassdilepton1->SetTitle("Jet Algorithem = ee_genkt_cambridge");
histMassdilepton1->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
//histMassdilepton1->GetXaxis()->SetTitleOffset(1.25);
histMassdilepton1->GetXaxis()->SetLabelFont(22);
histMassdilepton1->GetXaxis()->SetTitleFont(22);
histMassdilepton1->GetYaxis()->SetTitle("Events normalised to unit area");
histMassdilepton1->GetYaxis()->SetTitleOffset(1.40);
histMassdilepton1->GetYaxis()->SetLabelFont(22);
histMassdilepton1->GetYaxis()->SetTitleFont(22);

//histMassdilepton1->GetYaxis()->SetRangeUser(0,100);
//cout<<"histMassdilepton1="<<histMassdilepton1->Integral()<<endl;

   // histMassdilepton1->SetFillStyle(3001); 
//    histMassdilepton1->SetFillColor(kGreen+1);
    histMassdilepton1->SetLineWidth(3);
    histMassdilepton1->SetLineColor(kGreen+1);
    
    histMassdilepton1->DrawNormalized("hist");
    histMassdilepton2->DrawNormalized("hist same");   
   
   
 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 
 
c1->SaveAs("Massdilepton.pdf");
//c1->SaveAs("Massdilepton.C");
c1->SaveAs("Massdilepton.eps");
//c1->SaveAs("Massdilepton.root");                
c1->SaveAs("Massdilepton.jpg");      
  


// =======================================================================


TCanvas* c2 = new TCanvas("c2","Ptdilepton", 10, 10, 900, 700);

//histPtdilepton1->SetTitle("Jet Algorithem = ee_genkt_cambridge");
histPtdilepton1->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
//histPtdilepton1->GetXaxis()->SetTitleOffset(1.25);
histPtdilepton1->GetXaxis()->SetLabelFont(22);
histPtdilepton1->GetXaxis()->SetTitleFont(22);
histPtdilepton1->GetYaxis()->SetTitle("Events normalised to unit area");
histPtdilepton1->GetYaxis()->SetTitleOffset(1.40);
histPtdilepton1->GetYaxis()->SetLabelFont(22);
histPtdilepton1->GetYaxis()->SetTitleFont(22);

//histPtdilepton1->GetYaxis()->SetRangeUser(0,100);
//cout<<"histPtdilepton1="<<histPtdilepton1->Integral()<<endl;

   // histPtdilepton1->SetFillStyle(3001); 
//    histPtdilepton1->SetFillColor(kGreen+1);
    histPtdilepton1->SetLineWidth(3);
    histPtdilepton1->SetLineColor(kGreen+1);
    
    histPtdilepton1->DrawNormalized("hist");

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 


 
c2->SaveAs("Ptdilepton.pdf");
//c2->SaveAs("Ptdilepton.C");
c2->SaveAs("Ptdilepton.eps");
//c2->SaveAs("Ptdilepton.root");                
c2->SaveAs("Ptdilepton.jpg");      
  


// =======================================================================


TCanvas* c3 = new TCanvas("c3","tvalue", 10, 10, 900, 700);

//histtvalue1->SetTitle("Jet Algorithem = ee_genkt_cambridge");
histtvalue1->GetXaxis()->SetTitle("|t| [GeV^{2}]");
//histtvalue1->GetXaxis()->SetTitleOffset(1.25);
histtvalue1->GetXaxis()->SetLabelFont(22);
histtvalue1->GetXaxis()->SetTitleFont(22);
histtvalue1->GetYaxis()->SetTitle("# Events");
histtvalue1->GetYaxis()->SetTitleOffset(1.40);
histtvalue1->GetYaxis()->SetLabelFont(22);
histtvalue1->GetYaxis()->SetTitleFont(22);

//histtvalue1->GetYaxis()->SetRangeUser(0,100);
//cout<<"histtvalue1="<<histtvalue1->Integral()<<endl;

   // histtvalue1->SetFillStyle(3001); 
//    histtvalue1->SetFillColor(kGreen+1);
    histtvalue1->SetLineWidth(3);
    histtvalue1->SetLineColor(kGreen+1);
    
    histtvalue1->Draw("hist");

 leg->Draw("same");
 t2a->Draw("same");
 t3a->Draw("same");
 t4a->Draw("same"); 
 
 
c3->SetLogy(1);
 
c3->SaveAs("tvalue.pdf");
//c3->SaveAs("tvalue.C");
c3->SaveAs("tvalue.eps");
//c3->SaveAs("tvalue.root");                
c3->SaveAs("tvalue.jpg");      
  



} // The end of main program epic_out_file_v4





