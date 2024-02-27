#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

vector<string> S{
   "Tokyo University of Agriculture and Technology",
   "HyperText Transfer Protocol",
   "Transmission Control Protocol",
   "Uniform Resource Locator",
   "Central Processing Unit",
   "Very Long Instruction Word",
   "Redundant Arrays of Inexpensive Disks",
   "Static Random Access Memory",
   "Read Only Memory",
};

int main(int argc, char* argv[]){
    registerValidation(argc, argv);
    string s = inf.readLine();
    bool ok = false;
    for(auto ss : S){
        ok |= ss == s;
    }
    assert(ok);
    inf.readEof();
}