// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef IsoTreeConnector_h
#define IsoTreeConnector_h

#include "Ditto.h"
#include "IsoTree.h"

using namespace Ditto;

ObjUtil::Leptons getLeptons(/*IsoTree& mytree*/);
ObjUtil::Jets getJets(/*IsoTree& mytree*/);
ObjUtil::Jets getBJets(/*IsoTree& mytree*/);
ObjUtil::METs getMETs(/*IsoTree& mytree*/);
ObjUtil::MET getMET(/*IsoTree& mytree*/);

#endif
//eof
