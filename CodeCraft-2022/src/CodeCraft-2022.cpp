#include "CodeCraft-2022.h"

int main(){
    getCusDemandData();
    getSiteBW();
    getMaxLatency();
    // ofstream outfile("/output/solution.txt");
    ofstream outfile("out.txt");
    vector<SiteBandWidth> vecTemp=vecSiteBandWidth;
    vector<lastResult> vecResult;
    for(int i=0; i<vecWebStruct.size(); i++){
        for(int j=0; j<numCus; j++){
            if(vecWebStruct[i].arrayBWDemand[j]==0){
                outfile << arrayCusIDs[j] << ':' << endl;
                continue;
            }
            int res=getFirstSitePos(j, i);
            outfile << arrayCusIDs[j] << ':';
            if(res==-1){
                vecResult=lastAssignMethod(j, i);
                for(int l=0; l<vecResult.size()-1; l++){
                    outfile << '<' << vecSiteBandWidth[vecResult[l].posSite].site_name;
                    outfile << ',' << vecResult[l].numBandW << ">,";                    
                }
                outfile << '<' << vecSiteBandWidth[vecResult[vecResult.size()-1].posSite].site_name;
                outfile << ',' << vecResult[vecResult.size()-1].numBandW << '>';                 
            } else {
                outfile << '<' << vecSiteBandWidth[res].site_name;
                outfile << ',' << vecWebStruct[i].arrayBWDemand[j] << '>';
            }
            outfile << endl;
        }
        vecSiteBandWidth=vecTemp;
    }
    return 0;
}
