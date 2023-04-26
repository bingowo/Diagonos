#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void gcd(int a,int b)
{
    int a1=a,b1=b;
    while(a%b)
    {
        int tem=a%b;
        a=b;
        b=tem;
    }
    a1/=b;
    b1/=b;
    printf("%d/%d\n",b1,a1);
}
void rou(char * a)
{
    int len=strlen(a);
    int one=0;
    for(int i=0;i<len;i++)
    {
        char tem=a[i];
        while(tem)
        {
            tem=tem&(tem-1);
            one++;
        }
    }
    int x=8*len;
    gcd(x,one);
}
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char a[1000]={'\0'};
        char c;
        int j=0;
        while((c=getchar())!='\n')
            {a[j]=c;j++;}
        rou(a);
    }
    return 0;
}
