#include<stdio.h>
#include<string.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char num[100];scanf("%s",num);
        int l=strlen(num)-1,pow=1,res=0;
        for(;l>=0;l--)
        {
            if(num[l]=='0');
            else if(num[l]=='-') res+=-1*pow;
            else res+=pow;
            pow*=3;
        }
        printf("case #%d:\n%d\n",i,res);
    }

    return 0;
}