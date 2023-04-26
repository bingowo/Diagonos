#include <stdio.h>
#include <math.h> 
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        const int k=8;
        double sum=0;
        int num=0;
        char s[52];
        scanf("%s",s);
        for(int t=2;s[t]!='\0';t++)
        {
            num++;
            sum+=(s[t]-'0')/(pow(k,t-1));
        }
        printf("case #%d:\n",i);
        printf("%*.g",3*num,sum);
    }
    return 0;
}