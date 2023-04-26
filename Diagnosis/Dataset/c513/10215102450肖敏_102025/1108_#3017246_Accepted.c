#include <stdio.h>

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int status[100]={0},flag=0;
        int a,b;
        scanf("%d%d",&a,&b);
        printf("case #%d:\n0.",i);
        for(int j=1;!flag;j++)
        {
            if(a==0)
            {
                flag=1;
                printf("\n");
            }
            else
            {
                if(status[a])
                {
                    flag=1;
                    printf("\n");
                    printf("%d-%d\n",status[a],j-1);
                }
                else
                {
                    status[a]=j;
                    printf("%d",a*10/b);
                    a=a*10%b;
                }
            }
        }
    }
    return 0;
}
