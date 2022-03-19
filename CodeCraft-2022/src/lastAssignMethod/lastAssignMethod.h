#ifndef __LAST_ASSIGNMETHODH_
#define __LAST_ASSIGNMETHODH_

#include "../lib/WBStruct.h"
#include "../lib/SiteBandWidth.h"
#include "../lib/lastResult.h"
#include <vector>

using std::vector;

vector<lastResult> lastAssignMethod(int posCus, int mtime);
extern vector<SiteBandWidth> vecSiteBandWidth;
extern vector<webStruct> vecWebStruct;
extern int numSite;
extern int LATENCY_MAX;

 #endif