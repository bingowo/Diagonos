#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i,j,h=0; int x=1,y=0,z=0;
    int **p=(int**)malloc(n*sizeof(int*));
    for (i=0;i<n;i++)
        p[i]=(int*)malloc(m*sizeof(int));
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
            scanf("%d",&p[i][j]);
    }

    int cnt=0;
    for (int x0=0;x0<n;x0++)  //x-- ,y--
    {
        for (int y0=0;y0<m;y0++)
        {
            long long s=p[x0][y0];
            for (int r=1;x0-r>=0 && y0-r>=0;r++)
            {
                int lb=y0-r;
                int rb=y0;
                for (int y=lb;y<=rb;y++)
                {
                    s+=(long long)p[x0-r][y];
                }
                if (s>=k)
                    cnt++;
            }
        }
    }
     for (int x0=0;x0<n;x0++) //x-- y++
    {
        for (int y0=0;y0<m;y0++)
        {
            long long s=p[x0][y0];
            for (int r=1;x0-r>=0 && y0+r<m;r++)
            {
                int lb=y0;
                int rb=y0+r;
                for (int y=lb;y<=rb;y++)
                    s+=(long long)p[x0-r][y];
                if (s>=k)
                    cnt++;
            }
        }
    }
    for (int x0=0;x0<n;x0++)  //x++ ,y--
    {
        for (int y0=0;y0<m;y0++)
        {
            long long s=p[x0][y0];
            for (int r=1;x0+r<n && y0-r>=0;r++)
            {
                int lb=y0-r;
                int rb=y0;
                for (int y=lb;y<=rb;y++)
                    s+=(long long)p[x0+r][y];
                if (s>=k)
                    cnt++;
            }
        }
    }

      for (int x0=0;x0<n;x0++) //x++ y++
    {
        for (int y0=0;y0<m;y0++)
        {
            long long s=p[x0][y0];
            for (int r=1;x0+r<n && y0+r<m;r++)
            {
                int lb=y0;
                int rb=y0+r;
                for (int y=lb;y<=rb;y++)
                    s+=(long long)p[x0+r][y];
                if (s>=k)
                    cnt++;
            }
        }
    }


    free(p);
    printf("%d\n",cnt);
    return 0;
}
