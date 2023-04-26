//1066（3进制模拟可能性）
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long pow3(int n){
    if(n==0) return 1;
    return 3*pow3(n-1);
}
int cmp1(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int main(){
    int n;
    scanf("%d", &n);
    int weights[n], *targets;
    for(int i=0; i<n; i++) scanf("%d", &weights[i]);
    int sum1=pow3(n)-1, temp, size=sum1;
    targets = (int*)calloc(sum1, sizeof(int));
    while(sum1!=0){ //可以适当剪枝
        temp = sum1;
        for(int i=0; i<n&&temp!=0; i++){
            if(temp%3==1) targets[sum1-1] += weights[i];
            else if(temp%3==2) targets[sum1-1] -= weights[i];
            temp /= 3;
        }
        targets[sum1-1] = abs(targets[sum1-1]); //模拟可能性
        sum1--;
    }
    qsort(targets, size, sizeof(targets[0]), cmp1);
    int pos=0;
    while(targets[pos++]==0) ;
    for(int i=1; ; i++){
        if(i==targets[pos]){//可以便输出1
            printf("1");
            pos++;
            while(targets[pos]==targets[pos-1] && pos<size) pos++; //去重
        }else printf("0");
        if(pos==size) break;
    }
    return 0;
}