// vim: tabstop=2:softtabstop=2:shiftwidth=2:expandtab

//  .
// ..: P. Chang, philip@physics.ucsd.edu

#ifndef MyBabyConnector_h
#define MyBabyConnector_h

#include "Ditto.h"
#include "MyBaby.h"

using namespace Ditto;

ObjUtil::Leptons getLeptons(/*MyBaby& mytree*/);
ObjUtil::Jets getJets(/*MyBaby& mytree*/);
ObjUtil::Jets getBJets(/*MyBaby& mytree*/);
ObjUtil::METs getMETs(/*MyBaby& mytree*/);
ObjUtil::MET getMET(/*MyBaby& mytree*/);

#endif
//eof
