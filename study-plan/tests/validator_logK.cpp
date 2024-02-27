#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MIN_N = 1;
const int MAX_N = 60;
const int MIN_XYZ = 1;
const int MAX_XYZ = 100;
const int MIN_ABC = 0;
const int MAX_ABC = 100;

int main(int argc, char *argv[]){
    registerValidation(argc, argv);
    int N = inf.readInt(MIN_N, MAX_N, "N"); inf.readEoln();
    inf.readInt(MIN_XYZ, MAX_XYZ, "X"); inf.readSpace();
    inf.readInt(MIN_XYZ, MAX_XYZ, "Y"); inf.readSpace();
    inf.readInt(MIN_XYZ, MAX_XYZ, "Z"); inf.readEoln();
    inf.readIntegers(N, MIN_ABC, MAX_ABC, "A_i"); inf.readEoln();
    inf.readIntegers(N, MIN_ABC, MAX_ABC, "B_i"); inf.readEoln();
    inf.readIntegers(N, MIN_ABC, MAX_ABC, "C_i"); inf.readEoln();
    inf.readEof();
}