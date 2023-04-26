#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int que[11][11]={0};
        int r,c,n,k;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        for(int j=0;j<n;j++)
        {
            int pos1,pos2;
            scanf("%d %d",&pos1,&pos2);
            que[pos1][pos2]=1;
        }
        int ans=0;

        for(int x0=1;x0<=r;x0++)
        {
           for(int y0=1;y0<=c;y0++)
           {
               for(int xc=0;xc<=r-x0;xc++)
               {
                   int num=0;
                   for(int yc=0;yc<=c-y0;yc++)
                   {
                       for(int x=x0;x<=x0+xc;x++)
                       {
                           num+=que[x][y0+yc];
                       }
                       if(num>=k) ans++;
                       /*printf("%d\n",ans);*/
                   }
               }


           }
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }

}
