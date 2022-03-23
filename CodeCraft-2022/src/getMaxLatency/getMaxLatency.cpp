#include "getMaxLatency.h"

using std::ifstream;
using std::string;

void getMaxLatency(){
    // ifstream infile("/mnt/d/OneDrive - hnu.edu.cn/mylearn/HWSC/线下调试数据/线下调试数据/data/config.ini");
    ifstream infile("/data/config.ini");
    // ifstream infile("/mnt/d/OneDrive - hnu.edu.cn/mylearn/HWSC/SDK/SDK_C++/CodeCraft2022-benchmark/data/config.ini");
    string lineHead;
    string lineNext;
    getline(infile, lineHead);
    getline(infile, lineNext);
    string str=lineNext.substr(15);
    LATENCY_MAX=stoi(str);
}