// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "IsoTreeLooper.h"

//IsoTree mytree;
ObjUtil::AnalysisData ana_data;
TString output_name;

//______________________________________________________________________________________
int IsoTreeLooper(TChain* chain, TString output_name, int nevents)
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

  // Replace all ".root" added accidentally
  output_name_.ReplaceAll(".root", "");
  LoopUtil::output_name = output_name_;

}


//______________________________________________________________________________________
void loop()
{

  // Loop over file:ttree -> and loop over events in ttree
  // (usually I only have one file each.. so kinda redundant)
  while (LoopUtil::nextFileAndLoadTTreeWithName("IsoTree"))
  {

    initIsoTree();

    // Loop over the TTree
    while (LoopUtil::nextEvent())
    {

      if (LoopUtil::isAllEventsProcessed()) break;

      loadIsoTreeEvent();

      //=================================================================
      // <3 of the code
      // Do whatever you want to in the following function for each event
      //=================================================================
      processIsoTreeEvent();

    } // End TTree loop

  } // End Loop over files
}

//______________________________________________________________________________________
void initIsoTree()
{
  // Init the Class
  mytree.Init(LoopUtil::getCurrentTTree());
}

//______________________________________________________________________________________
void loadIsoTreeEvent()
{
  //mytree.LoadTree(LoopUtil::getCurrentTTreeEventIndex());
  mytree.GetEntry(LoopUtil::getCurrentTTreeEventIndex());
}

