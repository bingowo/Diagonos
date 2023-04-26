#include<stdio.h>
#include<stdlib.h>
int main()
{
    int number;
    scanf("%d",&number);
    int a[number];
    for(int i=0;i<number;i++)
    {
        scanf("%d",&a[i]);
        long long int b[a[i]];
        for(int j=0;j<a[i];j++)
        {
            scanf("%d",&b[j]);
        }
    }
}