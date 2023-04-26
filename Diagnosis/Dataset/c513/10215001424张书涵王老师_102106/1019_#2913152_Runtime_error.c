#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    int *ap=(int*)a;
    int *bp=(int*)b;
    if(ap[1]!=bp[1])
        return (bp[1]-ap[1]);
    else
    {
        if(ap[2]!=bp[2])
            return (bp[2]-ap[2]);
        else
        {
            if(ap[3]!=bp[3])
                return (ap[3]-bp[3]);
            else
                return (ap[0]-bp[0]);
        }
    }
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0||m==0);
        else
        {
            int a[m][3];
            int b[n][4];
            int i,j;
            for(i=0;i<n;i++)
            {
                for(j=0;j<4;j++)
                    b[i][j]=0;
            }
            for(i=0;i<n;i++)
                b[i][0]=i+1;
            for(i=0;i<m;i++)
            {
                for(j=0;j<3;j++)
                    scanf("%d",&a[i][j]);
            }
            for(i=0;i<m;i++)
            {
                if(a[i][2]==1)
                {
                    b[a[i][0]-1][1]=b[a[i][0]-1][1]+3;b[a[i][0]-1][2]=b[a[i][0]-1][2]+1;
                    b[a[i][1]-1][1]=b[a[i][1]-1][1]-1;b[a[i][1]-1][3]=b[a[i][1]-1][3]+1;
                }
                else
                {
                    if(a[i][2]==0)
                    {
                        b[a[i][0]-1][1]=b[a[i][0]-1][1]+1;
                        b[a[i][1]-1][1]=b[a[i][1]-1][1]+1;
                    }
                    else
                    {
                        b[a[i][0]-1][1]=b[a[i][0]-1][1]-1;b[a[i][0]-1][3]=b[a[i][0]-1][3]+1;
                        b[a[i][1]-1][1]=b[a[i][1]-1][1]+3;b[a[i][1]-1][2]=b[a[i][1]-1][2]+1;
                    }
                }
            }
            qsort(b,4,sizeof(b[0]),cmp);
            for(i=0;i<n;i++)
            printf("%d ",b[i][0]);
            printf("\n");
        }

    }
}
