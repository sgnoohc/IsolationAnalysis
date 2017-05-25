// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MyBabyLooper.h"

//MyBaby mytree;
ObjUtil::AnalysisData ana_data;
ObjUtil::AnalysisData ana_data_good_lep;
ObjUtil::AnalysisData ana_data_fake_lep;
TString output_name;

// isotree
TFile* isofilegood;
TFile* isofilefake;
TTree* isotreegood;
TTree* isotreefake;

bool do_object_cutflow = true;

//______________________________________________________________________________________
int MyBabyLooper(TChain* chain, TString output_name, int nevents)
{

  // Before the loop set up some configuration, histograms and etc.
  beforeLoop(chain, output_name, nevents);

  // During the event loop process each event one by one
  loop();

  // After the loop is done, save histograms and etc.
  afterLoop();

  return 0;
}

//______________________________________________________________________________________
void beforeLoop(TChain* chain, TString output_name_, int nevents)
{

  // Fun start ASCII art
  PrintUtil::start();

  // Initialize configurations for event looping
  LoopUtil::resetLoopCondition(chain, nevents);

  //output_name = output_name_;
  LoopUtil::output_name = output_name_;

  // If output name does not contain "_skimtree" setDoSkim
  if (!LoopUtil::output_name.Contains("_skimtree"))
    LoopUtil::doskim = true;

  // If output_name contains "_skimtree" remove it.
  LoopUtil::output_name.ReplaceAll("_skimtree", "");

  // Create a small ntuple for isolation study
  createIsoTree();

}


//______________________________________________________________________________________
void loop()
{

  // Loop over file:ttree -> and loop over events in ttree
  // (usually I only have one file each.. so kinda redundant)
  while (LoopUtil::nextFileAndLoadTTreeWithName("MyBaby"))
  {

    initMyBaby();

    // I am assuming I only run one file at a time
    // NOTE: Later I should probably update this to be more general
    if (LoopUtil::doskim)
      TreeUtil::createSkimTree((LoopUtil::output_name+"_skimtree.root").Data());

    // Loop over the TTree
    while (LoopUtil::nextEvent())
    {

      if (LoopUtil::isAllEventsProcessed()) break;

      loadMyBabyEvent();

      //=================================================================
      // <3 of the code
      // Do whatever you want to in the following function for each event
      //=================================================================
      processMyBabyEvent();

    } // End TTree loop

  } // End Loop over files
}

//______________________________________________________________________________________
void initMyBaby()
{
  // Init the Class
  mytree.Init(LoopUtil::getCurrentTTree());

  // If skim job, load all branches
  if (LoopUtil::doskim)
    mytree.LoadAllBranches();
}

//______________________________________________________________________________________
void loadMyBabyEvent()
{
  mytree.GetEntry(LoopUtil::getCurrentTTreeEventIndex());
}

//______________________________________________________________________________________
void processMyBabyEvent()
{
  // HT filter stitching for DY
  if (LoopUtil::output_name.Contains("dy__m") && !LoopUtil::output_name.Contains("ht"))
    if (mytree.gen_ht() > 100.)
      return;

  // HT filter stitching for DY
  if (LoopUtil::output_name.Contains("wjets__") && !LoopUtil::output_name.Contains("ht"))
    if (mytree.gen_ht() > 100.)
      return;

  //if (LoopUtil::doskim)
  //  doSkimming();

  doSMWWWSSmmAnalysis();

  doFillIsoTree();

}

//______________________________________________________________________________________
void getObjects()
{
  /// Get objects
  ana_data.lepcol["skimlep"] = getLeptons();
  ana_data.lepcol["goodlep"] = getLeptons();
  ana_data.lepcol["vetolep"] = getLeptons();
  ana_data.jetcol["goodjet"] = getJets();
  ana_data.jetcol["medbjet"] = getJets();
  ana_data.jetcol["lssbjet"] = getJets();
  ana_data.met = getMET();
  ana_data.wgt = mytree.evt_scale1fb();
}

