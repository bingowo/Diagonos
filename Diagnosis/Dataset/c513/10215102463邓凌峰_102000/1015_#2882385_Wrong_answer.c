#include <stdio.h>
#include <stdlib.h>



int main()
{
    long long sushu[25]={1,2},sscnt=2;
    for(int i=2;sscnt<25;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){break;}
            if(2*j>i){sushu[sscnt]=i;sscnt++;break;}
        }
    }
//    for(int i=0;i<25;i++){printf("%d ",sushu[i]);}
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int num1[25]={0},num2[25]={0};
        int i=0,q=1;
        while(q){
            scanf("%d",&num1[i++]);
            char w;w=getchar();
            if(w==' ' ||w== '\n'){q=0;}
        }
        i=0;q=1;
        while(q){
            scanf("%d",&num2[i++]);
            char w;w=getchar();
            if(w==' ' ||w== '\n'){q=0;}
        }
        for(int i=0;i<25;i++){printf("%d ",num1[i]);}
        printf("\n");
        for(int i=0;i<25;i++){printf("%d ",num2[i]);}
        printf("\n");
    }

    return 0;
}
