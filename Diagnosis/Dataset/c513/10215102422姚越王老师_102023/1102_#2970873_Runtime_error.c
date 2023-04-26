#include<stdio.h>
#define C 1000000010
typedef unsigned long long ull;
typedef struct{ull num,side,x,y;} point;
int main()
{
    ull i,cnt,n,mov,c,d,ansx,ansy;point arr[C];
    arr[0].num=3;arr[0].side=3;arr[0].x=-1;arr[0].y=0;
    for(i=1;;++i)
    {   
        arr[i].num=arr[i-1].num+arr[i-1].side*4;
        arr[i].side=arr[i-1].side+2;
        arr[i].x=arr[i-1].x-1;arr[i].y=arr[i-1].y-1;
        if(arr[i].num>1000000000000000000)break;
    }
    cnt=i;
    scanf("llu",&n);
    if(!n){printf("(0,0)");return 0;}
    if(n==1){printf("(0,1)");return 0;}
    if(n==2){printf("(-1,1)");return 0;}
    for(i=0;i<cnt-1;++i)if(arr[i].num<=n&&n<=arr[i+1].num)break;
    mov=n-arr[i].num;c=mov/arr[i].side;d=mov%arr[i].side;
    if(!c&&!d){printf("(%llu,%llu)",arr[i].x,arr[i].y);return 0;}
    switch(c)
    {
        case 0:
        {
            ansy=arr[i+1].y;
            ansx=arr[i+1].x+d;
            break;
        }
        case 1:
        {
            ansx=arr[i+1].x+arr[i].side;
            ansy=arr[i+1].y+d;
            break;
        }
        case 2:
        {
            ansy=arr[i+1].y+arr[i].side;
            ansx=arr[i+1].x+arr[i].side-d;
            break;
        }
        case 3:
        {
            ansx=arr[i+1].x;
            ansy=arr[i+1].y+arr[i].side-d;
            break;
        }
    }
    printf("(%llu,%llu)",ansx,ansy);
    return 0;
}