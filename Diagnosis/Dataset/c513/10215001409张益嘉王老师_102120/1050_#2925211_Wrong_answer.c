#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strhou(char* zong,char *s)
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
            if(co==lens) return i;
            else continue;

        }
    }
    return -1;
}

int strqian(char* zong,char *s)
{
    int lenzong=strlen(zong),lens=strlen(s),i,j,k,co;
    for(i=0;i<lenzong;i++)
    {
        j=0;
        if(s[j]==zong[i])
        {
            co=0;
            for(j=0,k=i;j<lens;j++,k++)
            {
                if(s[j]==zong[k]) co++;
                else break;
            }
            if(co==lens) return i;
            else continue;

        }
    }
    return -1;
}

int jianju(char a[],char b[],char zong[])
{
    int re;
    int qian=strqian(zong,a);
    qian=qian+strlen(a);
    printf("test: qian=%d\n",qian);
    int hou=strhou(zong,b);
    hou=hou-strlen(b);
    printf("test: hou=%d\n",hou);
    re=hou-qian+1;
    if(hou==-1) return 0;
    else if(qian==-1) return 0;
    else if(re<1)
    {
        return jianju(b,a,zong);
    }
    else return re;

}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char zong[100],a[100],b[100];
        int re,ans;
        scanf("%s%s%s",a,b,zong);
        ans=jianju(a,b,zong);

        printf("case #%d:\n%d\n",i,ans);

    }
    return 0;
}
