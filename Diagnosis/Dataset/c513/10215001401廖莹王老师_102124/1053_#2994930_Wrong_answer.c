#include <stdio.h>
#include <stdlib.h>
#define N 65536
int time[3];
void gps(char s[150])
{
    int i=0,sum=0,k=0,n=0;
    sum=s[1]^s[2];
    for(i=3;;i++)
    {   if(s[i]=='*')break;
        sum=sum^s[i];
    }
    sum=sum%N;
    for(k=i+1;k<=i+2;k++)
    {
        if(s[k]>='0' && s[k]<='9')n=n*16+s[k]-'0';
        if(s[k]>='A' && s[k]<='Z')n=n*16+s[k]-'A'+10;
    }
    if(sum==n && s[18]=='A')
    {
        time[0]=((s[7]-'0')*10+s[8]-'0'+8)%24;
        time[1]=(s[9]-'0')*10+s[10]-'0';
        time[2]=(s[11]-'0')*10+s[12]-'0';
    }
    return;
}
int main()
{
    while(1)
        {
            char s[150]={0};
            scanf("%s",s);
           if(strcmp(s,"END")==0)break;
           char t[7]={0};strncpy(t,s,6);
           if(strcmp(t,"$GPRMC")!=0)continue;
           else
           {   memset(time,0,sizeof(int)*3);
               gps(s);
           }
        }
        printf("%02d:""%02d:""%02d\n",time[0],time[1],time[2]);
    return 0;
}
