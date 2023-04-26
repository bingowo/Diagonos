#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b){
    int num_a = *(int*)a;
    int num_b = *(int*)b;
    int digit_a=0,digit_b=0,temp;
    if(num_a == 0) digit_a=1;
    if(num_b == 0) digit_b=1;
    if(num_a < 0) num_a *= -1;
    if(num_b < 0) num_b *= -1;
    while(num_a != 0){
        digit_a++;
        num_a /= 10;
    }
    while(num_b != 0){
        digit_b++;
        num_b /= 10;
    }
    if(digit_a != digit_b) {
        return digit_b - digit_a;
    }
    else{
        return *(int*)a - *(int*)b;
    }
}

int main() {
    int num_list[10000000];
    int cnt=0,temp;
    while(scanf("%d",&temp) != EOF){
        num_list[cnt++] = temp;
    }
    qsort(num_list,cnt,sizeof(int),cmp);
    for(int i=0;i<cnt;i++){
        printf("%d ",num_list[i]);
    }
    return 0;
}
//