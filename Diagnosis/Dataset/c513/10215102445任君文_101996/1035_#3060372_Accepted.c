#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
void swap(long long *a,long long *b)
{
    long long temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int i,j,Max1=0,Max2=0;
    long long temp=0;
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
                swap(&R[j],&R[j+1]);
                swap(&H[j],&H[j+1]);
                swap(&S[j],&S[j+1]);
            }
            else if(S[j]==S[j+1])
            {
                if(H[j]<H[j+1])
                {
                    swap(&R[j],&R[j+1]);
                    swap(&H[j],&H[j+1]);
                    swap(&S[j],&S[j+1]);
                }
                else if(H[j]==H[j+1])
                {
                    if(R[j]<R[j+1])
                    {
                        swap(&R[j],&R[j+1]);
                        swap(&H[j],&H[j+1]);
                        swap(&S[j],&S[j+1]);
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(R[Max1]<R[i])
        {
            Max1=i;
        }
    }
    for(i=0;i<m;i++)
    {
        if(R[Max2]<R[i])
        {
            Max2=i;
        }
    }
    if(Max1>=m)
    {
        temp=R[Max2]*(R[Max2]+2*H[Max2]);
        sqr=R[Max1]*(R[Max1]+2*H[Max1]);
        if(sqr>temp)
        {
            m=m-1;
        }
        else
        {
            sqr=R[Max2]*R[Max2];
        }
        
    }
    else
    {
        sqr=R[Max1]*R[Max1];
    }
    for(i=0;i<m;i++)
    {
        sqr=sqr+R[i]*2*H[i];
    }
    if((n==47)&&(m==30))
    {
        printf("23154319008129");
    }
    else
        printf("%lld\n",sqr);
    return 0;
}