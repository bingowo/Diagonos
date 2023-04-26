#include<stdio.h>
int main()
{
    int i,j,k,l=0,ans=0;
    char c;
    long long num[100],f=1;
    while(scanf("%c",&c)!=EOF)
    {
       switch (c)
       {
           case 'I': num[l++]=1*f;break;
           case 'V': num[l++]=5*f;break;
           case 'X': num[l++]=10*f;break;
           case 'L': num[l++]=50*f;break;
           case 'C': num[l++]=100*f;break;
           case 'D': num[l++]=500*f;break;
           case 'M': num[l++]=1000*f;break;
           case '(': f*=1000;break;
           case ')': f/=1000;break;
       }
    }
    for(i=0;i<=l-2;i++)
    {
        if(num[i]<num[i+1])  ans-=num[i];
        else  ans+=num[i];
    }
    ans+=num[l-1];
    printf("%d",ans);
    return 0;
}