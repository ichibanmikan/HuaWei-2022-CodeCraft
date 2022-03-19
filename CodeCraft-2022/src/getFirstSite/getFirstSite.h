#ifndef __GET_FIRSTSITE_
#define __GET_FIRSTSITE_
#include <vector>
#include "../lib/SiteBandWidth.h"
#include "../lib/WBStruct.h"

// #include "../lib/testHelp.h"

using std::vector;

extern int numSite;
extern int numCus;
extern int LATENCY_MAX;
extern vector<webStruct> vecWebStruct;
extern vector<SiteBandWidth> vecSiteBandWidth;
int getFirstSitePos(int posCus);

#endif