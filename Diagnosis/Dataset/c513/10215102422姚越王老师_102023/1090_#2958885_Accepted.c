#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int N,ans;double tmp;
    while(~scanf("%d",&N))
    {
        if(!N)return 0;
        tmp=N*log10(N);
        ans=(int)tmp;
        tmp-=ans;
        printf("%d\n",(int)pow(10,tmp));
        
    }

}