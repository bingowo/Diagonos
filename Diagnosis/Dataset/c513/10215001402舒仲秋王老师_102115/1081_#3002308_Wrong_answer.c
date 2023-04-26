#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int a,n,k;

        scanf("%d %d",&a,&n);
        printf("case #%d:\n",i);
        if(n==0) printf("1\n");
        else
        {
            int num[1000]={0};
            num[999]=a;
            for(k=1;k<n;k++)
            {
                int c,j,flag=0;
                for(j=999;num[j]!=0;j--)
                {
                    c=num[j]*a;
                    num[j]=c%10+flag;
                    flag=c/10;
                }
            }
            for(k=0;k<999;k++)
                if(num[k]!=0) printf("%d",num[k]);
            printf("%d\n",num[k]);
        }
    }
    return 0;
}