//______________________________________________________________________________________
void afterLoop()
{
  // Save histograms
  PlotUtil::savePlots(ana_data.hist_db,          (LoopUtil::output_name+"_hist.root").Data());
  PlotUtil::savePlots(ana_data_good_lep.hist_db, (LoopUtil::output_name+"_isostudysiglepton_hist.root").Data());
  PlotUtil::savePlots(ana_data_fake_lep.hist_db, (LoopUtil::output_name+"_isostudybkglepton_hist.root").Data());

  // Save skimmmed tree
  if (LoopUtil::doskim)
    TreeUtil::saveSkimTree();

  // Save iso trees
  isofilegood->cd();
  isotreegood->Write();
  isofilegood->Write();
  isofilegood->Close();
  isofilefake->cd();
  isotreefake->Write();
  isofilefake->Write();
  isofilefake->Close();

  // Fun exit
  PrintUtil::exit();
}

//=====================================================================================
//=====================================================================================
//=====================================================================================

//______________________________________________________________________________________
void doSkimming()
{
  /// Set objects
  getObjects();

  /// selectObjs for skimming
  selectObjectsForSkimming();

  /// Fill skimmed ttree
  if (passSkimming())
    TreeUtil::fillSkimTree();
}

//______________________________________________________________________________________
void selectObjectsForSkimming()
{
  Analyses::selectObjs<ObjUtil::Lepton>(ana_data.lepcol["skimlep"], isNonIsoGoodLepton);
}

//______________________________________________________________________________________
bool isNonIsoGoodLepton(ObjUtil::Lepton& lepton)
{
  return isNonIsoGoodElectron(lepton) || isNonIsoGoodMuon(lepton);
}

//______________________________________________________________________________________
bool isNonIsoGoodElectron(ObjUtil::Lepton& lepton)
{
  if (!( isNonIsoNoIPGoodElectron(lepton)         )) return false;
//	  if (!( fabs(lepton.sip3d)               <  4    )) return false;
  if (!( fabs(lepton.ip3d)                <  0.015)) return false;
  if (!( fabs(lepton.p4.Eta())            <  2.4  )) return false;
  if (!( fabs(lepton.p4.Pt())             > 10.   )) return false;
  return true;
}

//______________________________________________________________________________________
bool isNonIsoGoodMuon(ObjUtil::Lepton& lepton)
{
  if (!( isNonIsoNoIPGoodMuon(lepton)             )) return false;
//	  if (!( fabs(lepton.sip3d)               <  4    )) return false;
  if (!( fabs(lepton.ip3d)                <  0.015)) return false;
  if (!( fabs(lepton.p4.Eta())            <  2.4  )) return false;
  if (!( fabs(lepton.p4.Pt())             > 10.   )) return false;
  return true;
}


//______________________________________________________________________________________
bool passSkimming()
{
  if (ana_data.lepcol["skimlep"].size() < 2)
    return false;
  if ((ana_data.lepcol["skimlep"].size() == 2) && ((ana_data.lepcol["skimlep"][0].pdgId * ana_data.lepcol["skimlep"][1].pdgId) < 0))
    return false;
  return true;
}


//=====================================================================================
//=====================================================================================
//=====================================================================================

