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
   Float_t  integrated_cross_section_value_LM = 0;
   Float_t  integrated_cross_section_value_HM = 0;
   
   Float_t  event_weight_LM  = 0;
   Float_t  event_weight_HM = 0;
   
//*   -----------------------------------------------

void Plots_EIC_HMLM_ALL(){

    
   
   Float_t  nentries = 5000000.0;
   Float_t  integrated_luminosity = 300.0 / 1000.0; // fb^{-1} 
   Float_t  integrated_cross_section_value_LM  = 3.79989    * 1000.0;   //    nb   ALL LM
   Float_t  integrated_cross_section_value_HM  = 0.247091   * 1000.0;   //    nb   ALL HM
   
   Float_t  event_weight_LM  = integrated_cross_section_value_LM  * 1.0 / nentries;
   Float_t  event_weight_HM = integrated_cross_section_value_HM * 1.0 / nentries;
    
    
   gStyle->SetPalette(kBird);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(1);


TH1F * histMll_LM  = new TH1F ("Mll", "", 40, 0.0, 10.0);
TH1F * histMll_HM = new TH1F ("Mll", "", 40, 0.0, 10.0);

TH1F * histPtll_LM  = new TH1F ("Ptll", "",  30, 0.0, 1.0);
TH1F * histPtll_HM = new TH1F ("Ptll", "", 30, 0.0, 1.0);

TH1F * histtvalue_LM  = new TH1F ("tvalue", "",  30, 0.0, 4.0);
TH1F * histtvalue_HM = new TH1F ("tvalue", "", 30, 0.0, 4.0);


TH1F * histthetal_LM  = new TH1F ("thetal", "",  30, 0.0, 4.0);
TH1F * histthetal_HM = new TH1F ("thetal", "", 30, 0.0, 4.0);


TH1F * histphil_LM  = new TH1F ("phil", "",  30, 0.0, 7.0);
TH1F * histphil_HM = new TH1F ("phil", "", 30, 0.0, 7.0);

// ============================================

   TFile *file;
   TTree *tree_EIC_LM;
   TTree *tree_EIC_HM;


   file = TFile::Open("EIC_tagged.root");

 
   tree_EIC_LM  = (TTree*)file->Get("EIC_ALL_LM");
   tree_EIC_HM = (TTree*)file->Get("EIC_ALL_HM");


   cout << "tree Entries tree_EIC_LM  == " << tree_EIC_LM->GetEntries() << endl;
   cout << "tree Entries tree_EIC_HM == " << tree_EIC_HM->GetEntries() << endl;
      
   tree_EIC_LM->SetBranchAddress("Mll",&Mll);
   tree_EIC_HM->SetBranchAddress("Mll",&Mll);

   tree_EIC_LM->SetBranchAddress("Ptll",&Ptll);
   tree_EIC_HM->SetBranchAddress("Ptll",&Ptll);
   
   tree_EIC_LM->SetBranchAddress("tvalue",&tvalue);
   tree_EIC_HM->SetBranchAddress("tvalue",&tvalue);


   tree_EIC_LM->SetBranchAddress("thetal",&thetal);
   tree_EIC_HM->SetBranchAddress("thetal",&thetal);

   tree_EIC_LM->SetBranchAddress("phil",&phil);
   tree_EIC_HM->SetBranchAddress("phil",&phil);

   
  for (Long64_t ievt=0; ievt<tree_EIC_LM->GetEntries();ievt++) {
  tree_EIC_LM->GetEntry(ievt);
  
  histMll_LM->Fill(Mll,event_weight_LM/(10.0/40.0));
  histPtll_LM->Fill(Ptll,event_weight_LM/(1.0/30.0));
  histtvalue_LM->Fill(tvalue,tvalue*event_weight_LM/(4.0/30.0));   // ,event_weight_LM ,integrated_cross_section_value_LM
//cout << "event_weight_LM =" << event_weight_LM << endl;
  histthetal_LM->Fill(thetal,event_weight_LM/(4.0/30.0));
  histphil_LM->Fill(phil,event_weight_LM/(7.0/30.0));

    }
    
    
    
  int N_b = histMll_LM->GetNbinsX();
  cout <<  " N_b = " << N_b << endl;
    
  for (size_t i=1; i < N_b+1;i++) {
  
    cout <<  " histMll_LM->GetBinContent(i) = " << histMll_LM->GetBinContent(i) << endl;
   
  }   
  
  for(size_t i=1;  i < N_b+1; i++){
//			histPtll_LM->SetBinContent(i, histMll_LM->GetBinContent(i)/0.25 );
		}


  for (Long64_t ievt=0; ievt<tree_EIC_HM->GetEntries();ievt++) {
  tree_EIC_HM->GetEntry(ievt);
  
  histMll_HM->Fill(Mll,event_weight_HM/(10.0/40.0));
  histPtll_HM->Fill(Ptll,event_weight_HM/(1.0/30.0));
  histtvalue_HM->Fill(tvalue,tvalue*event_weight_HM/(4.0/30.0));  //  ,integrated_cross_section_value_HM
//cout << "event_weight_HM =" << event_weight_HM << endl;
  histthetal_HM->Fill(thetal,event_weight_HM/(4.0/30.0));
  histphil_HM->Fill(phil,event_weight_HM/(7.0/30.0));

    }



  
    
// ------------------- 
 
 
 
Double_t xl1=0.750, yl1=0.720, xl2=xl1+0.150, yl2=yl1+0.150;

TLegend *leg = new TLegend(xl1,yl1,xl2,yl2);
leg->SetBorderSize(0);

leg->AddEntry(histMll_LM,"ALL LM","L")->SetTextColor(2);
leg->AddEntry(histMll_HM,"ALL HM","L")->SetTextColor(6);

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


TCanvas* c1 = new TCanvas("c1","Massdilepton", 10, 10, 900, 700);

//histMll_LM->SetTitle("m_{ll}");
histMll_LM->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
histMll_LM->GetXaxis()->SetTitleOffset(1.25);
histMll_LM->GetXaxis()->SetLabelFont(22);
histMll_LM->GetXaxis()->SetTitleFont(22);
histMll_LM->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
histMll_LM->GetYaxis()->SetTitleOffset(1.40);
histMll_LM->GetYaxis()->SetLabelFont(22);
histMll_LM->GetYaxis()->SetTitleFont(22);

   histMll_LM->GetYaxis()->SetRangeUser(0.1,10000);
//   histMll_LM->GetXaxis()->SetRangeUser(0,1);

   histMll_LM->SetLineWidth(4);
   histMll_HM->SetLineWidth(4);
   
   histMll_LM->SetLineColor(2);
   histMll_HM->SetLineColor(6);

   histMll_LM->Draw("hist");
   histMll_HM->Draw("hist same");
   
   cout << "Integral histMll_LM = "  <<  histMll_LM->Integral()/4.0 << endl;
   
   c1->SetLogy(1);
//   c1->SetLogx(1);

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
  
 
//c1->SaveAs("Mll_tagged_Qprime10_Compare.pdf");
//c1->SaveAs("Mll_tagged_Qprime10_Compare.C");
//c1->SaveAs("Mll_tagged_Qprime10_Compare.eps");
//c1->SaveAs("Mll_tagged_Qprime10_Compare.root");




// +++++++++++++++++++++++++++++++++++++++++++++++++++++++



TCanvas *canvasMll = new TCanvas("canvasMll", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Mll = (TH1F*)histMll_LM->Clone(); // Clone histMll_LM to keep the original histogram
resultHist_Mll->Add(histMll_HM);





Double_t xl3=0.70, yl3=0.70, xl4=xl3+0.150, yl4=yl3+0.150;

TLegend *leg2 = new TLegend(xl3,yl3,xl4,yl4);
leg2->SetBorderSize(0);

leg2->AddEntry(resultHist_Mll,"ALL (LM+HM)","L")->SetTextColor(2);

leg2->SetTextSize(0.032);
leg2->SetTextFont(12);
leg2->SetFillStyle(0);


resultHist_Mll->GetXaxis()->SetTitle("M_{#mu^{+}#mu^{-}} [GeV]");
resultHist_Mll->GetXaxis()->SetTitleOffset(1.25);
resultHist_Mll->GetXaxis()->SetLabelFont(22);
resultHist_Mll->GetXaxis()->SetTitleFont(22);
resultHist_Mll->GetYaxis()->SetTitle("d#sigma/dM_{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Mll->GetYaxis()->SetTitleOffset(1.40);
resultHist_Mll->GetYaxis()->SetLabelFont(22);
resultHist_Mll->GetYaxis()->SetTitleFont(22);

resultHist_Mll->Draw("hist");


cout << "Integral resultHist_Mll = "  <<  resultHist_Mll->Integral()/4.0 << endl;


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


canvasMll->Update();
//delete canvas;
canvasMll->SaveAs("Mll_tagged_LM_HM_ALL.pdf");



// --------------------



TCanvas* c2 = new TCanvas("c2","Ptdilepton", 10, 10, 900, 700);

//histPtll_LM->SetTitle("m_{ll}");
histPtll_LM->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
histPtll_LM->GetXaxis()->SetTitleOffset(1.25);
histPtll_LM->GetXaxis()->SetLabelFont(22);
histPtll_LM->GetXaxis()->SetTitleFont(22);
histPtll_LM->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
histPtll_LM->GetYaxis()->SetTitleOffset(1.40);
histPtll_LM->GetYaxis()->SetLabelFont(22);
histPtll_LM->GetYaxis()->SetTitleFont(22);

   histPtll_LM->GetYaxis()->SetRangeUser(0.1,1000000);
//   histPtll_LM->GetXaxis()->SetRangeUser(0,1);

   histPtll_LM->SetLineWidth(4);
   histPtll_HM->SetLineWidth(4);

   histPtll_LM->SetLineColor(2);
   histPtll_HM->SetLineColor(6);

   histPtll_LM->Draw("hist");
   histPtll_HM->Draw("hist same");
   
   c2->SetLogy(1);
//   c2->SetLogx(1);

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
 
 
//c2->SaveAs("Ptll_tagged_Qprime10_Compare.pdf");
//c2->SaveAs("ptll_tagged_Qprime10_Compare.C");
//c2->SaveAs("ptll_tagged_Qprime10_Compare.eps");
//c2->SaveAs("ptll_tagged_Qprime10_Compare.root");





// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasPtll = new TCanvas("canvasPtll", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_Ptll = (TH1F*)histPtll_LM->Clone(); // Clone histPtll_LM to keep the original histogram
resultHist_Ptll->Add(histPtll_HM);


Double_t xl5=0.70, yl5=0.70, xl6=xl5+0.150, yl6=yl5+0.150;

TLegend *leg3 = new TLegend(xl5,yl5,xl6,yl6);
leg3->SetBorderSize(0);

leg3->AddEntry(resultHist_Ptll,"ALL (LM+HM)","L")->SetTextColor(2);

leg3->SetTextSize(0.032);
leg3->SetTextFont(12);
leg3->SetFillStyle(0);


resultHist_Ptll->GetXaxis()->SetTitle("P_{T}^{#mu^{+}#mu^{-}} [GeV]");
resultHist_Ptll->GetXaxis()->SetTitleOffset(1.25);
resultHist_Ptll->GetXaxis()->SetLabelFont(22);
resultHist_Ptll->GetXaxis()->SetTitleFont(22);
resultHist_Ptll->GetYaxis()->SetTitle("d#sigma/dP_{T}^{#mu^{+}#mu^{-}} [pb/GeV]");
resultHist_Ptll->GetYaxis()->SetTitleOffset(1.40);
resultHist_Ptll->GetYaxis()->SetLabelFont(22);
resultHist_Ptll->GetYaxis()->SetTitleFont(22);

resultHist_Ptll->Draw("hist");


cout << "Integral resultHist_Ptll = "  <<  resultHist_Ptll->Integral()/4.0 << endl;


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


canvasPtll->Update();
//delete canvas;
canvasPtll->SaveAs("Ptll_tagged_LM_HM_ALL.pdf");






// --------------------



TCanvas* c3 = new TCanvas("c3","tvalue", 10, 10, 900, 700);

//histtvalue_LM->SetTitle("m_{ll}");
histtvalue_LM->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_LM->GetXaxis()->SetTitleOffset(1.25);
histtvalue_LM->GetXaxis()->SetLabelFont(22);
histtvalue_LM->GetXaxis()->SetTitleFont(22);
histtvalue_LM->GetYaxis()->SetTitle("Events normalised to unit area");  // d#sigma/d|t| [pb]
histtvalue_LM->GetYaxis()->SetTitleOffset(1.40);
histtvalue_LM->GetYaxis()->SetLabelFont(22);
histtvalue_LM->GetYaxis()->SetTitleFont(22);

//   histtvalue_LM->GetXaxis()->SetRangeUser(0,8000);
//   histtvalue_LM->GetXaxis()->SetRangeUser(0,1);

   histtvalue_LM->SetLineWidth(3);
   histtvalue_HM->SetLineWidth(3);

   histtvalue_LM->SetLineColor(2);
   histtvalue_HM->SetLineColor(6);

   histtvalue_LM->DrawNormalized("hist");
   histtvalue_HM->DrawNormalized("hist same");

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



TCanvas* c4 = new TCanvas("c4","tvalue", 10, 10, 900, 700);

//histtvalue_LM->SetTitle("m_{ll}");
histtvalue_LM->GetXaxis()->SetTitle("|t| [GeV^{2}]");
histtvalue_LM->GetXaxis()->SetTitleOffset(1.25);
histtvalue_LM->GetXaxis()->SetLabelFont(22);
histtvalue_LM->GetXaxis()->SetTitleFont(22);
histtvalue_LM->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");  // d#sigma/d|t| [pb]
histtvalue_LM->GetYaxis()->SetTitleOffset(1.40);
histtvalue_LM->GetYaxis()->SetLabelFont(22);
histtvalue_LM->GetYaxis()->SetTitleFont(22);

//   histtvalue_LM->GetYaxis()->SetRangeUser(0,50000);
//   histtvalue_LM->GetXaxis()->SetRangeUser(0,1);

   histtvalue_LM->SetLineWidth(3);
   histtvalue_HM->SetLineWidth(3);

   histtvalue_LM->SetLineColor(2);
   histtvalue_HM->SetLineColor(6);

   histtvalue_LM->Draw("ep");
   histtvalue_HM->Draw("ep same");

     c4->SetLogy(1);
//   c4->SetLogx(1);

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
 

//c4->SaveAs("t_value_tagged_Qprime10_Compare.pdf");
//c4->SaveAs("t_value_tagged_Qprime10_Compare.C");
//c4->SaveAs("t_value_tagged_Qprime10_Compare.eps");
//c4->SaveAs("t_value_tagged_Qprime10_Compare.root");





// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvastvalue = new TCanvas("canvastvalue", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_tvalue = (TH1F*)histtvalue_LM->Clone(); // Clone histtvalue_LM to keep the original histogram
resultHist_tvalue->Add(histtvalue_HM);


Double_t xl7=0.70, yl7=0.70, xl8=xl7+0.150, yl8=yl7+0.150;

TLegend *leg4 = new TLegend(xl7,yl7,xl8,yl8);
leg4->SetBorderSize(0);

leg4->AddEntry(resultHist_tvalue,"ALL (LM+HM)","L")->SetTextColor(2);

leg4->SetTextSize(0.032);
leg4->SetTextFont(12);
leg4->SetFillStyle(0);


resultHist_tvalue->GetXaxis()->SetTitle("|t| [GeV^{2}]");
resultHist_tvalue->GetXaxis()->SetTitleOffset(1.25);
resultHist_tvalue->GetXaxis()->SetLabelFont(22);
resultHist_tvalue->GetXaxis()->SetTitleFont(22);
resultHist_tvalue->GetYaxis()->SetTitle("t.d#sigma/d|t| [pb]");
resultHist_tvalue->GetYaxis()->SetTitleOffset(1.40);
resultHist_tvalue->GetYaxis()->SetLabelFont(22);
resultHist_tvalue->GetYaxis()->SetTitleFont(22);

resultHist_tvalue->Draw("ep");


cout << "Integral resultHist_tvalue = "  <<  resultHist_tvalue->Integral()/4.0 << endl;


 canvastvalue->SetLogy(1);


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


canvastvalue->Update();
//delete canvas;
canvastvalue->SaveAs("t_value_tagged_LM_HM_ALL.pdf");








// =======================================================================


TCanvas* c5 = new TCanvas("c5","thetal", 10, 10, 900, 700);

//histthetal_LM->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histthetal_LM->GetXaxis()->SetTitle("#theta_{l}");
//histthetal_LM->GetXaxis()->SetTitleOffset(1.25);
histthetal_LM->GetXaxis()->SetLabelFont(22);
histthetal_LM->GetXaxis()->SetTitleFont(22);
histthetal_LM->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
histthetal_LM->GetYaxis()->SetTitleOffset(1.40);
histthetal_LM->GetYaxis()->SetLabelFont(22);
histthetal_LM->GetYaxis()->SetTitleFont(22);

histthetal_LM->GetYaxis()->SetRangeUser(0.1,200);


 cout<<"Integral(thetal) ="<<histthetal_LM->Integral()<<endl;

   histthetal_LM->SetLineWidth(3);
   histthetal_HM->SetLineWidth(3);

   histthetal_LM->SetLineColor(2);
   histthetal_HM->SetLineColor(6);

   histthetal_LM->Draw("hist");
   histthetal_HM->Draw("hist same");



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

 c5->SetLogy(1);


//c5->SaveAs("theta_tagged_Qprime10_Compare.pdf");
//c5->SaveAs("thetal_tagged_Qprime10_Compare.C");
//c5->SaveAs("thetal_tagged_Qprime10_Compare.eps");
//c5->SaveAs("thetal_tagged_Qprime10_Compare.root");
//c5->SaveAs("thetal_tagged_Qprime10_Compare.jpg");






// +++++++++++++++++++++++++++++++++++++++++++++++++++++++




TCanvas *canvasthetal = new TCanvas("canvasthetal", "Histogram Sum", 10, 10, 900, 700);
TH1F *resultHist_thetal = (TH1F*)histthetal_LM->Clone(); // Clone histtvalue_LM to keep the original histogram
resultHist_thetal->Add(histthetal_HM);


Double_t xl9=0.70, yl9=0.70, xl10=xl9+0.150, yl10=yl9+0.150;

TLegend *leg5 = new TLegend(xl9,yl9,xl10,yl10);
leg5->SetBorderSize(0);

leg5->AddEntry(resultHist_thetal,"ALL (LM+HM)","L")->SetTextColor(2);

leg5->SetTextSize(0.032);
leg5->SetTextFont(12);
leg5->SetFillStyle(0);


resultHist_thetal->GetXaxis()->SetTitle("#theta_{l}");
resultHist_thetal->GetXaxis()->SetTitleOffset(1.25);
resultHist_thetal->GetXaxis()->SetLabelFont(22);
resultHist_thetal->GetXaxis()->SetTitleFont(22);
resultHist_thetal->GetYaxis()->SetTitle("d#sigma/d#theta_{l}");
resultHist_thetal->GetYaxis()->SetTitleOffset(1.40);
resultHist_thetal->GetYaxis()->SetLabelFont(22);
resultHist_thetal->GetYaxis()->SetTitleFont(22);

resultHist_thetal->Draw("hist");


cout << "Integral resultHist_tvalue = "  <<  resultHist_thetal->Integral()/4.0 << endl;


 canvastvalue->SetLogy(1);


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


canvasthetal->Update();
//delete canvas;
canvasthetal->SaveAs("thetal_tagged_LM_HM_ALL.pdf");






// =======================================================================





TCanvas* c6 = new TCanvas("c6","phil", 10, 10, 900, 700);

//histphil_LM->SetTitle("Jet Algorithem = ee_genkt_cambridge"); t5a->Draw("same");
histphil_LM->GetXaxis()->SetTitle("#phi_{l}");
//histphil_LM->GetXaxis()->SetTitleOffset(1.25);
histphil_LM->GetXaxis()->SetLabelFont(22);
histphil_LM->GetXaxis()->SetTitleFont(22);
histphil_LM->GetYaxis()->SetTitle("d#sigma/d#phi_{l}");
histphil_LM->GetYaxis()->SetTitleOffset(1.40);
histphil_LM->GetYaxis()->SetLabelFont(22);
histphil_LM->GetYaxis()->SetTitleFont(22);

histphil_LM->GetYaxis()->SetRangeUser(0.1,100);


 cout<<"Integral(phil) ="<<histphil_LM->Integral()<<endl;

   histphil_LM->SetLineWidth(3);
   histphil_HM->SetLineWidth(3);

   histphil_LM->SetLineColor(2);
   histphil_HM->SetLineColor(6);

   histphil_LM->Draw("hist");
   histphil_HM->Draw("hist same");


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
