#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        int ans=1;
        int x=2;
        while(x<=n){
            if(x%2==0){
                for(int k=0;3*k<=x;k+=2){
                    int sheng=x-3*k;
                    ans=ans+1+sheng/4;
                }
            }
            else {
                for(int k=1;3*k<=x;k+=2){
                    int sheng=x-3*k;
                    ans=ans+1+sheng/4;
                }
            }
            x++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
