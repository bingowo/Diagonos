#include<stdio.h>
#include<string.h>
#define N 60
struct Base
{
    char word;
    int num;
};
int value(char c,int index,struct Base* base)
{
    int i,num1;
    for(i=0;i<index;i++)
    {
        if(c==base[i].word)
        {
            num1=base[i].num;
            break;
        }
    }
    return num1;
}
int ipow(int n,int x)
{
    int i=0;
    int sum=1;
    for(i=0;i<x;i++)
    sum=sum*n;
    return sum;
}
int main()
{
    int T;
    char s[N];
    scanf("%d",&T);
    struct Base base[N];
    int i;
    for(i=0;i<T;i++)
    {
        scanf("%s",s);
        int j=0,index=1;
        base[0].word=s[0];
        base[0].num=1;
        for(j=1;j<(strlen(s));j++)
        {
            if(s[j]!=s[j-1])
            {
                if(index<2)
                { base[index].word=s[j];
                 base[index].num=index-1;
                 index++;}
                 else if(index>=2)
                 {
                     base[index].word=s[j];
                    base[index].num=index;
                    index++;
                 }
            }
        }
        int count=0;
        for(j=strlen(s)-1;j>=0;j--)
        {
            count=count+value(s[j],index,base)*ipow(index,strlen(s)-1-j);
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }
}