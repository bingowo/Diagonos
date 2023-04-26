#include<stdio.h>
int main()
{
    int a,z;
    char num[100],c,b;
    scanf("%d",&a);
    int i=0;
    do
    {
        b=getchar(); 
    }
    while((c=getchar())!=' ')
    {
        num[i]=c;
        i++;
    }
    scanf("%d",&z);
    printf("%d",a);
}