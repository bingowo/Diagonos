#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 85

// 4w+3x+2y+z=n;

void setSignPoint(int* fx,int* fy,int n)
{
    if(n%2==0)*fx=*fy=-n/2;
    if(n%2){
        *fx=(n-1)/2;
        *fy=(n+1)/2;
    }
}

int main()
{
    long long n;
    scanf("%lld",&n);
    int flag1,flag2;
    flag1 = (int)sqrt(n);flag2=flag1+1;
    //printf("%lld %lld",flag1,flag2);

    int f1x,f1y,f2x,f2y;
    setSignPoint(&f1x,&f1y,flag1);
    setSignPoint(&f2x,&f2y,flag2);

    int retx,rety;
    int temp=flag1*flag1;
    if(flag1%2==0){
        if(n-temp<=flag1){
            rety=f1y;
            retx=f1x+(n-temp);
        }
        else{
            retx=f2x;
            rety=f1y+(n-temp-flag1);
        }
    }
    else{
        if(n-temp<=flag1){
            rety=f1y;
            retx=f1x-(n-temp);
        }
        else{
            retx=f2x;
            rety=f1y-(n-temp-flag1);
        }
    }
    printf("(%d,%d)",retx,rety);

    return 0;
}