#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[40];
    scanf("%s",s);
    long long a,b,qr,qi,r,d=0;
    int result[40];
    char *p=&s[0];
    if (strchr(s,'i')==NULL)
    {
        a=atoll(s);
        b=0;
    }
    else if(strchr(s,'i') && strchr(s,'+')==NULL && strchr(s,'-')==NULL)
    {
        a=0;
        if (s[0]=='i')
            b=1;
        else
            b=atoll(s);
    }
    else if(strrchr(s,'-')==p)
    {
        a=0;b=atoll(s);
    }
    else
    {
        int i=0,temp=0,len=strlen(s);
        char tr[20],ti[20];
        if (s[0]=='-')
            tr[i++]='-';
        while (s[i]!='-' && s[i]!='+')
            {tr[i]=s[i];i++;}
        if (s[i]=='-')
            ti[i]='-';
        a=atoll(tr);
        i++;
        int j=0;
        while (s[j+i]!='i')
            {ti[j]=s[j+i];j++;}
        b=atoll(ti);
    }
    int n=0;
    do
    {
        int r=(a%2+b%2)%2;
        result[n++]=r;
        qr=a;qi=b;
        a=(r-qr+qi)/2;b=(r-qr-qi)/2;
    }while(a!=0||b!=0);
    for(n=n-1;n>=0;n--)
	 	printf("%d",result[n]);
    return 0;
}
