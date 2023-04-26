#include<stdio.h>
int count(int T)
{
    int t[31],a,i=0;
    int num=1,nums[20];
    int count=0;
    while(T!=0){
        a=T%2;
        T/=2;
        t[i]=a;
        i++;
    }
    for(int j=0;j<i-1;j++){
        if(t[j]!=t[j+1]) num++;
        else{
            nums[count]=num;
            num=1;
            count++;
        }
    }
    nums[count]=num;
    int max=nums[0];
    for(int j=0;j<=count;j++){
        if(nums[j]>max) max=nums[j];
    }
    return max;
}
int main()
{
    int T;
    int N[10];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N[i]);
    }
    for(int j=0;j<T;j++){
        printf("case #%d:\n",j);
        printf("%d\n",count(N[j]));
    }
    return 0;
}
