#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

vector<string> T = {
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

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    string S = inf.readLine();
    inf.readEof();
    bool flag = false;
    for (auto& t : T) {
        if (S == t)
            flag = true;
    }
    assert(flag);
    return 0;
}