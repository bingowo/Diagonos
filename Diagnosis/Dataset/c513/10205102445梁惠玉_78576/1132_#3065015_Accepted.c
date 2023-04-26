#include <stdio.h>



int main()
{
    int T;
    scanf("%d",&T);
    char num[100];
    for(int i=0;i<T;i++)
    {
        int n,r;
        scanf("%d %d",&n,&r);
        int j,k=0,sum=0;
        while(n){
            sum+=n%r;
            n/=r;
        }
        while(sum)
        {
            if(sum%r>=0&&sum%r<=9)
            {
                num[k++]=sum%r+'0';

            }
            else{
                num[k++]=sum%r-10+'A';
            }
            sum=sum/r;
        }
        printf("case #%d:\n",i);
        for(j=k-1;j>=0;j--)
        {
            printf("%c",num[j]);
        }
        printf("\n");

    }

    return 0;
}
