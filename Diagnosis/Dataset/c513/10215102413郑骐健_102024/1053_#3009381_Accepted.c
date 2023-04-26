#include <stdio.h>
#include <stdlib.h>
int main()
{
    char s[2000];
    int time[3];
    while(scanf("%s",s))
    {
        if(!strcmp(s,"END"))break;
        for(int i=0;i<strlen(s);i++)
        {
            s[i] = (s[i]==',')?' ':s[i];
        }
        char s0[2000];
        if(sscanf(s,"%s",s0))
        {
            if(strcmp("$GPRMC",s0))continue;
        }
        else continue;
        char p9[200];
        sscanf(s,"%*s%*s%s",p9);
        if(strcmp(p9,"A"))continue;
        char *p = strchr(s,'*');
        if(p==NULL)continue;
        int res;
        sscanf(p+1,"%X",&res);
        char mid = s[1];
        int po=2;
        for(;po<(p-&s[0]);po++)
        {
            mid = mid^s[po];
        }
        if(mid==res)
        {
        char s1[8];
        sscanf(s,"%*s%s",s1);
        int t=0;
        for(int i =0;i<3;t=0,i++)
        {
            t= (s1[i*2]-'0')*10 +s1[i*2+1]-'0';
            if(i==0)t=(t+8)%24;
            time[i] =t;
        }
        }
        else continue;
    }
    for(int q=0;q<3;q++)
    {
        if(time[q]<10)printf("0%d",time[q]);
        else printf("%d",time[q]);
        if(q!=2)printf(":");
    }
    return 0;
}
