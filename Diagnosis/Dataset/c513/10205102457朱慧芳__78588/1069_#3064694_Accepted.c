#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int judge(int num)
{
    int s=num;
    int y=0;
    while(s>0){
        y=y*10+s%10;
        s=s/10;
    }
    if(y==num) return 1;
    else return 0;
}
int change(int n)
{
    int result=0;
    while(1){
        int i=n%10;
        result=result*10+i;
        n=n/10;
        if(n==0) break;
    }
    return result;
}
int main()
{
    int count=0;
    int n;
    scanf("%d",&n);
    while(judge(n)==0){
        n=n+change(n);
        count++;
    }
    printf("%d %d",count,n);
    return 0;
}