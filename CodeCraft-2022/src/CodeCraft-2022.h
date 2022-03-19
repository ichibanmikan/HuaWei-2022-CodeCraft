#ifndef _CODE_CRAFT_2022_
#define _CODE_CRAFT_2022_

#pragma once

#include <fstream>
#include <vector>
#include "./lib/WBStruct.h"
#include "./lib/SiteBandWidth.h"
#include "./lib/lastResult.h"

#include "./lib/testHelp.h"

using std::vector;
using std::ofstream;

extern int numCus;
extern int numSite;
extern int LATENCY_MAX;
extern string* arrayCusIDs;
extern void getSiteBW();
extern void getCusDemandData();
extern void getMaxLatency();
extern int getFirstSitePos(int, int);
extern int assignByNowUeful(int, int, int);
extern vector<lastResult> lastAssignMethod(int, int);
extern vector<webStruct> vecWebStruct;
extern vector<SiteBandWidth> vecSiteBandWidth; 

#endif