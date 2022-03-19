#include "lastAssignMethod.h"

vector<lastResult> lastAssignMethod(int posCus, int mtime){
    vector<lastResult> vecLastResult;
    lastResult lr;
    int cusBandWidth=vecWebStruct[mtime].arrayBWDemand[posCus];
    for(int i=0; i<numSite; i++){
        if(cusBandWidth<=0){
            return vecLastResult;
        }
        if(vecSiteBandWidth[i].bandWidth!=0&&vecSiteBandWidth[i].arraySiteCusLatency[posCus]<LATENCY_MAX){
            lr.posSite=i;
            if(cusBandWidth>=vecSiteBandWidth[i].bandWidth){
                lr.numBandW=vecSiteBandWidth[i].bandWidth;
                cusBandWidth-=lr.numBandW;
                vecSiteBandWidth[i].bandWidth=0;
            } else {
                lr.numBandW=cusBandWidth;
                cusBandWidth=0;
                vecSiteBandWidth[i].bandWidth-=cusBandWidth;
            }
            vecLastResult.push_back(lr);
        }
    }
}