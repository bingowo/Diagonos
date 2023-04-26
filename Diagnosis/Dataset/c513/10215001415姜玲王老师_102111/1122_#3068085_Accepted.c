#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k;
    scanf("%d",&n);
    unsigned long long a;
    for(int i=0;i<n;i++)
    {
        int b[100]={0};
        k=0;
        scanf("%llu",&a);
        while(a)
        {
           b[k]=a%2333;
           a=a/2333;
           k++;}
           if(k==0) {printf("0\n");continue;}
           for(k--;k>=0;k--)
           {
               printf("%d ",b[k]);
           }
           printf("\n");
    }
}