//______________________________________________________________________________________
void doSMWWWSSmmAnalysis()
{

  /// Set objects
  getObjects();

  /// selectObjects for analysis
  selectObjects();

  /// Overlap removal
  overlapRemoval();

  /// Cutflow
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  0); if (!( ana_data.lepcol["goodlep"].size() == 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  1); if (!( ana_data.lepcol["vetolep"].size() == 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  2); if (!( ana_data.lepcol["goodlep"][0].pdgId * ana_data.lepcol["goodlep"][1].pdgId == 169  )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  3); if (!( ana_data.lepcol["goodlep"][0].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  4); if (!( ana_data.lepcol["goodlep"][1].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  5); if (!( ana_data.jetcol["goodjet"].size() >= 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  6); if (!( ana_data.jetcol["goodjet"][0].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  7); if (!( ana_data.jetcol["goodjet"][1].p4.Pt() > 20.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  8); if (!( fabs(ana_data.jetcol["goodjet"][0].p4.Eta()) < 2.5                                )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  9); if (!( fabs(ana_data.jetcol["goodjet"][1].p4.Eta()) < 2.5                                )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 10); if (!( ana_data.jetcol["medbjet"].size() == 0                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 11); if (!( VarUtil::DEta(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) < 1.5 )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 12); if (!( VarUtil::Mass(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) < 105.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 13); if (!( VarUtil::Mass(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) >  65.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 14); if (!( VarUtil::Mass(ana_data.lepcol["goodlep"][0], ana_data.lepcol["goodlep"][1]) >  40.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 15);

  /// Select object containers for plotting
  ana_data.leptons = ana_data.lepcol["goodlep"];
  HistUtil::fillMET(__FUNCTION__, ana_data);
  HistUtil::fillLepSumPt(__FUNCTION__, ana_data);
}

//______________________________________________________________________________________
void doSMWWWSSeeAnalysis()
{

  /// Set objects
  getObjects();

  /// selectObjects for analysis
  selectObjects();

  /// Overlap removal
  overlapRemoval();

  /// Cutflow
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  0); if (!( ana_data.lepcol["goodlep"].size() == 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  1); if (!( ana_data.lepcol["vetolep"].size() == 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  2); if (!( ana_data.lepcol["goodlep"][0].pdgId * ana_data.lepcol["goodlep"][1].pdgId == 121  )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  3); if (!( ana_data.lepcol["goodlep"][0].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  4); if (!( ana_data.lepcol["goodlep"][1].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  5); if (!( ana_data.jetcol["goodjet"].size() >= 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  6); if (!( ana_data.jetcol["goodjet"][0].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  7); if (!( ana_data.jetcol["goodjet"][1].p4.Pt() > 20.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  8); if (!( fabs(ana_data.jetcol["goodjet"][0].p4.Eta()) < 2.5                                )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  9); if (!( fabs(ana_data.jetcol["goodjet"][1].p4.Eta()) < 2.5                                )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 10); if (!( ana_data.jetcol["medbjet"].size() == 0                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 11); if (!( VarUtil::DEta(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) < 1.5 )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 12); if (!( VarUtil::Mass(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) < 105.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 13); if (!( VarUtil::Mass(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) >  65.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 14); if (!( VarUtil::Mass(ana_data.lepcol["goodlep"][0], ana_data.lepcol["goodlep"][1]) >  40.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 15); if (!( VarUtil::Mass(ana_data.lepcol["goodlep"][0], ana_data.lepcol["goodlep"][1]) > 100.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 16); if (!( VarUtil::Mass(ana_data.lepcol["goodlep"][0], ana_data.lepcol["goodlep"][1]) <  80.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 17); if (!( ana_data.met.p4.Pt() > 55.                                                        )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 18);

  /// Select object containers for plotting
  ana_data.leptons = ana_data.lepcol["goodlep"];
  HistUtil::fillMET(__FUNCTION__, ana_data);
  HistUtil::fillLepSumPt(__FUNCTION__, ana_data);
}

//______________________________________________________________________________________
void doSMWWWSSemAnalysis()
{

  /// Set objects
  getObjects();

  /// selectObjects for analysis
  selectObjects();

  /// Overlap removal
  overlapRemoval();

  /// Cutflow
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  0); if (!( ana_data.lepcol["goodlep"].size() == 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  1); if (!( ana_data.lepcol["vetolep"].size() == 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  2); if (!( ana_data.lepcol["goodlep"][0].pdgId * ana_data.lepcol["goodlep"][1].pdgId == 143  )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  3); if (!( ana_data.lepcol["goodlep"][0].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  4); if (!( ana_data.lepcol["goodlep"][1].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  5); if (!( ana_data.jetcol["goodjet"].size() >= 2                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  6); if (!( ana_data.jetcol["goodjet"][0].p4.Pt() > 30.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  7); if (!( ana_data.jetcol["goodjet"][1].p4.Pt() > 20.                                       )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  8); if (!( fabs(ana_data.jetcol["goodjet"][0].p4.Eta()) < 2.5                                )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data,  9); if (!( fabs(ana_data.jetcol["goodjet"][1].p4.Eta()) < 2.5                                )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 10); if (!( ana_data.jetcol["medbjet"].size() == 0                                            )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 11); if (!( VarUtil::DEta(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) < 1.5 )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 12); if (!( VarUtil::Mass(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) < 105.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 13); if (!( VarUtil::Mass(ana_data.jetcol["goodjet"][0], ana_data.jetcol["goodjet"][1]) >  65.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 14); if (!( VarUtil::Mass(ana_data.lepcol["goodlep"][0], ana_data.lepcol["goodlep"][1]) >  40.)) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 15); if (!( ana_data.met.p4.Pt() > 55.                                                        )) return;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, 16);

  /// Select object containers for plotting
  ana_data.leptons = ana_data.lepcol["goodlep"];
  HistUtil::fillMET(__FUNCTION__, ana_data);
  HistUtil::fillLepSumPt(__FUNCTION__, ana_data);
}

//______________________________________________________________________________________
void selectObjects()
{
  Analyses::selectObjs<ObjUtil::Lepton>(ana_data.lepcol["goodlep"] , isGoodLepton);
  Analyses::selectObjs<ObjUtil::Lepton>(ana_data.lepcol["vetolep"] , isVetoLepton);
  Analyses::selectObjs<ObjUtil::Jet>   (ana_data.jetcol["goodjet"] , isGoodJet);
  Analyses::selectObjs<ObjUtil::Jet>   (ana_data.jetcol["medbjet"] , isGoodMediumBJet);
  Analyses::selectObjs<ObjUtil::Jet>   (ana_data.jetcol["lssbjet"] , isGoodLooseBJet);
}

//______________________________________________________________________________________
bool isGoodLepton(ObjUtil::Lepton& lepton)
{
  return isGoodElectron(lepton) || isGoodMuon(lepton);
}

//______________________________________________________________________________________
bool isGoodElectron(ObjUtil::Lepton& lepton)
{
  if (!( lepton.p4.Pt() > 20.         )) return false;
  if (!( fabs(lepton.p4.Eta()) < 2.4  )) return false;
  if (!( isNonIsoGoodElectron(lepton) )) return false;
  if (!( isIsoElectron(lepton)        )) return false;
  return true;
}

//______________________________________________________________________________________
bool isGoodMuon(ObjUtil::Lepton& lepton)
{
  if (!( lepton.p4.Pt() > 20.        )) return false;
  if (!( fabs(lepton.p4.Eta()) < 2.4 )) return false;
  if (!( isNonIsoGoodMuon(lepton)    )) return false;
  if (!( isIsoMuon(lepton)           )) return false;
  return true;
}

//______________________________________________________________________________________
bool isIsoElectron(ObjUtil::Lepton& lepton)
{
//	  if (!( lepton.miniRelIsoCMS3_EA                 <  0.12 )) return false;
//	  if (!( lepton.ptRatio >  0.80 || lepton.ptRel   >  7.2  )) return false;
  if (!( lepton.relIso03EA <  0.06 )) return false;
  return true;
}

//______________________________________________________________________________________
bool isIsoMuon(ObjUtil::Lepton& lepton)
{
//	  if (!( lepton.miniRelIsoCMS3_EA                 <  0.16 )) return false;
//	  if (!( lepton.ptRatio >  0.76 || lepton.ptRel   >  7.2  )) return false;
  if (!( lepton.relIso03EA <  0.1 )) return false;
  return true;
}

//______________________________________________________________________________________
bool isVetoLepton(ObjUtil::Lepton& lepton)
{
  return isVetoElectron(lepton) || isVetoMuon(lepton);
}

//______________________________________________________________________________________
bool isVetoElectron(ObjUtil::Lepton& lepton)
{
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  0); if (!( fabs(lepton.pdgId)               == 11   )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  1); if (!( fabs(lepton.elEtaSC)             <= 2.5  )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  2); if (!( !(lepton.elConvVeto)                     )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  3); if (!( lepton.elNmiss                   <= 1    )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  4); if (!( fabs(lepton.dz)                  <  0.1  )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  5); if (!( fabs(lepton.dxy)                 <  0.05 )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  6); if (!( fabs(lepton.p4.Pt())             >  7.   )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  7); if (!( Analyses::isTriggerSafenoIso_v1(lepton)  )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  8); if (!( lepton.isFromX & (1<<0)                  ))
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  9); if ( ( lepton.isFromX & (1<<0)                  ))
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 10);
  return true;
}

//______________________________________________________________________________________
bool isVetoMuon(ObjUtil::Lepton& lepton)
{
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 0); if (!( abs(lepton.pdgId)          ==   13    )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 1); if (!( fabs(lepton.dz)            <=    0.1  )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 2); if (!( fabs(lepton.dxy)           <=    0.05 )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 3); if (!( fabs(lepton.p4.Pt())       >     5.   )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 4); if (!( Analyses::isLooseMuonPOG(lepton)      )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 5); if (!( lepton.isFromX & (1<<0)               ))
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 6); if ( ( lepton.isFromX & (1<<0)               ))
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 7);
  return true;
}

//______________________________________________________________________________________
bool isGoodJet(ObjUtil::Jet& jet)
{
  if (!( jet.p4.Pt()         > 20. )) return false;
  if (!( fabs(jet.p4.Eta())  <  5. )) return false;
  if (!( Analyses::isLoosePFJet_Summer16_v1(jet)  )) return false;
  return true;
}

//______________________________________________________________________________________
bool isGoodMediumBJet(ObjUtil::Jet& jet)
{
  if (!( isGoodJet(jet)              )) return false;
  if (!( Analyses::isMediumBJet(jet) )) return false;
  return true;
}

//______________________________________________________________________________________
bool isGoodLooseBJet(ObjUtil::Jet& jet)
{
  if (!( isGoodJet(jet)              )) return false;
  if (!( Analyses::isLooseBJet(jet) )) return false;
  return true;
}

//______________________________________________________________________________________
void overlapRemoval()
{
  Analyses::removeJetsOverlappingLeptons(ana_data.jetcol["goodjet"] , ana_data.lepcol["goodlep"]);
  Analyses::removeJetsOverlappingLeptons(ana_data.jetcol["medbjet"] , ana_data.lepcol["goodlep"]);
  Analyses::removeJetsOverlappingLeptons(ana_data.jetcol["lssbjet"] , ana_data.lepcol["goodlep"]);
}

//=====================================================================================
//=====================================================================================
//=====================================================================================

//______________________________________________________________________________________
void createIsoTree()
{
  isofilegood = new TFile((LoopUtil::output_name+"_isotree_sig.root").Data(), "recreate");
  isotreegood = new TTree("IsoTree", "IsoTree");
  isofilefake = new TFile((LoopUtil::output_name+"_isotree_bkg.root").Data(), "recreate");
  isotreefake = new TTree("IsoTree", "IsoTree");

  TreeUtil::createFloatBranch(isotreegood, "sip3d");
  TreeUtil::createFloatBranch(isotreegood, "ip3d");
  TreeUtil::createFloatBranch(isotreegood, "ptrel");
  TreeUtil::createFloatBranch(isotreegood, "ptratio");
  TreeUtil::createFloatBranch(isotreegood, "relIso03");
  TreeUtil::createFloatBranch(isotreegood, "relIso03DB");
  TreeUtil::createFloatBranch(isotreegood, "relIso03EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso04DB");
  TreeUtil::createFloatBranch(isotreegood, "relIso04EA");
  TreeUtil::createFloatBranch(isotreegood, "miniRelIsoDB");
  TreeUtil::createFloatBranch(isotreegood, "miniRelIsoEA");
  TreeUtil::createFloatBranch(isotreegood, "relIso005EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso010EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso015EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso020EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso025EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso030EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso035EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso045EA");
  TreeUtil::createFloatBranch(isotreegood, "relIso050EA");
  TreeUtil::createFloatBranch(isotreegood, "absIso03");
  TreeUtil::createFloatBranch(isotreegood, "absIso03DB");
  TreeUtil::createFloatBranch(isotreegood, "absIso03EA");
  TreeUtil::createFloatBranch(isotreegood, "absIso04DB");
  TreeUtil::createFloatBranch(isotreegood, "absIso04EA");
  TreeUtil::createFloatBranch(isotreegood, "pt");
  TreeUtil::createFloatBranch(isotreegood, "eta");
  TreeUtil::createIntBranch  (isotreegood, "pdgId");
  TreeUtil::createFloatBranch(isotreegood, "relIso03EAv2");
  TreeUtil::createFloatBranch(isotreegood, "relIso04EAv2");
  TreeUtil::createFloatBranch(isotreegood, "miniRelIsoEAv2");
  TreeUtil::createFloatBranch(isotreegood, "absIso03EAv2");
  TreeUtil::createFloatBranch(isotreegood, "absIso04EAv2");

  TreeUtil::createFloatBranch(isotreefake, "sip3d");
  TreeUtil::createFloatBranch(isotreefake, "ip3d");
  TreeUtil::createFloatBranch(isotreefake, "ptrel");
  TreeUtil::createFloatBranch(isotreefake, "ptratio");
  TreeUtil::createFloatBranch(isotreefake, "relIso03");
  TreeUtil::createFloatBranch(isotreefake, "relIso03DB");
  TreeUtil::createFloatBranch(isotreefake, "relIso03EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso04DB");
  TreeUtil::createFloatBranch(isotreefake, "relIso04EA");
  TreeUtil::createFloatBranch(isotreefake, "miniRelIsoDB");
  TreeUtil::createFloatBranch(isotreefake, "miniRelIsoEA");
  TreeUtil::createFloatBranch(isotreefake, "relIso005EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso010EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso015EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso020EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso025EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso030EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso035EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso045EA");
  TreeUtil::createFloatBranch(isotreefake, "relIso050EA");
  TreeUtil::createFloatBranch(isotreefake, "absIso03");
  TreeUtil::createFloatBranch(isotreefake, "absIso03DB");
  TreeUtil::createFloatBranch(isotreefake, "absIso03EA");
  TreeUtil::createFloatBranch(isotreefake, "absIso04DB");
  TreeUtil::createFloatBranch(isotreefake, "absIso04EA");
  TreeUtil::createFloatBranch(isotreefake, "pt");
  TreeUtil::createFloatBranch(isotreefake, "eta");
  TreeUtil::createIntBranch  (isotreefake, "pdgId");
  TreeUtil::createFloatBranch(isotreefake, "relIso03EAv2");
  TreeUtil::createFloatBranch(isotreefake, "relIso04EAv2");
  TreeUtil::createFloatBranch(isotreefake, "miniRelIsoEAv2");
  TreeUtil::createFloatBranch(isotreefake, "absIso03EAv2");
  TreeUtil::createFloatBranch(isotreefake, "absIso04EAv2");
}

//______________________________________________________________________________________
void doFillIsoTree()
{
  /// Get objects
  ObjUtil::Leptons leptons = getLeptons();
  ObjUtil::Jets jets = getJets();

  /// Select leptons
  Analyses::selectObjs<ObjUtil::Lepton>(leptons, isNonIsoGoodLepton);
  Analyses::selectObjs<ObjUtil::Jet>(jets, isGoodJet);

  PlotUtil::plot1D("beforeORnlep", leptons.size(), 1, ana_data.hist_db, "", 5, 0, 5);
  PlotUtil::plot1D("beforeORnjet", jets.size()   , 1, ana_data.hist_db, "", 5, 0, 5);

  Analyses::removeJetsOverlappingLeptons(jets, leptons);

  PlotUtil::plot1D("nlep", leptons.size(), 1, ana_data.hist_db, "", 5, 0, 5);
  PlotUtil::plot1D("njet", jets.size()   , 1, ana_data.hist_db, "", 5, 0, 5);

  HistUtil::fillCutflow(__FUNCTION__, ana_data, 0);

//	  if (VarUtil::MinDR(jets, leptons) < 0.4)
//	  {
//	    HistUtil::fillCutflow(__FUNCTION__, ana_data, 1);
//	    return;
//	  }

  for (auto& lepton: leptons)
  {

    TreeUtil::initTreeData();

    TreeUtil::setFloatBranch("ip3d"           , lepton.ip3d);
    TreeUtil::setFloatBranch("sip3d"          , lepton.sip3d);
    TreeUtil::setFloatBranch("ptrel"          , lepton.ptRel);
    TreeUtil::setFloatBranch("ptratio"        , lepton.ptRatio);
    TreeUtil::setFloatBranch("relIso03"       , lepton.relIso03);
    TreeUtil::setFloatBranch("relIso03DB"     , lepton.relIso03DB);
    TreeUtil::setFloatBranch("relIso03EA"     , lepton.relIso03EA);
    TreeUtil::setFloatBranch("relIso04DB"     , lepton.relIso04DB);
    TreeUtil::setFloatBranch("relIso04EA"     , lepton.relIso04EA);
    TreeUtil::setFloatBranch("miniRelIsoDB"   , lepton.miniRelIsoCMS3_DB);
    TreeUtil::setFloatBranch("miniRelIsoEA"   , lepton.miniRelIsoCMS3_EA);
    TreeUtil::setFloatBranch("relIso005EA"    , lepton.relIso005EAstudy);
    TreeUtil::setFloatBranch("relIso010EA"    , lepton.relIso010EAstudy);
    TreeUtil::setFloatBranch("relIso015EA"    , lepton.relIso015EAstudy);
    TreeUtil::setFloatBranch("relIso020EA"    , lepton.relIso020EAstudy);
    TreeUtil::setFloatBranch("relIso025EA"    , lepton.relIso025EAstudy);
    TreeUtil::setFloatBranch("relIso030EA"    , lepton.relIso030EAstudy);
    TreeUtil::setFloatBranch("relIso035EA"    , lepton.relIso035EAstudy);
    TreeUtil::setFloatBranch("relIso045EA"    , lepton.relIso045EAstudy);
    TreeUtil::setFloatBranch("relIso050EA"    , lepton.relIso050EAstudy);
    TreeUtil::setFloatBranch("absIso03"       , lepton.relIso03*lepton.p4.Pt());
    TreeUtil::setFloatBranch("absIso03DB"     , lepton.relIso03DB*lepton.p4.Pt());
    TreeUtil::setFloatBranch("absIso03EA"     , lepton.relIso03EA*lepton.p4.Pt());
    TreeUtil::setFloatBranch("absIso04DB"     , lepton.relIso04DB*lepton.p4.Pt());
    TreeUtil::setFloatBranch("absIso04EA"     , lepton.relIso04EA*lepton.p4.Pt());
    TreeUtil::setFloatBranch("pt"             , lepton.p4.Pt());
    TreeUtil::setFloatBranch("eta"            , lepton.p4.Eta());
    TreeUtil::setIntBranch  ("pdgId"          , lepton.pdgId);
    TreeUtil::setFloatBranch("relIso03EAv2"   , lepton.relIso03EAv2);
    TreeUtil::setFloatBranch("relIso04EAv2"   , lepton.relIso04EAv2);
    TreeUtil::setFloatBranch("miniRelIsoEAv2" , lepton.miniRelIsoCMS3_EAv2);
    TreeUtil::setFloatBranch("absIso03EAv2"   , lepton.relIso03EAv2*lepton.p4.Pt());
    TreeUtil::setFloatBranch("absIso04EAv2"   , lepton.relIso04EAv2*lepton.p4.Pt());

    if (lepton.p4.Pt() <= 10)
      continue;
    if (lepton.isFromX & (1<<0))
    {
//	      ObjUtil::Leptons goodleptons;
//	      goodleptons.push_back(lepton);
//	      if (jets.size() < 4)
//	        continue;
//	      if (VarUtil::MinDR(jets, goodleptons) > 0.4)
//	        isotreegood->Fill();
      isotreegood->Fill();

    }
    else if (lepton.isFromX & (1<<2))
      isotreefake->Fill();
    else if (lepton.isFromX & (1<<3))
      isotreefake->Fill();
    else if (lepton.isFromX & (1<<4))
      isotreefake->Fill();
    else if (lepton.isFromX & (1<<5))
      isotreefake->Fill();

  }

}

//______________________________________________________________________________________
bool isNonIsoNoIPGoodLepton(ObjUtil::Lepton& lepton)
{
  return isNonIsoNoIPGoodElectron(lepton) || isNonIsoNoIPGoodMuon(lepton);
}

//______________________________________________________________________________________
bool isNonIsoNoIPGoodElectron(ObjUtil::Lepton& lepton)
{
                                                                   if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  0);
  if (!( fabs(lepton.pdgId)               == 11   )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  1);
  if (!( fabs(lepton.elEtaSC)             <= 2.5  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  2);
  if (!( !(lepton.elConvVeto)                     )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  3);
  if (!( lepton.elNmiss                   <= 0    )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  4);
  if (!( fabs(lepton.dz)                  <  0.1  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  5);
  if (!( fabs(lepton.dxy)                 <  0.05 )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  6);
  if (!( lepton.tightcharge               == 2    )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  7);
  if (!( Analyses::isElectronPOGMVAIDCut(lepton,
          /* barrel */      0.77, 0.52, 0.77,
          /* transition */  0.56, 0.11, 0.56,
          /* endcap */      0.48,-0.01, 0.48)     )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  8);
  if (!( Analyses::isTriggerSafenoIso_v1(lepton)  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data,  9);
  if (!( lepton.isFromX & (1<<0)                  ))               if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 10);
  if ( ( lepton.isFromX & (1<<0)                  ))               if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 11);
  return true;
}

//______________________________________________________________________________________
bool isNonIsoNoIPGoodMuon(ObjUtil::Lepton& lepton)
{
                                                                if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 0);
  if (!( abs(lepton.pdgId)          ==   13    )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 1);
  if (!( fabs(lepton.dz)            <=    0.1  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 2);
  if (!( fabs(lepton.dxy)           <=    0.05 )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 3);
  if (!( lepton.muPOverP            <     0.2  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 4);
  if (!( Analyses::isMediumMuonPOG(lepton)     )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 5);
  if (!( lepton.isFromX & (1<<0)               ))               if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 6);
  if ( ( lepton.isFromX & (1<<0)               ))               if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, 7);
  return true;
}


//eof
