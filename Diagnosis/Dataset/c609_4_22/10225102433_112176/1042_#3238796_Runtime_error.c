#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100000

int ansm;
int ansn;
int x,y;
int m[N];
int n[N];

int find(int a,int b)
{
    int sum = a+b;
    a = a > b ? a : b;
    b = sum-a;
    if(b == 0) return 1;
    while(a % b)
    {
        int res = a%b;
        a = b;
        b = res;
    }
    return b;
}

void reverse(int *a)
{
    int res = ansm/2;
    for(int i = 0;i < res;i++)
    {
        int tmp  = a[i];
        a[i] = a[ansm-1-i];
        a[ansm-1-i] = tmp;
    }
}

void put(int num)
{
    while(num)
    {
        m[ansm++] = num%3;
        num /= 3;
    }
}

void dput(int a,int b)
{
    for(int i = 1;;i++)
    {
        if(a == 0) break;
        int res = (int)pow(3,i);
        int times = b/res;
        if(a < times)
        {
            n[ansn++] = 0;
        }
        else if(a == times)
        {
            n[ansn++] = times;
            break;
        }
        else
        {
            n[ansn++] = a/times;
            a -= (a/times)*times;
        }
    }
//    ansn--;
}

int main()
{
    int a = 3/0;
    printf("%d",a);
    return 0;
}