//______________________________________________________________________________________
void processIsoTreeEvent()
{
  /// Set objects
  getObjects();

  ObjUtil::Lepton lepton = ana_data.leptons[0];
  // less than 50
  if (lepton.p4.Pt() < 50. && lepton.p4.Pt() > 10.)
  {
    fillHistograms("le50_lepton", lepton);
    if (abs(lepton.pdgId) == 11)
      fillHistograms("le50_electron", lepton);
    else
      fillHistograms("le50_muon", lepton);
  }
  if (lepton.p4.Pt() > 25.)
  {
    fillHistograms("lepton", lepton);
    if (abs(lepton.pdgId) == 11)
      fillHistograms("electron", lepton);
    else
      fillHistograms("muon", lepton);
  }
  else if (lepton.p4.Pt() > 10. && lepton.p4.Pt() <= 25.)
  {
    fillHistograms("lowpt_lepton", lepton);
    if (abs(lepton.pdgId) == 11)
      fillHistograms("lowpt_electron", lepton);
    else
      fillHistograms("lowpt_muon", lepton);
  }

  // Cutflow

  // Nominal isolation working point
  if (abs(lepton.pdgId) == 13)
  {
    if (lepton.p4.Pt() > 25.)
    {
      HistUtil::fillCutflow("SSMuonIsolationWPs", ana_data, 0); if (lepton.miniRelIsoCMS3_EA < 0.4)
      HistUtil::fillCutflow("SSMuonIsolationWPs", ana_data, 1); if (lepton.miniRelIsoCMS3_EA < 0.4 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.76))
      HistUtil::fillCutflow("SSMuonIsolationWPs", ana_data, 2); if (lepton.miniRelIsoCMS3_EA < 0.16 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.76))
      HistUtil::fillCutflow("SSMuonIsolationWPs", ana_data, 3);
    }
    else if (lepton.p4.Pt() > 10. && lepton.p4.Pt() < 25.)
    {
      HistUtil::fillCutflow("lowPtSSMuonIsolationWPs", ana_data, 0); if (lepton.miniRelIsoCMS3_EA < 0.4)
      HistUtil::fillCutflow("lowPtSSMuonIsolationWPs", ana_data, 1); if (lepton.miniRelIsoCMS3_EA < 0.4 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.76))
      HistUtil::fillCutflow("lowPtSSMuonIsolationWPs", ana_data, 2); if (lepton.miniRelIsoCMS3_EA < 0.16 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.76))
      HistUtil::fillCutflow("lowPtSSMuonIsolationWPs", ana_data, 3);
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  0); if (lepton.relIso03EA < 0.01)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  1); if (lepton.relIso03EA < 0.02)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  2); if (lepton.relIso03EA < 0.03)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  3); if (lepton.relIso03EA < 0.04)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  4); if (lepton.relIso03EA < 0.05)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  5); if (lepton.relIso03EA < 0.06)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  6); if (lepton.relIso03EA < 0.07)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  7); if (lepton.relIso03EA < 0.08)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  8); if (lepton.relIso03EA < 0.09)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data,  9); if (lepton.relIso03EA < 0.10)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 10); if (lepton.relIso03EA < 0.11)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 11); if (lepton.relIso03EA < 0.12)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 12); if (lepton.relIso03EA < 0.13)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 13); if (lepton.relIso03EA < 0.14)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 14); if (lepton.relIso03EA < 0.15)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 15); if (lepton.relIso03EA < 0.16)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 16); if (lepton.relIso03EA < 0.17)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 17); if (lepton.relIso03EA < 0.18)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 18); if (lepton.relIso03EA < 0.19)
      HistUtil::fillCutflow("lowPt03MuonIsolationWPs", ana_data, 19);
    }
    if (lepton.p4.Pt() < 50. && lepton.p4.Pt() > 10.)
    {
      HistUtil::fillCutflow("le50SSMuonIsolationWPs", ana_data, 0); if (lepton.miniRelIsoCMS3_EA < 0.4)
      HistUtil::fillCutflow("le50SSMuonIsolationWPs", ana_data, 1); if (lepton.miniRelIsoCMS3_EA < 0.4 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.76))
      HistUtil::fillCutflow("le50SSMuonIsolationWPs", ana_data, 2); if (lepton.miniRelIsoCMS3_EA < 0.16 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.76))
      HistUtil::fillCutflow("le50SSMuonIsolationWPs", ana_data, 3);
    }
    HistUtil::fillCutflow("SSMuonSIP3DWPs", ana_data, 0);
    if (lepton.sip3d < 4)
      HistUtil::fillCutflow("SSMuonSIP3DWPs", ana_data, 1);
    if (lepton.sip3d < 2)
      HistUtil::fillCutflow("SSMuonSIP3DWPs", ana_data, 2);
  }
  else if (abs(lepton.pdgId) == 11)
  {
    if (lepton.p4.Pt() > 25.)
    {
      HistUtil::fillCutflow("SSElectronIsolationWPs", ana_data, 0); if (lepton.miniRelIsoCMS3_EA < 0.4)
      HistUtil::fillCutflow("SSElectronIsolationWPs", ana_data, 1); if (lepton.miniRelIsoCMS3_EA < 0.4 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.80))
      HistUtil::fillCutflow("SSElectronIsolationWPs", ana_data, 2); if (lepton.miniRelIsoCMS3_EA < 0.12 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.80))
      HistUtil::fillCutflow("SSElectronIsolationWPs", ana_data, 3);
    }
    else if (lepton.p4.Pt() > 10. && lepton.p4.Pt() < 25.)
    {
      HistUtil::fillCutflow("lowPtSSElectronIsolationWPs", ana_data, 0); if (lepton.miniRelIsoCMS3_EA < 0.4)
      HistUtil::fillCutflow("lowPtSSElectronIsolationWPs", ana_data, 1); if (lepton.miniRelIsoCMS3_EA < 0.4 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.80))
      HistUtil::fillCutflow("lowPtSSElectronIsolationWPs", ana_data, 2); if (lepton.miniRelIsoCMS3_EA < 0.12 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.80))
      HistUtil::fillCutflow("lowPtSSElectronIsolationWPs", ana_data, 3);
    }
    if (lepton.p4.Pt() < 50. && lepton.p4.Pt() > 10.)
    {
      HistUtil::fillCutflow("le50SSElectronIsolationWPs", ana_data, 0); if (lepton.miniRelIsoCMS3_EA < 0.4)
      HistUtil::fillCutflow("le50SSElectronIsolationWPs", ana_data, 1); if (lepton.miniRelIsoCMS3_EA < 0.4 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.80))
      HistUtil::fillCutflow("le50SSElectronIsolationWPs", ana_data, 2); if (lepton.miniRelIsoCMS3_EA < 0.12 && (lepton.ptRel > 7.2 || lepton.ptRatio > 0.80))
      HistUtil::fillCutflow("le50SSElectronIsolationWPs", ana_data, 3);
    }
    HistUtil::fillCutflow("SSElectronSIP3DWPs", ana_data, 0);
    if (lepton.sip3d < 4)
      HistUtil::fillCutflow("SSElectronSIP3DWPs", ana_data, 1);
    if (lepton.sip3d < 2)
      HistUtil::fillCutflow("SSElectronSIP3DWPs", ana_data, 2);
  }

}

//______________________________________________________________________________________
void getObjects()
{
  /// Get objects
  ana_data.leptons = getLeptons(/*mytree*/);
  //ana_data.jets    = getJets(/*mytree*/);
  //ana_data.met     = getMET(/*mytree*/);
  //ana_data.wgt     = mytree.evt_scale1fb;
  ana_data.wgt     = 1;
}

//______________________________________________________________________________________
void afterLoop()
{
  // Save histograms
  PlotUtil::savePlots(ana_data.hist_db, (LoopUtil::output_name+"_hist.root").Data());

  // Fun exit
  PrintUtil::exit();
}

