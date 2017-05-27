// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#include "MyBabyConnector.h"

ObjUtil::Leptons getLeptons(/*MyBaby& mytree*/)
{
  ObjUtil::Leptons leptons;
  for (int ilep = 0; ilep < mytree.lep_n(); ++ilep)
  {
    ObjUtil::Lepton lepton;
    lepton.p4.SetPtEtaPhiM(mytree.lep_pt().at(ilep),mytree.lep_eta().at(ilep),mytree.lep_phi().at(ilep),mytree.lep_mass().at(ilep));
    // General
    lepton.dxy = mytree.lep_dxy().at(ilep);
    lepton.dz = mytree.lep_dz().at(ilep);
    lepton.ip3d = mytree.lep_ip3d().at(ilep);
    lepton.sip3d = mytree.lep_sip3d().at(ilep);
    lepton.tightcharge = mytree.lep_tightcharge().at(ilep);
    lepton.charge = mytree.lep_charge().at(ilep);
    lepton.pdgId = mytree.lep_pdgId().at(ilep);
    lepton.id = mytree.lep_id().at(ilep);
    // Isolation related
    lepton.ptRatio = mytree.lep_ptRatio().at(ilep);
    lepton.ptRel = mytree.lep_ptRel().at(ilep);
    lepton.relIso03 = mytree.lep_relIso03().at(ilep);
    lepton.relIso03DB = mytree.lep_relIso03DB().at(ilep);
    lepton.relIso03EA = mytree.lep_relIso03EA().at(ilep);
    lepton.relIso04DB = mytree.lep_relIso04DB().at(ilep);
    lepton.relIso04EA = mytree.lep_relIso04EA().at(ilep);
    lepton.relIso005EAstudy = mytree.lep_relIso005EAstudy().at(ilep);
    lepton.relIso010EAstudy = mytree.lep_relIso010EAstudy().at(ilep);
    lepton.relIso015EAstudy = mytree.lep_relIso015EAstudy().at(ilep);
    lepton.relIso020EAstudy = mytree.lep_relIso020EAstudy().at(ilep);
    lepton.relIso025EAstudy = mytree.lep_relIso025EAstudy().at(ilep);
    lepton.relIso030EAstudy = mytree.lep_relIso030EAstudy().at(ilep);
    lepton.relIso035EAstudy = mytree.lep_relIso035EAstudy().at(ilep);
    lepton.relIso040EAstudy = mytree.lep_relIso040EAstudy().at(ilep);
    lepton.relIso045EAstudy = mytree.lep_relIso045EAstudy().at(ilep);
    lepton.relIso050EAstudy = mytree.lep_relIso050EAstudy().at(ilep);
    lepton.relIso005EAstudyv2 = mytree.lep_relIso005EAstudyv2().at(ilep);
    lepton.relIso010EAstudyv2 = mytree.lep_relIso010EAstudyv2().at(ilep);
    lepton.relIso015EAstudyv2 = mytree.lep_relIso015EAstudyv2().at(ilep);
    lepton.relIso020EAstudyv2 = mytree.lep_relIso020EAstudyv2().at(ilep);
    lepton.relIso025EAstudyv2 = mytree.lep_relIso025EAstudyv2().at(ilep);
    lepton.relIso030EAstudyv2 = mytree.lep_relIso030EAstudyv2().at(ilep);
    lepton.relIso035EAstudyv2 = mytree.lep_relIso035EAstudyv2().at(ilep);
    lepton.relIso040EAstudyv2 = mytree.lep_relIso040EAstudyv2().at(ilep);
    lepton.relIso045EAstudyv2 = mytree.lep_relIso045EAstudyv2().at(ilep);
    lepton.relIso050EAstudyv2 = mytree.lep_relIso050EAstudyv2().at(ilep);
    lepton.miniRelIsoCMS3_DB = mytree.lep_miniRelIsoCMS3_DB().at(ilep);
    lepton.miniRelIsoCMS3_EA = mytree.lep_miniRelIsoCMS3_EA().at(ilep);
    lepton.relIso03EAv2 = mytree.lep_relIso03EAv2().at(ilep);
    lepton.relIso04EAv2 = mytree.lep_relIso04EAv2().at(ilep);
    lepton.miniRelIsoCMS3_EAv2 = mytree.lep_miniRelIsoCMS3_EAv2().at(ilep);
    // Muon specifics
    lepton.muPOverP = mytree.lep_muPOverP().at(ilep);
    lepton.muPidPFMuon = mytree.lep_muPidPFMuon().at(ilep);
    lepton.muType = mytree.lep_muType().at(ilep);
    lepton.muChi2OverNDof = mytree.lep_muChi2OverNDof().at(ilep);
    lepton.muChi2LocalPosition = mytree.lep_muChi2LocalPosition().at(ilep);
    lepton.muTrkKink = mytree.lep_muTrkKink().at(ilep);
    lepton.muValidHitFraction = mytree.lep_muValidHitFraction().at(ilep);
    lepton.muSegmCompatibility = mytree.lep_muSegmCompatibility().at(ilep);
    // Electron specifics
    lepton.elEtaSC = mytree.lep_elEtaSC().at(ilep);
    lepton.elSigmaIEtaIEta_full5x5 = mytree.lep_elSigmaIEtaIEta_full5x5().at(ilep);
    lepton.elHOverE = mytree.lep_elHOverE().at(ilep);
    lepton.elMva = mytree.lep_elMva().at(ilep);
    lepton.elDEtaIn = mytree.lep_elDEtaIn().at(ilep);
    lepton.elDPhiIn = mytree.lep_elDPhiIn().at(ilep);
    lepton.elEpRatio = mytree.lep_elEpRatio().at(ilep);
    lepton.elConvVeto = mytree.lep_elConvVeto().at(ilep);
    lepton.elNmiss = mytree.lep_elNmiss().at(ilep);
    lepton.isFromX = mytree.lep_isFromX().at(ilep);
    leptons.push_back(lepton);
  }
  return leptons;
}

