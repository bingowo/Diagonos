#include<stdio.h>
int main()
{
    int a,z;
    char num[100],c;
    scanf("%d",&a);
    int i=0;
    while((c=getchar())!=' ')
    {
        num[i]=c;
        i++;
    }
    scanf("%d",&z);
}