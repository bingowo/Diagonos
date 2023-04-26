#include <stdio.h>
#include <string.h>
int noReputationTwice;
void solve(char *num)
{
    int l=strlen(num), check=0, i;
    if(l==1 && num[0]<'9') printf("%c\n",num[0]+1);
    else if(l==1 && num[0]=='9') printf("10\n");
    else
    {
        for(i=0; i<l-1; i++) if(num[i]==num[i+1]) break;
        if(i==l-1)
        {
            if(noReputationTwice)
            {
                for(i=0; i<l; i++) printf("%c",num[i]); printf("\n");
                return;
            }
            if(num[l-1]=='9') {num[l-2]++; num[l-1]='0';}
            else num[l-1]++;
            noReputationTwice=1;
            solve(num);
            return;
        }
        else if(num[i]!='9')
        {
            num[i+1]++;
            for(i+=2; i<l; i++)
            {
                if(check==0) {num[i]='0'; check=1;}
                else {num[i]='1'; check=0;}
            }
        }
        else if(i==0)
        {
            printf("1");
            for(i=0; i<l; i++)
            {
                if(check==0) {num[i]='0'; check=1;}
                else {num[i]='1'; check=0;}
            }
        }
        else
        {
            num[i-1]++;
            for(; i<l; i++)
            {
                if(check==0) {num[i]='0'; check=1;}
                else {num[i]='1'; check=0;}
            }
        }
        noReputationTwice=0;
        for(i=0; i<l-1; i++) if(num[i]==num[i+1]) break;
        if(i==l-1) 
        {
            for(i=0; i<l; i++) printf("%c",num[i]); printf("\n");
            return;
        }
        else solve(num);
    }
}
int main()
{
    int T, I;
    scanf("%d",&T);
    for(I=0; I<T; I++)
    {
        noReputationTwice=0;
        char num[120];
        int i;
        scanf("%s",num);
        printf("case #%d:\n",I);
        solve(num);
    }
    return 0;
}