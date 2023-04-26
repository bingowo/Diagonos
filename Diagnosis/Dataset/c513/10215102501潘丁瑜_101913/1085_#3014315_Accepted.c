#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500

void Input(char s[],int a[])
{
    int j,k;
    for(j=L,k=strlen(s)-1;k>=0;j--,k--)
        a[j] = s[k]-'0';
}

int compare(int a[],int b[])
{
    int i=0;
    for(i=0;i<=L;i++)
    {
        if(a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    if(i > L) return 0;
}

void minus(int a[],int b[])
{
    int i=0;
    for(i=0;i<=L;i++)
        a[i] -= b[i];
}

void borrow(int a[])
{
    int i;
    for(i=L;i>=0;i--)
    {
        if(a[i] < 0)
        {
            a[i] += 10;
            a[i-1]--;
        }
    }
}

void output(int a[],int flag)
{
    int i=0;
    if(flag == -1) printf("-");
    while(a[i]==0 && i<=L) i++;
    if(i>L) printf("0");
    else
        while(i<=L)
            printf("%d",a[i++]);
    printf("\n");
}
int main()
{
    char s1[L+1]={0};
    char s2[L+1]={0};
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int a[L+1]={0};
        int b[L+1]={0};
        Input(s1,a);
        Input(s2,b);
        int flag;
        flag = compare(a,b);
        if(flag == 1)
        {
            minus(a,b);
            borrow(a);
            output(a,flag);
        }
        else
        {
            minus(b,a);
            borrow(b);
            output(b,flag);
        }

    }
    return 0;
}