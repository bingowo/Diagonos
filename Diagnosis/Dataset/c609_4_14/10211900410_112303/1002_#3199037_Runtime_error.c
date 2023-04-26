#include<stdio.h>
int count(int T)
{
    int t[31],a,i=1;
    int num=0,nums[20];
    int *p=nums;
    while(T!=0){
        a=T%2;
        T/=2;
        t[i]=a;
        i++;

    }
    for(int j=0;j<i;j++){
        if(t[j]!=t[j-1]) num++;
        else{
            *p=num;
            num=0;
            p++;
        }
    }
    int max=nums[0];
    for(int j=1;j<(sizeof(nums)/sizeof(int));j++){
        if(nums[j]>max) max=nums[j];
    }
    return max;
}

int main()
{
    int T,i=0;
    int N[10];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d\n",N[i]);
    }
    for(int j=0;j<T;j++){
        printf("case #%d:\n",j);
        printf("%d\n",count(N[j]));
    }
    return 0;
}