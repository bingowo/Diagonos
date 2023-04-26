#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[100];int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        readernumber(s,a);
        scanf("%s",s);
        readernumber(s,b);
        add(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }
}

void ADD(int a[],int b[],int c[])
{
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int i,j;
    
    
} 
