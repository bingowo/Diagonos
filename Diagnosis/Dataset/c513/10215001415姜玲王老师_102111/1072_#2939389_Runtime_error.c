#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int number(long long a)
{if(a==0) return 0;
else return number(a/2)+1;}
void direction(long long x,long long y)
{if(x==0&&y==1) {printf("S");return;}
if(x==0&&y==-1) {printf("N");return;}
if(x==1&&y==0) {printf("W");return;}
if(x==-1&&y==0) {printf("E");return;}
if((x%2)&&(((x+y+1)/2)%2)) {printf("E");direction((x+1)/2,y/2);}
if((x%2)&&(((x+y-1)/2)%2)) {printf("W");direction((x-1)/2,y/2);}
if((y%2)&&(((x+y+1)/2)%2)) {printf("N");direction(x/2,(y+1)/2);}
if((y%2)&&(((x+y-1)/2)%2)) {printf("S");direction(x/2,(y-1)/2);}
}
int main()
{long long x,y;
scanf("%lld%lld",&x,&y);
if(x==0&&y==0) {printf("-1");return;}
if((llabs(x)+llabs(y))%2){printf("%d\n",number(llabs(x)+llabs(y)));direction(-x,-y);printf("\n");}
else{printf("-1\n");return 0;}
}
