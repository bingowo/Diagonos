#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num[1000]={0};
    int n=0;
    int i;
    char c;
    while((c=getchar())!='\n')
    {
        num[n]=c-'0';
        n++;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",num[i]);
    }
    printf("\n");
    return 0;
}