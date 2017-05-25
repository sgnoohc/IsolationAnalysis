#include "IsoTree.h"
IsoTree mytree;

void IsoTree::Init(TTree *tree) {

  tree->SetMakeClass(1);

  sip3d_branch = tree->GetBranch("sip3d");
  if (sip3d_branch) sip3d_branch->SetAddress(&sip3d_);
  ip3d_branch = tree->GetBranch("ip3d");
  if (ip3d_branch) ip3d_branch->SetAddress(&ip3d_);
  ptrel_branch = tree->GetBranch("ptrel");
  if (ptrel_branch) ptrel_branch->SetAddress(&ptrel_);
  ptratio_branch = tree->GetBranch("ptratio");
  if (ptratio_branch) ptratio_branch->SetAddress(&ptratio_);
  relIso03_branch = tree->GetBranch("relIso03");
  if (relIso03_branch) relIso03_branch->SetAddress(&relIso03_);
  relIso03DB_branch = tree->GetBranch("relIso03DB");
  if (relIso03DB_branch) relIso03DB_branch->SetAddress(&relIso03DB_);
  relIso03EA_branch = tree->GetBranch("relIso03EA");
  if (relIso03EA_branch) relIso03EA_branch->SetAddress(&relIso03EA_);
  relIso04DB_branch = tree->GetBranch("relIso04DB");
  if (relIso04DB_branch) relIso04DB_branch->SetAddress(&relIso04DB_);
  relIso04EA_branch = tree->GetBranch("relIso04EA");
  if (relIso04EA_branch) relIso04EA_branch->SetAddress(&relIso04EA_);
  miniRelIsoDB_branch = tree->GetBranch("miniRelIsoDB");
  if (miniRelIsoDB_branch) miniRelIsoDB_branch->SetAddress(&miniRelIsoDB_);
  miniRelIsoEA_branch = tree->GetBranch("miniRelIsoEA");
  if (miniRelIsoEA_branch) miniRelIsoEA_branch->SetAddress(&miniRelIsoEA_);
  relIso005EA_branch = tree->GetBranch("relIso005EA");
  if (relIso005EA_branch) relIso005EA_branch->SetAddress(&relIso005EA_);
  relIso010EA_branch = tree->GetBranch("relIso010EA");
  if (relIso010EA_branch) relIso010EA_branch->SetAddress(&relIso010EA_);
  relIso015EA_branch = tree->GetBranch("relIso015EA");
  if (relIso015EA_branch) relIso015EA_branch->SetAddress(&relIso015EA_);
  relIso020EA_branch = tree->GetBranch("relIso020EA");
  if (relIso020EA_branch) relIso020EA_branch->SetAddress(&relIso020EA_);
  relIso025EA_branch = tree->GetBranch("relIso025EA");
  if (relIso025EA_branch) relIso025EA_branch->SetAddress(&relIso025EA_);
  relIso030EA_branch = tree->GetBranch("relIso030EA");
  if (relIso030EA_branch) relIso030EA_branch->SetAddress(&relIso030EA_);
  relIso035EA_branch = tree->GetBranch("relIso035EA");
  if (relIso035EA_branch) relIso035EA_branch->SetAddress(&relIso035EA_);
  relIso045EA_branch = tree->GetBranch("relIso045EA");
  if (relIso045EA_branch) relIso045EA_branch->SetAddress(&relIso045EA_);
  relIso050EA_branch = tree->GetBranch("relIso050EA");
  if (relIso050EA_branch) relIso050EA_branch->SetAddress(&relIso050EA_);
  absIso03_branch = tree->GetBranch("absIso03");
  if (absIso03_branch) absIso03_branch->SetAddress(&absIso03_);
  absIso03DB_branch = tree->GetBranch("absIso03DB");
  if (absIso03DB_branch) absIso03DB_branch->SetAddress(&absIso03DB_);
  absIso03EA_branch = tree->GetBranch("absIso03EA");
  if (absIso03EA_branch) absIso03EA_branch->SetAddress(&absIso03EA_);
  absIso04DB_branch = tree->GetBranch("absIso04DB");
  if (absIso04DB_branch) absIso04DB_branch->SetAddress(&absIso04DB_);
  absIso04EA_branch = tree->GetBranch("absIso04EA");
  if (absIso04EA_branch) absIso04EA_branch->SetAddress(&absIso04EA_);
  pt_branch = tree->GetBranch("pt");
  if (pt_branch) pt_branch->SetAddress(&pt_);
  eta_branch = tree->GetBranch("eta");
  if (eta_branch) eta_branch->SetAddress(&eta_);
  pdgId_branch = tree->GetBranch("pdgId");
  if (pdgId_branch) pdgId_branch->SetAddress(&pdgId_);
  relIso03EAv2_branch = tree->GetBranch("relIso03EAv2");
  if (relIso03EAv2_branch) relIso03EAv2_branch->SetAddress(&relIso03EAv2_);
  relIso04EAv2_branch = tree->GetBranch("relIso04EAv2");
  if (relIso04EAv2_branch) relIso04EAv2_branch->SetAddress(&relIso04EAv2_);
  miniRelIsoEAv2_branch = tree->GetBranch("miniRelIsoEAv2");
  if (miniRelIsoEAv2_branch) miniRelIsoEAv2_branch->SetAddress(&miniRelIsoEAv2_);
  absIso03EAv2_branch = tree->GetBranch("absIso03EAv2");
  if (absIso03EAv2_branch) absIso03EAv2_branch->SetAddress(&absIso03EAv2_);
  absIso04EAv2_branch = tree->GetBranch("absIso04EAv2");
  if (absIso04EAv2_branch) absIso04EAv2_branch->SetAddress(&absIso04EAv2_);

  tree->SetMakeClass(0);
}

