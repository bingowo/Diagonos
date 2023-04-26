#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int bushu(int a,int *b)
{
    b[0]=0;
    b[1]=1;
    b[2]=2;
    b[3]=4;
    b[4]=8;
    b[5]=15;
    if(a<=4) return b[a];
   if(a>4)  {b[a]=2*b[a-1]-b[a-5];return b[a];}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,c;
        scanf("%d",&a);
        int b[51];
        c=bushu(a,b);
        printf("case #%d:\n",i);
        printf("%d\n",c);
    }
    return 0;
}