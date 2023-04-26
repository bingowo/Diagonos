#include <stdio.h>
#include <stdlib.h>



int main()
{
    long long sushu[25]={2},sscnt=1;
    for(int i=2;sscnt<25;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){break;}
            if(2*j>i){sushu[sscnt]=i;sscnt++;break;}
        }
    }
    for(int i=0;i<25;i++){printf("%d ",sushu[i]);}
    printf("\n");
    long long su[25]={1};
    for(int i=1;i<25;i++){
        su[i]=su[i-1]*sushu[i-1];
        printf("su[%d]=%lld\n",i,su[i]);
    }


    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){

    }

    return 0;
}
