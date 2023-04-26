#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int num[101][101]={0};
int change(char* s)
{
    int res=0;
    for(int i=0;i<=7;i++)
    {
        if(s[i]=='1')
            res=res+pow(2,7-i);
    }
    return res;
}
int f(int x,int y)
{
    char s[9]={'\0'};
    if(num[x-1][y-1]>=num[x][y]) s[0]='1';
    else s[0]='0';
    if(num[x-1][y]>=num[x][y]) s[1]='1';
    else s[1]='0';
    if(num[x-1][y+1]>=num[x][y]) s[2]='1';
    else s[2]='0';
    if(num[x][y+1]>=num[x][y]) s[3]='1';
    else s[3]='0';
    if(num[x+1][y+1]>=num[x][y]) s[4]='1';
    else s[4]='0';
    if(num[x+1][y]>=num[x][y]) s[5]='1';
    else s[5]='0';
    if(num[x+1][y-1]>=num[x][y]) s[6]='1';
    else s[6]='0';
    if(num[x][y-1]>=num[x][y]) s[7]='1';
    else s[7]='0';
    //printf("%s\n",s);
    int min=change(s);
    for(int i=1;i<=7;i++)
    {
        char temp=s[0];
        for(int j=0;j<7;j++) s[j]=s[j+1];
        s[7]=temp;
        if(change(s)<min)
            min=change(s);
    }
    return min;
}
int main()
{
    int x,y;
    scanf("%d %d",&y,&x);
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            scanf("%d",&num[i][j]);
    for(int i=1;i<x-1;i++)
    {
        for(int j=1;j<y-1;j++) printf("%d ",f(i,j));
        printf("%c",10);
    }
    return 0;
}