//______________________________________________________________________________________
void fillHistograms(string prefix, ObjUtil::Lepton& lepton)
{
  PlotUtil::plot1D(prefix+"_widerange_ip3d"         , lepton.ip3d                        , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.5);
  PlotUtil::plot1D(prefix+"_widerange_sip3d"        , lepton.sip3d                       , 1 , ana_data.hist_db , "" , 10000 , 0. , 50.);
  PlotUtil::plot1D(prefix+"_widerange_relIso03"     , lepton.relIso03                    , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso03EA"   , lepton.relIso03EA                  , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso03DB"   , lepton.relIso03DB                  , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso04EA"   , lepton.relIso04EA                  , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso04DB"   , lepton.relIso04DB                  , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_miniRelIsoEA" , lepton.miniRelIsoCMS3_EA           , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_miniRelIsoDB" , lepton.miniRelIsoCMS3_DB           , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);

//	  PlotUtil::plot1D(prefix+"_widerange_relIso005EA"  , lepton.relIso005EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
//	  PlotUtil::plot1D(prefix+"_widerange_relIso010EA"  , lepton.relIso010EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
//	  PlotUtil::plot1D(prefix+"_widerange_relIso015EA"  , lepton.relIso015EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
//	  PlotUtil::plot1D(prefix+"_widerange_relIso020EA"  , lepton.relIso020EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
//	  PlotUtil::plot1D(prefix+"_widerange_relIso025EA"  , lepton.relIso025EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
//	  PlotUtil::plot1D(prefix+"_widerange_relIso030EA"  , lepton.relIso030EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
//	  PlotUtil::plot1D(prefix+"_widerange_relIso035EA"  , lepton.relIso035EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
//	  PlotUtil::plot1D(prefix+"_widerange_relIso045EA"  , lepton.relIso045EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);
//	  PlotUtil::plot1D(prefix+"_widerange_relIso050EA"  , lepton.relIso050EAstudy            , 1 , ana_data.hist_db , "" , 10000 , 0. , 12.);

  PlotUtil::plot1D(prefix+"_widerange_relIso005EA"  , lepton.relIso005EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);
  PlotUtil::plot1D(prefix+"_widerange_relIso010EA"  , lepton.relIso010EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);
  PlotUtil::plot1D(prefix+"_widerange_relIso015EA"  , lepton.relIso015EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);
  PlotUtil::plot1D(prefix+"_widerange_relIso020EA"  , lepton.relIso020EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);
  PlotUtil::plot1D(prefix+"_widerange_relIso025EA"  , lepton.relIso025EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);
  PlotUtil::plot1D(prefix+"_widerange_relIso030EA"  , lepton.relIso030EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);
  PlotUtil::plot1D(prefix+"_widerange_relIso035EA"  , lepton.relIso035EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);
  PlotUtil::plot1D(prefix+"_widerange_relIso045EA"  , lepton.relIso045EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);
  PlotUtil::plot1D(prefix+"_widerange_relIso050EA"  , lepton.relIso050EAstudy , 1 , ana_data.hist_db , "" , 10000 , -5. , -1.);

  PlotUtil::plot1D(prefix+"_relIso03"               , lepton.relIso03                    , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso03EA"             , lepton.relIso03EA                  , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso03EAv2"           , lepton.relIso03EAv2                , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso03DB"             , lepton.relIso03DB                  , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso04EA"             , lepton.relIso04EA                  , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso04EAv2"           , lepton.relIso04EAv2                , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso04DB"             , lepton.relIso04DB                  , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_miniRelIsoEA"           , lepton.miniRelIsoCMS3_EA           , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_miniRelIsoEAv2"         , lepton.miniRelIsoCMS3_EAv2         , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_miniRelIsoDB"           , lepton.miniRelIsoCMS3_DB           , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_absIso03"               , lepton.relIso03*lepton.p4.Pt()     , 1 , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso03EA"             , lepton.relIso03EA*lepton.p4.Pt()   , 1 , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso03EAv2"           , lepton.relIso03EAv2*lepton.p4.Pt() , 1 , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso03DB"             , lepton.relIso03DB*lepton.p4.Pt()   , 1 , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso04EA"             , lepton.relIso04EA*lepton.p4.Pt()   , 1 , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso04EAv2"           , lepton.relIso04EAv2*lepton.p4.Pt() , 1 , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso04DB"             , lepton.relIso04DB*lepton.p4.Pt()   , 1 , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_pt"                     , lepton.p4.Pt()                     , 1 , ana_data.hist_db , "" , 60    , 0. , 60);
  PlotUtil::plot1D(prefix+"_ip3d"                   , lepton.ip3d                        , 1 , ana_data.hist_db , "" , 10000 , 0. , 0.1);
  PlotUtil::plot1D(prefix+"_sip3d"                  , lepton.sip3d                       , 1 , ana_data.hist_db , "" , 10000 , 0. , 10);
}

//eof
