#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <cstdio>
#include <format>
#include <initializer_list>
#include <unordered_set>
#include <cmath>

using namespace std;
#define pb push_back


int main()
{
  int numofboxes;
  cin>>numofboxes;

  int boxes[numofboxes][3];
  for(int i = 0; i < numofboxes; i++){
    for(int j = 0; j < 3; j++){
      cin>>boxes[i][j];
    }
    sort(boxes[i], boxes[i]+3);
  }

  int numofpackages;
  cin>>numofpackages;
  int packages[numofpackages][3];
  for(int i = 0; i < numofpackages; i++){
    for(int j = 0; j < 3; j++){
      cin>>packages[i][j];
    }
    sort(packages[i], packages[i]+3);
    bool condition = true;
    int smallest = 1000000000;
    for(int j = 0; j < numofboxes; j++){
      if(packages[i][0]<=boxes[j][0]&&packages[i][1]<=boxes[j][1]&&packages[i][2]<=boxes[j][2]){
        // cout<<boxes[j][0]*boxes[j][1]*boxes[j][2]<<"\n";
        if(smallest>boxes[j][0]*boxes[j][1]*boxes[j][2]){
          smallest = boxes[j][0]*boxes[j][1]*boxes[j][2];
        }
        condition = false;
      }
    }
    if(condition){
      cout<<"Item does not fit.\n";
    }
    else{
      cout<<smallest<<"\n";
    }
  }
  return 0;
}