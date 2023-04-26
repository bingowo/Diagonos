#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,r;
        scanf("%d %d",&n,&r);
        if(n<0){
            printf("-");
        }
        int out[100]={0},x=0;
        while(n){
            out[x++]=n%r;
            n/=r;
        }

        for(int j=x-1;j>=0;j--){
            if(out[j]<=9){
                printf("%d",abs(out[j]));
            }
            else{
                printf("%c",out[j]-10+'A');
            }
        }
        printf("\n");
    }
}


