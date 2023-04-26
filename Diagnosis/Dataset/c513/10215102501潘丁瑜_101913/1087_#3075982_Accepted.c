#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 100
void input(char s[],int a[])
{
    int j,k;
    scanf("%s",s);
    for(j=L,k=strlen(s)-1;k>=0;j--,k--)
        a[j] = s[k]-'0';
}

void carry(int a[])
{
    int i;
    for(i=L;i>0;i--)
    {
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}
void judge(int a[])
{
    int i,j;
    a[L]++;
    if(a[L]>9) carry(a);
    i=0;
    while(1)
    {
        i=0;
        while(a[i] == 0) i++;
        for(;i<L;i++)
            if(a[i] == a[i+1])
            {
                a[i+1]++;
                if(a[i+1]>9) carry(a);
                for(j=i+2;j<=L;j+=2)
                {
                    a[j] = 0;
                    if(j+1<=L)
                        a[j+1]=1;
                }
                break;
            }
        if(i==L) break;
    }
}

void output(int a[])
{
    int i=0;
    while(a[i]==0) i++;
    for(;i<L;i++)
        printf("%d",a[i]);
    printf("%d\n",a[i]);
}
int main()
{
    int t;
    int i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[L+1]={0};
        int a[L+1]={0};
        input(s,a);
        judge(a);
        printf("case #%d:\n",i);
        output(a);
    }
    return 0;
}