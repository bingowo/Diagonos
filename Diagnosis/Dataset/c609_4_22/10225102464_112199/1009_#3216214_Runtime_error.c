#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int set[8];
int num_1;
int num_0;
void binary(char x){
    char m=x;
    for(int i=0;i<8;i++)
        {
            set[i]=(bool)(x&0x80);
            x=x<<1;
        }
    for(int i=0;i<8;i++)
    {
        if(set[i]==1) num_1++;
        else num_0++;
    }
    }

int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}

void solve(char *s)
{
    int n=strlen(s);
    num_1=0;
    num_0=0;
    for(int i=0;i<n;i++)
    {
       binary(s[i]);
    }
    int h=gcd(num_1,num_0);
    printf("%d %d",num_1/h,num_0/h);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s;
        gets(s);
        solve(s);
    }

    return 0;
}