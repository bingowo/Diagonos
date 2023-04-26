#include <stdio.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int n,m,status[100]={0},q[100],j,t,flag = 0;
        scanf("%d %d",&n,&m);
        printf("case #%d:\n0.",i);
        for(j = 1;!flag;j++)
        {
            if(n==0)
            {
                flag = 1;
                for(t = 1;t<j;t++) printf("%d",q[t]);
                printf("\n");
            }
            else {
                if(status[n])
                {
                    flag = 1;
                    for(t = 1;t<j;t++) printf("%d",q[t]);
                    printf("\n");
                    printf("%d-%d\n",status[n],j-1);
                }
                else{
                    status[n] = j;
                    q[j] = n*10/m;
                    n = n*10%m;
                }
            }
        }
    }
    return 0;
}
