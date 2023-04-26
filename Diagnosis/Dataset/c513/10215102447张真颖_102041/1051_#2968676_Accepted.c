#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char form[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[101]={0};
        scanf("%s",s);
        int sb[820]={0},cnt=819,len=strlen(s)*8;
        while(len%6)
        {
            len++;
            sb[cnt]=0;
            cnt--;
        }
        for(int i=strlen(s)-1;i>=0;i--)
        {
            int tmp=s[i];
            for(int j=0;j<8;j++,cnt--)
            {
                if(tmp>0)
                {
                    sb[cnt]=tmp%2;
                    tmp/=2;
                }
                else sb[cnt]=0;
            }
        }
        char r[200]={0};
        cnt+=1;
        for(int i=0;;i++)
        {
            int t=0;
            for(int j=0;j<6;j++)
            {
                t=t*2+sb[cnt];
                cnt++;
            }
            r[i]=form[t];
            if(cnt==820) break;
        }
        while(strlen(r)%4)
            strcat(r,"=");
        printf("case #%d:\n%s\n",i,r);
    }
    return 0;
}