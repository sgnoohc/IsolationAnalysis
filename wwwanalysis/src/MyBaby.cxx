#include "MyBaby.h"
MyBaby mytree;

void MyBaby::Init(TTree *tree) {

  tree->SetMakeClass(1);

  truth_n_branch = tree->GetBranch("truth_n");
  if (truth_n_branch) truth_n_branch->SetAddress(&truth_n_);
  truth_pt_branch = tree->GetBranch("truth_pt");
  if (truth_pt_branch) truth_pt_branch->SetAddress(&truth_pt_);
  truth_eta_branch = tree->GetBranch("truth_eta");
  if (truth_eta_branch) truth_eta_branch->SetAddress(&truth_eta_);
  truth_phi_branch = tree->GetBranch("truth_phi");
  if (truth_phi_branch) truth_phi_branch->SetAddress(&truth_phi_);
  truth_mass_branch = tree->GetBranch("truth_mass");
  if (truth_mass_branch) truth_mass_branch->SetAddress(&truth_mass_);
  truth_energy_branch = tree->GetBranch("truth_energy");
  if (truth_energy_branch) truth_energy_branch->SetAddress(&truth_energy_);
  truth_pdgId_branch = tree->GetBranch("truth_pdgId");
  if (truth_pdgId_branch) truth_pdgId_branch->SetAddress(&truth_pdgId_);
  truth_status_branch = tree->GetBranch("truth_status");
  if (truth_status_branch) truth_status_branch->SetAddress(&truth_status_);
  truth_motherId_branch = tree->GetBranch("truth_motherId");
  if (truth_motherId_branch) truth_motherId_branch->SetAddress(&truth_motherId_);
  truth_grandmotherId_branch = tree->GetBranch("truth_grandmotherId");
  if (truth_grandmotherId_branch) truth_grandmotherId_branch->SetAddress(&truth_grandmotherId_);
  lep_n_branch = tree->GetBranch("lep_n");
  if (lep_n_branch) lep_n_branch->SetAddress(&lep_n_);
  lep_pt_branch = tree->GetBranch("lep_pt");
  if (lep_pt_branch) lep_pt_branch->SetAddress(&lep_pt_);
  lep_eta_branch = tree->GetBranch("lep_eta");
  if (lep_eta_branch) lep_eta_branch->SetAddress(&lep_eta_);
  lep_phi_branch = tree->GetBranch("lep_phi");
  if (lep_phi_branch) lep_phi_branch->SetAddress(&lep_phi_);
  lep_mass_branch = tree->GetBranch("lep_mass");
  if (lep_mass_branch) lep_mass_branch->SetAddress(&lep_mass_);
  lep_energy_branch = tree->GetBranch("lep_energy");
  if (lep_energy_branch) lep_energy_branch->SetAddress(&lep_energy_);
  lep_dxy_branch = tree->GetBranch("lep_dxy");
  if (lep_dxy_branch) lep_dxy_branch->SetAddress(&lep_dxy_);
  lep_dz_branch = tree->GetBranch("lep_dz");
  if (lep_dz_branch) lep_dz_branch->SetAddress(&lep_dz_);
  lep_ip3d_branch = tree->GetBranch("lep_ip3d");
  if (lep_ip3d_branch) lep_ip3d_branch->SetAddress(&lep_ip3d_);
  lep_sip3d_branch = tree->GetBranch("lep_sip3d");
  if (lep_sip3d_branch) lep_sip3d_branch->SetAddress(&lep_sip3d_);
  lep_tightcharge_branch = tree->GetBranch("lep_tightcharge");
  if (lep_tightcharge_branch) lep_tightcharge_branch->SetAddress(&lep_tightcharge_);
  lep_charge_branch = tree->GetBranch("lep_charge");
  if (lep_charge_branch) lep_charge_branch->SetAddress(&lep_charge_);
  lep_pdgId_branch = tree->GetBranch("lep_pdgId");
  if (lep_pdgId_branch) lep_pdgId_branch->SetAddress(&lep_pdgId_);
  lep_id_branch = tree->GetBranch("lep_id");
  if (lep_id_branch) lep_id_branch->SetAddress(&lep_id_);
  lep_ptRatio_branch = tree->GetBranch("lep_ptRatio");
  if (lep_ptRatio_branch) lep_ptRatio_branch->SetAddress(&lep_ptRatio_);
  lep_ptRel_branch = tree->GetBranch("lep_ptRel");
  if (lep_ptRel_branch) lep_ptRel_branch->SetAddress(&lep_ptRel_);
  lep_relIso03_branch = tree->GetBranch("lep_relIso03");
  if (lep_relIso03_branch) lep_relIso03_branch->SetAddress(&lep_relIso03_);
  lep_relIso03DB_branch = tree->GetBranch("lep_relIso03DB");
  if (lep_relIso03DB_branch) lep_relIso03DB_branch->SetAddress(&lep_relIso03DB_);
  lep_relIso03EA_branch = tree->GetBranch("lep_relIso03EA");
  if (lep_relIso03EA_branch) lep_relIso03EA_branch->SetAddress(&lep_relIso03EA_);
  lep_relIso03EAv2_branch = tree->GetBranch("lep_relIso03EAv2");
  if (lep_relIso03EAv2_branch) lep_relIso03EAv2_branch->SetAddress(&lep_relIso03EAv2_);
  lep_relIso04_branch = tree->GetBranch("lep_relIso04");
  if (lep_relIso04_branch) lep_relIso04_branch->SetAddress(&lep_relIso04_);
  lep_relIso04DB_branch = tree->GetBranch("lep_relIso04DB");
  if (lep_relIso04DB_branch) lep_relIso04DB_branch->SetAddress(&lep_relIso04DB_);
  lep_relIso04EA_branch = tree->GetBranch("lep_relIso04EA");
  if (lep_relIso04EA_branch) lep_relIso04EA_branch->SetAddress(&lep_relIso04EA_);
  lep_relIso04EAv2_branch = tree->GetBranch("lep_relIso04EAv2");
  if (lep_relIso04EAv2_branch) lep_relIso04EAv2_branch->SetAddress(&lep_relIso04EAv2_);
  lep_miniRelIsoCMS3_EA_branch = tree->GetBranch("lep_miniRelIsoCMS3_EA");
  if (lep_miniRelIsoCMS3_EA_branch) lep_miniRelIsoCMS3_EA_branch->SetAddress(&lep_miniRelIsoCMS3_EA_);
  lep_miniRelIsoCMS3_EAv2_branch = tree->GetBranch("lep_miniRelIsoCMS3_EAv2");
  if (lep_miniRelIsoCMS3_EAv2_branch) lep_miniRelIsoCMS3_EAv2_branch->SetAddress(&lep_miniRelIsoCMS3_EAv2_);
  lep_miniRelIsoCMS3_DB_branch = tree->GetBranch("lep_miniRelIsoCMS3_DB");
  if (lep_miniRelIsoCMS3_DB_branch) lep_miniRelIsoCMS3_DB_branch->SetAddress(&lep_miniRelIsoCMS3_DB_);
  lep_relIso005EAstudy_branch = tree->GetBranch("lep_relIso005EAstudy");
  if (lep_relIso005EAstudy_branch) lep_relIso005EAstudy_branch->SetAddress(&lep_relIso005EAstudy_);
  lep_relIso010EAstudy_branch = tree->GetBranch("lep_relIso010EAstudy");
  if (lep_relIso010EAstudy_branch) lep_relIso010EAstudy_branch->SetAddress(&lep_relIso010EAstudy_);
  lep_relIso015EAstudy_branch = tree->GetBranch("lep_relIso015EAstudy");
  if (lep_relIso015EAstudy_branch) lep_relIso015EAstudy_branch->SetAddress(&lep_relIso015EAstudy_);
  lep_relIso020EAstudy_branch = tree->GetBranch("lep_relIso020EAstudy");
  if (lep_relIso020EAstudy_branch) lep_relIso020EAstudy_branch->SetAddress(&lep_relIso020EAstudy_);
  lep_relIso025EAstudy_branch = tree->GetBranch("lep_relIso025EAstudy");
  if (lep_relIso025EAstudy_branch) lep_relIso025EAstudy_branch->SetAddress(&lep_relIso025EAstudy_);
  lep_relIso030EAstudy_branch = tree->GetBranch("lep_relIso030EAstudy");
  if (lep_relIso030EAstudy_branch) lep_relIso030EAstudy_branch->SetAddress(&lep_relIso030EAstudy_);
  lep_relIso035EAstudy_branch = tree->GetBranch("lep_relIso035EAstudy");
  if (lep_relIso035EAstudy_branch) lep_relIso035EAstudy_branch->SetAddress(&lep_relIso035EAstudy_);
  lep_relIso045EAstudy_branch = tree->GetBranch("lep_relIso045EAstudy");
  if (lep_relIso045EAstudy_branch) lep_relIso045EAstudy_branch->SetAddress(&lep_relIso045EAstudy_);
  lep_relIso050EAstudy_branch = tree->GetBranch("lep_relIso050EAstudy");
  if (lep_relIso050EAstudy_branch) lep_relIso050EAstudy_branch->SetAddress(&lep_relIso050EAstudy_);
  lep_muPOverP_branch = tree->GetBranch("lep_muPOverP");
  if (lep_muPOverP_branch) lep_muPOverP_branch->SetAddress(&lep_muPOverP_);
  lep_muPidPFMuon_branch = tree->GetBranch("lep_muPidPFMuon");
  if (lep_muPidPFMuon_branch) lep_muPidPFMuon_branch->SetAddress(&lep_muPidPFMuon_);
  lep_muType_branch = tree->GetBranch("lep_muType");
  if (lep_muType_branch) lep_muType_branch->SetAddress(&lep_muType_);
  lep_muChi2OverNDof_branch = tree->GetBranch("lep_muChi2OverNDof");
  if (lep_muChi2OverNDof_branch) lep_muChi2OverNDof_branch->SetAddress(&lep_muChi2OverNDof_);
  lep_muChi2LocalPosition_branch = tree->GetBranch("lep_muChi2LocalPosition");
  if (lep_muChi2LocalPosition_branch) lep_muChi2LocalPosition_branch->SetAddress(&lep_muChi2LocalPosition_);
  lep_muTrkKink_branch = tree->GetBranch("lep_muTrkKink");
  if (lep_muTrkKink_branch) lep_muTrkKink_branch->SetAddress(&lep_muTrkKink_);
  lep_muValidHitFraction_branch = tree->GetBranch("lep_muValidHitFraction");
  if (lep_muValidHitFraction_branch) lep_muValidHitFraction_branch->SetAddress(&lep_muValidHitFraction_);
  lep_muSegmCompatibility_branch = tree->GetBranch("lep_muSegmCompatibility");
  if (lep_muSegmCompatibility_branch) lep_muSegmCompatibility_branch->SetAddress(&lep_muSegmCompatibility_);
  lep_muGFitValidSTAHits_branch = tree->GetBranch("lep_muGFitValidSTAHits");
  if (lep_muGFitValidSTAHits_branch) lep_muGFitValidSTAHits_branch->SetAddress(&lep_muGFitValidSTAHits_);
  lep_muNMatchedStations_branch = tree->GetBranch("lep_muNMatchedStations");
  if (lep_muNMatchedStations_branch) lep_muNMatchedStations_branch->SetAddress(&lep_muNMatchedStations_);
  lep_muValidPixelHits_branch = tree->GetBranch("lep_muValidPixelHits");
  if (lep_muValidPixelHits_branch) lep_muValidPixelHits_branch->SetAddress(&lep_muValidPixelHits_);
  lep_muNLayers_branch = tree->GetBranch("lep_muNLayers");
  if (lep_muNLayers_branch) lep_muNLayers_branch->SetAddress(&lep_muNLayers_);
  lep_elEtaSC_branch = tree->GetBranch("lep_elEtaSC");
  if (lep_elEtaSC_branch) lep_elEtaSC_branch->SetAddress(&lep_elEtaSC_);
  lep_elSigmaIEtaIEta_full5x5_branch = tree->GetBranch("lep_elSigmaIEtaIEta_full5x5");
  if (lep_elSigmaIEtaIEta_full5x5_branch) lep_elSigmaIEtaIEta_full5x5_branch->SetAddress(&lep_elSigmaIEtaIEta_full5x5_);
  lep_elHOverE_branch = tree->GetBranch("lep_elHOverE");
  if (lep_elHOverE_branch) lep_elHOverE_branch->SetAddress(&lep_elHOverE_);
  lep_elMvaRaw_branch = tree->GetBranch("lep_elMvaRaw");
  if (lep_elMvaRaw_branch) lep_elMvaRaw_branch->SetAddress(&lep_elMvaRaw_);
  lep_elMva_branch = tree->GetBranch("lep_elMva");
  if (lep_elMva_branch) lep_elMva_branch->SetAddress(&lep_elMva_);
  lep_elDEtaIn_branch = tree->GetBranch("lep_elDEtaIn");
  if (lep_elDEtaIn_branch) lep_elDEtaIn_branch->SetAddress(&lep_elDEtaIn_);
  lep_elDPhiIn_branch = tree->GetBranch("lep_elDPhiIn");
  if (lep_elDPhiIn_branch) lep_elDPhiIn_branch->SetAddress(&lep_elDPhiIn_);
  lep_elEpRatio_branch = tree->GetBranch("lep_elEpRatio");
  if (lep_elEpRatio_branch) lep_elEpRatio_branch->SetAddress(&lep_elEpRatio_);
  lep_elConvVeto_branch = tree->GetBranch("lep_elConvVeto");
  if (lep_elConvVeto_branch) lep_elConvVeto_branch->SetAddress(&lep_elConvVeto_);
  lep_elNmiss_branch = tree->GetBranch("lep_elNmiss");
  if (lep_elNmiss_branch) lep_elNmiss_branch->SetAddress(&lep_elNmiss_);
  lep_isFromX_branch = tree->GetBranch("lep_isFromX");
  if (lep_isFromX_branch) lep_isFromX_branch->SetAddress(&lep_isFromX_);
  jet_n_branch = tree->GetBranch("jet_n");
  if (jet_n_branch) jet_n_branch->SetAddress(&jet_n_);
  jet_pt_branch = tree->GetBranch("jet_pt");
  if (jet_pt_branch) jet_pt_branch->SetAddress(&jet_pt_);
  jet_eta_branch = tree->GetBranch("jet_eta");
  if (jet_eta_branch) jet_eta_branch->SetAddress(&jet_eta_);
  jet_phi_branch = tree->GetBranch("jet_phi");
  if (jet_phi_branch) jet_phi_branch->SetAddress(&jet_phi_);
  jet_mass_branch = tree->GetBranch("jet_mass");
  if (jet_mass_branch) jet_mass_branch->SetAddress(&jet_mass_);
  jet_energy_branch = tree->GetBranch("jet_energy");
  if (jet_energy_branch) jet_energy_branch->SetAddress(&jet_energy_);
  jet_btagCSV_branch = tree->GetBranch("jet_btagCSV");
  if (jet_btagCSV_branch) jet_btagCSV_branch->SetAddress(&jet_btagCSV_);
  jet_rawPt_branch = tree->GetBranch("jet_rawPt");
  if (jet_rawPt_branch) jet_rawPt_branch->SetAddress(&jet_rawPt_);
  jet_mcPt_branch = tree->GetBranch("jet_mcPt");
  if (jet_mcPt_branch) jet_mcPt_branch->SetAddress(&jet_mcPt_);
  jet_mcFlavour_branch = tree->GetBranch("jet_mcFlavour");
  if (jet_mcFlavour_branch) jet_mcFlavour_branch->SetAddress(&jet_mcFlavour_);
  jet_hadronFlavour_branch = tree->GetBranch("jet_hadronFlavour");
  if (jet_hadronFlavour_branch) jet_hadronFlavour_branch->SetAddress(&jet_hadronFlavour_);
  jet_area_branch = tree->GetBranch("jet_area");
  if (jet_area_branch) jet_area_branch->SetAddress(&jet_area_);
  jet_undoJEC_branch = tree->GetBranch("jet_undoJEC");
  if (jet_undoJEC_branch) jet_undoJEC_branch->SetAddress(&jet_undoJEC_);
  jet_jecCorr_branch = tree->GetBranch("jet_jecCorr");
  if (jet_jecCorr_branch) jet_jecCorr_branch->SetAddress(&jet_jecCorr_);
  jet_jecCorrUp_branch = tree->GetBranch("jet_jecCorrUp");
  if (jet_jecCorrUp_branch) jet_jecCorrUp_branch->SetAddress(&jet_jecCorrUp_);
  jet_jecCorrDn_branch = tree->GetBranch("jet_jecCorrDn");
  if (jet_jecCorrDn_branch) jet_jecCorrDn_branch->SetAddress(&jet_jecCorrDn_);
  jet_chf_branch = tree->GetBranch("jet_chf");
  if (jet_chf_branch) jet_chf_branch->SetAddress(&jet_chf_);
  jet_nhf_branch = tree->GetBranch("jet_nhf");
  if (jet_nhf_branch) jet_nhf_branch->SetAddress(&jet_nhf_);
  jet_cef_branch = tree->GetBranch("jet_cef");
  if (jet_cef_branch) jet_cef_branch->SetAddress(&jet_cef_);
  jet_nef_branch = tree->GetBranch("jet_nef");
  if (jet_nef_branch) jet_nef_branch->SetAddress(&jet_nef_);
  jet_muf_branch = tree->GetBranch("jet_muf");
  if (jet_muf_branch) jet_muf_branch->SetAddress(&jet_muf_);
  jet_cm_branch = tree->GetBranch("jet_cm");
  if (jet_cm_branch) jet_cm_branch->SetAddress(&jet_cm_);
  jet_nm_branch = tree->GetBranch("jet_nm");
  if (jet_nm_branch) jet_nm_branch->SetAddress(&jet_nm_);
  jet_puValue_branch = tree->GetBranch("jet_puValue");
  if (jet_puValue_branch) jet_puValue_branch->SetAddress(&jet_puValue_);
  jet_mcdr_branch = tree->GetBranch("jet_mcdr");
  if (jet_mcdr_branch) jet_mcdr_branch->SetAddress(&jet_mcdr_);
  jet_npfcand_branch = tree->GetBranch("jet_npfcand");
  if (jet_npfcand_branch) jet_npfcand_branch->SetAddress(&jet_npfcand_);
  jet_id_branch = tree->GetBranch("jet_id");
  if (jet_id_branch) jet_id_branch->SetAddress(&jet_id_);
  jet_puId_branch = tree->GetBranch("jet_puId");
  if (jet_puId_branch) jet_puId_branch->SetAddress(&jet_puId_);
  jet_puIdpuppi_branch = tree->GetBranch("jet_puIdpuppi");
  if (jet_puIdpuppi_branch) jet_puIdpuppi_branch->SetAddress(&jet_puIdpuppi_);
  jet_FSveto_branch = tree->GetBranch("jet_FSveto");
  if (jet_FSveto_branch) jet_FSveto_branch->SetAddress(&jet_FSveto_);
  met_pt_branch = tree->GetBranch("met_pt");
  if (met_pt_branch) met_pt_branch->SetAddress(&met_pt_);
  met_phi_branch = tree->GetBranch("met_phi");
  if (met_phi_branch) met_phi_branch->SetAddress(&met_phi_);
  evt_run_branch = tree->GetBranch("evt_run");
  if (evt_run_branch) evt_run_branch->SetAddress(&evt_run_);
  evt_lumi_branch = tree->GetBranch("evt_lumi");
  if (evt_lumi_branch) evt_lumi_branch->SetAddress(&evt_lumi_);
  evt_event_branch = tree->GetBranch("evt_event");
  if (evt_event_branch) evt_event_branch->SetAddress(&evt_event_);
  evt_nEvts_branch = tree->GetBranch("evt_nEvts");
  if (evt_nEvts_branch) evt_nEvts_branch->SetAddress(&evt_nEvts_);
  evt_scale1fb_branch = tree->GetBranch("evt_scale1fb");
  if (evt_scale1fb_branch) evt_scale1fb_branch->SetAddress(&evt_scale1fb_);
  gen_ht_branch = tree->GetBranch("gen_ht");
  if (gen_ht_branch) gen_ht_branch->SetAddress(&gen_ht_);

  tree->SetMakeClass(0);
}

