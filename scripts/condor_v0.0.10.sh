rm -rf /hadoop/cms/store/user/phchang/ditto_output/isolationanalysis_isolation_v0.0.10__*
ditto_runana -c  -t isolation_v0.0.10__www    -f -d /hadoop/cms/store/user/phchang/AutoTwopler_babies/general_v0.0.10_isostudy/WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/output_tree/
ditto_runana -c  -t isolation_v0.0.10__ttbar  -f -d /hadoop/cms/store/user/phchang/AutoTwopler_babies/general_v0.0.10_isostudy/TTJets_SingleLeptFromT_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6_ext1-v1/output_tree/
ditto_runana -c  -t isolation_v0.0.10__qcd    -f -d /hadoop/cms/store/user/phchang/AutoTwopler_babies/general_v0.0.10_isostudy/QCD_Pt-20toInf_MuEnrichedPt15_TuneCUETP8M1_13TeV_pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/output_tree/
ditto_runana -c  -t isolation_v0.0.10__wjets  -f -d /hadoop/cms/store/user/phchang/AutoTwopler_babies/general_v0.0.10_isostudy/WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/output_tree/