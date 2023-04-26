#include<stdio.h>
#include<math.h>

int main()
{
        int pros;
        scanf("%d",&pros);
        for(int i=0;i<pros;i++)
        {
            unsigned long long int m;
            int n;
            scanf("%d",&n);
            m=pow(2,n);
            printf("case #%d:\n%d\n",i,m);
        }
}
