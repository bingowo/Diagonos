#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int num,j=0;
        scanf("%d",&num);
        int ans[100];
        while(num){
            ans[j]=num%2;
            num=num/2;
            j++;
        }
        printf("case #%d:",i);
        printf("%d",ans[j]);
        for(j;j>=0;j--){
            if(ans[j-1]==ans[j]) continue;
            else printf("%d",ans[j-1]);
        }
        printf("\n");
    }
    return 0;
}
