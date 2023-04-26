#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
void swap(int* b, int* a)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}
int main()
{
    int n=1;
    char c;
    int i;
    char str[M][31]={0};
    scanf("%s",str[0]);
    while((c=getchar())!=EOF)
    {
        scanf("%s",str[n]);
        n++;
    }
    if(n==1)
        printf("%s\n",str[0]);
    else
    {
        ;
    }
    return 0;
}