#include <stdio.h>
#include <stdlib.h>
int m=0;
int jiayi(int g[500],int k)
{
    int i=0,p=0,q=1;
    for(i=k+1;i<=m;i++)
    {
        p=g[i]+q;
        if(p<=9){g[i]=p;return i;}
        else
        {
            g[i]=p%10;q=p/10;
        }
    }
    if(q>0){m++;g[m]=q;}
    return m;

}
int main()
{
    char s[500]={0};
    int g[500]={0};
    scanf("%s",s);
    int i=0,j=0,count=0,sum=0;
    m=strlen(s)-1;
    for(i=m;i>=0;i--){g[m-i]=s[i]-'0';}
    jiayi(g,-1);
    while(count<=m)
    {
        for(i=m;i>=count;i--){if(g[i]==9)count=jiayi(g,i);}
        if(count==j)break;
        j=count;
    }
    if(count!=0){for(i=count-1;i>=0;i--)g[i]=0;}
    while(1)
    {
        for(i=0;i<=m;i++)sum=sum+g[i];
        if(sum%9==0){jiayi(g,-1);}
        else break;
    }
    for(i=0;i<=m;i++)printf("%d",g[m-i]);
    return 0;
}
