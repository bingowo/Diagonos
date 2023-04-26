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
int judge(int a[],int b[])
{
    int i=0;
    int a_flag=0,b_flag=0;
    for(i=L-1;i>=0;i--)
    {
        if(a[i] == -3)//-3=='-'-0
        {
            a[i] = 0;
            a_flag = 1;
        }
        if(b[i] == -3)
        {
            b[i] = 0;
            b_flag = 1;
        }
    }
    if(a_flag == 1 && b_flag == 1) return 1;
    else if(a_flag == 0 && b_flag == 0) return 2;
    else if(a_flag == 1 && b_flag == 0) return 3;
    else return 4;
}
void minus(int a[],int b[])
{
    int i=0;
    for(i=0;i<=L;i++)
        a[i] -= b[i];
}

void add(int a[],int b[])
{
    int i;
    for(i=L;i>0;i--)
        a[i] += b[i];
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

void carry(int a[])
{
    int i;
    for(i=L;i>0;i--)
    {
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}

void output(int a[],int pivot,int flag)
{
    int i=0;
    if(flag == -2)//同号
    {
        if(pivot == 1)//同负
            printf("-");
    }
    else//不同号
    {
        if(flag == 1)
        {//a大
            if(pivot == 3)//a负
                printf("-");
        }
        else if(flag == -1)
        {//b大
            if(pivot == 4)
                printf("-");
        }
    }
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
    scanf("%s %s",s1,s2);
        int a[L+1]={0};
        int b[L+1]={0};
        Input(s1,a);
        Input(s2,b);

        int pivot;
        pivot = judge(a,b);

        if(pivot == 1 || pivot == 2)
        {
            add(a,b);
            carry(a);
            output(a,pivot,-2);
        }

        if(pivot == 3 || pivot == 4)
        {
            int flag;
            flag = compare(a,b);
            if(flag == 1)
            {
                minus(a,b);
                borrow(a);
                output(a,pivot,flag);
            }
            else
            {
                minus(b,a);
                borrow(b);
                output(b,pivot,flag);
            }
        }
    return 0;
}
