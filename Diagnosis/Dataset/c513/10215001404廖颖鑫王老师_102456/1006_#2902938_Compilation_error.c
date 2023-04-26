#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int kk(char* m);
int kkr(char m);

int main()
{
    int n,i,all;
    char m[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",m);
        all=kk(m);
        printf("%d\n",all);
    }
    return 0;
}

int kk(char* m)
{
    int len,i2,x,y=0;
    len=strlen(m);
    for(i2=0;i2<len;i2++)
    {
        x=kkr(m[i2]);
        y=y*3+x;
    }
    return y;
}
int krr(char m)
{
    int z;
    switch (m)
    {
        case '-':z=-1;break;
        case '0':z=0;break;
        case '1':z=1;break;
    }
    return z;
}