#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long pows(long long x,long long y)
{
    long long z=x;
    for(int i=0;i<y-1;i++)x=x*z;
    if(y==0)x=1;
    return x;
}

long long gys(long long x,long long y)
{
    long long temp;
    if(x<y){temp=x;x=y;y=temp;}
    while(y!=0)
    {
        temp=x%y;
        x=y;y=temp;
    }return x;
}

int main()
{
    long long pows(long long x,long long y);long long gys(long long x,long long y);
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[17];scanf("%s",s);long long a=0,b=0,c=0,j,kb=0,kc=0;
        for(j=0;j<strlen(s);j++)
        {
            if(s[j]=='.')
            {char s1[17];strncpy(s1,s,j);s1[j]='\0';a=atol(s1);break;}
        }j++;
        for(;j<strlen(s);j++)
        {
            if(isdigit(s[j])){b=b*10+s[j]-'0';kb++;}
            else break;
        }
        if(j==strlen(s)){c=0;kc=0;}
        else
        {
            j++;
            for(;j<strlen(s)-1;j++)
            {
                c=c*10+s[j]-'0';kc++;
            }
        }
        long long d1,d2;
        if(kc!=0)
        {
            d1=b*pows(10,kc)-b+c;
            d2=pows(10,kb)*(pows(10,kc)-1);
        }
        else
        {
            d1=b;d2=pows(10,kb);
        }
        long long m=gys(d1,d2);
        d1=d1/m;d2=d2/m;
        printf("case #%d:\n",i);
        printf("%lld/%lld\n",d1+d2*a,d2);
    }
}
