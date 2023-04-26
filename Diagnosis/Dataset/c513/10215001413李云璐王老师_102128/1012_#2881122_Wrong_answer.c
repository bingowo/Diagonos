#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[100000]={0};
    char *p=a;
    int count=0;
    char b=getchar();
    if(b!='-') {*p=b;p++;count++;}
    while(*p!='-'&&*p!='+'&&*p)
    {*p=getchar();
    p++;
    count++;
    }
    
    
    
    
}