# include "testlib.h"
# include <bits/stdc++.h>

std::string lst[] = {
   "Tokyo University of Agriculture and Technology", "TUAT",
   "HyperText Transfer Protocol", "HTTP",
   "Transmission Control Protocol", "TCP",
   "Uniform Resource Locator", "URL",
   "Central Processing Unit", "CPU",
   "Very Long Instruction Word", "VLIW",
   "Redundant Arrays of Inexpensive Disks", "RAID",
   "Static Random Access Memory", "SRAM",
   "Read Only Memory", "ROM",
};

int main(int argc, char* argv[]){
   registerValidation(argc, argv);
   std::string s = inf.readLine();
   bool ok = false;
   for (int i = 0; i < std::size(lst) / 2; i++) {
      ok |= s == lst[2*i];
   }
   inf.ensuref(ok, "in lisst");
   inf.readEof();
   return 0;
}
