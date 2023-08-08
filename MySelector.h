//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug  7 12:09:46 2023 by ROOT version 6.24/06
// from TTree hepmc3_tree/hepmc3_tree
// found on file: epic_out_file.root
//////////////////////////////////////////////////////////

#ifndef MySelector_h
#define MySelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class MySelector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> event_number = {fReader, "event_number"};
   TTreeReaderValue<Int_t> momentum_unit = {fReader, "momentum_unit"};
   TTreeReaderValue<Int_t> length_unit = {fReader, "length_unit"};
   TTreeReaderArray<Int_t> particles_pid = {fReader, "particles.pid"};
   TTreeReaderArray<Int_t> particles_status = {fReader, "particles.status"};
   TTreeReaderArray<Bool_t> particles_is_mass_set = {fReader, "particles.is_mass_set"};
   TTreeReaderArray<Double_t> particles_mass = {fReader, "particles.mass"};
   TTreeReaderArray<Double_t> particles_momentum_m_v1 = {fReader, "particles.momentum.m_v1"};
   TTreeReaderArray<Double_t> particles_momentum_m_v2 = {fReader, "particles.momentum.m_v2"};
   TTreeReaderArray<Double_t> particles_momentum_m_v3 = {fReader, "particles.momentum.m_v3"};
   TTreeReaderArray<Double_t> particles_momentum_m_v4 = {fReader, "particles.momentum.m_v4"};
   TTreeReaderArray<Int_t> vertices_status = {fReader, "vertices.status"};
   TTreeReaderArray<Double_t> vertices_position_m_v1 = {fReader, "vertices.position.m_v1"};
   TTreeReaderArray<Double_t> vertices_position_m_v2 = {fReader, "vertices.position.m_v2"};
   TTreeReaderArray<Double_t> vertices_position_m_v3 = {fReader, "vertices.position.m_v3"};
   TTreeReaderArray<Double_t> vertices_position_m_v4 = {fReader, "vertices.position.m_v4"};
   TTreeReaderArray<double> weights = {fReader, "weights"};
   TTreeReaderValue<Double_t> event_pos_m_v1 = {fReader, "event_pos.m_v1"};
   TTreeReaderValue<Double_t> event_pos_m_v2 = {fReader, "event_pos.m_v2"};
   TTreeReaderValue<Double_t> event_pos_m_v3 = {fReader, "event_pos.m_v3"};
   TTreeReaderValue<Double_t> event_pos_m_v4 = {fReader, "event_pos.m_v4"};
   TTreeReaderArray<int> links1 = {fReader, "links1"};
   TTreeReaderArray<int> links2 = {fReader, "links2"};
   TTreeReaderArray<int> attribute_id = {fReader, "attribute_id"};
   TTreeReaderArray<string> attribute_name = {fReader, "attribute_name"};
   TTreeReaderArray<string> attribute_string = {fReader, "attribute_string"};
   TTreeReaderArray<string> weight_names = {fReader, "weight_names"};
   TTreeReaderArray<string> tool_name = {fReader, "tool_name"};
   TTreeReaderArray<string> tool_version = {fReader, "tool_version"};
   TTreeReaderArray<string> tool_description = {fReader, "tool_description"};


   MySelector(TTree * /*tree*/ =0) { }
   virtual ~MySelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(MySelector,0);

};

#endif

#ifdef MySelector_cxx
void MySelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t MySelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef MySelector_cxx
