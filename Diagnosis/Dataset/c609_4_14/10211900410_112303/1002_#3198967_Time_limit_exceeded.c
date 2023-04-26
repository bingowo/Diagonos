#include<stdio.h>
int count(int T)
{
    int t[31],a,i=0;
    while(T!=0){
        a=T%2;
        T/=2;
        t[i]=a;
        i++;
    }
    int num=0,nums[20];
    int *p=nums;
    for(int j=0;j<i;j++){
        if(t[j]!=t[j+1]) num++;
        else{
            *p=num;
            num=0;
            p++;
        }
    }
    int max=nums[0];
    for(i=1;i;i++){
        if(nums[i]>max) max=nums[i];
    }
    return max;
}

int main()
{
    int T,i=0;
    int N[10];
    while(scanf("%d",&T)!=EOF){
        N[i]=count(T);
        i++;
    }
    for(int j=0;j<i;j++){
        printf("case #%d:\n",j);
        printf("%d\n",N[j]);
    }
    return 0;
}