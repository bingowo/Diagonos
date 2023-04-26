#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long int bushu(int a)
{
    long long int b[51];
    b[0]=0;
    b[1]=1;
    b[2]=2;
    b[3]=4;
    b[4]=8;
    b[5]=15;
   if(a>5)  return 2*bushu(a-1)-bushu(a-5);
   else return b[a];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        long long int c=bushu(a);
        printf("case #%d:\n",i);
        printf("%lld\n",c);
    }
    return 0;
}