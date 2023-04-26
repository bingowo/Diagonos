#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef long long int lli;






int main()
{
    int n,m,k;scanf("%d",&k);

    for(int i=0;i<k;i++)
    {
        int flag=0,status[100]={0},q[100]={0};
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",i);
        printf("0.");

        for(int j=1;!flag;j++)
        {
            if(n==0)
            {
                flag=1;
                for(int p=1;p<j;p++) printf("%d",q[p]);
                printf("\n");
            }
            else
            {
                if(status[n])
                {
                    flag=1;
                    for(int p=1;p<j;p++) printf("%d",q[p]);
                    printf("\n");
                    printf("%d-%d\n",status[n],j-1);
                }
                else
                {
                    status[n]=j;
                    q[j]=n*10/m;
//                    printf("!!!%d\n",n?\);
                    n=n*10%m;
                }
            }
        }
    }
    return 0;
}
