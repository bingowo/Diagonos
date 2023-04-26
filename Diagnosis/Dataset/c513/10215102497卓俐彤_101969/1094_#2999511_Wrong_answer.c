#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bigint{
    char num[121];
};

int cmp(const void*a,const void*b){
    struct bigint d1,d2;
    d1=*((struct bigint*)a);
    d2=*((struct bigint*)b);
    if(strlen(d1.num)==strlen(d2.num)){
        for(int i=0;i<strlen(d1.num);i++){
            if(d1.num[i]>d2.num[i])return 1;
            else if(d1.num[i]<d2.num[i])return -1;
        }
        return 0;
    }else{
        if(strlen(d1.num)>strlen(d2.num))return 1;
        else return -1;
    }
}

void sub(char a[],char b[],char res[]){
    int p1,p2;
    int i=(int)strlen(a)-1;
    int j=(int)strlen(b)-1;
    int carry=0,temp=0;
    for(int k=120;k>=0;k--,i--,j--){
        p1=i<0?0:a[i]-'0';
        p2=j<0?0:b[j]-'0';
        temp=p1-p2+carry;
        carry=0;
        if(temp<0){
            temp+=10;
            carry=-1;
        }
        res[k]='0'+temp;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    struct bigint nums[T];
    char distance[121];
    for(int t=0;t<T;t++){
        scanf("%s",nums[t].num);
    }
    qsort(nums, T, sizeof(nums[0]), cmp);
    sub(nums[T-1].num,nums[0].num,distance);
    int flag=0;
    while(distance[flag]=='0')flag++;
    for(;flag<strlen(distance);flag++)
        printf("%c",distance[flag]);
    printf("\n");
    return 0;
}
