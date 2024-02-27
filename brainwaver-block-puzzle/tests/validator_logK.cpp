#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MIN = -100000;
const int MAX = 100000;

int main(int argc, char *argv[]){
    registerValidation(argc, argv);
    inf.readInt(MIN, MAX, "sx");
    inf.readSpace();
    inf.readInt(MIN, MAX, "sy");
    inf.readSpace();
    inf.readInt(MIN, MAX, "gx");
    inf.readSpace();
    inf.readInt(MIN, MAX, "gy");
    inf.readEoln();
    inf.readEof();
}