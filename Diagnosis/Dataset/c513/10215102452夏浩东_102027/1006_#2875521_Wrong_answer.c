#include <stdio.h>
#include <math.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[100];
        int L[100];
        scanf("%s",s);
        long long int num=0;
        int count=0;
        for(int t=0;s[t]!='\0';t++)
        {
            if(s[t]=='-') L[t]=-1;
            else if(s[t]=='1') L[t]=1;
            else L[t]=0;
            count++;
        }
        for(int t=count;t>=0;t--)
        {
            num+=pow(3,(count-t))*L[t];
        }
        printf("case #%d\n",i);
        printf("%lld\n",num);
    }
    return 0;
}