// 0  A 1000 int[某数字的权重]
// B 整活儿！ 结构体
// int  ini数字
//int  位权

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct B_type{
    int ini_num ;
    int weight_num ;
};
struct B_type B[1010];
int number_weight[1100];

int cmp(const void *a,const void *b){
    struct B_type* A = (B_type *)a;
    struct B_type* C = (B_type *)b;
    if(A->weight_num > C->weight_num){
        return -1;
    }else if(A->weight_num < C->weight_num){
        return 1;
    }else if (A->weight_num == 0 &&C->weight_num ==0){
        return -(-A->ini_num+ C->ini_num);
    }

}
int main(){
    int weight = 500;
    int totalA = 0;
    scanf("%d",&totalA);
    for(int i = 0 ; i < totalA;i++){
        int tempnum = 0;
        scanf("%d",&tempnum);
        number_weight[tempnum] = weight;
        weight--;
    }
    int totalB = 0;
    scanf("%d",&totalB);
    for(int i = 0; i < totalB;i++){
        int tempB = 0;
        scanf("%d",&tempB);
        B[i].ini_num = tempB;
        B[i].weight_num = number_weight[tempB];
    }
    qsort(B,totalB,sizeof(B[0]),cmp);
    for (int i = 0; i < totalB;i++){
        printf("%d ",B[i].ini_num);
    }


}