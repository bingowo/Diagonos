#include<stdio.h>

int sum(int a);
int main()
{
    int T;
    int a[10],i,max;
    scanf("%d",&T);
    for(i = 0;i<T;i++){
        scanf("%d",&a[i]);
    }
    for(i = 0;i<T;i++){
        max = sum(a[i]);
        printf("case #%d:\n",i);
        printf("%d\n",max);
    }
    return 0;
}
int sum(int a){
    int b[100],i = 0,sum[100],count=1,n=0,j; //b[]储存二进制,sum[]储存该数字中非重复二进制串的长度，count储存每串长度
    int max;
    while(a){
        b[i]=a%2;
        a = a/2;
        i++;
    }
    for(j = 0;j-1<i;j=j+2){
        if (b[j] != b[j+1]){
            count = count +1;
        }
        else{
            sum[n] = count;
            n++;
            count = 1;
        }
    }
    sum[n] = count;
    max = sum[0];
    for(j = 1;j<n;j++){
        if(sum[j]>max) max = sum[j];
    }
    return max;
}
