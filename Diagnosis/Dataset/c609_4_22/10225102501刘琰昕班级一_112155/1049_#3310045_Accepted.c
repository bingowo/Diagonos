#include <stdio.h>
#include <stdlib.h>
#define L 500

void Input(int a[],char s[])//输入一个整数
{
    int i=strlen(s)-1,j;
    for(j=L;i>=0;i--,j--)
         a[j]=s[i]-'0';
}

char cmp(int a[],int b[])
{
    int i=0;
    while(i<L && a[i]==b[i])i++;
    if(a[i]>=b[i]) return '+';
    else return '-';
}

void swap(int a[],int b[])
{
    int i,tmp;
    for(i=0;i<L+1;i++)
    {
        tmp=a[i];
        a[i]=b[i];
        b[i]=tmp;
    }
}

void sub(int a[],int b[])
{   int i;
    for(i=L;i>=0;i--)
    {
        a[i]-=b[i];
        if(a[i]<0)
        {
            a[i-1]--;
            a[i]+=10;
        }
    }
}

void output(int a[])
{
    int i=0;
    while(i<L&&a[i]==0)i++; //跳过前置0
    while(i<=L)printf("%d",a[i++]); //输出
    printf("\n");
}

int main()
{
    char s1[L+1],s2[L+1];
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int A[L+1]={0},B[L+1]={0};
        char sign;
        Input(A,s1);
        Input(B,s2);
        sign=cmp(A,B);
        if(sign=='-')
        {
            printf("-");
            swap(A,B);
        }
        sub(A,B); //A-=B
        output(A);
    }
    return 0;
}
