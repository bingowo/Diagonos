#include <string.h>
#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int q=0;q<cnt;q++)
    {
        char s1[80];
        char s2[80];
        char s[80];
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s);
        int ins1=0,ins2=0;
        int L1[80]={-1},L2[80]={-1};
        int m=0,n=0;
        int max= strlen(s1)>strlen(s2)?strlen(s1):strlen(s2);
        for(int i=0;i<=(int)strlen(s)-max;i++)
        {
            if(s[i]==s1[0])
            {
                for(int k=1;s1[k]!='\0';k++)
                {
                    if(s[i+k]!=s1[k]) {ins1=-1;break;}
                }
                if(ins1==0) L1[m++]=i;
                ins1=0;
            }
            if(s[i]==s2[0])
            {
                for(int k=1;s2[k]!='\0';k++)
                {
                    if(s[i+k]!=s2[k]) {ins2=-1;break;}
                }
                if(ins2==0) L2[n++]=i;
                ins2=0;
            }
        }
        int tem=0,length=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(L1[i]>L2[j]) tem=L1[i]-(L2[j]+(int)strlen(s2));
                else tem=L2[j]-(L1[i]+(int)strlen(s1));
                length = length>tem ? length:tem;
                tem=0;
            }
        }
        printf("case #%d:\n",q);
        printf("%d\n",length);
    }
    return 0;
}