#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int bushu(int a,int *b)
{
    if(a==0) return b[0]=0;
    if(a==1) return b[1]=1;
    if(a==2) return b[2]=2;
    if(a==3) return b[3]=4;
    if(a==4) return b[4]=8;
    if(a>4)  {b[n]=bushu(a-1,b)+bushu(a-2,b)+bushu(a-3,b)+bushu(a-4,b);return b[n];}
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d",&a);
        b=bushu(a);
        printf("case #%d:\n",i);
        printf("%d\n",b);
    }
    return 0;
}