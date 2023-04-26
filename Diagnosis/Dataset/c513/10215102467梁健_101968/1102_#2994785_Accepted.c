#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    long long n;scanf("%lld",&n);
    long long x=0,y=0,i=1;
    while(n-8*i+1>=0){
        n=n-8*i+1;
        x++;
        i+=1;
    }
    //进入最后一圈
    //先往上走
    if(n-i>=0){
        n-=i;
        y=i;
    }
    else{
        y=n;
        printf("(%lld,%lld)",x,y);
        return 0;
    }
    //往左
    if(n-2*i+1>=0){
        x=-i;
        n=n-2*i+1;
    }
    else{
        x-=n;
        printf("(%lld,%lld)",x,y);
        return 0;
    }
    //往下
    if(n-2*i>=0){
        y=-i;
        n=n-2*i;
    }
    else{
        y-=n;
        printf("(%lld,%lld)",x,y);
        return 0;
    }
    //往右
    if(n-2*i>=0){
        x=i;
        n=n-2*i;
    }
    else{
        x+=n;
        printf("(%lld,%lld)",x,y);
        return 0;
    }
    //往上
    y+=n;
    printf("(%lld,%lld)",x,y);
    return 0;
    
}