void MyBaby::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  truth_n_isLoaded = false;
  truth_pt_isLoaded = false;
  truth_eta_isLoaded = false;
  truth_phi_isLoaded = false;
  truth_mass_isLoaded = false;
  truth_energy_isLoaded = false;
  truth_pdgId_isLoaded = false;
  truth_status_isLoaded = false;
  truth_motherId_isLoaded = false;
  truth_grandmotherId_isLoaded = false;
  lep_n_isLoaded = false;
  lep_pt_isLoaded = false;
  lep_eta_isLoaded = false;
  lep_phi_isLoaded = false;
  lep_mass_isLoaded = false;
  lep_energy_isLoaded = false;
  lep_dxy_isLoaded = false;
  lep_dz_isLoaded = false;
  lep_ip3d_isLoaded = false;
  lep_sip3d_isLoaded = false;
  lep_tightcharge_isLoaded = false;
  lep_charge_isLoaded = false;
  lep_pdgId_isLoaded = false;
  lep_id_isLoaded = false;
  lep_ptRatio_isLoaded = false;
  lep_ptRel_isLoaded = false;
  lep_relIso03_isLoaded = false;
  lep_relIso03DB_isLoaded = false;
  lep_relIso03EA_isLoaded = false;
  lep_relIso03EAv2_isLoaded = false;
  lep_relIso04_isLoaded = false;
  lep_relIso04DB_isLoaded = false;
  lep_relIso04EA_isLoaded = false;
  lep_relIso04EAv2_isLoaded = false;
  lep_miniRelIsoCMS3_EA_isLoaded = false;
  lep_miniRelIsoCMS3_EAv2_isLoaded = false;
  lep_miniRelIsoCMS3_DB_isLoaded = false;
  lep_relIso005EAstudy_isLoaded = false;
  lep_relIso010EAstudy_isLoaded = false;
  lep_relIso015EAstudy_isLoaded = false;
  lep_relIso020EAstudy_isLoaded = false;
  lep_relIso025EAstudy_isLoaded = false;
  lep_relIso030EAstudy_isLoaded = false;
  lep_relIso035EAstudy_isLoaded = false;
  lep_relIso045EAstudy_isLoaded = false;
  lep_relIso050EAstudy_isLoaded = false;
  lep_muPOverP_isLoaded = false;
  lep_muPidPFMuon_isLoaded = false;
  lep_muType_isLoaded = false;
  lep_muChi2OverNDof_isLoaded = false;
  lep_muChi2LocalPosition_isLoaded = false;
  lep_muTrkKink_isLoaded = false;
  lep_muValidHitFraction_isLoaded = false;
  lep_muSegmCompatibility_isLoaded = false;
  lep_muGFitValidSTAHits_isLoaded = false;
  lep_muNMatchedStations_isLoaded = false;
  lep_muValidPixelHits_isLoaded = false;
  lep_muNLayers_isLoaded = false;
  lep_elEtaSC_isLoaded = false;
  lep_elSigmaIEtaIEta_full5x5_isLoaded = false;
  lep_elHOverE_isLoaded = false;
  lep_elMvaRaw_isLoaded = false;
  lep_elMva_isLoaded = false;
  lep_elDEtaIn_isLoaded = false;
  lep_elDPhiIn_isLoaded = false;
  lep_elEpRatio_isLoaded = false;
  lep_elConvVeto_isLoaded = false;
  lep_elNmiss_isLoaded = false;
  lep_isFromX_isLoaded = false;
  jet_n_isLoaded = false;
  jet_pt_isLoaded = false;
  jet_eta_isLoaded = false;
  jet_phi_isLoaded = false;
  jet_mass_isLoaded = false;
  jet_energy_isLoaded = false;
  jet_btagCSV_isLoaded = false;
  jet_rawPt_isLoaded = false;
  jet_mcPt_isLoaded = false;
  jet_mcFlavour_isLoaded = false;
  jet_hadronFlavour_isLoaded = false;
  jet_area_isLoaded = false;
  jet_undoJEC_isLoaded = false;
  jet_jecCorr_isLoaded = false;
  jet_jecCorrUp_isLoaded = false;
  jet_jecCorrDn_isLoaded = false;
  jet_chf_isLoaded = false;
  jet_nhf_isLoaded = false;
  jet_cef_isLoaded = false;
  jet_nef_isLoaded = false;
  jet_muf_isLoaded = false;
  jet_cm_isLoaded = false;
  jet_nm_isLoaded = false;
  jet_puValue_isLoaded = false;
  jet_mcdr_isLoaded = false;
  jet_npfcand_isLoaded = false;
  jet_id_isLoaded = false;
  jet_puId_isLoaded = false;
  jet_puIdpuppi_isLoaded = false;
  jet_FSveto_isLoaded = false;
  met_pt_isLoaded = false;
  met_phi_isLoaded = false;
  evt_run_isLoaded = false;
  evt_lumi_isLoaded = false;
  evt_event_isLoaded = false;
  evt_nEvts_isLoaded = false;
  evt_scale1fb_isLoaded = false;
  gen_ht_isLoaded = false;
}

