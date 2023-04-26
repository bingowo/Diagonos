#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int saver[26] = {0};
    char opr[5], s[16];
    while(scanf("%s %s",opr, s) != EOF) {
        int k = s[0] - 'A';
        if(! strcmp(opr, "IN")){
            saver[k] = atoi(&s[3]);
        }else if(! strcmp(opr, "OUT")){
            printf("%d\n",saver[k]);
        }else if(strlen(s) == 5){
            int i = s[3] - 'A';
            if(! strcmp(opr, "MOV")) saver[k] = saver[i];
            else if(! strcmp(opr, "XCHR")){
                int temp=saver[k]; saver[k]=saver[i]; saver[i]=temp;
            }else if(! strcmp(opr, "AND"))
                saver[k] &= saver[i];
            else if(! strcmp(opr, "MOD"))
                saver[k] %= saver[i];
            else switch(opr[0]) {
                case 'A': saver[k] += saver[i]; break;
                case 'S': saver[k] -= saver[i]; break;
                case 'M': saver[k] *= saver[i]; break;
                case 'D': saver[k] /= saver[i]; break;
                case 'O': saver[k] |= saver[i]; break;
                case 'X': saver[k] ^= saver[i]; break;
            }
        }else {
            int i = s[3]-'A', j = s[6]-'A';
            if(! strcmp(opr, "AND"))
                saver[k] = saver[i] & saver[j];
            else if(! strcmp(opr, "MOD"))
                saver[k] = saver[i] % saver[j];
            else switch(opr[0]) {
                case 'A': saver[k] = saver[i] + saver[j]; break;
                case 'S': saver[k] = saver[i] - saver[j]; break;
                case 'M': saver[k] = saver[i] * saver[j]; break;
                case 'D': saver[k] = saver[i] / saver[j]; break;
                case 'O': saver[k] = saver[i] | saver[j]; break;
                case 'X': saver[k] = saver[i] ^ saver[j]; break;
            }
        }
    }
    return 0;
}
