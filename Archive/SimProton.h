//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct 29 11:48:31 2021 by ROOT version 6.14/04
// from TTree OutputCube/OutputCube
// found on file: topas.root
//////////////////////////////////////////////////////////

#ifndef SimProton_h
#define SimProton_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class SimProton {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxPosition_X__cm = 1;
   static constexpr Int_t kMaxPosition_Y__cm = 1;
   static constexpr Int_t kMaxPosition_Z__cm = 1;
   static constexpr Int_t kMaxEnergy__MeV = 1;
   static constexpr Int_t kMaxParticle_Type__in_PDG_Format = 1;
   static constexpr Int_t kMaxFlag_to_tell_if_Third_Direction_Cosine_is_Negative__1_means_true = 1;
   static constexpr Int_t kMaxFlag_to_tell_if_this_is_the_First_Scored_Particle_from_this_History__1_means_true = 1;

   // Declaration of leaf types
   Float_t         Position_X__cm_;
   Float_t         Position_Y__cm_;
   Float_t         Position_Z__cm_;
   Float_t         Direction_Cosine_X;
   Float_t         Direction_Cosine_Y;
   Float_t         Energy__MeV_;
   Float_t         Weight;
   Int_t           Particle_Type__in_PDG_Format_;
   Int_t           Flag_to_tell_if_Third_Direction_Cosine_is_Negative__1_means_true_;
   Int_t           Flag_to_tell_if_this_is_the_First_Scored_Particle_from_this_History__1_means_true_;
   Int_t           Event_ID;
   Int_t           Track_ID;

   // List of branches
   TBranch        *b_Position_X__cm_;   //!
   TBranch        *b_Position_Y__cm_;   //!
   TBranch        *b_Position_Z__cm_;   //!
   TBranch        *b_Direction_Cosine_X;   //!
   TBranch        *b_Direction_Cosine_Y;   //!
   TBranch        *b_Energy__MeV_;   //!
   TBranch        *b_Weight;   //!
   TBranch        *b_Particle_Type__in_PDG_Format_;   //!
   TBranch        *b_Flag_to_tell_if_Third_Direction_Cosine_is_Negative__1_means_true_;   //!
   TBranch        *b_Flag_to_tell_if_this_is_the_First_Scored_Particle_from_this_History__1_means_true_;   //!
   TBranch        *b_Event_ID;   //!
   TBranch        *b_Track_ID;   //!

   SimProton(TTree *tree=0);
   virtual ~SimProton();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SimProton_cxx
SimProton::SimProton(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("topas.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("topas.root");
      }
      f->GetObject("OutputCube",tree);

   }
   Init(tree);
}

SimProton::~SimProton()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SimProton::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SimProton::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SimProton::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Position_X__cm_", &Position_X__cm_, &b_Position_X__cm_);
   fChain->SetBranchAddress("Position_Y__cm_", &Position_Y__cm_, &b_Position_Y__cm_);
   fChain->SetBranchAddress("Position_Z__cm_", &Position_Z__cm_, &b_Position_Z__cm_);
   fChain->SetBranchAddress("Direction_Cosine_X", &Direction_Cosine_X, &b_Direction_Cosine_X);
   fChain->SetBranchAddress("Direction_Cosine_Y", &Direction_Cosine_Y, &b_Direction_Cosine_Y);
   fChain->SetBranchAddress("Energy__MeV_", &Energy__MeV_, &b_Energy__MeV_);
   fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
   fChain->SetBranchAddress("Particle_Type__in_PDG_Format_", &Particle_Type__in_PDG_Format_, &b_Particle_Type__in_PDG_Format_);
   fChain->SetBranchAddress("Flag_to_tell_if_Third_Direction_Cosine_is_Negative__1_means_true_", &Flag_to_tell_if_Third_Direction_Cosine_is_Negative__1_means_true_, &b_Flag_to_tell_if_Third_Direction_Cosine_is_Negative__1_means_true_);
   fChain->SetBranchAddress("Flag_to_tell_if_this_is_the_First_Scored_Particle_from_this_History__1_means_true_", &Flag_to_tell_if_this_is_the_First_Scored_Particle_from_this_History__1_means_true_, &b_Flag_to_tell_if_this_is_the_First_Scored_Particle_from_this_History__1_means_true_);
   fChain->SetBranchAddress("Event_ID", &Event_ID, &b_Event_ID);
   fChain->SetBranchAddress("Track_ID", &Track_ID, &b_Track_ID);
   Notify();
}

Bool_t SimProton::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SimProton::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SimProton::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SimProton_cxx