void MyBaby::LoadAllBranches() {
  // load all branches
  if (truth_n_branch != 0) truth_n();
  if (truth_pt_branch != 0) truth_pt();
  if (truth_eta_branch != 0) truth_eta();
  if (truth_phi_branch != 0) truth_phi();
  if (truth_mass_branch != 0) truth_mass();
  if (truth_energy_branch != 0) truth_energy();
  if (truth_pdgId_branch != 0) truth_pdgId();
  if (truth_status_branch != 0) truth_status();
  if (truth_motherId_branch != 0) truth_motherId();
  if (truth_grandmotherId_branch != 0) truth_grandmotherId();
  if (lep_n_branch != 0) lep_n();
  if (lep_pt_branch != 0) lep_pt();
  if (lep_eta_branch != 0) lep_eta();
  if (lep_phi_branch != 0) lep_phi();
  if (lep_mass_branch != 0) lep_mass();
  if (lep_energy_branch != 0) lep_energy();
  if (lep_dxy_branch != 0) lep_dxy();
  if (lep_dz_branch != 0) lep_dz();
  if (lep_ip3d_branch != 0) lep_ip3d();
  if (lep_sip3d_branch != 0) lep_sip3d();
  if (lep_tightcharge_branch != 0) lep_tightcharge();
  if (lep_charge_branch != 0) lep_charge();
  if (lep_pdgId_branch != 0) lep_pdgId();
  if (lep_id_branch != 0) lep_id();
  if (lep_ptRatio_branch != 0) lep_ptRatio();
  if (lep_ptRel_branch != 0) lep_ptRel();
  if (lep_relIso03_branch != 0) lep_relIso03();
  if (lep_relIso03DB_branch != 0) lep_relIso03DB();
  if (lep_relIso03EA_branch != 0) lep_relIso03EA();
  if (lep_relIso03EAv2_branch != 0) lep_relIso03EAv2();
  if (lep_relIso04_branch != 0) lep_relIso04();
  if (lep_relIso04DB_branch != 0) lep_relIso04DB();
  if (lep_relIso04EA_branch != 0) lep_relIso04EA();
  if (lep_relIso04EAv2_branch != 0) lep_relIso04EAv2();
  if (lep_miniRelIsoCMS3_EA_branch != 0) lep_miniRelIsoCMS3_EA();
  if (lep_miniRelIsoCMS3_EAv2_branch != 0) lep_miniRelIsoCMS3_EAv2();
  if (lep_miniRelIsoCMS3_DB_branch != 0) lep_miniRelIsoCMS3_DB();
  if (lep_relIso005EAstudy_branch != 0) lep_relIso005EAstudy();
  if (lep_relIso010EAstudy_branch != 0) lep_relIso010EAstudy();
  if (lep_relIso015EAstudy_branch != 0) lep_relIso015EAstudy();
  if (lep_relIso020EAstudy_branch != 0) lep_relIso020EAstudy();
  if (lep_relIso025EAstudy_branch != 0) lep_relIso025EAstudy();
  if (lep_relIso030EAstudy_branch != 0) lep_relIso030EAstudy();
  if (lep_relIso035EAstudy_branch != 0) lep_relIso035EAstudy();
  if (lep_relIso045EAstudy_branch != 0) lep_relIso045EAstudy();
  if (lep_relIso050EAstudy_branch != 0) lep_relIso050EAstudy();
  if (lep_muPOverP_branch != 0) lep_muPOverP();
  if (lep_muPidPFMuon_branch != 0) lep_muPidPFMuon();
  if (lep_muType_branch != 0) lep_muType();
  if (lep_muChi2OverNDof_branch != 0) lep_muChi2OverNDof();
  if (lep_muChi2LocalPosition_branch != 0) lep_muChi2LocalPosition();
  if (lep_muTrkKink_branch != 0) lep_muTrkKink();
  if (lep_muValidHitFraction_branch != 0) lep_muValidHitFraction();
  if (lep_muSegmCompatibility_branch != 0) lep_muSegmCompatibility();
  if (lep_muGFitValidSTAHits_branch != 0) lep_muGFitValidSTAHits();
  if (lep_muNMatchedStations_branch != 0) lep_muNMatchedStations();
  if (lep_muValidPixelHits_branch != 0) lep_muValidPixelHits();
  if (lep_muNLayers_branch != 0) lep_muNLayers();
  if (lep_elEtaSC_branch != 0) lep_elEtaSC();
  if (lep_elSigmaIEtaIEta_full5x5_branch != 0) lep_elSigmaIEtaIEta_full5x5();
  if (lep_elHOverE_branch != 0) lep_elHOverE();
  if (lep_elMvaRaw_branch != 0) lep_elMvaRaw();
  if (lep_elMva_branch != 0) lep_elMva();
  if (lep_elDEtaIn_branch != 0) lep_elDEtaIn();
  if (lep_elDPhiIn_branch != 0) lep_elDPhiIn();
  if (lep_elEpRatio_branch != 0) lep_elEpRatio();
  if (lep_elConvVeto_branch != 0) lep_elConvVeto();
  if (lep_elNmiss_branch != 0) lep_elNmiss();
  if (lep_isFromX_branch != 0) lep_isFromX();
  if (jet_n_branch != 0) jet_n();
  if (jet_pt_branch != 0) jet_pt();
  if (jet_eta_branch != 0) jet_eta();
  if (jet_phi_branch != 0) jet_phi();
  if (jet_mass_branch != 0) jet_mass();
  if (jet_energy_branch != 0) jet_energy();
  if (jet_btagCSV_branch != 0) jet_btagCSV();
  if (jet_rawPt_branch != 0) jet_rawPt();
  if (jet_mcPt_branch != 0) jet_mcPt();
  if (jet_mcFlavour_branch != 0) jet_mcFlavour();
  if (jet_hadronFlavour_branch != 0) jet_hadronFlavour();
  if (jet_area_branch != 0) jet_area();
  if (jet_undoJEC_branch != 0) jet_undoJEC();
  if (jet_jecCorr_branch != 0) jet_jecCorr();
  if (jet_jecCorrUp_branch != 0) jet_jecCorrUp();
  if (jet_jecCorrDn_branch != 0) jet_jecCorrDn();
  if (jet_chf_branch != 0) jet_chf();
  if (jet_nhf_branch != 0) jet_nhf();
  if (jet_cef_branch != 0) jet_cef();
  if (jet_nef_branch != 0) jet_nef();
  if (jet_muf_branch != 0) jet_muf();
  if (jet_cm_branch != 0) jet_cm();
  if (jet_nm_branch != 0) jet_nm();
  if (jet_puValue_branch != 0) jet_puValue();
  if (jet_mcdr_branch != 0) jet_mcdr();
  if (jet_npfcand_branch != 0) jet_npfcand();
  if (jet_id_branch != 0) jet_id();
  if (jet_puId_branch != 0) jet_puId();
  if (jet_puIdpuppi_branch != 0) jet_puIdpuppi();
  if (jet_FSveto_branch != 0) jet_FSveto();
  if (met_pt_branch != 0) met_pt();
  if (met_phi_branch != 0) met_phi();
  if (evt_run_branch != 0) evt_run();
  if (evt_lumi_branch != 0) evt_lumi();
  if (evt_event_branch != 0) evt_event();
  if (evt_nEvts_branch != 0) evt_nEvts();
  if (evt_scale1fb_branch != 0) evt_scale1fb();
  if (gen_ht_branch != 0) gen_ht();
}

