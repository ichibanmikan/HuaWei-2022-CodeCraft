#include "getFirstSite.h"

int getFirstSitePos(int posCus, int thisMTime){
    for(int i=0; i<numSite; i++){
        if(vecSiteBandWidth[i].arraySiteCusLatency[posCus]<LATENCY_MAX&&(vecSiteBandWidth[i].bandWidth>=vecWebStruct[thisMTime].arrayBWDemand[posCus])){
            vecSiteBandWidth[i].bandWidth-=vecWebStruct[thisMTime].arrayBWDemand[posCus];
            return i;
        }
    }
    return -1;
}