#include <stdio.h>
#include <stdlib.h>

int singlejuzhen(int a[][11],int hang,int lie,int n,int k,int x,int y)
{
    int i,j,re=0,mid=0;
    for(i=hang;i<=x;i++)
    {
        for(j=lie;j<=y;j++)
        {
            mid+=a[i][j];
        }
    }
    if(mid>=k) return 1;
    else return 0;

}


int nofre(int a[][11],int hang,int lie,int n,int k)
{
    int i,j,re=0,x,y;
    for(i=0;i<hang;i++)
    {
        for(j=0;j<lie;j++)
        {
            for(x=i;x<hang;x++)
            {
                for(y=j;y<lie;y++)
                {
                    re+=singlejuzhen(a,i,j,n,k,x,y);
                    //printf("re=%d\n",re);
                }
            }
        }
    }
    return re;

}

int main()
{
    int TT,t;
    scanf("%d",&TT);
    for(t=0;t<TT;t++)
    {
        int hang,lie,n,k;
        scanf("%d%d%d%d",&hang,&lie,&n,&k);
        int a[11][11],i,j;
        for(i=0;i<hang;i++)
        {
            for(j=0;j<lie;j++)
            {
                a[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x-1][y-1]++;
        }

        int re;
        re=nofre(a,hang,lie,n,k);

        printf("case #%d:\n%d\n",t,re);
        /*for(i=0;i<hang;i++)
        {
            for(j=0;j<lie;j++)
            {
                printf("%d ",a[i][j]);

            }
            printf("\n");
        }*/
        //printf("%d",re);
    }
    return 0;
}