const int &MyBaby::truth_n() {
  if (not truth_n_isLoaded) {
    if (truth_n_branch != 0) {
      truth_n_branch->GetEntry(index);
    } else {
      printf("branch truth_n_branch does not exist!\n");
      exit(1);
    }
    truth_n_isLoaded = true;
  }
  return truth_n_;
}

const vector<float> &MyBaby::truth_pt() {
  if (not truth_pt_isLoaded) {
    if (truth_pt_branch != 0) {
      truth_pt_branch->GetEntry(index);
    } else {
      printf("branch truth_pt_branch does not exist!\n");
      exit(1);
    }
    truth_pt_isLoaded = true;
  }
  return *truth_pt_;
}

const vector<float> &MyBaby::truth_eta() {
  if (not truth_eta_isLoaded) {
    if (truth_eta_branch != 0) {
      truth_eta_branch->GetEntry(index);
    } else {
      printf("branch truth_eta_branch does not exist!\n");
      exit(1);
    }
    truth_eta_isLoaded = true;
  }
  return *truth_eta_;
}

const vector<float> &MyBaby::truth_phi() {
  if (not truth_phi_isLoaded) {
    if (truth_phi_branch != 0) {
      truth_phi_branch->GetEntry(index);
    } else {
      printf("branch truth_phi_branch does not exist!\n");
      exit(1);
    }
    truth_phi_isLoaded = true;
  }
  return *truth_phi_;
}

const vector<float> &MyBaby::truth_mass() {
  if (not truth_mass_isLoaded) {
    if (truth_mass_branch != 0) {
      truth_mass_branch->GetEntry(index);
    } else {
      printf("branch truth_mass_branch does not exist!\n");
      exit(1);
    }
    truth_mass_isLoaded = true;
  }
  return *truth_mass_;
}

const vector<float> &MyBaby::truth_energy() {
  if (not truth_energy_isLoaded) {
    if (truth_energy_branch != 0) {
      truth_energy_branch->GetEntry(index);
    } else {
      printf("branch truth_energy_branch does not exist!\n");
      exit(1);
    }
    truth_energy_isLoaded = true;
  }
  return *truth_energy_;
}

const vector<int> &MyBaby::truth_pdgId() {
  if (not truth_pdgId_isLoaded) {
    if (truth_pdgId_branch != 0) {
      truth_pdgId_branch->GetEntry(index);
    } else {
      printf("branch truth_pdgId_branch does not exist!\n");
      exit(1);
    }
    truth_pdgId_isLoaded = true;
  }
  return *truth_pdgId_;
}

const vector<int> &MyBaby::truth_status() {
  if (not truth_status_isLoaded) {
    if (truth_status_branch != 0) {
      truth_status_branch->GetEntry(index);
    } else {
      printf("branch truth_status_branch does not exist!\n");
      exit(1);
    }
    truth_status_isLoaded = true;
  }
  return *truth_status_;
}

const vector<int> &MyBaby::truth_motherId() {
  if (not truth_motherId_isLoaded) {
    if (truth_motherId_branch != 0) {
      truth_motherId_branch->GetEntry(index);
    } else {
      printf("branch truth_motherId_branch does not exist!\n");
      exit(1);
    }
    truth_motherId_isLoaded = true;
  }
  return *truth_motherId_;
}

const vector<int> &MyBaby::truth_grandmotherId() {
  if (not truth_grandmotherId_isLoaded) {
    if (truth_grandmotherId_branch != 0) {
      truth_grandmotherId_branch->GetEntry(index);
    } else {
      printf("branch truth_grandmotherId_branch does not exist!\n");
      exit(1);
    }
    truth_grandmotherId_isLoaded = true;
  }
  return *truth_grandmotherId_;
}

const int &MyBaby::lep_n() {
  if (not lep_n_isLoaded) {
    if (lep_n_branch != 0) {
      lep_n_branch->GetEntry(index);
    } else {
      printf("branch lep_n_branch does not exist!\n");
      exit(1);
    }
    lep_n_isLoaded = true;
  }
  return lep_n_;
}

const vector<float> &MyBaby::lep_pt() {
  if (not lep_pt_isLoaded) {
    if (lep_pt_branch != 0) {
      lep_pt_branch->GetEntry(index);
    } else {
      printf("branch lep_pt_branch does not exist!\n");
      exit(1);
    }
    lep_pt_isLoaded = true;
  }
  return *lep_pt_;
}

const vector<float> &MyBaby::lep_eta() {
  if (not lep_eta_isLoaded) {
    if (lep_eta_branch != 0) {
      lep_eta_branch->GetEntry(index);
    } else {
      printf("branch lep_eta_branch does not exist!\n");
      exit(1);
    }
    lep_eta_isLoaded = true;
  }
  return *lep_eta_;
}

const vector<float> &MyBaby::lep_phi() {
  if (not lep_phi_isLoaded) {
    if (lep_phi_branch != 0) {
      lep_phi_branch->GetEntry(index);
    } else {
      printf("branch lep_phi_branch does not exist!\n");
      exit(1);
    }
    lep_phi_isLoaded = true;
  }
  return *lep_phi_;
}

const vector<float> &MyBaby::lep_mass() {
  if (not lep_mass_isLoaded) {
    if (lep_mass_branch != 0) {
      lep_mass_branch->GetEntry(index);
    } else {
      printf("branch lep_mass_branch does not exist!\n");
      exit(1);
    }
    lep_mass_isLoaded = true;
  }
  return *lep_mass_;
}

const vector<float> &MyBaby::lep_energy() {
  if (not lep_energy_isLoaded) {
    if (lep_energy_branch != 0) {
      lep_energy_branch->GetEntry(index);
    } else {
      printf("branch lep_energy_branch does not exist!\n");
      exit(1);
    }
    lep_energy_isLoaded = true;
  }
  return *lep_energy_;
}

const vector<float> &MyBaby::lep_dxy() {
  if (not lep_dxy_isLoaded) {
    if (lep_dxy_branch != 0) {
      lep_dxy_branch->GetEntry(index);
    } else {
      printf("branch lep_dxy_branch does not exist!\n");
      exit(1);
    }
    lep_dxy_isLoaded = true;
  }
  return *lep_dxy_;
}

const vector<float> &MyBaby::lep_dz() {
  if (not lep_dz_isLoaded) {
    if (lep_dz_branch != 0) {
      lep_dz_branch->GetEntry(index);
    } else {
      printf("branch lep_dz_branch does not exist!\n");
      exit(1);
    }
    lep_dz_isLoaded = true;
  }
  return *lep_dz_;
}

const vector<float> &MyBaby::lep_ip3d() {
  if (not lep_ip3d_isLoaded) {
    if (lep_ip3d_branch != 0) {
      lep_ip3d_branch->GetEntry(index);
    } else {
      printf("branch lep_ip3d_branch does not exist!\n");
      exit(1);
    }
    lep_ip3d_isLoaded = true;
  }
  return *lep_ip3d_;
}

const vector<float> &MyBaby::lep_sip3d() {
  if (not lep_sip3d_isLoaded) {
    if (lep_sip3d_branch != 0) {
      lep_sip3d_branch->GetEntry(index);
    } else {
      printf("branch lep_sip3d_branch does not exist!\n");
      exit(1);
    }
    lep_sip3d_isLoaded = true;
  }
  return *lep_sip3d_;
}

const vector<int> &MyBaby::lep_tightcharge() {
  if (not lep_tightcharge_isLoaded) {
    if (lep_tightcharge_branch != 0) {
      lep_tightcharge_branch->GetEntry(index);
    } else {
      printf("branch lep_tightcharge_branch does not exist!\n");
      exit(1);
    }
    lep_tightcharge_isLoaded = true;
  }
  return *lep_tightcharge_;
}

const vector<int> &MyBaby::lep_charge() {
  if (not lep_charge_isLoaded) {
    if (lep_charge_branch != 0) {
      lep_charge_branch->GetEntry(index);
    } else {
      printf("branch lep_charge_branch does not exist!\n");
      exit(1);
    }
    lep_charge_isLoaded = true;
  }
  return *lep_charge_;
}

const vector<int> &MyBaby::lep_pdgId() {
  if (not lep_pdgId_isLoaded) {
    if (lep_pdgId_branch != 0) {
      lep_pdgId_branch->GetEntry(index);
    } else {
      printf("branch lep_pdgId_branch does not exist!\n");
      exit(1);
    }
    lep_pdgId_isLoaded = true;
  }
  return *lep_pdgId_;
}

const vector<int> &MyBaby::lep_id() {
  if (not lep_id_isLoaded) {
    if (lep_id_branch != 0) {
      lep_id_branch->GetEntry(index);
    } else {
      printf("branch lep_id_branch does not exist!\n");
      exit(1);
    }
    lep_id_isLoaded = true;
  }
  return *lep_id_;
}

