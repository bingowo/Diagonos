#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
char s1[10005],s2[10005];

struct node
{
    int num[1005],cnt;
}A,B;

int main()
{
    scanf("%s%s%d",s1,s2,&n);
    int pre1=0,pre2=0;
    for(int i=0;s1[i];i++)
    {
        if(s1[i]=='.')
        {
            pre1=i;
            break;
        }
        if(!s1[i+1])  //没有标点的情况，就在个位的后一位
            pre1=i+1;
    }
    if(pre1<1) //也就是小数点在第一位的情况
    {
        A.num[++A.cnt]=0;
        pre1++;  //补0，小数点后移一位
    }
    //以下重复
    for(int i=0;s2[i];i++)
    {
        if(s2[i]=='.')
        {
            pre2=i;
            break;
        }
        if(!s2[i+1])
            pre2=i+1;
    }
    if(pre2<1)
    {
        B.num[++B.cnt]=0;
        pre2++;
    }
    
    //小数点对齐
    while(pre1<pre2)
    {
        A.num[++A.cnt]=0;
        pre1++;
    }
    while(pre2<pre1)
    {
        B.num[++B.cnt]=0;
        pre2++;
    }
    
    //留给小数点的位置
    A.num[++A.cnt]=0;
    pre1++;
    B.num[++B.cnt]=0;
    pre2++;
    
    //读入整型数组
    for(int i=0;s1[i];i++)
        if(s1[i]!='.')
            A.num[++A.cnt]=s1[i]-'0';
    for(int i=0;s2[i];i++)
        if(s2[i]!='.')
            B.num[++B.cnt]=s2[i]-'0';
    
    //补齐末尾 包括题目给的要求的位数
    while(A.cnt<B.cnt||A.cnt<pre1+n)
        A.num[++A.cnt]=0;
    while(B.cnt<A.cnt||B.cnt<pre1+n)
        B.num[++B.cnt]=0;
    
    
    int flg=0; //通过首位来决定正负号
    for(int i=1;i<=A.cnt;i++)
    {
        A.num[i]-=B.num[i]; //这里暂时保留负数，不考虑进位
        if(A.num[i]!=0&&flg==0)
        {
            if(A.num[i]>0)
                flg=1;
            else
                flg=-1;
        }
        A.num[i]*=flg;
    }
    //进位
    for(int i=A.cnt;i;i--)
    {
        if(i==pre1+n && A.num[i+1]>=5) //四舍五入 i+1是否取到取决于末尾补0时原先位数是否已超过要求
            A.num[i]++;
        if(A.num[i]<0)
        {
            A.num[i]+=10;
            A.num[i-1]--;
        }
    }
    //去除前置0
    int i=1;
    while(A.num[i]==0&&i<pre1)
        i++;
    if(flg==-1)
        printf("-");
    //输出
    for(;i<=pre1+n;i++)
    {
        printf("%d",A.num[i]);
        if(i==pre1)
            printf(".");
    }
    return 0;
}

