#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    int N,R;
    char num[1000];
    for(int i=0;i<T;i++){
        int j=0;
        scanf("%d %d",&N,&R);
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
                if(m!=0){
                printf("%c",'A'+num[m]-10);}
                else printf("%c\n",'A'+num[m]-10);
                j=0;
            }
            else {
                if(m!=0){
                printf("%d",num[m]);}
                else printf("%d\n",num[m]);
                j=0;
            }

        }
    }
    return 0;
}