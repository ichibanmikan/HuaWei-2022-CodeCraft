#include "getSiteBW.h"

using std::ifstream;
using std::getline;
// using std::cout;
// using std::endl;
using std::string;

void getSiteBW(){ 
    // ifstream infile_qos("/mnt/d/OneDrive - hnu.edu.cn/mylearn/HWSC/线下调试数据/线下调试数据/data/qos.csv");
    // ifstream infile_site_bandwidth("/mnt/d/OneDrive - hnu.edu.cn/mylearn/HWSC/线下调试数据/线下调试数据/data/site_bandwidth.csv");
    ifstream infile_qos("/data/qos.csv");
    ifstream infile_site_bandwidth("/data/site_bandwidth.csv");
    // ifstream infile_qos("/mnt/d/OneDrive - hnu.edu.cn/mylearn/HWSC/SDK/SDK_C++/CodeCraft2022-benchmark/data/qos.csv");
    // ifstream infile_site_bandwidth("/mnt/d/OneDrive - hnu.edu.cn/mylearn/HWSC/SDK/SDK_C++/CodeCraft2022-benchmark/data/site_bandwidth.csv");
    string strHead;
    getline(infile_site_bandwidth, strHead);
    string eveLineSB;
    numSite=0;
    while(getline(infile_site_bandwidth, eveLineSB)){
        numSite++;
        SiteBandWidth sbw;
        sbw.arraySiteCusLatency=new int [40];
        int pos=0;
        for(int i=0; i<eveLineSB.size(); i++){
            if(eveLineSB[i]!=','){
                sbw.site_name+=eveLineSB[i];
                continue;
            }
            pos=i;
            break;
        }
        string strTemp=eveLineSB.substr(pos+1);
        sbw.bandWidth=stoi(strTemp);
        vecSiteBandWidth.push_back(sbw);
    }
    string qosHead;
    getline(infile_qos, qosHead);
    string eveLineQOS;
    int posSiteLate=0;
    while(getline(infile_qos, eveLineQOS)){
        int pos;
        for(int i=0; i<eveLineQOS.size(); i++){
            if(eveLineQOS[i]==','){
                pos=i;
                break;
            }
        }
        string strNumLatency;
        int numThisSiteCus=0;
        for(int i=pos+1; i<eveLineQOS.size(); i++){
            if(eveLineQOS[i]!=','){
                strNumLatency+=eveLineQOS[i];
                continue;
            }
            vecSiteBandWidth[posSiteLate].arraySiteCusLatency[numThisSiteCus]=stoi(strNumLatency);
            numThisSiteCus++;
            strNumLatency="";
        }
        // cout << strNumLatency << ' ' << numThisSiteCus << endl;
        vecSiteBandWidth[posSiteLate].arraySiteCusLatency[numThisSiteCus]=stoi(strNumLatency);
        posSiteLate++;
    }
}