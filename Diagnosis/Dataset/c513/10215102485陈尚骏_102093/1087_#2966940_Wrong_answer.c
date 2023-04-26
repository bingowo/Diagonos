#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int noReputationTwice;

void solve(char *n)
{
    int len=strlen(n);
    int i,ck=0;
    if(len==1&&n[0]<'9') printf("%c\n",n[0]+1);
    else if(len==1&&n[0]=='9') printf("10\n");
    else
    {
        for(i=0;i<len-1;i++)
        {
            if(n[i]==n[i+1]) break;
            if(i==len-1)
            {
                if(noReputationTwice)
                {
                    for(i=0;i<len;i++) printf("%c",n[i]);
                    printf("\n");
                    return;
                }
                if(n[len-1]=='9')
                {
                    n[len-2]++;
                    n[len-1]='0';
                }
                else n[len-1]++;
                noReputationTwice=1;
                solve(n);
                return;
            }
            else if(n[i]!='9')
            {
                n[i+1]++;
                for(i+=2;i<len;i++)
                {
                    if(ck==0) {n[i]='0';ck=1;}
                    else {n[i]='1';ck=0;}
                }
            }
            else if(i==0)
            {
                printf("1");
                for(i=0;i<len;i++)
                {
                    if(ck==0) {n[i]='0';ck=1;}
                    else {n[i]='1';ck=0;}
                }
            }
            else
            {
                n[i-1]++;
                for(;i<len;i++)
                {
                    if(ck==0) {n[i]='0';ck=1;}
                    else {n[i]='1';ck=0;}
                }
            }
            noReputationTwice=0;
            for(i=0;i<len-1;i++)
            {
                if(n[i]==n[i+1]) break;
            }
            if(i==len-1)
            {
                for(i=0;i<len;i++) printf("%c",n[i]);
                printf("\n");
                return;
            }
            else solve(n);
        }
    }
}

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        noReputationTwice=0;
        char n[121];
        scanf("%s",n);
        printf("case #%d:\n",i);
        solve(n);
    }
    return 0;
}
