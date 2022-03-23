#include "getCusDemandData.h"

using std::ifstream;
using std::string;
using std::getline;
using std::vector;
using std::string;

void getCusDemandData() {
    // ifstream infile("/mnt/d/OneDrive - hnu.edu.cn/mylearn/HWSC/线下调试数据/线下调试数据/data/demand.csv");
    ifstream infile("/data/demand.csv");
    // ifstream infile("/mnt/d/OneDrive - hnu.edu.cn/mylearn/HWSC/SDK/SDK_C++/CodeCraft2022-benchmark/data/demand.csv");
    string lineHead;
    getline(infile, lineHead);
    // cout << lineHead << endl;
    arrayCusIDs=new string [40];
    // cout << lineHead.size() << endl;
    for(int i=6; i<lineHead.size()-1; i++){
        if(lineHead[i]!=','){
            arrayCusIDs[numCus]+=lineHead[i];
            continue;
        }
        numCus++;
    }
    numCus++;
    string eveLine;
    while(getline(infile, eveLine)){
        webStruct wsTemp;
        int pos;
        for(int i=0; i<eveLine.size(); i++){
            if(eveLine[i]==','){
                pos=i;
                break;
            }
            wsTemp.mtime+=eveLine[i];
        }
        wsTemp.arrayBWDemand=new int [numCus+5];
        string strBW;
        int posEveNum=0;
        for(int i=pos+1; i<eveLine.size(); i++){
            if(eveLine[i]!=','){
                strBW+=eveLine[i];
                continue;
            }
            int bandWidth=stoi(strBW);
            wsTemp.arrayBWDemand[posEveNum]=bandWidth;
            strBW="";
            posEveNum++;
        }
        int bandWidth=stoi(strBW);
        wsTemp.arrayBWDemand[posEveNum]=bandWidth;
        vecWebStruct.push_back(wsTemp);
    }
}
