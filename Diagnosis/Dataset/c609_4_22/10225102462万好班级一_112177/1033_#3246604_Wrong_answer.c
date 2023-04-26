#include <stdio.h>
#include <string.h>

int main(){
    char s[64]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int loop;scanf("%d",&loop);getchar();
    for (int k = 0; k < loop; ++k) {

        char inp[101]; gets(inp);int arr[808] = {0};

        unsigned int nub = ((strlen(inp))*8)/6;
        if(nub*6 != strlen(inp)*8)nub = nub +1;

        for (int i = 0;inp[i]; ++i)
        {int tmp = (int)inp[i];for (int j = (i+1)*8 - 1; j > i*8 - 1; --j)
            {arr[j] = tmp%2;tmp/=2;}}

        printf("case #0:\n");

        for (int i = 0; i < nub; ++i) {int tmp = 0;
            for (unsigned int j = i*6; j < (i+1)*6; ++j) {
                tmp = tmp*2 + arr[j];}printf("%c",s[tmp]);}

        if((((nub/4) + 1)*4) - nub < 4){for (int i = 0; i < (((nub/4) + 1)*4) - nub ; ++i) {printf("=");}}
        printf("\n");
    }

}