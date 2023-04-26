#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void d(char sa[],char sb[],char sr[])
{
        int cheat=0;
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
}

int main()
{
    char sa[501]={0},sb[501]={0};
    while(scanf("%s%s",sa,sb))
    {
        char sr[501]={0};
        if(strcmp(sa,sb)==0) printf("0");
        else if(strcmp(sa,sb)<0)
        {
            d(sb,sa,sr);
            printf("-");
            int i=0;
            while(sr[i]=='0') i++;
            for(;i<strlen(sr);i++)
               printf("%c",sr[i]);
            printf("\n");
        }
        else
        {
            d(sa,sb,sr);
            int i=0;
            while(sr[i]=='0') i++;
            for(;i<strlen(sr);i++)
               printf("%c",sr[i]);
            printf("\n");
        }
    }
    return 0;
}