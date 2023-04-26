#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int r,c,n,k;
        int cnt=0,sum=0;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int **matrix=(int**)calloc(r,sizeof(int*));
        int* cnt1=(int*)calloc(r,sizeof(int));
        int* cnt2=(int*)calloc(c,sizeof(int));
        for (int j=0;j<r;j++)
            matrix[j]=(int*)calloc(c,sizeof(int));
        for (int j=0;j<n;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            matrix[a-1][b-1]=1;
            cnt1[a-1]++;
            cnt2[b-1]++;
        }
        for (int j=0;j<r;j++)
        {
            if (cnt1[j]>=k)
            {
                cnt+=(r-j);
                int m=0,x;
                for (x=0;x<c;x++)
                {
                    if (matrix[j][x])
                        m++;
                    if (m==k)
                    {
                        cnt+=(c-1-x)*(r-j);
                        break;
                    }
                }
            }
            else
            {
                int m=0,v=0,x,y;
                for (x=0;j+x<r;x++)
                {
                    m+=cnt1[j+x];
                    if (m>=k)
                    {
                        cnt+=r-j-x;
                        break;
                    }
                }
                if (m>=k)
                {
                    for (y=0;y<c;y++)
                    {
                        for (int u=0;u<=x;u++)
                        {
                            if (matrix[j+u][y])
                                v++;
                            if (v==k)
                            {
                                cnt+=(r-j-x)*(c-1-y);
                                break;
                            }
                        }
                    }
                }

            }
        }
        for (int j=0;j<c;j++)
        {
            if (cnt2[j]>=k)
            {
                if (j!=0)
                    cnt+=(c-j);
                if (j==0)
                    cnt+=(c-j)-1;
                int m=0,x,flag=0;
                for (x=0;x<r;x++)
                {
                    if (matrix[x][j])
                        m++;
                    if (m==k)
                    {
                        if (x==r-1)
                            flag==1;
                        if (flag==0)
                            cnt+=(r-1-x)*(c-j);
                        break;
                    }
                }
            }
            else
            {
                int m=0,v=0,x,y,flag=0;
                for (x=0;j+x<c;x++)
                {
                    m+=cnt2[j+x];
                    if (m>=k)
                    {
                        if (x==c-1)
                            flag=1;
                        if (flag==0)
                        {
                            cnt+=c-j-x;
                        }

                        break;
                    }
                }
                if (m>=k && flag==0)
                {
                    for (y=0;y<r;y++)
                    {
                        for (int u=0;u<=x;u++)
                        {
                            if (matrix[y][j+u])
                                v++;
                            if (v==k)
                            {
                                cnt+=(c-j-x)*(r-1-y);
                                break;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",cnt);

    }
    return 0;
}