void IsoTree::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  sip3d_isLoaded = false;
  ip3d_isLoaded = false;
  ptrel_isLoaded = false;
  ptratio_isLoaded = false;
  relIso03_isLoaded = false;
  relIso03DB_isLoaded = false;
  relIso03EA_isLoaded = false;
  relIso04DB_isLoaded = false;
  relIso04EA_isLoaded = false;
  miniRelIsoDB_isLoaded = false;
  miniRelIsoEA_isLoaded = false;
  relIso005EA_isLoaded = false;
  relIso010EA_isLoaded = false;
  relIso015EA_isLoaded = false;
  relIso020EA_isLoaded = false;
  relIso025EA_isLoaded = false;
  relIso030EA_isLoaded = false;
  relIso035EA_isLoaded = false;
  relIso045EA_isLoaded = false;
  relIso050EA_isLoaded = false;
  absIso03_isLoaded = false;
  absIso03DB_isLoaded = false;
  absIso03EA_isLoaded = false;
  absIso04DB_isLoaded = false;
  absIso04EA_isLoaded = false;
  pt_isLoaded = false;
  eta_isLoaded = false;
  pdgId_isLoaded = false;
  relIso03EAv2_isLoaded = false;
  relIso04EAv2_isLoaded = false;
  miniRelIsoEAv2_isLoaded = false;
  absIso03EAv2_isLoaded = false;
  absIso04EAv2_isLoaded = false;
}

