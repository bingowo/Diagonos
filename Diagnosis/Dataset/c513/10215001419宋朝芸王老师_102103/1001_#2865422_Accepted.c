#include <stdio.h>
#include <stdlib.h>
void num2R(int a,int b);
int main()
{
    int N,R,T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d",&N,&R);
        num2R(N,R);
    }
    return 0;
}

void num2R(int a,int b)
{
    char result[100];
    int i;
    if(a<0)
    {
        a=-a;
        printf("-");
    }
    for(i=0;a>0;i++)
    {
        if(a%b<10) result[i]=a%b+'0';
        else result[i]=a%b-10+'A';
        a=a/b;
    }
    for(int k=i-1;k>=0;k--)
        printf("%c",result[k]);
    printf("\n");
}
