#include <stdio.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int q[100]={0},status[100]={0},m,n,flag=0;
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",t); printf("0.");

        for(int i=1; !flag; i++)
        {
            if(n==0)
            {
                flag=1;
                for(int j=1;j<i;j++) printf("%d",q[j]);
                printf("\n");
            }
            else
            {
                if(status[n])
                {
                    flag=1;
                    for(int j=1;i<j;j++) printf("%d",q[j]);
                    printf("\n");
                    printf("%d-%d\n",status[n],i-1);
                }
                else
                {
                    status[n]=i; q[i]=n*10/m; n=n*10%m;
                }
            }
        }
    }
    return 0;
}