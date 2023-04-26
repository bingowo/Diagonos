#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    for(int i=0;i<x+1;i++)
    {
        char a[150];
        gets(a);
        printf("%s\n",a);
        
    }
}