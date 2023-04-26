#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int save[4] = {0};
    char opr[4], s[16];
    while(scanf("%s %s",opr,s) != EOF) {
        int i = s[0] - 'A';
        if(! strcmp(opr, "IN")) {
            save[i] = atoi(&s[3]);
        }else if(! strcmp(opr, "OUT")) {
            printf("%d\n",save[i]);
        }else {
            int j = s[3] - 'A';
            if(! strcmp(opr, "MOV")) save[i] = save[j];
            else switch(opr[0]) {
                case 'A': save[i] += save[j]; break;
                case 'S': save[i] -= save[j]; break;
                case 'M': save[i] *= save[j]; break;
                case 'D': save[i] /= save[j]; break;
            }
        }
    }
    return 0;
}
