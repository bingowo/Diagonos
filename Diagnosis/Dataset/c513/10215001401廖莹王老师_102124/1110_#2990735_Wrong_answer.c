#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100]={0};
    char c;
    int f=1,i=0;
    double p2=0,p1=0,m=0,re=0;
    scanf("%s",s);
    for(i=0;s[i];)
    {    f=1;m=0;
        if(s[i]=='=')break;
        if(s[i]=='-'){f=-1;i++;} if(s[i]=='+'){f=1;i++;}
        while(isdigit(s[i])){m=m*10+(s[i]-'0');i++;}m=m*f;
        if(s[i]>='a' && s[i]<='z'){c=s[i];p1=p1+m;i++;}else p2=p2+m;
    }
    p2=-p2;
    for(i=i+1;s[i];)
    {    f=1;m=0;
        if(s[i]=='-'){f=-1;i++;} if(s[i]=='+'){f=1;i++;}
        while(isdigit(s[i])){m=m*10+(s[i]-'0');i++;}m=m*f;
        if(s[i]>='a' && s[i]<='z'){c=s[i];p1=p1-m;i++;}else p2=p2+m;
    }
    re=p2/p1;
    printf("%lf %lf\n",p1,p2);
    printf("%c=""%.3lf",c,re);
    return 0;
}