void IsoTree::LoadAllBranches() {
  // load all branches
  if (sip3d_branch != 0) sip3d();
  if (ip3d_branch != 0) ip3d();
  if (ptrel_branch != 0) ptrel();
  if (ptratio_branch != 0) ptratio();
  if (relIso03_branch != 0) relIso03();
  if (relIso03DB_branch != 0) relIso03DB();
  if (relIso03EA_branch != 0) relIso03EA();
  if (relIso04DB_branch != 0) relIso04DB();
  if (relIso04EA_branch != 0) relIso04EA();
  if (miniRelIsoDB_branch != 0) miniRelIsoDB();
  if (miniRelIsoEA_branch != 0) miniRelIsoEA();
  if (relIso005EA_branch != 0) relIso005EA();
  if (relIso010EA_branch != 0) relIso010EA();
  if (relIso015EA_branch != 0) relIso015EA();
  if (relIso020EA_branch != 0) relIso020EA();
  if (relIso025EA_branch != 0) relIso025EA();
  if (relIso030EA_branch != 0) relIso030EA();
  if (relIso035EA_branch != 0) relIso035EA();
  if (relIso045EA_branch != 0) relIso045EA();
  if (relIso050EA_branch != 0) relIso050EA();
  if (absIso03_branch != 0) absIso03();
  if (absIso03DB_branch != 0) absIso03DB();
  if (absIso03EA_branch != 0) absIso03EA();
  if (absIso04DB_branch != 0) absIso04DB();
  if (absIso04EA_branch != 0) absIso04EA();
  if (pt_branch != 0) pt();
  if (eta_branch != 0) eta();
  if (pdgId_branch != 0) pdgId();
  if (relIso03EAv2_branch != 0) relIso03EAv2();
  if (relIso04EAv2_branch != 0) relIso04EAv2();
  if (miniRelIsoEAv2_branch != 0) miniRelIsoEAv2();
  if (absIso03EAv2_branch != 0) absIso03EAv2();
  if (absIso04EAv2_branch != 0) absIso04EAv2();
}

const float &IsoTree::sip3d() {
  if (not sip3d_isLoaded) {
    if (sip3d_branch != 0) {
      sip3d_branch->GetEntry(index);
    } else {
      printf("branch sip3d_branch does not exist!\n");
      exit(1);
    }
    sip3d_isLoaded = true;
  }
  return sip3d_;
}

const float &IsoTree::ip3d() {
  if (not ip3d_isLoaded) {
    if (ip3d_branch != 0) {
      ip3d_branch->GetEntry(index);
    } else {
      printf("branch ip3d_branch does not exist!\n");
      exit(1);
    }
    ip3d_isLoaded = true;
  }
  return ip3d_;
}

const float &IsoTree::ptrel() {
  if (not ptrel_isLoaded) {
    if (ptrel_branch != 0) {
      ptrel_branch->GetEntry(index);
    } else {
      printf("branch ptrel_branch does not exist!\n");
      exit(1);
    }
    ptrel_isLoaded = true;
  }
  return ptrel_;
}

const float &IsoTree::ptratio() {
  if (not ptratio_isLoaded) {
    if (ptratio_branch != 0) {
      ptratio_branch->GetEntry(index);
    } else {
      printf("branch ptratio_branch does not exist!\n");
      exit(1);
    }
    ptratio_isLoaded = true;
  }
  return ptratio_;
}

const float &IsoTree::relIso03() {
  if (not relIso03_isLoaded) {
    if (relIso03_branch != 0) {
      relIso03_branch->GetEntry(index);
    } else {
      printf("branch relIso03_branch does not exist!\n");
      exit(1);
    }
    relIso03_isLoaded = true;
  }
  return relIso03_;
}

const float &IsoTree::relIso03DB() {
  if (not relIso03DB_isLoaded) {
    if (relIso03DB_branch != 0) {
      relIso03DB_branch->GetEntry(index);
    } else {
      printf("branch relIso03DB_branch does not exist!\n");
      exit(1);
    }
    relIso03DB_isLoaded = true;
  }
  return relIso03DB_;
}

const float &IsoTree::relIso03EA() {
  if (not relIso03EA_isLoaded) {
    if (relIso03EA_branch != 0) {
      relIso03EA_branch->GetEntry(index);
    } else {
      printf("branch relIso03EA_branch does not exist!\n");
      exit(1);
    }
    relIso03EA_isLoaded = true;
  }
  return relIso03EA_;
}

