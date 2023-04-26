#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
int main()
{
    int i,j,Max=0;
    long long temp;
    long long sqr=0;
    int n,m;
    long long R[M]={0},H[M]={0},S[M]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&R[i],&H[i]);
        S[i]=R[i]*H[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(S[j]<S[j+1])
            {
                temp=R[j];R[j]=R[j+1];R[j+1]=temp;
                temp=H[j];H[j]=H[j+1];H[j+1]=temp;
                temp=S[j];S[j]=S[j+1];S[j+1]=temp;
            }
            else if(S[j]==S[j+1])
            {
                if(H[j]<H[j+1])
                {
                    temp=R[j];R[j]=R[j+1];R[j+1]=temp;
                    temp=H[j];H[j]=H[j+1];H[j+1]=temp;
                    temp=S[j];S[j]=S[j+1];S[j+1]=temp;
                }
                else if(H[j]==H[j+1])
                {
                    if(R[j]<R[j+1])
                    {
                        temp=R[j];R[j]=R[j+1];R[j+1]=temp;
                        temp=H[j];H[j]=H[j+1];H[j+1]=temp;
                        temp=S[j];S[j]=S[j+1];S[j+1]=temp;
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(R[Max]<R[i])
        {
            Max=i;
        }
    }
    if(Max>=m)
    {
        sqr=R[Max]*(R[Max]+2*H[Max]);
        m=m-1;
    }
    else
    {
        sqr=R[Max]*R[Max];
    }
    for(i=0;i<m;i++)
    {
        sqr=sqr+R[i]*2*H[i];
    }
    printf("%lld\n",sqr);
    return 0;
}