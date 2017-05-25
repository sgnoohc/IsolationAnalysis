// -*- C++ -*-
// This is a header file generated with the command:
// makeCMS3ClassFiles("/home/users/phchang/public_html/analysis/www/studies/20170523_IsolationStudy/v0.0.8_isostudy/output/output_tree_1_isotree_sig.root", "IsoTree", "IsoTree", "tas", "mytree")

#ifndef IsoTree_H
#define IsoTree_H

#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
#include <unistd.h> 
typedef ROOT::Math::LorentzVector< ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std; 
class IsoTree {
 private: 
 protected: 
  unsigned int index;
  float    sip3d_;
  TBranch *sip3d_branch;
  bool     sip3d_isLoaded;
  float    ip3d_;
  TBranch *ip3d_branch;
  bool     ip3d_isLoaded;
  float    ptrel_;
  TBranch *ptrel_branch;
  bool     ptrel_isLoaded;
  float    ptratio_;
  TBranch *ptratio_branch;
  bool     ptratio_isLoaded;
  float    relIso03_;
  TBranch *relIso03_branch;
  bool     relIso03_isLoaded;
  float    relIso03DB_;
  TBranch *relIso03DB_branch;
  bool     relIso03DB_isLoaded;
  float    relIso03EA_;
  TBranch *relIso03EA_branch;
  bool     relIso03EA_isLoaded;
  float    relIso04DB_;
  TBranch *relIso04DB_branch;
  bool     relIso04DB_isLoaded;
  float    relIso04EA_;
  TBranch *relIso04EA_branch;
  bool     relIso04EA_isLoaded;
  float    miniRelIsoDB_;
  TBranch *miniRelIsoDB_branch;
  bool     miniRelIsoDB_isLoaded;
  float    miniRelIsoEA_;
  TBranch *miniRelIsoEA_branch;
  bool     miniRelIsoEA_isLoaded;
  float    relIso005EA_;
  TBranch *relIso005EA_branch;
  bool     relIso005EA_isLoaded;
  float    relIso010EA_;
  TBranch *relIso010EA_branch;
  bool     relIso010EA_isLoaded;
  float    relIso015EA_;
  TBranch *relIso015EA_branch;
  bool     relIso015EA_isLoaded;
  float    relIso020EA_;
  TBranch *relIso020EA_branch;
  bool     relIso020EA_isLoaded;
  float    relIso025EA_;
  TBranch *relIso025EA_branch;
  bool     relIso025EA_isLoaded;
  float    relIso030EA_;
  TBranch *relIso030EA_branch;
  bool     relIso030EA_isLoaded;
  float    relIso035EA_;
  TBranch *relIso035EA_branch;
  bool     relIso035EA_isLoaded;
  float    relIso045EA_;
  TBranch *relIso045EA_branch;
  bool     relIso045EA_isLoaded;
  float    relIso050EA_;
  TBranch *relIso050EA_branch;
  bool     relIso050EA_isLoaded;
  float    absIso03_;
  TBranch *absIso03_branch;
  bool     absIso03_isLoaded;
  float    absIso03DB_;
  TBranch *absIso03DB_branch;
  bool     absIso03DB_isLoaded;
  float    absIso03EA_;
  TBranch *absIso03EA_branch;
  bool     absIso03EA_isLoaded;
  float    absIso04DB_;
  TBranch *absIso04DB_branch;
  bool     absIso04DB_isLoaded;
  float    absIso04EA_;
  TBranch *absIso04EA_branch;
  bool     absIso04EA_isLoaded;
  float    pt_;
  TBranch *pt_branch;
  bool     pt_isLoaded;
  float    eta_;
  TBranch *eta_branch;
  bool     eta_isLoaded;
  int      pdgId_;
  TBranch *pdgId_branch;
  bool     pdgId_isLoaded;
  float    relIso03EAv2_;
  TBranch *relIso03EAv2_branch;
  bool     relIso03EAv2_isLoaded;
  float    relIso04EAv2_;
  TBranch *relIso04EAv2_branch;
  bool     relIso04EAv2_isLoaded;
  float    miniRelIsoEAv2_;
  TBranch *miniRelIsoEAv2_branch;
  bool     miniRelIsoEAv2_isLoaded;
  float    absIso03EAv2_;
  TBranch *absIso03EAv2_branch;
  bool     absIso03EAv2_isLoaded;
  float    absIso04EAv2_;
  TBranch *absIso04EAv2_branch;
  bool     absIso04EAv2_isLoaded;
public: 
void Init(TTree *tree);
void GetEntry(unsigned int idx); 
void LoadAllBranches(); 
  const float &sip3d();
  const float &ip3d();
  const float &ptrel();
  const float &ptratio();
  const float &relIso03();
  const float &relIso03DB();
  const float &relIso03EA();
  const float &relIso04DB();
  const float &relIso04EA();
  const float &miniRelIsoDB();
  const float &miniRelIsoEA();
  const float &relIso005EA();
  const float &relIso010EA();
  const float &relIso015EA();
  const float &relIso020EA();
  const float &relIso025EA();
  const float &relIso030EA();
  const float &relIso035EA();
  const float &relIso045EA();
  const float &relIso050EA();
  const float &absIso03();
  const float &absIso03DB();
  const float &absIso03EA();
  const float &absIso04DB();
  const float &absIso04EA();
  const float &pt();
  const float &eta();
  const int &pdgId();
  const float &relIso03EAv2();
  const float &relIso04EAv2();
  const float &miniRelIsoEAv2();
  const float &absIso03EAv2();
  const float &absIso04EAv2();

  static void progress(int nEventsTotal, int nEventsChain);
};

#ifndef __CINT__
extern IsoTree mytree;
#endif

namespace tas {
  const float &sip3d();
  const float &ip3d();
  const float &ptrel();
  const float &ptratio();
  const float &relIso03();
  const float &relIso03DB();
  const float &relIso03EA();
  const float &relIso04DB();
  const float &relIso04EA();
  const float &miniRelIsoDB();
  const float &miniRelIsoEA();
  const float &relIso005EA();
  const float &relIso010EA();
  const float &relIso015EA();
  const float &relIso020EA();
  const float &relIso025EA();
  const float &relIso030EA();
  const float &relIso035EA();
  const float &relIso045EA();
  const float &relIso050EA();
  const float &absIso03();
  const float &absIso03DB();
  const float &absIso03EA();
  const float &absIso04DB();
  const float &absIso04EA();
  const float &pt();
  const float &eta();
  const int &pdgId();
  const float &relIso03EAv2();
  const float &relIso04EAv2();
  const float &miniRelIsoEAv2();
  const float &absIso03EAv2();
  const float &absIso04EAv2();
}
#endif
