#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char N[300];
    char F[300];
}BASE;


void reverse(char* s)
{
    int i,j;
    char tmp;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}

int main()
{
    int A,B,flag=0;
    scanf("%d %d",&A,&B);
    BASE num;
    if (A==0)
        printf("0");
    if (A<0)
    {
        A=-A;
        flag=1;
    }
    int M=A/B;
    int X=A%B;
    int i,j;
    for (i=0;M;i++)
    {
        num.N[i]=M%3+'0';
        M=M/3;
    }
    num.N[i]=0;
    for (j=0;B!=1;j++)
    {
        num.F[j]=X%3+'0';
        X=X/3;
        B=B/3;
    }
    num.F[j]=0;
    int carry=0;
    for (i=0;i<strlen(num.F);i++)
    {
        num.F[i]=num.F[i]+1+carry;
        if (num.F[i]=='3')
        {
            num.F[i]='0';
            carry=1;
        }
        else if (num.F[i]=='4')
        {
            num.F[i]='1';
            carry=1;
        }
        else
            carry=0;

    }
    for (i=0;i<strlen(num.N);i++)
    {
        num.N[i]=num.N[i]+1+carry;
        if (num.N[i]=='3')
        {
            num.N[i]='0';
            carry=1;
        }
        else if (num.N[i]=='4')
        {
            num.N[i]='1';
            carry=1;
        }
        else
            carry=0;
    }
    if (carry)
    {
        num.N[i++]='1';
        num.N[i]=0;
    }
    reverse(num.F);
    reverse(num.N);
    if (carry==0)
        for (i=0;i<strlen(num.N) && (num.N[i]-1)=='0';i++);
    else
        i=1;
    for (i;i<strlen(num.N);i++)
    {
        if (num.N[i]-1<'0')
            num.N[i]='2';
        else
            num.N[i]--;
    }
    for (j=strlen(num.F)-1;j>=0;j--)
    {
        if ((num.F[j]-1)!='0')
            break;
        else
            num.F[j]=0;
    }
    for (i=0;i<strlen(num.N) && num.N[i]==0;i++);
    if (flag)
        for (i;i<strlen(num.N);i++)
        {
            if (num.N[i]=='1')
                printf("2");
            if (num.N[i]=='2')
                printf("1");
            if (num.N[i]=='0')
                printf("0");
        }
    else
        printf("%s",num.N);
    if (strlen(num.F)!=0)
    {
        if (strlen(num.N)==0)
            printf("0");
        printf(".");
    }

    for (j=0;j<strlen(num.F);j++)
    {
        if (num.F[j]=='0')
            num.F[j]='2';
        else
            num.F[j]--;
    }
    if (flag)
        for (i=0;i<strlen(num.F);i++)
        {
            if (num.F[i]=='1')
                printf("2");
            if (num.F[i]=='2')
                printf("1");
            if (num.F[i]=='0')
                printf("0");
        }
    else
        printf("%s",num.F);
    return 0;
}
