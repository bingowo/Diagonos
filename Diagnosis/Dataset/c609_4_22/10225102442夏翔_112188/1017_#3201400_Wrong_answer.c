#include<stdio.h>
#include<stdlib.h>
int cmp1(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}
int cmp2(const void *a, const void *b){
    return *(int*)b-*(int*)a;
}
int main(){
    char R, ret;
    scanf("%c", &R);
    int num[1000],count=0;
    while(scanf("%d", &num[count])!=EOF){
        count++;
    }
    if(R=='A')
        qsort(num,count,sizeof(num[0]),cmp1);
    else
        qsort(num,count,sizeof(num[0]),cmp2);
    for(int i=1; i<count-1; i++)
        if(num[i]!=num[i-1]) printf("%d ", num[i]);
    if(num[count-1]!=num[count-2]) printf("%d", num[count-1]);
    return 0;
}