#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   int n;
    scanf("%d",&n);
    int i;
    long long m;
    for(i=0;i<n;i++){
       scanf("%lld",&m);
       int ans[20],j=0,y;
       if (m==0) printf("0\n");
       else{
       while(m>0){
        y=m%2333;
        ans[j++]=y;
        m/=2333;
       }
       for (int t=j-1;t>=0;t--){
        printf("%d ",ans[t]);
       }
       printf("\n");
       }
    }
    return 0;
}
