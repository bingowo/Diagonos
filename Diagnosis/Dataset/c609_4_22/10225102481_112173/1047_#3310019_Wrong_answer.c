#include <stdio.h>
#include <stdlib.h>

#define N 99
void mul(int *result,int a)
{
    int i,carry=0;
    for (i=0; i<N; i++)
    {
        int t=result[i]*a+carry;
        result[i]=t%10;
        carry=t/10;
    }
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
        int result[N]={1};
        for(int m=0;m<n;m++)mul(result,a);
        for(int j=N;j>=0;j--){if(result[j]==0)continue;printf("%d",result[j]);}
        printf("\n");
    }
   return 0;
}
