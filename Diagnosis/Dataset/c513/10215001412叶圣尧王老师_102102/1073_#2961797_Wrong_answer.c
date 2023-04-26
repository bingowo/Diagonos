#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    long long a,b,i;int j,k=0,sum;char s[20];
    for(i=a+1;i<b;i++)
    {
        if(i%9==0){k++;continue;}
        sprintf(s,"%lld",i);
        for(j=0;j<strlen(s);j++)
            if(s[j]=='9'){k++;break;}
    }
    sum=b-a+1-k;
    printf("%d",k);
}