# include <stdio.h>
# include <string.h>
# include <assert.h>

int main(void) {
   char s[256];
   scanf("%s", s);

   if (strcmp(s, "Tokyo") == 0) {
      printf("TUAT\n");
   }
   else if (strcmp(s, "HyperText") == 0) {
      printf("HTTP\n");
   }
   else if (strcmp(s, "Transmission") == 0) {
      printf("TCP\n");
   }
   else if (strcmp(s, "Uniform") == 0) {
      printf("URL\n");
   }
   else if (strcmp(s, "Central") == 0) {
      printf("CPU\n");
   }
   else if (strcmp(s, "Very") == 0) {
      printf("VLIW\n");
   }
   else if (strcmp(s, "Redundant") == 0) {
      printf("RAID\n");
   }
   else if (strcmp(s, "Static") == 0) {
      printf("SRAM\n");
   }
   else {
      assert(strcmp(s, "Read") == 0);
      printf("ROM\n");
   }

   return 0;
}
