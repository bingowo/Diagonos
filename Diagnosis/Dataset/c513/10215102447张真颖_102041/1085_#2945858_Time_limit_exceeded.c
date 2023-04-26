#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sa[501]={0},sb[501]={0};
    while(scanf("%s%s",sa,sb))
    {
        char sr[501]={0};
        int cheat=0,sign=1;
        if(strlen(sa)<strlen(sb))
        {
            sign=-1;
            char t[501]={0};
            strcpy(t,sa);
            strcpy(sa,sb);
            strcpy(sb,t);
        }
        else if(strlen(sa)==strlen(sb))
        {
            for(int i=0;i<strlen(sa);i++)
            {
                if(sa[i]>sb[i]) break;
                else if(sa[i]<sb[i])
                {
                    sign=-1;
                    char t[501]={0};
                    strcpy(t,sa);
                    strcpy(sa,sb);
                    strcpy(sb,t);
                }
            }
        }
        for(int i=strlen(sa)-1,j=strlen(sb)-1;i>=0;i--)
        {
            if(j>=0)
            {
                int a=sa[i]-'0'-cheat,b=sb[j]-'0';
                if(a<b) cheat=1;
                else cheat=0;
                sr[i]=a+cheat*10-b+'0';
                j--;
            }
            else
            {
                int a=sa[i]-'0'-cheat,b=0;
                if(a<0) cheat=1;
                else cheat=0;
                sr[i]=a+cheat*10-b+'0';
            }
        }
        if(sign==-1) printf("-");
        sign=0;
        for(int i=0;i<strlen(sr);i++)
        {
            if(sr[i]=='0'&&sign==0);
            else
            {
                printf("%c",sr[i]);
                sign=1;
            }
        }
        printf("\n");
    }
    return 0;
}