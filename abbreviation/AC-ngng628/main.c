# include <stdio.h>
# include <ctype.h>

int main(void) {
    char c;
    while ((c = getchar()) != EOF) {
        if (isupper(c)) {
            printf("%c", c);
        }
    }
    printf("\n");
}
