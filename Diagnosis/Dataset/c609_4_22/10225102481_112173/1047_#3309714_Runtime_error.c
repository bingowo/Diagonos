#include <stdio.h>
#include <stdlib.h>

#define N 95


void mul(int a,int n)
{
    int result[N]={1};
    int i,carry=0;
    for (i=0; i<n; i++)
    {
        int t=result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;
    }
     for(int j=n;j>=0;j--)printf("%d",result[j]);
     printf("\n");
}



int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {

        int a,n;
        scanf("%d %d\n",&a,&n);
        printf("case #%d:\n",i);
        mul(a,n);

    }
   return 0;
}
