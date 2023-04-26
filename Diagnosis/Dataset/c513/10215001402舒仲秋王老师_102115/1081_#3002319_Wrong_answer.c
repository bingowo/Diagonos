#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int a,n,k,j;
        scanf("%d %d",&a,&n);
        printf("case #%d:\n",i);
        if(n==0) printf("1\n");
        else
        {
            int num[1000]={0};
            num[999]=a;
            for(k=1;k<n;k++)
            {
                int c,flag=0;
                for(j=999;j>=0;j--)
                {
                    c=num[j]*a;
                    num[j]=c%10+flag;
                    flag=c/10;
                }
            }
            for(j=0;j<1000;j++)
                if(num[j]!=0) break;
            for(;j<999;j++) printf("%d",num[j]);
            printf("%d\n",num[j]);
        }
    }
    return 0;
}
