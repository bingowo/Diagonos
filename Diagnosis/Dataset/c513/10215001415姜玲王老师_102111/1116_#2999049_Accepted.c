#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int number(long long a)
{if(a==0) return 0;
else return number(a/2)+1;}
int main()
{long long x,y;
scanf("%lld%lld",&x,&y);
if(x==0&&y==0) {printf("0");return 0;}
if((llabs(x)+llabs(y))%2){printf("%d\n",number(llabs(x)+llabs(y)));}
else{printf("-1\n");return 0;}
}