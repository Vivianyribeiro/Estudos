#include <stdio.h>
#include <ctype.h>
#define MAX 50

int main() {
    char string[MAX];
    int entrada;
    int i = 0, maiscula = 0;

    while ((entrada = getchar()) != EOF) {
        if (isalpha(entrada)) { //se e letra maiscula ou minuscula
            if (maiscula == 0) {
                string[i++] = toupper(entrada);
                maiscula = 1;
            } else { 
                string[i++] = tolower(entrada);
                maiscula = 0;
            }
        } else { 
            string[i++] = entrada;
        }

        if (entrada == '\n') {
            string[i] = '\0';
            printf("%s", string);
            i = 0;
            maiscula = 0;
        }
    }

    return 0;
}