const vector<float> &MyBaby::lep_ptRatio() {
  if (not lep_ptRatio_isLoaded) {
    if (lep_ptRatio_branch != 0) {
      lep_ptRatio_branch->GetEntry(index);
    } else {
      printf("branch lep_ptRatio_branch does not exist!\n");
      exit(1);
    }
    lep_ptRatio_isLoaded = true;
  }
  return *lep_ptRatio_;
}

const vector<float> &MyBaby::lep_ptRel() {
  if (not lep_ptRel_isLoaded) {
    if (lep_ptRel_branch != 0) {
      lep_ptRel_branch->GetEntry(index);
    } else {
      printf("branch lep_ptRel_branch does not exist!\n");
      exit(1);
    }
    lep_ptRel_isLoaded = true;
  }
  return *lep_ptRel_;
}

const vector<float> &MyBaby::lep_relIso03() {
  if (not lep_relIso03_isLoaded) {
    if (lep_relIso03_branch != 0) {
      lep_relIso03_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso03_branch does not exist!\n");
      exit(1);
    }
    lep_relIso03_isLoaded = true;
  }
  return *lep_relIso03_;
}

const vector<float> &MyBaby::lep_relIso03DB() {
  if (not lep_relIso03DB_isLoaded) {
    if (lep_relIso03DB_branch != 0) {
      lep_relIso03DB_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso03DB_branch does not exist!\n");
      exit(1);
    }
    lep_relIso03DB_isLoaded = true;
  }
  return *lep_relIso03DB_;
}

const vector<float> &MyBaby::lep_relIso03EA() {
  if (not lep_relIso03EA_isLoaded) {
    if (lep_relIso03EA_branch != 0) {
      lep_relIso03EA_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso03EA_branch does not exist!\n");
      exit(1);
    }
    lep_relIso03EA_isLoaded = true;
  }
  return *lep_relIso03EA_;
}

const vector<float> &MyBaby::lep_relIso03EAv2() {
  if (not lep_relIso03EAv2_isLoaded) {
    if (lep_relIso03EAv2_branch != 0) {
      lep_relIso03EAv2_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso03EAv2_branch does not exist!\n");
      exit(1);
    }
    lep_relIso03EAv2_isLoaded = true;
  }
  return *lep_relIso03EAv2_;
}

const vector<float> &MyBaby::lep_relIso04() {
  if (not lep_relIso04_isLoaded) {
    if (lep_relIso04_branch != 0) {
      lep_relIso04_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso04_branch does not exist!\n");
      exit(1);
    }
    lep_relIso04_isLoaded = true;
  }
  return *lep_relIso04_;
}

const vector<float> &MyBaby::lep_relIso04DB() {
  if (not lep_relIso04DB_isLoaded) {
    if (lep_relIso04DB_branch != 0) {
      lep_relIso04DB_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso04DB_branch does not exist!\n");
      exit(1);
    }
    lep_relIso04DB_isLoaded = true;
  }
  return *lep_relIso04DB_;
}

const vector<float> &MyBaby::lep_relIso04EA() {
  if (not lep_relIso04EA_isLoaded) {
    if (lep_relIso04EA_branch != 0) {
      lep_relIso04EA_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso04EA_branch does not exist!\n");
      exit(1);
    }
    lep_relIso04EA_isLoaded = true;
  }
  return *lep_relIso04EA_;
}

const vector<float> &MyBaby::lep_relIso04EAv2() {
  if (not lep_relIso04EAv2_isLoaded) {
    if (lep_relIso04EAv2_branch != 0) {
      lep_relIso04EAv2_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso04EAv2_branch does not exist!\n");
      exit(1);
    }
    lep_relIso04EAv2_isLoaded = true;
  }
  return *lep_relIso04EAv2_;
}

const vector<float> &MyBaby::lep_miniRelIsoCMS3_EA() {
  if (not lep_miniRelIsoCMS3_EA_isLoaded) {
    if (lep_miniRelIsoCMS3_EA_branch != 0) {
      lep_miniRelIsoCMS3_EA_branch->GetEntry(index);
    } else {
      printf("branch lep_miniRelIsoCMS3_EA_branch does not exist!\n");
      exit(1);
    }
    lep_miniRelIsoCMS3_EA_isLoaded = true;
  }
  return *lep_miniRelIsoCMS3_EA_;
}

const vector<float> &MyBaby::lep_miniRelIsoCMS3_EAv2() {
  if (not lep_miniRelIsoCMS3_EAv2_isLoaded) {
    if (lep_miniRelIsoCMS3_EAv2_branch != 0) {
      lep_miniRelIsoCMS3_EAv2_branch->GetEntry(index);
    } else {
      printf("branch lep_miniRelIsoCMS3_EAv2_branch does not exist!\n");
      exit(1);
    }
    lep_miniRelIsoCMS3_EAv2_isLoaded = true;
  }
  return *lep_miniRelIsoCMS3_EAv2_;
}

const vector<float> &MyBaby::lep_miniRelIsoCMS3_DB() {
  if (not lep_miniRelIsoCMS3_DB_isLoaded) {
    if (lep_miniRelIsoCMS3_DB_branch != 0) {
      lep_miniRelIsoCMS3_DB_branch->GetEntry(index);
    } else {
      printf("branch lep_miniRelIsoCMS3_DB_branch does not exist!\n");
      exit(1);
    }
    lep_miniRelIsoCMS3_DB_isLoaded = true;
  }
  return *lep_miniRelIsoCMS3_DB_;
}

