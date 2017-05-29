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

}


//______________________________________________________________________________________
void loop()
{

  // Loop over file:ttree -> and loop over events in ttree
  // (usually I only have one file each.. so kinda redundant)
  while (LoopUtil::nextFileAndLoadTTreeWithName("MyBaby"))
  {

    initMyBaby();

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
}

//______________________________________________________________________________________
void loadMyBabyEvent()
{
  mytree.GetEntry(LoopUtil::getCurrentTTreeEventIndex());
}

//______________________________________________________________________________________
void processMyBabyEvent()
{

  doIsoStudy();

}

//______________________________________________________________________________________
void afterLoop()
{
  // Save plots
  PlotUtil::savePlots(ana_data.hist_db, LoopUtil::output_name + "_hist.root");

  // Fun exit
  PrintUtil::exit();
}

//=====================================================================================
//=====================================================================================
//=====================================================================================

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
bool isNonIsoGoodLepton(ObjUtil::Lepton& lepton)
{
  return isNonIsoGoodElectron(lepton) || isNonIsoGoodMuon(lepton);
}

//______________________________________________________________________________________
bool isNonIsoGoodElectron(ObjUtil::Lepton& lepton)
{
  if (!( isNonIsoNoIPGoodElectron(lepton)         )) return false;
  if (!( fabs(lepton.sip3d)               <  4    )) return false;
  if (!( fabs(lepton.ip3d)                <  0.015)) return false;
  if (!( fabs(lepton.p4.Eta())            <  2.4  )) return false;
  if (!( fabs(lepton.p4.Pt())             > 10.   )) return false;
  return true;
}

//______________________________________________________________________________________
bool isNonIsoGoodMuon(ObjUtil::Lepton& lepton)
{
  if (!( isNonIsoNoIPGoodMuon(lepton)             )) return false;
  if (!( fabs(lepton.sip3d)               <  4    )) return false;
  if (!( fabs(lepton.ip3d)                <  0.015)) return false;
  if (!( fabs(lepton.p4.Eta())            <  2.4  )) return false;
  if (!( fabs(lepton.p4.Pt())             > 10.   )) return false;
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
bool isNonIsoNoIPGoodLepton(ObjUtil::Lepton& lepton)
{
  return isNonIsoNoIPGoodElectron(lepton) || isNonIsoNoIPGoodMuon(lepton);
}

//______________________________________________________________________________________
bool isNonIsoNoIPGoodElectron(ObjUtil::Lepton& lepton)
{
  int cutflow = 0;
                                                                   if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( fabs(lepton.pdgId)               == 11   )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( fabs(lepton.elEtaSC)             <= 2.5  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( !(lepton.elConvVeto)                     )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( lepton.elNmiss                   <= 0    )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( fabs(lepton.dz)                  <  0.1  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( fabs(lepton.dxy)                 <  0.05 )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( lepton.tightcharge               == 2    )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( Analyses::isElectronPOGMVAIDCut(lepton,
          /* barrel */      0.77, 0.52, 0.77,
          /* transition */  0.56, 0.11, 0.56,
          /* endcap */      0.48,-0.01, 0.48)     )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( Analyses::isTriggerSafenoIso_v1(lepton)  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( lepton.isFromX & (1<<0)                  ))               if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if ( ( lepton.isFromX & (1<<0)                  ))               if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  return true;
}

//______________________________________________________________________________________
bool isNonIsoNoIPGoodMuon(ObjUtil::Lepton& lepton)
{
  int cutflow = 0;
                                                                if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( abs(lepton.pdgId)          ==   13    )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( fabs(lepton.dz)            <=    0.1  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( fabs(lepton.dxy)           <=    0.05 )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( lepton.muPOverP            <     0.2  )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( Analyses::isMediumMuonPOG(lepton)     )) return false; if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if (!( lepton.isFromX & (1<<0)               ))               if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  if ( ( lepton.isFromX & (1<<0)               ))               if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
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
  int cutflow = 0;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( fabs(lepton.pdgId)               == 11   )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( fabs(lepton.elEtaSC)             <= 2.5  )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( !(lepton.elConvVeto)                     )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( lepton.elNmiss                   <= 1    )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( fabs(lepton.dz)                  <  0.1  )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( fabs(lepton.dxy)                 <  0.05 )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( fabs(lepton.p4.Pt())             >  7.   )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( Analyses::isTriggerSafenoIso_v1(lepton)  )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( lepton.isFromX & (1<<0)                  ))
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if ( ( lepton.isFromX & (1<<0)                  ))
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  return true;
}

//______________________________________________________________________________________
bool isVetoMuon(ObjUtil::Lepton& lepton)
{
  int cutflow = 0;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( abs(lepton.pdgId)          ==   13    )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( fabs(lepton.dz)            <=    0.1  )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( fabs(lepton.dxy)           <=    0.05 )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( fabs(lepton.p4.Pt())       >     5.   )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( Analyses::isLooseMuonPOG(lepton)      )) return false;
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if (!( lepton.isFromX & (1<<0)               ))
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow); if ( ( lepton.isFromX & (1<<0)               ))
  if (do_object_cutflow) HistUtil::fillCutflow(__FUNCTION__, ana_data, cutflow);
  return true;
}

//______________________________________________________________________________________
bool isGoodJet(ObjUtil::Jet& jet)
{
  if (!( jet.p4.Pt()         > 20. )) return false;
  if (!( fabs(jet.p4.Eta())  <  5. )) return false;
//	  if (!( Analyses::isLoosePFJet_Summer16_v1(jet)  )) return false;
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

//=====================================================================================
//=====================================================================================
//=====================================================================================

//______________________________________________________________________________________
void doIsoStudy()
{
  /// Get objects
  ObjUtil::Leptons leptons = getLeptons();
  ObjUtil::Jets jets = getJets();

  /// Select leptons
  Analyses::selectObjs<ObjUtil::Lepton>(leptons, isNonIsoGoodMuon);
  Analyses::selectObjs<ObjUtil::Jet>   (jets   , isGoodJet);

  /// If no lepton candidates found, skip
  if (leptons.size() == 0) return;

  PlotUtil::plot1D("beforeORnlep", leptons.size(), mytree.evt_scale1fb(), ana_data.hist_db, "", 5, 0, 5);
  PlotUtil::plot1D("beforeORnjet", jets.size()   , mytree.evt_scale1fb(), ana_data.hist_db, "", 5, 0, 5);

  Analyses::removeJetsOverlappingLeptons(jets, leptons);

  PlotUtil::plot1D("nlep", leptons.size(), mytree.evt_scale1fb(), ana_data.hist_db, "", 5, 0, 5);
  PlotUtil::plot1D("njet", jets.size()   , mytree.evt_scale1fb(), ana_data.hist_db, "", 5, 0, 5);

  int counter = 0;
  HistUtil::fillCutflow(__FUNCTION__, ana_data, counter);

  int nprompt = 0;
  int nmisid = 0;

  for (auto& lepton: leptons)
  {
    if (!( lepton.p4.Pt() > 25 ))
      continue;
    if (!( fabs(lepton.p4.Eta()) < 2.4 ))
      continue;
    if (!( abs(lepton.pdgId) == 13 ))
      continue;
    if      (lepton.isFromX & (1<<0)) { nprompt++; }
    else if (lepton.isFromX & (1<<2)) { nmisid ++; }
    else if (lepton.isFromX & (1<<3)) { nmisid ++; }
    else if (lepton.isFromX & (1<<4)) { nmisid ++; }
    else if (lepton.isFromX & (1<<5)) { nmisid ++; }
    doFillHistograms("nvtxAll", lepton);
    if (mytree.evt_nvtx() < 15)
      doFillHistograms("nvtxle15", lepton);
    else if (mytree.evt_nvtx() >= 15 && mytree.evt_nvtx() < 25)
      doFillHistograms("nvtxgeq15le25", lepton);
    else if (mytree.evt_nvtx() >= 25 && mytree.evt_nvtx() < 35)
      doFillHistograms("nvtxgeq25le35", lepton);
    else if (mytree.evt_nvtx() >= 35)
      doFillHistograms("nvtxgeq35", lepton);
  }

  PlotUtil::plot1D("nprompt", nprompt, mytree.evt_scale1fb(), ana_data.hist_db, "", 5, 0, 5);
  PlotUtil::plot1D("nmisid" , nmisid , mytree.evt_scale1fb(), ana_data.hist_db, "", 5, 0, 5);

}

//______________________________________________________________________________________
void doFillHistograms(string prefix, ObjUtil::Lepton& lepton)
{
  if      (lepton.isFromX & (1<<0)) { fillHistograms(TString::Format("Prompt_%s", prefix.c_str()).Data(), lepton); }
  else if (lepton.isFromX & (1<<2)) { fillHistograms(TString::Format("MisID_%s" , prefix.c_str()).Data(), lepton); }
  else if (lepton.isFromX & (1<<3)) { fillHistograms(TString::Format("MisID_%s" , prefix.c_str()).Data(), lepton); }
  else if (lepton.isFromX & (1<<4)) { fillHistograms(TString::Format("MisID_%s" , prefix.c_str()).Data(), lepton); }
  else if (lepton.isFromX & (1<<5)) { fillHistograms(TString::Format("MisID_%s" , prefix.c_str()).Data(), lepton); }
}

//______________________________________________________________________________________
void fillHistograms(string prefix, ObjUtil::Lepton& lepton)
{
  PlotUtil::plot1D(prefix+"_widerange_ip3d"         , lepton.ip3d                        , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.5);
  PlotUtil::plot1D(prefix+"_widerange_sip3d"        , lepton.sip3d                       , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 50.);
  PlotUtil::plot1D(prefix+"_widerange_relIso03"     , lepton.relIso03                    , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso03EA"   , lepton.relIso03EA                  , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso03DB"   , lepton.relIso03DB                  , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso04EA"   , lepton.relIso04EA                  , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso04DB"   , lepton.relIso04DB                  , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_miniRelIsoEA" , lepton.miniRelIsoCMS3_EA           , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_miniRelIsoDB" , lepton.miniRelIsoCMS3_DB           , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);

  PlotUtil::plot1D(prefix+"_widerange_relIso005EA"  , lepton.relIso005EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso010EA"  , lepton.relIso010EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso015EA"  , lepton.relIso015EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso020EA"  , lepton.relIso020EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso025EA"  , lepton.relIso025EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso030EA"  , lepton.relIso030EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso035EA"  , lepton.relIso035EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso040EA"  , lepton.relIso040EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso045EA"  , lepton.relIso045EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso050EA"  , lepton.relIso050EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);

  PlotUtil::plot1D(prefix+"_widerange_relIso005EAuseVetoCone"  , lepton.relIso005EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso010EAuseVetoCone"  , lepton.relIso010EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso015EAuseVetoCone"  , lepton.relIso015EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso020EAuseVetoCone"  , lepton.relIso020EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso025EAuseVetoCone"  , lepton.relIso025EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso030EAuseVetoCone"  , lepton.relIso030EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso035EAuseVetoCone"  , lepton.relIso035EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso040EAuseVetoCone"  , lepton.relIso040EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso045EAuseVetoCone"  , lepton.relIso045EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);
  PlotUtil::plot1D(prefix+"_widerange_relIso050EAuseVetoCone"  , lepton.relIso050EAstudyv2 , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 12.);

  PlotUtil::plot1D(prefix+"_relIso005EA"            , lepton.relIso005EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso010EA"            , lepton.relIso010EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso015EA"            , lepton.relIso015EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso020EA"            , lepton.relIso020EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso025EA"            , lepton.relIso025EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso030EA"            , lepton.relIso030EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso035EA"            , lepton.relIso035EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso040EA"            , lepton.relIso040EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso045EA"            , lepton.relIso045EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso050EA"            , lepton.relIso050EAstudy            , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);

  PlotUtil::plot1D(prefix+"_relIso005EAv2"          , lepton.relIso005EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso010EAv2"          , lepton.relIso010EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso015EAv2"          , lepton.relIso015EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso020EAv2"          , lepton.relIso020EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso025EAv2"          , lepton.relIso025EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso030EAv2"          , lepton.relIso030EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso035EAv2"          , lepton.relIso035EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso040EAv2"          , lepton.relIso040EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso045EAv2"          , lepton.relIso045EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso050EAv2"          , lepton.relIso050EAstudyv2          , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);

  PlotUtil::plot1D(prefix+"_relIso03"               , lepton.relIso03                    , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso03EA"             , lepton.relIso03EA                  , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso03EAv2"           , lepton.relIso03EAv2                , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso03DB"             , lepton.relIso03DB                  , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso04EA"             , lepton.relIso04EA                  , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso04EAv2"           , lepton.relIso04EAv2                , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_relIso04DB"             , lepton.relIso04DB                  , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_miniRelIsoEA"           , lepton.miniRelIsoCMS3_EA           , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_miniRelIsoEAv2"         , lepton.miniRelIsoCMS3_EAv2         , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_miniRelIsoDB"           , lepton.miniRelIsoCMS3_DB           , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.25);
  PlotUtil::plot1D(prefix+"_absIso03"               , lepton.relIso03*lepton.p4.Pt()     , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso03EA"             , lepton.relIso03EA*lepton.p4.Pt()   , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso03EAv2"           , lepton.relIso03EAv2*lepton.p4.Pt() , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso03DB"             , lepton.relIso03DB*lepton.p4.Pt()   , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso04EA"             , lepton.relIso04EA*lepton.p4.Pt()   , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso04EAv2"           , lepton.relIso04EAv2*lepton.p4.Pt() , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_absIso04DB"             , lepton.relIso04DB*lepton.p4.Pt()   , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 10);
  PlotUtil::plot1D(prefix+"_pt"                     , lepton.p4.Pt()                     , mytree.evt_scale1fb() , ana_data.hist_db , "" , 60    , 0. , 60);
  PlotUtil::plot1D(prefix+"_ip3d"                   , lepton.ip3d                        , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 0.1);
  PlotUtil::plot1D(prefix+"_sip3d"                  , lepton.sip3d                       , mytree.evt_scale1fb() , ana_data.hist_db , "" , 10000 , 0. , 10);

  PlotUtil::plot1D(prefix+"_nvtx"                  , mytree.evt_nvtx()                  , mytree.evt_scale1fb() , ana_data.hist_db , "" ,    80 , 0. , 80);
}


//eof
