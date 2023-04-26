#include<stdio.h>

int count(int bigger, int smaller);
void swap(int *a, int *b);
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",count(x,y));
    return 0;
}

int count(int bigger, int smaller)
{
    if (bigger==smaller)
    {
        return 4*bigger;
    }
    else
    {
        if (smaller>bigger)
        {
            swap(&bigger,&smaller);
        }
        return (count(smaller,smaller)+count(bigger-smaller,smaller));
    }
} 

void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
    return;
}