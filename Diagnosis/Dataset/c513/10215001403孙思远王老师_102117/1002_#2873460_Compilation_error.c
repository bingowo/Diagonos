#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int an,i,n,all=0;
    char s[100];
    scanf("%d",&an);
    for(i=0;i<an;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",s);
        int a[128];
        for (i=0;i<128;i++)
            a[i]=-1;
        int digit=0,N=1,i;
        char *p=s;
        a[*p]=1;
        while (*++p)
         if (a[*p]==-1)
        {
            a[*p]=digit;
            digit=digit?digit+1:2;
            N++;
        }
        if(N<2) N=2;
        while(*p)
        {
            all=all*N+a[*p++];#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int an,i,n,all=0;
    char s[100];
    scanf("%d",&an);
    for(i=0;i<an;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",s);
        int a[128];
        for (i=0;i<128;i++)
            a[i]=-1;
        int digit=0,N=1,i;
        char *p=s;
        a[*p]=1;
        while (*++p)
         if (a[*p]==-1)
        {
            a[*p]=digit;
            digit=digit?digit+1:2;
            N++;
        }
        if(N<2) N=2;
        p=s;
        while(*p)
        {
            all=all*N+a[*p++];
        }
        printf("%d\n",all);
    }
    return 0;
}

        }
        printf("%d\n",all);
    }
    return 0;
}
