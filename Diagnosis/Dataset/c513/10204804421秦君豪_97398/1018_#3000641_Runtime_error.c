#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define N 5000
typedef struct
{
    int cnt,v[N];
}BIGINT;
int prime[27]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};

int Readnum (char* s,int* a)
{
    int i=0,digit;
    while (*s!='\0')
    {
        int digit=0;
        if(*s==',') s++;
        while (*s!=','&&*s!='\0')
        {
            digit = digit*10+(*s-'0');
            s++;
        }
        a[i++]=digit;
    }
    return i;
}

BIGINT int2BIG (int a)
{
    BIGINT r = {0,{0}};
    while (a!=0)
    {
        r.v[r.cnt++]= a%10;
        a/=10;
    }
    return r;
}

BIGINT BIGINTMUL(BIGINT a,BIGINT b)
{
    BIGINT r={0,{0}};
    r.cnt=a.cnt+b.cnt;
    for(int i=0;i<b.cnt;i++)
    {
        int t,k,j;
        int carry=0;
        for(j=0;j<a.cnt;j++)
        {
            t=a.v[j]*b.v[i]+r.v[i+j]+carry;
            r.v[i+j]=t%10;
            carry=t/10;
        }
        k=i+j;
        while (carry>0)
        {
            t=carry+r.v[k];
            r.v[k]=t%10;
            carry=t/10;
            k++;
        }
    }
    if(r.v[a.cnt+b.cnt-1]==0) r.cnt--;
    return r;
}

BIGINT BIGINTADD(BIGINT a,BIGINT b)
{
    BIGINT r={0,{0}};
    int i,carry=0;
    for(i=0;i<a.cnt&&i<b.cnt;i++)
    {
        int temp = a.v[i]+carry+b.v[i];
        r.v[i]=temp%10;
        carry=temp/10;
    }
    while (i<a.cnt)
    {
        int temp = a.v[i]+carry;
        r.v[i]=temp%10;
        carry=temp/10;
        i++;
    }
    while (i<b.cnt)
    {
        int temp = b.v[i]+carry;
        r.v[i]=temp%10;
        carry=temp/10;
        i++;
    }
    if(carry>0)
        r.v[i++]=carry%10;
    r.cnt=i;
    return r;
}

void print(BIGINT r)
{
    for(int i=r.cnt-1;i>=0;i--)
        printf("%d",r.v[i]);
    printf("\n");
}
int main(void)
{
    char s[51];scanf("%s",s);
    int a[25];
    int n = Readnum(s,a);//素数位数

    BIGINT R={0,{0}};
    R=int2BIG(a[0]);
//    printf("%d",a[0]);
    int i,j;
    for(i=1,j=n-1;i<n;i++,j--)
    {
        R=BIGINTMUL(R,int2BIG(prime[j]));
        R=BIGINTADD(R,int2BIG(a[i]));
         
    }
    print(R);
    return 0;

}
