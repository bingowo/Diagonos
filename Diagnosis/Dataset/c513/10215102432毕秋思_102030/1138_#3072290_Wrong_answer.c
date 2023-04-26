#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void itob(long long n,int b,char *str)
{
    char s[]="0123456789ABCDEF";
    int j,i=100;
    char buf[i+1];
    buf[100]='\0';
    while(n!=0)
    {
        buf[--i]=s[n%b];
        n/=b;
    }
    for(j=0;(*(str+j)=buf[i])!='\0';j++,i++);
}

int main()
{
    int a,b;
    char n[100],ans[100];
    scanf("%d%s%d",&a,&n,&b);
    long long t=0;
    int len=strlen(n);
    for(int i=0;i<len;i++)
    {
        if(n[i]>='a'&&n[i]<='f')
        {
            n[i]-=87;
        }
        else if(n[i]>='A'&&n[i]<='F')
        {
            n[i]-=55;
        }
        else
        {
            n[i]-='0';
        }
        t=t*a+n[i];
    }
    itob(t,b,ans);
    printf("%s\n",ans);
    return 0;
}