const vector<float> &MyBaby::lep_relIso005EAstudy() {
  if (not lep_relIso005EAstudy_isLoaded) {
    if (lep_relIso005EAstudy_branch != 0) {
      lep_relIso005EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso005EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso005EAstudy_isLoaded = true;
  }
  return *lep_relIso005EAstudy_;
}

const vector<float> &MyBaby::lep_relIso010EAstudy() {
  if (not lep_relIso010EAstudy_isLoaded) {
    if (lep_relIso010EAstudy_branch != 0) {
      lep_relIso010EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso010EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso010EAstudy_isLoaded = true;
  }
  return *lep_relIso010EAstudy_;
}

const vector<float> &MyBaby::lep_relIso015EAstudy() {
  if (not lep_relIso015EAstudy_isLoaded) {
    if (lep_relIso015EAstudy_branch != 0) {
      lep_relIso015EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso015EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso015EAstudy_isLoaded = true;
  }
  return *lep_relIso015EAstudy_;
}

const vector<float> &MyBaby::lep_relIso020EAstudy() {
  if (not lep_relIso020EAstudy_isLoaded) {
    if (lep_relIso020EAstudy_branch != 0) {
      lep_relIso020EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso020EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso020EAstudy_isLoaded = true;
  }
  return *lep_relIso020EAstudy_;
}

const vector<float> &MyBaby::lep_relIso025EAstudy() {
  if (not lep_relIso025EAstudy_isLoaded) {
    if (lep_relIso025EAstudy_branch != 0) {
      lep_relIso025EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso025EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso025EAstudy_isLoaded = true;
  }
  return *lep_relIso025EAstudy_;
}

const vector<float> &MyBaby::lep_relIso030EAstudy() {
  if (not lep_relIso030EAstudy_isLoaded) {
    if (lep_relIso030EAstudy_branch != 0) {
      lep_relIso030EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso030EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso030EAstudy_isLoaded = true;
  }
  return *lep_relIso030EAstudy_;
}

const vector<float> &MyBaby::lep_relIso035EAstudy() {
  if (not lep_relIso035EAstudy_isLoaded) {
    if (lep_relIso035EAstudy_branch != 0) {
      lep_relIso035EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso035EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso035EAstudy_isLoaded = true;
  }
  return *lep_relIso035EAstudy_;
}

const vector<float> &MyBaby::lep_relIso045EAstudy() {
  if (not lep_relIso045EAstudy_isLoaded) {
    if (lep_relIso045EAstudy_branch != 0) {
      lep_relIso045EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso045EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso045EAstudy_isLoaded = true;
  }
  return *lep_relIso045EAstudy_;
}

const vector<float> &MyBaby::lep_relIso050EAstudy() {
  if (not lep_relIso050EAstudy_isLoaded) {
    if (lep_relIso050EAstudy_branch != 0) {
      lep_relIso050EAstudy_branch->GetEntry(index);
    } else {
      printf("branch lep_relIso050EAstudy_branch does not exist!\n");
      exit(1);
    }
    lep_relIso050EAstudy_isLoaded = true;
  }
  return *lep_relIso050EAstudy_;
}

const vector<float> &MyBaby::lep_muPOverP() {
  if (not lep_muPOverP_isLoaded) {
    if (lep_muPOverP_branch != 0) {
      lep_muPOverP_branch->GetEntry(index);
    } else {
      printf("branch lep_muPOverP_branch does not exist!\n");
      exit(1);
    }
    lep_muPOverP_isLoaded = true;
  }
  return *lep_muPOverP_;
}

const vector<int> &MyBaby::lep_muPidPFMuon() {
  if (not lep_muPidPFMuon_isLoaded) {
    if (lep_muPidPFMuon_branch != 0) {
      lep_muPidPFMuon_branch->GetEntry(index);
    } else {
      printf("branch lep_muPidPFMuon_branch does not exist!\n");
      exit(1);
    }
    lep_muPidPFMuon_isLoaded = true;
  }
  return *lep_muPidPFMuon_;
}

const vector<int> &MyBaby::lep_muType() {
  if (not lep_muType_isLoaded) {
    if (lep_muType_branch != 0) {
      lep_muType_branch->GetEntry(index);
    } else {
      printf("branch lep_muType_branch does not exist!\n");
      exit(1);
    }
    lep_muType_isLoaded = true;
  }
  return *lep_muType_;
}

const vector<float> &MyBaby::lep_muChi2OverNDof() {
  if (not lep_muChi2OverNDof_isLoaded) {
    if (lep_muChi2OverNDof_branch != 0) {
      lep_muChi2OverNDof_branch->GetEntry(index);
    } else {
      printf("branch lep_muChi2OverNDof_branch does not exist!\n");
      exit(1);
    }
    lep_muChi2OverNDof_isLoaded = true;
  }
  return *lep_muChi2OverNDof_;
}

const vector<float> &MyBaby::lep_muChi2LocalPosition() {
  if (not lep_muChi2LocalPosition_isLoaded) {
    if (lep_muChi2LocalPosition_branch != 0) {
      lep_muChi2LocalPosition_branch->GetEntry(index);
    } else {
      printf("branch lep_muChi2LocalPosition_branch does not exist!\n");
      exit(1);
    }
    lep_muChi2LocalPosition_isLoaded = true;
  }
  return *lep_muChi2LocalPosition_;
}

const vector<float> &MyBaby::lep_muTrkKink() {
  if (not lep_muTrkKink_isLoaded) {
    if (lep_muTrkKink_branch != 0) {
      lep_muTrkKink_branch->GetEntry(index);
    } else {
      printf("branch lep_muTrkKink_branch does not exist!\n");
      exit(1);
    }
    lep_muTrkKink_isLoaded = true;
  }
  return *lep_muTrkKink_;
}

const vector<float> &MyBaby::lep_muValidHitFraction() {
  if (not lep_muValidHitFraction_isLoaded) {
    if (lep_muValidHitFraction_branch != 0) {
      lep_muValidHitFraction_branch->GetEntry(index);
    } else {
      printf("branch lep_muValidHitFraction_branch does not exist!\n");
      exit(1);
    }
    lep_muValidHitFraction_isLoaded = true;
  }
  return *lep_muValidHitFraction_;
}

const vector<float> &MyBaby::lep_muSegmCompatibility() {
  if (not lep_muSegmCompatibility_isLoaded) {
    if (lep_muSegmCompatibility_branch != 0) {
      lep_muSegmCompatibility_branch->GetEntry(index);
    } else {
      printf("branch lep_muSegmCompatibility_branch does not exist!\n");
      exit(1);
    }
    lep_muSegmCompatibility_isLoaded = true;
  }
  return *lep_muSegmCompatibility_;
}

const vector<int> &MyBaby::lep_muGFitValidSTAHits() {
  if (not lep_muGFitValidSTAHits_isLoaded) {
    if (lep_muGFitValidSTAHits_branch != 0) {
      lep_muGFitValidSTAHits_branch->GetEntry(index);
    } else {
      printf("branch lep_muGFitValidSTAHits_branch does not exist!\n");
      exit(1);
    }
    lep_muGFitValidSTAHits_isLoaded = true;
  }
  return *lep_muGFitValidSTAHits_;
}

const vector<int> &MyBaby::lep_muNMatchedStations() {
  if (not lep_muNMatchedStations_isLoaded) {
    if (lep_muNMatchedStations_branch != 0) {
      lep_muNMatchedStations_branch->GetEntry(index);
    } else {
      printf("branch lep_muNMatchedStations_branch does not exist!\n");
      exit(1);
    }
    lep_muNMatchedStations_isLoaded = true;
  }
  return *lep_muNMatchedStations_;
}

const vector<int> &MyBaby::lep_muValidPixelHits() {
  if (not lep_muValidPixelHits_isLoaded) {
    if (lep_muValidPixelHits_branch != 0) {
      lep_muValidPixelHits_branch->GetEntry(index);
    } else {
      printf("branch lep_muValidPixelHits_branch does not exist!\n");
      exit(1);
    }
    lep_muValidPixelHits_isLoaded = true;
  }
  return *lep_muValidPixelHits_;
}

const vector<int> &MyBaby::lep_muNLayers() {
  if (not lep_muNLayers_isLoaded) {
    if (lep_muNLayers_branch != 0) {
      lep_muNLayers_branch->GetEntry(index);
    } else {
      printf("branch lep_muNLayers_branch does not exist!\n");
      exit(1);
    }
    lep_muNLayers_isLoaded = true;
  }
  return *lep_muNLayers_;
}

const vector<float> &MyBaby::lep_elEtaSC() {
  if (not lep_elEtaSC_isLoaded) {
    if (lep_elEtaSC_branch != 0) {
      lep_elEtaSC_branch->GetEntry(index);
    } else {
      printf("branch lep_elEtaSC_branch does not exist!\n");
      exit(1);
    }
    lep_elEtaSC_isLoaded = true;
  }
  return *lep_elEtaSC_;
}

const vector<float> &MyBaby::lep_elSigmaIEtaIEta_full5x5() {
  if (not lep_elSigmaIEtaIEta_full5x5_isLoaded) {
    if (lep_elSigmaIEtaIEta_full5x5_branch != 0) {
      lep_elSigmaIEtaIEta_full5x5_branch->GetEntry(index);
    } else {
      printf("branch lep_elSigmaIEtaIEta_full5x5_branch does not exist!\n");
      exit(1);
    }
    lep_elSigmaIEtaIEta_full5x5_isLoaded = true;
  }
  return *lep_elSigmaIEtaIEta_full5x5_;
}

const vector<float> &MyBaby::lep_elHOverE() {
  if (not lep_elHOverE_isLoaded) {
    if (lep_elHOverE_branch != 0) {
      lep_elHOverE_branch->GetEntry(index);
    } else {
      printf("branch lep_elHOverE_branch does not exist!\n");
      exit(1);
    }
    lep_elHOverE_isLoaded = true;
  }
  return *lep_elHOverE_;
}

const vector<float> &MyBaby::lep_elMvaRaw() {
  if (not lep_elMvaRaw_isLoaded) {
    if (lep_elMvaRaw_branch != 0) {
      lep_elMvaRaw_branch->GetEntry(index);
    } else {
      printf("branch lep_elMvaRaw_branch does not exist!\n");
      exit(1);
    }
    lep_elMvaRaw_isLoaded = true;
  }
  return *lep_elMvaRaw_;
}

const vector<float> &MyBaby::lep_elMva() {
  if (not lep_elMva_isLoaded) {
    if (lep_elMva_branch != 0) {
      lep_elMva_branch->GetEntry(index);
    } else {
      printf("branch lep_elMva_branch does not exist!\n");
      exit(1);
    }
    lep_elMva_isLoaded = true;
  }
  return *lep_elMva_;
}

const vector<float> &MyBaby::lep_elDEtaIn() {
  if (not lep_elDEtaIn_isLoaded) {
    if (lep_elDEtaIn_branch != 0) {
      lep_elDEtaIn_branch->GetEntry(index);
    } else {
      printf("branch lep_elDEtaIn_branch does not exist!\n");
      exit(1);
    }
    lep_elDEtaIn_isLoaded = true;
  }
  return *lep_elDEtaIn_;
}

const vector<float> &MyBaby::lep_elDPhiIn() {
  if (not lep_elDPhiIn_isLoaded) {
    if (lep_elDPhiIn_branch != 0) {
      lep_elDPhiIn_branch->GetEntry(index);
    } else {
      printf("branch lep_elDPhiIn_branch does not exist!\n");
      exit(1);
    }
    lep_elDPhiIn_isLoaded = true;
  }
  return *lep_elDPhiIn_;
}

const vector<float> &MyBaby::lep_elEpRatio() {
  if (not lep_elEpRatio_isLoaded) {
    if (lep_elEpRatio_branch != 0) {
      lep_elEpRatio_branch->GetEntry(index);
    } else {
      printf("branch lep_elEpRatio_branch does not exist!\n");
      exit(1);
    }
    lep_elEpRatio_isLoaded = true;
  }
  return *lep_elEpRatio_;
}

const vector<int> &MyBaby::lep_elConvVeto() {
  if (not lep_elConvVeto_isLoaded) {
    if (lep_elConvVeto_branch != 0) {
      lep_elConvVeto_branch->GetEntry(index);
    } else {
      printf("branch lep_elConvVeto_branch does not exist!\n");
      exit(1);
    }
    lep_elConvVeto_isLoaded = true;
  }
  return *lep_elConvVeto_;
}

const vector<int> &MyBaby::lep_elNmiss() {
  if (not lep_elNmiss_isLoaded) {
    if (lep_elNmiss_branch != 0) {
      lep_elNmiss_branch->GetEntry(index);
    } else {
      printf("branch lep_elNmiss_branch does not exist!\n");
      exit(1);
    }
    lep_elNmiss_isLoaded = true;
  }
  return *lep_elNmiss_;
}

const vector<int> &MyBaby::lep_isFromX() {
  if (not lep_isFromX_isLoaded) {
    if (lep_isFromX_branch != 0) {
      lep_isFromX_branch->GetEntry(index);
    } else {
      printf("branch lep_isFromX_branch does not exist!\n");
      exit(1);
    }
    lep_isFromX_isLoaded = true;
  }
  return *lep_isFromX_;
}

const int &MyBaby::jet_n() {
  if (not jet_n_isLoaded) {
    if (jet_n_branch != 0) {
      jet_n_branch->GetEntry(index);
    } else {
      printf("branch jet_n_branch does not exist!\n");
      exit(1);
    }
    jet_n_isLoaded = true;
  }
  return jet_n_;
}

const vector<float> &MyBaby::jet_pt() {
  if (not jet_pt_isLoaded) {
    if (jet_pt_branch != 0) {
      jet_pt_branch->GetEntry(index);
    } else {
      printf("branch jet_pt_branch does not exist!\n");
      exit(1);
    }
    jet_pt_isLoaded = true;
  }
  return *jet_pt_;
}

const vector<float> &MyBaby::jet_eta() {
  if (not jet_eta_isLoaded) {
    if (jet_eta_branch != 0) {
      jet_eta_branch->GetEntry(index);
    } else {
      printf("branch jet_eta_branch does not exist!\n");
      exit(1);
    }
    jet_eta_isLoaded = true;
  }
  return *jet_eta_;
}

const vector<float> &MyBaby::jet_phi() {
  if (not jet_phi_isLoaded) {
    if (jet_phi_branch != 0) {
      jet_phi_branch->GetEntry(index);
    } else {
      printf("branch jet_phi_branch does not exist!\n");
      exit(1);
    }
    jet_phi_isLoaded = true;
  }
  return *jet_phi_;
}

const vector<float> &MyBaby::jet_mass() {
  if (not jet_mass_isLoaded) {
    if (jet_mass_branch != 0) {
      jet_mass_branch->GetEntry(index);
    } else {
      printf("branch jet_mass_branch does not exist!\n");
      exit(1);
    }
    jet_mass_isLoaded = true;
  }
  return *jet_mass_;
}

const vector<float> &MyBaby::jet_energy() {
  if (not jet_energy_isLoaded) {
    if (jet_energy_branch != 0) {
      jet_energy_branch->GetEntry(index);
    } else {
      printf("branch jet_energy_branch does not exist!\n");
      exit(1);
    }
    jet_energy_isLoaded = true;
  }
  return *jet_energy_;
}

const vector<float> &MyBaby::jet_btagCSV() {
  if (not jet_btagCSV_isLoaded) {
    if (jet_btagCSV_branch != 0) {
      jet_btagCSV_branch->GetEntry(index);
    } else {
      printf("branch jet_btagCSV_branch does not exist!\n");
      exit(1);
    }
    jet_btagCSV_isLoaded = true;
  }
  return *jet_btagCSV_;
}

const vector<float> &MyBaby::jet_rawPt() {
  if (not jet_rawPt_isLoaded) {
    if (jet_rawPt_branch != 0) {
      jet_rawPt_branch->GetEntry(index);
    } else {
      printf("branch jet_rawPt_branch does not exist!\n");
      exit(1);
    }
    jet_rawPt_isLoaded = true;
  }
  return *jet_rawPt_;
}

const vector<float> &MyBaby::jet_mcPt() {
  if (not jet_mcPt_isLoaded) {
    if (jet_mcPt_branch != 0) {
      jet_mcPt_branch->GetEntry(index);
    } else {
      printf("branch jet_mcPt_branch does not exist!\n");
      exit(1);
    }
    jet_mcPt_isLoaded = true;
  }
  return *jet_mcPt_;
}

const vector<int> &MyBaby::jet_mcFlavour() {
  if (not jet_mcFlavour_isLoaded) {
    if (jet_mcFlavour_branch != 0) {
      jet_mcFlavour_branch->GetEntry(index);
    } else {
      printf("branch jet_mcFlavour_branch does not exist!\n");
      exit(1);
    }
    jet_mcFlavour_isLoaded = true;
  }
  return *jet_mcFlavour_;
}

const vector<int> &MyBaby::jet_hadronFlavour() {
  if (not jet_hadronFlavour_isLoaded) {
    if (jet_hadronFlavour_branch != 0) {
      jet_hadronFlavour_branch->GetEntry(index);
    } else {
      printf("branch jet_hadronFlavour_branch does not exist!\n");
      exit(1);
    }
    jet_hadronFlavour_isLoaded = true;
  }
  return *jet_hadronFlavour_;
}

const vector<float> &MyBaby::jet_area() {
  if (not jet_area_isLoaded) {
    if (jet_area_branch != 0) {
      jet_area_branch->GetEntry(index);
    } else {
      printf("branch jet_area_branch does not exist!\n");
      exit(1);
    }
    jet_area_isLoaded = true;
  }
  return *jet_area_;
}

const vector<float> &MyBaby::jet_undoJEC() {
  if (not jet_undoJEC_isLoaded) {
    if (jet_undoJEC_branch != 0) {
      jet_undoJEC_branch->GetEntry(index);
    } else {
      printf("branch jet_undoJEC_branch does not exist!\n");
      exit(1);
    }
    jet_undoJEC_isLoaded = true;
  }
  return *jet_undoJEC_;
}

const vector<float> &MyBaby::jet_jecCorr() {
  if (not jet_jecCorr_isLoaded) {
    if (jet_jecCorr_branch != 0) {
      jet_jecCorr_branch->GetEntry(index);
    } else {
      printf("branch jet_jecCorr_branch does not exist!\n");
      exit(1);
    }
    jet_jecCorr_isLoaded = true;
  }
  return *jet_jecCorr_;
}

const vector<float> &MyBaby::jet_jecCorrUp() {
  if (not jet_jecCorrUp_isLoaded) {
    if (jet_jecCorrUp_branch != 0) {
      jet_jecCorrUp_branch->GetEntry(index);
    } else {
      printf("branch jet_jecCorrUp_branch does not exist!\n");
      exit(1);
    }
    jet_jecCorrUp_isLoaded = true;
  }
  return *jet_jecCorrUp_;
}

const vector<float> &MyBaby::jet_jecCorrDn() {
  if (not jet_jecCorrDn_isLoaded) {
    if (jet_jecCorrDn_branch != 0) {
      jet_jecCorrDn_branch->GetEntry(index);
    } else {
      printf("branch jet_jecCorrDn_branch does not exist!\n");
      exit(1);
    }
    jet_jecCorrDn_isLoaded = true;
  }
  return *jet_jecCorrDn_;
}

const vector<float> &MyBaby::jet_chf() {
  if (not jet_chf_isLoaded) {
    if (jet_chf_branch != 0) {
      jet_chf_branch->GetEntry(index);
    } else {
      printf("branch jet_chf_branch does not exist!\n");
      exit(1);
    }
    jet_chf_isLoaded = true;
  }
  return *jet_chf_;
}

const vector<float> &MyBaby::jet_nhf() {
  if (not jet_nhf_isLoaded) {
    if (jet_nhf_branch != 0) {
      jet_nhf_branch->GetEntry(index);
    } else {
      printf("branch jet_nhf_branch does not exist!\n");
      exit(1);
    }
    jet_nhf_isLoaded = true;
  }
  return *jet_nhf_;
}

const vector<float> &MyBaby::jet_cef() {
  if (not jet_cef_isLoaded) {
    if (jet_cef_branch != 0) {
      jet_cef_branch->GetEntry(index);
    } else {
      printf("branch jet_cef_branch does not exist!\n");
      exit(1);
    }
    jet_cef_isLoaded = true;
  }
  return *jet_cef_;
}

const vector<float> &MyBaby::jet_nef() {
  if (not jet_nef_isLoaded) {
    if (jet_nef_branch != 0) {
      jet_nef_branch->GetEntry(index);
    } else {
      printf("branch jet_nef_branch does not exist!\n");
      exit(1);
    }
    jet_nef_isLoaded = true;
  }
  return *jet_nef_;
}

const vector<float> &MyBaby::jet_muf() {
  if (not jet_muf_isLoaded) {
    if (jet_muf_branch != 0) {
      jet_muf_branch->GetEntry(index);
    } else {
      printf("branch jet_muf_branch does not exist!\n");
      exit(1);
    }
    jet_muf_isLoaded = true;
  }
  return *jet_muf_;
}

const vector<float> &MyBaby::jet_cm() {
  if (not jet_cm_isLoaded) {
    if (jet_cm_branch != 0) {
      jet_cm_branch->GetEntry(index);
    } else {
      printf("branch jet_cm_branch does not exist!\n");
      exit(1);
    }
    jet_cm_isLoaded = true;
  }
  return *jet_cm_;
}

const vector<float> &MyBaby::jet_nm() {
  if (not jet_nm_isLoaded) {
    if (jet_nm_branch != 0) {
      jet_nm_branch->GetEntry(index);
    } else {
      printf("branch jet_nm_branch does not exist!\n");
      exit(1);
    }
    jet_nm_isLoaded = true;
  }
  return *jet_nm_;
}

const vector<float> &MyBaby::jet_puValue() {
  if (not jet_puValue_isLoaded) {
    if (jet_puValue_branch != 0) {
      jet_puValue_branch->GetEntry(index);
    } else {
      printf("branch jet_puValue_branch does not exist!\n");
      exit(1);
    }
    jet_puValue_isLoaded = true;
  }
  return *jet_puValue_;
}

const vector<float> &MyBaby::jet_mcdr() {
  if (not jet_mcdr_isLoaded) {
    if (jet_mcdr_branch != 0) {
      jet_mcdr_branch->GetEntry(index);
    } else {
      printf("branch jet_mcdr_branch does not exist!\n");
      exit(1);
    }
    jet_mcdr_isLoaded = true;
  }
  return *jet_mcdr_;
}

const vector<int> &MyBaby::jet_npfcand() {
  if (not jet_npfcand_isLoaded) {
    if (jet_npfcand_branch != 0) {
      jet_npfcand_branch->GetEntry(index);
    } else {
      printf("branch jet_npfcand_branch does not exist!\n");
      exit(1);
    }
    jet_npfcand_isLoaded = true;
  }
  return *jet_npfcand_;
}

const vector<int> &MyBaby::jet_id() {
  if (not jet_id_isLoaded) {
    if (jet_id_branch != 0) {
      jet_id_branch->GetEntry(index);
    } else {
      printf("branch jet_id_branch does not exist!\n");
      exit(1);
    }
    jet_id_isLoaded = true;
  }
  return *jet_id_;
}

const vector<int> &MyBaby::jet_puId() {
  if (not jet_puId_isLoaded) {
    if (jet_puId_branch != 0) {
      jet_puId_branch->GetEntry(index);
    } else {
      printf("branch jet_puId_branch does not exist!\n");
      exit(1);
    }
    jet_puId_isLoaded = true;
  }
  return *jet_puId_;
}

const vector<int> &MyBaby::jet_puIdpuppi() {
  if (not jet_puIdpuppi_isLoaded) {
    if (jet_puIdpuppi_branch != 0) {
      jet_puIdpuppi_branch->GetEntry(index);
    } else {
      printf("branch jet_puIdpuppi_branch does not exist!\n");
      exit(1);
    }
    jet_puIdpuppi_isLoaded = true;
  }
  return *jet_puIdpuppi_;
}

const vector<int> &MyBaby::jet_FSveto() {
  if (not jet_FSveto_isLoaded) {
    if (jet_FSveto_branch != 0) {
      jet_FSveto_branch->GetEntry(index);
    } else {
      printf("branch jet_FSveto_branch does not exist!\n");
      exit(1);
    }
    jet_FSveto_isLoaded = true;
  }
  return *jet_FSveto_;
}

const float &MyBaby::met_pt() {
  if (not met_pt_isLoaded) {
    if (met_pt_branch != 0) {
      met_pt_branch->GetEntry(index);
    } else {
      printf("branch met_pt_branch does not exist!\n");
      exit(1);
    }
    met_pt_isLoaded = true;
  }
  return met_pt_;
}

const float &MyBaby::met_phi() {
  if (not met_phi_isLoaded) {
    if (met_phi_branch != 0) {
      met_phi_branch->GetEntry(index);
    } else {
      printf("branch met_phi_branch does not exist!\n");
      exit(1);
    }
    met_phi_isLoaded = true;
  }
  return met_phi_;
}

const int &MyBaby::evt_run() {
  if (not evt_run_isLoaded) {
    if (evt_run_branch != 0) {
      evt_run_branch->GetEntry(index);
    } else {
      printf("branch evt_run_branch does not exist!\n");
      exit(1);
    }
    evt_run_isLoaded = true;
  }
  return evt_run_;
}

const int &MyBaby::evt_lumi() {
  if (not evt_lumi_isLoaded) {
    if (evt_lumi_branch != 0) {
      evt_lumi_branch->GetEntry(index);
    } else {
      printf("branch evt_lumi_branch does not exist!\n");
      exit(1);
    }
    evt_lumi_isLoaded = true;
  }
  return evt_lumi_;
}

const int &MyBaby::evt_event() {
  if (not evt_event_isLoaded) {
    if (evt_event_branch != 0) {
      evt_event_branch->GetEntry(index);
    } else {
      printf("branch evt_event_branch does not exist!\n");
      exit(1);
    }
    evt_event_isLoaded = true;
  }
  return evt_event_;
}

const int &MyBaby::evt_nEvts() {
  if (not evt_nEvts_isLoaded) {
    if (evt_nEvts_branch != 0) {
      evt_nEvts_branch->GetEntry(index);
    } else {
      printf("branch evt_nEvts_branch does not exist!\n");
      exit(1);
    }
    evt_nEvts_isLoaded = true;
  }
  return evt_nEvts_;
}

const float &MyBaby::evt_scale1fb() {
  if (not evt_scale1fb_isLoaded) {
    if (evt_scale1fb_branch != 0) {
      evt_scale1fb_branch->GetEntry(index);
    } else {
      printf("branch evt_scale1fb_branch does not exist!\n");
      exit(1);
    }
    evt_scale1fb_isLoaded = true;
  }
  return evt_scale1fb_;
}

const float &MyBaby::gen_ht() {
  if (not gen_ht_isLoaded) {
    if (gen_ht_branch != 0) {
      gen_ht_branch->GetEntry(index);
    } else {
      printf("branch gen_ht_branch does not exist!\n");
      exit(1);
    }
    gen_ht_isLoaded = true;
  }
  return gen_ht_;
}


void MyBaby::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace tas {

const int &truth_n() { return mytree.truth_n(); }
const vector<float> &truth_pt() { return mytree.truth_pt(); }
const vector<float> &truth_eta() { return mytree.truth_eta(); }
const vector<float> &truth_phi() { return mytree.truth_phi(); }
const vector<float> &truth_mass() { return mytree.truth_mass(); }
const vector<float> &truth_energy() { return mytree.truth_energy(); }
const vector<int> &truth_pdgId() { return mytree.truth_pdgId(); }
const vector<int> &truth_status() { return mytree.truth_status(); }
const vector<int> &truth_motherId() { return mytree.truth_motherId(); }
const vector<int> &truth_grandmotherId() { return mytree.truth_grandmotherId(); }
const int &lep_n() { return mytree.lep_n(); }
const vector<float> &lep_pt() { return mytree.lep_pt(); }
const vector<float> &lep_eta() { return mytree.lep_eta(); }
const vector<float> &lep_phi() { return mytree.lep_phi(); }
const vector<float> &lep_mass() { return mytree.lep_mass(); }
const vector<float> &lep_energy() { return mytree.lep_energy(); }
const vector<float> &lep_dxy() { return mytree.lep_dxy(); }
const vector<float> &lep_dz() { return mytree.lep_dz(); }
const vector<float> &lep_ip3d() { return mytree.lep_ip3d(); }
const vector<float> &lep_sip3d() { return mytree.lep_sip3d(); }
const vector<int> &lep_tightcharge() { return mytree.lep_tightcharge(); }
const vector<int> &lep_charge() { return mytree.lep_charge(); }
const vector<int> &lep_pdgId() { return mytree.lep_pdgId(); }
const vector<int> &lep_id() { return mytree.lep_id(); }
const vector<float> &lep_ptRatio() { return mytree.lep_ptRatio(); }
const vector<float> &lep_ptRel() { return mytree.lep_ptRel(); }
const vector<float> &lep_relIso03() { return mytree.lep_relIso03(); }
const vector<float> &lep_relIso03DB() { return mytree.lep_relIso03DB(); }
const vector<float> &lep_relIso03EA() { return mytree.lep_relIso03EA(); }
const vector<float> &lep_relIso03EAv2() { return mytree.lep_relIso03EAv2(); }
const vector<float> &lep_relIso04() { return mytree.lep_relIso04(); }
const vector<float> &lep_relIso04DB() { return mytree.lep_relIso04DB(); }
const vector<float> &lep_relIso04EA() { return mytree.lep_relIso04EA(); }
const vector<float> &lep_relIso04EAv2() { return mytree.lep_relIso04EAv2(); }
const vector<float> &lep_miniRelIsoCMS3_EA() { return mytree.lep_miniRelIsoCMS3_EA(); }
const vector<float> &lep_miniRelIsoCMS3_EAv2() { return mytree.lep_miniRelIsoCMS3_EAv2(); }
const vector<float> &lep_miniRelIsoCMS3_DB() { return mytree.lep_miniRelIsoCMS3_DB(); }
const vector<float> &lep_relIso005EAstudy() { return mytree.lep_relIso005EAstudy(); }
const vector<float> &lep_relIso010EAstudy() { return mytree.lep_relIso010EAstudy(); }
const vector<float> &lep_relIso015EAstudy() { return mytree.lep_relIso015EAstudy(); }
const vector<float> &lep_relIso020EAstudy() { return mytree.lep_relIso020EAstudy(); }
const vector<float> &lep_relIso025EAstudy() { return mytree.lep_relIso025EAstudy(); }
const vector<float> &lep_relIso030EAstudy() { return mytree.lep_relIso030EAstudy(); }
const vector<float> &lep_relIso035EAstudy() { return mytree.lep_relIso035EAstudy(); }
const vector<float> &lep_relIso045EAstudy() { return mytree.lep_relIso045EAstudy(); }
const vector<float> &lep_relIso050EAstudy() { return mytree.lep_relIso050EAstudy(); }
const vector<float> &lep_muPOverP() { return mytree.lep_muPOverP(); }
const vector<int> &lep_muPidPFMuon() { return mytree.lep_muPidPFMuon(); }
const vector<int> &lep_muType() { return mytree.lep_muType(); }
const vector<float> &lep_muChi2OverNDof() { return mytree.lep_muChi2OverNDof(); }
const vector<float> &lep_muChi2LocalPosition() { return mytree.lep_muChi2LocalPosition(); }
const vector<float> &lep_muTrkKink() { return mytree.lep_muTrkKink(); }
const vector<float> &lep_muValidHitFraction() { return mytree.lep_muValidHitFraction(); }
const vector<float> &lep_muSegmCompatibility() { return mytree.lep_muSegmCompatibility(); }
const vector<int> &lep_muGFitValidSTAHits() { return mytree.lep_muGFitValidSTAHits(); }
const vector<int> &lep_muNMatchedStations() { return mytree.lep_muNMatchedStations(); }
const vector<int> &lep_muValidPixelHits() { return mytree.lep_muValidPixelHits(); }
const vector<int> &lep_muNLayers() { return mytree.lep_muNLayers(); }
const vector<float> &lep_elEtaSC() { return mytree.lep_elEtaSC(); }
const vector<float> &lep_elSigmaIEtaIEta_full5x5() { return mytree.lep_elSigmaIEtaIEta_full5x5(); }
const vector<float> &lep_elHOverE() { return mytree.lep_elHOverE(); }
const vector<float> &lep_elMvaRaw() { return mytree.lep_elMvaRaw(); }
const vector<float> &lep_elMva() { return mytree.lep_elMva(); }
const vector<float> &lep_elDEtaIn() { return mytree.lep_elDEtaIn(); }
const vector<float> &lep_elDPhiIn() { return mytree.lep_elDPhiIn(); }
const vector<float> &lep_elEpRatio() { return mytree.lep_elEpRatio(); }
const vector<int> &lep_elConvVeto() { return mytree.lep_elConvVeto(); }
const vector<int> &lep_elNmiss() { return mytree.lep_elNmiss(); }
const vector<int> &lep_isFromX() { return mytree.lep_isFromX(); }
const int &jet_n() { return mytree.jet_n(); }
const vector<float> &jet_pt() { return mytree.jet_pt(); }
const vector<float> &jet_eta() { return mytree.jet_eta(); }
const vector<float> &jet_phi() { return mytree.jet_phi(); }
const vector<float> &jet_mass() { return mytree.jet_mass(); }
const vector<float> &jet_energy() { return mytree.jet_energy(); }
const vector<float> &jet_btagCSV() { return mytree.jet_btagCSV(); }
const vector<float> &jet_rawPt() { return mytree.jet_rawPt(); }
const vector<float> &jet_mcPt() { return mytree.jet_mcPt(); }
const vector<int> &jet_mcFlavour() { return mytree.jet_mcFlavour(); }
const vector<int> &jet_hadronFlavour() { return mytree.jet_hadronFlavour(); }
const vector<float> &jet_area() { return mytree.jet_area(); }
const vector<float> &jet_undoJEC() { return mytree.jet_undoJEC(); }
const vector<float> &jet_jecCorr() { return mytree.jet_jecCorr(); }
const vector<float> &jet_jecCorrUp() { return mytree.jet_jecCorrUp(); }
const vector<float> &jet_jecCorrDn() { return mytree.jet_jecCorrDn(); }
const vector<float> &jet_chf() { return mytree.jet_chf(); }
const vector<float> &jet_nhf() { return mytree.jet_nhf(); }
const vector<float> &jet_cef() { return mytree.jet_cef(); }
const vector<float> &jet_nef() { return mytree.jet_nef(); }
const vector<float> &jet_muf() { return mytree.jet_muf(); }
const vector<float> &jet_cm() { return mytree.jet_cm(); }
const vector<float> &jet_nm() { return mytree.jet_nm(); }
const vector<float> &jet_puValue() { return mytree.jet_puValue(); }
const vector<float> &jet_mcdr() { return mytree.jet_mcdr(); }
const vector<int> &jet_npfcand() { return mytree.jet_npfcand(); }
const vector<int> &jet_id() { return mytree.jet_id(); }
const vector<int> &jet_puId() { return mytree.jet_puId(); }
const vector<int> &jet_puIdpuppi() { return mytree.jet_puIdpuppi(); }
const vector<int> &jet_FSveto() { return mytree.jet_FSveto(); }
const float &met_pt() { return mytree.met_pt(); }
const float &met_phi() { return mytree.met_phi(); }
const int &evt_run() { return mytree.evt_run(); }
const int &evt_lumi() { return mytree.evt_lumi(); }
const int &evt_event() { return mytree.evt_event(); }
const int &evt_nEvts() { return mytree.evt_nEvts(); }
const float &evt_scale1fb() { return mytree.evt_scale1fb(); }
const float &gen_ht() { return mytree.gen_ht(); }

}
