#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[10000];
    scanf("%s",s);
    char*p=strchr(s,'.');
    long long  a=0;
    long long b=0;

    if (p==NULL)
    {
        int i=0;
        while (i<strlen(s))
        {
            long long t;
            if(s[i]=='2') t=-1;
            else t=s[i]-'0';
            a=a*3+t;
              i++;
        }
        printf("%lld\n",a);

    }
    else
    {   int i;
        for(i=0; s[i]!='.'; i++)
        {
            long long t;
            if(s[i]=='2') t=-1;
            else t=s[i]-'0';
            a=a*3+t;
        }
        i++;
        long long  c=1;
        for (;i<strlen(s);i++){
            long long t;
            if(s[i]=='2') t=-1;
            else t=s[i]-'0';
            b=b*3+t;
            c=c*3;
        }
        if (b<0&&a>0) {b=c+b;a=a-1;}
        else if (b<0&&a<0){b=-b;}
        else if (b>0&&a<0) {b=c-b;a=a+1;}
        if (a!=0)
        printf("%lld %lld %lld\n",a,b,c);
        else printf("%lld %lld\n",b,c);


    }
    return 0;
}
