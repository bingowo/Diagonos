#include<stdio.h>
int main()
{
    int m[100],x,y,sum1,sum2,i,j,z,n,T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        j=0;
        scanf("%d",&n);
        while(n!=0)
        {
            x=n%2;
            m[j]=x;
            n=n/2;
            j++;
        }
        sum1=1;
        sum2=1;
        y=m[0];
        for(z=1;z<j;z++)
        {
            if(y!=m[z])
            {
                y=m[z];
                sum2++;
            }
            else
            {
                if(sum1<sum2)
                    sum1=sum2;
                sum2=1;
            }
        }
        if(sum1<sum2)
            sum1=sum2;
        printf("case #%d:\n%d\n",i,sum1);
    }
    return 0;

}
