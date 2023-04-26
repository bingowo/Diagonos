#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void atob(int a,int ret[])
{
    int i,b;
    for(i=0;i<10;i++) ret[i]=0;
    for(i=0;a!=0;i++)
    {
        b=a%2;
        ret[i]=b;
        a/=2;
    }
}

int main()
{
    char c[505];int i=0,j,ret[10],l=0;
    for(i=0;i<505;i++) for(j=0;j<3;j++) c[i]=-1;
    scanf("%s",c);l=strlen(c);
    atob(l,ret);printf("0001");
    for(i=0;i<10;i++) printf("%d",ret[9-i]);
    for(i=0;c[i+3]!=-1&&c[i+3]!=EOF;i+=3)
    {
        int sum=100*(c[i]-'0')+10*(c[i+1]-'0')+c[i+2]-'0';
        atob(sum,ret);
        for(j=0;j<10;j++) printf("%d",ret[9-j]);
    }
    if(c[i+2]>='0'&&c[i+2]<='9')
    {
        int sum=100*(c[i]-'0')+10*(c[i+1]-'0')+c[i+2]-'0';
        atob(sum,ret);
        for(j=0;j<10;j++) printf("%d",ret[7-j]);
    }
    else if(c[i+1]>='0'&&c[i+1]<='9')
    {
        int sum=10*(c[i]-'0')+c[i+1]-'0';
        atob(sum,ret);
        for(j=0;j<7;j++) printf("%d",ret[6-j]);
    }
    else
    {
        int sum=c[i]-'0';
        atob(sum,ret);
        for(j=0;j<4;j++) printf("%d",ret[3-j]);
    }
    return 0;
}
