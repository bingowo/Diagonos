#include<stdio.h>
#include <string.h>
#define LEN 100
typedef struct{
int num[LEN];
}BigNum;
void add(int a[], int b[])
{
for(int i = LEN - 1; i ; i --){
a[i] += b[i];
for(int k = i ; a[k] >= 10; k --){
a[k] %= 10;
a[k - 1] += 1;
}
}
}
int main(void)
{
int k, n;
scanf("%d %d", &k, &n);
BigNum in[110];
memset(in, 0, sizeof(in));
in[2].num[LEN - 1] = 1;
for(int i = 3; i <= n; i ++){
for(int j = 0 ; j < k ; j ++){
if(i - j - 1 >= 1){
add(in[i].num, in[i - j - 1].num);
}
}
}
int idx;
for(idx = 0 ;idx < LEN && in[n].num[idx] == 0; idx ++);
if(idx == LEN){
printf("0");
}else{
for(; idx < LEN; idx ++){
printf("%d", in[n].num[idx]);
}
}
return 0;
}