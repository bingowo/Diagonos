#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[5000];
    scanf("%s",s);
    long long a,b,qr,qi,r,d=0;
    long long result[40];
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
    else if(strrchr(s,'-')==p&&strchr(s,'+')==NULL)
    {
        a=0;b=atoll(s);
    }
    else
    {
        int i=0,j=0,temp=0,len=strlen(s),flag=1;
        char tr[20],ti[20];
        if (s[0]=='-')
            tr[i++]='-';
        while (s[i]!='-' && s[i]!='+')
            {tr[i]=s[i];i++;}
        if (s[i]=='-')
            flag=-1;
        a=atoll(tr);
        i++;
        while (s[j+i]!='i')
            {ti[j]=s[j+i];j++;}
        if (j==0) ti[j]='1';
        b=atoll(ti)*flag;
    }
    long long i[5000]={0};
    int n=0;
    do
    {
	  if ((a-b)%2) r=1;
	  else r=0;
	  i[n++]=r;
	  qr=a;
	  qi=b;
	  a=(r-qr+qi)/2,b=(r-qr-qi)/2;
	 }while(a!=0||b!=0);
	 for(n=n-1;n>=0;n--){
	 	printf("%lld",i[n]);
	 }
		return 0;
}
