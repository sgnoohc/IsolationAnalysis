// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef IsoTreeLooper_h
#define IsoTreeLooper_h

// ROOT
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TObjArray.h>
#include <TString.h>
#include <TTree.h>

// C++
#include <iostream>

// Ditto
#include "Ditto.h"
#include "IsoTree.h"
#include "IsoTreeConnector.h"

using namespace Ditto;

//extern IsoTree mytree;
extern ObjUtil::AnalysisData ana_data;
extern TString output_name;

int IsoTreeLooper(TChain* chain, TString output_name, int nEvents);
void loop();
void beforeLoop(TChain* chain, TString output_name, int nevents);
void afterLoop();
void initIsoTree();
void loadIsoTreeEvent();
void processIsoTreeEvent();
void getObjects();

void fillHistograms(string prefix, ObjUtil::Lepton& lepton);

#endif
//eof
