#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
char s1[10005],s2[10005];
struct node{
    int num[1005],cnt;
}A,B;
//对比1086浮点数减法
//分清cnt pre的区别
int main()
{
    scanf("%s%s%d",s1,s2,&n);
    int pre1=0,pre2=0;
    //确定小数点位置
    for(int i=0;s1[i];i++)
    {
        if(s1[i]=='.')
        {
            pre1=i;
            break;
        }
        if(!s1[i+1])
            pre1=i+1;
    }
    if(pre1<1)
    {
        A.num[++A.cnt]=0;
        pre1++;
    }
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
    //前面对齐
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
    //因此最高位在2的位置!!!
    //自己写的时候
    //如果是从零开始
    //要注意这里的细节！
    A.num[++A.cnt]=0;
    pre1++;
    B.num[++B.cnt]=0;
    pre2++;
    //读入整型数组
    for(int i=0;s1[i];i++)
        if(s1[i]!='.')
            A.num[++A.cnt]=s1[i]-'0'; //遇到小数点就跳过
    for(int i=0;s2[i];i++)
        if(s2[i]!='.')
            B.num[++B.cnt]=s2[i]-'0';
    //末尾对齐 并且符合精确要求
    while(A.cnt<B.cnt||A.cnt<pre1+n)
        A.num[++A.cnt]=0;
    while(B.cnt<A.cnt||B.cnt<pre1+n)
        B.num[++B.cnt]=0;
    for(int i=A.cnt;i;i--)
    {
        A.num[i]+=B.num[i];
        if(i==pre1+n && A.num[i+1]>=5)
            A.num[i]++;
        A.num[i-1]+=A.num[i]/10;
        A.num[i]%=10;
    }
    
    int i=1;
    while(A.num[i]==0&&i<pre1)
        i++;
    for(;i<=pre1+n;i++)
    {
        printf("%d",A.num[i]);
        if(i==pre1)
            printf(".");
    }
    return 0;
}
//首位的进位的细节要注意
