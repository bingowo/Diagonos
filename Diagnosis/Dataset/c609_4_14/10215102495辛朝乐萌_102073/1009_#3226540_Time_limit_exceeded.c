#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void calculate(char s[],int *num,int *onenum)
{
    unsigned char *end=s;
    int temp;
    while (*end){
        end++;
    }
    unsigned char *p=(unsigned char *)s;
    while (*p!=end){
        temp=*p;
        *num+=8;
        while (temp>0){
            if (temp%2==1)
                *onenum+=1;
        }
        temp/=2;
    }
    p++;
}

int gcd(int a,int b)
{
    int ret,rest=a%b;
    while (rest){
        a=b;
        b=rest;
        rest=a%b;
    }
    ret=b;
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for (int i = 0; i < t; ++i) {
        char s[121];
        gets(s);
        int num=0,onenum=0;
        calculate(s,&num,&onenum);
        int mult= gcd(num,onenum);
        printf("%d/%d\n",onenum/mult,num/mult);
    }
    return 0;
}