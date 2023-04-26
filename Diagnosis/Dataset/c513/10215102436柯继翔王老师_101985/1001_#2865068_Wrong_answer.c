#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    long N,R;
    int flag;
    scanf("%d",&T);
    for(int i = 1;i<=T;i++){
        scanf("%d %d",&N,&R);
        if(N>0){
            flag = 0;
        }else{
            flag = 1;
            N=-N;
        }
        int a[32],index = 0;
        while(N>0){
            a[index++] = N%R;
            N/=R;
        }
        if(flag){
                printf("-");
            }
        for(int j = index - 1;j>=0;j--){
            if(a[j]<10){
                printf("%d",a[j]);
            }else{
                printf("%c",a[j]-10+'A');
            }
        }
    }
    return 0;
}
