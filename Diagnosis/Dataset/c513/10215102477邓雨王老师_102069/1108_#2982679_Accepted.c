#include <stdio.h>
#include <string.h> 
#define LEN 100
typedef struct{
int isLoop;
int begin, end;
}Info;
Info div(int d[], int n, int m)
{
Info ret = {0, 0, 0};
int remainder[100] = {0};
for(int i = 0 ; i < LEN; i ++){
d[i] = n / m;
if(n % m == 0){
ret.isLoop = 0; 
ret.end = i;
break; 
}else{
if(!remainder[n % m]){
//记录余数出现的位置，便于找到开始与结尾
remainder[n % m] = i + 1; }else{
ret.isLoop = 1;
ret.begin = remainder[n % m];
ret.end = i;
break; }
n = (n % m) * 10; 
} }
return ret;
}
int main(void) {
int t;
scanf("%d", &t);
for(int i = 0; i < t; i ++){
int n, m;
int d[LEN] = {0};
scanf("%d %d", &n, &m);
Info loop = div(d, n, m);
printf("case #%d:\n0.", i);;
for(int i = 1 ; i <= loop.end; i ++){
printf("%d", d[i]);
}
printf("\n");
if(loop.isLoop){
	printf("%d-%d\n", loop.begin, loop.end);
} }
return 0; }