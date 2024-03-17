# include "testlib.h"
# include <bits/stdc++.h>

const int N_MIN = 1;
const int N_MAX = 365;
const int ABC_MIN = 0;
const int ABC_MAX = 300;
const int XYZ_MIN = 0;
const int XYZ_MAX = 300;

int main(int argc, char* argv[]) {
   registerValidation(argc, argv);

   int N = inf.readInt(N_MIN, N_MAX, "N");
   inf.readEoln();

   int X = inf.readInt(XYZ_MIN, XYZ_MAX, "X");
   inf.readSpace();
   int Y = inf.readInt(XYZ_MIN, XYZ_MAX, "Y");
   inf.readSpace();
   int Z = inf.readInt(XYZ_MIN, XYZ_MAX, "Z");
   inf.readEoln();

   auto A = inf.readInts(N, ABC_MIN, ABC_MAX, "A");
   inf.readEoln();
   auto B = inf.readInts(N, ABC_MIN, ABC_MAX, "B");
   inf.readEoln();
   auto C = inf.readInts(N, ABC_MIN, ABC_MAX, "C");
   inf.readEoln();

   inf.readEof();
   return 0;
}
