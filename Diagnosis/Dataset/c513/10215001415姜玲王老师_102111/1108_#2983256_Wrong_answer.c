#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
int t,a,b,j=0,k;
scanf("%d",&t);
for(int i=0;i<t;i++)
{   int c[100]={0};
    scanf("%d%d",&a,&b);
    k=a/b;
    printf("%d",k);
    a=a%b*10;
    if(a)printf(".");
    c[j++]=a;
    while(a)
    {k=a/b;
    printf("%d",k);
    a=a%b*10;
    if(a==0) break;
    for(int n=0;n<100;n++)
        {
            if(a==c[n]){printf("\n%d-%d",n+1,j);a=0;break;}
        }
    c[j++]=a;
    }
    printf("\n");
}
}
