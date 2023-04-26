#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cas; scanf("%d",&cas);
    int hash[256]; hash['-']=-1; hash['0']=0; hash['1']=1;
    for(int i=0;i<cas;i++)
    {
        char s[27]; int N=0; char* p=s; scanf("%s",s);
        while(*p)
        {
            N = N*3 + hash[*p];
            p++;
        }
        printf("case #%d:\n",i);
        printf("%d",N);
        printf(i==cas-1? " ":"\n");
    }
    return 0;
}

