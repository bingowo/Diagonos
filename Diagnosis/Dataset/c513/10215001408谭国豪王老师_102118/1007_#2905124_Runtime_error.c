#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count(int b[32]);
    int n,t,a[32],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++);
    {


    scanf("%d",&t);
    for(j=0;j<32;j++)
    {
        a[j]=t%2;
        t=t/2;
    }
    printf("%d",count(a[32]));
    }
    return 0;
}
int count(int b[32])
{
    int k,total,max;
    for(k=0;k<31;k++)
    {
        if(b[k]!=b[k+1])
        {
            total++;k++;
            if(total>max)max=total;
        }
        else{total=0;k++;}
    }
    return max;
}
