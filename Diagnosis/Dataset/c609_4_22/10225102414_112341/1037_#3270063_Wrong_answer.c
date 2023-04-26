#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c, *I = NULL, *O = NULL;
    int l, s = 0, i, pass;
    I = (char *)malloc(sizeof(char) * 1000000);
    O = (char *)malloc(sizeof(char));
    O[0] = '\0';
    memset(I, '\0', 1000000);
    while(1){
        c = getchar();
        pass = 0;
        l = strlen(I);
        for (i = 0;i < l;i++){
            if (I[i] == c || c == '\n'){
                pass = 1;
                break;
            }
        }
        if (pass == 1){
            s = strlen(O);
            if (s < l){
                free(O);
                O = (char *)malloc(sizeof(char) * (l + 1));
                strcpy(O, I);
            }
            if (c == '\n'){
                break;
            }
            memset(I, '\0', 1000000);
            I[0] = c;
        }else{
            I[l] = c;
        }
    }
    printf("%s", O);
    free(O);free(I);
    return 0;
}