#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        char a[101];
        gets(a);
        printf("%s\n",a);
        
    }
}