const float &IsoTree::relIso04DB() {
  if (not relIso04DB_isLoaded) {
    if (relIso04DB_branch != 0) {
      relIso04DB_branch->GetEntry(index);
    } else {
      printf("branch relIso04DB_branch does not exist!\n");
      exit(1);
    }
    relIso04DB_isLoaded = true;
  }
  return relIso04DB_;
}

const float &IsoTree::relIso04EA() {
  if (not relIso04EA_isLoaded) {
    if (relIso04EA_branch != 0) {
      relIso04EA_branch->GetEntry(index);
    } else {
      printf("branch relIso04EA_branch does not exist!\n");
      exit(1);
    }
    relIso04EA_isLoaded = true;
  }
  return relIso04EA_;
}

const float &IsoTree::miniRelIsoDB() {
  if (not miniRelIsoDB_isLoaded) {
    if (miniRelIsoDB_branch != 0) {
      miniRelIsoDB_branch->GetEntry(index);
    } else {
      printf("branch miniRelIsoDB_branch does not exist!\n");
      exit(1);
    }
    miniRelIsoDB_isLoaded = true;
  }
  return miniRelIsoDB_;
}

const float &IsoTree::miniRelIsoEA() {
  if (not miniRelIsoEA_isLoaded) {
    if (miniRelIsoEA_branch != 0) {
      miniRelIsoEA_branch->GetEntry(index);
    } else {
      printf("branch miniRelIsoEA_branch does not exist!\n");
      exit(1);
    }
    miniRelIsoEA_isLoaded = true;
  }
  return miniRelIsoEA_;
}

const float &IsoTree::relIso005EA() {
  if (not relIso005EA_isLoaded) {
    if (relIso005EA_branch != 0) {
      relIso005EA_branch->GetEntry(index);
    } else {
      printf("branch relIso005EA_branch does not exist!\n");
      exit(1);
    }
    relIso005EA_isLoaded = true;
  }
  return relIso005EA_;
}

const float &IsoTree::relIso010EA() {
  if (not relIso010EA_isLoaded) {
    if (relIso010EA_branch != 0) {
      relIso010EA_branch->GetEntry(index);
    } else {
      printf("branch relIso010EA_branch does not exist!\n");
      exit(1);
    }
    relIso010EA_isLoaded = true;
  }
  return relIso010EA_;
}

const float &IsoTree::relIso015EA() {
  if (not relIso015EA_isLoaded) {
    if (relIso015EA_branch != 0) {
      relIso015EA_branch->GetEntry(index);
    } else {
      printf("branch relIso015EA_branch does not exist!\n");
      exit(1);
    }
    relIso015EA_isLoaded = true;
  }
  return relIso015EA_;
}

const float &IsoTree::relIso020EA() {
  if (not relIso020EA_isLoaded) {
    if (relIso020EA_branch != 0) {
      relIso020EA_branch->GetEntry(index);
    } else {
      printf("branch relIso020EA_branch does not exist!\n");
      exit(1);
    }
    relIso020EA_isLoaded = true;
  }
  return relIso020EA_;
}

const float &IsoTree::relIso025EA() {
  if (not relIso025EA_isLoaded) {
    if (relIso025EA_branch != 0) {
      relIso025EA_branch->GetEntry(index);
    } else {
      printf("branch relIso025EA_branch does not exist!\n");
      exit(1);
    }
    relIso025EA_isLoaded = true;
  }
  return relIso025EA_;
}

const float &IsoTree::relIso030EA() {
  if (not relIso030EA_isLoaded) {
    if (relIso030EA_branch != 0) {
      relIso030EA_branch->GetEntry(index);
    } else {
      printf("branch relIso030EA_branch does not exist!\n");
      exit(1);
    }
    relIso030EA_isLoaded = true;
  }
  return relIso030EA_;
}

const float &IsoTree::relIso035EA() {
  if (not relIso035EA_isLoaded) {
    if (relIso035EA_branch != 0) {
      relIso035EA_branch->GetEntry(index);
    } else {
      printf("branch relIso035EA_branch does not exist!\n");
      exit(1);
    }
    relIso035EA_isLoaded = true;
  }
  return relIso035EA_;
}

