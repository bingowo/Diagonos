#include<stdio.h>
#include<string.h>
#define C 5000
int find_diff(char a,char b,char c)
{
    if(a==b&&b==c)return 1;
    else if(a==b||b==c||a==c)return 2;
    return 3;
}
void multi(int* A,int n)
{
    int tmp,carry=0;
    for(int i=C-1;i>-1;--i)
    {
        tmp=A[i]*n+carry;
        if(tmp>=10){A[i]=tmp%10;carry=tmp/10;}
        else {A[i]=tmp;carry=0;}
    }
    return;
}