#include<stdio.h>
int main()
{
    int pos;
    scanf("%d",&pos);
    for(int i=0;i<pos;i++)
    {
        int tab[20][20],count=0;
        for(int i=0;i<20;i++) for(int j=0;j<20;j++) tab[i][j]=0;
        int r,c,n,k;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        for(int j=0;j<n;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            tab[a-1][b-1]=1;
        }
        for(int wid=0;wid<r;wid++)
        {
            for(int hei=0;hei<c;hei++)
            {
                for(int i=0;i<r-wid;i++)
                {
                    for(int j=0;j<c-hei;j++)
                    {
                        int res=0;
                        for(int p=0;p<=wid;p++) for(int q=0;q<=hei;q++) res+=tab[i+p][j+q];
                        if(res>=k) count++;
                    }
                }
            }
        }
        printf("case #%d:\n%d\n",i,count);
    }
}