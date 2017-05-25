// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "IsoTreeConnector.h"

ObjUtil::Leptons getLeptons(/*IsoTree& mytree*/)
{
  ObjUtil::Leptons leptons;
  ObjUtil::Lepton lepton;
  lepton.p4.SetPtEtaPhiM(mytree.pt(),mytree.eta(),0.,0.);
  lepton.ptRel = mytree.ptrel();
  lepton.ptRatio = mytree.ptratio();
  lepton.relIso03 = mytree.relIso03();
  lepton.relIso03DB = mytree.relIso03DB();
  lepton.relIso03EA = mytree.relIso03EA();
  lepton.relIso04DB = mytree.relIso04DB();
  lepton.relIso04EA = mytree.relIso04EA();
  lepton.relIso005EAstudy = mytree.relIso005EA();
  lepton.relIso010EAstudy = mytree.relIso010EA();
  lepton.relIso015EAstudy = mytree.relIso015EA();
  lepton.relIso020EAstudy = mytree.relIso020EA();
  lepton.relIso025EAstudy = mytree.relIso025EA();
  lepton.relIso030EAstudy = mytree.relIso030EA();
  lepton.relIso035EAstudy = mytree.relIso035EA();
  lepton.relIso045EAstudy = mytree.relIso045EA();
  lepton.relIso050EAstudy = mytree.relIso050EA();
  lepton.miniRelIsoCMS3_DB = mytree.miniRelIsoDB();
  lepton.miniRelIsoCMS3_EA = mytree.miniRelIsoEA();
  lepton.relIso03EAv2 = mytree.relIso03EAv2();
  lepton.relIso04EAv2 = mytree.relIso04EAv2();
  lepton.miniRelIsoCMS3_EAv2 = mytree.miniRelIsoEAv2();
  lepton.pdgId = mytree.pdgId();
  lepton.ip3d = mytree.ip3d();
  lepton.sip3d = mytree.sip3d();
  leptons.push_back(lepton);
  return leptons;
}

ObjUtil::Jets getJets(/*IsoTree& mytree*/)
{
  ObjUtil::Jets jets;
  return jets;
}

ObjUtil::Jets getBJets(/*IsoTree& mytree*/)
{
  ObjUtil::Jets jets;
  return jets;
}

ObjUtil::METs getMETs(/*IsoTree& mytree*/)
{
  ObjUtil::METs mets;
  return mets;
}

ObjUtil::MET getMET(/*IsoTree& mytree*/)
{
  ObjUtil::MET met;
  return met;
}

//eof