const float &IsoTree::relIso045EA() {
  if (not relIso045EA_isLoaded) {
    if (relIso045EA_branch != 0) {
      relIso045EA_branch->GetEntry(index);
    } else {
      printf("branch relIso045EA_branch does not exist!\n");
      exit(1);
    }
    relIso045EA_isLoaded = true;
  }
  return relIso045EA_;
}

const float &IsoTree::relIso050EA() {
  if (not relIso050EA_isLoaded) {
    if (relIso050EA_branch != 0) {
      relIso050EA_branch->GetEntry(index);
    } else {
      printf("branch relIso050EA_branch does not exist!\n");
      exit(1);
    }
    relIso050EA_isLoaded = true;
  }
  return relIso050EA_;
}

const float &IsoTree::absIso03() {
  if (not absIso03_isLoaded) {
    if (absIso03_branch != 0) {
      absIso03_branch->GetEntry(index);
    } else {
      printf("branch absIso03_branch does not exist!\n");
      exit(1);
    }
    absIso03_isLoaded = true;
  }
  return absIso03_;
}

const float &IsoTree::absIso03DB() {
  if (not absIso03DB_isLoaded) {
    if (absIso03DB_branch != 0) {
      absIso03DB_branch->GetEntry(index);
    } else {
      printf("branch absIso03DB_branch does not exist!\n");
      exit(1);
    }
    absIso03DB_isLoaded = true;
  }
  return absIso03DB_;
}

const float &IsoTree::absIso03EA() {
  if (not absIso03EA_isLoaded) {
    if (absIso03EA_branch != 0) {
      absIso03EA_branch->GetEntry(index);
    } else {
      printf("branch absIso03EA_branch does not exist!\n");
      exit(1);
    }
    absIso03EA_isLoaded = true;
  }
  return absIso03EA_;
}

const float &IsoTree::absIso04DB() {
  if (not absIso04DB_isLoaded) {
    if (absIso04DB_branch != 0) {
      absIso04DB_branch->GetEntry(index);
    } else {
      printf("branch absIso04DB_branch does not exist!\n");
      exit(1);
    }
    absIso04DB_isLoaded = true;
  }
  return absIso04DB_;
}

const float &IsoTree::absIso04EA() {
  if (not absIso04EA_isLoaded) {
    if (absIso04EA_branch != 0) {
      absIso04EA_branch->GetEntry(index);
    } else {
      printf("branch absIso04EA_branch does not exist!\n");
      exit(1);
    }
    absIso04EA_isLoaded = true;
  }
  return absIso04EA_;
}

const float &IsoTree::pt() {
  if (not pt_isLoaded) {
    if (pt_branch != 0) {
      pt_branch->GetEntry(index);
    } else {
      printf("branch pt_branch does not exist!\n");
      exit(1);
    }
    pt_isLoaded = true;
  }
  return pt_;
}

const float &IsoTree::eta() {
  if (not eta_isLoaded) {
    if (eta_branch != 0) {
      eta_branch->GetEntry(index);
    } else {
      printf("branch eta_branch does not exist!\n");
      exit(1);
    }
    eta_isLoaded = true;
  }
  return eta_;
}

const int &IsoTree::pdgId() {
  if (not pdgId_isLoaded) {
    if (pdgId_branch != 0) {
      pdgId_branch->GetEntry(index);
    } else {
      printf("branch pdgId_branch does not exist!\n");
      exit(1);
    }
    pdgId_isLoaded = true;
  }
  return pdgId_;
}

const float &IsoTree::relIso03EAv2() {
  if (not relIso03EAv2_isLoaded) {
    if (relIso03EAv2_branch != 0) {
      relIso03EAv2_branch->GetEntry(index);
    } else {
      printf("branch relIso03EAv2_branch does not exist!\n");
      exit(1);
    }
    relIso03EAv2_isLoaded = true;
  }
  return relIso03EAv2_;
}

