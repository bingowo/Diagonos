#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    while(scanf("%d ",&n)!=0 && scanf("%d",&m)!=0 )
    {
        int sum[11]={},win[11]={},lose[11]={};
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                sum[a]+=3;
                sum[b]-=1;
                win[a]+=1;
                lose[b]+=1;

            }
            else if(c==-1)
            {
                sum[b]+=3;
                sum[a]-=1;
                win[b]+=1;
                lose[a]+=1;
            }
            else if(c==0)
            {
                sum[a]+=1;
                sum[b]+=1;
            }
        }
        int ran[]={0,1,2,3,4,5,6,7,8,9,10};
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(sum[i]<sum[j])
                {
                    int temp=ran[i];
                    ran[i]=ran[j];
                    ran[j]=temp;
                }
                else if(sum[i]==sum[j])
                {
                    if(win[i]<win[j])
                    {
                        int temp=ran[i];
                        ran[i]=ran[j];
                        ran[j]=temp;
                    }
                    else if(win[i]==win[j])
                    {
                        if(lose[i]>lose[j])
                        {
                            int temp=ran[i];
                            ran[i]=ran[j];
                            ran[j]=temp;
                        }
                    }
                }
            }
        }
        for(int i=1;i<n;i++) printf("%d ",&ran[i]);
        printf("%d",&ran[n]);
    }
    return 0;
}
