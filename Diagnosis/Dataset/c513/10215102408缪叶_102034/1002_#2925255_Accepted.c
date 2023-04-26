#include<stdio.h>
#include<string.h>

int main()
{
    int t;scanf("%d",&t);
    int n[150];
    for(int i=0;i<t;i++)
    {
        for(int i=0;i<150;i++) n[i]=-1;
        char inf[61];
        int t=2,m=1;
        scanf("%s",inf);
        int l=strlen(inf);
        n[inf[0]]=1;
        while (n[inf[m]]==1) m++;
        n[inf[m++]]=0;        
        for(;m<l;m++)
        {
            if(n[inf[m]]==-1) n[inf[m]]=t++;
            else;
        }
        long long pow=1,res=0;
        for(int p=l-1;p>=0;p--)
        {
            res+=n[inf[p]]*pow;
            pow*=t;
        }
        printf("case #%d:\n%lld\n",i,res);
    }

    return 0;
}