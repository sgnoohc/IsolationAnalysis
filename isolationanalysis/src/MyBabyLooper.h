// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef MyBabyLooper_h
#define MyBabyLooper_h

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
#include "MyBaby.h"
#include "MyBabyConnector.h"

using namespace Ditto;

//extern MyBaby mytree;
extern ObjUtil::AnalysisData ana_data;
extern ObjUtil::AnalysisData ana_data_good_lep;
extern ObjUtil::AnalysisData ana_data_fake_lep;
//extern TString output_name;

extern TFile* isofilegood;
extern TFile* isofilefake;
extern TTree* isotreegood;
extern TTree* isotreefake;

extern bool do_object_cutflow;

int MyBabyLooper(TChain* chain, TString output_name, int nEvents);
void loop();
void beforeLoop(TChain* chain, TString output_name, int nevents);
void afterLoop();
void initMyBaby();
void loadMyBabyEvent();
void processMyBabyEvent();

//-------------------------------------------------------------

bool isGoodLepton(ObjUtil::Lepton& lepton);
bool isGoodElectron(ObjUtil::Lepton& lepton);
bool isGoodMuon(ObjUtil::Lepton& lepton);
bool isNonIsoGoodLepton(ObjUtil::Lepton& lepton);
bool isNonIsoGoodMuon(ObjUtil::Lepton& lepton);
bool isNonIsoGoodElectron(ObjUtil::Lepton& lepton);
bool isIsoElectron(ObjUtil::Lepton& lepton);
bool isIsoMuon(ObjUtil::Lepton& lepton);
bool isNonIsoNoIPGoodLepton(ObjUtil::Lepton& lepton);
bool isNonIsoNoIPGoodMuon(ObjUtil::Lepton& lepton);
bool isNonIsoNoIPGoodElectron(ObjUtil::Lepton& lepton);
bool isVetoLepton(ObjUtil::Lepton& lepton);
bool isVetoMuon(ObjUtil::Lepton& lepton);
bool isVetoElectron(ObjUtil::Lepton& lepton);
bool isGoodJet(ObjUtil::Jet& jet);
bool isGoodMediumBJet(ObjUtil::Jet& jet);
bool isGoodLooseBJet(ObjUtil::Jet& jet);
void overlapRemoval();


//-------------------------------------------------------------

void createIsoTree();
void doFillIsoTree();

#endif
//eof
