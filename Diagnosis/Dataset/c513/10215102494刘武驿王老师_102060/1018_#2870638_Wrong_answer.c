#include <stdio.h>
#include <string.h>
void multi(int *a,int b,int* res,int lena,int lenres)
{
    int next=0,tmp,i;
    for(i=0;i<lena;i++)
    {
        tmp=a[lena-i-1]*b;
        tmp+=next;
        res[lenres-i-1]=tmp%10;
        next=tmp/10;
    }
}
void plus(int *a,int*b,int* res,int len)
{
    int next=0,tmp,i;
    for(i=0;i<len;i++)
    {
        tmp=a[i]+b[i]+next;
        res[i]=tmp%10;
        next=tmp/10;
    }
}
int main()
{
    int T, I, weight[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int mem[25][50];
    for(int i=0;i<25;i++) for(int j=0;j<50;j++) mem[i][j]=0;
    mem[0][49]=1;
    for(int i=0;i<24;i++)
    {
        multi(mem[i],weight[i],mem[i+1],50,50);
    }
    int ten[25];
    int i=0;
    char c;
    while((c=getchar())!='\n')
    {
        if(c-'0'>=0&&'9'-c>=0) ten[i++]=c-'0';
    }
    int temp[50],res[50],trans[50],x;
    for(int j=0;j<50;j++) res[j]=0;
    for(int j=0;j<i;j++)
    {
        for(x=0;x<50;x++) {temp[x]=0;trans[x]=0;}
        multi(mem[i-j-1],ten[j],temp,50,50);
        plus(res,temp,trans,50);
        for(x=0;x<50;x++) res[x]=trans[x];
    }
    int test=0;
    for(x=0;x<50;x++)
    {
        if(res[x]!=0) test=1;
        if(test==1) printf("%d",res[x]);
    }
}