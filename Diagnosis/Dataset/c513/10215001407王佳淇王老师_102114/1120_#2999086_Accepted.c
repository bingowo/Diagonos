#include<stdio.h>
int func(int(*a)[11],int k, int r, int c, int n)
{
    int sum = 0;
    for(int a1 = 1; a1 <= r; a1++)
    {
        for(int a2 = 1; a2 <= c; a2++)
        {
            for(int b1 = 1; b1 <= r; b1++)
            {
                for(int b2 = 1; b2 <= c; b2++)
                {
                    int z = 0;
                    for(int c1 = a1; c1 <= b1; c1++)
                    {
                        for(int c2 = a2; c2 <= b2; c2++)
                        {
                            if(a[c1][c2])
                            {
                                z++;
                            }
                        }
                    }
                    if(z >= k) sum++;
                }
            }
        }
    }
    return sum;
}

int main()
{
    int T,k,r,c,n;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        int a[11][11] = {{0}};
        scanf("%d %d %d %d ",&r,&c,&n,&k);
        for(int i=0;i<n;i++)
        {   
            int x, y;
            scanf("%d %d",&x,&y);
            a[x][y] = 1;
        }
        
        printf("case #%d:\n",j);
        printf("%d\n",func(a,k,r,c,n));   
    }
    return 0;
}
