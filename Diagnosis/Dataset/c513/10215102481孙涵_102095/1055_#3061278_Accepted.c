#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000001];
    char charTable[256] = {0};
    int max = 0;
    int pll,plr;;
    scanf("%s",s);
    int i,j,length = 0;;
    int len = strlen(s);
    for(i = 0; i < len; i++){
        for(j = i; j < len; j++){
            if(charTable[s[j]] == 0){
                charTable[s[j]] = 1;
                length++;
            }else{
                break;
            }
            if(length > max){
                pll = i;
                plr = j;
                max = length;
            }
        }
        length = 0;
        for(int l = 0; l < 256; l++){
            charTable[l] = 0;
        }
    }
    int k ;
    if(plr == len - 1){
        plr = plr + 1;
    }
    for(k = pll; k <= plr; k++){
        printf("%c",s[k]);
    }
    return 0;
}
