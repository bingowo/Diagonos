#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T; scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int matrix[10][10];
        int r,c,n,k;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        memset(matrix,0,sizeof(matrix));
        for (int j=0;j<n;j++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            matrix[x-1][y-1] = 1;
        }
        int sum = 0;
        for (int a=0;a<r;a++)
            for (int b=0;b<c;b++)
                for (int e=a;e<r;e++)
                {
                    for (int f=b;f<c;f++)
                    {
                        int cnt = 0;
                        for (int g=a;g<=e;g++)
                            for (int h=b;h<=f;h++)
                                if (matrix[g][h]) cnt++;
                        if (cnt>=k) sum++;
                    }
                }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}