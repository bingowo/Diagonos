#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int min(int a,int b)
{
    if(a>b) return b;
    else    return a;
}
int main()
{
    int n,m,k,i,j,s=0,l,sum,a,b,x,y,cnt,left,right,tx,ty,tmp,maxl,maxlx,maxly;
    int num[250][250];
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
                left=1;
                if(a==0 || a==3)    maxlx=n-1-i;
                else    maxlx=i;
                if(a==0 || a==1)    maxly=m-1-j;
                else    maxly=j;
                maxl=min(maxlx,maxly);
                right=maxl;
                while (left<right)
                {
                    l=(left+right)/2;
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
                    if(sum>=k)
                    {
                        right=l;
                    }
                    else
                    {
                        left=l+1;
                    }
                }
                if(maxl>=2)
                {
                    if(sum>=k)
                    {
                        l=left;
                        s+=maxl-l+1;
                    }
                }
                else
                {
                    if(maxl==1)
                    {
                        sum=num[i][j]+num[i+mi[a]][j]+num[i][j+mj[a]];
                        if(sum>=k)  s++;
                    }
                }
            }
        }
    }
    printf("%d",s);
    return 0;
}