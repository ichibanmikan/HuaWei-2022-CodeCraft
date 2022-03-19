#ifndef __GET_CUSDEMANDDATA_
#define __GET_CUSDEMANDDATA_

#include <iostream>
#include <fstream>
#include <vector>
#include "../lib/WBStruct.h"

using std::vector;
using std::string;

int numCus;                      //The number of customer
string* arrayCusIDs;             //Customer ID
vector<webStruct> vecWebStruct;  //当前时刻和该时刻各客户节点的带宽需求

void getCusDemandData();

#endif