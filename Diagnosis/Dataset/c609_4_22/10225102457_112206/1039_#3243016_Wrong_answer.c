#include <stdio.h>
#include<string.h>
#include <stdlib.h>

int main(void)
{
    int T;
    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        char in1[81], in2[81], se[81];
        scanf("%s%s%s",in1,in2,se);

        char *i1,*i2;
        i1 = strstr(se,in1);
        i2 = strstr(se,in2);
        if(i1 == NULL || i2 == NULL){
            printf("case #%d:\n",i);
            printf("0\n");
            continue;
        }

        unsigned maxdis = abs(i1 - i2) - (i1 > i2? strlen(in2): i1 < i2?strlen(in1):0);

        char *temp = strstr(se,in1);
        int v;
        for(v = 1; temp != NULL; v++){
            i1 = temp;
            temp = strstr(i1+1,in1);
        }
        if(abs(i1 - i2) - (i1 > i2? strlen(in2): i1 < i2?strlen(in1):0) > maxdis) maxdis = abs(i1 - i2) - (i1 > i2? strlen(in2): i1 < i2?strlen(in1):0);

        i1 = strstr(se,in1);
        temp = strstr(se,in2);
        for(v = 1; temp != NULL; v++){
            i2 = temp;
            temp = strstr(i2+1,in2);
        }
        if(abs(i1 - i2) - (i1 > i2? strlen(in2): i1 < i2?strlen(in1):0) > maxdis) maxdis = abs(i1 - i2) - (i1 > i2? strlen(in2): i1 < i2?strlen(in1):0);

        printf("case #%d:\n",i);
        printf("%u\n",maxdis);
    }
    return 0;
}