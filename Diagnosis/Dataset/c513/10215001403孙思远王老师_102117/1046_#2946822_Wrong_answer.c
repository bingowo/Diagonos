#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        int all=0;
        printf("case #%d:\n",t);
        char s[101];
        char f1[4]="the",f2[2]="a",f3[3]="an",f4[3]="of",f5[4]="for",f6[4]="and";
        while(scanf("%s",s)!=EOF)
        {
            if(strcmp(s,f1)!=0&&strcmp(s,f2)!=0&&strcmp(s,f3)!=0&&strcmp(s,f4)!=0&&strcmp(s,f5)!=0&&strcmp(s,f6)!=0)
                all++;
        }
        printf("%d\n",all);
    }
    return 0;
}
