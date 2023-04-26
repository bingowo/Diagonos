#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void mul(int*a,int d)
{
    int i,carry=0;
    for(i=0;i<500;i++)
    {
        int t=a[i]*d+carry;
        a[i]=t%10;
        carry=t/10;
    }
}

int main()
{
    char w[1001];scanf("%s",w);
    int d[1001]={0},i,j;
    if(strlen(w)!=1)
        for(i=0;i<strlen(w);i++)
        {
            d[i]++;
            if(i==0){if(w[i]!=w[i+1])d[i]++;}
            else if(i==strlen(w)-1){if(w[i]!=w[i-1])d[i]++;}
            else
            {
                if(w[i]!=w[i-1])d[i]++;
                if(w[i]!=w[i+1])d[i]++;
            }
        }
    int a[500]={0};a[0]=d[0];
    for(j=1;j<i;j++)
        mul(a,d[j]);
    i=499;
    while(a[i]==0)i--;
    for(;i>=0;i--)printf("%d",a[i]);

}
