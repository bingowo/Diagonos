#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strhou(char* zong,char *s)
{
    int lenzong=strlen(zong),lens=strlen(s),i,j,k,co;
    for(i=lenzong-1;i>=0;i--)
    {
        j=lens-1;
        if(s[j]==zong[i])
        {
            co=0;
            for(j=lens-1,k=i;j>=0;j--,k--)
            {
                if(s[j]==zong[k]) co++;
                else break;
            }
            if(co==lens) return &zong[i];
            else continue;

        }
    }
    return 0;
}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char zong[100],a[100],b[100];
        int re;
        scanf("%s%s%s",a,b,zong);
        char* qian=strstr(zong,a);
        qian=qian+strlen(a);
        char* hou=strhou(zong,b);
        hou=hou-strlen(b);
        re=hou-qian+1;
        printf("case #%d:\n%d\n",i,re);

    }
    return 0;
}
