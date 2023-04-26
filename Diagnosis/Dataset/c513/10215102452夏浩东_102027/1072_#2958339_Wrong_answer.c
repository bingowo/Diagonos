#include <stdlib.h>
#include <stdio.h>
int main()
{
    long long int x=0,y=0;
    long long int m=0,n=0;
    int flag1=0,flag2=0;
    scanf("%lld %lld",&x,&y);
    if(x<0){m=-x; flag1=1;}
    if(y<0){n=-y; flag2=1;}
    if(m%2+n%2!=1) printf("-1");
    else
    {
        int k=0;
        int L[1000]={0};
        while(m!=0 || n!=0)
        {
            if(m%2==1){
                if((m+1)/2%2+n/2%2==1)
                {
                    m=(m+1)/2;n=n/2;
                    if(flag1==1) L[k++]=1;
                    else L[k++]=-1;
                }
                else if((m-1)/2%2+n/2%2==1)
                {
                    m=(m-1)/2;n=n/2;
                    if(flag1==1) L[k++]=-1;
                    else L[k++]=1;
                }
            }
            else{
                if((n+1)/2%2+m/2%2==1)
                {
                    n=(n+1)/2;m=m/2;
                    if(flag2==1) L[k++]=2;
                    else L[k++]=-2;
                }
                else if((n-1)/2%2+m/2%2==1)
                {
                    n=(n-1)/2;m=m/2;
                    if(flag2==1) L[k++]=-2;
                    else L[k++]=2;
                }
            }
        }
        printf("%d\n",k);
        for(int i=0;i<k;i++)
        {
            if(L[i]==1) printf("E");
            else if(L[i]==-1) printf("W");
            else if(L[i]==2) printf("N");
            else if(L[i]==-2) printf("S");
        }
    }
    return 0;
}