ObjUtil::Jets getJets(/*MyBaby& mytree*/)
{
  ObjUtil::Jets jets;
  for (int ijet = 0; ijet < mytree.jet_n(); ++ijet)
  {
    ObjUtil::Jet jet;
    jet.p4.SetPtEtaPhiM(mytree.jet_pt().at(ijet),mytree.jet_eta().at(ijet),mytree.jet_phi().at(ijet),mytree.jet_mass().at(ijet));
    jet.btagCSV = mytree.jet_btagCSV().at(ijet);
    jet.rawPt = mytree.jet_rawPt().at(ijet);
    jet.mcPt = mytree.jet_mcPt().at(ijet);
    jet.mcFlavour = mytree.jet_mcFlavour().at(ijet);
    jet.hadronFlavour = mytree.jet_hadronFlavour().at(ijet);
    jet.area = mytree.jet_area().at(ijet);
    jet.undoJEC = mytree.jet_undoJEC().at(ijet);
    jet.jecCorr = mytree.jet_jecCorr().at(ijet);
    jet.jecCorrUp = mytree.jet_jecCorrUp().at(ijet);
    jet.jecCorrDn = mytree.jet_jecCorrDn().at(ijet);
    jet.chf = mytree.jet_chf().at(ijet);
    jet.id = mytree.jet_id().at(ijet);
    jet.puId = mytree.jet_puId().at(ijet);
    jet.puIdpuppi = mytree.jet_puIdpuppi().at(ijet);
    jet.FSveto = mytree.jet_FSveto().at(ijet);
    // optional
    jet.chf = mytree.jet_chf().at(ijet);
    jet.nhf = mytree.jet_nhf().at(ijet);
    jet.cef = mytree.jet_cef().at(ijet);
    jet.nef = mytree.jet_nef().at(ijet);
    jet.muf = mytree.jet_muf().at(ijet);
    jet.cm = mytree.jet_cm().at(ijet);
    jet.nm = mytree.jet_nm().at(ijet);
    jet.puValue = mytree.jet_puValue().at(ijet);
    jet.mcdr = mytree.jet_mcdr().at(ijet);
    jet.npfcand = mytree.jet_npfcand().at(ijet);
    // optional
    jets.push_back(jet);
  }
  return jets;
}

ObjUtil::Jets getBJets(/*MyBaby& mytree*/)
{
  ObjUtil::Jets jets;
  return jets;
}

ObjUtil::METs getMETs(/*MyBaby& mytree*/)
{
  ObjUtil::METs mets;
  return mets;
}

ObjUtil::MET getMET(/*MyBaby& mytree*/)
{
  ObjUtil::MET met;
  met.p4.SetPtEtaPhiE(mytree.met_pt(), 0, mytree.met_phi(), mytree.met_pt());
  return met;
}

//eof

// MadGraph lhe output
// ------------------------------------------------------------------
//  for (unsigned int ip = 0; ip < mytree.P_X->size(); ++ip)
//  {
//    ObjUtil::Jet jet;
//    float px     = mytree.P_X -> at(ip);
//    float py     = mytree.P_Y -> at(ip);
//    float pz     = mytree.P_Z -> at(ip);
//    float energy = mytree.E   -> at(ip);
//    int   pdgId  = mytree.PID -> at(ip);
//    if (abs(pdgId) <= 5 || abs(pdgId) == 21)
//    {
//      jet.id = pdgId;
//      jet.p4.SetXYZT(px, py, pz, energy);
//      jets.push_back(jet);
//    }
//  }
//  std::sort(jets.begin(), jets.end(), comparator_pt<ObjUtil::Jet>);
// ------------------------------------------------------------------
