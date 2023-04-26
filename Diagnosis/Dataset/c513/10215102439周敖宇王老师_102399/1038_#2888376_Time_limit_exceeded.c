#include<stdio.h>
int main()
{
    int n,m,k,i,j,s=0,l,sum,a,b,x,y,cnt;
    int num[200][200];
    int mi[]={1,-1,-1,1};
    int mj[]={1,1,-1,-1};
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&num[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            for(a=0;a<=3;a++)
            {
                for(l=1;l<=m+n;l++)
                {
                    if(i+mi[a]*l>=0 && i+mi[a]*l<n && j+mj[a]*l>=0 && j+mj[a]*l<m)
                    {
                        cnt=0;
                        sum=0;
                        for(x=i;x<=i+l && x>=i-l;x+=mi[a])
                        {
                            for(y=j;y<=j+l-cnt && y>=j-l+cnt;y+=mj[a])
                            {
                                sum+=num[x][y];
                            }
                            cnt++;
                        }
                    }
                    else  break;
                    if(sum>=k)  s++;
                }
            }
        }
    }
    printf("%d",s);
    return 0;
}