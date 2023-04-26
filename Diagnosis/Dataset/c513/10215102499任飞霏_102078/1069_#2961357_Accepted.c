#include <stdio.h>
#include <stdlib.h>

int reverseint(int n)
{
    int m=0;
    while(n){
        m=m*10+n%10;
        n/=10;
    }
    return m;
}

int isreverse(int n)
{
    int tmp=n,len=0,flag=0;
    while(tmp){
        len++;
        tmp/=10;
    }
    int tmp1=reverseint(n),tmp2=n;
    for(int i=0;i<len/2;i++){
        int q = tmp1%10;
        int h = tmp2%10;
        tmp1/=10;
        tmp2/=10;
        if(q!=h){
            flag=1;
            break;
        }
    }
    return flag;
}

int main()
{
    int n;
    scanf("%d",&n);
    int t=0;
    while(isreverse(n)){
        int m = reverseint(n);
        n+=m;
        t++;
    }
    printf("%d %d",t,n);
    return 0;
}
