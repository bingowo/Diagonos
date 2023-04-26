#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    int* pa=(int*)a;  int* pb=(int*)b;
    return (*pa>*pb)?-1:1;
}

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i,j,h=0; int x=1,y=0,z=0;
    int **p=(int**)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
        p[i]=(int*)malloc(m*sizeof(int));
    int* arr2=(int*)calloc(4*(n-1)*(m-1),sizeof(int));
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
            scanf("%d",&p[i][j]);
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            x=1;
            while (j+x<m && i+x<n) //direction: x++ y++;
            {
                for (z=0;z<x+1;z++)
                    for (y=0;y<x+1-z;y++)
                    {
                        arr2[h]+=p[i+z][j+y];

                    }

                h++;
                x++;
            }
            x=1;
            while (j+x<m && i-x>=0) //direction: x++ y--;
            {
                for (z=0;z<x+1;z++)
                    for (y=0;y<x+1-z;y++)
                    {
                        arr2[h]+=p[i-z][j+y];

                    }
                h++;
                x++;
            }
            x=1;
            while (j-x>=0 && i-x>=0) //direction: x-- y--;
            {
                for (z=0;z<x+1;z++)
                    for (y=0;y<x+1-z;y++)
                    {
                        arr2[h]+=p[i-z][j-y];

                    }
                h++;
                x++;
            }
            x=1;
            while (j-x>=0 && i+x<n) //direction: x-- y++;
            {
                for (z=0;z<x+1;z++)
                    for (y=0;y<x+1-z;y++)
                    {
                        arr2[h]+=p[i+z][j-y];

                    }
                h++;
                x++;
            }
            x=1;

        }
    }
    int cnt=0;
    qsort(arr2,h,sizeof(int),cmp);
    for (i=0;i<h;i++)
        if (arr2[i]>=k)
            cnt++;
        else
            break;
    free(p);
    printf("%d\n",cnt);
    return 0;
}
