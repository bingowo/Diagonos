#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bigint{
    char num[121];
    int flag;
};

int cmp(const void*a,const void*b){
    struct bigint d1,d2;
    d1=*((struct bigint*)a);
    d2=*((struct bigint*)b);
    if(d1.flag!=d2.flag){
        return d1.flag;
    }else{
        if(d1.flag==1){
            if(strlen(d1.num)!=strlen(d2.num)){
                return (int)(strlen(d1.num))-(int)(strlen(d2.num));
            }else{
                return strcmp(d1.num,d2.num);
            }
        }else{
            if(strlen(d1.num)!=strlen(d2.num)){
                return (int)(strlen(d2.num))-(int)(strlen(d1.num));
            }else{
                return strcmp(d2.num,d1.num);
            }
        }
    }
}

void sub(char a[],char b[],int res[]){
    int carry=0,temp=0,p=120;
    char p1,p2;
    for(int i=(int)strlen(a)-1,j=(int)strlen(b)-1;i>=0||j>=0||carry;i--,j--){
        p1=i<0?'0':a[i];
        p2=j<0?'0':b[j];
        temp=(p1-'0')-(p2-'0')+carry;
        if(temp<0){
            temp+=10;
            carry=-1;
        }else carry=0;
        res[p--]=temp;
    }
}

void add(char a[],char b[],int res[]){
    int carry=0,temp=0,p=120;
    char p1,p2;
    for(int i=(int)strlen(a)-1,j=(int)strlen(b)-1;i>=0||j>=0||carry;i--,j--){
        p1=i<0?'0':a[i];
        p2=j<0?'0':b[j];
        temp=(p1-'0')-(p2-'0')+carry;
        if(temp>9){
            temp-=10;
            carry=1;
        }else carry=0;
        res[p--]=temp;
    }
}


int main(){
    int T;
    scanf("%d",&T);
    struct bigint nums[T];
    int distance[121]={0};
    for(int t=0;t<T;t++){
        scanf("%s",nums[t].num);
        if(nums[t].num[0]=='-'){
            nums[t].flag=-1;
        }
        else nums[t].flag=1;
    }
    qsort(nums, T, sizeof(nums[0]), cmp);
    if(nums[0].flag==1)sub(nums[T-1].num,nums[0].num,distance);
    else if(nums[T-1].flag==-1){
        struct bigint n1,n2;
        int k=0;
        for(int i=1;i<strlen(nums[T-1].num);i++)n1.num[k++]=nums[T-1].num[i];
        n1.num[k]='\0';k=0;
        for(int i=1;i<strlen(nums[0].num);i++)n2.num[k++]=nums[T-1].num[i];
        n2.num[k]='\0';
        sub(n2.num,n1.num,distance);
    }else{
        struct bigint n;
        int k=0;
        for(int i=1;i<strlen(nums[0].num);i++)n.num[k++]=nums[T-1].num[i];
        n.num[k]='\0';
        add(nums[T-1].num,n.num,distance);
    }
    int flag=0;
    while(!distance[flag])flag++;
    for(;flag<121;flag++)
        printf("%d",distance[flag]);
    printf("\n");
    return 0;
}
