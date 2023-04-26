#include <stdio.h>
int xy[4][2]={1,1,1,-1,-1,1,-1,-1};
int a[200][200];
int suma[200][201];
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
int sum(int i,int j,int p,int l)
{
    if(xy[p][0]==1)
        return suma[i][j]-suma[i][j+l];
    else
        return suma[i][j-l+1]-suma[i][j+1];
}
int main()
{
    int k,i,j,p,l,t,t0,i0,s,s0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<=m;j++){
            s=0;
            for(p=j;p<m;p++)
                s=s+a[i][p];
            suma[i][j]=s;
        }
    s=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(p=0;p<4;p++){
                l=maxl(i,j,p);
                t=2;
                while(t<=l){
                    s0=0;
                    i0=i;
                    for(t0=t;t0>0;t0--){
                        s0=s0+sum(i0,j,p,t0);
                        i0=i0+xy[p][0];
                    }
                    if(s0>=k){
                        //printf("%d %d %d\n",i,j,p);
                        break;
                    }
                    t++;
                }
                s=s+(l-t+1);
            }
    printf("%d\n",s);
    return 0;
}
