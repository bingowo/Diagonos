#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int n,r;
        scanf("%d%d",&n,&r);
        int sum=0;
        while(n!=0){
            sum=sum+n%r;
            n=n/r;
        }
        int a[100];
        int j=0;
        while(sum/r!=0){
            a[j]=sum%r;
            sum=sum/r;
            j++;
        }
        if(sum>10) printf("%c",'A'+sum-10);
        else printf("%d",sum);
        for(int k=j-1;k>=0;k--){
            if(a[k]>=10) printf("%c",'A'+a[k]-10);
            else printf("%d",a[k]);
        }
        printf("\n");
    }
    return 0;
}