const float &IsoTree::relIso04EAv2() {
  if (not relIso04EAv2_isLoaded) {
    if (relIso04EAv2_branch != 0) {
      relIso04EAv2_branch->GetEntry(index);
    } else {
      printf("branch relIso04EAv2_branch does not exist!\n");
      exit(1);
    }
    relIso04EAv2_isLoaded = true;
  }
  return relIso04EAv2_;
}

const float &IsoTree::miniRelIsoEAv2() {
  if (not miniRelIsoEAv2_isLoaded) {
    if (miniRelIsoEAv2_branch != 0) {
      miniRelIsoEAv2_branch->GetEntry(index);
    } else {
      printf("branch miniRelIsoEAv2_branch does not exist!\n");
      exit(1);
    }
    miniRelIsoEAv2_isLoaded = true;
  }
  return miniRelIsoEAv2_;
}

const float &IsoTree::absIso03EAv2() {
  if (not absIso03EAv2_isLoaded) {
    if (absIso03EAv2_branch != 0) {
      absIso03EAv2_branch->GetEntry(index);
    } else {
      printf("branch absIso03EAv2_branch does not exist!\n");
      exit(1);
    }
    absIso03EAv2_isLoaded = true;
  }
  return absIso03EAv2_;
}

const float &IsoTree::absIso04EAv2() {
  if (not absIso04EAv2_isLoaded) {
    if (absIso04EAv2_branch != 0) {
      absIso04EAv2_branch->GetEntry(index);
    } else {
      printf("branch absIso04EAv2_branch does not exist!\n");
      exit(1);
    }
    absIso04EAv2_isLoaded = true;
  }
  return absIso04EAv2_;
}


void IsoTree::progress( int nEventsTotal, int nEventsChain ){
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

const float &sip3d() { return mytree.sip3d(); }
const float &ip3d() { return mytree.ip3d(); }
const float &ptrel() { return mytree.ptrel(); }
const float &ptratio() { return mytree.ptratio(); }
const float &relIso03() { return mytree.relIso03(); }
const float &relIso03DB() { return mytree.relIso03DB(); }
const float &relIso03EA() { return mytree.relIso03EA(); }
const float &relIso04DB() { return mytree.relIso04DB(); }
const float &relIso04EA() { return mytree.relIso04EA(); }
const float &miniRelIsoDB() { return mytree.miniRelIsoDB(); }
const float &miniRelIsoEA() { return mytree.miniRelIsoEA(); }
const float &relIso005EA() { return mytree.relIso005EA(); }
const float &relIso010EA() { return mytree.relIso010EA(); }
const float &relIso015EA() { return mytree.relIso015EA(); }
const float &relIso020EA() { return mytree.relIso020EA(); }
const float &relIso025EA() { return mytree.relIso025EA(); }
const float &relIso030EA() { return mytree.relIso030EA(); }
const float &relIso035EA() { return mytree.relIso035EA(); }
const float &relIso045EA() { return mytree.relIso045EA(); }
const float &relIso050EA() { return mytree.relIso050EA(); }
const float &absIso03() { return mytree.absIso03(); }
const float &absIso03DB() { return mytree.absIso03DB(); }
const float &absIso03EA() { return mytree.absIso03EA(); }
const float &absIso04DB() { return mytree.absIso04DB(); }
const float &absIso04EA() { return mytree.absIso04EA(); }
const float &pt() { return mytree.pt(); }
const float &eta() { return mytree.eta(); }
const int &pdgId() { return mytree.pdgId(); }
const float &relIso03EAv2() { return mytree.relIso03EAv2(); }
const float &relIso04EAv2() { return mytree.relIso04EAv2(); }
const float &miniRelIsoEAv2() { return mytree.miniRelIsoEAv2(); }
const float &absIso03EAv2() { return mytree.absIso03EAv2(); }
const float &absIso04EAv2() { return mytree.absIso04EAv2(); }

}
