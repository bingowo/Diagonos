#include <stdio.h>
#include <math.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int t=0;t<cnt;t++)
    {
        long long int A=0; 
        int N=0,B=0;
        scanf("%lld %d %d",&A,&B,&N);
        long long int res=1;
        for(int i=0;i<B;i++)
        {
            long long int temp=0;
            res=res*A;
            for(int k=0;k<N;k++)
            {
                temp+=res%10*pow(10,k);
                res=res/10;
                if(res==0) break;
            }
            res=temp;
        }
        printf("case #%d:\n",t);
        int len=0;
        long long int res2=res;
        while(res2>0) {res2=res2/10;len++;}
        for(int i=0;i<N-len;i++) printf("0");
        if(res!=0) printf("%lld\n",res);
        else printf("\n");
    }
    return 0;
}