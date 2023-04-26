#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct liist{
    long long num_1 ;
    long long digit ;
}Liist;

struct liist L[11000];

int cmp(const void*a,const void *b){
    struct liist* A = (Liist*) a;
    struct liist* B= (Liist*) b;
    if(A->num_1 != B->num_1){
        return(int)(B->num_1 - A->num_1);//big first <0
    }else{
        return(int)(A->digit-B->digit);//small first > 0
    }
}
int main(){
    int set = 0;
    scanf("%d",&set);
    for(int i = 0; i < set;i++){ //不同的组数
        int rangenum = 0;//一共有多少数字
        scanf("%d",&rangenum);
        for(int j = 0;j < rangenum;j++){
            long long figure = 0;
            scanf("%lld",&figure);
            L[j].digit = figure;

            long long kk = 1;
            int one = 0;
           for(int k = 0; k < 64;k++){
               if((figure & kk) == 1){
                   one++;
               }else{
                 ;
               }
              figure =  figure >> 1;
           }
            L[j].num_1 = one;

        }
        qsort(L,rangenum,sizeof(L[0]),cmp);
        printf("case #%d:\n",i);
        for(int kk = 0; kk < rangenum;kk++){
            printf("%lld ",L[kk].digit);
        }
        printf("\n");

    }


}