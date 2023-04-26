#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int z=0;z<t;z++)
    {
        int n,m;
        int flag=0,q[100]={0},s[100]={0};
        scanf("%d%d",&n,&m);
        printf("case #%d:\n",z);
        printf("0.");
        for(int i=1;flag==0;i++)
        {
            if(n==0)
            {
                flag=1;
                for(int j=1;j<i;j++)
                    printf("%d",q[j]);
                printf("\n");
            }
            else
            {
                if(s[n]>0)
                {
                    flag=1;
                    for(int j=1;j<i;j++)
                        printf("%d",q[j]);
                    printf("\n");
                    printf("%d-%d",s[n],i-1);
                }
                else
                {
                    s[n]=i;
                    q[i]=n*10/m;
                    n=n*10%m;
                }
            }
        }
    }
    return 0;
}
