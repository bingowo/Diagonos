#include<stdio.h>
#include<string.h>
int main()
{
    char s0[8000000000];
    scanf("%s",s0);
    long long q=0;
    if(s0[2]=='0')
    {
        printf("0");
        return 0;
    }
    for(int i=2;i<strlen(s0);i++)
    {
        if(s0[i]>=48&&s0[i]<=57)
        {
            q=q*16+s0[i]-48;
        }
        else
        {
            q=q*16+s0[i]-55;
        }
    }
    /*printf("%d\n",q);*/
    char s[800000000]={'\0'};
    long long i=0;
    while(q!=0)
    {
        s[i]=q%2;
        q=q/2;
        i++;
    }
   /* printf("%d\n",i);*/
    long long a=1;
    long long b=0;
    long long a1;
    long long b1;
    for(long long j=i-2;j>=0;j--)
    {
        a1=a;
        b1=b;
        a=s[j]-a1-b1;
        b=a1-b1;
    }
    /*printf("%d %d\n",a,b);*/
    if(a!=0){
    if(b<0)
    {
        if(b==-1)
        {
            printf("%lld-i",a);
            return 0;
        }
        printf("%lld%-lldi",a,b);
        return 0;
    }
    if(b==0)
    {
        printf("%lld",a);
        return 0;
    }
    if(b>0)
    {
        if(b==1)
        {
            printf("%lld+i",a);
            return 0;
        }
        printf("%lld+%lldi",a,b);
        return 0;
    }
    }
    else
    {
        if(b==1)
        {
            printf("i");
            return 0;
        }
        if(b==-1)
        {
            printf("-i");
            return 0;
        }
        printf("%lldi",b);
        return 0;
    }
}
