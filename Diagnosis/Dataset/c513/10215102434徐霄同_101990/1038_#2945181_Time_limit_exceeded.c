#include <stdio.h>
int xy[4][2]={1,1,1,-1,-1,1,-1,-1};
int a[200][200];
int n,m;
int maxl(int i,int j,int p)
{
    int x,y,l;
    x=i;
    y=j;
    l=0;
    while(x<n&&y<m&&x>=0&&y>=0){
        x=x+xy[p][0];
        y=y+xy[p][1];
        l++;
    }
    return l;
}
int sum(int i,int j,int p,int l0)
{
    int j0,l,s;
    s=0;
    j0=j;
    for(l=l0;l>0;l--){
        s=s+a[i][j0];
        j0=j0+xy[p][1];
    }
    return s;
}
int main()
{
    int k,i,j,p,t,l,l0,i0,s,s0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    s=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(p=0;p<4;p++){
                l=maxl(i,j,p);
                for(t=2;t<=l;t++){
                    s0=0;
                    i0=i;
                    for(l0=t;l0>0;l0--){
                        s0=s0+sum(i0,j,p,l0);
                        i0=i0+xy[p][0];
                    }
                    if(s0>=k)
                        s++;
                }
            }
    printf("%d\n",s);
    return 0;
}