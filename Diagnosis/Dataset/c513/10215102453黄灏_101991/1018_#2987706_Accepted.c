#include <stdio.h>
#include <string.h>

int prime[] = {1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void trans(int *array){
    for(int i=99;i>0;i--){
        array[i-1] += array[i]/10;
        array[i] %= 10;
    }
}

void multi(int *array, int num){
    for(int i=99;i>0;i--){
        array[i] *= num;
    }
    trans(array);
}

void add(int *array,int *num){
    int carry=0;//进位
    for(int i=99;i>=0;i--){
        int temp = carry+num[i]+array[i];
        carry = temp/10;
        array[i] = temp%10;
    }
}

int main(){
    char s[100];
    scanf("%s",s);
    int len = strlen(s);
    if(len == 1) {printf("%s",s); return 0;}

    int array[100]={0};//存放1110；
    int temp=0; int num=0; // 如1，1，1，0 num=4
    for(int i=0;i<len;i++){
        if(s[i]==',') {
            array[num]=temp;
            num++; temp=0;
        }
        else{
            temp *= 10;
            temp = temp+s[i]-'0';
        }
    }
    array[num] = temp;//array = [1,1,1,0]

    int sum[100]={0};
    for(int i=num;i>=0;i--){
        int carry[100]={0};
        carry[99] = 1;
        for(int j=0;j<=num-i;j++){
            multi(carry,prime[j]);
        }
        multi(carry,array[i]);
        add(sum,carry);
    }
    num = 0;
    while (sum[num]==0 && num<100) num++;
    while (num<100) printf("%d",sum[num++]);
    printf("\n");


    return 0;
}
