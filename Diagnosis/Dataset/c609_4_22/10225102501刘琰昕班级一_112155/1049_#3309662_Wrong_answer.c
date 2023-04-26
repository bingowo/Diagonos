#include <stdio.h>
#include <stdlib.h>
#define L 500

void Input(int a[],char s[])//输入一个整数
{
    int i=strlen(s)-1,j;
    for(j=0;i>=0;i--,j++)
         a[j]=s[i]-'0';
}

int cmp(int a[],int b[])
{
    int i=L,j=L;
    while(i>0 && a[i]==b[j]){i--,j--;};
    if(a[i]>=b[i]) return 1;
    else return -1;
}

void sub(int a[],int b[])
{   int i;
    for(i=0;i<L;i++)
    {
        a[i]-=b[i];
        if(a[i]<0)
        {
            a[i+1]--;
            a[i]+=10;
        }
    }
}

void output(int a[])
{
    int i=L-1;
    while(i>0&&a[i]==0)i--; //跳过前置0
    while(i>=0)printf("%d",a[i--]); //输出
    printf("\n");
}

int main()
{
    char s1[L+1],s2[L+1];
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int A[L+1]={0},B[L+1]={0},sign=1;
        Input(A,s1);
        Input(B,s2);
        output(A);
        output(B);
        sign=cmp(A,B);
        printf("%d\n",sign);
        if(sign>0)
        {
            sub(A,B); //A-=B
            output(A);
        }
        else
        {
            printf("-");
            sub(B,A);
            output(B);
        }
    }
    return 0;
}
