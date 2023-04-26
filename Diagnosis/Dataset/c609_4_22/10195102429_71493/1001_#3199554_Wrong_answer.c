#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int N,R;
    for(int i=0;i<T;i++){
        int j=0;
        scanf("%d %d",&N,&R);
        int num[100];
        if(N<0){
             printf("-");N=-N;
        }
        if(N==0){printf("0\n");continue;}
        while(N){
            num[j]=(N%R);
            N=N/R;
            j++;
        }
        for(int m=j-1;m>=0;m--){
            if(num[m]>=10)
            {
                printf("%c",'A'+num[m]-10);
            }
            else printf("%d",num[m]);

        }
    }
    return 0;
}
