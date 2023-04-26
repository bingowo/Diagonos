#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        char a[150];
        gets("%s",&a);
        printf("%s\n",a);
        
    }
}