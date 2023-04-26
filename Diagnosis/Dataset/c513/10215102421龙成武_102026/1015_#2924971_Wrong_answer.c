#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int primetable[26];
int isprime(int x,int i);
void createprimetable(int *a);
void createarray(char *a,char *A);
int Max(int a,int b)
{
    return a>b? a:b;
}
int main()
{
    createprimetable(primetable);
    int T,i,j,sum,up;
    char A[80],B[80],a[30],b[30],res[30];

    scanf("%d",&T);

    while(T--)
    {
        up=0;
        j=0;
        scanf("%s",A);scanf("%s",B);
        createarray(a,A);createarray(b,B);
        for(i=1;i<Max((strlen(A)+1)/2,(strlen(B)+1)/2)+1;i++)
        {
            sum=a[i]-'0'+b[i]-'0'+up;
            if(sum>=primetable[i])
            {
                sum=sum-primetable[i];
                up=1;
            }
            else
            {
                up=0;
            }
            res[j++]=sum+'0';
        }
        if(up==1)
            res[j++]=up+'0';
        res[j]=0;

        puts(res);
    }
    return 0;
}

int isprime(int x,int i)
{
    int flag;
    if(i*i>x)
    {
        flag=1;
    }
    else if(x%i==0)
    {
        flag=0;
    }
    else
    {
        flag=isprime(x,i+1);
    }
    return flag;
}
void createprimetable(int *a)
{
    int x,i=1;
    for(x=2;x<2000;x++)
    {
        if(a[25]!=0)
            break;
        else if(isprime(x,2))
        {
            a[i++]=x;
        }
    }
}
void createarray(char *a,char *A)
{
    int len=strlen(A)-1,i=1;
    while(len>=0)
    {
        if('0'<=A[len]&&A[len]<='9')
        {
            a[i++]=A[len];
        }
        len--;
    }
    for(;i<26;i++)
    {
        a[i]='0';
    }
    a[i]=0;
}
