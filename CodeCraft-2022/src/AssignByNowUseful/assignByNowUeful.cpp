#include "assignByNowUeful.h"

int assignByNowUeful(int posCus, int thisMTime, int nowUsefulPos){
    int cusDemand=vecWebStruct[thisMTime].arrayBWDemand[posCus];
    for(int i=nowUsefulPos; i<numSite; i++){
        if(vecSiteBandWidth[i].arraySiteCusLatency[posCus]<LATENCY_MAX&&cusDemand<vecSiteBandWidth[i].bandWidth){
            vecSiteBandWidth[i].bandWidth-=cusDemand;
            return i;
        }
        cusDemand-=vecSiteBandWidth[i].bandWidth;
        vecSiteBandWidth[i].bandWidth=0;
    }
    return -1;
}