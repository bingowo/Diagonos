#include <stdio.h>
int main()
{
    char s[100];
    scanf("%s",s);
    char *p=s;
    long long a=0,b=0;
    int flag1=0,flag2=0;
    if((*p)=='-'){flag1=1;p++;}
    while(((*p)!='+')&&((*p)!='-'))
    {
        a=a*10+((*p)-'0');
        p++;
    }
    if(flag1==1) a=-a;
    if((*p)=='-'){flag2=1;p++;}
    while((*p)!='i')
    {
        b=b*10+(*p-'0');
        p++;
    }
    if(flag2==1) b=-b;
    int r[100];
    int qr,qi,j=0;
    while(a!=0)
    {
        if(((a+b)%2)==1) r[j]=1;
        else r[j]=0;
        qr=(r[j]-a+b)/2;
        qi=(r[j]-a-b)/2;
        a=qr;
        b=qi;
        j++;
    }
    for(int m=j;m>=0;m--)
    printf("%d",r[m]);
    return 0;
}
