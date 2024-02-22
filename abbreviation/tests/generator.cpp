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
   registerGen(argc, argv, 1);

   // サンプル
   {
      std::ofstream of("00_sample_01.in");
      of << "Tokyo University of Agriculture and Technology" << std::endl;
      of.close();
   }

   {
      std::ofstream of("00_sample_02.in");
      of << "Read Only Memory" << std::endl;
      of.close();
   }

   for (int ts = 1; ts < std::size(lst) / 2; ts++) {
      std::ofstream of(format("01_all_%02d", ts).c_str());
      of << lst[2*ts] << std::endl;
      of.close();
   }

   return 0;
}
